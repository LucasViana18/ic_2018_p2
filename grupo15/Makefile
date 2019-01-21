all: a.out
	echo "Construção feita!"

a.out: main.o
	gcc -o prog main.o

main.o: main.c functions.h
	gcc -c -std=c99 -g -Wall -Wextra -Wpedantic main.c

clean:
	rm -f *.out *.o
