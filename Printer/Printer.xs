#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <cups/cups.h>
#include <cups/ppd.h>

#include "Printer_constant_c.inc"
#include "../common/common.c"



static SV *password_cb = (SV*) NULL;

const char *
password_cb_wrapper(const char *prompt)
{
	STRLEN n_a;
	static char password[255] = { '\0' };

	if (! password_cb) {
		return NULL;
	}

	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(SP);
	XPUSHs(sv_2mortal(newSVpv(prompt, 0)));
	PUTBACK;
	call_sv(password_cb, G_SCALAR);
	SPAGAIN;
	strncpy(password, POPpx, 254);

	PUTBACK;
	FREETMPS;
	LEAVE;

	return password;
}


MODULE = Net::CUPS::Printer		PACKAGE = Net::CUPS::Printer		

PROTOTYPES: DISABLE

INCLUDE: Printer_constant_xs.inc

int
cupsAddDest( name, instance, dests )
		const char* name;
		const char* instance;
		AV*			dests;
	INIT:
		int loop = 0;
		int num_dests = 0;
		cups_dest_t* destinations = NULL;
		SV* destination = NULL;
		SV** ssv = NULL;
	PPCODE:
		num_dests = av_len( dests ) + 1;

		Newz( 69, destinations, num_dests, cups_dest_t );
		
		for( loop = 0; loop < num_dests; loop++ )
		{
			ssv = av_fetch( dests, loop ,0 );
			destinations[loop] = *XS_unpack_cups_dest_tPtr( *ssv );
		}

		num_dests = cupsAddDest( name, instance, num_dests, &destinations );
		
		if( num_dests != 0 )
		{
			for( loop = 0; loop < num_dests; loop++ )
			{
				destination = sv_newmortal();
				XS_pack_cups_dest_tPtr( destination, &destinations[loop] );
				XPUSHs( destination );
			} 
		
			Safefree( destinations );
			XSRETURN( loop );
		}
		else
		{
			XSRETURN_UNDEF;
		}

int
cupsAddOption( name, value, opts )
		const char* name;
		const char* value;
		AV*			opts;
	INIT:
		int loop = 0;
		int num_options = 0;
		cups_option_t* options = NULL;
		SV* option = NULL;
		SV** ssv = NULL;
	PPCODE:
		num_options = av_len( opts ) + 1;

		Newz( 69, options, num_options, cups_option_t );
		
		for( loop = 0; loop < num_options; loop++ )
		{
			ssv = av_fetch( opts, loop ,0 );
			options[loop] = *XS_unpack_cups_option_tPtr( *ssv );
		}

		num_options = cupsAddOption( name, value, num_options, &options );
		
		if( num_options != 0 )
		{
			for( loop = 0; loop < num_options; loop++ )
			{
				option = sv_newmortal();
				XS_pack_cups_option_tPtr( option, &options[loop] );
				XPUSHs( option );
			} 
		
			Safefree( options );
			XSRETURN( loop );
		}
		else
		{
			XSRETURN_UNDEF;
		}

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

cups_dest_t*
cupsGetDest( name, instance, dests )
		const char *name;
		const char *instance;
		AV* dests;
	INIT:
		int loop = 0;
		int num_dests = 0;
		cups_dest_t* destinations = NULL;
		SV**			ssv;
	CODE:
		num_dests = av_len( dests ) + 1;

		Newz( 69, destinations, num_dests, cups_dest_t );
		
		for( loop = 0; loop < num_dests; loop++ )
		{
			ssv = av_fetch( dests, loop ,0 );
			destinations[loop] = *XS_unpack_cups_dest_tPtr( *ssv );
		}

		if( strlen( name ) == 0 )
		{
			name = NULL;
		}

		if( strlen( instance ) == 0 )
		{
			instance = NULL;
		}

		RETVAL = cupsGetDest( name, instance, num_dests, destinations );
	OUTPUT:
		RETVAL

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
				XS_pack_cups_dest_tPtr( destination, &destinations[loop] );
				XPUSHs( destination );
			} 
		
			cupsFreeDests( destination_count, destinations );

			XSRETURN( loop );
		}
		else
		{
			/* I was sorta confused about what would be proper to return */
			/* here.  If I returned XS_RETURNUNDEF it would cause issues */
			/* with using scalar( @return_array ).  My solution is to    */
			/* just return '0' */
			XSRETURN( 0 );
		}

const char*
cupsGetDefault()
	CODE:
		RETVAL = cupsGetDefault();
	OUTPUT:
		RETVAL

const char*
cupsGetOption( name, opts )
		const char* name;
		AV*			opts;
	INIT:
		int loop = 0;
		int num_options = 0;
		cups_option_t* options = NULL;
		SV* option = NULL;
		SV** ssv = NULL;
	CODE:
		num_options = av_len( opts ) + 1;

		Newz( 69, options, num_options, cups_option_t );
		
		for( loop = 0; loop < num_options; loop++ )
		{
			ssv = av_fetch( opts, loop ,0 );
			options[loop] = *XS_unpack_cups_option_tPtr( *ssv );
		}

		RETVAL = cupsGetOption( name, num_options, options );
	OUTPUT:
		RETVAL

ppd_file_t*
cupsGetPPD( printer )
		const char *printer;
	INIT:
		const char* filename = NULL;
	CODE:
		if( (filename = cupsGetPPD( printer )) == NULL )
		{
			printf( "Printer %s does not have a PPD file!\n", printer );
		}

		if( (RETVAL = ppdOpenFile( filename )) == NULL )
		{
			unlink( filename );
			printf( "Unable to open PPD file printer %s!\n", printer );
			XSRETURN_UNDEF;
		}

	OUTPUT:
		RETVAL
	CLEANUP:
		ppdClose( RETVAL );
	
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
				XS_pack_cups_job_tPtr( job, &queue[loop] );
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
		
		option_t = XS_unpack_cups_option_tPtr( options ); 
		
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
		
		option_t = XS_unpack_cups_option_tPtr( options ); 
		
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

int
cupsSetDests( dests )
		AV* dests;
	INIT:
		int loop = 0;
		int num_dests = 0;
		cups_dest_t* destinations = NULL;
		SV**			ssv;
	CODE:
		num_dests = av_len( dests ) + 1;

		Newz( 69, destinations, num_dests, cups_dest_t );
		
		for( loop = 0; loop < num_dests; loop++ )
		{
			ssv = av_fetch( dests, loop, 0 );
			destinations[loop] = *XS_unpack_cups_dest_tPtr( *ssv );
		}

		cupsSetDests( num_dests, destinations );

		RETVAL = 1;
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



void
cupsSetPasswordCB( cb )
		SV *cb
	CODE:
		if( password_cb == (SV*) NULL ) {
			password_cb = newSVsv( cb );
			cupsSetPasswordCB( password_cb_wrapper );
		} else {
			SvSetSV( password_cb, cb );
		}

const char*
cupsGetPassword( prompt )
		const char *prompt;
	CODE:
		RETVAL = cupsGetPassword( prompt );
	OUTPUT:
		RETVAL

const char*
cupsUser()
	CODE:
		RETVAL = cupsUser();
	OUTPUT:
		RETVAL

