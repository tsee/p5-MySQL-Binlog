use strict;
use warnings;

use Test::More tests => 20;
use MySQL::Binlog;

SCOPE: {
  my $header = MySQL::Binlog::Event::Header->new;
  isa_ok($header, 'MySQL::Binlog::Event::Header');
  is($header->next_position(2), 2, 'Event header next_position accessor (set)');
  is($header->next_position, 2, 'Event header next_position accessor (get after initial set)');
  is($header->next_position(3), 3, 'Event header next_position accessor (set)');
  is($header->next_position, 3, 'Event header next_position accessor (get after set)');

  my $inc_event = MySQL::Binlog::Event::create_incident_event(2, "foo", 1);
  isa_ok($inc_event, 'MySQL::Binlog::Event');
  isa_ok($inc_event, 'MySQL::Binlog::Event::Incident');

  is($inc_event->type, 2, 'Incident event type accessor (get)');
  is($inc_event->type(3), 3, 'Incident event type accessor (set)');
  is($inc_event->type, 3, 'Incident event type accessor (get after set)');

  is($inc_event->message, "foo", 'Incident event message accessor (get)');
  is($inc_event->message("barrr"), "barrr", 'Incident event message accessor (set)');
  is($inc_event->message, "barrr", 'Incident event message accessor (get after set)');

  my $einfo = $inc_event->get_event_info();
  ok(defined($einfo), "Some event info exists");
  my $linfo = $inc_event->get_long_info;
  ok(defined($linfo), "Long event info at least doesn't barf");

  my $etype = $inc_event->get_event_type();
  is($etype, MySQL::Binlog::INCIDENT_EVENT(), "Event type correct");
  my $h = $inc_event->header();
  isa_ok($h, 'MySQL::Binlog::Event::Header');
  $h->next_position(123);
  my $h2 = $inc_event->header();
  isa_ok($h2, 'MySQL::Binlog::Event::Header');
  is($h2->next_position, 123, "Header has same data multiple times");

  exit;
}

pass("Alive after destructors");
