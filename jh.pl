#!/usr/bin/perl

use strict;
use warnings;

use FindBin;

sub main {
  for my $argv (@ARGV) {
    my $path = qq($FindBin::Bin/$argv);

    # Check if directory exist
    if (-e $path && -d $path) {
      print(qq($path - Junk found\n));
      return 1;
    }

    print(qq($path - Junk not found\n));
  }

  return 0;
}

exit(main);
