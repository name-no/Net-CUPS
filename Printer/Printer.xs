#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <cups/cups.h>
#include <cups/http.h>
#include <cups/image.h>
#include <cups/ipp.h>
#include <cups/language.h>
#include <cups/md5.h>
#include <cups/ppd.h>
#include <cups/raster.h>

void
XS_pack_cups_option_tPTR( SV* s, cups_option_t* option )
{
	SV* sv;
	HV* hv = newHV();
	
/*	hv_store( hv, "name", strlen( "name" ),
			  newSVpv( option->name, 0 ), 0 );
	hv_store( hv, "value", strlen( "value" ),
			  newSVpv( option->value, 0 ), 0 );  */

	hv_store( hv, option->name, strlen( option->name ),
			  newSVpv( option->value, strlen( option->value ) ), 0 );
	
	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	return;
}

void 
XS_pack_cups_dest_tPTR( SV* s, cups_dest_t* dest )
{
	int loop = 0;
	SV* sv;
	SV* option;
	HV* hv = newHV();
	AV* av = newAV();
	
	hv_store( hv, "name", strlen( "name" ),
			  newSVpv( dest->name, 0 ), 0 );

	if( dest->instance != NULL )
	{
		hv_store( hv, "instance", strlen( "instance" ),
				  newSVpv( dest->instance, 0 ), 0 );
	}
	else
	{
		hv_store( hv, "instance", strlen( "instance" ),
				  newSVpv( "", 0 ), 0 );
	}
	
	hv_store( hv, "is_default", strlen( "is_default" ), 
			  newSViv( dest->is_default ), 0 );  
	hv_store( hv, "num_options", strlen( "num_options" ), 
			  newSViv( dest->num_options ), 0 );
	
	for( loop = 0; loop < dest->num_options; loop++ )
	{
		option = sv_newmortal();
		XS_pack_cups_option_tPTR( option, &dest->options[loop] );
		av_push( av,  newSVsv( option ) );
	}
	
	option = newRV( (SV*)av );
	
	hv_store( hv, "options", strlen( "options" ),
			option, 0 );  
	
	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	return;
}

void
XS_pack_cups_job_tPTR( SV* s, cups_job_t* job )
{
	SV* sv;
	HV* hv = newHV();

	hv_store( hv, "id", strlen( "id" ), 
			  newSViv( job->id ), 0 );
	hv_store( hv, "dest", strlen( "dest" ),
			  newSVpv( job->dest, 0 ), 0 );
	hv_store( hv, "title", strlen( "title" ),
			  newSVpv( job->title, 0 ), 0 );
	hv_store( hv, "user", strlen( "user" ),
			  newSVpv( job->user, 0 ), 0 );
	hv_store( hv, "format", strlen( "format" ),
			  newSVpv( job->format, 0 ), 0 );
	hv_store( hv, "state", strlen( "state" ),
			  newSViv( (ipp_jstate_t)job->state ), 0 );
	hv_store( hv, "size", strlen( "size" ), 
			  newSViv( job->size ), 0 );
	hv_store( hv, "priority", strlen( "priority" ), 
			  newSViv( job->priority ), 0 );
	hv_store( hv, "completed_time", strlen( "completed_time" ),
			  newSVnv( job->completed_time ), 0 );
	hv_store( hv, "creation_time", strlen( "creation_time" ),
			  newSVnv( job->creation_time ), 0 );
	hv_store( hv, "processing_time", strlen( "processing_time" ),
			  newSVnv( job->processing_time ), 0 );

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	return;
}

