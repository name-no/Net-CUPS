use 5.008;
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

print "                                                            \n";
print "**WARNING** **WARNING** **WARNING** **WARNING** **WARNING** \n";
print "                                                            \n";
print "Please read the README concerning this module!              \n";
print "                                                            \n";
print "**WARNING** **WARNING** **WARNING** **WARNING** **WARNING** \n";
print "                                                            \n";

## Not that this will make them see the above warning notice, but
## I guess if it helps out once person then it is worth it.
sleep( 5 );

## Grab the CFLAGS ...
$config{INC} = `cups-config --cflags`;
## Grab the LIBS ...
$config{LIBS} = `cups-config --libs`;

WriteMakefile(
    'NAME'		=> 'Net::CUPS',
    'VERSION_FROM'	=> 'CUPS.pm', # finds $VERSION
    'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
    ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM => 'CUPS.pm', # retrieve abstract from module
       AUTHOR     => 'D. Hageman <dhageman@localdomain>') : ()),
    'DEFINE'		=> '', # e.g., '-DHAVE_SOMETHING'
	%config
);
