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
constant_18 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* Offset 15 gives the best switch position.  */
  switch (name[15]) {
  case 'A':
    if (memEQ(name, "CUPS_PRINTER_CLASS", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_CLASS;
      return PERL_constant_ISIV;
    }
    if (memEQ(name, "CUPS_PRINTER_SMALL", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_SMALL;
      return PERL_constant_ISIV;
    }
    break;
  case 'C':
    if (memEQ(name, "CUPS_PRINTER_LOCAL", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_LOCAL;
      return PERL_constant_ISIV;
    }
    break;
  case 'J':
    if (memEQ(name, "CUPS_VERSION_MAJOR", 18)) {
    /*                              ^         */
#ifdef CUPS_VERSION_MAJOR
      *iv_return = CUPS_VERSION_MAJOR;
      return PERL_constant_ISIV;
#else
      return PERL_constant_NOTDEF;
#endif
    }
    break;
  case 'L':
    if (memEQ(name, "CUPS_PRINTER_COLOR", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_COLOR;
      return PERL_constant_ISIV;
    }
    break;
  case 'N':
    if (memEQ(name, "CUPS_PRINTER_PUNCH", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_PUNCH;
      return PERL_constant_ISIV;
    }
    if (memEQ(name, "CUPS_VERSION_MINOR", 18)) {
    /*                              ^         */
      *iv_return = CUPS_VERSION_MINOR;
      return PERL_constant_ISIV;
    }
    break;
  case 'R':
    if (memEQ(name, "CUPS_PRINTER_LARGE", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_LARGE;
      return PERL_constant_ISIV;
    }
    break;
  case 'T':
    if (memEQ(name, "CUPS_VERSION_PATCH", 18)) {
    /*                              ^         */
#ifdef CUPS_VERSION_PATCH
      *iv_return = CUPS_VERSION_PATCH;
      return PERL_constant_ISIV;
#else
      return PERL_constant_NOTDEF;
#endif
    }
    break;
  case 'V':
    if (memEQ(name, "CUPS_PRINTER_COVER", 18)) {
    /*                              ^         */
      *iv_return = CUPS_PRINTER_COVER;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_19 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* Offset 13 gives the best switch position.  */
  switch (name[13]) {
  case 'C':
    if (memEQ(name, "CUPS_PRINTER_COPIES", 19)) {
    /*                            ^            */
      *iv_return = CUPS_PRINTER_COPIES;
      return PERL_constant_ISIV;
    }
    break;
  case 'D':
    if (memEQ(name, "CUPS_PRINTER_DUPLEX", 19)) {
    /*                            ^            */
      *iv_return = CUPS_PRINTER_DUPLEX;
      return PERL_constant_ISIV;
    }
    break;
  case 'M':
    if (memEQ(name, "CUPS_PRINTER_MEDIUM", 19)) {
    /*                            ^            */
      *iv_return = CUPS_PRINTER_MEDIUM;
      return PERL_constant_ISIV;
    }
    break;
  case 'R':
    if (memEQ(name, "CUPS_PRINTER_REMOTE", 19)) {
    /*                            ^            */
      *iv_return = CUPS_PRINTER_REMOTE;
      return PERL_constant_ISIV;
    }
    break;
  case 'S':
    if (memEQ(name, "CUPS_PRINTER_STAPLE", 19)) {
    /*                            ^            */
      *iv_return = CUPS_PRINTER_STAPLE;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_20 (pTHX_ const char *name, IV *iv_return, NV *nv_return) {
  /* Offset 18 gives the best switch position.  */
  switch (name[18]) {
  case 'L':
    if (memEQ(name, "CUPS_PRINTER_DEFAULT", 20)) {
    /*                                 ^        */
      *iv_return = CUPS_PRINTER_DEFAULT;
      return PERL_constant_ISIV;
    }
    break;
  case 'N':
    if (memEQ(name, "CUPS_PRINTER_OPTIONS", 20)) {
    /*                                 ^        */
      *iv_return = CUPS_PRINTER_OPTIONS;
      return PERL_constant_ISIV;
    }
    break;
  case 'T':
    if (memEQ(name, "CUPS_PRINTER_COLLATE", 20)) {
    /*                                 ^        */
      *iv_return = CUPS_PRINTER_COLLATE;
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
my @names = (qw(CUPS_DATE_ANY CUPS_PRINTER_BIND CUPS_PRINTER_BW
	       CUPS_PRINTER_CLASS CUPS_PRINTER_COLLATE CUPS_PRINTER_COLOR
	       CUPS_PRINTER_COPIES CUPS_PRINTER_COVER CUPS_PRINTER_DEFAULT
	       CUPS_PRINTER_DUPLEX CUPS_PRINTER_IMPLICIT CUPS_PRINTER_LARGE
	       CUPS_PRINTER_LOCAL CUPS_PRINTER_MEDIUM CUPS_PRINTER_OPTIONS
	       CUPS_PRINTER_PUNCH CUPS_PRINTER_REMOTE CUPS_PRINTER_SMALL
	       CUPS_PRINTER_SORT CUPS_PRINTER_STAPLE CUPS_PRINTER_VARIABLE
	       CUPS_VERSION CUPS_VERSION_MAJOR CUPS_VERSION_MINOR
	       CUPS_VERSION_PATCH CUPS_PRINTER_REJECTING));

print constant_types(); # macro defs
foreach (C_constant ("T", 'constant', 'IV', $types, undef, 3, @names) ) {
    print $_, "\n"; # C constant subs
}
print "#### XS Section:\n";
print XS_constant ("T", $types);
__END__
   */

  switch (len) {
  case 12:
    if (memEQ(name, "CUPS_VERSION", 12)) {
#ifdef CUPS_VERSION
      *nv_return = CUPS_VERSION;
      return PERL_constant_ISNV;
#else
      return PERL_constant_NOTDEF;
#endif
    }
    break;
  case 13:
    if (memEQ(name, "CUPS_DATE_ANY", 13)) {
#ifdef CUPS_DATE_ANY
      *iv_return = CUPS_DATE_ANY;
      return PERL_constant_ISIV;
#else
      return PERL_constant_NOTDEF;
#endif
    }
    break;
  case 15:
    if (memEQ(name, "CUPS_PRINTER_BW", 15)) {
      *iv_return = CUPS_PRINTER_BW;
      return PERL_constant_ISIV;
    }
    break;
  case 16:
  	if( memEQ(name, "CUPS_PRINTER_FAX", 16)) {
      *iv_return = CUPS_PRINTER_FAX;
      return PERL_constant_ISIV;
    }
    break;
  case 17:
    /* Names all of length 17.  */
    /* CUPS_PRINTER_BIND CUPS_PRINTER_SORT */
    /* Offset 15 gives the best switch position.  */
    switch (name[15]) {
    case 'N':
      if (memEQ(name, "CUPS_PRINTER_BIND", 17)) {
      /*                              ^        */
        *iv_return = CUPS_PRINTER_BIND;
        return PERL_constant_ISIV;
      }
      break;
    case 'R':
      if (memEQ(name, "CUPS_PRINTER_SORT", 17)) {
      /*                              ^        */
        *iv_return = CUPS_PRINTER_SORT;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 18:
    return constant_18 (aTHX_ name, iv_return, nv_return);
    break;
  case 19:
    return constant_19 (aTHX_ name, iv_return, nv_return);
    break;
  case 20:
    return constant_20 (aTHX_ name, iv_return, nv_return);
    break;
  case 21:
    /* Names all of length 21.  */
    /* CUPS_PRINTER_IMPLICIT CUPS_PRINTER_VARIABLE */
    /* Offset 18 gives the best switch position.  */
    switch (name[18]) {
    case 'B':
      if (memEQ(name, "CUPS_PRINTER_VARIABLE", 21)) {
      /*                                 ^         */
        *iv_return = CUPS_PRINTER_VARIABLE;
        return PERL_constant_ISIV;
      }
      break;
    case 'C':
      if (memEQ(name, "CUPS_PRINTER_IMPLICIT", 21)) {
      /*                                 ^         */
        *iv_return = CUPS_PRINTER_IMPLICIT;
        return PERL_constant_ISIV;
      }
      break;
    }
  case 22:
    if (memEQ(name, "CUPS_PRINTER_REJECTING", 22)) {
	  *iv_return = CUPS_PRINTER_REJECTING;
	  return PERL_constant_ISIV;
	}
	break;
  }
  return PERL_constant_NOTFOUND;
}
