### Simple Word Count Parser Example
=================

### Build Status
Tested on linux and OS X

[![Build Status](https://travis-ci.org/jonathan-beard/simple_wc_example.svg?branch=master)](https://travis-ci.org/jonathan-beard/simple_wc_example)

### About

So this is a super simple parser example. The tutorial is located here:
<a href="http://www.jonathanbeard.io/tutorials/FlexBisonC++.html" target="_blank">link</a>

Between the tutorial and the code you should be able to get started with more
advanced projects using C++ and Flex/Bison. Admittedly the example itself is a
bit contrived, however it's mean to be simple and get the point across. If
there are changes in Flex/Bison that prevent the example from compiling or if
you just have improvements, feel free to generate a pull request or just shoot
me an e-mail.

To compile just download and run make, there's a super simple test harness to
make sure it runs in the <tt>test</tt> dir.

Or you use CMake.

    mkdir build/
    cmake ..
    make

or with clang

    mkdir build/
    CC=clang CXX=clang++ cmake ..
    make

or with clang with optimisations

    mkdir build/
    CC=clang CXX=clang++ cmake .. -DCMAKE_BUILD_TYPE=Release
    make

To run the simple test after make call

    ctest

**NOTE FOR OS X USERS**: I've heard of some issues compiling if you've installed 
command line tools, then XCode.app afterwards on Catalina (with bash). When compiling with 
```clang++```, the C++ header files aren't found. If you have this issue, exporting an environment
variable, such as this, 
```export CXX=/usr/bin/clang++```, seems to be a workaround. If anybody has a better
solution (aside from wiping out all build tools and reinstalling) please let
me know. 


Thanks!
