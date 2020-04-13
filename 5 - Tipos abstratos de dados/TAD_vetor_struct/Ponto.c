#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

struct ponto {
    int x;
    int y;
};

Ponto * aloca(int tamanho) {
   Ponto *poligono = (Ponto*)malloc(tamanho * sizeof(Ponto));
   return poligono;
}

void cadastra_poligono(int x, int y, Ponto *poligono, int pos) {
	//poligono[pos].x = x; // ao acessar o índice através dos [] já faz a op. de deferência.
        //(*(poligono + pos)).x = x; // poligono + pos: move o ponteiro para o índice pos. *(poligono + pos): faz a deferência e me da acesso a um item tipo Ponto.
        (poligono + pos)->x = x; // poligono + pos: move o ponteiro para o índice pos. A deferência é feita usando -> em vez de usar (*ponteiro).x
	//poligono[pos].y = y;
        //(*(poligono + pos)).y = y;
        (poligono + pos)->y = y;
}

void imprime(Ponto *poligono, int tamanho) {
     for(int i = 0; i < tamanho; i++) 
	printf("P%d: %d, %d\n", i+1, poligono[i].x, poligono[i].y);
}

void libera(Ponto *poligono) {
   free(poligono);
}


