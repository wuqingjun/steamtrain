EXE=final

# Main target
all: $(EXE)


#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a $(EXE).tar
TAR=tar cvf $(EXE).tar *
endif

ex11.o: ex11.c CSCIx229.h
fatal.o: fatal.c CSCIx229.h
loadtexbmp.o: loadtexbmp.c CSCIx229.h
print.o: print.c CSCIx229.h
project.o: project.c CSCIx229.h
errcheck.o: errcheck.c CSCIx229.h
object.o: object.c CSCIx229.h
square.o: square.cc square.h
sphere.o: sphere.cc sphere.h
cylinder.o: cylinder.cc cylinder.h
cube.o: cube.cc cube.h
pie.o: pie.cc pie.h
cover.o: cover.cc cover.h
wheel.o: wheel.cc wheel.h
pile.o: pile.cc pile.h
raleway.o: raleway.cc raleway.h
train.o: train.cc train.h
mountain.o: mountain.cc mountain.h 
diamondsquare.o: diamondsquare.cc diamondsquare.h
sun.o: sun.cc sun.h
smoothheightmap.o: smoothheightmap.cc smoothheightmap.h
tunnel.o: tunnel.cc tunnel.h
ground.o: ground.cc ground.h
beam.o: beam.cc beam.h
rain.o: rain.cc rain.h
particle.o: particle.cc particle.h
smoke.o: smoke.cc smoke.h

#  Create archive
CSCIx229.a:fatal.o loadtexbmp.o print.o project.o errcheck.o object.o square.o sphere.o cylinder.o cube.o pie.o cover.o wheel.o pile.o raleway.o train.o mountain.o diamondsquare.o sun.o smoothheightmap.o tunnel.o ground.o beam.o rain.o particle.o smoke.o 
	ar -rcs $@ $^

$(EXE).o: $(EXE).cc
.cc.o:
	g++ -g -c $(CFLG) $< $(LIBS) 

#  Compile and link
$(EXE):$(EXE).o CSCIx229.a 
	g++ -g $(CFLG) -o $@ $^  $(LIBS) 

#  Clean
clean:
	$(CLEAN)
# Target 
tar:
	$(TAR)
