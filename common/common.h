/*
 *  Net::CUPS Common Data Conversion Routines
 *
 *  Author: D. Hageman <dhageman@dracken.com>
 *
 *  Copyright 2003-2004 Dracken Technologies.
 *
 * CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro 
 * are the trademark property of Easy Software Products.
 *
 */


/* Structures found in cups.h */
void XS_pack_cups_option_tPtr( SV* s, cups_option_t* option );
cups_option_t* XS_unpack_cups_option_tPtr( SV* rv );
void XS_pack_cups_dest_tPtr( SV* s, cups_dest_t* dest );
cups_dest_t* XS_unpack_cups_dest_tPtr( SV* rv );
void XS_pack_cups_job_tPtr( SV* s, cups_job_t* job );
cups_job_t* XS_unpack_cups_job_tPtr( SV* rv );

/* Structures found in ipp.h */
void XS_pack_ipp_tPtr( SV* s, ipp_t* ipp );
ipp_t* XS_unpack_ipp_tPtr( SV* rv );

void XS_pack_ppd_attr_tPtr( SV* s, ppd_attr_t* attr );
void XS_pack_ppd_choice_tPtr( SV* s, ppd_choice_t* choice );
void XS_pack_ppd_const_tPtr( SV* s, ppd_const_t* constraint );
void XS_pack_ppd_emul_tPtr( SV* s, ppd_emul_t* emul );
void XS_pack_ppd_option_tPtr( SV* s, ppd_option_t* option );
void XS_pack_ppd_group_tPtr( SV* s, ppd_group_t* group );
void XS_pack_ppd_size_tPtr( SV* s, ppd_size_t* size );
void XS_pack_ppd_profile_tPtr( SV* s, ppd_profile_t* profile );
void XS_pack_ppd_file_tPtr( SV* s, ppd_file_t* file );

ppd_attr_t* XS_unpack_ppd_attr_tPtr( SV* rv );
ppd_choice_t* XS_unpack_ppd_choice_tPtr( SV* rv );
ppd_const_t* XS_unpack_ppd_const_tPtr( SV* rv );
ppd_emul_t* XS_unpack_ppd_emul_tPtr( SV* rv );
ppd_option_t* XS_unpack_ppd_option_tPtr( SV* rv );
ppd_group_t* XS_unpack_ppd_group_tPtr( SV* rv );
ppd_size_t* XS_unpack_ppd_size_tPtr( SV* rv );
ppd_file_t* XS_unpack_ppd_file_tPtr( SV* rv );
