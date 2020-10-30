# Endereços de memória

Quando declaramos uma variável na linguagem C, precisamos informar seu tipo, seu nome, e em algum momento, lhe atribuímos um valor. Por exemplo:

```c
int n = 10;
char c = 'a';
```

Além de estar associada a um tipo, um nome e um valor, uma variável também está associada a um endereço de memória.
O desenho abaixo traz a representação da memória de um computador, onde cada retângulo representa 1 byte. À esquerda de cada retângulo está o seu endereço de memória.

![alt text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/representacao_memoria.png)

Quando a variável:

```c
char c = 'a';
```

é declarada, ela é guardada em algum lugar da memória do computador, por exemplo:

![alt text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/memoria_char.png)

Uma variável do tipo char ocupa apenas 1 byte, portanto, no exemplo acima, a variável “c” ocupa a posição 1000. Dizemos então, que o endereço de “c” é 1000.

Considere agora uma variável do tipo int:

```c
int n = 10;
```

Uma variável do tipo int, na maioria dos computadores atuais, ocupa 4 bytes:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/memoria_int.png)

No exemplo acima, a variável “n” ocupa os endereços 1001, 1002, 1003 e 1004. Quando uma variável ocupa mais do que um endereço na memória, dizemos que o seu endereço é onde ela começa, ou seja, o primeiro endereço ocupado por ela. Neste exemplo, endereço de memória da variável “n” é 1001. 

O mesmo vale para um vetor ou matriz. O endereço de um vetor, por exemplo, sempre será onde ele “começa”, ou seja o primeiro endereço ocupado por ele.

# Verificando o tamanho de um tipo de dado em C

Para verificar o tamanho de um tipo de dados, a linguagem C possui o operador sizeof. Ele retorna um número inteiro que representa a quantidade de bytes usada pelo tipo de dado. Exemplos:

```c
#include <stdio.h>

typedef struct aluno Aluno;
struct aluno {
    char nome[20];
    int RA;
    float coeficiente;
}

main() {
    printf("char: %d\n", sizeof(char));
    printf("int: %d\n", sizeof(int));
    printf("float: %d\n", sizeof(float));
    printf("Aluno: %d\n", sizeof(Aluno)); // funciona também com novos tipos
}
```

A saída do programa será:
```diff
char: 1
int: 4
float: 4
Aluno: 28
```

# Verificando o endereço de uma variável na linguagem C
   
Na linguagem C estamos acostumados a acessar os valores das variáveis, na hora de exibir seus valores, por exemplo:

```c
printf("O valor da variável c é: %c\n", c);
printf("O valor da variável n é: %d\n", n);
```

E se quiséssemos saber os endereços das variáveis “c” e “n” em vez de seus valores? Para isso existe o operador de endereço, representado pelo símbolo “&”. Quando colocado do lado esquerdo de uma variável, em vez de termos o valor da variável, temos o seu endereço na memória. O exemplo abaixo mostra essa diferença:

```c
#include <stdio.h>

int main() {
    char c = 'a';
    int n = 50;

    printf("O valor da variável c é: %c\n", c);
    printf("O valor da variável n é: %d\n", n);

    printf("O endereço da variável c é: %ld\n", &c);
    printf("O endereço da variável n é: %ld\n", &n);
}

```
A saída do programa deve ser parecida com o exemplo abaixo:
```diff
O valor da variável c é: a
O valor da variável n é: 50
O endereço da variável c é: 2686735
O endereço da variável n é: 2686728
```

Perceba que usamos o mesmo & do scanf:

```c
int x;
printf("Informe o valor de x: ");
scanf("%d", &x);
```

Os argumentos básicos da função scanf são: o tipo do valor que será lido e o endereço onde esse valor será guardado.

# Tipo ponteiro

Na linguagem C, existem variáveis que podem guardar endereços em vez de valores. Essas variáveis são chamadas **ponteiros** ou **apontadores**. 

Esse tipo de variável possui uma declaração especial. O nome da variável deve estar precedido por um asterisco para indicar que ela vai guardar um endereço de memória e não um valor:

```diff
tipo *nome_variavel;
```
ou:

```diff
tipo* nome_variavel;
```

ou ainda:

```diff
tipo * nome_variavel;
```

