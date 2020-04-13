# Tabela hash

Muitos métodos de busca baseiam-se em comparação de chaves para encontrar um algum dado. Se os dados estiverem ordenados, este 
tipo de busca pode ter um custo O(log<sub>2</sub>n). Seria possível encontrar um elemento sem a necessidade de comparar chaves, 
a custo constante - O(1)?

Sabemos que em vetores, conseguimos acessar um dado de forma direta através de um índice, com custo O(1). Entretanto, como não 
temos como saber em qual índice cada dado está, e nem sempre os dados estão ordenados, normalmente precisamos fazer uma busca sequencial, que tem custo O(n).

As tabelas de hash (tabelas de espalhamento, tabelas de dispersão) são uma solução para este problema. Uma tabela hash associa 
chaves e valores:
- Chave: uma parte da informação que compõe o item a ser inserido ou buscado.
- Valor: índice ou posição onde o item deve ficar na tabela (vetor).

A tabela hash usa uma função que tem como entrada a chave. Com base nessa chave, a função calcula um valor que será a posição onde 
o item deve ser guardado. Este processo chama-se “espalhar” (hash, em inglês, quer dizer “confusão”).

Esta mesma função é usada durante uma busca. Assim, a partir da chave do item, será possível calcular a posição onde ele está 
guardado, recuperando-o a um custo constante.

A figura abaixo representa um exemplo de mapeamento de chaves (neste caso, a chave usada foi o nome da pessoa), em posições na
tabela.

![all text](https://upload.wikimedia.org/wikipedia/commons/7/7d/Hash_table_3_1_1_0_1_0_0_SP.svg)

Fonte da imagem: Jorge Stolfi, "A small phone book as hash table", disponível em:
https://en.wikipedia.org/wiki/Hash_table#/media/File:Hash_table_3_1_1_0_1_0_0_SP.svg)

## Funções de Hasing

Uma função de hashing tem como objetivo pegar uma chave e mapear esta chave em uma posição. Existem diferentes possibilidades 
para implementar a função de hashing, porém deve-se considerar que: se a ideia de uma tabela hash é que um item possa ser mapeado 
e recuperado de maneira rápida, a função de hashing deve ser simples. Abaixo são apresentados algumas funções de hashing bastante
conhecidas.

### Divisão

Encontra-se o resto da divisão da chave pelo tamanho máximo da tabela, e usa-se este resto como posição. Preferencialmente, 
o tamanho da tabela deve ser um número primo, para diminuir a possibilidade de gerar a mesma posição para chaves diferentes 
(colisão). 

### Multiplicação
1. Selciona-se uma constante c, tal que 0 < c < 1. 
2. Multiplica-se a chave por esta constante;
3. Seleciona-se a parte fracionária desta multiplicação;
4. A parte fracionária é multiplicada pelo tamanho da tabela;
5. A parte inteira desta multiplicação é usada como posição.

### Dobra
A chave é interpretada como uma sequência de dígitos escrita em um papel. Enquanto a chave for maior do que o tamanho da tabela, 
o papel vai sendo dobrado ao meio e os dígitos que se sobrepõe são somados sem levar em consideração o “vai um”. 
Calcula-se o resto da divisão da soma pela tabela para usar como chave:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/hash_dobra.png)

Fonte da imagem: Backes, André Ricardo, Estruturas de dados descomplicada: em linguagem C, 1ª ed., Rio de Janeiro: Elsevier, 2016.

### Hashing universal

Qualquer função hash está sujeita ao problema de criar chaves iguais para itens diferentes. Dependendo da entrada, 
algumas funções hash podem espalhar os elementos de forma mais equilibrada que outras. Desta forma, se pudermos utilizar 
diferentes funções hash, o espalhamento será mais equilibrado.

Além disso, se a função de hashing for conhecida, é possível que alguma pessoa má intencionada tente inserir chaves de modo que 
sempre acontecem colisões, fazendo a complexidade subir para O(n), como será visto adiante.
    
Na estratégia de hashing universal, uma função de hashing é gerada aleatoriamente em tempo de execução. Um exemplo de função de 
hashing universal é apresentado abaixo:

Considerando que:
- m = tamanho da tabela
- k = chave

A função é construída da seguinte forma:
1. Selecionar um número primo para m.
2. Decompor k em r + 1 dígitos.
3. Selecionar aleatoriamente uma sequencia de r + 1 números entre 0 e m - 1 (a0, a1, …, ar).
4. A família de funções de hashing é dada por:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/hash_universal.png)

Veja aqui uma estratégia para gerar números primos para utilziar na função: 
https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/

Obs.: quando falamos que a função de hashing é gerada aleatoriamente em tempo de execução, não significa que a cada item inserido,
uma função diferente é usada. Significa que a sequência de números que será usada pela função não é conhecida previamente. 
Ela será criada durante a execução do programa.

### Hashing com strings

Também é possível usar uma string como chave para gerar uma posição. Intuitivamente, poderíamos pensar em somar os códigos ASCII 
de cada caractere da string. O problema é que palavras como “cama” e “maca” iriam ter a mesma soma e gerar a mesma posição, 
provocando colisão. Por isso, temos que fazer uma  abordagem um pouco diferente.

