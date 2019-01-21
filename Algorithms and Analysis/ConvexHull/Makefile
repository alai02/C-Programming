all: q11 q12 q21 q22

q11: q11.c
	gcc -o q11 q11.c

q12: q12.c
	gcc -o q12 q12.c

q21: q21.c
	gcc -o q21 q21.c

q22: q22.c
	gcc -o q22 q22.c -lm

clean:
	rm -r -f bin *.o *.dump q11
	rm -r -f bin *.o *.dump q12
	rm -r -f bin *.o *.dump q21
	rm -r -f bin *.o *.dump q22
