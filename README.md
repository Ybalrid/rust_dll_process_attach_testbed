# Rust DLL Process Attach Debug testbed

This repository contains 2 projects. A very simple Rust project building a dynamic library that export a function called `get_number()`, that returns 42 as an `i32` (`int`). And a simple C++ project building an executable that dynamically load that DLL and call said function.

This is intended as being a test bed to figure out how to breakpoint, and inspect the memory inside a dynamic library authored in Rust, and being loaded by a random process (On Windows, at least)

## What to do with this

1. Build both the Rust and C++ project. C++ one uses CMake.
1. Copy the MyRustDLL.dll (and eventually .pdb?) file in the directory where you will execute loadrustdll.exe from
1. Run loadrustdll.exe
1. *Attach a debugger to loadrustdll.exe*, set a breakpoint within `lib.rs` `get_number()`
1. Press the Return key in the console running `loadrustdll.exe`

The expected result is to get a debugger break inside the rust codem and to be able to examine variables successfully.