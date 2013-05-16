use strict;
use warnings;

use ExtUtils::Constant qw(WriteConstants);

my %event_types_classes = (
  INTVAR_EVENT => "IntVar",
  FORMAT_DESCRIPTION_EVENT => "Format", # FIXME is this correct?
  USER_DEFINED => "UserDefined", # FIXME is this correct?
  map {
    my $x = $_;
    $x =~ s/_EVENT(?:_(V[0-9]))?$// or die;
    my $v = $1;
    $x = join "", map ucfirst(lc($_)), split /_/, $x;
    $x .= $v if defined $v;
    $_ => $x
  }
  qw(
    START_EVENT_V3
    UNKNOWN_EVENT
    QUERY_EVENT
    STOP_EVENT
    ROTATE_EVENT
    LOAD_EVENT
    SLAVE_EVENT
    CREATE_FILE_EVENT
    APPEND_BLOCK_EVENT
    EXEC_LOAD_EVENT
    DELETE_FILE_EVENT
    NEW_LOAD_EVENT
    RAND_EVENT
    USER_VAR_EVENT
    XID_EVENT
    BEGIN_LOAD_QUERY_EVENT
    EXECUTE_LOAD_QUERY_EVENT
    TABLE_MAP_EVENT
    PRE_GA_WRITE_ROWS_EVENT
    PRE_GA_UPDATE_ROWS_EVENT
    PRE_GA_DELETE_ROWS_EVENT
    WRITE_ROWS_EVENT_V1
    UPDATE_ROWS_EVENT_V1
    DELETE_ROWS_EVENT_V1
    INCIDENT_EVENT
    HEARTBEAT_LOG_EVENT
    IGNORABLE_LOG_EVENT
    ROWS_QUERY_LOG_EVENT
    WRITE_ROWS_EVENT
    UPDATE_ROWS_EVENT
    DELETE_ROWS_EVENT
    GTID_LOG_EVENT
    ANONYMOUS_GTID_LOG_EVENT
    PREVIOUS_GTIDS_LOG_EVENT
    ENUM_END_EVENT
  )
);

$event_types_classes{$_} = "MySQL::Binlog::Event::$event_types_classes{$_}"
  for keys %event_types_classes;

my @consts = (
  # enum Log_event_type in binlog_event.h
  keys %event_types_classes,
  # enum Value_type in binlog_event.h
  (map {"User_var_event::$_"} qw(
    STRING_TYPE
    REAL_TYPE
    INT_TYPE
    ROW_TYPE
    DECIMAL_TYPE
    VALUE_TYPE_COUNT
  )),
  # enum enum_flag in binlog_event.h (TODO: May go away)
  (map {"Row_event::$_"} qw(
    STMT_END_F
    NO_FOREIGN_KEY_CHECKS_F
    RELAXED_UNIQUE_CHECKS_F
    COMPLETE_ROWS_F
  )),
  # enum Int_event_type in binlog_event.h
  (map {"Int_var_event::$_"} qw(
    INVALID_INT_EVENT
    LAST_INSERT_ID_EVENT
    INSERT_ID_EVENT
  )),
);

my $realNamespace = 'MySQL::Binlog';
my $loadNamespace = 'MySQL::Binlog::Constants';

my @sanitary_consts = map {my $x = $_; $x =~ s/^[^:]*:://; $x} @consts;

mkdir('lib/MySQL/Binlog');
open my $fh, ">", "lib/MySQL/Binlog/Constants.pm" or die $!;
print $fh <<HERE;
package $loadNamespace;
# WARNING: Autogenerated file, do not edit!
use 5.008; use strict; use warnings;
use vars '\@Names';
\@Names = qw(
@sanitary_consts
);
package
  $realNamespace;
HERE
print $fh "sub $_;\n" for @sanitary_consts;

print $fh <<HERE;

package
  $loadNamespace;
1;
HERE


WriteConstants(
  NAME         => $realNamespace,
  NAMES        => \@sanitary_consts,
  DEFAULT_TYPE => 'IV',
  C_FILE       => 'const-c.inc',
  XS_FILE      => 'const-xs.inc',
);

munge_c();


sub munge_c {
  # remove any #ifdefs from the generated code since we don't have
  # #defines for the constants but "const" initializations
  open my $fh, '+<', 'const-c.inc' or die $!;
  my $code = do {local $/; <$fh>};
  $code =~ s{
              \#ifdef .*? \n
              ( .*? )
              \#else
              .*?
              \#endif
            }
            {$1}sxg;
  seek $fh, 0, 0;
  truncate $fh, 0;

  foreach my $iconst (0..$#consts) {
    if ($consts[$iconst] =~ /:/) {
      print $fh "#define $sanitary_consts[$iconst]_td $consts[$iconst]\n";
      $code =~ s/(\s+\Q$sanitary_consts[$iconst]\E)\b/${1}_td/g;
    }
  }
  print $fh $code;

  print $fh <<'HERE';
const char *
mbl_event_id_to_perl_class(IV event_id)
{
  switch (event_id) {
HERE

  foreach my $k (keys %event_types_classes) {
    print $fh <<HERE;
  case $k:
    return "$event_types_classes{$k}";
HERE
  }

  print $fh <<HERE;
  default:
    {
      dTHX;
      croak("Invalid event id '%i'!", (int)event_id);
    }
  }
}
HERE

  close $fh;
}

