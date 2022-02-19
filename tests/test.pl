#!/usr/bin/perl

use strict;
use FindBin;
use File::Basename;

# Using ANSI color code to replace Term::ANSIColor.
sub colored {
  (my $string, my $color) = (@_[0], @_[1]);

  (my $color_ansi, my $no_color) = ("", "\033[0m");

  if ($color eq "red") {
    $color_ansi = "\033[91m";
  }

  elsif ($color eq "green") {
    $color_ansi = "\033[92m";
  }

  elsif ($color eq "yellow") {
    $color_ansi = "\033[93m";
  }

  elsif ($color eq "blue") {
    $color_ansi = "\033[96m";
  }

  else {
    $color_ansi = $no_color;
  }

  $string = $color_ansi . $string . $no_color;

  return $string;
}

# Counting files inside a directoryi (exclude . and ..)
# Stolen from https://www.perlmonks.org/?node_id=606767
sub count_files {
  my $dir = @_[0];

  opendir D, $dir or die $!;

  return scalar grep { ! m{^\.\.?$} } readdir D;
}

# Get a file content
sub get_file_content {
  my $file = @_[0];

  open my $fh, "<", $file or die "Cannot open file $file: $!";

  read $fh, my $file_content, -s $fh;

  close $fh;

  return $file_content;
}

# Execute a payload, and return stdout.
sub execute_payload {
  my $payload_file = @_[0];

  my $payload_content = get_file_content "$payload_file";

  my $runtime_output = qx{$payload_content};

  return $runtime_output;
}

# print success progressbar
sub print_success_progress {
  (my $current, my $total, my $print_progress) = (@_[0], @_[1], @_[2]);

  # Progress bar
  if ($print_progress) {
    my $current_progress = colored("✔" x $current, "green");
    my $remain_progress = "." x ($total - $current - 1);

    print "\rTesting: ", "$current_progress", "$remain_progress";
  }
}

# Print failed progressbar & stats
sub print_failed_progress {
  (my $current, my $total) = (@_[0], @_[1]);
  (my $result, my $expected) = (@_[2], @_[3]);
  (my $input_file, my $print_progress) = (@_[4], @_[5]);

  my $payload = get_file_content "$input_file";

  # Progress bar
  if ($print_progress) {
    my $current_progress = colored("✔" x ($current - 1), "green");
    my $error_progress = colored("✘", "red");
    my $remain_progress = "." x ($total - $current - 2);

    print "\rTesting: ", "$current_progress", "$error_progress", "$remain_progress";
  }

  # Failed info
  print colored("\n✘ Testcase \"$input_file\" failed:\n", "red");
  print colored("Payload:\n", "blue");
  print colored("$payload\n", "yellow");
  print colored("Expected output:\n", "blue");
  print "$expected\n";
  print colored("Runtime:\n", "blue");
  print "$result\n";
}

# Running testcases.
sub try {
  my $input_dir = @_[0];
  my $output_dir = @_[1];
  my $print_progress = @_[2];

  my $total_tests = count_files($input_dir);

  # Report error if there are not enough input / output files.
  if ($total_tests != count_files($output_dir)) {
    print colored("✘ Error: Input file and Output file quantity are not the same!", "red"), "\n";

    return 1;
  }

  # Read input dir and get file list.
  opendir my $INDIR, $input_dir or die "Cannot open $input_dir";

  my @input_files = readdir($INDIR);

  my $index = 0;

  foreach my $input_file (@input_files) {
    unless ($input_file eq "." || $input_file eq "..") {
      # Getting output file.
      my $output_file = basename($input_file);

      $output_file =~ s/.inp/.out/g;

      $output_file = "$output_dir/$output_file";

      # Adding correct path to input file.
      $input_file = "$input_dir/$input_file";

      # Testing if expected_output match runtime.
      my $expected_output = get_file_content "$output_file";

      my $runtime_output = execute_payload "$input_file";

      if ($runtime_output eq $expected_output) {
        print_success_progress ++$index, $total_tests, $print_progress;
      }

      else {
        print_failed_progress ++$index, $total_tests, $runtime_output, $expected_output, $input_file, $print_progress;

        return 1;
      }
    }
  }

  close $INDIR;

  print colored("\n✔ All testcases passed", "green"), " ($total_tests / $total_tests)\n";

  return 0;
}

sub main {
  my $print_progress = ($ARGV[0] eq "--silent") ? 0 : 1;

  my $input = "$FindBin::Bin/input";
  my $output = "$FindBin::Bin/output";

  return try $input, $output, $print_progress;
}

exit(main);
