#define PERL_constant_NOTFOUND	1
#define PERL_constant_NOTDEF	2
#define PERL_constant_ISIV	3
#define PERL_constant_ISNO	4
#define PERL_constant_ISNV	5
#define PERL_constant_ISPV	6
#define PERL_constant_ISPVN	7
#define PERL_constant_ISSV	8
#define PERL_constant_ISUNDEF	9
#define PERL_constant_ISUV	10
#define PERL_constant_ISYES	11

#ifndef NVTYPE
typedef double NV; /* 5.6 and later define NVTYPE, and typedef NV to it.  */
#endif
#ifndef aTHX_
#define aTHX_ /* 5.6 or later define this for threading support.  */
#endif
#ifndef pTHX_
#define pTHX_ /* 5.6 or later define this for threading support.  */
#endif

static int
constant_12 (pTHX_ const char *name, IV *iv_return, NV *nv_return) 
{
	switch (name[8]) 
	{
		case 'L':
			if (memEQ(name, "PPD_MAX_LINE", 12)) 
			{
			/*                       ^          */
#ifdef PPD_MAX_LINE
				*iv_return = PPD_MAX_LINE;
				return PERL_constant_ISIV;
#else
				return PERL_constant_NOTDEF;
#endif
			}
		break;

		case 'N':
			if (memEQ(name, "PPD_MAX_NAME", 12)) 
			{
			/*                       ^          */
#ifdef PPD_MAX_NAME
				*iv_return = PPD_MAX_NAME;
				return PERL_constant_ISIV;
#else
				return PERL_constant_NOTDEF;
#endif
			}
		break;

		case 'T':
			if (memEQ(name, "PPD_MAX_TEXT", 12)) 
			{
			/*                       ^          */
#ifdef PPD_MAX_TEXT
				*iv_return = PPD_MAX_TEXT;
				return PERL_constant_ISIV;
#else
				return PERL_constant_NOTDEF;
#endif
			}
		break;
	}
	
	return PERL_constant_NOTFOUND;
}

static int
constant (pTHX_ const char *name, STRLEN length, IV *iv_return, NV *nv_return) 
{
	switch( length ) 
	{
		case 8:
			if( memEQ( name, "PPD_CS_N", 8 ) )
			{
				*iv_return = PPD_CS_N;
				return PERL_constant_ISIV;
			}
		break;

		case 10:
			if( memEQ( name, "PPD_CS_CMY", 10 ) )
			{
				*iv_return = PPD_CS_CMY;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_CS_RGB", 10 ) )
			{
				*iv_return = PPD_CS_RGB;
				return PERL_constant_ISIV;
			}
		break;

		case 11:
			if ( memEQ( name, "PPD_VERSION", 11 ) ) 
			{
#ifdef PPD_VERSION
				*nv_return = PPD_VERSION;
				return PERL_constant_ISNV;
#else
				return PERL_constant_NOTDEF;
#endif
			}
			if( memEQ( name, "PPD_CS_CMYK", 11 ) )
			{
				*iv_return = PPD_CS_CMYK;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_CS_GRAY", 11 ) )
			{
				*iv_return = PPD_CS_GRAY;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_CS_RGBK", 11 ) )
			{
				*iv_return = PPD_CS_RGBK;
				return PERL_constant_ISIV;
			}
		break;
		
		case 12:
    		return constant_12 (aTHX_ name, iv_return, nv_return);
		break;

		case 13:
			if( memEQ( name, "PPD_ORDER_ANY", 13 ) )
			{
				*iv_return = PPD_ORDER_ANY;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_ORDER_JCL", 13 ) )
			{
				*iv_return = PPD_ORDER_JCL;
				return PERL_constant_ISIV;
			}
		break;

		case 14:
			if( memEQ( name, "PPD_UI_BOOLEAN", 14 ) )
			{
				*iv_return = PPD_UI_BOOLEAN;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_UI_PICKONE", 14 ) )
			{
				*iv_return = PPD_UI_PICKONE;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_ORDER_EXIT", 14 ) )
			{
				*iv_return = PPD_ORDER_EXIT;
				return PERL_constant_ISIV;
			}
			if( memEQ( name, "PPD_ORDER_PAGE", 14 ) )
			{
				*iv_return = PPD_ORDER_PAGE;
				return PERL_constant_ISIV;
			}
		break;
	
		case 15:
			if( memEQ( name, "PPD_UI_PICKMANY", 15 ) )
			{
				*iv_return = PPD_UI_PICKMANY;
				return PERL_constant_ISIV;
			}
		break;	
	
		case 16:
			if( memEQ( name, "PPD_ORDER_PROLOG", 16 ) )
			{
				*iv_return = PPD_ORDER_PROLOG;
				return PERL_constant_ISIV;
			}
		break;	
	
		case 18:
			if( memEQ( name, "PPD_ORDER_DOCUMENT", 18 ) )
			{
				*iv_return = PPD_ORDER_DOCUMENT;
				return PERL_constant_ISIV;
			}
		break;	
	}
  
	return PERL_constant_NOTFOUND;
}

