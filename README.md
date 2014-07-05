Dwengo library
==============
For more information visit the [Dwengo](ww.dwengo.org) homepage.

Requirements
------------
To use and compile the Dwengo library for your projects and to program your Dwengo board you need to have [SDCC](http://sdcc.sourceforge.net/) 3.4.0 (or newer) and pk2cmd.

If the `./configure` script fails, checl the definitions of the
following varibales :

* SDCC_BIN
The path wherein sdcc compiler can be found.

* SDAR_BIN
The path wherein sdar linker can be found.

* SDCC_INCLUDE
The path wherein p18f4550.h can be found.

* SDCC_LIBS
The path to libsdcc.lib.

* PK2_BIN
The PATH wherein pk2cmd can be found

You can do this before calling the configure script with commands like

        export SDCC_BIN=path/to/sdcc/folder
        export SDAR_BIN=path/to/sdar/folder
        export SDCC_INCLUDE=path/to/p18f4550/folder
        export PK2_BIN=path/to/pk2cmd/folder
        
By default the library is installed (with make install) to _/usr/local_
to change this destination use the `--prexif` option to `./configure`.

You can obtain more help running `./configure --help`. 

Compiling and Programming your projects
---------------------------------------
You will find the following three files in the folder ${prefix}/share/libdwengo

* common.mk :
Contains all the variables required to compile and program the board (this values are generated at configure time).
 
* Makefile.topprojdir : 
A file that can be placed in the folder containing all the project folders (common.mk should be placed there too) and renamed to Makefile

* Makefile.proj : 
A file that can be placed in the folder of **each** project and renamed to Makefile.

So a possible tree structure looks like

        projects/
        |-- common.mk
        |-- Makefile                 # This was Makefile.topprojdir
        |-- blinkingLEDS/
             |-- blinkingLEDS.c
             `-- Makefile                 # This was Makefile.proj
        |-- newsTicker/
             |-- newsTicker.c
             `-- Makefile                 # This was Makefile.proj
        |-- usartCounter/
             |-- usartCounter.c
             `-- Makefile                 # This was Makefile.proj
        |-- lightMeasurement/
             |-- lightMeasurement.c
             `-- Makefile                 # This was Makefile.proj
        |-- usartNewsticker/
             |-- usartNewsticker.c
             `-- Makefile                 # This was Makefile.proj
        `-- usartEcho/
             |-- usartEcho.c
             `-- Makefile                 # This was Makefile.proj
        
The files provide, at top level, the commands

        make   #defualts to make help
        make help
        make clean
        make all
        make PROJ=<dir> all   #(where <dir> is the folder name of one of the projects, explained in "make help")
        make PROJ=<dir> program
        
Inside each project folder they provide the same commands

        make   #defaults to make all
        make clean
        make all
        make program
        
Compiling out of source tree
----------------------------

If you are compiling dwengo.lib from source, you may want to compile it outside
of the foulder with the sources. Lets assume you have the sources at
_~/libdwengo-version_, to compile in a folder _~/libdwengo-build_ do the following

        cd ~/libdwengo-version
        ./bootstrap.sh
        cd ~/libdwengo-build
        < export the required varibles here >
        ~/libdwengo-version/configure
        make
        
This will make the library inside the folder _~/libdwengo-build_ and keep
_~/libdwengo-version_ clean.

Additionally, if you want to install to a local folder call the
configure script with the option `--prefix=path/to/install`
If you do so, running

    make install

will install the library at _path/to/install/lib/libdwengo_.

The header files will be in _path/to/install/include/libdwengo_
and the files that help you compile your projects and program the board will be
in _path/to/install/share/libdwengo_.
