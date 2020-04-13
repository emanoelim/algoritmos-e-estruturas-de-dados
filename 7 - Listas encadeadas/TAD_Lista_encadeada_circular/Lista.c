#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

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
  int tamanho;
};

Lista * cria_lista_vazia() {
  Lista *l = malloc(sizeof(Lista));
  l->primeira = NULL;
  l->tamanho = 0;
  return l;
}

int verifica_lista_vazia(Lista *l) {
  return l->primeira == NULL;
}

void insere_fim_lista(Lista *l, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;

  if(verifica_lista_vazia(l)) {
    l->primeira = nova;
    nova->prox = nova; // aponta para ela mesma
  }
  else {
    Celula *ultima = l->primeira;
    while(ultima->prox != l->primeira){
      ultima = ultima->prox;
    }
    ultima->prox = nova;
    nova->prox = l->primeira;
  }
  l->tamanho++;
}

void imprime(Lista *l) {
    if(verifica_lista_vazia(l)) {
	printf("Lista vazia.\n");
	return;
    }
    Celula *aux = l->primeira;
    while(aux->prox != l->primeira) {
      printf("chave = %d\n", aux->item.chave);
      aux = aux->prox;
    }
    printf("chave = %d\n", aux->item.chave);
}

/* retorna a célula contendo o item correspondente a chave informada ou NULL se não encontrou */
Celula * busca_por_chave(Lista *l, int chave) {
  if(l->primeira->item.chave == chave) // se for a primeira já retorna
	return l->primeira;
  Celula *aux = l->primeira->prox; // procura pela célula, partindo da segunda. Para quando encontrar ou quando voltar até a primeira
  while(aux != l->primeira && aux->item.chave != chave) {
	aux = aux->prox;  	
  }
  if(aux != l->primeira) // se não voltou até a primeira, significa que achou
	return aux;
  else // se não, voltou até a primeira, não achou
	return NULL; 
}

void imprime_celula(Celula *c) {
	if(c != NULL)
		printf("Chave: %d\n", c->item.chave);
	else
		printf("Célula não encontrada.\n");
}

void remove_item(Lista *l, int x) {
  Celula *aux = l->primeira;
  if(aux == aux->prox) { // se só tem uma
	l->primeira = NULL;
  }
  else if(aux->item.chave == x) { // se é a primeira, remover do início
	Celula *ultima = l->primeira; // achar a última, pois a ultima tem que apontar para a nova primeira
	while(ultima->prox != l->primeira) 
		ultima = ultima->prox;
	ultima->prox = aux->prox;
	l->primeira = aux->prox;
  }
  else {
  	aux = aux->prox; // partindo da segunda
  	Celula *anterior;
  	while(aux != l->primeira && aux->item.chave != x) { // percorrer até encontrar ou até voltar na primeira
		anterior = aux;
		aux = aux->prox;
  	}
  	if(aux == l->primeira) { // se voltou até primeira, não achou
		printf("Célula não encontrada.\n");
		return;
  	}
  	anterior->prox = aux->prox;
  }
  free(aux);
  l->tamanho--;
}

void libera_lista(Lista *l) {
  Celula *aux = l->primeira;
  Celula *liberar;
  while(aux->prox != l->primeira) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(aux);
  free(l);
}

int tamanho_lista(Lista *l) {
  return l->tamanho;
}

