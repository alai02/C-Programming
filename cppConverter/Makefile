OBJ = A1.o create.o manipulate.o fileio.o helper.o

all: a1

a1: $(OBJ)
	gcc A1.o create.o manipulate.o fileio.o helper.o -o a1

A1.o: src/A1.c
	gcc -Wall -g -ansi src/A1.c -Iinclude  -c

create.o: src/create.c
	gcc -Wall -g -ansi src/create.c -Iinclude -c

manipulate.o: src/manipulate.c
	gcc -Wall -g -ansi src/manipulate.c -Iinclude -c

fileio.o: src/fileio.c
	gcc -Wall -g -ansi src/fileio.c -Iinclude  -c

helper.o: src/helper.c
	gcc -Wall -g -ansi src/helper.c -Iinclude  -c

clean:
	rm -r -f bin *.o *.dump a1 assets/sample1.c assets/sample2.c assets/sample3.c a.out
