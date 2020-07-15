# Listas encadeadas

Na lista implementada usando arranjos/vetores, os itens da lista ficavam em posições contíguas de memória. Além disso, era
necessário ter uma ideia do tamanho da lista, para alocar a memória necessária no momento da sua criação. 
Esse tipo de implementação possuía alguns inconvenientes:

- Era necessário definir um tamanho máximo para a lista. Se o tamanho fosse muito maior do que o utilizado, sobraria memória. 
Se o tamanho máximo fosse menor do que o utilizado, faltaria memória.
- Para adicionar ou remover itens do início ou meio da lista, era preciso deslocar todos os itens após o item adicionado/removido.

Uma solução a estes problemas, é implementar uma lista encadeada (*linked list*). Uma lista encadeada é uma sequência de células: 
cada célula contém um item e um ponteiro com o endereço da próxima célula. 

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/lista_encadeada_mem.png)

Como cada célula contém um ponteiro para a próxima, as células não precisam estar em posições contíguas na memória. Elas podem ser 
alocadas dinamicamente conforme a necessidade, ou seja: não é mais necessário definir um tamanho máximo para a lista no momento da 
sua criação. Isto é muito vantajoso quando não sabemos previamente quantos itens a lista terá, pois os itens poderão ser 
adicionados conforme a demanda.

### Estrutura da lista encadeada

Uma lista encadeada pode ser representada pela seguinte estrutura:
```c
typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

// item que vai ser guardado na lista (igual na lista por arranjo)
struct item {
  int chave;
  // demais campos;
};

// a célula contém um item e um ponteiro para a próxima célula da lista
struct celula {
  Item item;
  Celula *prox;
};

/* a struct lista guarda o endereço da primeira célula de lista. A partir da primeira é possível acessar todas as outras */
struct lista {
  Celula *primeira;
};
```

A estrutura lista contém um ponteiro que terá o endereço da primeira célula da lista (poderia também guardar um ponteiro para a último e guardar outros atributos da lista, como tamanho). Podemos  então visualizar  a lista da seguinte forma:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/representa%C3%A7%C3%A3o_lista_encadeada.png)

### Criação de lista vazia

Uma vez definida a estrutura a ser usada, pode ser implementada a função para criar uma lista vazia. Se a lista está vazia, 
não temos um endereço para o qual “primeira” deve apontar. Assim, podemos fazer “primeira” receber um ponteiro nulo 
(que não aponta para nada). Em C, existe o NULL.

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/lista_vazia.png)

Pensando nisso, um exemplo de função para criar uma lista vazia seria:

```c
Lista * cria_lista_vazia() {
  Lista *l = malloc(sizeof(Lista));
  l->primeira = NULL;
  return l;
}
```
### Verificação de lista vazia

Para verificar se a lista está vazia, basta ver se “primeira” ainda aponta para NULL:

```c
int verifica_lista_vazia(Lista *l) {
  return l->primeira == NULL;
}
```

Para adicionar um novo item na lista encadeada, não precisamos nos preocupar se a lista está cheia ou não, em listas encadeadas, 
o conceito de lista cheia não existe, já que não precisamos definir um tamanho máximo para a lista. Os itens vão sendo 
adicionados um a um conforme a necessidade. O tamanho máximo da lista vai ser ditado pela memória disponível.

### Inserção na lista

A inserção de itens em uma lista pode ser feita no início da lista, no meio da lista ou no fim da lista.

**Inserção início**: considere que vamos inserir um item na lista que estava vazia. Precisamos criar a nova célula, 
fazer a nova célula apontar aquela que era a primeira (por enquanto é NULL) e então fazer com que “primeira” aponte para nova 
célula. Vamos manter o ponteiro NULL, pois ele indicará o término da lista.

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/inser%C3%A7%C3%A3o_inicio_lista_vazia_1.png)

e assim por diante:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/inser%C3%A7%C3%A3o_inicio_lista_vazia_2.png)

```c
void insere_inicio_lista(Lista *l, int chave) {
  // criar novo item que vai ser guardado na lista
  Item novo;
  novo.chave = chave;
  // cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  // inserção no início: a próxima célula é aquela que era a primeira
  nova->prox = l->primeira;
  // a primeira agora é a nova célula
  l->primeira = nova;
}
```

**Inserção no fim**: considerando que a lista não está vazia, a nova célula deve ser inserida após a última, que agora vai 
apontar para a nova célula, que por sua vez aponta para NULL:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/inser%C3%A7%C3%A3o_fim_lista.png)

Caso a lista esteja vazia, quem deve apontar para a nova célula é a primeira (teremos uam inserção no início).

