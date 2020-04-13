#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

struct item {
  int chave;
  // nome
  // endereço...
};

struct hash {
  int quantidade;
  Item **itens;
};

Hash * cria_tabela() {
  int i;
  Hash *h = malloc(sizeof(Hash));
  h->quantidade = 0;
  h->itens = malloc(TABLESIZE * sizeof(Item*));
  for(i = 0; i < TABLESIZE; i++)
    h->itens[i] = NULL;
  return h;
}

void libera_tabela(Hash *h) {
  int i;
  for(i = 0; i < TABLESIZE; i++) {
    if(h->itens[i] != NULL)
      free(h->itens[i]);
  }
  free(h->itens);
  free(h);
}

int hashing_divisao(int chave) {
  return chave % TABLESIZE;
}

int sondagem_linear(int posicao, int i) {
  return (posicao + i) % TABLESIZE;
}

int sondagem_quadratica(int posicao, int i) {
  float c1 = 0.5;
  float c2 = 0.5;
  int nova = posicao + c1*i + c2*i*i;
  return nova % TABLESIZE;
}

int duplo_hash(int chave, int antiga, int i) {
  int nova;
  if(antiga == 0)
    nova = 1;
  else
    nova = TABLESIZE - antiga;
  return (antiga + i*nova) % TABLESIZE;
}

// Retorna 1 se a tabela está cheia.
int verifica_tabela_cheia(Hash *h) {
  return h->quantidade == TABLESIZE;
}

// Retorna 1 se a tabela está vazia.
int verifica_tabela_vazia(Hash *h) {
  return h->quantidade == 0;
}

void insere_enderecamento_aberto(Hash *h, int chave) {
  if(verifica_tabela_cheia(h)) {
    printf("Erro: não existem posições livres.\n");
    return;
  }
  int i, posicao, nova_posicao;
  posicao = hashing_divisao(chave);
  // vai para a próx. (máximo de tentativas = TABLESIZE - 1)
  for(i = 0; i < TABLESIZE; i++) {
    nova_posicao = sondagem_linear(posicao, i);
    if(h->itens[nova_posicao] == NULL) {
      Item *item = malloc(sizeof(Item));
      item->chave = chave;
      h->itens[nova_posicao] = item;
      h->quantidade++;
      return;
    }
  }
  printf("Não foi possível inserir o item.\n");
}

Item * busca_enderecamento_aberto(Hash *h, int chave) {
  if(verifica_tabela_vazia(h)) {
    printf("Tabela vazia.\n");
    return NULL;
  }
  int i;
  int posicao, nova_posicao;
  posicao = hashing_divisao(chave);
  // vai para a próx. (máximo de tentativas = TABLESIZE - 1)
  for(i = 0; i < TABLESIZE; i++) {
    nova_posicao = sondagem_linear(posicao, i);
    // se a posição contém NULL, não foi tentado inserir o item
    if(h->itens[nova_posicao] == NULL)
      return NULL;
    if(h->itens[nova_posicao]->chave == chave)
      return h->itens[nova_posicao];
  }
  // se em nenhuma das tentativas o item foi encontrado, o item não existe
  return NULL;
}

void imprime_item(Item *item) {
  if(item != NULL)
    printf("Chave: %d\n",item->chave);
  else
    printf("Item não existe.\n");
}

void imprime_tabela(Hash *h) {
  int i;
  for(i = 0; i < TABLESIZE; i++) {
    if(h->itens[i] == NULL)
      printf("Pos: %d - Chave: NULL\n", i);
    else
      printf("Pos: %d - Chave: %d\n", i, h->itens[i]->chave);
  }
}
