
OBJ=cliente.o servidor.o imp_clave.o claves.o lib.so
FLAGS=-g -Wall -lrt
LIB=-L. -Wl,-rpath=.
SRC=src/

.PHONY: all clean

all: $(OBJ)
	gcc $(FLAGS) $(LIB) -o cliente cliente.o lib.so
	gcc $(FLAGS) -o servidor servidor.o imp_clave.o
	@echo -e "\n\033[;32m\033[1mSUCCESS\033[0m\n"

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

