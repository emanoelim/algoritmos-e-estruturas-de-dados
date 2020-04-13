#include "hash.h"

main() {
  Hash *h = cria_tabela();

  insere_enderecamento_aberto(h, 0);
  insere_enderecamento_aberto(h, 1);
  insere_enderecamento_aberto(h, 2);
  insere_enderecamento_aberto(h, 3);
  insere_enderecamento_aberto(h, 50); // sem tratamento, cairia na posição 0
  insere_enderecamento_aberto(h, 101); // sem tratamento, cairia na posição 1
  insere_enderecamento_aberto(h, 102); // sem tratamento, cairia na posição 2
  insere_enderecamento_aberto(h, 103); // sem tratamento, cairia na posição 3

  imprime_tabela(h);

  imprime_item(busca_enderecamento_aberto(h, 0));
  imprime_item(busca_enderecamento_aberto(h, 1));
  imprime_item(busca_enderecamento_aberto(h, 2));
  imprime_item(busca_enderecamento_aberto(h, 3));
  imprime_item(busca_enderecamento_aberto(h, 50));
  imprime_item(busca_enderecamento_aberto(h, 101));
  imprime_item(busca_enderecamento_aberto(h, 102));
  imprime_item(busca_enderecamento_aberto(h, 103));

  libera_tabela(h);
}
