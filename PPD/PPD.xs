#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <cups/ppd.h>

#include "PPD_constant_c.inc"
#include "../common/common.c"

MODULE = Net::CUPS::PPD		PACKAGE = Net::CUPS::PPD		

PROTOTYPES: DISABLE

INCLUDE: PPD_constant_xs.inc

int
ppdConflicts( ppd )
		ppd_file_t* ppd;
	CODE:
		RETVAL = ppdConflicts( ppd );
	OUTPUT:
		RETVAL

int
ppdEmit( ppd, file, section )
		ppd_file_t*		ppd;
		FILE*			file;
		ppd_section_t	section;
	CODE:
		RETVAL = ppdEmit( ppd, file, section );
	OUTPUT:
		RETVAL

int
ppdEmitFd( ppd, file, section )
		ppd_file_t*		ppd;
		int				file;
		ppd_section_t	section;
	CODE:
		RETVAL = ppdEmitFd( ppd, file, section );
	OUTPUT:
		RETVAL

ppd_choice_t*
ppdFindChoice( option, choice )
		ppd_option_t*	option;
		const char*		choice;
	CODE:
		RETVAL = ppdFindChoice( option, choice );
	OUTPUT:
		RETVAL

ppd_choice_t*
ppdFindMarkedChoice( ppd, keyword )
		ppd_file_t*		ppd;
		const char*		keyword;
	CODE:
		RETVAL = ppdFindMarkedChoice( ppd, keyword );
	OUTPUT:
		RETVAL

ppd_option_t*
ppdFindOption( ppd, keyword )
		ppd_file_t*		ppd;
		const char*		keyword;
	CODE:
		RETVAL = ppdFindOption( ppd, keyword );
	OUTPUT:
		RETVAL


int
ppdIsMarked( ppd, keyword, choice )
		ppd_file_t*		ppd;
		const char*		keyword;
		const char*		choice;
	CODE:
		RETVAL = ppdIsMarked( ppd, keyword, choice );
	OUTPUT:
		RETVAL

int
ppdMarkDefaults( ppd )
		ppd_file_t*		ppd;
	CODE:
		RETVAL = 1;
		ppdMarkDefaults( ppd );
	OUTPUT:
		RETVAL

int
ppdMarkOption( ppd, keyword, choice )
		ppd_file_t*		ppd;
		const char*		keyword;
		const char*		choice;
	PPCODE:
		RETVAL = ppdMarkOption( ppd, keyword, choice );
		XS_pack_ppd_file_tPtr( ST(0), ppd );
		SvSETMAGIC( ST(0) );
		XSprePUSH;
		PUSHi((IV)RETVAL);
		XSRETURN( 1 );

ppd_file_t*
ppdOpenFile( filename )
		const char *filename;
	CODE:
		RETVAL = ppdOpenFile( filename );
		if( RETVAL == NULL )
		{
			printf( "Error: ppdOpenFile failed to open the requested PPD!\n" );
		}
	OUTPUT:
		RETVAL
	CLEANUP:
		if( RETVAL != NULL )
		{
			ppdClose( RETVAL );
		}

float
ppdPageLength( ppd, name )
		ppd_file_t*		ppd;
		const char*		name;
	CODE:
		RETVAL = ppdPageLength( ppd, name );
	OUTPUT:
		RETVAL

ppd_size_t*
ppdPageSize( ppd, name )
		ppd_file_t*		ppd;
		const char*		name;
	CODE:
		RETVAL = ppdPageSize( ppd, name );
	OUTPUT:
		RETVAL

float
ppdPageWidth( ppd, name )
		ppd_file_t*		ppd;
		const char*		name;
	CODE:
		RETVAL = ppdPageWidth( ppd, name );
	OUTPUT:
		RETVAL
