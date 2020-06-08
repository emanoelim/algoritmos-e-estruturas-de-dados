# Complexidade de algoritmos recursivos

Encontrar a complexidade de tempo de um algoritmo recursivo não é tão intuitivo como em algoritmos não recursivos. Precisamos
montar uma **relação de recorrência**, uma equação em que cada termo é definido em função dos termos anteriores. 

### Exemplo do fatorial recursivo

Abaixo tem-se o código da função fatorial_rec:
```c
int fatorial_rec(int n) {
  if(n == 1) 
    return 1;
  else 
    return n * fatorial_rec(n - 1);
}
```

A partir desse código, podemos deduzir que quando n é 1, o custo da função fatorial_rec é constente, ou seja, O(1). Portanto
temos que:

T(1) = c

Para outros valores de n, o custo da função será a soma dos custos constantes (vamos chamar de c) mais a custo para chamar a função
para n - 1. Portanto temos:

T(n) = c + T(n - 1)


Desta forma relação de recorrência da função pode ser descrita como:

T(n) = c + T(n - 1)

T(1) = c


Resolvendo alguns termos dessa relação:

T(n) = c + T(n - 1)

T(n - 1) = c + T(n - 2)

T(n - 2) = c + T(n - 3)

T(n - 3) = c + T(n - 4)

…

T(n - (n - 1)) = T(1) = c

Reorganizando:

T(n) = c + <s>T(n - 1)</s>

<s>T(n - 1)</s> = c + <s>T(n - 2)</s>

<s>T(n - 2)</s> = c + <s>T(n - 3)</s>

<s>T(n - 3)</s> = c + <s>T(n - 4)</s>

…

<s>T(1)</s> = c

Somando os termos que não foram cortados:

T(n) = c + c + c + c + … 

T(n) = n * c 

T(n) = n

T(n) = **O(n)**

Quanto a complexidade de espaço, vamos analisar a pilha de chamadas da função. Considere, por exemplo, que n = 5:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/pilha_fatorial_rec.png)

Sendo n = 5, é possível ver no passo 5, que até n chamadas da função ocupam a pilha de execução do programa. Cada chamada precisa guardar informações como endereço de retorno, parâmetros e variáveis locais da função. Para guardar essas informações o custo sempre será o mesmo (constante). O que vai definir a complexidade de espaço da função é a quantidade máxima de chamadas ocupando a pilha, que é O(n).

### Exemplo da soma dos N primeiros números recursiva

Analise o código:
```c
int soma_n_rec(int n){
  if(n == 1)
    return 1;
  else 
    return n + soma_n_rec(n - 1);
}
``` 
Quando n é 1, temos:

T(1) = c

Quando n é diferente de 1, temos que considerar os custos constantes mais o custo de chamar a função para n - 1, ou seja:

T(n) = c + T(n - 1)

Resultado na relação de recorrência:

T(n) = c + T(n - 1)

T(1) = c

Que é a mesma relação do exemplo anterior, sendo resolvida da mesma maneira. Para a análise da complexidade de espaço também podemos considerar o exemplo onde n = 5, constantando que o número máximo de chamadas na pilha também será n. Ou seja esta função  terá complexidade de tempo O(n) e complexidade de espaço O(n).

### Exemplo do Fibonacci recursivo

Considere o código:
```c
int fib_rec(int x){
    if(x == 0)
            return 0;
    if(x == 1)
            return 1;
    else
            return fib_rec(x - 1) + fib_rec(x - 2);
}
```

Sabemos que quando n é 0 ou 1 o custo é constante, portanto:

T(1) = T(0) = c

Quando n é qualquer outro valor, temos que considerar, além dos custos contantes, o custo para chamar a função para n - 1 e para n - 2, logo:

T(n) = c + T(n - 1) + T(n - 2)

a relação de recorrência será:

T(n) = c + T(n - 1) + T(n - 2)
T(1) = c

Esta relação de recorrência pode ser simplificada considerando que T(n - 2) será no máximo tão custosa quanto T(n - 1), então teremos:

T(n) = c + 2T(n - 1)

T(1) = c

Resolvendo alguns termos:

T(n) = c + 2T(n - 1)

2T(n - 1) = 2c + 4T(n - 2)

4T(n - 2) = 4c + 8T(n - 3)

8T(n - 3) = 8c + 16T(n - 4)

…

É possível identificar um padrão: todos os termos são precedidos por potências de 2:

2<sup>0</sup>T(n - 0) = 2<sup>0</sup>c + 2<sup>1</sup>T(n - 1)

2<sup>1</sup>T(n - 1) = 2<sup>1</sup>c + 2<sup>2</sup>T(n - 2)

2<sup>2</sup>T(n - 2) = 2<sup>2</sup>c + 2<sup>3</sup>T(n - 3)

2<sup>3</sup>T(n - 3) = 2<sup>3</sup>c + 2<sup>4</sup>T(n - 4)

…

2<sup>n - 1</sup>T(n - (n - 1)) = 2<sup>n - 1</sup>c (caso base)

Reorganizando:

2<sup>0</sup>T(n - 0) = 2<sup>0</sup>c + <s>2<sup>1</sup>T(n - 1)</s>

<s>2<sup>1</sup>T(n - 1)</s> = 2<sup>1</sup>c + <s>2<sup>2</sup>T(n - 2)</s>

<s>2<sup>2</sup>T(n - 2)</s> = 2<sup>2</sup>c + <s>2<sup>3</sup>T(n - 3)</s>

<s>2<sup>3</sup>T(n - 3)</s> = 2<sup>3</sup>c + <s>2<sup>4</sup>T(n - 4)</s>

…

<s>2<sup>n - 1</sup>T(n - (n - 1))</s> = 2<sup>n - 1</sup>c

Somando todos os termos que não foram cortados:

T(n) = 2<sup>0</sup>c + 2<sup>1</sup>c + 2<sup>2</sup>c + ... + 2<sup>n - 1</sup>c 

Ou seja, teremos um somatório:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/sum1.png)

Para facilitar a resolução vamos considerar que m = n - 1, assim o somatório pode ser reescrito como:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/sum2.png)

Vamos aplicar a técnica da perturbação para resolver o somatório. Esta técnica consiste em "perturbar” o somatório adicionando um termo a mais e então reescrever o somatório como:
- Primeiro termo + somatório dos próximos termos;
- Último termo + somatório dos termos anteriores.

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/sum3.png)

Sendo assim, é possível dizer que:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/sum4.png)

Logo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/sum5.png)

Ou seja, a complexidade de tempo é fatorial, O(2<sup>n</sup>).

A complexidade de espaço também pode ser analisada através da pilha de chamadas. Para n = 5:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/pilha_fib_2.png)

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/pilha_fib_1.png)

Existem situações onde até n chamadas ocupam a pilha, portanto, pode-se dizer que a complexidade de espaço é O(n).




