use strict;
use warnings;

use Getopt::Long qw(GetOptions);

my $uv_type_rx = qr/^(?:uint[0-9]+_t|unsigned|unsigned\s+ (?:int|(?:long )?long|short|char)|UV)$/;
my $iv_type_rx = qr/^(?:int[0-9]+_t|(?:int|(?:long )?long|short|char)|IV)$/;
my $string_type_rx = qr/^(?:std::)?string$/;
my $vector_type_rx = qr/^std::vector<\s*(?:u?int[0-9]+_t|(?:unsigned\s+ )?(?:int|(?:long )?long|short|char)|[UI]V)\s*>$/;

my @accessors;
my $class;
GetOptions(
  'class|c=s' => \$class,
  'accessor|a=s@' => \@accessors,
);

my @uv_acc;
my @iv_acc;
my @string_acc;
my @vector_acc;
foreach my $acc_str (@accessors) {
  my ($type, $name) = split /,/, $acc_str;
  if (not defined $type or not defined $name) {
    die "Invalid type,name combination in $acc_str!";
  }
  if ($type =~ $uv_type_rx) {
    push @uv_acc, [$type, $name];
  }
  elsif ($type =~ $iv_type_rx) {
    push @iv_acc, [$type, $name];
  }
  elsif ($type =~ $string_type_rx) {
    push @string_acc, [$type, $name];
  }
  elsif ($type =~ $vector_type_rx) {
    push @vector_acc, [$type, $name];
  }
  else {
    die "Unsupported accessor type $type!";
  }
}

print emit_accessors(\@uv_acc, 'UV') if @uv_acc;
print emit_accessors(\@iv_acc, 'IV') if @iv_acc;
print emit_accessors(\@string_acc, 'std::string') if @string_acc;
print emit_accessors(\@vector_acc, 'std::vector') if @vector_acc;

sub emit_accessors {
  my ($acc, $meta_type) = @_;

  my $main_func_name = $acc->[0][1];

  my @lines;
  my $output_type = $meta_type eq 'std::vector' ? 'SV *' : $meta_type;
  push @lines, "", $output_type, $class . "::" . $main_func_name . "(...)";
  if (@$acc > 1) {
    push @lines, "  ALIAS:";
    foreach my $ialias (1 .. $#$acc) {
      push @lines, "    " . $acc->[$ialias][1] . " = $ialias";
    }
  }
  push @lines, "  CODE:";
  push @lines, "    if (items > 1) {";

  if ($meta_type eq 'std::string') {
    push @lines, "      STRLEN len;\n      char *str;\n      str = SvPV(ST(1), len);";
  }

  if (@$acc == 1) {
    emit_mutator_snippet($acc->[0], $meta_type, \@lines);
  }
  else {
    for (0..$#$acc-1) {
      push @lines, "      if (ix == $_) {";
      emit_mutator_snippet($acc->[$_], $meta_type, \@lines);
      push @lines, "      }\n      else";
    }
    $lines[-1] .= " {";
    emit_mutator_snippet($acc->[$#$acc], $meta_type, \@lines);
    push @lines, "      }";
  }

  push @lines, "    } else {";
  if (@$acc == 1) {
    emit_accessor_snippet($acc->[0], $meta_type, \@lines);
  }
  else {
    for (0..$#$acc-1) {
      push @lines, "      if (ix == $_) {";
      emit_accessor_snippet($acc->[$_], $meta_type, \@lines);
      push @lines, "      }\n      else";
    }
    $lines[-1] .= " {";
    emit_accessor_snippet($acc->[$#$acc], $meta_type, \@lines);
    push @lines, "      }";
  }
  push @lines, "    }";
  push @lines, "  OUTPUT: RETVAL";
  return join("\n", (map {chomp $_; $_} @lines), "\n");
}

sub emit_mutator_snippet {
  my ($acc, $meta_type, $lines) = @_;
  if ($meta_type eq 'UV') {
    push @$lines, "        THIS->$acc->[1] = ($acc->[0])SvUV(ST(1));",
                  "        RETVAL = (UV)THIS->$acc->[1];";
  }
  elsif ($meta_type eq 'IV') {
    push @$lines, "      THIS->$acc->[1] = ($acc->[0])SvIV(ST(1));",
                  "      RETVAL = (IV)THIS->$acc->[1];";
  }
  elsif ($meta_type eq 'std::string') {
    push @$lines, "      THIS->$acc->[1] = std::string(str, len);",
                  "      RETVAL = THIS->$acc->[1];";
  }
  elsif ($meta_type eq 'std::vector') {
    my ($subtype, $get_macro, $new_macro) = vector_type_meta_data($acc->[0]);
    push @$lines, <<HERE;
      SV* const xsub_tmp_sv = ST(1);
      SvGETMAGIC(xsub_tmp_sv);
      AV *av;
      if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV)
        av = (AV*)SvRV(xsub_tmp_sv);
      else
        Perl_croak(aTHX_ "Parameter is not an ARRAY reference");
      unsigned int i;
      const int len = av_len(av)+1;
      $acc->[0] & v = THIS->$acc->[1];
      v.resize(len);
      for (i = 0; i < (unsigned int)len; ++i) {
        SV **elem = av_fetch(av, i, 0);
        v[i] = (elem == NULL ? 0 : ($subtype)$get_macro(*elem));
      }
      XSRETURN_UNDEF;
HERE
  }
  else {
    die "Bad Mojo";
  }
}

sub emit_accessor_snippet {
  my ($acc, $meta_type, $lines) = @_;
  if ($meta_type eq 'UV') {
    push @$lines, "        RETVAL = (UV)THIS->$acc->[1];";
  }
  elsif ($meta_type eq 'IV') {
    push @$lines, "      RETVAL = (IV)THIS->$acc->[1];";
  }
  elsif ($meta_type eq 'std::string') {
    push @$lines, "      RETVAL = THIS->$acc->[1];";
  }
  elsif ($meta_type eq 'std::vector') {
    my ($subtype, $get_macro, $new_macro) = vector_type_meta_data($acc->[0]);
    push @$lines, <<HERE;
      const $acc->[0] & v = THIS->$acc->[1];
      const unsigned int len = v.size();
      unsigned int i;
      AV *av = newAV();
      RETVAL = sv_2mortal(newRV_noinc((SV *)av));
      av_extend(av, len-1);
      for (i = 0; i < len; ++i) {
        av_store(av, i, $new_macro(v[i]));
      }
HERE
  }
  else {
    die "Bad Mojo";
  }
}

sub vector_type_meta_data {
  my $type = shift;
  my $subtype = $type;
  $subtype =~ s/^std::vector<\s*// or die;
  $subtype =~ s/\s*>$// or die;
  my $get_macro = ($subtype =~ /uint|unsigned|UV/ ? 'SvUV' : 'SvIV');
  my $new_macro = ($subtype =~ /uint|unsigned|UV/ ? 'newSVuv' : 'newSViv');
  return ($subtype, $get_macro, $new_macro);
}
