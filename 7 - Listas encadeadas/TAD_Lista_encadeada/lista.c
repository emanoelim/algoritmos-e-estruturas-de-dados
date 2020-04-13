#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct item {
  int chave;
  // demais campos;
};

struct celula {
  Item item;
  struct celula *prox;
};

struct lista {
  Celula *primeira;
};

Lista * cria_lista_vazia() {
  Lista *l = malloc(sizeof(Lista));
  l->primeira = NULL;
  return l;
}

int verifica_lista_vazia(Lista *l) {
  return l->primeira == NULL;
}

void insere_inicio_lista(Lista *l, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = l->primeira;
  l->primeira = nova;
}

void imprime(Lista *l) {
    Celula *aux;
    for(aux = l->primeira; aux != NULL; aux = aux->prox)
        printf("chave = %d\n", aux->item.chave);
}

int tamanho_lista(Lista *l) {
   Celula *aux = l->primeira;
   int i = 0;
   while(aux != NULL) {
      aux = aux->prox;
      i++;
   }
   return i;
}

Celula * busca_por_chave(Lista *l, int chave) {
  Celula *aux = l->primeira;
  while(aux != NULL && aux->item.chave != chave) {
      aux = aux->prox;
  }
  return aux;
}

void insere_fim_lista(Lista *l, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = NULL;
  if(verifica_lista_vazia(l))
    l->primeira = nova;
  else {
    Celula *ultima;
    ultima = l->primeira;
    while(ultima->prox != NULL) {
      ultima = ultima->prox;
    }
    ultima->prox = nova;
  }
}

// inserir novo item após o item com chave = x
void insere_meio_lista(Lista *l, int chave, int x) {
  Celula *aux = busca_por_chave(l, x);
  if(aux != NULL) {
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = aux->prox;
    aux->prox = nova;
  }
  else {
    printf("O item informado não existe.\n");
  }
}

// remover o item com a chave = x
void remove_item(Lista *l, int x) {
  Celula *aux = l->primeira;
  Celula *anterior;
  while(aux != NULL && aux->item.chave != x) {
    anterior = aux;
    aux = aux->prox;
  }
  if(aux == NULL) {
    printf("O item informado não existe.\n");
    return;
  }
  if(aux == l->primeira) // remover do começo
    l->primeira = aux->prox;
  else
      anterior->prox = aux->prox;
  free(aux);
}

void libera_lista(Lista *l) {
  Celula *aux = l->primeira;
  Celula *liberar;
  while(aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(l);
}
