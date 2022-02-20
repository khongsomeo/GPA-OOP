#!/usr/bin/perl

use strict;
use warnings;

use FindBin;

use lib "$FindBin::Bin/";
use utils;

package progress;

# print success progressbar
sub print_success_progress {
  (my $current, my $total, my $print_progress) = ($_[0], $_[1], $_[2]);

  # Progress bar
  if ($print_progress) {
    my $current_progress = utils::colored("✔" x $current, "green");
    
    my $remain_progress = "." x ($total - $current);

    print "\rTesting: ", "$current_progress", "$remain_progress";
  }
}

# Print failed progressbar & stats
sub print_failed_progress {
  (my $current, my $total) = ($_[0], $_[1]);
  (my $result, my $expected) = ($_[2], $_[3]);
  (my $input_file, my $print_progress) = ($_[4], $_[5]);

  my $payload = utils::get_file_content($input_file);

  # Progress bar
  if ($print_progress) {
    my $current_progress = utils::colored("✔" x ($current - 1), "green");
    my $error_progress = utils::colored("✘", "red");
    my $remain_progress = "." x ($total - $current - 2);

    print "\rTesting: ", "$current_progress", "$error_progress", "$remain_progress";
  }

  # Failed info
  print utils::colored("\n✘ Testcase \"$input_file\" failed:\n", "red");
  print utils::colored("Payload:\n", "blue");
  print utils::colored("$payload\n", "yellow");
  print utils::colored("Expected output:\n", "blue");
  print "$expected\n";
  print utils::colored("Runtime:\n", "blue");
  print "$result\n";
}

1;
