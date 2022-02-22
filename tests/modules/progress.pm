#!/usr/bin/perl

use strict;
use warnings;

use FindBin;

use lib qq($FindBin::Bin/);
use utils;

package progress;

# print success progressbar
sub print_success_progress {
  (my $current, my $total, my $print_progress) = ($_[0], $_[1], $_[2]);

  # Progress bar
  if ($print_progress) {
    my $current_progress = utils::colored(qq(✔) x $current, qq(green));
    
    my $remain_progress = qq(.) x ($total - $current);

    print(qq(\rTesting: ($current / $total) $current_progress), qq($remain_progress));
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
    my $current_progress = utils::colored(qq(✔) x ($current - 1), qq(green));
    my $error_progress = utils::colored(qq(✘), qq(red));
    my $remain_progress = qq(.) x ($total - $current - 2);

    print(qq(\rTesting: ($current / $total) $current_progress), qq($error_progress), qq($remain_progress));
  }

  # Failed info
  print(utils::colored(qq(\n✘ Testcase \"$input_file\" failed:\n), qq(red)));
  print(utils::colored(qq(Payload:\n), qq(blue)));
  print(utils::colored(qq($payload\n), qq(yellow)));
  print(utils::colored(qq(Expected output:\n), qq(blue)));
  print(qq($expected\n));
  print(utils::colored(qq(Runtime:\n), qq(blue)));
  print(qq($result\n));
}

1;
