#!/usr/bin/env perl
use strict;
use warnings;

system( "../my_wc wordlist.txt > temp.txt" );
my $diff = `diff temp.txt wordlist_out.txt`;
chomp( $diff );
if( $diff )
{
    print STDERR $diff;
    unlink( "temp.txt" );
    exit( -1 );
}
print STDERR "***PASSED***\n";
unlink( "temp.txt" );
exit( 0 );
