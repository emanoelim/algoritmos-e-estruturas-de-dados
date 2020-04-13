# Exercícios com listas estáticas

1) Crie uma função que permite adicionar um item em uma posição qualquer da lista.

___

2) Crie uma função que insere os itens em uma lista de forma ordenada.

___

3) Altere a função que adiciona um item no fim da lista para que não seja permitido adicionar itens repetidos (itens com chaves/códigos iguais).

___

4) Crie uma função chamada copia_lista que recebe duas listas. A primeira deve ser uma lista vazia e a segunda não. A função deve copiar os itens da segunda lista na primeira lista.

___

5) Crie uma função que recebe duas listas. Considere que dentro de uma lista não existem itens repetidos (você já tratou para que não seja permitido adicionar itens iguais). Sua função deve retornar uma terceira lista que representa a intersecção entre as duas listas recebidas.

___

6) Crie uma função que recebe duas listas. Considere que dentro de uma lista não existem itens repetidos. Sua função deve retornar uma terceira lista que representa a união entre as duas listas recebidas. Assegure-se de que a terceira lista não tenha itens repetidos.

___

7) Crie uma função que percorre uma lista de números inteiros e diz se ela está ordenada ou não.

___

8) A struct abaixo representa um aluno da disciplina de Estruturas de dados: 
```c
struct aluno {
  int cod;
  char nome[30];
  float notas[3];
  float media;
};
```

Crie um TAD Aluno baseado nessa estrutura. O TAD deve conter funções básicas como criar uma lista vazia, cadastrar um aluno na lista, etc. Além disso:
- Crie uma função para calcular a média de cada aluno com base nas suas 3 notas;
- Crie uma função que recebe uma lista alunos e duas outras listas vazias, L1 e L2. Percorra a lista de alunos, colocando todos os alunos com notas menores que 6,0 em L1 e todos os alunos com notas maiores ou iguais a 6,0 em L2.
___

9) Você está prestes a fazer uma viagem rodoviária e quer estimar quanto irá gastar. Você considera dois tipos de custos: o custo de cada quilômetro percorrido na rodovia (consumo de combustível, desgaste dos pneus, etc.) e o custo com os pedágios. A estrutura "pedagio" abaixo, guarda a distância em quilômetros onde existe um pedágio e também o valor do pedágio:
```c
struct pedagio {
  int km;
  float valor;
};
```
Escreva um programa que solicita a distância e o valor de cada pedágio do trajeto e armazena esses dados em uma lista. Leia também o custo por quilômetro percorrido. Calcule o custo total da viagem e mostre a distância do pedágio mais caro, bem como seu valor.

Exemplo:
```diff
Primeiro pedágio: km 37, valor = R$ 10,00
Segundo pedágio: km 74, valor = R$ 12,00
Terceiro pedágio: km 111 = R$ 11,00
Custo por quilometro percorrido: R$ 2,00

Custo total da viagem: R$ 255,00
Pedágio mais caro: km 74, R$ 12,00
```
