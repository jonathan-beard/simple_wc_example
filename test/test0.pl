#!/usr/bin/env perl
use strict;
use warnings;

system( "${PWD}../my_wc wordlist.txt > ${PWD}/temp.txt" );
my $diff = `diff ${PWD}/temp.txt ${PWD}/wordlist_out.txt`;
chomp( $diff );
if( $diff )
{
    print STDERR $diff;
    unlink( "${PWD}/temp.txt" );
    exit( -1 );
}
print STDERR "PASSED!";
unlink( "${PWD}/temp.txt" );
exit( 0 );
