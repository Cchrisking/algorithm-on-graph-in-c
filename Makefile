CC=gcc
CFLAGS= -Wall -g
all:graphe-optimisation
b-spline_3:src/main.o src/b-spline_3.o
	$(CC) $(CFLAGS) src/graphe.c src/matrice_adjacence.c src/alloc_mem.c src/liste_adjacence.c src/file_successeur.c src/parcours.c -o exe
clean :
	rm -f all \#*\#
