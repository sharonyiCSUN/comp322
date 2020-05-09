all: 
	dining mole
dining: dining.c
	gcc -c dining.c -Wall -Wextra
	gcc -o dining dining.o -lm
mole: mole.c
	gcc -c mole.c -Wall -Wextra
	gcc -o mole mole.o -lm
clean:
	rm -f dning mole dining.o mole.o
	rm -f dining dining.o
	rm -f mole mole.o
