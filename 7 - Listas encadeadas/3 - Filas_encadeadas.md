# Fila encadeada

Assim como na lista, teremos uma estrutura tipo Item e uma estrutura tipo tipo Celula que aponta para quem é a próxima célula da 
fila. A diferença agora é que na estrutura fila é conveniente guardar o início e o fim da fila, já que vamos remover do início 
(desenfileirar) e adicionar no fim (enfileirar):

```c
typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;

struct item {
  int chave;
  // demais campos
};
struct celula {
  Item item;
  Celula *prox;
};
struct fila {
  Celula *ini;
  Celula *fim;
};
```

Podemos visualizar a fila assim:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/fila_encadeada.png)

Vamos criar um TAD fila com funções para:
- criar fila vazia;
- verificar fila vazia;
- enfileirar;
- imprimir a fila;
- desenfileirar;
- liberar fila.

### Criar fila vazia

Para criar a fila vazia, tanto ini quanto fim devem apontar para NULL:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/fila_vazia.png)

```c
Fila * cria_fila_vazia() {
  Fila *f = malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}
```

### Verificar fila vazia

Podemos dizer que a fila está vazia se o seu início ainda aponta para NULL:

```c
int verifica_fila_vazia(Fila *f) {
  return f->ini == NULL;
}
```

### Enfileirar

Na a função enfileira, uma nova célula é inserida no final da fila, logo, sabemos que:
- A próxima célula da nova célula é NULL;
- O ponteiro "fim" deve apontar para a nova célula.

Além disso, existem duas situações que precisam ser tratadas:

- Se a fila está vazia, o ponteiro "ini" deve apontar para a nova célula (ela será a única célula, portando será a última e também a primeira):

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/enfileira_vazia.png)

- Se a fila não está vazia, aquela que é a última célula (a que é apontada por "fim") deve apontar para a nova célula:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/enfileira_nao_vazia.png)

```c

void enfileira(Fila *f, int chave) {
  Item novo_item;
  novo_item.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo_item;
  nova->prox = NULL;
  if(verifica_fila_vazia(f)) // se está vazia adiciona no início
    f->ini = nova;
  else
    f->fim->prox = nova;
  f->fim = nova;
}
```

### Imprimir fila

Para imprimir a fila:

```c
void imprime_fila(Fila *f) {
  Celula *aux = f->ini;
  while(aux != NULL) {
    printf("Chave: %d\n", aux->item.chave);
    aux = aux->prox;
  }
}
```

### Desenfileirar

Para desenfileirar um item, primeiramente será necessário ver se a fila não está vazia. A célula que vai ser removida é aquela 
que foi adicionada menos recentemente, ou seja, a célula apontada por "ini". O ponteiro "ini" deve agora apontar para a célula 
que era a próxima da primeira célula:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/desenfileira.png)

Antes de finalizar temos que tomar cuidado para ver se a fila não ficou vazia após a remoção. Caso tenha ficado vazia, é necessário
fazer "fim" apontar para NULL:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/desenfileira_fica_vazia.png)

```c
void desenfileira(Fila *f) {
  if(verifica_fila_vazia(f)) {
      printf("Erro: a fila está vazia.\n");
      return;
  }
  Celula *remover = f->ini;
  f->ini = remover->prox;
  free(remover);
  if(verifica_fila_vazia(f)) // se ficou vazia, fim aponta para NULL
      f->fim = NULL;
}
```

### Liberar fila

Por fim, a liberação da fila, que é semelhante a liberação da lista:

```c
void libera_fila(Fila *f) {
  Celula *aux = f->ini;
  Celula *liberar;
  while(aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(f);
}
```

# Materiais recomendados

- Vídeo aulas sobre filas encadeadas do canal Linguagem C Programação Descomplicada, com prof. André Backes:
https://www.youtube.com/watch?v=4YXnrKJCWrE
- Visualização de uma fila encadeada: https://www.cs.usfca.edu/~galles/visualization/QueueLL.html

