package Net::CUPS::IPP;
######################################################################
##                                                                  ##
##  Package:  IPP.pm                                                ##
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

XSLoader::load( 'Net::CUPS::IPP', $VERSION );

our @EXPORT = qw(
					IPP_MAX_NAME
					IPP_MAX_VALUES
					IPP_PORT
					IPP_TAG_ZERO
					IPP_TAG_OPERATION
					IPP_TAG_JOB
					IPP_TAG_END
					IPP_TAG_PRINTER
					IPP_TAG_UNSUPPORTED_GROUP
					IPP_TAG_SUBSCRIPTION
					IPP_TAG_EVENT_NOTIFICATION
					IPP_TAG_UNSUPPORTED_VALUE
					IPP_TAG_DEFAULT
					IPP_TAG_UNKNOWN
					IPP_TAG_NOVALUE
					IPP_TAG_NOTSETTABLE
					IPP_TAG_DELETEATTR
					IPP_TAG_ADMINDEFINE
					IPP_TAG_INTEGER
					IPP_TAG_BOOLEAN
					IPP_TAG_ENUM
					IPP_TAG_STRING
					IPP_TAG_DATE
					IPP_TAG_RESOLUTION
					IPP_TAG_RANGE
					IPP_TAG_BEGIN_COLLECTION
					IPP_TAG_TEXTLANG
					IPP_TAG_NAMELANG
					IPP_TAG_END_COLLECTION
					IPP_TAG_TEXT
					IPP_TAG_NAME
					IPP_TAG_KEYWORD
					IPP_TAG_URI
					IPP_TAG_URISCHEME
					IPP_TAG_CHARSET
					IPP_TAG_LANGUAGE
					IPP_TAG_MIMETYPE
					IPP_TAG_MEMBERNAME
					IPP_TAG_MASK
					IPP_TAG_COPY
					IPP_RES_PER_INCH
					IPP_RES_PER_CM
					IPP_FINISHINGS_NONE
					IPP_FINISHINGS_STAPLE
					IPP_FINISHINGS_PUNCH
					IPP_FINISHINGS_COVER
					IPP_FINISHINGS_BIND
					IPP_FINISHINGS_SADDLE_STITCH
					IPP_FINISHINGS_EDGE_STITCH
					IPP_FINISHINGS_FOLD
					IPP_FINISHINGS_TRIM
					IPP_FINISHINGS_BALE
					IPP_FINISHINGS_BOOKLET_MAKER
					IPP_FINISHINGS_JOB_OFFSET
					IPP_FINISHINGS_STAPLE_TOP_LEFT
					IPP_FINISHINGS_STAPLE_BOTTOM_LEFT
					IPP_FINISHINGS_STAPLE_TOP_RIGHT
					IPP_FINISHINGS_STAPLE_BOTTOM_RIGHT
					IPP_FINISHINGS_EDGE_STITCH_LEFT
					IPP_FINISHINGS_EDGE_STITCH_TOP
					IPP_FINISHINGS_EDGE_STITCH_RIGHT
					IPP_FINISHINGS_EDGE_STITCH_BOTTOM
					IPP_FINISHINGS_STAPLE_DUAL_LEFT
					IPP_FINISHINGS_STAPLE_DUAL_TOP
					IPP_FINISHINGS_STAPLE_DUAL_RIGHT
					IPP_FINISHINGS_STAPLE_DUAL_BOTTOM
					IPP_FINISHINGS_BIND_LEFT
					IPP_FINISHINGS_BIND_TOP
					IPP_FINISHINGS_BIND_RIGHT
					IPP_FINISHINGS_BIND_BOTTOM
					IPP_PORTRAIT
					IPP_LANDSCAPE
					IPP_REVERSE_LANDSCAPE
					IPP_REVERSE_PORTRAIT
					IPP_QUALITY_DRAFT
					IPP_QUALITY_NORMAL
					IPP_QUALITY_HIGH
					IPP_JOB_PENDING
					IPP_JOB_HELD
					IPP_JOB_PROCESSING
					IPP_JOB_STOPPED
					IPP_JOB_CANCELLED
					IPP_JOB_ABORTED
					IPP_JOB_COMPLETED
					IPP_PRINTER_IDLE
					IPP_PRINTER_PROCESSING
					IPP_PRINTER_STOPPED
					IPP_ERROR
					IPP_IDLE
					IPP_HEADER
					IPP_ATTRIBUTE
					IPP_DATA
					IPP_PRINT_JOB
					IPP_PRINT_URI
					IPP_VALIDATE_JOB
					IPP_CREATE_JOB
					IPP_SEND_DOCUMENT
					IPP_SEND_URI
					IPP_CANCEL_JOB
					IPP_GET_JOB_ATTRIBUTES
					IPP_GET_JOBS
					IPP_GET_PRINTER_ATTRIBUTES
					IPP_HOLD_JOB
					IPP_RELEASE_JOB
					IPP_RESTART_JOB
					IPP_PAUSE_PRINTER
					IPP_RESUME_PRINTER
					IPP_PURGE_JOBS
					IPP_SET_PRINTER_ATTRIBUTES
					IPP_SET_JOB_ATTRIBUTES
					IPP_GET_PRINTER_SUPPORTED_VALUES
					IPP_CREATE_PRINTER_SUBSCRIPTION
					IPP_CREATE_JOB_SUBSCRIPTION
					IPP_GET_SUBSCRIPTION_ATTRIBUTES
					IPP_GET_SUBSCRIPTIONS
					IPP_RENEW_SUBSCRIPTION
					IPP_CANCEL_SUBSCRIPTION
					IPP_GET_NOTIFICATIONS
					IPP_SEND_NOTIFICATIONS
					IPP_GET_PRINT_SUPPORT_FILES
					IPP_ENABLE_PRINTER
					IPP_DISABLE_PRINTER
					IPP_PAUSE_PRINTER_AFTER_CURRENT_JOB
					IPP_HOLD_NEW_JOBS
					IPP_RELEASE_HELD_NEW_JOBS
					IPP_DEACTIVATE_PRINTER
					IPP_ACTIVATE_PRINTER
					IPP_RESTART_PRINTER
					IPP_SHUTDOWN_PRINTER
					IPP_STARTUP_PRINTER
					IPP_REPROCESS_JOB
					IPP_CANCEL_CURRENT_JOB
					IPP_SUSPEND_CURRENT_JOB
					IPP_RESUME_JOB
					IPP_PROMOTE_JOB
					IPP_SCHEDULE_JOB_AFTER
					IPP_PRIVATE
					CUPS_GET_DEFAULT
					CUPS_GET_PRINTERS
					CUPS_ADD_PRINTER
					CUPS_DELETE_PRINTER
					CUPS_GET_CLASSES
					CUPS_ADD_CLASS
					CUPS_DELETE_CLASS
					CUPS_ACCEPT_JOBS
					CUPS_REJECT_JOBS
					CUPS_SET_DEFAULT
					CUPS_GET_DEVICES
					CUPS_GET_PPDS
					CUPS_MOVE_JOB
					CUPS_ADD_DEVICE
					CUPS_DELETE_DEVICE

					IPP_OK
					IPP_OK_SUBST
					IPP_OK_CONFLICT
					IPP_OK_IGNORED_SUBSCRIPTIONS
					IPP_OK_IGNORED_NOTIFICATIONS
					IPP_OK_TOO_MANY_EVENTS
					IPP_REDIRECTION_OTHER_SITE
					IPP_BAD_REQUEST
					IPP_FORBIDDEN
					IPP_NOT_AUTHENTICATED
					IPP_NOT_AUTHORIZED
					IPP_NOT_POSSIBLE

					IPP_VERSION
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
		croak( "&NET::CUPS::IPP::constant not defined" );
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

Net::CUPS::IPP - CUPS C API Interface.

=head1 SYNOPSIS

 use Net::CUPS::IPP;

=head1 ABSTRACT

 This is the abstract for this file.
 
=head1 FUNCTIONS

=over 4

=item function

function description goes here.

=back

=head1 DESCRIPTION

Net::CUPS::IPP is an interface to the Common Unix Printing System API.

=head1 AUTHOR

D. Hageman E<lt>dhageman@dracken.comE<gt>

=head1 SEE ALSO

None.

=head1 COPYRIGHT

Copyright (c) 2003-2004 D. Hageman (Dracken Technologies)
All rights reserved.

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
