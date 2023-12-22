CC := g++
CFLAGS := -g -std=c++17
INCLUDES := -I./include
OBJECTS := window.o main.o

ODIR=.
IDIR=./include

LIBS := -lSDL2

main: $(OBJECTS)
	$(CC) $^ -o $@ $(LIBS)

%.o: ./src/%.cpp
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f  main
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append  
