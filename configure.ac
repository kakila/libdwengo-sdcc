### Copyright (C) 2012 Juan Pablo Carbajal
###
### This file is part of Dwengo.
###
### Octave is free software; you can redistribute it and/or modify it
### under the terms of the GNU General Public License as published by the
### Free Software Foundation; either version 3 of the License, or (at
### your option) any later version.
###
### Octave is distributed in the hope that it will be useful, but WITHOUT
### ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
### FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
### for more details.
###
### You should have received a copy of the GNU General Public License
### along with Octave; see the file COPYING.  If not, see
### <http://www.gnu.org/licenses/>.

AC_PREREQ([2.65])

AC_INIT([libdwengo], [1.0.0], [info@dwengo.org],, [www.dwengo.org])
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([lib/dwengoBoard.c])
AC_CONFIG_HEADERS([config.h])

#AC_CONFIG_MACRO_DIR([m4])
#LT_PREREQ([2.2.2])
#LT_INIT([disable-shared])

#AC_CONFIG_LIBOBJ_DIR([lib])

#AC_CONFIG_FILES([examples/common.mk:examples/common.mk \
#examples/Makefile.proj:examples/Makefile.proj])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

### Configure variables: SDCC_BIN, SDCC_INCLUDE, SDCC_LIBS and PK2_BIN
AC_ARG_VAR([SDCC_BIN], [Path to sdcc compiler.])
AC_ARG_VAR([SDAR_BIN], [Path to sdar linker.])
AC_ARG_VAR([SDCC_INCLUDE], [The PATH wherein p18f4550.h can be found.])
AC_ARG_VAR([SDCC_LIBS], [Path to libsdcc.lib.])
AC_ARG_VAR([PK2_BIN], [The PATH wherein pk2cmd can be found.])

# Ensure that both or neither are specified (for compilation).
#if (test -n "$SDCC_BIN" && test -z "$SDCC_INCLUDE") || \
#   (test -n "$SDCC_INCLUDE" && test -z "$SDCC_BIN"); then
#  AC_MSG_ERROR([Specify both sdcc and include paths, or neither.])
#fi

## Find sdcc program from environment variable or by searching
#AC_CHECK_LIB(libsdcc.lib, XX)
##Search for location of libsdcc.lib
#if test ; then
#  true
#  # TODO: Search for libsdcc.lib
#  SDCC_LIBS = 
#fi
#AC_CHECK_LIB(${SDCC_LIBS}/libsdcc.lib, XX)

## Find sdcc program from environment variable or by searching
AC_CHECK_PROG([SDCC_C], sdcc, sdcc, [])
#Search for location of sdcc
if test -z "$SDCC_C"; then
  true
  # TODO: Search for sdcc components
fi
#AC_CHECK_PROG([SDCC_C], [sdcc], [${SDCC_BIN}/sdcc],[],[${SDCC_BIN}])

#### Check version number of sdcc
SDCC_VERSION=
sdd_version=
if test "$SDCC_C"; then

  sdcc_version=`$SDCC_C -v 2>&1 | sed -n -e '1 s/^.*\([[0-9]]\.[[0-9]]\.[[0-9]]\).*$/\1/p'`

  AS_VERSION_COMPARE([$sdcc_version], [3.4.0],
    [AC_MSG_ERROR([sdcc version $sdcc_version will probably fail to compile libdwengo])])

  SDCC_VERSION=$sdcc_version
else
  AC_MSG_WARN([SDCC not defined. Make sure that variable SDCC_BIN is correct.])
fi
AC_SUBST(SDCC_VERSION)

## Find sdar program from environment variable or by searching
AC_CHECK_PROG([SDAR_L], sdar, sdar, [])
#Search for location of sdar
if test -z "$SDAR_L"; then
  true
  # TODO: Search for sdar components
fi
#AC_CHECK_PROG([SDAR_L], [sdar], [${SDAR_BIN}/sdar],[],[${SDAR_BIN}])

# Ensure that path to pk2cmd is given or given a warning (for programming).
if (test -z "$PK2_BIN"); then
  AC_MSG_WARN([Path to PK2CMD not defined. Define PK2_BIN or "make program" wont work.])
fi

#Search for location of pk2cmd
if test -z "$PK2_BIN"; then
  true
  # TODO: Search for pk2cmd
fi

AC_ARG_VAR([SDCCFLAGS], [The FLAGS for sdcc.])
if test -z "$SDCCFLAGS"; then
  AC_SUBST([SDCCFLAGS],["-mpic16 -p18f4550 --use-non-free --optimize-cmp --optimize-df -lm"])
fi

AC_ARG_VAR([SDCCLINKFLAGS], [The FLAGS for sdcc when linking.])
if test -z "$SDCCLINKFLAGS"; then
  if test "$SDCC_LIBS"; then
    AC_SUBST([SDCCLINKFLAGS],["-L $SDCC_LIBS"])
  fi
fi

# Checks for programs.
AC_PROG_INSTALL

#AC_CHECK_PROG([PK2], [pk2cmd], [${PK2_BIN}/pk2cmd],[no],[${PK2_BIN}])
#### Check version number of mplib.
#PK2_VERSION=
#FRM_VERSION="not found"
#if test "$PK2" != no; then
#  pk2_exec_version=`$PK2 -?V 2>&1 | grep "^Exec" | \
#    sed -e 's/^Executable Version:    //' -e 's/.00$//'`;
#  pk2_firm_version=`$PK2 -?V 2>&1 | grep "^OS" | \
#    sed -e 's/^OS Firmware Version:  //' -e 's/.00$//'`;

#  echo $PK2
#  AS_VERSION_COMPARE([$pk2_exec_version], [1.20],
#    [AC_MSG_ERROR([pk2cmd version $pk2_exec_version will probably fail to program the the dwengo board])])

#  PK2_VERSION=$pk2_exec_version
#  FRM_VERSION=$pk2_firm_version
#fi
#AC_SUBST(MCCL_VERSION)

# Define library construction
AC_CONFIG_FILES([Makefile lib/Makefile share/Makefile])

AC_OUTPUT

echo \
"-------------------------------------------------
 ${PACKAGE_NAME} Version ${PACKAGE_VERSION}
 Prefix........: $prefix
 Include folder: $SDCC_INCLUDE

 Compiler........: $SDCC_C
 Librarian........: $SDAR_L
 Version: $SDCC_VERSION

 Compiler flags..: $SDCCFLAGS

 Device database version: $DEVDB_VERSION

 Programmer tool             : $PK2
 Programmer tool version     : $PK2_VERSION
 Programmer firmware version : $FRM_VERSION

 Now type 'make @<:@<target>@:>@'
   where the optional <target> is:
     all                - build all binaries
     install            - install everything
--------------------------------------------------"
