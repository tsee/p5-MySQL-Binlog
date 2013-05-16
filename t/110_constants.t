use strict;
use warnings;

use Test::More tests => 2;
use MySQL::Binlog;

ok(defined(MySQL::Binlog::FORMAT_DESCRIPTION_EVENT()));

MySQL::Binlog->import(":all");
ok(defined(XID_EVENT()));

