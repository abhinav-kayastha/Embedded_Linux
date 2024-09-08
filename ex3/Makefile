random_generator: function.o main.o
	gcc -o random_generator function.o main.o

function.o: function.c function.h
	gcc -c function.c

main.o: main.c function.h
	gcc -c main.c

.PHONY: clean

clean:
	rm -f *.o
