# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl 1.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 9;
BEGIN { use_ok('Net::CUPS::Protocol') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

ok( IPP_PORT eq 631, "IPP_PORT Test" );
ok( IPP_MAX_NAME eq 256, "IPP_MAX_NAME Test" );
ok( IPP_TAG_ZERO == 0x00, "IPP_TAG_ZERO Test" );
ok( IPP_FINISHINGS_NONE == 3, "IPP_FINISHINGS_NONE Test" );
ok( HTTP_SERVER_ERROR == 500, "HTTP_SERVER_ERROR Test" );
ok( HTTP_FIELD_UNKNOWN == -1, "HTTP_FIELD_UNKNOWN Test" );
ok( HTTP_KEEPALIVE_OFF == 0, "HTTP_KEEPALIVE_OFF Test" );
ok( HTTP_1_1 == 101, "HTTP_1_1  Test" );
