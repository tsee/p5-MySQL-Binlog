use strict;
use warnings;

package MySQL::Binlog::Event;

sub print_long_info {
  my ($self, $fh) = @_;
  $fh ||= \*STDOUT;
  print $fh $self->get_long_info;
}

sub print_event_info {
  my ($self, $fh) = @_;
  $fh ||= \*STDOUT;
  print $fh $self->get_event_info;
}

1;