As 3 formas são aceitas pela linguagem C. Leia mais em: https://www.ime.usp.br/~pf/algoritmos/aulas/footnotes/pointer-decl.html.

Abaixo, um exemplo de declaração de um ponteiro para um inteiro:

```c
int *p;

```

# O operador & - “o endereço de”

Agora vamos passar o endereço de “n” para o ponteiro “p”. Como “p” não vai guardar o valor, mas sim o endereço de “n”, a variável “n” deve estar precedida por um “&”:

```c
p = &n;
```

Como “p” guarda o endereço da variável “n”, podemos dizer que **“p” aponta para “n”**. 

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/memoria_ponteiro.png)

No código abaixo, os dois últimos printf irão imprimir o mesmo valor, que é o endereço de “n”. O endereço será um número inteiro, que pode ser um número grande. Por isso, usamos “%ld” no printf, de long int.

```c
#include <stdio.h>

main() {
    int n = 10; 
    int *p; 
    p = &n; // p guarda o endereço de n, ou seja, p aponta para n;
    printf("Valor de n: %d\n", n);
    printf("Endereco de n: %ld\n", &n);
    printf("Valor de p: %d\n", p);
}
```

# O operador * - “no endereço… “ 

Quando um ponteiro aponta para um endereço de memória, a operação para acessar o conteúdo desse endereço é chamada de deferência. O operador utilizado é o asterisco. Teste o código abaixo:

```c
#include <stdio.h>

main() {
    int i = 10;
    char c = 'a';
    int *pi = &i;
    char *pc = &c;
    printf("O valor de i é: %d\n", i);
    printf("O valor de c é: %c\n", c);
    printf("O endereço de i é: %ld\n", &i);
    printf("O endereço de c é: %ld\n", &c);
    printf("pi aponta para o endereço de i, que é: %ld\n", pi);
    printf("pc aponta para o endereço de c, que é %ld\n", pc);
    printf("No endereço apontado por pi está o conteúdo: %d\n", *pi);
    printf("No endereço apontado por pc está o conteúdo: %c\n", *pc);
}
```

A saída do programa deve ser parecida com o exemplo de saída abaixo:
```diff
O valor de i é: 10
O valor de c é: a
O endereço de i é: 2686724
O endereço de c é: 2686723
pi aponta para o endereþo de i, que é: 2686724
pc aponta para o endereço de c, que é 2686723
No endereço apontado por pi está o conteúdo: 10
No endereço apontado por pc está o conteúdo: a

```

O código abaixo mostra que quando queremos mexer no endereço apontado por px, usamos apenas px. Quando queremos mexer no conteúdo apontado por px, usamos o operador de deferência antes de px. Ao alterar o conteúdo do endereço, automaticamente a variável associada à aquele endereço reflete a alteração.
```c
#include <stdio.h>

main() {
    int x = 10;
    int *px = &x; // o ponteiro px recebe o endereço da variável x
    printf("Valor de x: %d\n", x);
    printf("px aponta para x, que esta no end.: %ld\n", px);

    *px = 20; // alteramos o conteúdo guardado no endereço apontado por px
    printf("px ainda aponta para o end.: %ld\n", px);
    printf("O conteúdo do endereço apontado por px foi alterado, logo, x passou a valer: %d", x);
}
```

# Cuidados ao fazer atribuições

```c
...
int i = 10;
char c = 'a';

int *p;
int *pi;
char *pc;

pi = &i; // Ok
pc = &c; // Ok
pi = pc; // Warning: os ponteiros não são do mesmo tipo (pi é int* e pc é char*)
pi = i; // Warning: ponteiro recebendo um valor, não um endereço
*p = 10; // Erro: p não está inicializado, ou seja, ainda não está associado a nenhum endereço, não é possível receber um conteúdo
...
```

## Atenção
A última instrução do trecho de código acima mostra uma situação muito comum quando estamos aprendendo sobre ponteiros. No exemplo,
esquecemos de associar o ponteiro **p** a um endereço de memória e então tentamos fazer uma operação de deferência em um ponteiro
que ainda não aponta para lugar algum. Isso irá gerar um erro.

Para corrigir o problema, antes de fazer *p = 10, devemos fazer p apontar para algum lugar:
```c
p = &i; // p aponta para i
*p = 10; // agora é possível fazer a op. de deferência, pois já existe um endereço associado a p, onde o valor 10 pode ser guardado
```

