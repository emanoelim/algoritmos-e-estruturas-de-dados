#include <stdio.h>
#include "Lista.h"

int main() {
  Lista *l = cria_lista_vazia();

  printf("Vazia: %d\n", verifica_lista_vazia(l));

  printf("\nInserindo no inicio...\n");
  inserir_inicio(l, 10);
  inserir_inicio(l, 20);
  inserir_inicio(l, 30);
  inserir_inicio(l, 40);

  printf("Imprimindo esq->dir\n");
  imprime_esq_dir(l);
  printf("\nImprimindo dir->esq\n");
  imprime_dir_esq(l);

  printf("\nInserindo no final...\n");
  insere_final(l, 5);
  insere_final(l, 15);
  imprime_esq_dir(l);

  printf("\nInserindo 90 após o 20...\n");
  insere_meio(l, 20, 90);
  imprime_esq_dir(l);

  printf("\nInserindo 1 após o 15...\n");
  insere_meio(l, 15, 1);
  imprime_esq_dir(l);

  printf("\nRemovendo o primeiro (40)...\n");
  remove_por_chave(l, 40);
  imprime_esq_dir(l);

  printf("\nRemovendo o último (1)...\n");
  remove_por_chave(l, 1);
  imprime_esq_dir(l);

  printf("\nRemovendo do meio (10)...\n");
  remove_por_chave(l, 10);
  imprime_esq_dir(l);

  printf("\nLista original:\n");
  imprime_esq_dir(l);
  printf("\nLista invertida:\n");
  inverte_lista(l);
  imprime_esq_dir(l);

  libera_lista(l);
}
