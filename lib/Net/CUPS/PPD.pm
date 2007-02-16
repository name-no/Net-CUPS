package Net::CUPS::PPD;

##==================================================================##
##  Libraries and Variables                                         ##
##==================================================================##

use 5.006;
use strict;
use warnings;
use Carp;

require Exporter;
use AutoLoader;

use Net::CUPS;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use Net::CUPS ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	AF_LOCAL
	CUPS_ACCEPT_JOBS
	CUPS_ADD_CLASS
	CUPS_ADD_MODIFY_CLASS
	CUPS_ADD_MODIFY_PRINTER
	CUPS_ADD_PRINTER
	CUPS_AUTHENTICATE_JOB
	CUPS_AUTO_ENCODING
	CUPS_BACKEND_AUTH_REQUIRED
	CUPS_BACKEND_CANCEL
	CUPS_BACKEND_FAILED
	CUPS_BACKEND_HOLD
	CUPS_BACKEND_OK
	CUPS_BACKEND_STOP
	CUPS_DATE_ANY
	CUPS_DELETE_CLASS
	CUPS_DELETE_PRINTER
	CUPS_ENCODING_DBCS_END
	CUPS_ENCODING_SBCS_END
	CUPS_ENCODING_VBCS_END
	CUPS_EUC_CN
	CUPS_EUC_JP
	CUPS_EUC_KR
	CUPS_EUC_TW
	CUPS_FILE_GZIP
	CUPS_FILE_NONE
	CUPS_GET_CLASSES
	CUPS_GET_DEFAULT
	CUPS_GET_DEVICES
	CUPS_GET_PPDS
	CUPS_GET_PRINTERS
	CUPS_IMAGE_BLACK
	CUPS_IMAGE_CMY
	CUPS_IMAGE_CMYK
	CUPS_IMAGE_RGB
	CUPS_IMAGE_RGB_CMYK
	CUPS_IMAGE_WHITE
	CUPS_ISO8859_1
	CUPS_ISO8859_10
	CUPS_ISO8859_11
	CUPS_ISO8859_13
	CUPS_ISO8859_14
	CUPS_ISO8859_15
	CUPS_ISO8859_16
	CUPS_ISO8859_2
	CUPS_ISO8859_3
	CUPS_ISO8859_4
	CUPS_ISO8859_5
	CUPS_ISO8859_6
	CUPS_ISO8859_7
	CUPS_ISO8859_8
	CUPS_ISO8859_9
	CUPS_KOI8_R
	CUPS_KOI8_U
	CUPS_MAC_ROMAN
	CUPS_MAX_USTRING
	CUPS_MOVE_JOB
	CUPS_PRINTER_AUTHENTICATED
	CUPS_PRINTER_BIND
	CUPS_PRINTER_BW
	CUPS_PRINTER_CLASS
	CUPS_PRINTER_COLLATE
	CUPS_PRINTER_COLOR
	CUPS_PRINTER_COMMANDS
	CUPS_PRINTER_COPIES
	CUPS_PRINTER_COVER
	CUPS_PRINTER_DEFAULT
	CUPS_PRINTER_DELETE
	CUPS_PRINTER_DUPLEX
	CUPS_PRINTER_FAX
	CUPS_PRINTER_IMPLICIT
	CUPS_PRINTER_LARGE
	CUPS_PRINTER_LOCAL
	CUPS_PRINTER_MEDIUM
	CUPS_PRINTER_NOT_SHARED
	CUPS_PRINTER_OPTIONS
	CUPS_PRINTER_PUNCH
	CUPS_PRINTER_REJECTING
	CUPS_PRINTER_REMOTE
	CUPS_PRINTER_SMALL
	CUPS_PRINTER_SORT
	CUPS_PRINTER_STAPLE
	CUPS_PRINTER_VARIABLE
	CUPS_REJECT_JOBS
	CUPS_SET_DEFAULT
	CUPS_US_ASCII
	CUPS_UTF8
	CUPS_VERSION
	CUPS_VERSION_MAJOR
	CUPS_VERSION_MINOR
	CUPS_VERSION_PATCH
	CUPS_WINDOWS_1250
	CUPS_WINDOWS_1251
	CUPS_WINDOWS_1252
	CUPS_WINDOWS_1253
	CUPS_WINDOWS_1254
	CUPS_WINDOWS_1255
	CUPS_WINDOWS_1256
	CUPS_WINDOWS_1257
	CUPS_WINDOWS_1258
	CUPS_WINDOWS_1361
	CUPS_WINDOWS_874
	CUPS_WINDOWS_932
	CUPS_WINDOWS_936
	CUPS_WINDOWS_949
	CUPS_WINDOWS_950
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
	HTTP_ENCODE_FIELDS
	HTTP_ENCODE_LENGTH
	HTTP_ENCRYPT_ALWAYS
	HTTP_ENCRYPT_IF_REQUESTED
	HTTP_ENCRYPT_NEVER
	HTTP_ENCRYPT_REQUIRED
	HTTP_ERROR
	HTTP_EXPECTATION_FAILED
	HTTP_FIELD_ACCEPT_LANGUAGE
	HTTP_FIELD_ACCEPT_RANGES
	HTTP_FIELD_AUTHORIZATION
	HTTP_FIELD_CONNECTION
	HTTP_FIELD_CONTENT_ENCODING
	HTTP_FIELD_CONTENT_LANGUAGE
	HTTP_FIELD_CONTENT_LENGTH
	HTTP_FIELD_CONTENT_LOCATION
	HTTP_FIELD_CONTENT_MD5
	HTTP_FIELD_CONTENT_RANGE
	HTTP_FIELD_CONTENT_TYPE
	HTTP_FIELD_CONTENT_VERSION
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
	HTTP_PARTIAL_CONTENT
	HTTP_PAYMENT_REQUIRED
	HTTP_POST
	HTTP_POST_RECV
	HTTP_POST_SEND
	HTTP_PRECONDITION
	HTTP_PROXY_AUTHENTICATION
	HTTP_PUT
	HTTP_PUT_RECV
	HTTP_REQUESTED_RANGE
	HTTP_REQUEST_TIMEOUT
	HTTP_REQUEST_TOO_LARGE
	HTTP_RESET_CONTENT
	HTTP_SEE_OTHER
	HTTP_SERVER_ERROR
	HTTP_SERVICE_UNAVAILABLE
	HTTP_STATUS
	HTTP_SWITCHING_PROTOCOLS
	HTTP_TRACE
	HTTP_UNAUTHORIZED
	HTTP_UNSUPPORTED_MEDIATYPE
	HTTP_UPGRADE_REQUIRED
	HTTP_URI_BAD_ARGUMENTS
	HTTP_URI_BAD_HOSTNAME
	HTTP_URI_BAD_PORT
	HTTP_URI_BAD_RESOURCE
	HTTP_URI_BAD_SCHEME
	HTTP_URI_BAD_URI
	HTTP_URI_BAD_USERNAME
	HTTP_URI_CODING_ALL
	HTTP_URI_CODING_HOSTNAME
	HTTP_URI_CODING_MOST
	HTTP_URI_CODING_NONE
	HTTP_URI_CODING_QUERY
	HTTP_URI_CODING_RESOURCE
	HTTP_URI_CODING_USERNAME
	HTTP_URI_MISSING_RESOURCE
	HTTP_URI_MISSING_SCHEME
	HTTP_URI_OK
	HTTP_URI_OVERFLOW
	HTTP_URI_TOO_LONG
	HTTP_URI_UNKNOWN_SCHEME
	HTTP_USE_PROXY
	HTTP_WAITING
	INET6
	IPP_ACTIVATE_PRINTER
	IPP_ATTRIBUTE
	IPP_ATTRIBUTES
	IPP_ATTRIBUTES_NOT_SETTABLE
	IPP_BAD_REQUEST
	IPP_CANCEL_CURRENT_JOB
	IPP_CANCEL_JOB
	IPP_CANCEL_SUBSCRIPTION
	IPP_CHARSET
	IPP_COMPRESSION_ERROR
	IPP_COMPRESSION_NOT_SUPPORTED
	IPP_CONFLICT
	IPP_CREATE_JOB
	IPP_CREATE_JOB_SUBSCRIPTION
	IPP_CREATE_PRINTER_SUBSCRIPTION
	IPP_DATA
	IPP_DEACTIVATE_PRINTER
	IPP_DEVICE_ERROR
	IPP_DISABLE_PRINTER
	IPP_DOCUMENT_ACCESS_ERROR
	IPP_DOCUMENT_FORMAT
	IPP_DOCUMENT_FORMAT_ERROR
	IPP_ENABLE_PRINTER
	IPP_ERROR
	IPP_ERROR_JOB_CANCELED
	IPP_ERROR_JOB_CANCELLED
	IPP_FINISHINGS_BALE
	IPP_FINISHINGS_BIND
	IPP_FINISHINGS_BIND_BOTTOM
	IPP_FINISHINGS_BIND_LEFT
	IPP_FINISHINGS_BIND_RIGHT
	IPP_FINISHINGS_BIND_TOP
	IPP_FINISHINGS_BOOKLET_MAKER
	IPP_FINISHINGS_COVER
	IPP_FINISHINGS_EDGE_STITCH
	IPP_FINISHINGS_EDGE_STITCH_BOTTOM
	IPP_FINISHINGS_EDGE_STITCH_LEFT
	IPP_FINISHINGS_EDGE_STITCH_RIGHT
	IPP_FINISHINGS_EDGE_STITCH_TOP
	IPP_FINISHINGS_FOLD
	IPP_FINISHINGS_JOB_OFFSET
	IPP_FINISHINGS_NONE
	IPP_FINISHINGS_PUNCH
	IPP_FINISHINGS_SADDLE_STITCH
	IPP_FINISHINGS_STAPLE
	IPP_FINISHINGS_STAPLE_BOTTOM_LEFT
	IPP_FINISHINGS_STAPLE_BOTTOM_RIGHT
	IPP_FINISHINGS_STAPLE_DUAL_BOTTOM
	IPP_FINISHINGS_STAPLE_DUAL_LEFT
	IPP_FINISHINGS_STAPLE_DUAL_RIGHT
	IPP_FINISHINGS_STAPLE_DUAL_TOP
	IPP_FINISHINGS_STAPLE_TOP_LEFT
	IPP_FINISHINGS_STAPLE_TOP_RIGHT
	IPP_FINISHINGS_TRIM
	IPP_FORBIDDEN
	IPP_GET_JOBS
	IPP_GET_JOB_ATTRIBUTES
	IPP_GET_NOTIFICATIONS
	IPP_GET_PRINTER_ATTRIBUTES
	IPP_GET_PRINTER_SUPPORTED_VALUES
	IPP_GET_PRINT_SUPPORT_FILES
	IPP_GET_SUBSCRIPTIONS
	IPP_GET_SUBSCRIPTION_ATTRIBUTES
	IPP_GONE
	IPP_HEADER
	IPP_HOLD_JOB
	IPP_HOLD_NEW_JOBS
	IPP_IDLE
	IPP_IGNORED_ALL_NOTIFICATIONS
	IPP_IGNORED_ALL_SUBSCRIPTIONS
	IPP_INTERNAL_ERROR
	IPP_JOB_ABORTED
	IPP_JOB_CANCELED
	IPP_JOB_CANCELLED
	IPP_JOB_COMPLETED
	IPP_JOB_HELD
	IPP_JOB_PENDING
	IPP_JOB_PROCESSING
	IPP_JOB_STOPPED
	IPP_LANDSCAPE
	IPP_MAX_NAME
	IPP_MAX_VALUES
	IPP_MULTIPLE_JOBS_NOT_SUPPORTED
	IPP_NOT_ACCEPTING
	IPP_NOT_AUTHENTICATED
	IPP_NOT_AUTHORIZED
	IPP_NOT_FOUND
	IPP_NOT_POSSIBLE
	IPP_OK
	IPP_OK_BUT_CANCEL_SUBSCRIPTION
	IPP_OK_CONFLICT
	IPP_OK_EVENTS_COMPLETE
	IPP_OK_IGNORED_NOTIFICATIONS
	IPP_OK_IGNORED_SUBSCRIPTIONS
	IPP_OK_SUBST
	IPP_OK_TOO_MANY_EVENTS
	IPP_OPERATION_NOT_SUPPORTED
	IPP_PAUSE_PRINTER
	IPP_PAUSE_PRINTER_AFTER_CURRENT_JOB
	IPP_PORT
	IPP_PORTRAIT
	IPP_PRINTER_BUSY
	IPP_PRINTER_IDLE
	IPP_PRINTER_IS_DEACTIVATED
	IPP_PRINTER_PROCESSING
	IPP_PRINTER_STOPPED
	IPP_PRINT_JOB
	IPP_PRINT_SUPPORT_FILE_NOT_FOUND
	IPP_PRINT_URI
	IPP_PRIVATE
	IPP_PROMOTE_JOB
	IPP_PURGE_JOBS
	IPP_QUALITY_DRAFT
	IPP_QUALITY_HIGH
	IPP_QUALITY_NORMAL
	IPP_REDIRECTION_OTHER_SITE
	IPP_RELEASE_HELD_NEW_JOBS
	IPP_RELEASE_JOB
	IPP_RENEW_SUBSCRIPTION
	IPP_REPROCESS_JOB
	IPP_REQUEST_ENTITY
	IPP_REQUEST_VALUE
	IPP_RESTART_JOB
	IPP_RESTART_PRINTER
	IPP_RESUME_JOB
	IPP_RESUME_PRINTER
	IPP_RES_PER_CM
	IPP_RES_PER_INCH
	IPP_REVERSE_LANDSCAPE
	IPP_REVERSE_PORTRAIT
	IPP_SCHEDULE_JOB_AFTER
	IPP_SEND_DOCUMENT
	IPP_SEND_NOTIFICATIONS
	IPP_SEND_URI
	IPP_SERVICE_UNAVAILABLE
	IPP_SET_JOB_ATTRIBUTES
	IPP_SET_PRINTER_ATTRIBUTES
	IPP_SHUTDOWN_PRINTER
	IPP_STARTUP_PRINTER
	IPP_SUSPEND_CURRENT_JOB
	IPP_TAG_ADMINDEFINE
	IPP_TAG_BEGIN_COLLECTION
	IPP_TAG_BOOLEAN
	IPP_TAG_CHARSET
	IPP_TAG_COPY
	IPP_TAG_DATE
	IPP_TAG_DEFAULT
	IPP_TAG_DELETEATTR
	IPP_TAG_END
	IPP_TAG_END_COLLECTION
	IPP_TAG_ENUM
	IPP_TAG_EVENT_NOTIFICATION
	IPP_TAG_INTEGER
	IPP_TAG_JOB
	IPP_TAG_KEYWORD
	IPP_TAG_LANGUAGE
	IPP_TAG_MASK
	IPP_TAG_MEMBERNAME
	IPP_TAG_MIMETYPE
	IPP_TAG_NAME
	IPP_TAG_NAMELANG
	IPP_TAG_NOTSETTABLE
	IPP_TAG_NOVALUE
	IPP_TAG_OPERATION
	IPP_TAG_PRINTER
	IPP_TAG_RANGE
	IPP_TAG_RESOLUTION
	IPP_TAG_STRING
	IPP_TAG_SUBSCRIPTION
	IPP_TAG_TEXT
	IPP_TAG_TEXTLANG
	IPP_TAG_UNKNOWN
	IPP_TAG_UNSUPPORTED_GROUP
	IPP_TAG_UNSUPPORTED_VALUE
	IPP_TAG_URI
	IPP_TAG_URISCHEME
	IPP_TAG_ZERO
	IPP_TEMPORARY_ERROR
	IPP_TIMEOUT
	IPP_TOO_MANY_SUBSCRIPTIONS
	IPP_URI_SCHEME
	IPP_VALIDATE_JOB
	IPP_VERSION_NOT_SUPPORTED
	PPD_ALLOC_ERROR
	PPD_BAD_CUSTOM_PARAM
	PPD_BAD_OPEN_GROUP
	PPD_BAD_OPEN_UI
	PPD_BAD_ORDER_DEPENDENCY
	PPD_BAD_UI_CONSTRAINTS
	PPD_CONFORM_RELAXED
	PPD_CONFORM_STRICT
	PPD_CS_CMY
	PPD_CS_CMYK
	PPD_CS_GRAY
	PPD_CS_N
	PPD_CS_RGB
	PPD_CS_RGBK
	PPD_CUSTOM_CURVE
	PPD_CUSTOM_INT
	PPD_CUSTOM_INVCURVE
	PPD_CUSTOM_PASSCODE
	PPD_CUSTOM_PASSWORD
	PPD_CUSTOM_POINTS
	PPD_CUSTOM_REAL
	PPD_CUSTOM_STRING
	PPD_FILE_OPEN_ERROR
	PPD_ILLEGAL_CHARACTER
	PPD_ILLEGAL_MAIN_KEYWORD
	PPD_ILLEGAL_OPTION_KEYWORD
	PPD_ILLEGAL_TRANSLATION
	PPD_ILLEGAL_WHITESPACE
	PPD_INTERNAL_ERROR
	PPD_LINE_TOO_LONG
	PPD_MAX_LINE
	PPD_MAX_NAME
	PPD_MAX_TEXT
	PPD_MISSING_ASTERISK
	PPD_MISSING_PPDADOBE4
	PPD_MISSING_VALUE
	PPD_NESTED_OPEN_GROUP
	PPD_NESTED_OPEN_UI
	PPD_NULL_FILE
	PPD_OK
	PPD_ORDER_ANY
	PPD_ORDER_DOCUMENT
	PPD_ORDER_EXIT
	PPD_ORDER_JCL
	PPD_ORDER_PAGE
	PPD_ORDER_PROLOG
	PPD_UI_BOOLEAN
	PPD_UI_PICKMANY
	PPD_UI_PICKONE
	PPD_VERSION
	_CUPS_DEPRECATED
	_HTTP_DEPRECATED
	s6_addr32
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	AF_LOCAL
	CUPS_ACCEPT_JOBS
	CUPS_ADD_CLASS
	CUPS_ADD_MODIFY_CLASS
	CUPS_ADD_MODIFY_PRINTER
	CUPS_ADD_PRINTER
	CUPS_AUTHENTICATE_JOB
	CUPS_AUTO_ENCODING
	CUPS_BACKEND_AUTH_REQUIRED
	CUPS_BACKEND_CANCEL
	CUPS_BACKEND_FAILED
	CUPS_BACKEND_HOLD
	CUPS_BACKEND_OK
	CUPS_BACKEND_STOP
	CUPS_DATE_ANY
	CUPS_DELETE_CLASS
	CUPS_DELETE_PRINTER
	CUPS_ENCODING_DBCS_END
	CUPS_ENCODING_SBCS_END
	CUPS_ENCODING_VBCS_END
	CUPS_EUC_CN
	CUPS_EUC_JP
	CUPS_EUC_KR
	CUPS_EUC_TW
	CUPS_FILE_GZIP
	CUPS_FILE_NONE
	CUPS_GET_CLASSES
	CUPS_GET_DEFAULT
	CUPS_GET_DEVICES
	CUPS_GET_PPDS
	CUPS_GET_PRINTERS
	CUPS_IMAGE_BLACK
	CUPS_IMAGE_CMY
	CUPS_IMAGE_CMYK
	CUPS_IMAGE_RGB
	CUPS_IMAGE_RGB_CMYK
	CUPS_IMAGE_WHITE
	CUPS_ISO8859_1
	CUPS_ISO8859_10
	CUPS_ISO8859_11
	CUPS_ISO8859_13
	CUPS_ISO8859_14
	CUPS_ISO8859_15
	CUPS_ISO8859_16
	CUPS_ISO8859_2
	CUPS_ISO8859_3
	CUPS_ISO8859_4
	CUPS_ISO8859_5
	CUPS_ISO8859_6
	CUPS_ISO8859_7
	CUPS_ISO8859_8
	CUPS_ISO8859_9
	CUPS_KOI8_R
	CUPS_KOI8_U
	CUPS_MAC_ROMAN
	CUPS_MAX_USTRING
	CUPS_MOVE_JOB
	CUPS_PRINTER_AUTHENTICATED
	CUPS_PRINTER_BIND
	CUPS_PRINTER_BW
	CUPS_PRINTER_CLASS
	CUPS_PRINTER_COLLATE
	CUPS_PRINTER_COLOR
	CUPS_PRINTER_COMMANDS
	CUPS_PRINTER_COPIES
	CUPS_PRINTER_COVER
	CUPS_PRINTER_DEFAULT
	CUPS_PRINTER_DELETE
	CUPS_PRINTER_DUPLEX
	CUPS_PRINTER_FAX
	CUPS_PRINTER_IMPLICIT
	CUPS_PRINTER_LARGE
	CUPS_PRINTER_LOCAL
	CUPS_PRINTER_MEDIUM
	CUPS_PRINTER_NOT_SHARED
	CUPS_PRINTER_OPTIONS
	CUPS_PRINTER_PUNCH
	CUPS_PRINTER_REJECTING
	CUPS_PRINTER_REMOTE
	CUPS_PRINTER_SMALL
	CUPS_PRINTER_SORT
	CUPS_PRINTER_STAPLE
	CUPS_PRINTER_VARIABLE
	CUPS_REJECT_JOBS
	CUPS_SET_DEFAULT
	CUPS_US_ASCII
	CUPS_UTF8
	CUPS_VERSION
	CUPS_VERSION_MAJOR
	CUPS_VERSION_MINOR
	CUPS_VERSION_PATCH
	CUPS_WINDOWS_1250
	CUPS_WINDOWS_1251
	CUPS_WINDOWS_1252
	CUPS_WINDOWS_1253
	CUPS_WINDOWS_1254
	CUPS_WINDOWS_1255
	CUPS_WINDOWS_1256
	CUPS_WINDOWS_1257
	CUPS_WINDOWS_1258
	CUPS_WINDOWS_1361
	CUPS_WINDOWS_874
	CUPS_WINDOWS_932
	CUPS_WINDOWS_936
	CUPS_WINDOWS_949
	CUPS_WINDOWS_950
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
	HTTP_ENCODE_FIELDS
	HTTP_ENCODE_LENGTH
	HTTP_ENCRYPT_ALWAYS
	HTTP_ENCRYPT_IF_REQUESTED
	HTTP_ENCRYPT_NEVER
	HTTP_ENCRYPT_REQUIRED
	HTTP_ERROR
	HTTP_EXPECTATION_FAILED
	HTTP_FIELD_ACCEPT_LANGUAGE
	HTTP_FIELD_ACCEPT_RANGES
	HTTP_FIELD_AUTHORIZATION
	HTTP_FIELD_CONNECTION
	HTTP_FIELD_CONTENT_ENCODING
	HTTP_FIELD_CONTENT_LANGUAGE
	HTTP_FIELD_CONTENT_LENGTH
	HTTP_FIELD_CONTENT_LOCATION
	HTTP_FIELD_CONTENT_MD5
	HTTP_FIELD_CONTENT_RANGE
	HTTP_FIELD_CONTENT_TYPE
	HTTP_FIELD_CONTENT_VERSION
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
	HTTP_PARTIAL_CONTENT
	HTTP_PAYMENT_REQUIRED
	HTTP_POST
	HTTP_POST_RECV
	HTTP_POST_SEND
	HTTP_PRECONDITION
	HTTP_PROXY_AUTHENTICATION
	HTTP_PUT
	HTTP_PUT_RECV
	HTTP_REQUESTED_RANGE
	HTTP_REQUEST_TIMEOUT
	HTTP_REQUEST_TOO_LARGE
	HTTP_RESET_CONTENT
	HTTP_SEE_OTHER
	HTTP_SERVER_ERROR
	HTTP_SERVICE_UNAVAILABLE
	HTTP_STATUS
	HTTP_SWITCHING_PROTOCOLS
	HTTP_TRACE
	HTTP_UNAUTHORIZED
	HTTP_UNSUPPORTED_MEDIATYPE
	HTTP_UPGRADE_REQUIRED
	HTTP_URI_BAD_ARGUMENTS
	HTTP_URI_BAD_HOSTNAME
	HTTP_URI_BAD_PORT
	HTTP_URI_BAD_RESOURCE
	HTTP_URI_BAD_SCHEME
	HTTP_URI_BAD_URI
	HTTP_URI_BAD_USERNAME
	HTTP_URI_CODING_ALL
	HTTP_URI_CODING_HOSTNAME
	HTTP_URI_CODING_MOST
	HTTP_URI_CODING_NONE
	HTTP_URI_CODING_QUERY
	HTTP_URI_CODING_RESOURCE
	HTTP_URI_CODING_USERNAME
	HTTP_URI_MISSING_RESOURCE
	HTTP_URI_MISSING_SCHEME
	HTTP_URI_OK
	HTTP_URI_OVERFLOW
	HTTP_URI_TOO_LONG
	HTTP_URI_UNKNOWN_SCHEME
	HTTP_USE_PROXY
	HTTP_WAITING
	INET6
	IPP_ACTIVATE_PRINTER
	IPP_ATTRIBUTE
	IPP_ATTRIBUTES
	IPP_ATTRIBUTES_NOT_SETTABLE
	IPP_BAD_REQUEST
	IPP_CANCEL_CURRENT_JOB
	IPP_CANCEL_JOB
	IPP_CANCEL_SUBSCRIPTION
	IPP_CHARSET
	IPP_COMPRESSION_ERROR
	IPP_COMPRESSION_NOT_SUPPORTED
	IPP_CONFLICT
	IPP_CREATE_JOB
	IPP_CREATE_JOB_SUBSCRIPTION
	IPP_CREATE_PRINTER_SUBSCRIPTION
	IPP_DATA
	IPP_DEACTIVATE_PRINTER
	IPP_DEVICE_ERROR
	IPP_DISABLE_PRINTER
	IPP_DOCUMENT_ACCESS_ERROR
	IPP_DOCUMENT_FORMAT
	IPP_DOCUMENT_FORMAT_ERROR
	IPP_ENABLE_PRINTER
	IPP_ERROR
	IPP_ERROR_JOB_CANCELED
	IPP_ERROR_JOB_CANCELLED
	IPP_FINISHINGS_BALE
	IPP_FINISHINGS_BIND
	IPP_FINISHINGS_BIND_BOTTOM
	IPP_FINISHINGS_BIND_LEFT
	IPP_FINISHINGS_BIND_RIGHT
	IPP_FINISHINGS_BIND_TOP
	IPP_FINISHINGS_BOOKLET_MAKER
	IPP_FINISHINGS_COVER
	IPP_FINISHINGS_EDGE_STITCH
	IPP_FINISHINGS_EDGE_STITCH_BOTTOM
	IPP_FINISHINGS_EDGE_STITCH_LEFT
	IPP_FINISHINGS_EDGE_STITCH_RIGHT
	IPP_FINISHINGS_EDGE_STITCH_TOP
	IPP_FINISHINGS_FOLD
	IPP_FINISHINGS_JOB_OFFSET
	IPP_FINISHINGS_NONE
	IPP_FINISHINGS_PUNCH
	IPP_FINISHINGS_SADDLE_STITCH
	IPP_FINISHINGS_STAPLE
	IPP_FINISHINGS_STAPLE_BOTTOM_LEFT
	IPP_FINISHINGS_STAPLE_BOTTOM_RIGHT
	IPP_FINISHINGS_STAPLE_DUAL_BOTTOM
	IPP_FINISHINGS_STAPLE_DUAL_LEFT
	IPP_FINISHINGS_STAPLE_DUAL_RIGHT
	IPP_FINISHINGS_STAPLE_DUAL_TOP
	IPP_FINISHINGS_STAPLE_TOP_LEFT
	IPP_FINISHINGS_STAPLE_TOP_RIGHT
	IPP_FINISHINGS_TRIM
	IPP_FORBIDDEN
	IPP_GET_JOBS
	IPP_GET_JOB_ATTRIBUTES
	IPP_GET_NOTIFICATIONS
	IPP_GET_PRINTER_ATTRIBUTES
	IPP_GET_PRINTER_SUPPORTED_VALUES
	IPP_GET_PRINT_SUPPORT_FILES
	IPP_GET_SUBSCRIPTIONS
	IPP_GET_SUBSCRIPTION_ATTRIBUTES
	IPP_GONE
	IPP_HEADER
	IPP_HOLD_JOB
	IPP_HOLD_NEW_JOBS
	IPP_IDLE
	IPP_IGNORED_ALL_NOTIFICATIONS
	IPP_IGNORED_ALL_SUBSCRIPTIONS
	IPP_INTERNAL_ERROR
	IPP_JOB_ABORTED
	IPP_JOB_CANCELED
	IPP_JOB_CANCELLED
	IPP_JOB_COMPLETED
	IPP_JOB_HELD
	IPP_JOB_PENDING
	IPP_JOB_PROCESSING
	IPP_JOB_STOPPED
	IPP_LANDSCAPE
	IPP_MAX_NAME
	IPP_MAX_VALUES
	IPP_MULTIPLE_JOBS_NOT_SUPPORTED
	IPP_NOT_ACCEPTING
	IPP_NOT_AUTHENTICATED
	IPP_NOT_AUTHORIZED
	IPP_NOT_FOUND
	IPP_NOT_POSSIBLE
	IPP_OK
	IPP_OK_BUT_CANCEL_SUBSCRIPTION
	IPP_OK_CONFLICT
	IPP_OK_EVENTS_COMPLETE
	IPP_OK_IGNORED_NOTIFICATIONS
	IPP_OK_IGNORED_SUBSCRIPTIONS
	IPP_OK_SUBST
	IPP_OK_TOO_MANY_EVENTS
	IPP_OPERATION_NOT_SUPPORTED
	IPP_PAUSE_PRINTER
	IPP_PAUSE_PRINTER_AFTER_CURRENT_JOB
	IPP_PORT
	IPP_PORTRAIT
	IPP_PRINTER_BUSY
	IPP_PRINTER_IDLE
	IPP_PRINTER_IS_DEACTIVATED
	IPP_PRINTER_PROCESSING
	IPP_PRINTER_STOPPED
	IPP_PRINT_JOB
	IPP_PRINT_SUPPORT_FILE_NOT_FOUND
	IPP_PRINT_URI
	IPP_PRIVATE
	IPP_PROMOTE_JOB
	IPP_PURGE_JOBS
	IPP_QUALITY_DRAFT
	IPP_QUALITY_HIGH
	IPP_QUALITY_NORMAL
	IPP_REDIRECTION_OTHER_SITE
	IPP_RELEASE_HELD_NEW_JOBS
	IPP_RELEASE_JOB
	IPP_RENEW_SUBSCRIPTION
	IPP_REPROCESS_JOB
	IPP_REQUEST_ENTITY
	IPP_REQUEST_VALUE
	IPP_RESTART_JOB
	IPP_RESTART_PRINTER
	IPP_RESUME_JOB
	IPP_RESUME_PRINTER
	IPP_RES_PER_CM
	IPP_RES_PER_INCH
	IPP_REVERSE_LANDSCAPE
	IPP_REVERSE_PORTRAIT
	IPP_SCHEDULE_JOB_AFTER
	IPP_SEND_DOCUMENT
	IPP_SEND_NOTIFICATIONS
	IPP_SEND_URI
	IPP_SERVICE_UNAVAILABLE
	IPP_SET_JOB_ATTRIBUTES
	IPP_SET_PRINTER_ATTRIBUTES
	IPP_SHUTDOWN_PRINTER
	IPP_STARTUP_PRINTER
	IPP_SUSPEND_CURRENT_JOB
	IPP_TAG_ADMINDEFINE
	IPP_TAG_BEGIN_COLLECTION
	IPP_TAG_BOOLEAN
	IPP_TAG_CHARSET
	IPP_TAG_COPY
	IPP_TAG_DATE
	IPP_TAG_DEFAULT
	IPP_TAG_DELETEATTR
	IPP_TAG_END
	IPP_TAG_END_COLLECTION
	IPP_TAG_ENUM
	IPP_TAG_EVENT_NOTIFICATION
	IPP_TAG_INTEGER
	IPP_TAG_JOB
	IPP_TAG_KEYWORD
	IPP_TAG_LANGUAGE
	IPP_TAG_MASK
	IPP_TAG_MEMBERNAME
	IPP_TAG_MIMETYPE
	IPP_TAG_NAME
	IPP_TAG_NAMELANG
	IPP_TAG_NOTSETTABLE
	IPP_TAG_NOVALUE
	IPP_TAG_OPERATION
	IPP_TAG_PRINTER
	IPP_TAG_RANGE
	IPP_TAG_RESOLUTION
	IPP_TAG_STRING
	IPP_TAG_SUBSCRIPTION
	IPP_TAG_TEXT
	IPP_TAG_TEXTLANG
	IPP_TAG_UNKNOWN
	IPP_TAG_UNSUPPORTED_GROUP
	IPP_TAG_UNSUPPORTED_VALUE
	IPP_TAG_URI
	IPP_TAG_URISCHEME
	IPP_TAG_ZERO
	IPP_TEMPORARY_ERROR
	IPP_TIMEOUT
	IPP_TOO_MANY_SUBSCRIPTIONS
	IPP_URI_SCHEME
	IPP_VALIDATE_JOB
	IPP_VERSION_NOT_SUPPORTED
	PPD_ALLOC_ERROR
	PPD_BAD_CUSTOM_PARAM
	PPD_BAD_OPEN_GROUP
	PPD_BAD_OPEN_UI
	PPD_BAD_ORDER_DEPENDENCY
	PPD_BAD_UI_CONSTRAINTS
	PPD_CONFORM_RELAXED
	PPD_CONFORM_STRICT
	PPD_CS_CMY
	PPD_CS_CMYK
	PPD_CS_GRAY
	PPD_CS_N
	PPD_CS_RGB
	PPD_CS_RGBK
	PPD_CUSTOM_CURVE
	PPD_CUSTOM_INT
	PPD_CUSTOM_INVCURVE
	PPD_CUSTOM_PASSCODE
	PPD_CUSTOM_PASSWORD
	PPD_CUSTOM_POINTS
	PPD_CUSTOM_REAL
	PPD_CUSTOM_STRING
	PPD_FILE_OPEN_ERROR
	PPD_ILLEGAL_CHARACTER
	PPD_ILLEGAL_MAIN_KEYWORD
	PPD_ILLEGAL_OPTION_KEYWORD
	PPD_ILLEGAL_TRANSLATION
	PPD_ILLEGAL_WHITESPACE
	PPD_INTERNAL_ERROR
	PPD_LINE_TOO_LONG
	PPD_MAX_LINE
	PPD_MAX_NAME
	PPD_MAX_TEXT
	PPD_MISSING_ASTERISK
	PPD_MISSING_PPDADOBE4
	PPD_MISSING_VALUE
	PPD_NESTED_OPEN_GROUP
	PPD_NESTED_OPEN_UI
	PPD_NULL_FILE
	PPD_OK
	PPD_ORDER_ANY
	PPD_ORDER_DOCUMENT
	PPD_ORDER_EXIT
	PPD_ORDER_JCL
	PPD_ORDER_PAGE
	PPD_ORDER_PROLOG
	PPD_UI_BOOLEAN
	PPD_UI_PICKMANY
	PPD_UI_PICKONE
	PPD_VERSION
);

