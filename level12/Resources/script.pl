#!/usr/bin/env perl

sub t {
  $nn = $_[1];

  $xx = $_[0];
  print($xx);
  print("\n");

  $xx =~ tr/a-z/A-Z/;
  print($xx);
  print("\n");

  $xx =~ s/\s.*//;
  print($xx);
  print("\n");
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  print(`echo egrep "^$xx" /tmp/xd`);
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t($ARGV[0], $ARGV[1]));
