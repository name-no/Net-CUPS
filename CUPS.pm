package Net::CUPS;
######################################################################
##                                                                  ##
##  Package:  CUPS.pm                                               ##
##  Author:   D. Hageman <dhageman@eecs.ku.edu>                     ##
##                                                                  ##
##  Description:                                                    ##
##                                                                  ##
##  Perl interface to the Common Unix Printing System (CUPS) API.   ##
##                                                                  ##
######################################################################

##==================================================================##
##  Libraries and Variables                                         ##
##==================================================================##

require 5.006;
require Exporter::Cluster;

use strict;
use warnings;

our $VERSION = "0.20";

our @ISA = qw( Exporter::Cluster );

our %EXPORT_CLUSTER = (
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

=head1 SYNOPSIS

 use Net::CUPS;

=head1 ABSTRACT

 This is the abstract for this file.

=head1 FUNCTIONS

=over 4

=item None.

 None.

=back

=head1 DESCRIPTION

Net::CUPS is an interface to the Common Unix Printing System API.

=head1 AUTHOR

D. Hageman E<lt>dhageman@dracken.comE<gt>

=head1 SEE ALSO

L<Net::CUPS::Printer>, L<Net::CUPS::PPD>, L<Net::CUPS::IPP>

=head1 COPYRIGHT

Copyright (c) 2003.
D. Hageman (Dracken Technologies)
All rights reserved.

CUPS, the Common UNIX Printing System, the CUPS logo, and ESP Print Pro are the trademark property of Easy Software Products.

=cut
