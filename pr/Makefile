calculate : calculator.o ./lib/add.o ./lib/subtract.o ./lib/multiply.o ./lib/divide.o
	gcc -o calculate calculator.o ./lib/add.o ./lib/subtract.o ./lib/multiply.o ./lib/divide.o -I./lib -L./lib
	
calculator.o : calculator.c
	gcc -c calculator.c -I./lib
	
./lib/add.o : ./lib/add.c
	gcc -c ./lib/add.c
	
./lib/subtract.o : ./lib/subtract.c
	gcc -c ./lib/subtract.c

./lib/multiply.o : ./lib/multiply.c
	gcc -c ./lib/multiply.c

./lib/divide.o : ./lib/divide.c
	gcc -c ./lib/divide.c
	
clean :
	rm -f calcultate calculator.o ./lib/add.o ./lib/subtract.o ./lib/multiply.o ./lib/divide.o
