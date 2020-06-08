# Pilha encadeada

Podemos definir a estrutura da pilha de maneira semelhante a da lista vista anteriormente:

```c
typedef struct item Item;
typedef struct celula Celula;
typedef struct pilha Pilha;

struct item {
  int chave;
  // demais campos
};
struct celula {
  Item item;
  Celula *prox;
};
struct pilha {
  Celula *topo;
};
```

Temos uma estrutura do tipo Item para guardar o item e seus campos relevantes, uma estrutura do tipo Celula, que guarda um item 
e um ponteiro para quem será a próxima célula da pilha e uma estrutura do tipo Pilha, que contém nada mais do que um 
ponteiro para a célula que é o topo da pilha. Podemos visualizar da seguinte forma:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/pilha_encadeada.png)

Para este TAD pilha vamos criar funções para:

- criação de pilha vazia;
- verificação de pilha vazia;
- empilha;
- imprime pilha;
- desempilha;
- libera pilha.

### Criação de pilha vazia

A criação da pilha vazia também fica muito parecida com a criação da lista. Se ela está vazia, não existe um endereço para o qual 
“topo” deve apontar. Assim, podemos fazer “topo” apontar para NULL.

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/pilha_vazia.png)

Isto pode ser implementado da seguinte forma:

```c
Pilha * cria_pilha_vazia() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}
```
### Verificação de pilha vazia

Para verificar se a pilha está vazia basta verificar se o topo ainda é igual a NULL:

```c
int verifica_pilha_vazia(Pilha *p) {
  return p->topo == NULL;
}
```
### Empilha

A função de empilha fica semelhante a inserção no início de uma lista lista. A próxima célula da nova célula adicionada será aquela que era o topo. O topo, por sua vez, agora deve apontar para a nova célula:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/empilha.png)

```c
void empilha(Pilha *p, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = p->topo;
  p->topo = nova;
}
```
### Imprimir pilha

Após criar a função empilha(), podemos criar a função que imprime a pilha, para visualizar como ela está ficando:

```c
void imprime(Pilha *p) {
    Celula *aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox)
           printf("chave = %d\n", aux->item.chave);
}
```
### Desempilha

Para a função desempilha, precisamos “desligar” a célula que estava no topo e ligar o ponteiro topo com a próxima (desde que a pilha não esteja vazia):

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/desempilha.png)

```c
void desempilha(Pilha *p) {
  if(verifica_pilha_vazia(p)) {
    printf("Erro: pilha vazia!\n");
    return ;
  }
  Celula *remover = p->topo;
  p->topo = remover->prox;
  free(remover);
  }
}
```
### Liberar pilha

A liberação da pilha também é muito paracida com a lista:

```c
void libera_pilha(Pilha *p) {
  Celula *aux = p->topo;
  Celula *liberar;
  while(aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(p);
}
```

# Materiais recomendados

- Vídeo aulas sobre pilhas encadeadas do canal Linguagem C Programação Descomplicada, com prof. André Backes: 
https://www.youtube.com/watch?v=9GGJH2sjOac
- Visualização de uma pilha encadeada: https://www.cs.usfca.edu/~galles/visualization/StackLL.html