# Aritmética com ponteiros

Com ponteiros é possível fazer apenas operações de soma, subtração e comparação. Exemplo de soma:

```c
#include <stdio.h>

int main() {
    int i = 10;
    int *pi = &i;
    printf("O endereço apontado por pi é: %ld\n", pi);
    printf("O conteúdo apontado por pi é: %d\n", *pi);
    pi = pi + 1;
    printf("O endereço apontado por pi agora é: %ld\n", pi);
}
```
Saída:
```diff
O endereço apontado por pi é: 2686728
O conteúdo apontado por pi é: 10
O endereço apontado por pi agora é: 2686732
```

Ao fazer a adição pi = pi + 1, estamos adicionando uma unidade ao endereço e não o valor 10. O endereço resultante está 4 endereços a frente, uma vez que um tipo int ocupa 4 bytes. Se imprimirmos o valor contido no endereço resultante, teremos um valor de pouca utilidade, visto que o endereço pode conter algum lixo de memória.

Podemos perceber que a operação de soma no exemplo acima não tem muito sentido prático. Uma aplicação mais útil sobre operações de soma e subtração pode ser mostrada com vetores, como será visto em breve.

Comparações entre ponteiros só terão algum sentido quando forem feitas sobre ponteiros que apontam para o mesmo objeto:

```c
#include <stdio.h>

int main() {
    int x, y, *p1, *p2;
    x = 5;
    y = 6;
    p1 = &x; // p1 aponta para x
    p2 = &y; // p2 aponta para y
    printf("p1 e p2 são iguais? %d\n", p1 == p2); // não apontam para o mesmo objeto
    p1 = &x; // p1 aponta para x
    p2 = &x; // p2 também aponta para x
    printf("p1 e p2 são iguais? %d\n", p1 == p2 // apontam para o mesmo objeto
}
```
Saída:
```diff
p1 e p2 são iguais? 0
p1 e p2 são iguais? 1
```

# Ponteiros e vetores

 Quando declaramos o vetor "v":
 
 ```c
 int v[] = {1, 2, 3, 4, 5};
 
 ```
 
 O nome "v" nada mais é do que um ponteiro para o primeiro endereço ocupado pelo vetor. Você pode perceber isso pelo exemplo abaixo:
 ```c
 #include <stdio.h>

int main() {
    int v[] = {1, 2, 3, 4, 5};
    printf("v: %ld\n", v); // v guarda o primeiro endereço ocupado pelo vetor

    printf("endereço de v[0]: %ld\n", &v[0]);
    printf("endereço de v[1]: %ld\n", &v[1]);
    printf("endereço de v[2]: %ld\n", &v[2]);
    printf("endereço de v[3]: %ld\n", &v[3]);
    printf("endereço de v[4]: %ld\n", &v[4]);
}
 ```
 Cuja saída é:
 ```difff
v: 2686716
endereço de v[0]: 2686716
endereço de v[1]: 2686720
endereço de v[2]: 2686724
endereço de v[3]: 2686728
endereço de v[4]: 2686732
 ```

Perceba que o primeiro e o segundo printf mostram o mesmo valor, ou seja, o nome "v" guarda exatamente o primeiro endereço de memória
ocupado pelo vetor, ou seja, o endereço do v[0].
 
# Aritmética de ponteiros e vetores

A aritmética de ponteiros é útil para percorrer um vetor:
 
