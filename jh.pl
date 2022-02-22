#!/usr/bin/perl

use strict;
use warnings;

use FindBin;

sub main {
  for my $argv (@ARGV) {
    my $path = "$FindBin::Bin/$argv";

    print $path;

    # Check if directory exist
    if (-e $path && -d $path) {
      print " - Junk found\n";
      return 1;
    }

    print " - Junk not found\n";
  }

  return 0;
}

exit(main);
