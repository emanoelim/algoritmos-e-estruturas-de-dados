typedef struct ponto Ponto;

Ponto * aloca(int tamanho);
void cadastra_poligono(int x, int y, Ponto *poligono, int pos);
void imprime(Ponto *poligono, int tamanho);
void libera(Ponto *poligono);
