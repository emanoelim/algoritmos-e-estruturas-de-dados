#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main() {
    Ponto *poligono = aloca(10);
    int x, y;

    for(int i = 0; i < 10; i++) {
        printf("Informe x e y no formato x, y: ");
        scanf("%d, %d", &x, &y);
	cadastra_poligono(x, y, poligono, i);
    }

    imprime(poligono, 10);

    libera(poligono);

    return 0;
}
