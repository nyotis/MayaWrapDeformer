#-
# ==========================================================================
# Copyright 2010 Autodesk, Inc. All rights reserved.
#
# Use of this software is subject to the terms of the Autodesk
# license agreement provided at the time of installation or download,
# or which otherwise accompanies this software in either electronic
# or hard copy form.
# ==========================================================================
#+

#
# Include platform specific build settings
#
include buildconfig

%.o :	%.c
	$(CC) -c $(INCLUDES) $(CFLAGS) $<
	
%.o :	%.cc
	$(C++) -c $(INCLUDES) $(C++FLAGS) $<

%.o :	%.cpp
	$(C++) -c $(INCLUDES) $(C++FLAGS) $<

%.i :	%.cc
	$(C++) -E $(INCLUDES) $(C++FLAGS) $*.cc > $*.i

%.$(EXT) :	%.c
	-rm -f $@
	$(CC) -o $@ $(INCLUDES) $(CFLAGS) $< $(LFLAGS) $(LIBS)

%.$(EXT) :	%.cc
	-rm -f $@
	$(C++) -o $@ $(INCLUDES) $(C++FLAGS) $< $(LFLAGS) $(LIBS)

%.$(EXT) :	%.cpp
	-rm -f $@
	$(C++) -o $@ $(INCLUDES) $(C++FLAGS) $< $(LFLAGS) $(LIBS)

%.$(EXT) :	%.o
	-rm -f $@
	$(LD) -o $@ $< $(LIBS)


CustomWrapDeformer.$(EXT):	CustomWrapDeformer.o
#poseDeformer.$(EXT):	poseDeformer.o plugin.o MatrixNN.o mirrorData.o poseDeformerEdit.o
	-rm -f $@
	$(LD) -o $@ $^ $(LIBS) -lOpenMayaUI -lOpenMayaAnim -lOpenMayaFX


depend:
	makedepend $(INCLUDES) -I/usr/include/CC *.cc 

clean:
	-rm -f *.o

Clean:
	-rm -f *.o *.so *.lib *.bak *.bundle
