#
# Seccion 1
#
# Esta seccion se puede modificar segun
# los requerimientos de su proyecto

CC=gcc
SRC=main.c check_args.c mandelbrot-serial.c ppm.c crono.c
BIN=mandelbrot

LIB=-lpthread 
CFLAGS=-Wall -W

#
# Seccion 2
#

OBJ=$(SRC:.c=.o)

default: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LIB) $(OBJ) -o $(BIN) -lm 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f *~

distclean: clean
	rm -f $(BIN)
	rm -f *.ppm
