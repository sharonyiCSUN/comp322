all: 
	gcc -c spiritd.c -Wall -Wextra
	gcc -o spiritd spiritd.o -lm
	gcc -c mole.c -Wall -Wextra
	gcc -o mole mole.o -lm	
dining: spiritd.c
	gcc -c spiritd.c -Wall -Wextra
	gcc -o spiritd spiritd.o -lm
mole: mole.c
	gcc -c mole.c -Wall -Wextra
	gcc -o mole mole.o -lm
clean:
	rm -f spiritd mole spiritd.o mole.o
	rm -f spiritd spiritd.o
	rm -f mole mole.o