Uma ideia seria pegar o código ASCII de cada caractere e multiplicá-lo por um número inteiro na base 256. Por exemplo, para 
mapear a string “abcd”, teríamos:

97 * 256^3 + 98 * 256^2 + 99  * 256^1 + 100 * 256^0 = 1633837924

Em seguida, encontra-se o resto do resultado pelo tamanho da tabela.

## Funções perfeitas e imperfeitas

Funções de hash podem ser classificadas como “perfeitas” e “imperfeitas”.

### Perfeitas
Chaves diferentes sempre produzem posições diferentes. Não é necessário tratar colisões. O o custo para inserção 
e busca será, no pior caso, O(1). Esse tipo de hashing é usado quando colisões não são toleráveis e encaixam-se em aplicações 
muito específicas, onde já sabemos previamente quais serão as possíveis entradas.

### Imperfeitas
Colisões são indesejáveis (elas irão diminuir o desempenho do algoritmo) mas são permitidas. Como colisões podem acontecer, 
pode ser que chaves diferentes sejam mapeadas para uma mesma posição. Então, será necessário usar alguma outra estrutura de 
dados para fazer o tratamento destas colisões. Este será o caso da maioria das aplicações.

## Exemplo de implementação sem tratamento de colisões

Abaixo é apresentada uma implementação de tabela hash em C. Esta é uma é uma implementação bem simples, que não trata colisões. 
Ela tem como objetivo passar um entendimento sobre o mapeamento de chaves em posições. A estrutura usada será a seguinte:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/estrutura_implementacao_hash.png)

Em C ela pode ser representada por:
```c
typedef struct item Item;
typedef struct hash Hash;

struct item {
  int chave;
  // demais campos
};
struct hash {
  int qtd;
  Item **itens;
};
```

Optou-se nesse exemplo, representar cada posição na tabela como um ponteiro para um item. Desta forma a mesma estrutura pode ser usada em uma implementação com tratamento de colisões por endereçamento aberto ou endereçamento separado, como será visto adiante.

O próximo passo é a criação de uma tabela vazia, onde alocamos memória para a tabela, alocamos memória para o vetor de ponteiros e inicializamos cada ponteiro da lista com NULL.

```c
Hash * cria_tabela() {
  int i;
  Hash *h = malloc(sizeof(Hash));
  h->qtd = 0;
  h->itens = malloc(TABLESIZE * sizeof(Item*));
  for(i = 0; i < TABLESIZE; i++)
    h->itens[i] = NULL;
  return h;
}
```
A liberação da tabela pode ser feita da seguinte forma:
```c
void libera_tabela(Hash *h) {
  if(h != NULL) {
    int i;
    for(i = 0; i < TABLESIZE; i++) {
        free(h->itens[i]);
    }
    free(h->itens);
    free(h);
  }
}
```

Na sequência, vamos implementar uma função de hashing. Para exemplificar vamos usar a abordagem de divisão:
```c
int hashing(int chave) {
  return chave % TABLESIZE;
}
```

Antes de fazer a inserção de algum item usando esta função, é conveniente ter uma verificação para ver se a tabela não está cheia:
```c
int verifica_tabela_cheia(Hash *h) {
  return h->qtd == TABLESIZE;
}
```

Finalmente, criamos uma função para inserção. A função recebe um item a ser inserido. Caso a tabela tenha sido criada com 
sucesso (não aponta para NULL) e caso a tabela ainda tenha posições vagas, a posição é calculada com base em uma parte da informação a ser guardada e é feita a inserção do item na posição calculada (lembrando de atualizar o campo que indica a quantidade de itens).
```c
void insere_sem_tratar_colisao(Hash *h, Item *item) {
  if(h == NULL || verifica_tabela_cheia(h)) {
    printf("Erro: erro de memória ou tabela cheia.\n");
    return;
  }
  int chave = item->chave; // usa parte da informação como chave, poderia ser qualquer campo
  int posicao = hashing(chave);
  h->itens[posicao] = item;
  h->qtd++;
}
```
Agora que é possível inserir itens, podemos pensar em uma função para mostrar como está a tabela:
```c
void imprime_tabela(Hash *h) {
  int i;
  for(i = 0; i < TABLESIZE; i++) {
    if(h->itens[i] == NULL)
      printf("%d - NULL\n", i);
    else
      printf("%d - %d\n", i, h->itens[i]->chave);
  }
}
```

Por fim, a função de busca pode ser implementada da seguinte forma:
```c
Item * busca_sem_tratar_colisao(Hash *h, int chave) {
  if(h == NULL) {
    printf("Erro: tabela vazia.\n");
    return NULL;
  }
  int posicao = hashing(chave);
  if(h->itens[posicao] == NULL) {
    printf("Erro: chave não encontrada.\n");
    return NULL;
  }
  else {
    return h->itens[posicao];
  }
}
```

Obs.: esta implementação considera o “caminho feliz”, e supõe que nunca aconteceria uma colisão, o que não é verdade. Ela tem meramente objetivo de mostrar como funciona o mapeamento e recuperação de chaves.

## Referências
- Backes, André Ricardo, **Estruturas de dados descomplicada: em linguagem C**, 1ª ed., Rio de Janeiro: Elsevier, 2016.



