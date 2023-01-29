
https://pocoproject.org/download.html

build POCO (1.12.4)

The POCO C++ Libraries support CMake as a build system on Linux, macOS and Windows.
To build the POCO C++ Libraries with CMake:

1. create a cmake-build directory (e.g. in the POCO root directory):

$ mkdir cmake-build

2. and run CMake from there:

$ cd cmake-build
$ cmake ..
$ make -s -j (or build the generated Visual Studio solution on Windows)

Building on OS
============================

For building on Unix platforms, the POCO C++ Libraries come with their own
build system. The build system is based on GNU Make 5.0 (or newer), with the help
from a few shell scripts. If you do not have GNU Make 5.0 (or later) installed on
your machine, you will need to download it from
http://directory.fsf.org/devel/build/make.html>,
build and install it prior to building the POCO C++ Libraries.

You can check the version of GNU Make installed on your system with

> gmake --version

or

> make --version

Once you have GNU Make up and running, the rest is quite simple.
To extract the sources and build all libraries, testsuites and samples, simply

> gunzip poco-X.Y.tar.gz
> tar -xf poco-X.Y.tar
> cd poco-X.Y
> ./configure
> gmake -s

See the configure script source for a list of possible options.
For starters, we recommend --no-tests and --no-samples, to reduce build times.
On a multicore or multiprocessor machine, use parallel makes to speed up
the build (make -j4).

Once you have successfully built POCO, you can install it
to /usr/local (or another directory specified as parameter
to configure --prefix=<path>):

> sudo gmake -s install

You can omit certain components from the build. For example, you might
want to omit Data/ODBC or Data/MySQL if you do not have the corresponding
third-party libraries (iodbc or unixodbc, mysqlclient) installed
on your system. To do this, use the --omit argument to configure:

> ./configure --omit=Data/ODBC,Data/MySQL


IMPORTANT: Make sure that the path to the build directory does not
contain symbolic links. Furthermore, on macOS (or other systems
with case insensitive filesystems), make sure that the characters in
the path have the correct case. Otherwise you'll get an error saying
"Current working directory not under $PROJECT_BASE.".

Building the CODE
============================

```cmake
cmake_minimum_required(VERSION 3.25)
project(poc)
add_executable(poc client/src/http-get-method.cpp)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "PocoNet_DIR library path: ${PocoNet_DIR}")

find_package(Poco CONFIG REQUIRED Foundation Util Net)
find_package(PocoNet REQUIRED)

## link specific object files we need
target_link_libraries(poc PUBLIC Poco::Foundation)
target_link_libraries(poc PUBLIC Poco::Net Poco::Util Poco::JSON)


```