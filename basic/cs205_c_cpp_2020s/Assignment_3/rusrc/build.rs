use std::{env, fs};
use std::path::Path;
use std::path::PathBuf;
use std::process::Command;

fn main() {
    cc::Build::new()
        .cpp(true) // Switch to C++ library compilation.
        .file("lib/utf8.cpp")
        .compile("ass3_utf8lib_utf8");
    println!("cargo:rerun‐if‐changed=lib/utf8.cpp");
}