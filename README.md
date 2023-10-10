# Rust DLL Process Attach Debug testbed

This repository contains 2 projects. A very simple Rust project building a dynamic library that export a function called `get_number()`, that returns 42 as an `i32` (`int`). And a simple C++ project building an executable that dynamically load that DLL and call said function.

This is intended as being a test bed to figure out how to breakpoint, and inspect the memory inside a dynamic library authored in Rust, and being loaded by a random process (On Windows, at least)
