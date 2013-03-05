#!/usr/bin/perl 
#---
# Excerpted from "HTML5 and CSS3",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
#---
use strict;
use warnings;

sub say {
    my $w = shift;
    print $w;
    print "\n";
}

sub dump {
   my $i = shift;
   &say(sprintf("Sbox[%d] = _Sbox[%d]", $i, $i));
   &say(sprintf("InvSbox[%d] = _InvSbox[%d]", $i, $i));
   &say(sprintf("Xtime2Sbox[%d] = _Xtime2Sbox[%d]", $i, $i));
   &say(sprintf("Xtime3Sbox[%d] = _Xtime3Sbox[%d]", $i, $i));
   &say(sprintf("Xtime2[%d] = _Xtime2[%d]", $i, $i));
   &say(sprintf("Xtime9[%d] = _Xtime9[%d]", $i, $i));
   &say(sprintf("XtimeB[%d] = _XtimeB[%d]", $i, $i));
   &say(sprintf("XtimeD[%d] = _XtimeD[%d]", $i, $i));
   &say(sprintf("XtimeE[%d] = _XtimeE[%d]", $i, $i));
}

for (my $i=0;$i<256;$i++) {
    &dump($i);
}



