package Net::CUPS::PPD;
######################################################################
##                                                                  ##
##  Package:  CUPS.pm                                               ##
##  Author:   D. Hageman <dhageman@dracken.com>                     ##
##                                                                  ##
##  Description:                                                    ##
##                                                                  ##
##  Perl interface to the Common Unix Printing System (CUPS) API.   ##
##                                                                  ##
######################################################################

##==================================================================##
##  Libraries and Variables                                         ##
##==================================================================##

require 5.006;
require Exporter;
require XSLoader;

use Carp;
use strict;
use warnings;

our $VERSION = "0.37";

our @ISA = qw( Exporter );

XSLoader::load( 'Net::CUPS::PPD', $VERSION );

our @EXPORT = qw( 
					PPD_VERSION
					PPD_MAX_NAME
					PPD_MAX_TEXT
					PPD_MAX_LINE
					PPD_UI_BOOLEAN
					PPD_UI_PICKONE
					PPD_UI_PICKMANY
					PPD_ORDER_ANY
					PPD_ORDER_DOCUMENT
					PPD_ORDER_EXIT
					PPD_ORDER_JCL
					PPD_ORDER_PAGE
					PPD_ORDER_PROLOG
					PPD_CS_CMYK
					PPD_CS_CMY
					PPD_CS_GRAY
					PPD_CS_RGB
					PPD_CS_RGBK
					PPD_CS_N
					PPD_OK
					PPD_FILE_OPEN_ERROR
					PPD_NULL_FILE
					PPD_ALLOC_ERROR
					PPD_MISSING_PPDADOBE4
					PPD_MISSING_VALUE
					PPD_INTERNAL_ERROR
					PPD_BAD_OPEN_GROUP
					PPD_NESTED_OPEN_GROUP
					PPD_BAD_ORDER_DEPENDENCY
					PPD_BAD_UI_CONSTRAINTS
					PPD_MISSING_ASTERISK
					PPD_LINE_TOO_LONG
					PPD_ILLEGAL_CHARACTER
					PPD_ILLEGAL_MAIN_KEYWORD
					PPD_ILLEGAL_OPTION_KEYWORD
					PPD_ILLEGAL_TRANSLATION
					ppdConflicts
					ppdEmit
					ppdEmitFd
					ppdFindChoice
					ppdFindMarkedChoice
					ppdFindOption
					ppdIsMarked
					ppdMarkDefaults
					ppdMarkOption
					ppdOpenFile
					ppdPageLength
					ppdPageSize
					ppdPageWidth	);

##==================================================================##
##  Function(s)                                                     ##
##==================================================================##

##----------------------------------------------##
##  AUTOLOAD                                    ##
##----------------------------------------------##
##  Catch all method and constant handling      ##
##  routine.                                    ##
##----------------------------------------------##
sub AUTOLOAD
{
	my $constant;
	our $AUTOLOAD;

	( $constant = $AUTOLOAD ) =~ s/.*:://;

	if( $constant eq 'constant' )
	{
		croak( "&NET::CUPS::PPD::constant not defined" );
	}

	## Attempt to resolve the constant ...
	my( $error, $value ) = constant( $constant );

	## Check for an error and die if one exists.
	if( $error )
	{
		croak( $error );
	}
	
	## We are good to go ... so return the constant.
	{
		no strict 'refs';

		*$AUTOLOAD = sub{ $value };
	}

	goto &$AUTOLOAD;
}

##==================================================================##
##  End of Code                                                     ##
##==================================================================##
1;

##==================================================================##
##  Plain Old Documentation (POD)                                   ##
##==================================================================##

__END__

=head1 NAME

Net::CUPS::PPD - CUPS C API Interface.

=head1 SYNOPSIS

 use Net::CUPS::PPD;

=head1 ABSTRACT

 This is the abstract for this file.
 
=head1 FUNCTIONS

=over 4

=item cupsCancelJob ( DESTINATION, JOBID )

Function to remove a job from the queue.

=item cupsErrorString ( ERRORCODE )

Function to translate a numeric error code into a human readable form.

=item cupsGetClasses ()

This function returns an array of all available printing classes.

=item cupsGetDefault ()

Function to return the default printer.

=item cupsGetDests ()

This function returns an array of all available printing destinations.

=item cupsGetPrinters ()

Function that returns an array of all available printers.

=item cupsGetJobs ( DESTINATION, NOTALL, COMPLETED )

A function to return the jobs currently in the printer spool.  Destination
is the printer to query.  The NOTALL argument indicates if you want just
your print jobs (1) or if you want to see all of the jobs (0).  If the
COMPLETED variable is set to true then only the completed jobs will be 
returned.  If it is set to false then all pending/processing jobs
will be returned.

=item cupsLastError ()

Function to grab the last error code the CUPS system encountered.

=item cupsPrintFile ( DESTINATION, FILE, TITLE, OPTIONS )

Function to send a FILE to be printed by DESTINATION.  TITLE is
the name of the job.  OPTIONS is a hash reference holding
the perfered printing options.

=item cupsPrintFiles ( DESTINATION, FILES, TITLE, OPTIONS )

Function to send FILES to be printed by DESTINATION.  TITLE is
the name of the job.  OPTIONS is a hash reference holding
the perfered printing options.

=item cupsServer ()

Grabs the name of the current choosen CUPS server.

=item cupsUser ()

Grabs the username of the selecting printing user.

=back

=head1 DESCRIPTION

Net::CUPS::PPD is an interface to the Common Unix Printing System API.

=head1 AUTHOR

D. Hageman E<lt>dhageman@dracken.comE<gt>

=head1 SEE ALSO

None.

=head1 COPYRIGHT

Copyright (c) 2003-2004 D. Hageman (Dracken Technologies)
All rights reserved.

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
