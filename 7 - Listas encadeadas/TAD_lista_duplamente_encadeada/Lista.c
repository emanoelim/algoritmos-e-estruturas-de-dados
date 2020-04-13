#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

struct item {
  int chave;
  // demais campos
};
struct celula {
  Item item;
  Celula *ant;
  Celula *prox;
};
struct lista {
  Celula *primeira;
};

Lista * cria_lista_vazia() {
  Lista *l = malloc(sizeof(Lista));
  l->primeira = NULL;
  return l;
}

// retorna 1 se está vazia, ou 0 se não está
int verifica_lista_vazia(Lista *l) {
  return l->primeira == NULL;
}

void inserir_inicio(Lista *l, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->ant = NULL;
  nova->prox = l->primeira;
  // se a lista não está vazia, a anterior da que era a primeira será a nova
  if(!verifica_lista_vazia(l))
    l->primeira->ant = nova;
  l->primeira = nova;
}

void imprime_esq_dir(Lista *l) {
  Celula *aux = l->primeira;
  while(aux != NULL) {
    printf("Chave: %d\n", aux->item.chave);
    aux = aux->prox;
  }
}

void imprime_dir_esq(Lista *l) {
  Celula *aux = l->primeira;
  while(aux->prox != NULL) { 
    aux = aux->prox;
  }
  while(aux != NULL) {
    printf("Chave: %d\n", aux->item.chave);
    aux = aux->ant;
  }
}

void insere_final(Lista *l, int chave) {
  if(verifica_lista_vazia(l))
    inserir_inicio(l, chave);
  else {
    Item novo;
    novo.chave = chave;

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;

    Celula *ultima = l->primeira;
    while(ultima->prox != NULL) { // achar a última
      ultima = ultima->prox;
    }
    nova->ant = ultima;

    ultima->prox = nova;
  }
}

Celula * busca_chave(Lista *l, int chave) {
  Celula *aux = l->primeira;
  while(aux != NULL && aux->item.chave != chave) {
    aux = aux->prox;
  }
  return aux;
}

void insere_meio(Lista *l, int chave_b, int chave_i) {
  Celula *anterior = busca_chave(l, chave_b);
  if(anterior == NULL) {
    printf("Chave não encontrada ou lista vazia.\n");
    return;
  }
  Item novo;
  novo.chave = chave_i;
  
  Celula *proxima = anterior->prox;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->ant = anterior;
  nova->prox = proxima;
  
  anterior->prox = nova;
  if(proxima != NULL) // somente caso proxima não seja NULL, pois NULL não tem anterior
    proxima->ant = nova; 
}

void remove_por_chave(Lista *l, int chave) {
	Celula *remover = busca_chave(l, chave);
	if(remover == NULL) {
		printf("Item não encontrado ou lista vazia.\n");
		return;
	}
        if(remover->ant == NULL && remover->prox == NULL) // se é a única
		l->primeira = NULL;
	else if(remover == l->primeira) { // remover do inicio
		l->primeira = remover->prox;
		l->primeira->ant = NULL;		
	}
	else {	// remover do meio ou fim
		Celula *proxima = remover->prox;
		Celula *anterior = remover->ant;
		anterior->prox = proxima;
		if(proxima != NULL) 
			proxima->ant = anterior;
	}
	free(remover);
}

void inverte_lista(Lista *l) {
	Celula *frente = l->primeira;
	Celula *tras = l->primeira;
	Item aux;
	int i = 0, j = 0;
	while(tras->prox != NULL) {
		tras = tras->prox;
		i++;
	}
	while(j <= i / 2) {
		if(frente != tras) {
			aux = frente->item;
			frente->item = tras->item;
			tras->item = aux;
			frente = frente->prox;
			tras = tras->ant;
		}
		j++;
	}
	
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
