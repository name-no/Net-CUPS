package Net::CUPS::Printer;
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

use strict;
use warnings;

our $VERSION = "0.35";

our @ISA = qw( Exporter );

XSLoader::load( 'Net::CUPS::Printer', $VERSION );

our @EXPORT = qw( 
					CUPS_PRINTER_LOCAL
					CUPS_PRINTER_CLASS
					CUPS_PRINTER_REMOTE
					CUPS_PRINTER_BW
					CUPS_PRINTER_COLOR
					CUPS_PRINTER_DUPLEX
					CUPS_PRINTER_STAPLE
					CUPS_PRINTER_COPIES
					CUPS_PRINTER_COLLATE
					CUPS_PRINTER_PUNCH
					CUPS_PRINTER_COVER
					CUPS_PRINTER_BIND
					CUPS_PRINTER_SORT
					CUPS_PRINTER_SMALL
					CUPS_PRINTER_MEDIUM
					CUPS_PRINTER_LARGE
					CUPS_PRINTER_VARIABLE
					CUPS_PRINTER_IMPLICIT
					CUPS_PRINTER_DEFAULT
					CUPS_PRINTER_FAX
					CUPS_PRINTER_REJECTING
					CUPS_PRINTER_OPTIONS
					CUPS_VERSION
					CUPS_VERSION_MAJOR
					CUPS_VERSION_MINOR
					CUPS_VERSION_PATCH
					CUPS_DATE_ANY
					cupsAddDest
					cupsAddOption
					cupsCancelJob
					cupsErrorString
					cupsGetClasses
					cupsGetDefault
					cupsGetDest
					cupsGetDests
					cupsGetOption
					cupsGetPPD
					cupsGetPrinters 
					cupsGetJobs
					cupsLastError
					cupsPrintFile
					cupsPrintFiles
					cupsServer
					cupsSetDests
					cupsUser
);


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
		croak( "&NET::CUPS::Printer::constant not defined" );
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

Net::CUPS::Printer - CUPS C API Interface.

=head1 SYNOPSIS

 use Net::CUPS::Printer;

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

Net::CUPS::Printer is an interface to the Common Unix Printing System API.

=head1 AUTHOR

D. Hageman E<lt>dhageman@dracken.comE<gt>

=head1 SEE ALSO

None.

=head1 COPYRIGHT

Copyright (c) 2003-2004 D. Hageman (Dracken Technologies)
All rights reserved.

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