```c
void insere_fim_lista(Lista *l, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = NULL; // a nova célula vai ser a última, então após ela vem NULL
  if(verifica_lista_vazia(l)) // se a lista está vazia, quem vai apontar para a nova é a primeira
    l->primeira = nova;
  else { // se não está vazia, quem vai apontar para a nova é a que era a última
    Celula *ultima; 
    ultima = l->primeira; // partindo da primeira célula, percorrer a lista até achar a última
    while(ultima->prox != NULL) {
      ultima = ultima->prox;
    }
    ultima->prox = nova; // após a última, inserir a nova célula
  }
}
```

**Inserção no meio**: como as células da lista não ficam em posições contíguas, acesso por meio de índices não existe. Se 
quisermos inserir uma nova célula após uma célula x, será preciso encontrar a célula x, ligar a célula x à nova célula, e 
ligar a nova célula naquela que estava ligada à célula x.

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/inser%C3%A7%C3%A3o_meio_lista.png)

O mais comum é fazer uma inserção após um item que contém determinada chave. Assim, convém criar uma função que busca a célula 
que contém o item com essa chave, para que o novo item seja inserido após essa célula:

```c
// retorna a célula contendo o item correspondente a chave informada ou NULL se não encontrou
Celula * busca_por_chave(Lista *l, int chave) {
  Celula *aux = l->primeira;
  while(aux != NULL && aux->item.chave != chave) {
      aux = aux->prox;
  }
  return aux;
}
```

Agora é possível usar essa função para fazer a inserção:

```c
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
```
### Imprimir lista

Agora podemos criar uma função que imprime os itens da lista:

```c
void imprime(Lista *l) {
    Celula *aux;
    for(aux = l->primeira; aux != NULL; aux = aux->prox)
        printf("chave = %d\n", aux->item.chave);
}
```

### Remoção de item da lista

Vamos criar uma função que recebe uma chave e remove o item com a chave correspondente, caso encontre. Este item podem ser: 
- o primeiro da lista (remoção no início);
- um item do meio da lista (remoção no meio);
- o último item da lista (remoção do fim).

Quando o item a ser removido é o primeiro, basta fazer com que o primeiro passe a ser o próximo e então liberar o antigo primeiro.

Quando o item a ser removido está no meio ou no fim da lista, precisamos encontrar quem é o item anterior daquele que será removido, para ligar o anterior com o próximo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/remo%C3%A7%C3%A3o_meio_lista.png)

Portanto, vamos criar uma função preparada para lidar com estes 3 tipos de remoção:

```c
void remove_item(Lista *l, int x) {
  Celula *aux = l->primeira;
  Celula *anterior;
  while(aux != NULL && aux->item.chave != x) { // encontrar o item com a chave que deve ser removida
    anterior = aux; // guardar quem é o anterior
    aux = aux->prox;
  }
  if(aux == NULL) {
    printf("Item não encontrado.");
    return;
  }
  if(aux == l->primeira) // remover do começo
    l->primeira = aux->prox;
  else // meio ou fim
      anterior->prox = aux->prox;
  free(aux);
}
```

### Liberar lista 

Por fim precisamos é necessário liberar a lista. Será preciso percorrer toda a lista e ir liberando célula por célula e por fim linerar a estrutura que aponta para a primeira célula. Vamos usar uma variável auxiliar chamada "liberar":

```c
void libera_lista(Lista *l) {
  Celula *aux = l->primeira;
  Celula *liberar;
  while(aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(l);
```
Perceba que não podemos simplesmente fazer free(aux), pois estaríamos "quebrando" a lista e não teríamos como recuperar a próxima célula. A variável "liberar" recebe a célula atual, movemos aux para a próxima célula e então podemos liberar o endereço guardado na variável "liberar", sem prejudicar o restante da lista.

# Vantagens da lista encadeada
- Não é preciso definir tamanho máximo, as células são alocadas conforme a demanda.
- É possível liberar uma única célula, não é necessário esperar para liberar a lista toda, como na implementação por 
arranjos/vetores;
- Para remover ou adicionar uma célula, não é preciso deslocar as outras.

# Desvantagens da lista encadeada
- Não existe acesso por meio de índices, para encontrar uma célula é preciso percorrer a lista. 
- Usa mais memória, pois além do item, precisa guardar um ponteiro para a próxima célula.
- Quando se usa uma lista estática, ao utilizar um item da lista, toda a lista é carregada na memória cache, então quando algum outro item da lista precisar ser acessado, o acesso será mais rápido. Na lista encadeada, os itens ficam em blocos de memória independentes, então cada vez que um novo item precisar ser acessado ele terá que ser carregado.

# Links recomentados
- Série de vídeos sobre lista encadeada canal Linguagem C Programação Descomplicada: https://www.youtube.com/watch?v=0BDMqra4D94
- Valgrind - ferramenta para monitorar o uso da memória, entre outros: http://valgrind.org/docs/manual/QuickStart.html 
- Animação de uma lista encadeada: http://www.cs.armstrong.edu/liang/animation/web/LinkedList.html






