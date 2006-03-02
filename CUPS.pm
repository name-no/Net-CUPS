package Net::CUPS;

##==================================================================##
##  Libraries and Variables                                         ##
##==================================================================##

require 5.006;
require Exporter::Cluster;

use strict;
use warnings;

our $VERSION = "0.41";

our @ISA = qw( Exporter::Cluster );

our %EXPORT_CLUSTER = (
	'Net::CUPS::Protocol'	=>	[],
	'Net::CUPS::PPD'		=>	[],
	'Net::CUPS::Printer'	=>	[],
);

##==================================================================##
##  Function(s)                                                     ##
##==================================================================##

##
##  None.
##

##==================================================================##
##  End of Code                                                     ##
##==================================================================##
1;

##==================================================================##
##  Plain Old Documentation (POD)                                   ##
##==================================================================##

__END__

=head1 NAME

Net::CUPS - CUPS C API Interface.

=head1 ABSTRACT

 use Net::CUPS;

=head1 DESCRIPTION

Net::CUPS is an interface to the Common Unix Printing System API.

=head1 FUNCTIONS

This module does not contain any functions.  All of the functions are 
contained within the modules listed in the SEE ALSO section of this
document.

=head1 SUPPORT

This module is offered without any support.  If you have any questions
on how to use this module then you should start by reading the 
"CUPS Software Programmers Manual".  This module is for the most
part a Perl implementation of C API.  If you can use the C API
then you can use this module.  If you find a bug or get stuck feel
free to e-mail, but don't expect an immediate response.  I apologize
for taking this attitude, but several people have e-mailed me in the
past and were quite abbrasive with their correspondence.

=head1 AUTHOR

D. Hageman E<lt>dhageman@dracken.comE<gt>

=head1 SEE ALSO

L<Net::CUPS::Printer>, L<Net::CUPS::PPD>, L<Net::CUPS::IPP>, 
L<Net::CUPS::Protocol>

=head1 COPYRIGHT

Copyright (c) 2003-2005 D. Hageman 

Copyright (c) 2006 Dracken Technology, Inc.

All rights reserved.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
