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

libexec_PROGRAMS = libdwengo.lib

nobase_pkginclude_HEADERS = \
compiler.h \
dwengoADC.h \
dwengoBluetooth.h \
dwengoBoard.h \
dwengoClock.h \
dwengoConfig.h \
dwengoDelay.h \
dwengoI2C.h \
dwengoInterrupt.h \
dwengoLCD.h \
dwengoMotor.h \
dwengoNotes.h \
dwengoRC.h \
dwengoSensorModule.h \
dwengoServo.h \
dwengoSound.h \
dwengoTimer.h \
dwengoUsart.h \
compiler/mplabc18.h \
compiler/pwm.h \
compiler/sdcc_pic16.h \
compiler/sdcc_pic16_pwm.h

libdwengo_lib_SOURCES = \
dwengoADC.c \
dwengoBluetooth.c \
dwengoBoard.c \
dwengoClock.c \
dwengoDelay.c \
dwengoI2C.c \
dwengoInterrupt.c \
dwengoLCD.c \
dwengoMotor.c \
dwengoRC.c \
dwengoSensorModule.c \
dwengoServo.c \
dwengoTimer.c \
dwengoUsart.c
#dwengoSound.c 

REL_OBJ = $(libdwengo_lib_SOURCES:.c=.rel)

### Redefine implicit (suffix) rule to convert form .c to .rel
# Define our suffix list

.c.o:
	$(SDCC_C) -c $(SDCCFLAGS) $<

.o.rel: $(libdwengo_lib_OBJECTS)
	cp $< $@
  
libdwengo.lib$(EXEEXT): $(REL_OBJ)
	$(RM) $@
	$(SDAR_L) -rc $@ $(REL_OBJ)


