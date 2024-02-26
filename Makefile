CC := g++
CFLAGS := -g -std=c++20
INCLUDES := -I./include 
OBJECTS := window.o main.o

ODIR=.
IDIR=./include

LIBS := -lGL -ldl `pkg-config --libs --cflags glfw3 glew`

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
