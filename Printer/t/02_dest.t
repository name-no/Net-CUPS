# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl 1.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 4;
BEGIN { use_ok('Net::CUPS::Printer') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

my @destinations = cupsGetDests();

ok( @destinations, "cupsGetDests()" );

my $number_of_destinations_before = scalar( @destinations );

@destinations = cupsAddDest( "abcdedf", "data", \@destinations );

my $number_of_destinations_after = scalar( @destinations );

ok( $number_of_destinations_before == ( $number_of_destinations_after - 1 ),
	"cupsAddDest( name, instance, destinations )" );

my $destination = cupsGetDest( "abcdedf", "data", \@destinations );

ok( $destination, "cupsGetDest( name, instance )" );
