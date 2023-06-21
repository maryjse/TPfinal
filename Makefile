PROGRAM = a.out
CC = gcc
CFLAGS = -c -lSDL2 -lSDL2_ttf -DTTF

$(PROGRAM): masa.o test_SDL2.o 
	$(CC) masa.o test_SDL2.o -o $(PROGRAM) -lSDL2 -lSDL2_ttf -DTTF

masa.o: masa.c masa.h
	$(CC) $(CFLAGS) masa.c

test_SDL2.o: test_SDL2.c masa.h config.h 
	$(CC) $(CFLAGS) test_SDL2.c

clean: 
	rm *.o 
	rm $(PROGRAM)