

all: numInvBrute numInvMerge convHullBrute convHullMerge

numInvBrute: numInvBrute.c
	gcc -o numInvBrute numInvBrute.c

numInvMerge: numInvMerge.c
	gcc -o numInvMerge numInvMerge.c

convHullBrute: convHullBrute.c
	gcc -o convHullBrute convHullBrute.c

convHullMerge: convHullMerge.c
	gcc -o convHullMerge convHullMerge.c -lm

clean:
	rm -r -f bin *.o *.dump numInvBrute
	rm -r -f bin *.o *.dump numInvMerge
	rm -r -f bin *.o *.dump convHullBrute
	rm -r -f bin *.o *.dump convHullMerge
