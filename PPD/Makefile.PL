use 5.006;
use ExtUtils::MakeMaker;

## Grab the CFLAGS ...
$config{INC} = `cups-config --cflags`;

## Grab the LIBS ...
$config{LIBS} = `cups-config --libs`;

WriteMakefile(
    'NAME'		=> 'Net::CUPS::PPD',
    'VERSION_FROM'	=> 'PPD.pm', # finds $VERSION
    'PREREQ_PM'		=> {'Test::More'  =>  0}, # e.g., Module::Name => 1.1
    ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM => 'PPD.pm', # retrieve abstract from module
       AUTHOR     => 'D. Hageman <dhageman@dracken.com>') : ()),
    'DEFINE'		=> '', # e.g., '-DHAVE_SOMETHING'
	%config
	# Un-comment this if you add C files to link with later:
    # 'OBJECT'		=> '$(O_FILES)', # link all the C files too
);
