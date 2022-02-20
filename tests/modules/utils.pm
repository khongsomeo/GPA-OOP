#!/usr/bin/perl

use strict;
use warnings;

package utils;

# Using ANSI color code to replace Term::ANSIColor.
sub colored {
  (my $string, my $color) = ($_[0], $_[1]);

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

# Counting files inside a directory (exclude . and ..)
# Stolen from https://www.perlmonks.org/?node_id=606767
sub count_files {
  my $dir = $_[0];

  opendir D, $dir or die $!;

  return scalar grep { ! m{^\.\.?$} } readdir D;
}

# Get a file content
sub get_file_content {
  my $file = $_[0];

  open my $fh, "<", $file or die "Cannot open file $file: $!";

  read $fh, my $file_content, -s $fh;

  close $fh;

  return $file_content;
}

# Execute a payload, and return stdout.
sub execute_payload {
  my $payload_file = $_[0];

  my $payload_content = get_file_content($payload_file);

  my $runtime_output = qx{$payload_content};

  return $runtime_output;
}

1;
