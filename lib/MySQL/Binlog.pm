package MySQL::Binlog;
use 5.008;
use strict;
use warnings;

use Carp qw(croak);
use Exporter 'import';
use MySQL::Binlog::Constants;
use MySQL::Binlog::Event;

our %EXPORT_TAGS = (
  'constants' => \@MySQL::Binlog::Constants::Names,
);
our @EXPORT_OK = map {@$_} values %EXPORT_TAGS;
$EXPORT_TAGS{all} = \@EXPORT_OK;

our $VERSION = '0.01';

sub AUTOLOAD {
    # This AUTOLOAD is used to 'autoload' constants from the constant()
    # XS function.

    my $constname;
    our $AUTOLOAD;
    ($constname = $AUTOLOAD) =~ s/.*:://;
    croak("&MySQL::Binlog::constant not defined") if $constname eq 'constant';
    my ($error, $val) = constant($constname);
    if ($error) { croak $error; }
    {
        no strict 'refs';
        *$AUTOLOAD = sub { $val };
    }
    goto &$AUTOLOAD;
}

require XSLoader;
XSLoader::load('MySQL::Binlog', $VERSION);

1;
__END__

=head1 NAME

MySQL::Binlog - MySQL Binlog tools

=head1 DESCRIPTION

B<Write me!>

=head1 SEE ALSO

L<https://code.launchpad.net/~mysql/mysql-replication-listener/trunk>

L<ExtUtils::XSpp>

=head1 AUTHOR

Author of the wrapper Perl module is:

Steffen Mueller, E<lt>smueller@cpan.orgE<gt>

=head1 COPYRIGHT AND LICENSE

The MySQL::Binlog module is distributed under the same license as the
underlying MySQL binlog library. The wrapper code is:

  Copyright (C) 2011, 2012, 2013 by Steffen Mueller.
  
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; version 2 of
  the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
  02110-1301  USA

=cut
