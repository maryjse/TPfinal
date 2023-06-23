PROGRAM = a.out
CC = gcc
CFLAGS = -c
LDFLAGS = -lSDL2 -lSDL2_ttf -DTTF


$(PROGRAM): masa.o test_SDL2.o malla.o resorte.o lista.o
	$(CC) masa.o test_SDL2.o malla.o resorte.o lista.o -o $(PROGRAM) $(LDFLAGS) -lm

masa.o: masa.c masa.h
	$(CC) $(CFLAGS) masa.c

test_SDL2.o: test_SDL2.c malla.h masa.h
	$(CC) $(CFLAGS) test_SDL2.c $(LDFLAGS)

malla.o: malla.c malla.h masa.h resorte.h lista.h config.h
	$(CC) $(CFLAGS) malla.c

resorte.o: resorte.c resorte.h lista.h
	$(CC) $(CFLAGS) resorte.c -lm

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) lista.c

clean: 
	rm *.o 
	rm $(PROGRAM)