# Filas estáticas

Uma fila é um tipo de lista onde inserções são feitas ao final da lista e retiradas são feitas no início da lista. É como uma fila 
de pessoas no banco: uma nova pessoa sempre deve entrar no final da fila e a pessoa que chegou primeiro será a primeira a ser 
atendida.

Como o primeiro item a entrar na fila é o primeiro a ser retirado, uma fila é conhecida como uma estrutura do tipo **FIFO** 
(first in, first out - primeiro a entrar, primeiro a sair). Filas são estruturas úteis quando queremos processar itens de acordo 
com a ordem de chegada. Elas são fundamentais para o funcionamento de computadores. Sistemas operacionais usam filas para regular 
a ordem na qual as tarefas devem receber processamento ou recursos.

# TAD Fila

Geralmente uma fila contém as seguintes operações:
- Criar uma fila vazia;
- Inserir um novo elemento no final (enfileirar);
- Retirar o elemento do início (desenfileirar);
- Verificar se a fila está vazia;
- Verificar se a fila está cheia;
- Imprimir a fila.

# Implementação por arranjos ou vetores

Assim como as pilhas, filas podem ser implementadas usando arranjos/vetores ou  ponteiros. Primeiramente estudaremos as filas 
usando arranjos/vetores.

Antes de partirmos para códigos é preciso analisar alguns pontos. Como a operação de desenfileirar consiste em remover o primeiro item da fila, seria muito ineficiente ficar deslocando todos os itens da fila para à esquerda toda vez que um item precisar ser desenfileirado. Desta forma, em vez de faze esse deslocamento, vamos criar uma estrutura que mantém as informações do primeiro e do último. Teremos uma fila como ilustrado na figura abaixo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/fila_primeiro_ultimo.png)

Por causa da característica da fila, a operação de enfileirar faz aumentar a parte de trás da fila, enquanto a operação desenfileirar faz contrair a parte da frente da fila. Desta forma, a fila tende a caminhar pela memória, ocupando espaço da parte de trás e descartando espaço da parte da frente. Isso faz com que em poucas operações a fila vá ao encontro do limite de memória reservado para ela. 

Exemplo de uma fila contendo 3 itens e com capacidade máxima de 6 itens.

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/ocupa%C3%A7%C3%A3o_fila.png)

A fila fica inutilizável pois seu limite foi atingido, apesar de termos posições vazias na parte da frente da fila.  Uma solução 
para este inconveniente é imaginar a fila com um círculo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/fila_circular.png)

Fonte da imagem: Nívio Ziviani, Projeto de algoritmos com implementações Pascal e C, 4ª ed., 1999.

As estruturas para representar a fila são semelhantes às vistas anteriormente. Porém, conforme a ilustração acima, podemos ver a 
necessidade de guardar quem são o primeiro e último item da fila. Para facilitar também podemos armazenar o tamanho da fila:

```c
typedef struct item Item;
typedef struct fila Fila;

#define MAXTAM 5

struct item {
  int chave;
  // demais campos
};

struct fila {
  Item item[MAXTAM];
  int primeiro;
  int ultimo;
  int tamanho;
};

```

### Criação de fila vazia
Na função para criar a fila vazia, podemos considerar que o primeiro item é igual ao último item, que é igual a 0. O tamanho da fila também deve ser 0:

```c
Fila * cria_fila_vazia() {
  Fila *f = malloc(sizeof(Fila));
  f->primeiro = 0;
  f->ultimo = 0;
  f->tamanho = 0;
  return f;
}
```

### Verificação de fila vazia/cheia
Com o campo tamanho fica fácil verificar se  a fila está vazia ou cheia:

```c
int verifica_fila_vazia(Fila *f) {
  return f->tamanho == 0;
}

int verifica_fila_cheia(Fila *f) {
  return f->tamanho == MAXTAM;
}

```

### Enfileirar
Vamos agora pensar na função que insere um item no final da fila. Devido a implementação circular, isso requer alguns cuidados 
a mais em relação a pilha. Considere o cenário abaixo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/fila_circular_funcionamento.png)

- Ao adicionar o item de chave 8, o último passa a ser 4;
- Ao adicionar o item de chave 19, o último passa a ser 5;
- Ao adicionar o item de chave 2, o último passa a ser 0;
- Ao adicionar o item de chave 11, o último passa a ser 1.

Perceba que esses índices caminhando de forma circular podem ser obtidos pela fórmula:
ultimo = (ultimo + 1) % MAXTAM

- Ao adicionar o item de chave 8, o último passa a ser 4:

```diff
ultimo = (3 + 1) % 6 = 4 % 6 = 4
```

- Ao adicionar o item de chave 19, o último passa a ser 5:

```diff
ultimo = (4 + 1) % 6 = 5 % 6 = 5
```

- Ao adicionar o item de chave 2, o último passa a ser 0:

```diff
ultimo = (5 + 1) % 6 = 6 % 6 = 0
```
- Ao adicionar o item de chave 11, o último passa a ser 1:

```diff
ultimo = (6 + 1) % 6 = 7 % 6 = 1
```

Assim, podemos implementar a função de inserir um item no final da lista da seguinte forma:

```c
void enfileira(Fila* f, int chave) {
  if(verifica_fila_cheia(f)) {
        printf("Erro: a fila está cheia.\n");
    return;
  }
  Item novo_item;
  novo_item.chave = chave;
  f->item[f->ultimo] = novo_item;
  f->ultimo = (f->ultimo + 1) % MAXTAM;
  f->tamanho++;
}
```

### Imprimir fila 
Caminhando de forma circular para imprimir a fila:

```c
void imprime(Fila* f) {
  int t;
  int i = f->primeiro;
  for(t = 0; t < f->tamanho; t++) {
    printf("Chave: %d\n", f->item[i].chave);
    i = (i+1) % MAXTAM;
  }
}
```

### Desenfileirar
A mesma lógica pode ser usada na função de remoção do início para calcular o novo índice do primeiro item da fila:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/fila_circular_remo%C3%A7%C3%A3o.png)

- Ao remover o item de chave 20, o primeiro passa a ser 4:

```diff
primeiro = (3 + 1) % 6 = 4 % 6 = 4
```

- Ao remover o item de chave 8, o último passa a ser 5:

```diff
primeiro = (4 + 1) % 6 = 5 % 6 = 5
```

- Ao remover o item de chave 19, o último passa a ser 0:

```diff
primeiro = (5 + 1) % 6 = 6 % 6 = 0
```

Portanto o método desenfileira pode ser implementado da seguinte forma:

```c
void desenfileira(Fila* f) {
    if(verifica_fila_vazia(f)) {
        printf("Erro: a fila está vazia.\n");
        return;
  }
  f->primeiro = (f->primeiro + 1) % MAXTAM;
  f->tamanho--;
}
```

# Referências
- Capítulo sobre estruturas de dados básicas do livro Projeto De Algoritmos Com Implementações Em Pascal E C - Nivio Ziviani.
- Aplicação interativa sobre funcionamento de fila: https://www.cs.usfca.edu/~galles/visualization/QueueArray.html
