PROGRAM = a.out
CC = gcc
CFLAGS = -c

$(PROGRAM): masa.o test_SDL2.o 
	$(CC) masa.o test_SDL2.o -o $(PROGRAM)

masa.o: masa.c masa.h
	$(CC) $(CFLAGS) masa.c

test_SDL2.o: test_SDL2.c masa.h config.h
	$(CC) $(CFLAGS) test_SDL2.c

clean: 
	rm *.o 
	rm $(PROGRAM)