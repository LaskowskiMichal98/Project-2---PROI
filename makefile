CC = g++

CFLAGS = 

LIBS = equation.h Handlers.h 

OBJECTS = equation.o Handlers.o main.o


OUTPUT = TESTING

%.o: %.c $(LIBS)
	$(CC) -c -o $@ $^ $(CFLAGS)

$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clear:
	rm -f *.o TESTING