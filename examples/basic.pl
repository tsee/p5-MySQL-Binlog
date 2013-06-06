use strict;
use warnings;
use MySQL::Binlog qw(:constants create_transport str_error);
use Scalar::Util qw(blessed);

# @ARGV should have something like 'mysql://user:password@host:port'
my $d = create_transport(shift @ARGV);
my $bl = MySQL::Binlog->new($d);
my $err = $bl->connect;
if ($err != ERR_OK) {
  warn str_error($err) . "\n";
  exit(2);
}

while (1) {
  my ($status, $event) = $bl->wait_for_next_event;
  if ($status != ERR_OK) {
    warn "Got the following result from wait_for_next_event(): " . str_error($err)
         . ". Aborting main loop\n";
  }
  warn "Event is a " . blessed($event) . "\n";
  warn $event->get_event_info . "\n";
}