our $VERSION = '0.50';

sub AUTOLOAD {
    # This AUTOLOAD is used to 'autoload' constants from the constant()
    # XS function.

    my $constname;
    our $AUTOLOAD;
    ($constname = $AUTOLOAD) =~ s/.*:://;
    croak "&Net::CUPS::PPD::constant not defined" if $constname eq 'constant';
    my ($error, $val) = constant($constname);
    if ($error) { croak $error; }
    {
	no strict 'refs';
	# Fixed between 5.005_53 and 5.005_61
#XXX	if ($] >= 5.00561) {
#XXX	    *$AUTOLOAD = sub () { $val };
#XXX	}
#XXX	else {
	    *$AUTOLOAD = sub { $val };
#XXX	}
    }
    goto &$AUTOLOAD;
}

#require XSLoader;
#XSLoader::load('Net::CUPS', $VERSION);

##==================================================================##
##  Constructors                                                    ##
##==================================================================##

##----------------------------------------------##
##  new                                         ##
##----------------------------------------------##
sub new
{
	## Pull in what type of an object we will be
	my $type = shift;
	## Pull in our options if we have any ...
	my %options = @_;
	## XXX One of the options might be a server host ...
	## We will use a hash as our base class variable
	my $self = {};
	my $class = ref( $type ) || $type;
	## Bless the class for it is good [tm].
	bless( $self, $class );
	return( $self );
}

