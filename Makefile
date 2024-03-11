
OBJ=cliente.o servidor.o imp_clave.o claves.o
FLAGS=-g -Wall -lrt
LIB=-L. -Wl,-rpath=.
SRC=src/

.PHONY: all clean

all: $(OBJ)
	gcc $(FLAGS) $(LIB) -o client cliente.o lib.so
	gcc $(FLAGS) -o client2 cliente.o claves.o
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
	gcc -c -fPIC $<
	
lib.so: claves.o
	@echo "generating dinamic library..."
	gcc -shared -o lib.so $<


clean:
	rm *.o

DonLimpio:
	rm *.o cliente servidor *.so

