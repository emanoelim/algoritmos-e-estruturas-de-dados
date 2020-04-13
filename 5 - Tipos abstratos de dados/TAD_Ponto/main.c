#include "Ponto.h"

int main()
{
    Ponto *p1, *p2;
    float d;

    p1 = cadastra(10, 20);
    p2 = cadastra(30, 20);

    imprime(p1);
    imprime(p2);

    d = calcula_distancia(p1, p2);
    printf("Distancia p1 e p2: %.2f\n", d);

    libera_ponto(p1);
    libera_ponto(p2);

    return 0;
}