##----------------------------------------------##
##  DESTROY                                     ##
##----------------------------------------------##
sub DESTROY
{
	my $self = shift;

	NETCUPS_freePPD( $self );

	return;
}

##==================================================================##
##  Methods                                                         ##
##==================================================================##

##----------------------------------------------##
##  getCustomOption                             ##
##----------------------------------------------##
#sub getCustomOption
#{
#	my( $self, $keyword ) = @_;
#
#	return( NETCUPS_getCustomOption( $self, $keyword ) );
#}


##----------------------------------------------##
##  getFirstOption                              ##
##----------------------------------------------##
sub getFirstOption
{
	my $self = shift;

	return( NETCUPS_getFirstOption( $self ) );
}

##----------------------------------------------##
##  getNextOption                              ##
##----------------------------------------------##
sub getNextOption
{
	my $self = shift;

	return( NETCUPS_getNextOption( $self ) );
}

##----------------------------------------------##
##  getOption                                   ##
##----------------------------------------------##
sub getOption
{
	my( $self, $keyword ) = @_;

	return( NETCUPS_getOption( $self, $keyword ) );
}

##----------------------------------------------##
##  getPageLength                               ##
##----------------------------------------------##
sub getPageLength
{
	my( $self, $size ) = @_;

	return( NETCUPS_getPageLength( $self, $size ) );
}

