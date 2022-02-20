#!/usr/bin/perl

use strict;
use warnings;
use FindBin;

# UDF
use lib "$FindBin::Bin/modules";
use try;

sub main {
  my $print_progress = (!$ARGV[0] || ($ARGV[0] ne "--silent")) ? 1 : 0;

  my $input = "$FindBin::Bin/input";
  my $output = "$FindBin::Bin/output";

  return try::run($input, $output, $print_progress);
}

exit(main);
