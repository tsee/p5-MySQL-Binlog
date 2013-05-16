#!/usr/bin/perl -w
use strict;
use Module::Build::WithXSpp;

my $build = Module::Build::WithXSpp->new(
  module_name     => 'MySQL::Binlog',
  license         => 'perl',
  requires        => {
  },
  build_requires        => {
    'ExtUtils::ParseXS' => '3.18',
    'ExtUtils::XSpp' => '0.1604',
  },
  early_includes  => ['perl_myinit_early.h'],
  # Provides extra C typemaps for opaque objects:
  extra_typemap_modules => {
    'ExtUtils::Typemaps::Default' => '1.03',
  },
);

$build->create_build_script;