```c
#include <stdio.h>

int main() {
    short int a[] = {20, 30, 40, 50, 60};
    short int *p = a; // como o nome a já é um ponteiro, não precisamos colocar o &
    
    printf("p aponta para o endereço: %ld\n", p); // endereço de v[0]
    printf("O valor guardado no endereço acima é: %d\n", *p); // valor em v[0]
    
    p = p + 2;
    printf("p aponta para o endereço: %ld\n", p); // endereço de v[2]
    printf("O valor guardado no endereço acima é: %d\n", *p); // valor em v[2]
    
    p = p - 1;
    printf("p aponta para o endereço: %ld\n", p); // endereço de v[1]
    printf("O valor guardado no endereço acima é: %d\n", *p); // valor em v[1]
}
```
É possível ver que ao adicionar uma unidade ao endereço guardado por p, temos a posição seguinte do vetor. Ao diminuir uma unidade, tempos a posição anterior do vetor, como exemplificado pela figura:
![all text](http://codingfox.com/wp-content/uploads/2014/01/clip_image001_00002.gif)

Fonte da imagem: https://codingfox.com/14-13-sending-address-of-array-as-argument/

Perceba que nós fizemos:

int *p = a;

e não:

int *p = &a;

Pois como diz o comentário, o nome "a" já é um ponteiro que aponta para o primeiro endereço ocupado pelo vetor. Se "a" é um ponteiro, ele já guarda um endereço, então basta fazer o ponteiro "p" receber esse endereço. Pelo mesmo motivo não precisamos colocar o & para
ler uma string no scanf:

scanf("%[^\n]s", minha_string);

Uma string é um vetor de char. Ou seja, o nome "minha_string" já é um ponteiro e já guarda um endereço.

Obs.: deixar o & nessas duas situações pode não gerar um erro, mas irá gerar um warning.

No exemplo abaixo, podemos ver que um vetor pode ser acessado tanto por índices, quanto por aritmética de ponteios:

```c
#include <stdio.h>

main() {
    int vetor[] = {10, 20, 30, 40, 50};
    printf("Acessando itens do vetor por índices:\n");
    printf("Pos 0: %d\n", vetor[0]);
    printf("Pos 1: %d\n", vetor[1]);
    printf("Pos 2: %d\n", vetor[2]);
    printf("Pos 3: %d\n", vetor[3]);
    printf("Pos 4: %d\n", vetor[4]);
    rintf("\nAcessando itens do vetor usando aritmética de ponteiros\n");
    printf("Pos 0: %d\n", *(vetor));
    printf("Pos 1: %d\n", *(vetor + 1));
    printf("Pos 2: %d\n", *(vetor + 2));
    printf("Pos 3: %d\n", *(vetor + 3));
    printf("Pos 4: %d\n", *(vetor + 4));
}
```

Veja que a soma deve ser feita entre parênteses, pois o operador * é prioritário em relação ao perador +. A forma correta é primeiro
mover o ponteiro para a posição desejada e somente então acessar o seu conteúdo.

Poderíamos também usar um laço:

```c
#include <stdio.h>

main() {
    int vetor[] = {10, 20, 30, 40, 50};
    int i;
    printf("Acessando itens do vetor por índices:\n");
    for(i = 0; i < 5; i++) 
        printf("%d\t", vetor[i]);
    printf("\nAcessando itens do vetor usando aritmética de ponteiros\n");
    for(i = 0; i < 5; i++)
        printf("%d\t", *(vetor + i));
}
```
Fazer v[i] é equivalente a fazer *(v + i). O índice "i" indica quantos "deslocamentos" são necessários para acessar um determinado item.

## CUIDADO:
```c
#include <stdio.h>

main(){
   int vetor[] = {10, 20, 30, 40, 50};
   printf("%d\n", *(vetor + 1)); // Correto - imprime o 20
   printf("%d\n", *(vetor++)); // Erro
   return 0;
}
```
Para mover o ponteiro, deve-se usar sempre vetor + 1 e não vetor++. A segunda forma seria o mesmo que tentar fazer: vetor = vetor + 1, ou seja, tentaria atribuir um novo endereço para o ponteiro "vetor". Como o objetivo do ponteiro "vetor" é guardar o endereço do primeiro elemento do vetor, a linguagem C não permite fazer esse tipo de operação, pois a informação de quem é o primeiro elemento seria perdida. 

# Ponteiros como argumentos de funções

Imagine que você possui uma variável “a” com valor igual a 10 e uma variável “b” com valor igual a 15. Você quer trocar o conteúdo das duas variáveis, ou seja, “a” tem que passar a valer 15 e “b” tem que passar a valer 10. Uma ideia de resolver o problema seria:

```c
#include <stdio.h>

main() {
    int a = 10;
    int b = 15;
    int t;
    t = a;
    a = b;
    b = t;
    printf("A: %d - B: %d", a, b);
}
```

E se você precisasse fazer uma função para fazer essa troca? A função abaixo conseguiria trocar os valores de “a” e “b”?

```c
#include <stdio.h>

void troca(int a, int b) {
    int t;
    t = a;
    a = b;
    b = t;
}

main() {
    int a = 10;
    int b = 15;
    troca(a, b);
    printf("A: %d - B: %d", a, b);
}
```

A função troca trabalha com cópias de “a” e “b”, portanto, mesmo após chamar esta função, veremos no printf que “a” e “b” permanecem inalteradas.

Considere agora que a função troca, em vez de receber cópias de “a” e “b” recebe ponteiros que apontam para “a” e “b”.

```c
void troca(int *a, int *b) {
    int t;
    t = *a; // t recebe o conteúdo do end. apontado por a
    *a = *b; // o conteúdo do end. apontado por a recebe o conteúdo do end. apontado por b
    *b = t; // o conteúdo do end. apontado por b recebe o valor t
}
```

Na chamada da função em vez de passar cópias de “a” e “b”, devemos passar os endereços de “a” e “b” para que a função possa fazer as alterações diretamente sobre os conteúdos guardados nesses endereços. Dizemos que “a” e “b” são passados por **referência** para a função troca.

```c
main() {
    int a = 10;
    int b = 15;
    troca(&a, &b);
    printf("A: %d - B: %d", a, b);
}
```

Agora sim, as mudanças terão reflexo na main. O gif abaixo ajuda a lembrar a diferença entre passar um parâmetro por cópia ou referência: https://blog.penjee.com/passing-by-value-vs-by-reference-java-graphical/

# Vetores como argumentos de funções

E se for necessário criar uma função que recebe um vetor? Na linguagem C, quando fazemos:

```c
int v[] = {1, 2, 3};

```

o nome "v" nada mais é do que um ponteiro que guarda o primeiro endereço do vetor. Portanto, quando fazemos:

```c
void imprime_vetor(int v[], int n) {
...
}
```

somente uma cópia do ponteiro para a primeira posição do vetor é passada e não o conteúdo de todo o vetor. Esta cópia guarda o mesmo endereço apontado por "v". Assim, a função abaixo consegue alterar diretamente o conteúdo deste endereço, lembrando que v[0] = 2 seria o mesmo que fazer *(v + 0) = 2.

```c
#include <stdio.h>

int altera_vetor_1(int v[], int n) {
    v[0] = 2;
}

main() {
    int i, n = 5;
    int v[] = {1, 2, 3, 4, 5};

    altera_vetor_1(v, n);
    for(i = 0; i < n; i++) {
        printf("%d\t", v[i]);
    }
}

```

Uma outra forma de passar o vetor por parâmetro para a função altera_vetor() seria:

```c
int altera_vetor_1(int *v, int n) {
    v[0] = 2;
}
```

# Ponteiros como retorno de funções
    
Para ter uma função que retorna um ponteiro, deve-se colocar um asterísco após o tipo do dado. Considere uma função que retorna um ponteiro para a primeira ocorrência de um caractere “c” em uma string “s”:

```c
#include <stdio.h>

char * match(char c, char *s) { // char * - indica que o retorno da função é um ponteiro tipo char
   /*
   c != *s - verifica se c é diferente do conteúdo do ponteiro.
   *s - verifica se ainda não está no fim da string, ao chegar no fim da string o ponteiro terá \0 como conteúdo.
   */
   while(c != *s && *s)
        s++; // se ainda não encontrou, o ponteiro é movido para o próx. endereço
   return s; // retorna ponteiro
}

main() {
    char s[] = "boa noite";
    char c = 'a';
    char *p;
    p = match(c, s);
    if(*p) // encontrou (ponteiro não tem \0 como conteúdo)
            printf("%s", p); // imprime a string a partir do endereço p (onde acotenceu a ocorrência).
    else
            printf("Nao encontrou");
}
```

# Referências

* Livro C completo e Total - Herbert Schildt - 3ª edição.

* Notas de aula Profa. Carmem Hara e Prof. Wagner Zola: http://www.inf.ufpr.br/nicolui/Docs/Livros/C/ArmandoDelgado/notas-28_Ponteiros.html
    
# Leitura recomendada

* 20 erros comuns com ponteiros: https://www.acodersjourney.com/top-20-c-pointer-mistakes/

