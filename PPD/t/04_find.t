# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl 1.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 5;
BEGIN { use_ok('Net::CUPS::PPD') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

my $file = ppdOpenFile( "sample/test.ppd" );

ok( $file );

ppdMarkDefaults( $file );

ok( $file );

my $option = ppdFindOption( $file, "PageSize");

ok( $option );

my $choice = ppdFindChoice( $option, "Letter");

ok( $choice );
