/*
 *  Net::CUPS Common Data Conversion Routines
 *
 *  Author: D. Hageman <dhageman@dracken.com>
 *
 *  Copyright 2003 by Dracken Technologies.
 *
 *  CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro 
 *  are the trademark property of Easy Software Products.
 *
 */

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <cups/cups.h>
#include <cups/ppd.h>

#include "common.h"

void
XS_pack_cups_option_tPtr( SV* s, cups_option_t* option )
{
	SV* sv;
	HV* hv = newHV();
	
	if( option != NULL )
	{
		hv_store( hv, "name", strlen( "name" ),
				  newSVpv( option->name, strlen( option->name ) ), 0 );

		hv_store( hv, "value", strlen( "value" ),
				  newSVpv( option->value, strlen( option->value ) ), 0 );
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	return;
}

void 
XS_pack_cups_dest_tPtr( SV* s, cups_dest_t* dest )
{
	int loop = 0;
	SV* sv;
	SV* option;
	HV* hv = newHV();
	AV* av = newAV();
	
	if( dest != NULL )
	{
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
			XS_pack_cups_option_tPtr( option, &dest->options[loop] );
			av_push( av,  newSVsv( option ) );
		}
	
		option = newRV( (SV*)av );
		
		hv_store( hv, "options", strlen( "options" ),
				option, 0 );  
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	return;
}

void
XS_pack_cups_job_tPtr( SV* s, cups_job_t* job )
{
	SV* sv;
	HV* hv = newHV();

	if( job != NULL )
	{
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
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	return;
}

void
XS_pack_ppd_attr_tPtr( SV* s, ppd_attr_t* attr )
{
	SV* sv = NULL;
	HV* hv = newHV();

	if( attr != NULL )
	{
		/* Name of attribute (cupsXYZ) */
		hv_store( hv, "name", strlen( "name" ),
				  newSVpv( attr->name, 0 ), 0 );
		/* Specififier String if any */
		hv_store( hv, "spec", strlen( "spec" ),
				  newSVpv( attr->spec, 0 ), 0 );
		/* Human-readable text, if any */
		hv_store( hv, "text", strlen( "text" ),
				  newSVpv( attr->text, 0 ), 0 );
		/* Value string */
		hv_store( hv, "value", strlen( "value" ),
				  newSVpv( attr->value, 0 ), 0 );
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	return;
}

void
XS_pack_ppd_emul_tPtr( SV* s, ppd_emul_t* emul )
{
	SV* sv = NULL;
	HV* hv = newHV();

	if( emul != NULL )
	{
		/* Emulator Name */
		hv_store( hv, "name", strlen( "name" ),
				  newSVpv( emul->name, 0 ), 0 );
		/* Code to start to this emulation */
		hv_store( hv, "start", strlen( "start" ),
				  newSVpv( emul->start, 0 ), 0 );
		/* Code to stop this emulation */
		hv_store( hv, "stop", strlen( "stop" ),
				  newSVpv( emul->stop, 0 ), 0 );
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	return;
}

void
XS_pack_ppd_option_tPtr( SV* s, ppd_option_t* option )
{
	int loop = 0;
	SV* sv;
	SV* choice;
	HV* hv = newHV();
	AV* av = newAV();

	if( option != NULL )
	{
		/* Conflicts: 0 = No conflicts, 1 = Conflicts */
		hv_store( hv, "conflicted", strlen( "conflicted" ),
				  newSViv( option->conflicted ), 0 );
		/* Option Keyword Name ( "PageSize", etc ) */
		hv_store( hv, "keyword", strlen( "keyword" ),
				  newSVpv( option->keyword, 0 ), 0 );
		/* Default option choice */
		hv_store( hv, "defchoice", strlen( "defchoice" ),
				  newSVpv( option->defchoice, 0 ), 0 );
		/* Human-readable text */
		hv_store( hv, "text", strlen( "text" ),
				  newSVpv( option->text, 0 ), 0 );
		/* Type of UI option */
		hv_store( hv, "ui", strlen( "ui" ),
				  newSViv( option->ui ), 0 );
		/* Section for command */
		hv_store( hv, "section", strlen( "section" ),
				  newSViv( option->section ), 0 );
		/* Order Number */
		hv_store( hv, "order", strlen( "order" ),
				  newSVnv( option->order ), 0 );
		/* Number of option choices */
		hv_store( hv, "num_choices", strlen( "num_choices" ),
				  newSViv( option->num_choices ), 0 );
		/* Option Choices */
		for( loop = 0; loop < option->num_choices; loop++ )
		{
			choice = sv_newmortal();
			XS_pack_ppd_choice_tPtr( choice, &option->choices[loop] );
			av_push( av, newSVsv( choice ) );
		}

		hv_store( hv, "choices", strlen( "choices" ),
				  newRV( (SV*)av ), 0 );
		SvREFCNT_dec( av );
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	return;
}

void
XS_pack_ppd_group_tPtr( SV* s, ppd_group_t* group )
{
	int loop = 0;
	AV* av = NULL;
	SV* sv = NULL;
	SV* test = NULL;
	SV* option = NULL;
	HV* hv = newHV();
	
	if( group != NULL )
	{
		/* Human readable group name */
		hv_store( hv, "text", strlen( "text" ),
				  newSVpv( group->text, 0 ), 0 );
		/* Number of options */
		hv_store( hv, "num_options", strlen( "num_options" ),
				  newSViv( group->num_options ), 0 );
	
		/* Options */
		av = newAV();
		for( loop = 0; loop < group->num_options; loop++ )
		{
			sv = sv_newmortal();
			XS_pack_ppd_option_tPtr( sv, &group->options[loop] );
			test = newSVsv( sv );
			av_push( av, test );
		}
	
		option = newRV( (SV*)av );
		SvREFCNT_dec( av );
		hv_store( hv, "options", strlen( "options" ),
				  option, 0 );

		/* Number of sub-groups */
		hv_store( hv, "num_subgroups", strlen( "num_subgroups" ),
				  newSViv( group->num_subgroups ), 0 );
	
		/* Sub-groups (max depth = 1 ) */
		av = newAV();
		for( loop = 0; loop < group->num_subgroups; loop++ )
		{
			sv = sv_newmortal();
			XS_pack_ppd_group_tPtr( sv, &group->subgroups[loop] );
			av_push( av, newSVsv( sv ) );
		}
		
		hv_store( hv, "subgroups", strlen( "subgroups" ),
				  newRV( (SV*)av ), 0 );
		SvREFCNT_dec( av );
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	
	return;
}

void
XS_pack_ppd_size_tPtr( SV* s, ppd_size_t* size )
{
	SV* sv;
	HV* hv = newHV();
	
	if( size != NULL )
	{
		/* Page size selected? */
		hv_store( hv, "marked", strlen( "marked" ),
				  newSViv( size->marked ), 0 );
		/* Media size option name */
		hv_store( hv, "name", strlen( "name" ),
				  newSVpv( size->name, 0 ), 0 );
		/* Width of the media in points */
		hv_store( hv, "width", strlen( "width" ),
				  newSVnv( size->width ), 0 );
		/* Length of the media in points */
		hv_store( hv, "length", strlen( "length" ),
				  newSVnv( size->length ), 0 );
		/* Printable margins of each side in points */
		hv_store( hv, "left", strlen( "left" ),
				  newSVnv( size->left ), 0 );
		hv_store( hv, "bottom", strlen( "bottom" ),
				  newSVnv( size->bottom ), 0 );
		hv_store( hv, "right", strlen( "right" ),
				  newSVnv( size->right ), 0 );
		hv_store( hv, "top", strlen( "top" ),
				  newSVnv( size->top ), 0 );
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;

	
	return;
}

void
XS_pack_ppd_profile_tPtr( SV* s, ppd_profile_t* profile )
{
	SV* sv;
	HV* hv = newHV();

	if( profile != NULL )
	{
		/* Resolution or "-" */
		hv_store( hv, "resolution", strlen( "resolution" ),
				  newSVpv( profile->resolution, 0 ), 0 );
		/* Media type of "-" */
		hv_store( hv, "media_type", strlen( "media_type" ),
				  newSVpv( profile->media_type, 0 ), 0 );
		/* Ink density to use */
		hv_store( hv, "density", strlen( "density" ),
				  newSVnv( profile->density ), 0 );
		/* Gamma correction to use */
		hv_store( hv, "gamma", strlen( "gamma" ),
				  newSVnv( profile->gamma ), 0 );

		/* XXX Place holder for transform matrix XXX */
	}

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	return;
}

void
XS_pack_ppd_file_tPtr( SV* s, ppd_file_t* file )
{
	int loop = 0;
	SV* sv;
	SV* group;
	SV* emul;
	SV* size;
	SV* consts;
	SV* font;
	SV* filter;
	SV* profile;
	AV* av = NULL;
	HV* hv = newHV();
	
	if( file != NULL )
	{
		/* Language level of the device */
		hv_store( hv, "language_level", strlen( "language_level" ),
				  newSViv( file->language_level ), 0 );

		/* Color Device: 1 = color, 0 = grayscale */
		hv_store( hv, "color_device", strlen( "color_device" ),
				  newSViv( file->color_device ), 0 );
	
		/* Variable Sizes: 1 = Supported, 0 = Not Supported */
		hv_store( hv, "variable_sizes", strlen( "variable_sizes" ),
				  newSViv( file->variable_sizes ), 0 );
	
		/* Accurate Screens: 1 = Supported, 0 = Not Supported */
		hv_store( hv, "accurate_screens", strlen( "accurate_screens" ),
				  newSViv( file->accurate_screens ), 0 );
	
		/* Continous Tone: 1 = Continuous Tone Only, 0 = Not */
		hv_store( hv, "contone_only", strlen( "contone_only" ),
				  newSViv( file->contone_only ), 0 );
	
		/* Landscape Position: -90 or 90 */
		hv_store( hv, "landscape", strlen( "landscape" ),
				  newSViv( file->landscape ), 0 );
		
		/* Model Number: Device-specific model number */
		hv_store( hv, "model_number", strlen( "model_number" ),
				  newSViv( file->model_number ), 0 );
	
		/* Thoughput: Pages per Minute */
		hv_store( hv, "throughput", strlen( "throughput" ),
				  newSViv( file->throughput ), 0 );
		
		/* Place Holder for ppd_cs_t colorspace */
		hv_store( hv, "colorspace", strlen( "colorspace" ),
				  newSViv( file->colorspace ), 0 );
	
		/* Patch commands to be sent to the printer */
		if( file->patches != NULL )
		{
			hv_store( hv, "patches", strlen( "patches" ),
					  newSVpv( file->patches, 0 ), 0 );
		}
		else
		{
			/* XXX This may not make it what it should be on the XXX */
			/* XXX converstion back ...                          XXX */
			hv_store( hv, "patches", strlen( "patches" ),
					  newSVpv( "\0", 0 ), 0 );
		}
	
		/* Number of emulations supported */
		hv_store( hv, "num_emulations", strlen( "num_emulations" ),
				  newSViv( file->num_emulations ), 0 );
	
		/* Create a new AV and stick it in ... */
		av = newAV();
		for( loop = 0; loop < file->num_emulations; loop++ )
		{
			emul = sv_newmortal(); 
			XS_pack_ppd_emul_tPtr( emul, &file->emulations[loop] );
			av_push( av, newSVsv( emul ) );
		}
		
		hv_store( hv, "emulations", strlen( "emulations" ),
				  newRV( (SV*)av ), 0 );
		SvREFCNT_dec( av );
		
		/* Start JCL commands */
		if( file->jcl_begin != NULL )
		{
			hv_store( hv, "jcl_begin", strlen( "jcl_begin" ),
					  newSVpv( file->jcl_begin, 0 ), 0 );
		}
		else
		{
			hv_store( hv, "jcl_begin", strlen( "jcl_begin" ),
					  newSVpv( "\0", 0 ), 0 );
		}
	
		if( file->jcl_ps != NULL )
		{
			hv_store( hv, "jcl_ps", strlen( "jcl_ps" ),
					  newSVpv( file->jcl_ps, 0 ), 0 );
		}
		else
		{
			hv_store( hv, "jcl_ps", strlen( "jcl_ps" ),
					  newSVpv( "\0", 0 ), 0 );
		}
	
		if( file->jcl_end != NULL )
		{
			hv_store( hv, "jcl_end", strlen( "jcl_end" ),
					  newSVpv( file->jcl_end, 0 ), 0 );
		}
		else
		{
			hv_store( hv, "jcl_end", strlen( "jcl_end" ),
					  newSVpv( "\0", 0 ), 0 );
		}
	
		hv_store( hv, "lang_encoding", strlen( "lang_encoding" ),
				  newSVpv( file->lang_encoding, 0 ), 0 );
	
		hv_store( hv, "lang_version", strlen( "lang_version" ),
				  newSVpv( file->lang_version, 0 ), 0 );
	
		hv_store( hv, "modelname", strlen( "modelname" ),
				  newSVpv( file->modelname, 0 ), 0 );
	
		hv_store( hv, "ttrasterizer", strlen( "ttrasterizer" ),
				  newSVpv( file->ttrasterizer, 0 ), 0 );
		
		hv_store( hv, "manufacturer", strlen( "manufacturer" ),
				  newSVpv( file->manufacturer, 0 ), 0 );
	
		hv_store( hv, "product", strlen( "product" ),
				  newSVpv( file->product, 0 ), 0 );
	
		hv_store( hv, "nickname", strlen( "nickname" ),
				  newSVpv( file->nickname, 0 ), 0 );
	
		hv_store( hv, "shortnickname", strlen( "shortnickname" ),
				  newSVpv( file->shortnickname, 0 ), 0 );
		
		/* Number of UI groups */
		hv_store( hv, "num_groups", strlen( "num_groups" ),
				  newSViv( file->num_groups ), 0 );

		av = newAV();
		for( loop = 0; loop < file->num_groups; loop++ )
		{
			group = sv_newmortal();
			XS_pack_ppd_group_tPtr( group, &file->groups[loop] );
			av_push( av, newSVsv( group ) );
		}

		group = newRV( (SV*)av );
		SvREFCNT_dec( av );

		hv_store( hv, "groups", strlen( "groups" ),
				  group, 0 );
	
		/* Number of page sizes */
		hv_store( hv, "num_sizes", strlen( "num_sizes" ),
				  newSViv( file->num_sizes ), 0 );

		/* Create a new AV and stick it in ... */
		av = newAV();
		/* ppd_size_t* sizes */
		for( loop = 0; loop < file->num_sizes; loop++ )
		{
			size = sv_newmortal();
			XS_pack_ppd_size_tPtr( size, &file->sizes[loop] );
			av_push( av, newSVsv( size ) );
		}

		hv_store( hv, "sizes", strlen( "sizes" ),
				  newRV( (SV*)av ), 0 );
	
		SvREFCNT_dec( av );

		/* XXX Place holder for custom sizes XXX */

		/* Number of UI/Non-UI constraints */
		hv_store( hv, "num_consts", strlen( "num_consts" ),
				  newSViv( file->num_consts ), 0 );

		/* Create a new AV and stick it in ... */
		av = newAV();
		/* Place holder for ppd_const_t* consts */
		for( loop = 0; loop < file->num_consts; loop++ )
		{
			consts = sv_newmortal();
			XS_pack_ppd_const_tPtr( consts, &file->consts[loop] );
			av_push( av, newSVsv( consts ) );
		}
	
		consts = newRV( (SV*)av );
		SvREFCNT_dec( av );

		hv_store( hv, "consts", strlen( "consts" ),
				  consts, 0 );
	
		/* Number of pre-loaded fonts */
		hv_store( hv, "num_fonts", strlen( "num_fonts" ),
				  newSViv( file->num_fonts ), 0 );

		/* Create a new AV and stick it in ... */
		av = newAV();
		for( loop = 0; loop < file->num_fonts; loop++ )
		{
			font = sv_newmortal();
			font = newSVpv( file->fonts[loop], 0 );
			av_push( av, newSVsv( font ) );
		}
	
		hv_store( hv, "fonts", strlen( "fonts" ),
				  newRV( (SV*)av ), 0 );
	
		SvREFCNT_dec( av );
	
		/* Number of sRGB color profiles */
		hv_store( hv, "num_profiles", strlen( "num_profiles" ),
				  newSViv( file->num_profiles ), 0 );

		/* Create a new AV and stick it in ... */
		av = newAV();
		/* Place holder for ppd_profile_t* profiles */
		for( loop = 0; loop < file->num_profiles; loop++ )
		{
			profile = sv_newmortal();
			XS_pack_ppd_profile_tPtr( profile, &file->profiles[loop] );
			av_push( av, newSVsv( profile ) );
		}

		hv_store( hv, "profiles", strlen( "profiles" ),
				  newRV( (SV*)av ), 0 );
		SvREFCNT_dec( av );
	
		/* Number of filters */
		hv_store( hv, "num_filters", strlen( "num_filters" ),
				  newSViv( file->num_filters ), 0 );

		/* Create a new AV and stick it in ... */
		av = newAV();
		/* Place holder for char** filters */
		for( loop = 0; loop < file->num_filters; loop++ )
		{
			filter = sv_newmortal();
			filter = newSVpv( file->filters[loop], 0 );
			av_push( av, newSVsv( filter ) );
		}
	
		hv_store( hv, "filters", strlen( "filters" ),
				  newRV( (SV*)av ), 0 );
		SvREFCNT_dec( av );
	
		/* Duplex: 1 = Flip page for back sides */
		hv_store( hv, "flip_duplex", strlen( "flip_duplex" ),
				  newSViv( file->flip_duplex ), 0 );
	
		/* Protocols (BCP, TBCP) string */
		if( file->protocols != NULL )
		{
			hv_store( hv, "protocols", strlen( "protocols" ),
					  newSVpv( file->protocols, 0 ), 0 );
		}
		else
		{
			hv_store( hv, "protocols", strlen( "protocols" ),
					  newSVpv( "\0", 0 ), 0 );
		}

		/* PCFileName string */
		hv_store( hv, "pcfilename", strlen( "pcfilename" ),
				  newSVpv( file->pcfilename, 0 ), 0 );
	
		/* Current Attribute */
		hv_store( hv, "cur_attr", strlen( "cur_attr" ),
				  newSViv( file->cur_attr ), 0 );
	
		/* Number of sRGB color attrs */
		hv_store( hv, "num_attrs", strlen( "num_attrs" ),
				  newSViv( file->num_attrs ), 0 );

		/* Create a new AV and stick it in ... */
		av = newAV();
		
		/* Place holder for ppd_attr_t* attrs */
		for( loop = 0; loop < file->num_attrs; loop++ )
		{
			sv = sv_newmortal();
			XS_pack_ppd_attr_tPtr( sv, file->attrs[loop] );
			av_push( av, newSVsv( sv ) );
		}

		hv_store( hv, "attrs", strlen( "attrs" ),
				  newRV( (SV*)av ), 0 );
		SvREFCNT_dec( av );
	}
	
	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	return;
}

cups_job_t*
XS_unpack_cups_job_tPtr( SV* rv )
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
XS_unpack_cups_option_tPtr( SV* rv )
{
	cups_option_t* retval = NULL;
	HV* hv = NULL;
	SV* option;
	SV** ssv;
	
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV(rv);
	}

	if( !hv ) { return NULL; }
	
	/* Grab some memmory */
	Newz( 42, retval, 1,  cups_option_t ); 
	
	/* cups_option_t.name */
	ssv = hv_fetch( hv, "name", strlen( "name" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->name = SvPV_nolen( *ssv );
	}
	
	/* cups_option_t.value */
	ssv = hv_fetch( hv, "value", strlen( "value" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->value = SvPV_nolen( *ssv );
	}

	return retval;
}

void
XS_pack_ppd_choice_tPtr( SV* s, ppd_choice_t* choice )
{
	SV* sv = NULL;
	HV* hv = newHV();
	
	/* XXX ppd_choice_t may be NULL ... FIX! XXX */
	
	/* Selected: 0 = No, 1 = Yes */
	hv_store( hv, "marked", strlen( "marked" ),
			  newSViv( choice->marked ), 0 );
	/* Computer-readable option name */
	hv_store( hv, "choice", strlen( "choice" ),
			  newSVpv( choice->choice, 0 ), 0 );
	/* Human-readable option name */
	hv_store( hv, "text", strlen( "text" ),
			  newSVpv( choice->text, 0 ), 0 );
	
	if( choice->code != NULL )
	{
		/* Code to send for this option */
		hv_store( hv, "code", strlen( "code" ),
				  newSVpv( choice->code, 0 ), 0 );
	}
	else
	{
		hv_store( hv, "code", strlen( "code" ),
				  newSVpv( "\0", 0 ), 0 );
	}
	
	/* Pointer to parent option structure */
	/* void* option */
	
	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	return;
}

void
XS_pack_ppd_const_tPtr( SV* s, ppd_const_t* constraint )
{
	SV* sv = NULL;
	HV* hv = newHV();
	
	/* First Keyword */
	hv_store( hv, "option1", strlen( "option1" ),
			  newSVpv( constraint->option1, 0 ), 0 ); 
	/* First option/choice (blank for all) */
	hv_store( hv, "choice1", strlen( "choice1" ),
			  newSVpv( constraint->choice1, 0 ), 0 ); 
	/* Second Keyword */
	hv_store( hv, "option2", strlen( "option2" ),
			  newSVpv( constraint->option2, 0 ), 0 );
	/* Second option/choice (blank for all) */
	hv_store( hv, "choice2", strlen( "choice2" ),
			  newSVpv( constraint->choice2, 0 ), 0 );

	sv = newSVrv( s, NULL );
	SvREFCNT_dec( sv );
	SvRV( s ) = (SV*)hv;
	
	return;
}

ppd_attr_t*
XS_unpack_ppd_attr_tPtr( SV* rv )
{
	ppd_attr_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv = NULL;
	
	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) 
	{
		return NULL; 
	}
	
	/* Grab some memmory for our ppd_attr_t pointer ... */
	Newz( 69, retval, 1, ppd_attr_t );

	/* cups_attr_t.name */
	ssv = hv_fetch( hv, "name", strlen( "name" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->name, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* cups_attr_t.spec */
	ssv = hv_fetch( hv, "spec", strlen( "spec" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->spec, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* cups_attr_t.text */
	ssv = hv_fetch( hv, "text", strlen( "text" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->text, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* cups_attr_t.value */
	ssv = hv_fetch( hv, "value", strlen( "value" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->value = SvPV_nolen( *ssv );
	}

	return retval;
}

cups_dest_t*
XS_unpack_cups_dest_tPtr( SV* rv )
{
	cups_dest_t* retval = NULL;
	HV* hv = NULL;
	AV* av = NULL;
	SV** ssv = NULL;
	int loop = 0;
	
	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) 
	{
		return NULL; 
	}
	
	/* Grab some memmory for our ppd_choice_t pointer ... */
	Newz( 69, retval, 1, cups_dest_t );

	/* cups_dest_t.name */
	ssv = hv_fetch( hv, "name", strlen( "name" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->name = SvPV_nolen( *ssv );
	}
	
	/* cups_dest_t.instance */
	ssv = hv_fetch( hv, "instance", strlen( "instance" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->instance = SvPV_nolen( *ssv );
	}

	/* cups_dest_t.is_default */
	ssv = hv_fetch( hv, "is_default", strlen( "is_default" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->is_default = SvIV( *ssv );
	}
	
	/* Place holder for cups_dest_t *options */
	ssv = hv_fetch( hv, "options", strlen( "options" ), 0 );
	
	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}
	
	/* Stick this value into our structure so the crappy C code won't choke. */
	retval->num_options = av_len( av ) + 1;
	
	/* Grab some memory for this ... */
	Newz( 69, retval->options, retval->num_options, cups_option_t );
	
	for( loop = 0; loop < retval->num_options; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Convert it to the C code */
		retval->options[loop] = *XS_unpack_cups_option_tPtr( *ssv );
	}

	return retval;
}
	
ppd_choice_t*
XS_unpack_ppd_choice_tPtr( SV* rv )
{
	ppd_choice_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv;
	
	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) 
	{
		return NULL; 
	}

	/* Grab some memmory for our ppd_choice_t pointer ... */
	Newz( 69, retval, 1, ppd_choice_t );

	/* ppd_choice_t.marked */
	ssv = hv_fetch( hv, "marked", strlen( "marked" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->marked = SvIV( *ssv );
	}

	/* ppd_choice_t.choice */
	ssv = hv_fetch( hv, "choice", strlen( "choice" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->choice, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_choice_t.text */
	ssv = hv_fetch( hv, "text", strlen( "text" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->text, (char*)SvPV_nolen( *ssv ), PPD_MAX_TEXT );
	}

	/* ppd_choice_t.code */
	ssv = hv_fetch( hv, "code", strlen( "code" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->code = SvPV_nolen( *ssv );
	}

	/* Place holder for void* option */
	
	return retval;
}

ppd_const_t*
XS_unpack_ppd_const_tPtr( SV* rv )
{
	ppd_const_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv;
	
	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_const_t pointer ... */
	Newz( 69, retval, 1, ppd_const_t );

	/* ppd_const_t.option1 */
	ssv = hv_fetch( hv, "option1", strlen( "option1" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->option1, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_const_t.choice1 */
	ssv = hv_fetch( hv, "choice1", strlen( "choice1" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->choice1, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_const_t.option2 */
	ssv = hv_fetch( hv, "option2", strlen( "option2" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->option2, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_const_t.choice2 */
	ssv = hv_fetch( hv, "choice2", strlen( "choice2" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->choice2, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	return retval;
}

ppd_emul_t*
XS_unpack_ppd_emul_tPtr( SV* rv )
{
	ppd_emul_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv;

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_emul_t pointer ... */
	Newz( 69, retval, 1, ppd_emul_t );

	/* ppd_emul_t.name */
	ssv = hv_fetch( hv, "name", strlen( "name" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->name, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}
	
	/* ppd_emul_t.start */
	ssv = hv_fetch( hv, "start", strlen( "start" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->start = SvPV_nolen( *ssv );
	}
	
	/* ppd_emul_t.stop */
	ssv = hv_fetch( hv, "stop", strlen( "stop" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->stop = SvPV_nolen( *ssv );
	}

	return retval;
}

ppd_option_t*
XS_unpack_ppd_option_tPtr( SV* rv )
{
	int loop = 0;
	ppd_option_t* retval = NULL;
	AV* av = NULL;
	HV* hv = NULL;
	SV** ssv;
	
	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_option_t pointer ... */
	Newz( 69, retval, 1, ppd_option_t );
	
	/* ppd_option_t.conflicted */
	ssv = hv_fetch( hv, "conflicted", strlen( "conflicted" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->conflicted = SvIV( *ssv );
	}

	/* ppd_option_t.keyword */
	ssv = hv_fetch( hv, "keyword", strlen( "keyword" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->keyword, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}
	
	/* ppd_option_t.defchoice */
	ssv = hv_fetch( hv, "defchoice", strlen( "defchoice" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->defchoice, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_option_t.text */
	ssv = hv_fetch( hv, "text", strlen( "text" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->text, (char*)SvPV_nolen( *ssv ), PPD_MAX_TEXT );
	}
	
	/* ppd_option_t.ui */
	ssv = hv_fetch( hv, "ui", strlen( "ui" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->ui = SvIV( *ssv );
	}
	
	/* ppd_option_t.section */
	ssv = hv_fetch( hv, "section", strlen( "section" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->section = SvIV( *ssv );
	}

	/* ppd_option_t.order */
	ssv = hv_fetch( hv, "order", strlen( "order" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->order = SvNV( *ssv );
	}
	
	/* Place holder for ppd_choice_t *choices */
	ssv = hv_fetch( hv, "choices", strlen( "choices" ), 0 );
	
	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}
	
	/* Stick this value into our structure so the crappy C code won't choke. */
	retval->num_choices = av_len( av ) + 1;
	
	/* Grab some memory for this ... */
	Newz( 69, retval->choices, retval->num_choices, ppd_choice_t );
	
	for( loop = 0; loop < retval->num_choices; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Convert it to the C code */
		retval->choices[loop] = *XS_unpack_ppd_choice_tPtr( *ssv );
	}
	
	return retval;
}


ppd_group_t*
XS_unpack_ppd_group_tPtr( SV* rv )
{
	int loop = 0;
	ppd_group_t* retval = NULL;
	HV* hv = NULL;
	AV* av = NULL;
	SV** ssv;

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_group_t pointer ... */
	Newz( 69, retval, 1, ppd_group_t );
	
	/* ppd_group_t.text */
	ssv = hv_fetch( hv, "text", strlen( "text" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->text, (char*)SvPV_nolen( *ssv ), PPD_MAX_TEXT );
	}
	
	/* Place holder for ppd_option_t* options */
	ssv = hv_fetch( hv, "options", strlen( "options" ), 0 );

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Store this number ... */
	retval->num_options = av_len( av ) + 1;

	/* Grab some memory for this option array. */
	Newz( 69, retval->options, retval->num_options, ppd_option_t );
	
	for( loop = 0; loop < retval->num_options; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->options[loop] = *XS_unpack_ppd_option_tPtr( *ssv );
	}

	/* ppd_group_str *subgroups */
	ssv = hv_fetch( hv, "subgroups", strlen( "subgroups" ), 0 );

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Store this number ... */
	retval->num_subgroups = av_len( av ) + 1;

	/* Grab some memory for this option array. */
	Newz( 69, retval->subgroups, retval->num_subgroups, ppd_group_t );

	for( loop = 0; loop < retval->num_subgroups; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->subgroups[loop] = *XS_unpack_ppd_group_tPtr( *ssv );
	}

	return retval;
}

ppd_profile_t*
XS_unpack_ppd_profile_tPtr( SV* rv )
{
	ppd_profile_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv;

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_profile_t pointer ... */
	Newz( 69, retval, 1, ppd_profile_t );

	/* ppd_profile_t.resolution */
	ssv = hv_fetch( hv, "resolution", strlen( "resolution" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->resolution, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_profile_t.media_type */
	ssv = hv_fetch( hv, "media_type", strlen( "media_type" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->media_type, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}
	
	/* ppd_profile_t.density */
	ssv = hv_fetch( hv, "density", strlen( "density" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->density = SvNV( *ssv );
	}

	/* ppd_profile_t.gamma */
	ssv = hv_fetch( hv, "gamma", strlen( "gamma" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->gamma = SvNV( *ssv );
	}

	/* Place holder for float matrix [3][3] */
	
	return retval;
}

ppd_size_t*
XS_unpack_ppd_size_tPtr( SV* rv )
{
	ppd_size_t* retval = NULL;
	HV* hv = NULL;
	SV** ssv;

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_size_t pointer ... */
	Newz( 69, retval, 1, ppd_size_t );

	/* ppd_size_t.marked */
	ssv = hv_fetch( hv, "marked", strlen( "marked" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->marked = SvIV( *ssv );
	}
	
	/* ppd_size_t.name */
	ssv = hv_fetch( hv, "name", strlen( "name" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		/* XXX Not completely correct XXX */
		strncpy( retval->name, (char*)SvPV_nolen( *ssv ), PPD_MAX_NAME );
	}

	/* ppd_size_t.width */
	ssv = hv_fetch( hv, "width", strlen( "width" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->width = SvNV( *ssv );
	}

	/* ppd_size_t.length */
	ssv = hv_fetch( hv, "length", strlen( "length" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->length = SvNV( *ssv );
	}

	/* ppd_size_t.left */
	ssv = hv_fetch( hv, "left", strlen( "left" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->left = SvNV( *ssv );
	}

	/* ppd_size_t.bottom */
	ssv = hv_fetch( hv, "bottom", strlen( "bottom" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->bottom = SvNV( *ssv );
	}

	/* ppd_size_t.right */
	ssv = hv_fetch( hv, "right", strlen( "right" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->right = SvNV( *ssv );
	}

	/* ppd_size_t.top */
	ssv = hv_fetch( hv, "top", strlen( "top" ), 0 );

	if( ssv != NULL && SvNOK( *ssv ) )
	{
		retval->top = SvNV( *ssv );
	}

	return retval;
}

ppd_file_t*
XS_unpack_ppd_file_tPtr( SV* rv )
{
	int loop = 0;
	ppd_file_t* retval = NULL;
	HV* hv = NULL;
	AV* av = NULL;
	SV** ssv;
	
	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( rv ) && ( SvTYPE( SvRV( rv ) ) ) == SVt_PVHV ) )
	{
		hv = (HV*)SvRV( rv );
	}

	if( !hv ) { return NULL; }

	/* Grab some memmory for our ppd_file_t pointer ... */
	Newz( 69, retval, 1, ppd_file_t );

	/* ppd_file_t.language_level */
	ssv = hv_fetch( hv, "language_level", strlen( "language_level" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->language_level = SvIV( *ssv );
	}

	/* ppd_file_t.color_device */
	ssv = hv_fetch( hv, "color_device", strlen( "color_device" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->color_device = SvIV( *ssv );
	}

	/* ppd_file_t.variable_sizes */
	ssv = hv_fetch( hv, "variable_sizes", strlen( "variable_sizes" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->variable_sizes = SvIV( *ssv );
	}

	/* ppd_file_t.accurate_screens */
	ssv = hv_fetch( hv, "accurate_screens", strlen( "accurate_screens" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->accurate_screens = SvIV( *ssv );
	}

	/* ppd_file_t.contone_only */
	ssv = hv_fetch( hv, "contone_only", strlen( "contone_only" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->contone_only = SvIV( *ssv );
	}

	/* ppd_file_t.landscape */
	ssv = hv_fetch( hv, "landscape", strlen( "landscape" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->landscape = SvIV( *ssv );
	}

	/* ppd_file_t.model_number */
	ssv = hv_fetch( hv, "model_number", strlen( "model_number" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->model_number = SvIV( *ssv );
	}

	/* ppd_file_t.manual_copies */
	ssv = hv_fetch( hv, "manual_copies", strlen( "manual_copies" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->manual_copies = SvIV( *ssv );
	}

	/* ppd_file_t.throughput */
	ssv = hv_fetch( hv, "throughput", strlen( "throughput" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->throughput = SvIV( *ssv );
	}

	/* Place holder for ppd_cs_t colorspace */

	/* ppd_file_t.patches */
	ssv = hv_fetch( hv, "patches", strlen( "patches" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->patches = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.emulations & ppd_file_t.num_emulations */
	ssv = hv_fetch( hv, "emulations", strlen( "emulations" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "emulations" are in our array */
	retval->num_emulations = av_len( av ) + 1;
	
	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_emulations < 0 )
	{
		retval->num_emulations = 0;
		retval->emulations = NULL;
	}
	else
	{
		Newz( 69, retval->emulations, retval->num_emulations, ppd_emul_t );
	}

	for( loop = 0; loop < retval->num_emulations; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->emulations[loop] = *XS_unpack_ppd_emul_tPtr( *ssv );
	}
	
	/* ppd_file_t.jcl_begin */
	ssv = hv_fetch( hv, "jcl_begin", strlen( "jcl_begin" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->jcl_begin = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.jcl_ps */
	ssv = hv_fetch( hv, "jcl_ps", strlen( "jcl_ps" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->jcl_ps = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.jcl_end */
	ssv = hv_fetch( hv, "jcl_end", strlen( "jcl_end" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->jcl_end = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.lang_encoding */
	ssv = hv_fetch( hv, "lang_encoding", strlen( "lang_encoding" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->lang_encoding = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.lang_version */
	ssv = hv_fetch( hv, "lang_version", strlen( "lang_version" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->lang_version = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.modelname */
	ssv = hv_fetch( hv, "modelname", strlen( "modelname" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->modelname = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.ttrasterizer */
	ssv = hv_fetch( hv, "ttrasterizer", strlen( "ttrasterizer" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->ttrasterizer = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.manufacturer */
	ssv = hv_fetch( hv, "manufacturer", strlen( "manufacturer" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->manufacturer = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.product */
	ssv = hv_fetch( hv, "product", strlen( "product" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->product = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.nickname */
	ssv = hv_fetch( hv, "nickname", strlen( "nickname" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->nickname = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.shortnickname */
	ssv = hv_fetch( hv, "shortnickname", strlen( "shortnickname" ), 0 );

	if( ssv != NULL && SvPOK( *ssv ) )
	{
		retval->shortnickname = SvPV_nolen( *ssv );
	}

	/* Place holder for ppd_group_t *groups */
	ssv = hv_fetch( hv, "groups", strlen( "groups" ), 0 );

	/* Check to see if we have a reference to a hash or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}
	
	/* Store this number ... */
	retval->num_groups = av_len( av ) + 1;

	/* Grab some memory for this option array. */
	Newz( 69, retval->groups, retval->num_groups, ppd_group_t );

	for( loop = 0; loop < retval->num_groups; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->groups[loop] = *XS_unpack_ppd_group_tPtr( *ssv );
	}
	
	/* ppd_file_t.num_sizes */
	ssv = hv_fetch( hv, "sizes", strlen( "sizes" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "sizes" are in our array */
	retval->num_sizes = av_len( av ) + 1;

	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_sizes < 0 )
	{
		retval->num_sizes = 0;
	}
	
	Newz( 69, retval->sizes, retval->num_sizes, ppd_size_t );

	for( loop = 0; loop < retval->num_sizes; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->sizes[loop] = *XS_unpack_ppd_size_tPtr( *ssv );
	}
	
	/* Place holder for float custom_min[2] */
	/* Place holder for float custom_max[2] */
	/* Place holder for float custom_margins[2] */
	
	/* ppd_file_t.num_consts */
	ssv = hv_fetch( hv, "consts", strlen( "consts" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "consts" are in our array */
	retval->num_consts = av_len( av ) + 1;

	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_consts < 0 )
	{
		retval->num_consts = 0;
	}
	
	Newz( 69, retval->consts, retval->num_consts, ppd_const_t );

	for( loop = 0; loop < retval->num_consts; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->consts[loop] = *XS_unpack_ppd_const_tPtr( *ssv );
	}

	/* ppd_file_t.num_fonts, ppd_file_t.fonts */
	ssv = hv_fetch( hv, "fonts", strlen( "fonts" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "fonts" are in our array */
	retval->num_fonts = av_len( av ) + 1;

	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_fonts < 0 )
	{
		retval->num_fonts = 0;
	}
	
	Newz( 69, retval->fonts, retval->num_fonts, char* );

	for( loop = 0; loop < retval->num_fonts; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->fonts[loop] = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.num_profiles, ppd_file_t.profiles */
	ssv = hv_fetch( hv, "profiles", strlen( "profiles" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "profiles" are in our array */
	retval->num_profiles = av_len( av ) + 1;

	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_profiles < 0 )
	{
		retval->num_profiles = 0;
	}
	
	Newz( 69, retval->profiles, retval->num_profiles, ppd_profile_t );

	for( loop = 0; loop < retval->num_profiles; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->profiles[loop] = *XS_unpack_ppd_profile_tPtr( *ssv );
	}

	/* ppd_file_t.num_filters */
	ssv = hv_fetch( hv, "filters", strlen( "filters" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "filters" are in our array */
	retval->num_filters = av_len( av ) + 1;

	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_filters < 0 )
	{
		retval->num_filters = 0;
	}
	
	Newz( 69, retval->filters, retval->num_filters, char* );

	for( loop = 0; loop < retval->num_filters; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->filters[loop] = SvPV_nolen( *ssv );
	}

	/* ppd_file_t.flip_duplex */
	ssv = hv_fetch( hv, "flip_duplex", strlen( "flip_duplex" ), 0 );

	if( ssv != NULL && SvIOK( *ssv ) )
	{
		retval->flip_duplex = SvIV( *ssv );
	}
	
	/* ppd_file_t.num_attrs */
	ssv = hv_fetch( hv, "attrs", strlen( "attrs" ), 0 );

	/* Check to see if we have a reference to an array or not. */
	if( ( SvROK( *ssv ) && ( SvTYPE( SvRV( *ssv ) ) ) == SVt_PVAV ) )
	{
		av = (AV*)SvRV( *ssv );
	}

	/* Grab how many "attrs" are in our array */
	retval->num_attrs = av_len( av ) + 1;

	/* If the number of array elements is less then 0, then make it 0 */
	if( retval->num_attrs < 0 )
	{
		retval->num_attrs = 0;
	}
	
	Newz( 69, retval->attrs, retval->num_attrs, ppd_attr_t* );

	for( loop = 0; loop < retval->num_attrs; loop++ )
	{
		/* Grab the array item out of the array */
		ssv = av_fetch( av, loop, 0 );
		/* Store the converted array item. */
		retval->attrs[loop] = XS_unpack_ppd_attr_tPtr( *ssv );
	}
	
	return retval;
}
