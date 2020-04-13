#include <stdio.h>
#include "Lista.h"

main() {
  Lista *l;

  l = cria_lista_vazia();
  insere_fim_lista(l, 7);
  insere_fim_lista(l, 10);
  insere_fim_lista(l, 20); 
  insere_fim_lista(l, 90);
  insere_fim_lista(l, 15);
  insere_fim_lista(l, 30);
  imprime(l);
  printf("\nTamanho da lista: %d\n", tamanho_lista(l));

  printf("\nProcurando por chave:\n");
  imprime_celula(busca_por_chave(l, 7));
  imprime_celula(busca_por_chave(l, 20));
  imprime_celula(busca_por_chave(l, 30));
  imprime_celula(busca_por_chave(l, 17));

  printf("\nRemovendo do inicio (7):\n");
  remove_item(l, 7);
  imprime(l);

  printf("\nRemovendo do meio (90):\n");
  remove_item(l, 90);
  imprime(l);

  printf("\nRemovendo do fim (30):\n");
  remove_item(l, 30);
  imprime(l);

  printf("\nRemove tudo:\n");
  remove_item(l, 10);
  remove_item(l, 20);
  remove_item(l, 15);
  imprime(l);
  printf("\nTamanho da lista: %d\n", tamanho_lista(l));

  printf("\nInserindo após ter ficado vazia:\n");
  insere_fim_lista(l, 2);
  insere_fim_lista(l, 88);
  insere_fim_lista(l, 14);
  imprime(l);
  printf("\nTamanho da lista: %d\n", tamanho_lista(l));

  libera_lista(l);
}
