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
constant_11 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     PPD_CS_CMYK PPD_CS_GRAY PPD_CS_RGBK PPD_VERSION */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'G':
    if (memEQ(name, "PPD_CS_RGBK", 11)) {
    /*                       ^         */
      *iv_return = PPD_CS_RGBK;
      return PERL_constant_ISIV;
    }
    break;
  case 'I':
    if (memEQ(name, "PPD_VERSION", 11)) {
    /*                       ^         */
#ifdef PPD_VERSION
      *nv_return = PPD_VERSION;
      return PERL_constant_ISNV;
#else
      return PERL_constant_NOTDEF;
#endif
    }
    break;
  case 'M':
    if (memEQ(name, "PPD_CS_CMYK", 11)) {
    /*                       ^         */
      *iv_return = PPD_CS_CMYK;
      return PERL_constant_ISIV;
    }
    break;
  case 'R':
    if (memEQ(name, "PPD_CS_GRAY", 11)) {
    /*                       ^         */
      *iv_return = PPD_CS_GRAY;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_12 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     PPD_MAX_LINE PPD_MAX_NAME PPD_MAX_TEXT */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'L':
    if (memEQ(name, "PPD_MAX_LINE", 12)) {
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
    if (memEQ(name, "PPD_MAX_NAME", 12)) {
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
    if (memEQ(name, "PPD_MAX_TEXT", 12)) {
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
constant_13 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     PPD_NULL_FILE PPD_ORDER_ANY PPD_ORDER_JCL */
  /* Offset 10 gives the best switch position.  */
  switch (name[10]) {
  case 'A':
    if (memEQ(name, "PPD_ORDER_ANY", 13)) {
    /*                         ^         */
      *iv_return = PPD_ORDER_ANY;
      return PERL_constant_ISIV;
    }
    break;
  case 'I':
    if (memEQ(name, "PPD_NULL_FILE", 13)) {
    /*                         ^         */
      *iv_return = PPD_NULL_FILE;
      return PERL_constant_ISIV;
    }
    break;
  case 'J':
    if (memEQ(name, "PPD_ORDER_JCL", 13)) {
    /*                         ^         */
      *iv_return = PPD_ORDER_JCL;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_14 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     PPD_ORDER_EXIT PPD_ORDER_PAGE PPD_UI_BOOLEAN PPD_UI_PICKONE */
  /* Offset 10 gives the best switch position.  */
  switch (name[10]) {
  case 'E':
    if (memEQ(name, "PPD_ORDER_EXIT", 14)) {
    /*                         ^          */
      *iv_return = PPD_ORDER_EXIT;
      return PERL_constant_ISIV;
    }
    break;
  case 'K':
    if (memEQ(name, "PPD_UI_PICKONE", 14)) {
    /*                         ^          */
      *iv_return = PPD_UI_PICKONE;
      return PERL_constant_ISIV;
    }
    break;
  case 'L':
    if (memEQ(name, "PPD_UI_BOOLEAN", 14)) {
    /*                         ^          */
      *iv_return = PPD_UI_BOOLEAN;
      return PERL_constant_ISIV;
    }
    break;
  case 'P':
    if (memEQ(name, "PPD_ORDER_PAGE", 14)) {
    /*                         ^          */
      *iv_return = PPD_ORDER_PAGE;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_18 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     PPD_BAD_OPEN_GROUP PPD_INTERNAL_ERROR PPD_ORDER_DOCUMENT */
  /* Offset 11 gives the best switch position.  */
  switch (name[11]) {
  case 'L':
    if (memEQ(name, "PPD_INTERNAL_ERROR", 18)) {
    /*                          ^             */
      *iv_return = PPD_INTERNAL_ERROR;
      return PERL_constant_ISIV;
    }
    break;
  case 'N':
    if (memEQ(name, "PPD_BAD_OPEN_GROUP", 18)) {
    /*                          ^             */
      *iv_return = PPD_BAD_OPEN_GROUP;
      return PERL_constant_ISIV;
    }
    break;
  case 'O':
    if (memEQ(name, "PPD_ORDER_DOCUMENT", 18)) {
    /*                          ^             */
      *iv_return = PPD_ORDER_DOCUMENT;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_21 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     PPD_ILLEGAL_CHARACTER PPD_MISSING_PPDADOBE4 PPD_NESTED_OPEN_GROUP */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'E':
    if (memEQ(name, "PPD_NESTED_OPEN_GROUP", 21)) {
    /*                       ^                   */
      *iv_return = PPD_NESTED_OPEN_GROUP;
      return PERL_constant_ISIV;
    }
    break;
  case 'G':
    if (memEQ(name, "PPD_ILLEGAL_CHARACTER", 21)) {
    /*                       ^                   */
      *iv_return = PPD_ILLEGAL_CHARACTER;
      return PERL_constant_ISIV;
    }
    break;
  case 'I':
    if (memEQ(name, "PPD_MISSING_PPDADOBE4", 21)) {
    /*                       ^                   */
      *iv_return = PPD_MISSING_PPDADOBE4;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant (pTHX_ const char *name, STRLEN len, IV *iv_return, NV *nv_return) {
  /* Initially switch on the length of the name.  */
  /* When generated this function returned values for the list of names given
     in this section of perl code.  Rather than manually editing these functions
     to add or remove constants, which would result in this comment and section
     of code becoming inaccurate, we recommend that you edit this section of
     code, and use it to regenerate a new set of constant functions which you
     then use to replace the originals.

     Regenerate these constant functions by feeding this entire source file to
     perl -x

#!/usr/bin/perl -w
use ExtUtils::Constant qw (constant_types C_constant XS_constant);

my $types = {map {($_, 1)} qw(IV)};
my @names = (qw(PPD_ALLOC_ERROR PPD_BAD_OPEN_GROUP PPD_BAD_ORDER_DEPENDENCY
	       PPD_BAD_UI_CONSTRAINTS PPD_CS_CMY PPD_CS_CMYK PPD_CS_GRAY
	       PPD_CS_N PPD_CS_RGB PPD_CS_RGBK PPD_FILE_OPEN_ERROR
	       PPD_ILLEGAL_CHARACTER PPD_ILLEGAL_MAIN_KEYWORD
	       PPD_ILLEGAL_OPTION_KEYWORD PPD_ILLEGE_TRANSLATION
	       PPD_INTERNAL_ERROR PPD_LINE_TOO_LONG PPD_MAX_LINE PPD_MAX_NAME
	       PPD_MAX_TEXT PPD_MISSING_ASTERISK PPD_MISSING_PPDADOBE4
	       PPD_MISSING_VALUE PPD_NESTED_OPEN_GROUP PPD_NULL_FILE PPD_OK
	       PPD_ORDER_ANY PPD_ORDER_DOCUMENT PPD_ORDER_EXIT PPD_ORDER_JCL
	       PPD_ORDER_PAGE PPD_ORDER_PROLOG PPD_UI_BOOLEAN PPD_UI_PICKMANY
	       PPD_UI_PICKONE PPD_VERSION));

print constant_types(); # macro defs
foreach (C_constant ("T", 'constant', 'IV', $types, undef, 3, @names) ) {
    print $_, "\n"; # C constant subs
}
print "#### XS Section:\n";
print XS_constant ("T", $types);
__END__
   */

  switch (len) {
  case 6:
    if (memEQ(name, "PPD_OK", 6)) {
      *iv_return = PPD_OK;
      return PERL_constant_ISIV;
    }
    break;
  case 8:
    if (memEQ(name, "PPD_CS_N", 8)) {
      *iv_return = PPD_CS_N;
      return PERL_constant_ISIV;
    }
    break;
  case 10:
    /* Names all of length 10.  */
    /* PPD_CS_CMY PPD_CS_RGB */
    /* Offset 8 gives the best switch position.  */
    switch (name[8]) {
    case 'G':
      if (memEQ(name, "PPD_CS_RGB", 10)) {
      /*                       ^        */
        *iv_return = PPD_CS_RGB;
        return PERL_constant_ISIV;
      }
      break;
    case 'M':
      if (memEQ(name, "PPD_CS_CMY", 10)) {
      /*                       ^        */
        *iv_return = PPD_CS_CMY;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 11:
    return constant_11 (aTHX_ name, iv_return, nv_return);
    break;
  case 12:
    return constant_12 (aTHX_ name, iv_return, nv_return);
    break;
  case 13:
    return constant_13 (aTHX_ name, iv_return, nv_return);
    break;
  case 14:
    return constant_14 (aTHX_ name, iv_return, nv_return);
    break;
  case 15:
    /* Names all of length 15.  */
    /* PPD_ALLOC_ERROR PPD_UI_PICKMANY */
    /* Offset 7 gives the best switch position.  */
    switch (name[7]) {
    case 'O':
      if (memEQ(name, "PPD_ALLOC_ERROR", 15)) {
      /*                      ^              */
        *iv_return = PPD_ALLOC_ERROR;
        return PERL_constant_ISIV;
      }
      break;
    case 'P':
      if (memEQ(name, "PPD_UI_PICKMANY", 15)) {
      /*                      ^              */
        *iv_return = PPD_UI_PICKMANY;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 16:
    if (memEQ(name, "PPD_ORDER_PROLOG", 16)) {
      *iv_return = PPD_ORDER_PROLOG;
      return PERL_constant_ISIV;
    }
    break;
  case 17:
    /* Names all of length 17.  */
    /* PPD_LINE_TOO_LONG PPD_MISSING_VALUE */
    /* Offset 4 gives the best switch position.  */
    switch (name[4]) {
    case 'L':
      if (memEQ(name, "PPD_LINE_TOO_LONG", 17)) {
      /*                   ^                   */
        *iv_return = PPD_LINE_TOO_LONG;
        return PERL_constant_ISIV;
      }
      break;
    case 'M':
      if (memEQ(name, "PPD_MISSING_VALUE", 17)) {
      /*                   ^                   */
        *iv_return = PPD_MISSING_VALUE;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 18:
    return constant_18 (aTHX_ name, iv_return, nv_return);
    break;
  case 19:
    if (memEQ(name, "PPD_FILE_OPEN_ERROR", 19)) {
      *iv_return = PPD_FILE_OPEN_ERROR;
      return PERL_constant_ISIV;
    }
    break;
  case 20:
    if (memEQ(name, "PPD_MISSING_ASTERISK", 20)) {
      *iv_return = PPD_MISSING_ASTERISK;
      return PERL_constant_ISIV;
    }
    break;
  case 21:
    return constant_21 (aTHX_ name, iv_return, nv_return);
    break;
  case 22:
    /* Names all of length 22.  */
    /* PPD_BAD_UI_CONSTRAINTS PPD_ILLEGE_TRANSLATION */
    /* Offset 15 gives the best switch position.  */
    switch (name[15]) {
    case 'S':
      if (memEQ(name, "PPD_ILLEGAL_TRANSLATION", 22)) {
      /*                              ^             */
        *iv_return = PPD_ILLEGAL_TRANSLATION;
        return PERL_constant_ISIV;
      }
      break;
    case 'T':
      if (memEQ(name, "PPD_BAD_UI_CONSTRAINTS", 22)) {
      /*                              ^             */
        *iv_return = PPD_BAD_UI_CONSTRAINTS;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 24:
    /* Names all of length 24.  */
    /* PPD_BAD_ORDER_DEPENDENCY PPD_ILLEGAL_MAIN_KEYWORD */
    /* Offset 21 gives the best switch position.  */
    switch (name[21]) {
    case 'N':
      if (memEQ(name, "PPD_BAD_ORDER_DEPENDENCY", 24)) {
      /*                                    ^         */
        *iv_return = PPD_BAD_ORDER_DEPENDENCY;
        return PERL_constant_ISIV;
      }
      break;
    case 'O':
      if (memEQ(name, "PPD_ILLEGAL_MAIN_KEYWORD", 24)) {
      /*                                    ^         */
        *iv_return = PPD_ILLEGAL_MAIN_KEYWORD;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 26:
    if (memEQ(name, "PPD_ILLEGAL_OPTION_KEYWORD", 26)) {
      *iv_return = PPD_ILLEGAL_OPTION_KEYWORD;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

