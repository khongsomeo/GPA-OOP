#!/usr/bin/perl

use strict;
use warnings;

use FindBin;
use File::Basename;

use lib "$FindBin::Bin/";
use progress;
use utils;

package try;

# Running testcases.
sub run {
  my $input_dir = $_[0];
  my $output_dir = $_[1];
  my $print_progress = $_[2];

  my $total_tests = utils::count_files($input_dir);

  # Report error if there are not enough input / output files.
  if ($total_tests != utils::count_files($output_dir)) {
    print utils::colored("✘ Error: Input file and Output file quantity are not the same!", "red"), "\n";

    return 1;
  }

  # Read input dir and get file list.
  opendir my $INDIR, $input_dir or die "Cannot open $input_dir";

  my @input_files = readdir($INDIR);

  my $index = 0;

  foreach my $input_file (@input_files) {
    unless ($input_file eq "." || $input_file eq "..") {
      # Getting output file.
      my $output_file = File::Basename::basename($input_file);

      $output_file =~ s/.inp/.out/g;

      $output_file = "$output_dir/$output_file";

      # Adding correct path to input file.
      $input_file = "$input_dir/$input_file";

      # Testing if expected_output match runtime.
      my $expected_output = utils::get_file_content($output_file);

      my $runtime_output = utils::execute_payload($input_file);

      if ($runtime_output eq $expected_output) {
        progress::print_success_progress(++$index, $total_tests, $print_progress);
      }

      else {
        progress::print_failed_progress(++$index, $total_tests, $runtime_output, $expected_output, $input_file, $print_progress);

        return 1;
      }
    }
  }

  close $INDIR;

  print utils::colored("\n✔ All testcases passed", "green"), " ($total_tests / $total_tests)\n";

  return 0;
}

1;
