use 5.006;
use ExtUtils::MakeMaker;

print "Net::CUPS Configuration\n";

## We need to have a hash to store our configuration options.
my %config;

print "Running cups-config ... ";
my $version = `cups-config --version`;

## Check to see if we have found the cups-config.
if( !defined( $version ) )
{
	print "failed.\n\n";
	print "Net::CUPS requires the Common Unix Printing System. Check\n";
	print "your system configuration and then attempt the configure\n";
	print "process again.\n";
	die;
}
else
{
	print "$version\n";
}

my( @version_parts ) = split( /\./, $version );

if( ( $version_parts[1] < 1 ) || 
	( ( $version_parts[1] == 1 ) && ( $version_parts[2] < 21 ) ) )
{
	print "The version of the Common Unix Printing System installed\n";
	print "on your system is too old for this module to work properly.\n";
	print "Please upgrade the version of CUPS on your system to version \n";
	print "1.1.21 or higher and re-run Makefile.PL to install this module.\n\n";
	exit( 1 );
}

## Grab the CFLAGS ...
$config{INC} = `cups-config --cflags`;

## Grab the LIBS ...
$config{LIBS} = `cups-config --libs`;


# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'		=> 'Net::CUPS',
    'VERSION_FROM'	=> 'CUPS.pm', # finds $VERSION
    'PREREQ_PM'		=> {'Test::More'		=>	0,
						'Exporter::Cluster'	=>	0 },
    ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM => 'CUPS.pm', # retrieve abstract from module
       AUTHOR     => 'D. Hageman <dhageman@dracken.com>') : ()),
	'DEFINE'		=> '', # e.g., '-DHAVE_SOMETHING'
	%config
);
