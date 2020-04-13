# Pilhas estáticas

Uma pilha é um tipo de lista onde inserções e retiradas são feitas sempre no final da lista. Imagine uma pilha de pratos: quando 
você guarda um prato, normalmente coloca o prato no topo da pilha. Quando você precisa pegar um prato, normalmente você retira o 
prato que está no topo da pilha.

Desta forma, o item colocado mais recentemente na pilha fica no topo, enquanto o item colocado menos recentemente fica no fundo. 
Assim, o último item colocado é o primeiro a ser retirado. Por essa característica a pilha é dita como uma estrutura do tipo 
**LIFO** (last in, first out - último a entrar, primeiro a sair).

Uma aplicação muito importante de pilhas está na própria na execução dos nossos programas. Todo programa em C consiste de uma ou 
mais funções. Em um programa com chamadas para várias funções, o computador usa uma pilha de execução para administrar as chamadas
de funções que vão sendo feitas. Considere o programa:

```c
#include <stdio.h>

int soma(int x, int y, int z) {
  int s;
  s = soma_aux(x, y);
  s = s + z;
  return s;
}

int soma_aux(int x, int y) {
  return x + y;
}

main() {
  printf("%d + %d + %d = %d", 2, 3, 5, soma(2, 3, 5));
}
```

Na função principal temos o objetivo de somar 3 números. Para isso é chamada a função soma().

- A função soma() tem o objetivo de somar 3 números, mas para isso ela precisa chamar a função soma_aux();
- A função soma_aux() soma 2 números e retorna o resultado para a função soma(). 
- A função soma() adiciona a esse resultado parcial o terceiro número e retorna para a função principal.

Pilha de execução do programa acima:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_1.png)
![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_2.png)
![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_3.png)
![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_4.png)
![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_5.png)
![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_6.png)
![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/pilha_exe_7.png)

Para simplicar, cada chamada de função foi representada por um retângulo na pilha. Na verdade, cada chamada é composta por um *frame* que contém os parâmetros da função, suas variáveis locais e endereço de retorno (para que a função soma_aux(), por exemplo, saiba que tem que retornar a resposta do cálculo para a função soma()).

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/frame_pilha_exe.png)

Fonte da imagem: https://en.wikipedia.org/wiki/Call_stack#/media/File:Call_stack_layout.svg

# TAD Pilha

Geralmente, uma pilha precisa das seguintes operações:

- Criar uma pilha vazia;
- Inserir um novo elemento no final (empilhar);
- Retirar o elemento do final (desempilhar);
- Verificar se a pilha está vazia;
- Verificar se a pilha está cheia;
- Imprimir a pilha;

# Implementação por arranjos ou vetores

A pilha é um tipo de lista. Vimos que listas podem ser estáticas (por meio de arranjos ou vetores) ou encadeadas. Vamos primeiramente estudar uma pilha usando vetores.

Esta implementação será muito parecida com a implementação da lista das aulas passadas. Na verdade, a implementação será bem mais simples, pois as inserções e retiradas de itens são feitas sempre no final da pilha. Isso quer dizer que não será necessário nos preocuparmos com deslocamento de itens.

Vamos utilizar a seguinte estrutura:

```c
typedef struct item Item;
typedef struct pilha Pilha;

struct item {
  int chave;
  // demais campos
};

struct pilha {
  Item item[MAXTAM];
  int topo;
};
```

O item continua igual na implementação da lista. Na estrutura pilha temos um vetor de itens e tempos também um campo chamado topo que indicará a posição do item que está no topo da pilha. 

### Criação de pilha vazia
A criação da pilha vazia será semelhante a criação da lista vazia. Novamente o -1 indicará que ainda não há nenhum item:

```c
// criar uma pilha vazia
Pilha * cria_pilha_vazia() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}
```

### Verificar pilha cheia
Antes de empilhar um novo item convém verificar se a pilha está cheia, de modo semelhante como foi feito na lista:

```c
// retorna 1 se a lista está cheia ou 0 se não está cheia
int verifica_pilha_cheia(Pilha *p) {
    return p->topo == MAXTAM - 1;
}
```

### Empilhar itens
A operação de empilhar é equivalente a operação de adicionar um item no fim da lista:

```c
// adicionar item (empilhar)
void empilha(Pilha *p, int chave) {
    if(verifica_pilha_cheia(p)){
        printf("Erro: a pilha está cheia.\n");
        return;
    }
    Item novo_item;
    novo_item.chave = chave;
    p->topo++;
    p->item[p->topo] = novo_item;
}
```

### Imprimir pilha
Com alguns itens inseridos, é interessante imprimir a pilha:

```c
// imprime a pilha
void imprime_pilha(Pilha *p) {
    int i;
    for(i = p->topo; i >= 0; i--) // -- imprimir na ordem de inserção
        printf("Chave: %d\n", p->item[i].chave);
}
```

### Verificar pilha vazia
Antes de desempilhar é conveniênte verificar se a pilha não está vazia:

```c
// retorna 1 se a pilha está vazia ou 0 se não está vazia
int verifica_pilha_vazia(Pilha *p) {
    return p->topo == -1;
}
```

### Desempilhar itens
A operação de desempilha remove o item que estava no topo da pilha. A nível de código basta decrementar o topo:

```c
// remover item (desempilhar)
void desempilha(Pilha *p) {
    if (verifica_pilha_vazia(p)) {
        printf("Erro: a pilha está vazia.\n");
        return;
    }
    p->topo--;
}
```

### Liberar pilha
Por fim, a liberação da memória ocupada pela pilha:

``` c
void libera_pilha(Pilha *p) {
    free(p);
}
```

