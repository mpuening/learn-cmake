Learn CMake
===========

If you want to learn CMake, please check out the "Modern CMake for C++" book. It is
a great book that explains CMake from nothing and works its way up to building
a C++ project complete with unit testing, code coverage, code analysis, packaging and
installation. What is great is that the code in the book is simple and clean.
There are many examples on the internet that look dreadful compared to what you will
create because of what you learn from the book.

The code in this repository is contrived to allow me figure out how build a C++ project
that I can correlate to a Java project built using Maven. I want to build libraries
(sub-projects) with various dependencies between them, and dependencies to external
projects (e.g. Poco). So don't judge the code.

Overview
--------
This project is a dumb Poco command line application that uses a couple of libraries
as sub-projects. The application's sub-projects have various dependencies as a means
to test out how dependencies work. The `src/actuator` sub-project takes its name from Spring
Boot's actuator project and wraps the build info values. The `src/logger` sub-project
merely wraps the Poco logger. Again, don't judge the ridiculousness of this. The `src/app`
and `src/actuator` projects both depend on the `src/logger` project to verify that I
understand dependency management.

In the `cmake` directory, one will find a few CMake scripts. There is a `BuildInfo.cmake`
file to create a header file with a static struct containing the version, GitHub Commit
SHA and timestamp. The `Poco.cmake` script downloads and includes the Poco Framework in
this project. The script only enables the Foundation and Util libraries. All the other
libraries are disabled to speed up build times. The `Testing.cmake` script includes
Google Test framework for this project.

Install CMake
-------------

Using brew, execute this command:

```
brew install --cask cmake
```

Makefile Commands
-----------------
Using CMake is to understand the various ways to invoke the command and the various
parameters to pass into the command at each step. Rather than try to memorize those,
I encapsulated them into a simple `Makefile`.

The `make config` command invokes `cmake` to set up the `build` directory.

The `make build` command invokes `cmake` to build the binaries.

The `make test` command invokes `ctest` to run the test cases.

The `make clean` command invokes `cmake` to clean the build directory.

The `make realclean` command deletes the `build` directory.

Perhaps `make config build test` would be your first command. You will find the
Poco application at `build/bin/app/app`.

Useful Information
------------------

One aspect of CMake that seems to be difficult to understand is the difference
between PRIVATE, PUBLIC and INTERFACE for include directories. There are plenty
of sites on the internet that explain it. But for me, with regards to C++, private
include files are those used by a library and only that library. In other words,
consider an internal class; it is private and no one else should use it. Public 
include files are those expected to be used both by a library and external use of the 
library. Interface header files, or perhaps "API" header files are those that are
not required by the library, but define how external libraries or executables can
invoke functions in the library.

Eclipse IDE Support
-------------------

While some people may feel at home using a simple editor to write C++ code, I
wanted an IDE with support for intelli-sense and debugging. My "goto" IDE is
Eclipse, and fortunately, CMake has some support for generating an Eclipse project
for easy importing.

To build the Eclipse project, run the following command:

 ```
 make eclipse-setup
 ```

Now, be careful about that command. It creates a sub-directory at `eclipse/learn-cmake`
that contains the `.project` and `.settings` files. It is this directory that one will 
import into Eclipse. One does not import the root directory of this project.

To import to project into Eclipse:

* Select File > Import > C/C++ > Existing Code as C++ Makefile Project
* Select the `learn-cmake/eclipse/learn-cmake` directory as the existing code location
* Select `MacOSX GCC` as the Toolchain for Indexer Settings (if using a Mac)

To verify import, ensure these settings are made:

* Right click project > Properties > C/C++ Build > Tool Chain Build
* Select `MacOSX GCC` for the Current toolchain (if using a Mac)
* Select `GNU Make Builder` for the Current Builder

Once imported, one will find most of the code under the `[Targets]` sub-folders.
In my naming conventions of the CMake targets, libraries ending in `_src` have
the source files. One should see `Header Files` and `Source Files` for each library.
The libraries ending in `_lib` are the actual static libraries. For applications
(or executables), one will see an `[exe] app` sub-folder the the main program.
Test sub-folders should also be there having the test cases.

If for some reason, Eclipse does not understand the code, perhaps likely the Indexer
is not working correctly. One can correct this by doing this:

* Right click project > Index > Rebuild

To build the application:

* Right click project > Build Project

To run or debug the application, one needs to create a "Run Configuration" or
"Debug Configuration".

To configure a "Run Configuration" for the Poco app:

* Right click project > Run As > Run Configurations...
* right click C/C++ Application > New Configuration
* Enter `learn-cmake App` as the name of the configuration
* Browse to `eclipse/learn-cmake/bin/app/app` as the C/C++ Application
* Select Apply or Run to save

Once created, the configuration should display in icon menu for easy running.

To run test cases, one could also build a Run Configuration for each file. But
I have yet to find a solution to run all test cases together in Eclipse (`ctest`).

After one updates the CMake files, one can again run the `eclipse-setup` command
from the `Makefile`. Afterwards, just right click the project and select Refresh.
New changes should display, but to get the project working properly again, it may
require a project clean and the index rebuilt. Also check if the "C/C++ Build"
section in the project properties has disappeared. If so, delete the project and
re-import. I haven't figured out how to restore it after it disappears.

TODO
----
Use CMake Eclipse Plugin?

How to debug? Make sure `gdb` is installed on system.

Add support for pre-compiled headers
