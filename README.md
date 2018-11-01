# CUnit integration for CMake

This is a simple little project attempts to make writing unit tests in C with
[CUnit](http://cunit.sourceforge.net/) as easy as writing unit tests in C
with [Criterion](https://github.com/Snaipe/Criterion). The benefit of using
CUnit over Criterion is that tests can be run on embedded targets.

CMake is used to preprocess the every source file specified when defining a
new test executable. It searches through the files looking for the signatures:
`CU_Init`, `CU_Clean`, `CU_Test` and `CU_Theory`. When any of those
signatures is found the necessary actions are taken. When all files have been
scanned, a runner is generated that can be used to execute the tests.

A little demo is included. To build it, run the following commands.

```
cd cmake-cunit
mkdir build
cd build
cmake ..
./demo
```