cups_job_t*
XS_unpack_cups_job_tPTR( SV* rv )
{
	cups_job_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv;

	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/*retval = (cups_job_t*)calloc( 1, sizeof( cups_job_t ) );*/
	Newz( 69, retval, 1, cups_job_t );

	/* cups_job_t.id */
	ssv = hv_fetch( hv, "id", strlen( "id" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->id = SvIV( *ssv );
	}

	/* cups_job_t.dest */
	ssv = hv_fetch( hv, "dest", strlen( "dest" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->dest = SvPV_nolen( *ssv );
	}
	
	/* cups_job_t.title */
	ssv = hv_fetch( hv, "title", strlen( "title" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->title = SvPV_nolen( *ssv );
	}
	
	/* cups_job_t.user */
	ssv = hv_fetch( hv, "user", strlen( "user" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->user = SvPV_nolen( *ssv );
	}
	
	/* cups_job_t.format */
	ssv = hv_fetch( hv, "format", strlen( "format" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->format = SvPV_nolen( *ssv );
	}

	/* cups_job_t.state */
	ssv = hv_fetch( hv, "state", strlen( "state" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->state = SvIV( *ssv );
	}

	/* cups_job_t.size */
	ssv = hv_fetch( hv, "size", strlen( "size" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->size = SvIV( *ssv );
	}

	/* cups_job_t.priority */
	ssv = hv_fetch( hv, "priority", strlen( "priority" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->priority = SvIV( *ssv );
	}

	/* cups_job_t.completed_time */
	ssv = hv_fetch( hv, "completed_time", strlen( "completed_time" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->completed_time = SvNV( *ssv );
	}

	/* cups_job_t.creation_time */
	ssv = hv_fetch( hv, "creation_time", strlen( "creation_time" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->creation_time = SvNV( *ssv );
	}

	/* cups_job_t.processing_time */
	ssv = hv_fetch( hv, "processing_time", strlen( "processing_time" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->processing_time = SvNV( *ssv );
	}
	
	return retval;
}

cups_option_t*
XS_unpack_cups_option_tPTR( SV* rv )
{
	int loop = 0;
	int option_count = 0;
	char* key;
	int klen;
	cups_option_t* retval = NULL;
	HV* hv = NULL;
	SV* option;
	SV** ssv;
	
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV(rv);
	}

	if( !hv ) { return NULL; }

	/* Prepare to start iterating through all of the keys */
	option_count = hv_iterinit( hv );
	
	/* Grab some memmory */
	Newz( 42, retval, option_count,  cups_option_t ); 

	for( loop = 0; loop < option_count; loop++ )
	{
		option = hv_iternextsv( hv, &key, (I32*)&klen );
		
		retval[loop].name = strdup( key );	
	
		ssv = hv_fetch( hv, key, klen, 0 );

		if( ssv != NULL )
		{
			if( SvPOK( *ssv ) )
			{
				retval[loop].value = strdup( (char*)SvPV_nolen( *ssv ) );
			}
		}
	}

	return retval;
}
	
MODULE = Net::CUPS::Printer		PACKAGE = Net::CUPS::Printer		

PROTOTYPES: DISABLE

int
cupsCancelJob( destination, job )
		const char*	destination;
		int			job;
	CODE:
		RETVAL = cupsCancelJob( destination, job );
	OUTPUT:
		RETVAL

int
cupsGetClasses()
	INIT:
		int		loop = 0;
		int 	class_count = 0;
		char**	classes;
	PPCODE:
		class_count = cupsGetClasses( &classes );

		if( class_count > 0 )
		{
			for( loop = 0; loop < class_count; loop++ )
			{
				XPUSHs( sv_2mortal( newSVpv( classes[loop], 0 ) ) );
				/* We need to make sure we free up our allocated string */
				Safefree( classes[loop] );
			}

			Safefree( classes );

			XSRETURN( class_count );
		}
		else
		{
			XSRETURN_UNDEF;
		}

int
cupsGetDests()
	INIT:
		int				loop = 0;
		int				destination_count = 0;
		cups_dest_t*	destinations = NULL;
		SV*				destination;
	PPCODE:
		destination_count = cupsGetDests( &destinations );
		
		if( destination_count != 0 )
		{
			for( loop = 0; loop < destination_count; loop++ )
			{
				destination = sv_newmortal();
				XS_pack_cups_dest_tPTR( destination, &destinations[loop] );
				XPUSHs( destination );
			} 
		
			cupsFreeDests( destination_count, destinations );

			XSRETURN( loop );
		}
		else
		{
			XSRETURN_UNDEF;
		}

const char*
cupsGetDefault()
	CODE:
		RETVAL = cupsGetDefault();
	OUTPUT:
		RETVAL

int
cupsGetJobs( destination, my_jobs, completed )
		int			my_jobs;
		int			completed;
		const char*	destination;
	INIT:
		int			loop = 0;
		int			job_count = 0;
		cups_job_t*	queue = NULL;
		SV*			job = NULL;
	PPCODE:
		job_count = cupsGetJobs( &queue, destination, my_jobs, completed );

		if( job_count != 0 )
		{
			for( loop = 0; loop < job_count; loop++ )
			{
				job = sv_newmortal();
				XS_pack_cups_job_tPTR( job, &queue[loop] );
				XPUSHs( job );
			}
			cupsFreeJobs( job_count, queue );

			XSRETURN( loop );
		}
		else
		{
			XSRETURN_UNDEF;
		}

int
cupsGetPrinters()
	INIT:
		int  	loop = 0;
		int  	num_printers = 0;
		char** 	printers;
		SV* 	printer;
	PPCODE:
		num_printers = cupsGetPrinters( &printers );

		if( num_printers != 0 )	
		{
			/* Loop through all of the printers pushing them onto */
			/* our routine array.                                 */
			for( loop = 0; loop < num_printers; loop++ )
			{
				XPUSHs( sv_2mortal( newSVpv( printers[loop], 0 ) ) );
				/* We need to make sure we free up our allocated string */
				Safefree( printers[loop] );
			}

			/* We do this also for good measure. */
			Safefree( printers );
		
			XSRETURN( loop );
		}
		else
		{
			XSRETURN_UNDEF;
		}

ipp_status_t
cupsLastError()
	INIT:
		RETVAL = cupsLastError();
	OUTPUT:
		RETVAL


int
cupsPrintFile( printer, filename, title, options )
		const char* 	printer;
		const char*		filename;
		const char*	 	title;
		SV*				options;
	INIT:
		HV*				option_h;
		cups_option_t*	option_t = NULL;
		int				option_count = 0;
	CODE:
		
		option_h = (HV*)SvRV(options);
		
		option_count = hv_iterinit( option_h );
		
		option_t = XS_unpack_cups_option_tPTR( options ); 
		
		RETVAL = cupsPrintFile( printer, 
								filename, 
								title, 
								option_count, 
								option_t ); 

	OUTPUT:
		RETVAL


int
cupsPrintFiles( printer, files, title, options )
		const char*		printer;
		SV*				files;
		const char*		title;
		SV*				options;
	INIT:
		int				loop = 0;
		HV*				option_h;
		AV*				file_a;
		int				file_count = 0;
		cups_option_t*	option_t = NULL;
		int				option_count = 0;
		char**			file_ca;
		char*			file;
		SV**			sfile;
	CODE:
		file_a = (AV*)SvRV( files );
		option_h = (HV*)SvRV( options );
		
		file_count = av_len( file_a ) + 1;
		option_count = hv_iterinit( option_h );

		Newz( 69, file_ca, file_count, char* );
		
		for( loop = 0; loop < file_count; loop++ )
		{
			sfile = av_fetch( file_a, loop, 0 );

			file_ca[loop] = strdup( (const char*)SvPV_nolen( *sfile ) );
		}
		
		option_t = XS_unpack_cups_option_tPTR( options ); 
		
		RETVAL = cupsPrintFiles( printer, 
								 file_count,
								 (const char**)file_ca, 
								 title, 
								 option_count, 
								 option_t ); 

		for( loop = 0; loop < file_count; loop++ )
		{
			Safefree( file_ca[loop] );
		}

		Safefree( file_ca );

	OUTPUT:
		RETVAL

const char*
cupsErrorString( code )
		ipp_status_t code;
	CODE:
		RETVAL = ippErrorString( code );
	OUTPUT:
		RETVAL

const char*
cupsServer()
	CODE:
		RETVAL = cupsServer();
	OUTPUT:
		RETVAL

void
cupsSetServer( server )
		const char* server;
	CODE:
		cupsSetServer( server );

void
cupsSetUser( user )
		const char* user;
	CODE:
		cupsSetUser( user );

const char*
cupsUser()
	CODE:
		RETVAL = cupsUser();
	OUTPUT:
		RETVAL

