# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl 1.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 5;
BEGIN { use_ok('Net::CUPS::PPD') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

ok( PPD_MAX_NAME eq 41, "PPD_MAX_NAME Test" );
ok( PPD_MAX_TEXT eq 81, "PPD_MAX_TEXT Test" );
ok( PPD_MAX_LINE eq 256, "PPD_MAX_LINE Test" );
ok( PPD_OK eq 0, "PPD_OK Test" );
