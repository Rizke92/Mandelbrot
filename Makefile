
CXXFLAGS=-g
LDLIBS=-lX11 -lstdc++ -lm

Mandelbrot: Mandelbrot.o gfx.o Complex.o

clean: 
	rm -f Mandelbrot *.o