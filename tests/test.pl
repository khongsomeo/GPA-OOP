#!/usr/bin/perl

use strict;
use warnings;
use FindBin;

# UDF
use lib qq($FindBin::Bin/modules);
use try;

sub main {
  my $print_progress = (!$ARGV[0] || ($ARGV[0] ne qq(--silent))) ? 1 : 0;

  my $input = qq($FindBin::Bin/input);
  my $output = qq($FindBin::Bin/output);

  return try::run($input, $output, $print_progress);
}

exit(main);
