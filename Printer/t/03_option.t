# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl 1.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 3;
BEGIN { use_ok('Net::CUPS::Printer') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

my @options = ();

@options = cupsAddOption( "media", "letter", \@options );
@options = cupsAddOption( "resolution", "300dpi", \@options );

ok( scalar( @options ) == 2, "cupsAddOption( name, value, options )" );

my $value = cupsGetOption( "media", \@options );

ok( $value eq "letter", "cupsGetOption( name, options )" );
