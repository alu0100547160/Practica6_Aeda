# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $<


# Macros

CXX = g++ -std=c++11
CFLAGS =  -g -Wall -O2
SRC = main.cpp arbolBB.hpp  nodoBB.hpp modo.hpp Dni.hpp
OBJ = main.o


# Reglas expl�mcitas

all: ${OBJ}
	$(CXX) $(CFLAGS) -o main $(OBJ)

clean:
	$(RM) $(OBJ) main

# Reglas impl�citas

main.o: main.cpp arbolBB.hpp  nodoBB.hpp modo.hpp Dni.hpp
