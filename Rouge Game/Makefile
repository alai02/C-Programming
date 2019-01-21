OBJ = main.o drawThings.o playGame.o heroMove.o

all: a.out

a.out: $(OBJ)
	gcc main.o drawThings.o heroMove.o playGame.o -lncurses

main.o: src/main.c
	gcc -std=c99 -Wall src/main.c -Iinclude -lncurses -c

drawThings.o: src/drawThings.c
	gcc -std=c99 -Wall src/drawThings.c -Iinclude -lncurses -c

heroMove.o: src/heroMove.c
	gcc -std=c99 -Wall src/heroMove.c -Iinclude -lncurses -c

playGame.o: src/playGame.c
	gcc -std=c99 -Wall src/playGame.c -Iinclude -lncurses -c 

clean:
	rm -r -f bin *.o *.dump a.out
