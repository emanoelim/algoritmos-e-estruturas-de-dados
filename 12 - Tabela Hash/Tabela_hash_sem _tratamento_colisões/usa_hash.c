#include "hash.h"

main() {
  Hash *h = cria_tabela();

  insere_sem_tratamento(h, 92);
  insere_sem_tratamento(h, 10);
  insere_sem_tratamento(h, 2);
  insere_sem_tratamento(h, 60);

  imprime_tabela(h);

  imprime_item(busca_sem_tratamento(h, 1));
  imprime_item(busca_sem_tratamento(h, 110));

  libera_tabela(h);
}
