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
constant_8 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_0_9 HTTP_1_0 HTTP_1_1 HTTP_GET HTTP_PUT IPP_DATA IPP_IDLE IPP_PORT */
  /* Offset 5 gives the best switch position.  */
  switch (name[5]) {
  case '0':
    if (memEQ(name, "HTTP_0_9", 8)) {
    /*                    ^        */

      *iv_return = HTTP_0_9;
      return PERL_constant_ISIV;

      

    }
    break;
  case '1':
    if (memEQ(name, "HTTP_1_0", 8)) {
    /*                    ^        */

      *iv_return = HTTP_1_0;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_1_1", 8)) {
    /*                    ^        */

      *iv_return = HTTP_1_1;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'A':
    if (memEQ(name, "IPP_DATA", 8)) {
    /*                    ^        */

      *iv_return = IPP_DATA;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "IPP_IDLE", 8)) {
    /*                    ^        */

      *iv_return = IPP_IDLE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'G':
    if (memEQ(name, "HTTP_GET", 8)) {
    /*                    ^        */

      *iv_return = HTTP_GET;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "IPP_PORT", 8)) {
    /*                    ^        */

      *iv_return = IPP_PORT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "HTTP_PUT", 8)) {
    /*                    ^        */

      *iv_return = HTTP_PUT;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_9 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_GONE HTTP_HEAD HTTP_POST IPP_ERROR */
  /* Offset 5 gives the best switch position.  */
  switch (name[5]) {
  case 'G':
    if (memEQ(name, "HTTP_GONE", 9)) {
    /*                    ^         */

      *iv_return = HTTP_GONE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "HTTP_HEAD", 9)) {
    /*                    ^         */

      *iv_return = HTTP_HEAD;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "HTTP_POST", 9)) {
    /*                    ^         */

      *iv_return = HTTP_POST;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "IPP_ERROR", 9)) {
    /*                    ^         */

      *iv_return = IPP_ERROR;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_10 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_CLOSE HTTP_ERROR HTTP_TRACE IPP_HEADER */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'C':
    if (memEQ(name, "HTTP_TRACE", 10)) {
    /*                       ^        */

      *iv_return = HTTP_TRACE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "IPP_HEADER", 10)) {
    /*                       ^        */

      *iv_return = IPP_HEADER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "HTTP_ERROR", 10)) {
    /*                       ^        */

      *iv_return = HTTP_ERROR;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "HTTP_CLOSE", 10)) {
    /*                       ^        */

      *iv_return = HTTP_CLOSE;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_11 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_DELETE HTTP_STATUS IPP_PRIVATE IPP_TAG_END IPP_TAG_JOB IPP_TAG_URI */
  /* Offset 9 gives the best switch position.  */
  switch (name[9]) {
  case 'N':
    if (memEQ(name, "IPP_TAG_END", 11)) {
    /*                        ^        */

      *iv_return = IPP_TAG_END;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "IPP_TAG_JOB", 11)) {
    /*                        ^        */

      *iv_return = IPP_TAG_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "IPP_TAG_URI", 11)) {
    /*                        ^        */

      *iv_return = IPP_TAG_URI;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "HTTP_DELETE", 11)) {
    /*                        ^        */

      *iv_return = HTTP_DELETE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_PRIVATE", 11)) {
    /*                        ^        */

      *iv_return = IPP_PRIVATE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "HTTP_STATUS", 11)) {
    /*                        ^        */

      *iv_return = HTTP_STATUS;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_12 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_CREATED HTTP_MAX_URI HTTP_OPTIONS HTTP_WAITING IPP_GET_JOBS
     IPP_HOLD_JOB IPP_JOB_HELD IPP_MAX_NAME IPP_OK_SUBST IPP_PORTRAIT
     IPP_SEND_URI IPP_TAG_COPY IPP_TAG_DATE IPP_TAG_ENUM IPP_TAG_MASK
     IPP_TAG_NAME IPP_TAG_TEXT IPP_TAG_ZERO */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'A':
    if (memEQ(name, "HTTP_CREATED", 12)) {
    /*                       ^          */

      *iv_return = HTTP_CREATED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "IPP_TAG_COPY", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_COPY;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "IPP_TAG_DATE", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_DATE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "IPP_TAG_ENUM", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_ENUM;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_JOB_HELD", 12)) {
    /*                       ^          */

      *iv_return = IPP_JOB_HELD;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "HTTP_OPTIONS", 12)) {
    /*                       ^          */

      *iv_return = HTTP_OPTIONS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'J':
    if (memEQ(name, "IPP_GET_JOBS", 12)) {
    /*                       ^          */

      *iv_return = IPP_GET_JOBS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'M':
    if (memEQ(name, "IPP_TAG_MASK", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_MASK;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "IPP_MAX_NAME", 12)) {
    /*                       ^          */

      *iv_return = IPP_MAX_NAME;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_NAME", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_NAME;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "IPP_PORTRAIT", 12)) {
    /*                       ^          */

      *iv_return = IPP_PORTRAIT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "HTTP_WAITING", 12)) {
    /*                       ^          */

      *iv_return = HTTP_WAITING;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_TEXT", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_TEXT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "IPP_OK_SUBST", 12)) {
    /*                       ^          */

      *iv_return = IPP_OK_SUBST;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'Z':
    if (memEQ(name, "IPP_TAG_ZERO", 12)) {
    /*                       ^          */

      *iv_return = IPP_TAG_ZERO;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "HTTP_MAX_URI", 12)) {
    /*                       ^          */

      *iv_return = HTTP_MAX_URI;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_HOLD_JOB", 12)) {
    /*                       ^          */

      *iv_return = IPP_HOLD_JOB;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_SEND_URI", 12)) {
    /*                       ^          */

      *iv_return = IPP_SEND_URI;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_13 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_GET_PPDS CUPS_MOVE_JOB HTTP_ACCEPTED HTTP_AUTH_MD5 HTTP_CONFLICT
     HTTP_CONTINUE HTTP_GET_SEND HTTP_MAX_HOST HTTP_PUT_RECV IPP_ATTRIBUTE
     IPP_FORBIDDEN IPP_LANDSCAPE IPP_PRINT_JOB IPP_PRINT_URI IPP_TAG_RANGE */
  /* Offset 11 gives the best switch position.  */
  switch (name[11]) {
  case 'C':
    if (memEQ(name, "HTTP_CONFLICT", 13)) {
    /*                          ^        */

      *iv_return = HTTP_CONFLICT;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_PUT_RECV", 13)) {
    /*                          ^        */

      *iv_return = HTTP_PUT_RECV;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "CUPS_GET_PPDS", 13)) {
    /*                          ^        */

      *iv_return = CUPS_GET_PPDS;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_AUTH_MD5", 13)) {
    /*                          ^        */

      *iv_return = HTTP_AUTH_MD5;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_ACCEPTED", 13)) {
    /*                          ^        */

      *iv_return = HTTP_ACCEPTED;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FORBIDDEN", 13)) {
    /*                          ^        */

      *iv_return = IPP_FORBIDDEN;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'G':
    if (memEQ(name, "IPP_TAG_RANGE", 13)) {
    /*                          ^        */

      *iv_return = IPP_TAG_RANGE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "HTTP_GET_SEND", 13)) {
    /*                          ^        */

      *iv_return = HTTP_GET_SEND;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "CUPS_MOVE_JOB", 13)) {
    /*                          ^        */

      *iv_return = CUPS_MOVE_JOB;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_PRINT_JOB", 13)) {
    /*                          ^        */

      *iv_return = IPP_PRINT_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "IPP_LANDSCAPE", 13)) {
    /*                          ^        */

      *iv_return = IPP_LANDSCAPE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "IPP_PRINT_URI", 13)) {
    /*                          ^        */

      *iv_return = IPP_PRINT_URI;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "HTTP_MAX_HOST", 13)) {
    /*                          ^        */

      *iv_return = HTTP_MAX_HOST;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_ATTRIBUTE", 13)) {
    /*                          ^        */

      *iv_return = IPP_ATTRIBUTE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "HTTP_CONTINUE", 13)) {
    /*                          ^        */

      *iv_return = HTTP_CONTINUE;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_14 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_ADD_CLASS HTTP_AUTH_NONE HTTP_FIELD_MAX HTTP_FORBIDDEN HTTP_MAX_VALUE
     HTTP_NOT_FOUND HTTP_POST_RECV HTTP_POST_SEND HTTP_SEE_OTHER HTTP_USE_PROXY
     IPP_CANCEL_JOB IPP_CREATE_JOB IPP_MAX_VALUES IPP_PURGE_JOBS IPP_RESUME_JOB
     IPP_RES_PER_CM IPP_TAG_STRING */
  /* Offset 9 gives the best switch position.  */
  switch (name[9]) {
  case 'A':
    if (memEQ(name, "IPP_MAX_VALUES", 14)) {
    /*                        ^           */

      *iv_return = IPP_MAX_VALUES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "CUPS_ADD_CLASS", 14)) {
    /*                        ^           */

      *iv_return = CUPS_ADD_CLASS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "HTTP_FIELD_MAX", 14)) {
    /*                        ^           */

      *iv_return = HTTP_FIELD_MAX;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "IPP_CREATE_JOB", 14)) {
    /*                        ^           */

      *iv_return = IPP_CREATE_JOB;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_RESUME_JOB", 14)) {
    /*                        ^           */

      *iv_return = IPP_RESUME_JOB;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_RES_PER_CM", 14)) {
    /*                        ^           */

      *iv_return = IPP_RES_PER_CM;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'F':
    if (memEQ(name, "HTTP_NOT_FOUND", 14)) {
    /*                        ^           */

      *iv_return = HTTP_NOT_FOUND;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "HTTP_FORBIDDEN", 14)) {
    /*                        ^           */

      *iv_return = HTTP_FORBIDDEN;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "IPP_CANCEL_JOB", 14)) {
    /*                        ^           */

      *iv_return = IPP_CANCEL_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "HTTP_SEE_OTHER", 14)) {
    /*                        ^           */

      *iv_return = HTTP_SEE_OTHER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "HTTP_USE_PROXY", 14)) {
    /*                        ^           */

      *iv_return = HTTP_USE_PROXY;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_TAG_STRING", 14)) {
    /*                        ^           */

      *iv_return = IPP_TAG_STRING;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'V':
    if (memEQ(name, "HTTP_MAX_VALUE", 14)) {
    /*                        ^           */

      *iv_return = HTTP_MAX_VALUE;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "HTTP_AUTH_NONE", 14)) {
    /*                        ^           */

      *iv_return = HTTP_AUTH_NONE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_POST_RECV", 14)) {
    /*                        ^           */

      *iv_return = HTTP_POST_RECV;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_POST_SEND", 14)) {
    /*                        ^           */

      *iv_return = HTTP_POST_SEND;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_PURGE_JOBS", 14)) {
    /*                        ^           */

      *iv_return = IPP_PURGE_JOBS;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_15 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_ADD_DEVICE HTTP_AUTH_BASIC HTTP_FIELD_DATE HTTP_FIELD_HOST
     HTTP_FIELD_LINK HTTP_MAX_BUFFER HTTP_NO_CONTENT IPP_BAD_REQUEST
     IPP_JOB_ABORTED IPP_JOB_PENDING IPP_JOB_STOPPED IPP_OK_CONFLICT
     IPP_PROMOTE_JOB IPP_RELEASE_JOB IPP_RESTART_JOB IPP_TAG_BOOLEAN
     IPP_TAG_CHARSET IPP_TAG_DEFAULT IPP_TAG_INTEGER IPP_TAG_KEYWORD
     IPP_TAG_NOVALUE IPP_TAG_PRINTER IPP_TAG_UNKNOWN */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'A':
    if (memEQ(name, "IPP_JOB_ABORTED", 15)) {
    /*                       ^             */

      *iv_return = IPP_JOB_ABORTED;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_RELEASE_JOB", 15)) {
    /*                       ^             */

      *iv_return = IPP_RELEASE_JOB;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_RESTART_JOB", 15)) {
    /*                       ^             */

      *iv_return = IPP_RESTART_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'B':
    if (memEQ(name, "IPP_TAG_BOOLEAN", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_BOOLEAN;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "HTTP_NO_CONTENT", 15)) {
    /*                       ^             */

      *iv_return = HTTP_NO_CONTENT;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_CHARSET", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_CHARSET;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "IPP_TAG_DEFAULT", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_DEFAULT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "HTTP_AUTH_BASIC", 15)) {
    /*                       ^             */

      *iv_return = HTTP_AUTH_BASIC;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_TAG_INTEGER", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_INTEGER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'K':
    if (memEQ(name, "IPP_TAG_KEYWORD", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_KEYWORD;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "HTTP_FIELD_DATE", 15)) {
    /*                       ^             */

      *iv_return = HTTP_FIELD_DATE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_FIELD_HOST", 15)) {
    /*                       ^             */

      *iv_return = HTTP_FIELD_HOST;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_FIELD_LINK", 15)) {
    /*                       ^             */

      *iv_return = HTTP_FIELD_LINK;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "IPP_TAG_NOVALUE", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_NOVALUE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "IPP_OK_CONFLICT", 15)) {
    /*                       ^             */

      *iv_return = IPP_OK_CONFLICT;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_PROMOTE_JOB", 15)) {
    /*                       ^             */

      *iv_return = IPP_PROMOTE_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "IPP_JOB_PENDING", 15)) {
    /*                       ^             */

      *iv_return = IPP_JOB_PENDING;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_PRINTER", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "IPP_BAD_REQUEST", 15)) {
    /*                       ^             */

      *iv_return = IPP_BAD_REQUEST;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "IPP_JOB_STOPPED", 15)) {
    /*                       ^             */

      *iv_return = IPP_JOB_STOPPED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "IPP_TAG_UNKNOWN", 15)) {
    /*                       ^             */

      *iv_return = IPP_TAG_UNKNOWN;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "CUPS_ADD_DEVICE", 15)) {
    /*                       ^             */

      *iv_return = CUPS_ADD_DEVICE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_MAX_BUFFER", 15)) {
    /*                       ^             */

      *iv_return = HTTP_MAX_BUFFER;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_16 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_ACCEPT_JOBS CUPS_ADD_PRINTER CUPS_GET_CLASSES CUPS_GET_DEFAULT
     CUPS_GET_DEVICES CUPS_REJECT_JOBS CUPS_SET_DEFAULT HTTP_BAD_GATEWAY
     HTTP_BAD_REQUEST HTTP_FIELD_RANGE IPP_NOT_POSSIBLE IPP_PRINTER_IDLE
     IPP_QUALITY_HIGH IPP_RES_PER_INCH IPP_TAG_LANGUAGE IPP_TAG_MIMETYPE
     IPP_TAG_NAMELANG IPP_TAG_TEXTLANG IPP_VALIDATE_JOB */
  /* Offset 13 gives the best switch position.  */
  switch (name[13]) {
  case 'A':
    if (memEQ(name, "IPP_TAG_LANGUAGE", 16)) {
    /*                            ^         */

      *iv_return = IPP_TAG_LANGUAGE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_NAMELANG", 16)) {
    /*                            ^         */

      *iv_return = IPP_TAG_NAMELANG;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_TEXTLANG", 16)) {
    /*                            ^         */

      *iv_return = IPP_TAG_TEXTLANG;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'B':
    if (memEQ(name, "IPP_NOT_POSSIBLE", 16)) {
    /*                            ^         */

      *iv_return = IPP_NOT_POSSIBLE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "CUPS_GET_DEVICES", 16)) {
    /*                            ^         */

      *iv_return = CUPS_GET_DEVICES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "IPP_PRINTER_IDLE", 16)) {
    /*                            ^         */

      *iv_return = IPP_PRINTER_IDLE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_BAD_REQUEST", 16)) {
    /*                            ^         */

      *iv_return = HTTP_BAD_REQUEST;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_QUALITY_HIGH", 16)) {
    /*                            ^         */

      *iv_return = IPP_QUALITY_HIGH;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'J':
    if (memEQ(name, "IPP_VALIDATE_JOB", 16)) {
    /*                            ^         */

      *iv_return = IPP_VALIDATE_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "HTTP_FIELD_RANGE", 16)) {
    /*                            ^         */

      *iv_return = HTTP_FIELD_RANGE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_RES_PER_INCH", 16)) {
    /*                            ^         */

      *iv_return = IPP_RES_PER_INCH;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "CUPS_ACCEPT_JOBS", 16)) {
    /*                            ^         */

      *iv_return = CUPS_ACCEPT_JOBS;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "CUPS_REJECT_JOBS", 16)) {
    /*                            ^         */

      *iv_return = CUPS_REJECT_JOBS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "CUPS_GET_CLASSES", 16)) {
    /*                            ^         */

      *iv_return = CUPS_GET_CLASSES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "CUPS_ADD_PRINTER", 16)) {
    /*                            ^         */

      *iv_return = CUPS_ADD_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "CUPS_GET_DEFAULT", 16)) {
    /*                            ^         */

      *iv_return = CUPS_GET_DEFAULT;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "CUPS_SET_DEFAULT", 16)) {
    /*                            ^         */

      *iv_return = CUPS_SET_DEFAULT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'W':
    if (memEQ(name, "HTTP_BAD_GATEWAY", 16)) {
    /*                            ^         */

      *iv_return = HTTP_BAD_GATEWAY;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'Y':
    if (memEQ(name, "IPP_TAG_MIMETYPE", 16)) {
    /*                            ^         */

      *iv_return = IPP_TAG_MIMETYPE;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_17 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_DELETE_CLASS CUPS_GET_PRINTERS HTTP_AUTH_MD5_INT HTTP_KEEPALIVE_ON
     HTTP_NOT_MODIFIED HTTP_PRECONDITION HTTP_SERVER_ERROR HTTP_UNAUTHORIZED
     HTTP_URI_TOO_LONG IPP_HOLD_NEW_JOBS IPP_JOB_CANCELLED IPP_JOB_COMPLETED
     IPP_PAUSE_PRINTER IPP_QUALITY_DRAFT IPP_REPROCESS_JOB IPP_SEND_DOCUMENT
     IPP_TAG_OPERATION IPP_TAG_URISCHEME */
  /* Offset 12 gives the best switch position.  */
  switch (name[12]) {
  case '5':
    if (memEQ(name, "HTTP_AUTH_MD5_INT", 17)) {
    /*                           ^           */

      *iv_return = HTTP_AUTH_MD5_INT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'A':
    if (memEQ(name, "IPP_TAG_OPERATION", 17)) {
    /*                           ^           */

      *iv_return = IPP_TAG_OPERATION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "CUPS_DELETE_CLASS", 17)) {
    /*                           ^           */

      *iv_return = CUPS_DELETE_CLASS;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_URISCHEME", 17)) {
    /*                           ^           */

      *iv_return = IPP_TAG_URISCHEME;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "IPP_QUALITY_DRAFT", 17)) {
    /*                           ^           */

      *iv_return = IPP_QUALITY_DRAFT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_SERVER_ERROR", 17)) {
    /*                           ^           */

      *iv_return = HTTP_SERVER_ERROR;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_JOB_CANCELLED", 17)) {
    /*                           ^           */

      *iv_return = IPP_JOB_CANCELLED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "HTTP_NOT_MODIFIED", 17)) {
    /*                           ^           */

      *iv_return = HTTP_NOT_MODIFIED;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_PRECONDITION", 17)) {
    /*                           ^           */

      *iv_return = HTTP_PRECONDITION;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_PAUSE_PRINTER", 17)) {
    /*                           ^           */

      *iv_return = IPP_PAUSE_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "IPP_JOB_COMPLETED", 17)) {
    /*                           ^           */

      *iv_return = IPP_JOB_COMPLETED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "CUPS_GET_PRINTERS", 17)) {
    /*                           ^           */

      *iv_return = CUPS_GET_PRINTERS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "HTTP_UNAUTHORIZED", 17)) {
    /*                           ^           */

      *iv_return = HTTP_UNAUTHORIZED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "IPP_REPROCESS_JOB", 17)) {
    /*                           ^           */

      *iv_return = IPP_REPROCESS_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "IPP_SEND_DOCUMENT", 17)) {
    /*                           ^           */

      *iv_return = IPP_SEND_DOCUMENT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'V':
    if (memEQ(name, "HTTP_KEEPALIVE_ON", 17)) {
    /*                           ^           */

      *iv_return = HTTP_KEEPALIVE_ON;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "HTTP_URI_TOO_LONG", 17)) {
    /*                           ^           */

      *iv_return = HTTP_URI_TOO_LONG;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_HOLD_NEW_JOBS", 17)) {
    /*                           ^           */

      *iv_return = IPP_HOLD_NEW_JOBS;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_18 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_DELETE_DEVICE HTTP_AUTH_MD5_SESS HTTP_ENCODE_LENGTH
     HTTP_ENCRYPT_NEVER HTTP_FIELD_REFERER HTTP_FIELD_UNKNOWN
     HTTP_FIELD_UPGRADE HTTP_KEEPALIVE_OFF HTTP_NOT_SUPPORTED
     HTTP_RESET_CONTENT IPP_ENABLE_PRINTER IPP_JOB_PROCESSING
     IPP_NOT_AUTHORIZED IPP_QUALITY_NORMAL IPP_RESUME_PRINTER
     IPP_TAG_DELETEATTR IPP_TAG_MEMBERNAME IPP_TAG_RESOLUTION */
  /* Offset 11 gives the best switch position.  */
  switch (name[11]) {
  case 'B':
    if (memEQ(name, "IPP_TAG_MEMBERNAME", 18)) {
    /*                          ^             */

      *iv_return = IPP_TAG_MEMBERNAME;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "HTTP_RESET_CONTENT", 18)) {
    /*                          ^             */

      *iv_return = HTTP_RESET_CONTENT;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_JOB_PROCESSING", 18)) {
    /*                          ^             */

      *iv_return = IPP_JOB_PROCESSING;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "HTTP_AUTH_MD5_SESS", 18)) {
    /*                          ^             */

      *iv_return = HTTP_AUTH_MD5_SESS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "IPP_TAG_DELETEATTR", 18)) {
    /*                          ^             */

      *iv_return = IPP_TAG_DELETEATTR;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_NOT_AUTHORIZED", 18)) {
    /*                          ^             */

      *iv_return = IPP_NOT_AUTHORIZED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "HTTP_KEEPALIVE_OFF", 18)) {
    /*                          ^             */

      *iv_return = HTTP_KEEPALIVE_OFF;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "IPP_TAG_RESOLUTION", 18)) {
    /*                          ^             */

      *iv_return = IPP_TAG_RESOLUTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "HTTP_NOT_SUPPORTED", 18)) {
    /*                          ^             */

      *iv_return = HTTP_NOT_SUPPORTED;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_ENABLE_PRINTER", 18)) {
    /*                          ^             */

      *iv_return = IPP_ENABLE_PRINTER;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_RESUME_PRINTER", 18)) {
    /*                          ^             */

      *iv_return = IPP_RESUME_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "HTTP_FIELD_REFERER", 18)) {
    /*                          ^             */

      *iv_return = HTTP_FIELD_REFERER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "HTTP_ENCRYPT_NEVER", 18)) {
    /*                          ^             */

      *iv_return = HTTP_ENCRYPT_NEVER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "HTTP_FIELD_UNKNOWN", 18)) {
    /*                          ^             */

      *iv_return = HTTP_FIELD_UNKNOWN;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_FIELD_UPGRADE", 18)) {
    /*                          ^             */

      *iv_return = HTTP_FIELD_UPGRADE;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "CUPS_DELETE_DEVICE", 18)) {
    /*                          ^             */

      *iv_return = CUPS_DELETE_DEVICE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_ENCODE_LENGTH", 18)) {
    /*                          ^             */

      *iv_return = HTTP_ENCODE_LENGTH;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_QUALITY_NORMAL", 18)) {
    /*                          ^             */

      *iv_return = IPP_QUALITY_NORMAL;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_19 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     CUPS_DELETE_PRINTER HTTP_ENCODE_CHUNKED HTTP_ENCRYPT_ALWAYS
     HTTP_FIELD_LOCATION HTTP_NOT_ACCEPTABLE IPP_DISABLE_PRINTER
     IPP_FINISHINGS_BALE IPP_FINISHINGS_BIND IPP_FINISHINGS_FOLD
     IPP_FINISHINGS_NONE IPP_FINISHINGS_TRIM IPP_PRINTER_STOPPED
     IPP_RESTART_PRINTER IPP_STARTUP_PRINTER IPP_TAG_ADMINDEFINE
     IPP_TAG_NOTSETTABLE */
  /* Offset 8 gives the best switch position.  */
  switch (name[8]) {
  case 'A':
    if (memEQ(name, "IPP_RESTART_PRINTER", 19)) {
    /*                       ^                 */

      *iv_return = IPP_RESTART_PRINTER;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_TAG_ADMINDEFINE", 19)) {
    /*                       ^                 */

      *iv_return = IPP_TAG_ADMINDEFINE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'B':
    if (memEQ(name, "IPP_DISABLE_PRINTER", 19)) {
    /*                       ^                 */

      *iv_return = IPP_DISABLE_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "CUPS_DELETE_PRINTER", 19)) {
    /*                       ^                 */

      *iv_return = CUPS_DELETE_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "HTTP_FIELD_LOCATION", 19)) {
    /*                       ^                 */

      *iv_return = HTTP_FIELD_LOCATION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "IPP_TAG_NOTSETTABLE", 19)) {
    /*                       ^                 */

      *iv_return = IPP_TAG_NOTSETTABLE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "HTTP_ENCODE_CHUNKED", 19)) {
    /*                       ^                 */

      *iv_return = HTTP_ENCODE_CHUNKED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "HTTP_ENCRYPT_ALWAYS", 19)) {
    /*                       ^                 */

      *iv_return = HTTP_ENCRYPT_ALWAYS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "IPP_FINISHINGS_BALE", 19)) {
    /*                       ^                 */

      *iv_return = IPP_FINISHINGS_BALE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_BIND", 19)) {
    /*                       ^                 */

      *iv_return = IPP_FINISHINGS_BIND;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_FOLD", 19)) {
    /*                       ^                 */

      *iv_return = IPP_FINISHINGS_FOLD;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_NONE", 19)) {
    /*                       ^                 */

      *iv_return = IPP_FINISHINGS_NONE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_TRIM", 19)) {
    /*                       ^                 */

      *iv_return = IPP_FINISHINGS_TRIM;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_PRINTER_STOPPED", 19)) {
    /*                       ^                 */

      *iv_return = IPP_PRINTER_STOPPED;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_STARTUP_PRINTER", 19)) {
    /*                       ^                 */

      *iv_return = IPP_STARTUP_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "HTTP_NOT_ACCEPTABLE", 19)) {
    /*                       ^                 */

      *iv_return = HTTP_NOT_ACCEPTABLE;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_20 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_GATEWAY_TIMEOUT HTTP_LENGTH_REQUIRED HTTP_NOT_IMPLEMENTED
     HTTP_PARTIAL_CONTENT HTTP_REQUEST_TIMEOUT IPP_ACTIVATE_PRINTER
     IPP_FINISHINGS_COVER IPP_FINISHINGS_PUNCH IPP_REVERSE_PORTRAIT
     IPP_SHUTDOWN_PRINTER IPP_TAG_SUBSCRIPTION */
  /* Offset 5 gives the best switch position.  */
  switch (name[5]) {
  case 'A':
    if (memEQ(name, "IPP_TAG_SUBSCRIPTION", 20)) {
    /*                    ^                     */

      *iv_return = IPP_TAG_SUBSCRIPTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "IPP_ACTIVATE_PRINTER", 20)) {
    /*                    ^                     */

      *iv_return = IPP_ACTIVATE_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "IPP_REVERSE_PORTRAIT", 20)) {
    /*                    ^                     */

      *iv_return = IPP_REVERSE_PORTRAIT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'G':
    if (memEQ(name, "HTTP_GATEWAY_TIMEOUT", 20)) {
    /*                    ^                     */

      *iv_return = HTTP_GATEWAY_TIMEOUT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_SHUTDOWN_PRINTER", 20)) {
    /*                    ^                     */

      *iv_return = IPP_SHUTDOWN_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_FINISHINGS_COVER", 20)) {
    /*                    ^                     */

      *iv_return = IPP_FINISHINGS_COVER;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_PUNCH", 20)) {
    /*                    ^                     */

      *iv_return = IPP_FINISHINGS_PUNCH;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "HTTP_LENGTH_REQUIRED", 20)) {
    /*                    ^                     */

      *iv_return = HTTP_LENGTH_REQUIRED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "HTTP_NOT_IMPLEMENTED", 20)) {
    /*                    ^                     */

      *iv_return = HTTP_NOT_IMPLEMENTED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "HTTP_PARTIAL_CONTENT", 20)) {
    /*                    ^                     */

      *iv_return = HTTP_PARTIAL_CONTENT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "HTTP_REQUEST_TIMEOUT", 20)) {
    /*                    ^                     */

      *iv_return = HTTP_REQUEST_TIMEOUT;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_21 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_ENCRYPT_REQUIRED HTTP_FIELD_CONNECTION HTTP_FIELD_KEEP_ALIVE
     HTTP_FIELD_USER_AGENT HTTP_MULTIPLE_CHOICES HTTP_PAYMENT_REQUIRED
     HTTP_UPGRADE_REQUIRED IPP_FINISHINGS_STAPLE IPP_GET_NOTIFICATIONS
     IPP_GET_SUBSCRIPTIONS IPP_NOT_AUTHENTICATED IPP_REVERSE_LANDSCAPE */
  /* Offset 11 gives the best switch position.  */
  switch (name[11]) {
  case 'C':
    if (memEQ(name, "HTTP_FIELD_CONNECTION", 21)) {
    /*                          ^                */

      *iv_return = HTTP_FIELD_CONNECTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_UPGRADE_REQUIRED", 21)) {
    /*                          ^                */

      *iv_return = HTTP_UPGRADE_REQUIRED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_NOT_AUTHENTICATED", 21)) {
    /*                          ^                */

      *iv_return = IPP_NOT_AUTHENTICATED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_GET_NOTIFICATIONS", 21)) {
    /*                          ^                */

      *iv_return = IPP_GET_NOTIFICATIONS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'K':
    if (memEQ(name, "HTTP_FIELD_KEEP_ALIVE", 21)) {
    /*                          ^                */

      *iv_return = HTTP_FIELD_KEEP_ALIVE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "HTTP_MULTIPLE_CHOICES", 21)) {
    /*                          ^                */

      *iv_return = HTTP_MULTIPLE_CHOICES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE", 21)) {
    /*                          ^                */

      *iv_return = IPP_FINISHINGS_STAPLE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "IPP_GET_SUBSCRIPTIONS", 21)) {
    /*                          ^                */

      *iv_return = IPP_GET_SUBSCRIPTIONS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "HTTP_ENCRYPT_REQUIRED", 21)) {
    /*                          ^                */

      *iv_return = HTTP_ENCRYPT_REQUIRED;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_PAYMENT_REQUIRED", 21)) {
    /*                          ^                */

      *iv_return = HTTP_PAYMENT_REQUIRED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "HTTP_FIELD_USER_AGENT", 21)) {
    /*                          ^                */

      *iv_return = HTTP_FIELD_USER_AGENT;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "IPP_REVERSE_LANDSCAPE", 21)) {
    /*                          ^                */

      *iv_return = IPP_REVERSE_LANDSCAPE;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_22 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_AUTH_MD5_SESS_INT HTTP_FIELD_CONTENT_MD5 HTTP_FIELD_RETRY_AFTER
     HTTP_MOVED_PERMANENTLY HTTP_MOVED_TEMPORARILY HTTP_NOT_AUTHORITATIVE
     HTTP_REQUEST_TOO_LARGE IPP_CANCEL_CURRENT_JOB IPP_DEACTIVATE_PRINTER
     IPP_GET_JOB_ATTRIBUTES IPP_OK_TOO_MANY_EVENTS IPP_PRINTER_PROCESSING
     IPP_RENEW_SUBSCRIPTION IPP_SCHEDULE_JOB_AFTER IPP_SEND_NOTIFICATIONS
     IPP_SET_JOB_ATTRIBUTES IPP_TAG_END_COLLECTION */
  /* Offset 12 gives the best switch position.  */
  switch (name[12]) {
  case '5':
    if (memEQ(name, "HTTP_AUTH_MD5_SESS_INT", 22)) {
    /*                           ^                */

      *iv_return = HTTP_AUTH_MD5_SESS_INT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'A':
    if (memEQ(name, "IPP_GET_JOB_ATTRIBUTES", 22)) {
    /*                           ^                */

      *iv_return = IPP_GET_JOB_ATTRIBUTES;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_OK_TOO_MANY_EVENTS", 22)) {
    /*                           ^                */

      *iv_return = IPP_OK_TOO_MANY_EVENTS;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_SET_JOB_ATTRIBUTES", 22)) {
    /*                           ^                */

      *iv_return = IPP_SET_JOB_ATTRIBUTES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'B':
    if (memEQ(name, "IPP_RENEW_SUBSCRIPTION", 22)) {
    /*                           ^                */

      *iv_return = IPP_RENEW_SUBSCRIPTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "IPP_TAG_END_COLLECTION", 22)) {
    /*                           ^                */

      *iv_return = IPP_TAG_END_COLLECTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_FIELD_RETRY_AFTER", 22)) {
    /*                           ^                */

      *iv_return = HTTP_FIELD_RETRY_AFTER;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_MOVED_PERMANENTLY", 22)) {
    /*                           ^                */

      *iv_return = HTTP_MOVED_PERMANENTLY;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_MOVED_TEMPORARILY", 22)) {
    /*                           ^                */

      *iv_return = HTTP_MOVED_TEMPORARILY;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "HTTP_NOT_AUTHORITATIVE", 22)) {
    /*                           ^                */

      *iv_return = HTTP_NOT_AUTHORITATIVE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_SEND_NOTIFICATIONS", 22)) {
    /*                           ^                */

      *iv_return = IPP_SEND_NOTIFICATIONS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "HTTP_FIELD_CONTENT_MD5", 22)) {
    /*                           ^                */

      *iv_return = HTTP_FIELD_CONTENT_MD5;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "IPP_PRINTER_PROCESSING", 22)) {
    /*                           ^                */

      *iv_return = IPP_PRINTER_PROCESSING;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_DEACTIVATE_PRINTER", 22)) {
    /*                           ^                */

      *iv_return = IPP_DEACTIVATE_PRINTER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "IPP_CANCEL_CURRENT_JOB", 22)) {
    /*                           ^                */

      *iv_return = IPP_CANCEL_CURRENT_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "HTTP_REQUEST_TOO_LARGE", 22)) {
    /*                           ^                */

      *iv_return = HTTP_REQUEST_TOO_LARGE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_SCHEDULE_JOB_AFTER", 22)) {
    /*                           ^                */

      *iv_return = IPP_SCHEDULE_JOB_AFTER;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_23 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_FIELD_CONTENT_TYPE HTTP_METHOD_NOT_ALLOWED IPP_CANCEL_SUBSCRIPTION
     IPP_FINISHINGS_BIND_TOP IPP_SUSPEND_CURRENT_JOB */
  /* Offset 9 gives the best switch position.  */
  switch (name[9]) {
  case 'D':
    if (memEQ(name, "HTTP_FIELD_CONTENT_TYPE", 23)) {
    /*                        ^                    */

      *iv_return = HTTP_FIELD_CONTENT_TYPE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_FINISHINGS_BIND_TOP", 23)) {
    /*                        ^                    */

      *iv_return = IPP_FINISHINGS_BIND_TOP;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "IPP_CANCEL_SUBSCRIPTION", 23)) {
    /*                        ^                    */

      *iv_return = IPP_CANCEL_SUBSCRIPTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "IPP_SUSPEND_CURRENT_JOB", 23)) {
    /*                        ^                    */

      *iv_return = IPP_SUSPEND_CURRENT_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "HTTP_METHOD_NOT_ALLOWED", 23)) {
    /*                        ^                    */

      *iv_return = HTTP_METHOD_NOT_ALLOWED;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_24 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_FIELD_ACCEPT_RANGES HTTP_FIELD_AUTHORIZATION HTTP_FIELD_CONTENT_RANGE
     HTTP_FIELD_LAST_MODIFIED HTTP_SERVICE_UNAVAILABLE HTTP_SWITCHING_PROTOCOLS
     IPP_FINISHINGS_BIND_LEFT IPP_TAG_BEGIN_COLLECTION */
  /* Offset 16 gives the best switch position.  */
  switch (name[16]) {
  case 'I':
    if (memEQ(name, "IPP_FINISHINGS_BIND_LEFT", 24)) {
    /*                               ^              */

      *iv_return = IPP_FINISHINGS_BIND_LEFT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "IPP_TAG_BEGIN_COLLECTION", 24)) {
    /*                               ^              */

      *iv_return = IPP_TAG_BEGIN_COLLECTION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'M':
    if (memEQ(name, "HTTP_FIELD_LAST_MODIFIED", 24)) {
    /*                               ^              */

      *iv_return = HTTP_FIELD_LAST_MODIFIED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "HTTP_FIELD_CONTENT_RANGE", 24)) {
    /*                               ^              */

      *iv_return = HTTP_FIELD_CONTENT_RANGE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "HTTP_FIELD_AUTHORIZATION", 24)) {
    /*                               ^              */

      *iv_return = HTTP_FIELD_AUTHORIZATION;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "HTTP_SWITCHING_PROTOCOLS", 24)) {
    /*                               ^              */

      *iv_return = HTTP_SWITCHING_PROTOCOLS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "HTTP_FIELD_ACCEPT_RANGES", 24)) {
    /*                               ^              */

      *iv_return = HTTP_FIELD_ACCEPT_RANGES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'V':
    if (memEQ(name, "HTTP_SERVICE_UNAVAILABLE", 24)) {
    /*                               ^              */

      *iv_return = HTTP_SERVICE_UNAVAILABLE;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_25 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_ENCRYPT_IF_REQUESTED HTTP_FIELD_CONTENT_LENGTH
     HTTP_PROXY_AUTHENTICATION IPP_FINISHINGS_BIND_RIGHT
     IPP_FINISHINGS_JOB_OFFSET IPP_RELEASE_HELD_NEW_JOBS
     IPP_TAG_UNSUPPORTED_GROUP IPP_TAG_UNSUPPORTED_VALUE */
  /* Offset 21 gives the best switch position.  */
  switch (name[21]) {
  case 'A':
    if (memEQ(name, "IPP_TAG_UNSUPPORTED_VALUE", 25)) {
    /*                                    ^          */

      *iv_return = IPP_TAG_UNSUPPORTED_VALUE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'F':
    if (memEQ(name, "IPP_FINISHINGS_JOB_OFFSET", 25)) {
    /*                                    ^          */

      *iv_return = IPP_FINISHINGS_JOB_OFFSET;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_FINISHINGS_BIND_RIGHT", 25)) {
    /*                                    ^          */

      *iv_return = IPP_FINISHINGS_BIND_RIGHT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'J':
    if (memEQ(name, "IPP_RELEASE_HELD_NEW_JOBS", 25)) {
    /*                                    ^          */

      *iv_return = IPP_RELEASE_HELD_NEW_JOBS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'N':
    if (memEQ(name, "HTTP_FIELD_CONTENT_LENGTH", 25)) {
    /*                                    ^          */

      *iv_return = HTTP_FIELD_CONTENT_LENGTH;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "IPP_TAG_UNSUPPORTED_GROUP", 25)) {
    /*                                    ^          */

      *iv_return = IPP_TAG_UNSUPPORTED_GROUP;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "HTTP_ENCRYPT_IF_REQUESTED", 25)) {
    /*                                    ^          */

      *iv_return = HTTP_ENCRYPT_IF_REQUESTED;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "HTTP_PROXY_AUTHENTICATION", 25)) {
    /*                                    ^          */

      *iv_return = HTTP_PROXY_AUTHENTICATION;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_26 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_FIELD_ACCEPT_LANGUAGE HTTP_FIELD_CONTENT_VERSION
     HTTP_UNSUPPORTED_MEDIATYPE IPP_FINISHINGS_BIND_BOTTOM
     IPP_FINISHINGS_EDGE_STITCH IPP_GET_PRINTER_ATTRIBUTES
     IPP_REDIRECTION_OTHER_SITE IPP_SET_PRINTER_ATTRIBUTES
     IPP_TAG_EVENT_NOTIFICATION */
  /* Offset 18 gives the best switch position.  */
  switch (name[18]) {
  case 'D':
    if (memEQ(name, "IPP_FINISHINGS_BIND_BOTTOM", 26)) {
    /*                                 ^              */

      *iv_return = IPP_FINISHINGS_BIND_BOTTOM;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_UNSUPPORTED_MEDIATYPE", 26)) {
    /*                                 ^              */

      *iv_return = HTTP_UNSUPPORTED_MEDIATYPE;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_EDGE_STITCH", 26)) {
    /*                                 ^              */

      *iv_return = IPP_FINISHINGS_EDGE_STITCH;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'F':
    if (memEQ(name, "IPP_TAG_EVENT_NOTIFICATION", 26)) {
    /*                                 ^              */

      *iv_return = IPP_TAG_EVENT_NOTIFICATION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_REDIRECTION_OTHER_SITE", 26)) {
    /*                                 ^              */

      *iv_return = IPP_REDIRECTION_OTHER_SITE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'L':
    if (memEQ(name, "HTTP_FIELD_ACCEPT_LANGUAGE", 26)) {
    /*                                 ^              */

      *iv_return = HTTP_FIELD_ACCEPT_LANGUAGE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_GET_PRINTER_ATTRIBUTES", 26)) {
    /*                                 ^              */

      *iv_return = IPP_GET_PRINTER_ATTRIBUTES;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_SET_PRINTER_ATTRIBUTES", 26)) {
    /*                                 ^              */

      *iv_return = IPP_SET_PRINTER_ATTRIBUTES;
      return PERL_constant_ISIV;

      

    }
    break;
  case '_':
    if (memEQ(name, "HTTP_FIELD_CONTENT_VERSION", 26)) {
    /*                                 ^              */

      *iv_return = HTTP_FIELD_CONTENT_VERSION;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_27 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_FIELD_CONTENT_ENCODING HTTP_FIELD_CONTENT_LANGUAGE
     HTTP_FIELD_CONTENT_LOCATION HTTP_FIELD_WWW_AUTHENTICATE
     IPP_CREATE_JOB_SUBSCRIPTION IPP_GET_PRINT_SUPPORT_FILES */
  /* Offset 22 gives the best switch position.  */
  switch (name[22]) {
  case 'A':
    if (memEQ(name, "HTTP_FIELD_CONTENT_LOCATION", 27)) {
    /*                                     ^           */

      *iv_return = HTTP_FIELD_CONTENT_LOCATION;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'F':
    if (memEQ(name, "IPP_GET_PRINT_SUPPORT_FILES", 27)) {
    /*                                     ^           */

      *iv_return = IPP_GET_PRINT_SUPPORT_FILES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'G':
    if (memEQ(name, "HTTP_FIELD_CONTENT_LANGUAGE", 27)) {
    /*                                     ^           */

      *iv_return = HTTP_FIELD_CONTENT_LANGUAGE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "HTTP_FIELD_WWW_AUTHENTICATE", 27)) {
    /*                                     ^           */

      *iv_return = HTTP_FIELD_WWW_AUTHENTICATE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "HTTP_FIELD_CONTENT_ENCODING", 27)) {
    /*                                     ^           */

      *iv_return = HTTP_FIELD_CONTENT_ENCODING;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'P':
    if (memEQ(name, "IPP_CREATE_JOB_SUBSCRIPTION", 27)) {
    /*                                     ^           */

      *iv_return = IPP_CREATE_JOB_SUBSCRIPTION;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_28 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_FIELD_IF_MODIFIED_SINCE HTTP_FIELD_TRANSFER_ENCODING
     IPP_FINISHINGS_BOOKLET_MAKER IPP_FINISHINGS_SADDLE_STITCH
     IPP_OK_IGNORED_NOTIFICATIONS IPP_OK_IGNORED_SUBSCRIPTIONS */
  /* Offset 18 gives the best switch position.  */
  switch (name[18]) {
  case 'D':
    if (memEQ(name, "IPP_FINISHINGS_SADDLE_STITCH", 28)) {
    /*                                 ^                */

      *iv_return = IPP_FINISHINGS_SADDLE_STITCH;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'F':
    if (memEQ(name, "HTTP_FIELD_IF_MODIFIED_SINCE", 28)) {
    /*                                 ^                */

      *iv_return = HTTP_FIELD_IF_MODIFIED_SINCE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_OK_IGNORED_NOTIFICATIONS", 28)) {
    /*                                 ^                */

      *iv_return = IPP_OK_IGNORED_NOTIFICATIONS;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'K':
    if (memEQ(name, "IPP_FINISHINGS_BOOKLET_MAKER", 28)) {
    /*                                 ^                */

      *iv_return = IPP_FINISHINGS_BOOKLET_MAKER;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'R':
    if (memEQ(name, "HTTP_FIELD_TRANSFER_ENCODING", 28)) {
    /*                                 ^                */

      *iv_return = HTTP_FIELD_TRANSFER_ENCODING;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'S':
    if (memEQ(name, "IPP_OK_IGNORED_SUBSCRIPTIONS", 28)) {
    /*                                 ^                */

      *iv_return = IPP_OK_IGNORED_SUBSCRIPTIONS;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_30 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     HTTP_FIELD_IF_UNMODIFIED_SINCE IPP_FINISHINGS_EDGE_STITCH_TOP
     IPP_FINISHINGS_STAPLE_DUAL_TOP IPP_FINISHINGS_STAPLE_TOP_LEFT */
  /* Offset 22 gives the best switch position.  */
  switch (name[22]) {
  case 'D':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_DUAL_TOP", 30)) {
    /*                                     ^              */

      *iv_return = IPP_FINISHINGS_STAPLE_DUAL_TOP;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'E':
    if (memEQ(name, "HTTP_FIELD_IF_UNMODIFIED_SINCE", 30)) {
    /*                                     ^              */

      *iv_return = HTTP_FIELD_IF_UNMODIFIED_SINCE;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'I':
    if (memEQ(name, "IPP_FINISHINGS_EDGE_STITCH_TOP", 30)) {
    /*                                     ^              */

      *iv_return = IPP_FINISHINGS_EDGE_STITCH_TOP;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_TOP_LEFT", 30)) {
    /*                                     ^              */

      *iv_return = IPP_FINISHINGS_STAPLE_TOP_LEFT;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_31 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     IPP_CREATE_PRINTER_SUBSCRIPTION IPP_FINISHINGS_EDGE_STITCH_LEFT
     IPP_FINISHINGS_STAPLE_DUAL_LEFT IPP_FINISHINGS_STAPLE_TOP_RIGHT
     IPP_GET_SUBSCRIPTION_ATTRIBUTES */
  /* Offset 29 gives the best switch position.  */
  switch (name[29]) {
  case 'E':
    if (memEQ(name, "IPP_GET_SUBSCRIPTION_ATTRIBUTES", 31)) {
    /*                                            ^        */

      *iv_return = IPP_GET_SUBSCRIPTION_ATTRIBUTES;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'F':
    if (memEQ(name, "IPP_FINISHINGS_EDGE_STITCH_LEFT", 31)) {
    /*                                            ^        */

      *iv_return = IPP_FINISHINGS_EDGE_STITCH_LEFT;
      return PERL_constant_ISIV;

      

    }
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_DUAL_LEFT", 31)) {
    /*                                            ^        */

      *iv_return = IPP_FINISHINGS_STAPLE_DUAL_LEFT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'H':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_TOP_RIGHT", 31)) {
    /*                                            ^        */

      *iv_return = IPP_FINISHINGS_STAPLE_TOP_RIGHT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'O':
    if (memEQ(name, "IPP_CREATE_PRINTER_SUBSCRIPTION", 31)) {
    /*                                            ^        */

      *iv_return = IPP_CREATE_PRINTER_SUBSCRIPTION;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_32 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     IPP_FINISHINGS_EDGE_STITCH_RIGHT IPP_FINISHINGS_STAPLE_DUAL_RIGHT
     IPP_GET_PRINTER_SUPPORTED_VALUES */
  /* Offset 24 gives the best switch position.  */
  switch (name[24]) {
  case 'A':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_DUAL_RIGHT", 32)) {
    /*                                       ^              */

      *iv_return = IPP_FINISHINGS_STAPLE_DUAL_RIGHT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'C':
    if (memEQ(name, "IPP_FINISHINGS_EDGE_STITCH_RIGHT", 32)) {
    /*                                       ^              */

      *iv_return = IPP_FINISHINGS_EDGE_STITCH_RIGHT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'D':
    if (memEQ(name, "IPP_GET_PRINTER_SUPPORTED_VALUES", 32)) {
    /*                                       ^              */

      *iv_return = IPP_GET_PRINTER_SUPPORTED_VALUES;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant_33 (pTHX_ const char *name, IV *iv_return) {
  /* When generated this function returned values for the list of names given
     here.  However, subsequent manual editing may have added or removed some.
     IPP_FINISHINGS_EDGE_STITCH_BOTTOM IPP_FINISHINGS_STAPLE_BOTTOM_LEFT
     IPP_FINISHINGS_STAPLE_DUAL_BOTTOM */
  /* Offset 23 gives the best switch position.  */
  switch (name[23]) {
  case 'O':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_BOTTOM_LEFT", 33)) {
    /*                                      ^                */

      *iv_return = IPP_FINISHINGS_STAPLE_BOTTOM_LEFT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'T':
    if (memEQ(name, "IPP_FINISHINGS_EDGE_STITCH_BOTTOM", 33)) {
    /*                                      ^                */

      *iv_return = IPP_FINISHINGS_EDGE_STITCH_BOTTOM;
      return PERL_constant_ISIV;

      

    }
    break;
  case 'U':
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_DUAL_BOTTOM", 33)) {
    /*                                      ^                */

      *iv_return = IPP_FINISHINGS_STAPLE_DUAL_BOTTOM;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

static int
constant (pTHX_ const char *name, STRLEN len, IV *iv_return) {
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
my @names = (qw(CUPS_ACCEPT_JOBS CUPS_ADD_CLASS CUPS_ADD_DEVICE
	       CUPS_ADD_PRINTER CUPS_DELETE_CLASS CUPS_DELETE_DEVICE
	       CUPS_DELETE_PRINTER CUPS_GET_CLASSES CUPS_GET_DEFAULT
	       CUPS_GET_DEVICES CUPS_GET_PPDS CUPS_GET_PRINTERS CUPS_MOVE_JOB
	       CUPS_REJECT_JOBS CUPS_SET_DEFAULT HTTP_0_9 HTTP_1_0 HTTP_1_1
	       HTTP_ACCEPTED HTTP_AUTH_BASIC HTTP_AUTH_MD5 HTTP_AUTH_MD5_INT
	       HTTP_AUTH_MD5_SESS HTTP_AUTH_MD5_SESS_INT HTTP_AUTH_NONE
	       HTTP_BAD_GATEWAY HTTP_BAD_REQUEST HTTP_CLOSE HTTP_CONFLICT
	       HTTP_CONTINUE HTTP_CREATED HTTP_DELETE HTTP_ENCODE_CHUNKED
	       HTTP_ENCODE_LENGTH HTTP_ENCRYPT_ALWAYS HTTP_ENCRYPT_IF_REQUESTED
	       HTTP_ENCRYPT_NEVER HTTP_ENCRYPT_REQUIRED HTTP_ERROR
	       HTTP_FIELD_ACCEPT_LANGUAGE HTTP_FIELD_ACCEPT_RANGES
	       HTTP_FIELD_AUTHORIZATION HTTP_FIELD_CONNECTION
	       HTTP_FIELD_CONTENT_ENCODING HTTP_FIELD_CONTENT_LANGUAGE
	       HTTP_FIELD_CONTENT_LENGTH HTTP_FIELD_CONTENT_LOCATION
	       HTTP_FIELD_CONTENT_MD5 HTTP_FIELD_CONTENT_RANGE
	       HTTP_FIELD_CONTENT_TYPE HTTP_FIELD_CONTENT_VERSION
	       HTTP_FIELD_DATE HTTP_FIELD_HOST HTTP_FIELD_IF_MODIFIED_SINCE
	       HTTP_FIELD_IF_UNMODIFIED_SINCE HTTP_FIELD_KEEP_ALIVE
	       HTTP_FIELD_LAST_MODIFIED HTTP_FIELD_LINK HTTP_FIELD_LOCATION
	       HTTP_FIELD_MAX HTTP_FIELD_RANGE HTTP_FIELD_REFERER
	       HTTP_FIELD_RETRY_AFTER HTTP_FIELD_TRANSFER_ENCODING
	       HTTP_FIELD_UNKNOWN HTTP_FIELD_UPGRADE HTTP_FIELD_USER_AGENT
	       HTTP_FIELD_WWW_AUTHENTICATE HTTP_FORBIDDEN HTTP_GATEWAY_TIMEOUT
	       HTTP_GET HTTP_GET_SEND HTTP_GONE HTTP_HEAD HTTP_KEEPALIVE_OFF
	       HTTP_KEEPALIVE_ON HTTP_LENGTH_REQUIRED HTTP_MAX_BUFFER
	       HTTP_MAX_HOST HTTP_MAX_URI HTTP_MAX_VALUE
	       HTTP_METHOD_NOT_ALLOWED HTTP_MOVED_PERMANENTLY
	       HTTP_MOVED_TEMPORARILY HTTP_MULTIPLE_CHOICES HTTP_NOT_ACCEPTABLE
	       HTTP_NOT_AUTHORITATIVE HTTP_NOT_FOUND HTTP_NOT_IMPLEMENTED
	       HTTP_NOT_MODIFIED HTTP_NOT_SUPPORTED HTTP_NO_CONTENT HTTP_OK
	       HTTP_OPTIONS HTTP_PARTIAL_CONTENT HTTP_PAYMENT_REQUIRED
	       HTTP_POST HTTP_POST_RECV HTTP_POST_SEND HTTP_PRECONDITION
	       HTTP_PROXY_AUTHENTICATION HTTP_PUT HTTP_PUT_RECV
	       HTTP_REQUEST_TIMEOUT HTTP_REQUEST_TOO_LARGE HTTP_RESET_CONTENT
	       HTTP_SEE_OTHER HTTP_SERVER_ERROR HTTP_SERVICE_UNAVAILABLE
	       HTTP_STATUS HTTP_SWITCHING_PROTOCOLS HTTP_TRACE
	       HTTP_UNAUTHORIZED HTTP_UNSUPPORTED_MEDIATYPE
	       HTTP_UPGRADE_REQUIRED HTTP_URI_TOO_LONG HTTP_USE_PROXY
	       HTTP_WAITING IPP_ACTIVATE_PRINTER IPP_ATTRIBUTE IPP_BAD_REQUEST
	       IPP_CANCEL_CURRENT_JOB IPP_CANCEL_JOB IPP_CANCEL_SUBSCRIPTION
	       IPP_CREATE_JOB IPP_CREATE_JOB_SUBSCRIPTION
	       IPP_CREATE_PRINTER_SUBSCRIPTION IPP_DATA IPP_DEACTIVATE_PRINTER
	       IPP_DISABLE_PRINTER IPP_ENABLE_PRINTER IPP_ERROR
	       IPP_FINISHINGS_BALE IPP_FINISHINGS_BIND
	       IPP_FINISHINGS_BIND_BOTTOM IPP_FINISHINGS_BIND_LEFT
	       IPP_FINISHINGS_BIND_RIGHT IPP_FINISHINGS_BIND_TOP
	       IPP_FINISHINGS_BOOKLET_MAKER IPP_FINISHINGS_COVER
	       IPP_FINISHINGS_EDGE_STITCH IPP_FINISHINGS_EDGE_STITCH_BOTTOM
	       IPP_FINISHINGS_EDGE_STITCH_LEFT IPP_FINISHINGS_EDGE_STITCH_RIGHT
	       IPP_FINISHINGS_EDGE_STITCH_TOP IPP_FINISHINGS_FOLD
	       IPP_FINISHINGS_JOB_OFFSET IPP_FINISHINGS_NONE
	       IPP_FINISHINGS_PUNCH IPP_FINISHINGS_SADDLE_STITCH
	       IPP_FINISHINGS_STAPLE IPP_FINISHINGS_STAPLE_BOTTOM_LEFT
	       IPP_FINISHINGS_STAPLE_BOTTOM_RIGHT
	       IPP_FINISHINGS_STAPLE_DUAL_BOTTOM
	       IPP_FINISHINGS_STAPLE_DUAL_LEFT IPP_FINISHINGS_STAPLE_DUAL_RIGHT
	       IPP_FINISHINGS_STAPLE_DUAL_TOP IPP_FINISHINGS_STAPLE_TOP_LEFT
	       IPP_FINISHINGS_STAPLE_TOP_RIGHT IPP_FINISHINGS_TRIM
	       IPP_FORBIDDEN IPP_GET_JOBS IPP_GET_JOB_ATTRIBUTES
	       IPP_GET_NOTIFICATIONS IPP_GET_PRINTER_ATTRIBUTES
	       IPP_GET_PRINTER_SUPPORTED_VALUES IPP_GET_PRINT_SUPPORT_FILES
	       IPP_GET_SUBSCRIPTIONS IPP_GET_SUBSCRIPTION_ATTRIBUTES IPP_HEADER
	       IPP_HOLD_JOB IPP_HOLD_NEW_JOBS IPP_IDLE IPP_JOB_ABORTED
	       IPP_JOB_CANCELLED IPP_JOB_COMPLETED IPP_JOB_HELD IPP_JOB_PENDING
	       IPP_JOB_PROCESSING IPP_JOB_STOPPED IPP_LANDSCAPE IPP_MAX_NAME
	       IPP_MAX_VALUES IPP_NOT_AUTHENTICATED IPP_NOT_AUTHORIZED
	       IPP_NOT_POSSIBLE IPP_OK IPP_OK_CONFLICT
	       IPP_OK_IGNORED_NOTIFICATIONS IPP_OK_IGNORED_SUBSCRIPTIONS
	       IPP_OK_SUBST IPP_OK_TOO_MANY_EVENTS IPP_PAUSE_PRINTER
	       IPP_PAUSE_PRINTER_AFTER_CURRENT_JOB IPP_PORT IPP_PORTRAIT
	       IPP_PRINTER_IDLE IPP_PRINTER_PROCESSING IPP_PRINTER_STOPPED
	       IPP_PRINT_JOB IPP_PRINT_URI IPP_PRIVATE IPP_PROMOTE_JOB
	       IPP_PURGE_JOBS IPP_QUALITY_DRAFT IPP_QUALITY_HIGH
	       IPP_QUALITY_NORMAL IPP_REDIRECTION_OTHER_SITE
	       IPP_RELEASE_HELD_NEW_JOBS IPP_RELEASE_JOB IPP_RENEW_SUBSCRIPTION
	       IPP_REPROCESS_JOB IPP_RESTART_JOB IPP_RESTART_PRINTER
	       IPP_RESUME_JOB IPP_RESUME_PRINTER IPP_RES_PER_CM
	       IPP_RES_PER_INCH IPP_REVERSE_LANDSCAPE IPP_REVERSE_PORTRAIT
	       IPP_SCHEDULE_JOB_AFTER IPP_SEND_DOCUMENT IPP_SEND_NOTIFICATIONS
	       IPP_SEND_URI IPP_SET_JOB_ATTRIBUTES IPP_SET_PRINTER_ATTRIBUTES
	       IPP_SHUTDOWN_PRINTER IPP_STARTUP_PRINTER IPP_SUSPEND_CURRENT_JOB
	       IPP_TAG_ADMINDEFINE IPP_TAG_BEGIN_COLLECTION IPP_TAG_BOOLEAN
	       IPP_TAG_CHARSET IPP_TAG_COPY IPP_TAG_DATE IPP_TAG_DEFAULT
	       IPP_TAG_DELETEATTR IPP_TAG_END IPP_TAG_END_COLLECTION
	       IPP_TAG_ENUM IPP_TAG_EVENT_NOTIFICATION IPP_TAG_INTEGER
	       IPP_TAG_JOB IPP_TAG_KEYWORD IPP_TAG_LANGUAGE IPP_TAG_MASK
	       IPP_TAG_MEMBERNAME IPP_TAG_MIMETYPE IPP_TAG_NAME
	       IPP_TAG_NAMELANG IPP_TAG_NOTSETTABLE IPP_TAG_NOVALUE
	       IPP_TAG_OPERATION IPP_TAG_PRINTER IPP_TAG_RANGE
	       IPP_TAG_RESOLUTION IPP_TAG_STRING IPP_TAG_SUBSCRIPTION
	       IPP_TAG_TEXT IPP_TAG_TEXTLANG IPP_TAG_UNKNOWN
	       IPP_TAG_UNSUPPORTED_GROUP IPP_TAG_UNSUPPORTED_VALUE IPP_TAG_URI
	       IPP_TAG_URISCHEME IPP_TAG_ZERO IPP_VALIDATE_JOB));

print constant_types(); # macro defs
foreach (C_constant ("Net::CUPS::Network", 'constant', 'IV', $types, undef, 3, @names) ) {
    print $_, "\n"; # C constant subs
}
print "#### XS Section:\n";
print XS_constant ("Net::CUPS::Network", $types);
__END__
   */

  switch (len) {
  case 6:
    if (memEQ(name, "IPP_OK", 6)) {

      *iv_return = IPP_OK;
      return PERL_constant_ISIV;

      

    }
    break;
  case 7:
    if (memEQ(name, "HTTP_OK", 7)) {

      *iv_return = HTTP_OK;
      return PERL_constant_ISIV;

      

    }
    break;
  case 8:
    return constant_8 (aTHX_ name, iv_return);
    break;
  case 9:
    return constant_9 (aTHX_ name, iv_return);
    break;
  case 10:
    return constant_10 (aTHX_ name, iv_return);
    break;
  case 11:
    return constant_11 (aTHX_ name, iv_return);
    break;
  case 12:
    return constant_12 (aTHX_ name, iv_return);
    break;
  case 13:
    return constant_13 (aTHX_ name, iv_return);
    break;
  case 14:
    return constant_14 (aTHX_ name, iv_return);
    break;
  case 15:
    return constant_15 (aTHX_ name, iv_return);
    break;
  case 16:
    return constant_16 (aTHX_ name, iv_return);
    break;
  case 17:
    return constant_17 (aTHX_ name, iv_return);
    break;
  case 18:
    return constant_18 (aTHX_ name, iv_return);
    break;
  case 19:
    return constant_19 (aTHX_ name, iv_return);
    break;
  case 20:
    return constant_20 (aTHX_ name, iv_return);
    break;
  case 21:
    return constant_21 (aTHX_ name, iv_return);
    break;
  case 22:
    return constant_22 (aTHX_ name, iv_return);
    break;
  case 23:
    return constant_23 (aTHX_ name, iv_return);
    break;
  case 24:
    return constant_24 (aTHX_ name, iv_return);
    break;
  case 25:
    return constant_25 (aTHX_ name, iv_return);
    break;
  case 26:
    return constant_26 (aTHX_ name, iv_return);
    break;
  case 27:
    return constant_27 (aTHX_ name, iv_return);
    break;
  case 28:
    return constant_28 (aTHX_ name, iv_return);
    break;
  case 30:
    return constant_30 (aTHX_ name, iv_return);
    break;
  case 31:
    return constant_31 (aTHX_ name, iv_return);
    break;
  case 32:
    return constant_32 (aTHX_ name, iv_return);
    break;
  case 33:
    return constant_33 (aTHX_ name, iv_return);
    break;
  case 34:
    if (memEQ(name, "IPP_FINISHINGS_STAPLE_BOTTOM_RIGHT", 34)) {

      *iv_return = IPP_FINISHINGS_STAPLE_BOTTOM_RIGHT;
      return PERL_constant_ISIV;

      

    }
    break;
  case 35:
    if (memEQ(name, "IPP_PAUSE_PRINTER_AFTER_CURRENT_JOB", 35)) {

      *iv_return = IPP_PAUSE_PRINTER_AFTER_CURRENT_JOB;
      return PERL_constant_ISIV;

      

    }
    break;
  }
  return PERL_constant_NOTFOUND;
}
