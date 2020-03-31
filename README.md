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

## NOTES
* **OS X Users** I've heard of some issues compiling if you've installed 
command line tools, then XCode.app afterwards on Catalina (with bash). When compiling with 
```clang++```, the C++ header files aren't found. If you have this issue, exporting an environment
variable, such as this, 
```export CXX=/usr/bin/clang++```, seems to be a workaround. If anybody has a better
solution (aside from wiping out all build tools and reinstalling) please let
me know. 
* **OS X Users** If you have this message when compiling on OS X (likely Catalina and later),
```bash
mc_lexer.yy.cc:675:8: error: member reference type 'std::istream *' (aka 'basic_istream<char> *') is a
      pointer; did you mean to use '->'?
```
Then this means that you've a broken cpp path. To see why this is, go to the command line, type
```bash
cpp -xc++ -v < /dev/null
```
to see your path included by clang. The key problem is the lack of a modern FlexLexer.h in the 
command line tools of OS X, which is compouned when you install a new verson of Flex and the 
header isn't in the path. So, your binary will be the right one, the headers the wrong ones. 
As an example, the header file we want on my install of OS X (fresh VM install), is in 
```
/System/Volumes/Data/usr/local/Cellar/flex/2.6.4_1/include/FlexLexer.h
```
which is installed by _home brew_. Unfortunately, the default include path pulls in the system
default version at 
```
/System/Volumes/Data/Library/Developer/CommandLineTools/usr/include/FlexLexer.h
```
**HOW TO FIX**

    1.  Interestingly there's yet another version in ```/Library/Developer```. So how do you fix? 
    The simplest way if you have sudo access, do:
    ```
    sudo -s 
    ln -s <Path to your installed Flex Header>/FlexLexer.h
    ```
    As an example, here's my path:  
    ```
    ln -s /System/Volumes/Data/usr/local/Cellar/flex/2.6.4_1/include/FlexLexer.h
    ```
    2. Second, **best** way for non-root is to set the _CPLUS\_INCLUDE\_PATH_ like this
    ```
    CPLUS_INCLUDE_PATH=/System/Volumes/Data/usr/local/Cellar/flex/2.6.4_1/include/:$CPLUS_INCLUDE_PATH
    ```
    using my path above. 

* **Bison Version** - updated the latest head to test with Bison vs. 3.5, there were a few minor 
changes in syntax, now reflected in the example code. Will no longer work with Bison vs. < 3.3, 
see notes from [link](https://lwn.net/Articles/777594/).


Thanks!
