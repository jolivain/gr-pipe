#! /usr/bin/env perl

use warnings;
use strict;

my $buffer = '';

while ( read( STDIN, $buffer, 4 ) ) {
    my $val = unpack 'f', $buffer;
    # print STDERR "$val\n";
    $val *= $val;
    $buffer = pack 'f', $val;
    print STDOUT $buffer;
}

__END__
