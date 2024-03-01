
OBJ=cliente.o servidor.o imp_clave.o claves.o
FLAGS=-g -Wall -lrt
SRC=src/

.PHONY: all clean

all: $(OBJ)
	gcc $(FLAGS) -o client cliente.o claves.o
	gcc $(FLAGS) -o server servidor.o imp_clave.o

cliente.o: $(SRC)cliente.c 
	@echo "compiling client..."
	gcc -c $<

servidor.o: $(SRC)servidor.c 
	@echo "compiling server..."
	gcc -c $<

imp_clave.o: $(SRC)imp_clave.c
	@echo "compiling services..."
	gcc -c $<

claves.o: $(SRC)claves.c
	@echo "compiling tuple..."
	gcc -c $<

clean:
	rm *.o

