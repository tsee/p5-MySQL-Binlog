package MySQL::Binlog;
use 5.008;
use strict;
use warnings;

our $VERSION = '0.01';

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
