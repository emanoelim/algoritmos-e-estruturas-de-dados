#include "Ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    float x;
    float y;
};

Ponto * cadastra(float x, float y) {
    Ponto *p = malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

void imprime(Ponto *p) {
    printf("x: %.2f\n", p->x);
    printf("y: %.2f\n\n", p->y);
}

float calcula_distancia(Ponto *p1, Ponto *p2) {
    float dx, dy, d;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    d = sqrt(dx*dx + dy*dy);
    return d;
}

void libera_ponto(Ponto *p) {
    free(p);
}
