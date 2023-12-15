IDIR =./include
CC=g++
CFLAGS= -I$(IDIR) -g -O0 -std=c++11

ODIR=.

LIBS=

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: ./src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: main

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f  main
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append  