### Exemplo de uso
``` c
main() {
  Pilha *p = cria_pilha_vazia();
  printf("Empilhando 5 itens:\n");
  empilha(p, 1);
  empilha(p, 2);
  empilha(p, 3);
  empilha(p, 4);
  empilha(p, 5);
  imprime_pilha(p);
  printf("\nTentando empilhar mais um item:\n");
  empilha(p, 6);
  printf("\nDesempilhando:\n");
  desempilha(p);
  imprime_pilha(p);
  printf("\nDesempilhando:\n");
  desempilha(p);
  imprime_pilha(p);
  printf("\nDesempilhando:\n");
  desempilha(p);
  imprime_pilha(p);
  printf("\nDesempilhando:\n");
  desempilha(p);
  imprime_pilha(p);
  printf("\nDesempilhando:\n");
  desempilha(p);
  imprime_pilha(p);
  printf("\nDesempilhando:\n");
  desempilha(p);
  imprime_pilha(p);
  libera_pilha(p);
}
```
# Aplicações de pilhas

### Notação polonesa inversa
Na notação tradicional de expressões matemáticas (notação infixa) o operador sempre aparece entre os seus dois operandos:
```diff
a + b
a - b * c
```
Já na notação pós-fixa, também conhecida como *notação polonesa inversa*, o operador é colocado após os seus dois operandos. Exemplos:

| Notação tradicional | Notação polonesa inversa |
| ------------------- | -------------------------|
| a-b                 | ab-                      |
| a-b*c               | abc*-                    |
| (a-b)*c             | ab-c*                    |
| a*(b+c)*(d-g)*h     | abc+*dg-&ast;h&ast;      |

Neste tipo de notação os parênteses são dispensados. A ordem das operações é dada pela ordem em que os operadores aparecem. Por exemplo:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/notacao_polonesa_inversa.png)

A notação polonesa ganhou destaque na década de 70, por sua adoção nas calculadoras HP.

Esse tipo de notação pode ser facilmente resolvido usando uma estrutura do tipo pilha. Considere a expressão: 
```diff
5 + (1 + 2) * 4 - 3
```
que na notação polonesa inversa fica:
```diff
5 1 2 + 4 * + 3 -
```
Percorrendo a expressão da esquerda para a direita: cada vez que aparece um número, empilhamos. Cada vez que aparece um operador, desempilhamos os dois últimos números, calculamos o resultado da operação e empilhamos o resultado:

| Próximo | Operações necessárias                                       | Pilha   | 
| ------- | ----------------------------------------------------------- | ------- |
| 5       | empilha(5)                                                  | 5       |
| 1       | empilha(1)                                                  | 5, 1    |
| 2       | empilha(2)                                                  | 5, 1, 2 |
| +       | desempilha(2), desempilha(1), soma(1, 2), empilha(3)        | 5, 3    |
| 4       | empilha(4)                                                  | 5, 3, 4 |
| *       | desempilha(4), desempilha(3), multiplica(3, 4), empilha(12) | 5, 12   |
| +       | desempilha(12), desempilha(5), soma(5, 12), empilha(17)     | 17      |
| 3       | empilha(3)                                                  | 17, 3   |
| -       | desempilha(3), desempilha(17), subtrai(17, 3), empilha(14)  | 14      |

O item final da pilha é o resultado da expressão.

### Balanço de parênteses
Expressões matemáticas frequentemente contém parênteses (), colchetes [] e chaves {}. Para a expressão estar bem formada, todos os símbolos abertos tem que ser fechados. 

Exemplos de combinações bem formadas:
```diff
( ( ) [ ( ) ] )
( ( ( [ ] ) ( ) ) [ ] )
( { ( ) } [ ] )
```
Exemplos de combinações mal formadas:
```diff
( [ ) ]
( ( ( [ ] ) ( ) ) [ )
{ ( } ( ( [ ] ) )
```

Esse tipo de problema também pode ser facilmente resolvido com auxílio de uma estrutura do tipo pilha. Toda vez que for aparecer um símbolo (, [ ou { (abrindo), o símbolo é implilhado. Toda vez que aparecer um símbolo ), ] ou } (fechando), verificamos o topo da pilha: se o símbolo combina com o símbolo que está no topo da pilha, desempilhammos, se não quer dizer que temos uma inconsistência e podemos encerrar a verificação, pois a expressão não é bem formada. 

Ex.: ( ( ( [ ] ) ( ) ) [ ] )


| Próximo | Operações necessárias | Pilha | 
| ------- | --------------------- | ----- |
| ( | empilha ( | ( |
| ( | empilha ( | ( ( |
| ( | empilha ( | ( ( ( |
| [ | empilha [ | ( ( ( [ |
| ] | desempilha [ | ( ( ( |
| ) | desempilha ( | ( ( |
| ( | empilha ( | ( ( ( |
| ) | desempilha ( | ( ( |
| ) | desempilha ( | ( |
| [ | empilha [ | ( [ |
| ] | desempilha [ | ( |
| ) | desempilha ( | |

A pilha resultante está vazia, isso quer dizer que para cada símbolo aberto, havia um símbolo fechado na posição esperada. Logo, a expressão está bem formada.

Ex.: ( [ ) ]

| Próximo | Operações necessárias | Pilha | 
| ------- | --------------------- | ----- |
| ( | empilha ( | ( |
| [ | empilha [ | ( [ |
| ) | ) não combina com o topo [, para | ( [ |

A pilha resultante não está vazia, então a expressão não está bem formada.

# Materiais recomendados

- Capítulo sobre estruturas de dados básicas do livro Projeto De Algoritmos Com Implementações Em Pascal E C - Nivio Ziviani.
- Aplicação interativa sobre funcionamento de pilha: https://www.cs.usfca.edu/~galles/visualization/StackArray.html. 
