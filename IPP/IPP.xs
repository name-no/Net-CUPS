#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <cups/ipp.h>
#include <cups/http.h>

#include "IPP_constant_c.inc"
#include "../common/common.c"

MODULE = Net::CUPS::IPP		PACKAGE = Net::CUPS::IPP		

PROTOTYPES: DISABLE

INCLUDE: IPP_constant_xs.inc
