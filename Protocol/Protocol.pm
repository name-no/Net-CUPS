package Net::CUPS::Protocol;

##==================================================================##
##  Libraries and Variables                                         ##
##==================================================================##

require 5.006;
require Exporter;
require XSLoader;

use strict;
use warnings;

our $VERSION = "0.41";

our @ISA = qw( Exporter );

XSLoader::load( 'Net::CUPS::Protocol', $VERSION );

our @EXPORT = qw(
					CUPS_ACCEPT_JOBS 
					CUPS_ADD_CLASS 
					CUPS_ADD_DEVICE
					CUPS_ADD_PRINTER 
					CUPS_DELETE_CLASS 
					CUPS_DELETE_DEVICE
					CUPS_DELETE_PRINTER 
					CUPS_GET_CLASSES 
					CUPS_GET_DEFAULT
					CUPS_REJECT_JOBS 
					CUPS_SET_DEFAULT
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
					ippNew
					ippErrorString
					HTTP_0_9 
					HTTP_1_0 
					HTTP_1_1
					HTTP_ACCEPTED 
					HTTP_AUTH_BASIC 
					HTTP_AUTH_MD5 
					HTTP_AUTH_MD5_INT
					HTTP_AUTH_MD5_SESS 
					HTTP_AUTH_MD5_SESS_INT 
					HTTP_AUTH_NONE
					HTTP_BAD_GATEWAY 
					HTTP_BAD_REQUEST 
					HTTP_CLOSE 
					HTTP_CONFLICT
					HTTP_CONTINUE 
					HTTP_CREATED 
					HTTP_DELETE 
					HTTP_ENCODE_CHUNKED
					HTTP_ENCODE_LENGTH 
					HTTP_ENCRYPT_ALWAYS 
					HTTP_ENCRYPT_IF_REQUESTED
					HTTP_ENCRYPT_NEVER 
					HTTP_ENCRYPT_REQUIRED 
					HTTP_ERROR
					HTTP_FIELD_ACCEPT_LANGUAGE 
					HTTP_FIELD_ACCEPT_RANGES
					HTTP_FIELD_AUTHORIZATION 
					HTTP_FIELD_CONNECTION
					HTTP_FIELD_CONTENT_ENCODING 
					HTTP_FIELD_CONTENT_LANGUAGE
					HTTP_FIELD_DATE 
					HTTP_FIELD_HOST 
					HTTP_FIELD_IF_MODIFIED_SINCE
					HTTP_FIELD_IF_UNMODIFIED_SINCE 
					HTTP_FIELD_KEEP_ALIVE
					HTTP_FIELD_LAST_MODIFIED 
					HTTP_FIELD_LINK 
					HTTP_FIELD_LOCATION
					HTTP_FIELD_MAX 
					HTTP_FIELD_RANGE 
					HTTP_FIELD_REFERER
					HTTP_FIELD_RETRY_AFTER 
					HTTP_FIELD_TRANSFER_ENCODING
					HTTP_FIELD_UNKNOWN 
					HTTP_FIELD_UPGRADE 
					HTTP_FIELD_USER_AGENT
					HTTP_FIELD_WWW_AUTHENTICATE 
					HTTP_FORBIDDEN 
					HTTP_GATEWAY_TIMEOUT
					HTTP_GET 
					HTTP_GET_SEND 
					HTTP_GONE 
					HTTP_HEAD 
					HTTP_KEEPALIVE_OFF
					HTTP_KEEPALIVE_ON 
					HTTP_LENGTH_REQUIRED 
					HTTP_MAX_BUFFER
					HTTP_MAX_HOST 
					HTTP_MAX_URI 
					HTTP_MAX_VALUE
					HTTP_METHOD_NOT_ALLOWED 
					HTTP_MOVED_PERMANENTLY
					HTTP_MOVED_TEMPORARILY 
					HTTP_MULTIPLE_CHOICES 
					HTTP_NOT_ACCEPTABLE
					HTTP_NOT_AUTHORITATIVE 
					HTTP_NOT_FOUND 
					HTTP_NOT_IMPLEMENTED
					HTTP_NOT_MODIFIED 
					HTTP_NOT_SUPPORTED 
					HTTP_NO_CONTENT 
					HTTP_OK
					HTTP_OPTIONS 
					HTTP_PROXY_AUTHENTICATION 
					HTTP_PARTIAL_CONTENT
					HTTP_PAYMENT_REQUESTED 
					HTTP_POST 
					HTTP_POST_RECV 
					HTTP_POST_SEND
					HTTP_PRECONDITION 
					HTTP_PUT 
					HTTP_PUT_RECV 
					HTTP_REQUEST_TIMEOUT
					HTTP_REQUEST_TOO_LARGE 
					HTTP_RESET_CONTENT 
					HTTP_SEE_OTHER
					HTTP_SERVER_ERROR 
					HTTP_SERVICE_UNAVAILABLE 
					HTTP_STATUS
					HTTP_SWITCHING_PROTOCOLS 
					HTTP_TRACE 
					HTTP_UNAUTHORIZE
					HTTP_UNSUPPORTED_MEDIATYPE
					HTTP_UPGRADE_REQUIRED 
					HTTP_URI_TOO_LONG 
					HTTP_USE_PROXY
					HTTP_WAITING );

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

Net::CUPS::Protocol - CUPS C API Interface.

=head1 SYNOPSIS

 use Net::CUPS::Protocol;

=head1 ABSTRACT

 This is the abstract for this file.

=head1 FUNCTIONS

=over 4

=item function

function description goes here.

=back

=head1 DESCRIPTION

Net::CUPS::Protocol is an interface to the Common Unix Printing System API.

=head1 AUTHOR

D. Hageman E<lt>dhageman@dracken.comE<gt>

=head1 SEE ALSO

None.

=head1 COPYRIGHT

Copyright (c) 2003-2005 D. Hageman 

Copyright (c) 2006 Dracken Technology, Inc.

All rights reserved.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
