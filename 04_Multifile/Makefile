GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so
TRASH = *.o *~ o.*
CFLAGS=-fPIC

all:    README prog prog-a prog-so

prog:   const.o fun.o prog.o 

prog-a: liboutput_static.a prog.o
		cc -L. prog.o -loutput_static -o $@

prog-so: liboutput.so prog.o
		cc -L. prog.o -loutput -o $@

liboutput_static.a: const.o fun.o
		ar -rcs $@ $^

liboutput.so: const.o fun.o
		cc $(CFLAGS) -shared $^ -o $@ 

fun.o:  outlib.h

test: prog prog-a prog-so
		./prog > f1 
		./prog-a > f2 
		$ LD_LIBRARY_PATH=`pwd` ./prog-so > f3
		cmp f1 f2
		cmp f2 f3

		./prog hello > f1 
		./prog-a hello > f2 
		$ LD_LIBRARY_PATH=`pwd` ./prog-so hello > f3
		cmp f1 f2
		cmp f2 f3

		./prog hello moto one > f1 
		./prog-a hello moto one > f2 
		$ LD_LIBRARY_PATH=`pwd` ./prog-so hello moto one > f3
		cmp f1 f2
		cmp f2 f3

clean:
		rm -f $(TRASH)

distclean:      clean
		rm -rf $(GENERATES)