##----------------------------------------------##
##  getPageSize                                 ##
##----------------------------------------------##
sub getPageSize
{
	my( $self, $size ) = @_;

	return( NETCUPS_getPageSize( $self, $size ) );
}

##----------------------------------------------##
##  getPageWidth                                ##
##----------------------------------------------##
sub getPageWidth
{
	my( $self, $size ) = @_;

	return( NETCUPS_getPageWidth( $self, $size ) );
}

##----------------------------------------------##
##  isMarked                                    ##
##----------------------------------------------##
sub isMarked
{
	my( $self, $option, $choice ) = @_;

	return( NETCUPS_isMarked( $self, $option, $choice ) );
}

##----------------------------------------------##
##  markDefaults                                ##
##----------------------------------------------##
sub markDefaults
{
	my( $self ) = @_;

	return( NETCUPS_markDefaults( $self ) );
}

##----------------------------------------------##
##  markOption                                  ##
##----------------------------------------------##
sub markOption
{
	my( $self, $option, $choice ) = @_;

	return( NETCUPS_markOption( $self, $option, $choice ) );
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

Net::CUPS::PPD - PostScript Printer Definition Object

=head1 SYNOPSIS

  use Net::CUPS;
  use Net::CUPS::PPD;

  my $ppd = $cups->getPPD( "lj4200dn" );

=head1 DESCRIPTION

Net::CUPS is an object oriented interface to the Common Unix Printing System.

Net::CUPS::PPD is an abstraction of methods to deal with 
PostSript Printer Definition files.

=head1 METHODS

=over 4

=item B<getFirstOption>

my $option = $ppd->getFirstOption();

=item B<getNextOption>

my $option = $ppd->getNextOption();

=item B<getOption>

my $option = $ppd->getOption( $keyword );

=item B<getPageLength>

my $length = $ppd->getPageLength();

=item B<getPageSize>

my %size = $ppd->getPageSize();

=item B<getPageWidth>

my $width = $ppd->getPageWidth();

=item B<isMarked>

my $result = $ppd->isMarked( $option, $choice );

=item B<markDefaults>

$ppd->markDefaults();

=item B<markOption>

$ppd->markOption( $option, $choice );

=back

=head1 SEE ALSO

L<Net::CUPS>, L<Net::CUPS::Destination>, L<Net::CUPS::IPP>

=head1 SUPPORT

Support for this module and other software developed by 
Dracken Technology, Inc can be found at http://www.dracken.com/.

=head1 AUTHOR

Dracken Technology, Inc. (http://www.dracken.com/)

=head1 COPYRIGHT AND LICENSE

Copyright (c) 2003-2005 David Hageman 

Copyright (c) 2006-2007 Dracken Technology, Inc.

All rights reserved.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.8.8 or,
at your option, any later version of Perl 5 you may have available.

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
