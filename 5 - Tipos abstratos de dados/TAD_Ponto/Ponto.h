typedef struct ponto Ponto;

Ponto * cadastra(float x, float y);
void imprime(Ponto *p);
float calcula_distancia(Ponto *p1, Ponto *p2);
void libera_ponto(Ponto *p);
