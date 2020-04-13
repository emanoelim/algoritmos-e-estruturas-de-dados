# TADs - Tipos Abstratos de Dados

**Tipo de dados**: define o domínio de uma variável: int, float, char…

**Estrutura de dados**: representa um relacionamento lógico entre tipos de dados. Ex.:

```c
struct endereco {
      char rua[30];
      int numero;
      char bairro[30];
      char cep[9];
};
```

Temos variáveis do tipo char e int, mas que juntas têm um significado: representar o endereço de uma pessoa.

Outro exemplo:

```c
struct produto {
    char nome[30];
    char marca[30];
    int codigo;
    float valor;
    int categoria; // produto de limpeza, produto de beleza, doces, salgados, etc.
};
```

Temos variáveis do tipo char, int e float, que juntas têm o propósito de representar um produto de um supermercado.

**TADs - Tipos Abstratos de Dados**: em um TAD, além de ter uma estrutura de dados, tem-se também um conjunto de operações para 
manipular esses dados. Considere por exemplo que você tem uma struct que representa um aluno da disciplina de Fundamentos de 
programação:

```c
struct aluno_fundamentos {
    char nome[30];
    int RA;
    float notas[3];
    float media;
};
```
Imagine que você precisa:
- Cadastrar 44 alunos que se matricularam na turma;
- Excluir 4 alunos que conseguiram equivalência da matéria;
- Guardar as notas das 3 provas de cada aluno;
- Calcular a média de cada aluno;

Todas as operações acima podem ser consideradas operações que manipulam a estrutura de dados aluno_fundamentos. A estrutura 
de dados aluno_fundamentos e o conjunto das suas operações formam um TAD. Portanto podemos dizer que:

### TAD = estrutura de dados + operações de manipulação da estrutura.

São operações comuns em um TAD:

- Criação da estrutura;
- Inclusão de um elemento;
- Remoção de um elemento;
- Busca de um elemento;
- Atualização de um elemento;
- Imprimir dados;
- Etc.

# Manipulação através de funções

Toda a manipulação da estrutura é feita por meio de funções que interagem com ela. Para cadastrar um novo aluno, por exemplo, não deve ser feito o seguinte:

```c
main() {
    struct aluno_fundamentos aluno;
    char nome[30];
    int registro_academico;
    float notas[3];

    printf("Informe o nome do aluno: ");
    scanf("%[^\n]s", &nome);
    printf("Informe o RA do aluno: ");
    scanf("%d", &registro_academico);
    printf("Informe 3 notas do aluno: ");
    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);

    strcpy(aluno.nome, nome);
    aluno.RA = registro_academico;
    aluno.notas[0] = notas[0];
    aluno.notas[1] = notas[1];
    aluno.notas[2] = notas[2];
}
```

Deve-se criar uma função para cadastro, por exemplo, a função cadastra_aluno(). Assim, sempre que for preciso cadastrar um aluno, esta função é chamada em vez de acessar a estrutura de forma direta:

```c
struct aluno_fundamentos cadastra_aluno(char nome[], int registro_academico, float notas[]) {
    struct aluno_fundamentos novo_aluno;

    strcpy(novo_aluno.nome, nome);
    novo_aluno.RA = registro_academico;
    novo_aluno.notas[0] = notas[0];
    novo_aluno.notas[1] = notas[1];
    novo_aluno.notas[2] = notas[2];

    return novo_aluno;
}

main() {
    struct aluno_fundamentos aluno;
    char nome[30];
    int registro_academico;
    float notas[3];

    printf("Informe o nome do aluno: ");
    scanf("%[^\n]s", &nome);
    printf("Informe o RA do aluno: ");
    scanf("%d", &registro_academico);
    printf("Informe 3 notas do aluno: ");
    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);

    aluno = cadastra_aluno(nome, registro_academico, notas);    
}
```
Outro contra exemplo envolvendo o cálculo da média:

```c
main() {
    struct aluno_fundamentos aluno;
    char nome[30];
    int registro_academico;
    float notas[3];

    printf("Informe o nome do aluno: ");
    scanf("%[^\n]s", &nome);
    printf("Informe o RA do aluno: ");
    scanf("%d", &registro_academico);
    printf("Informe 3 notas do aluno: ");
    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);

    aluno = cadastra_aluno(nome, registro_academico, notas);

    aluno.media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3;
}
```

A abordagem correta seria criar uma função para manipular as notas e retornar a média:

```c
struct aluno_fundamentos calula_media(struct aluno_fundamentos aluno) {
    int i;
    float soma = 0;

    for(i = 0; i < 3; i++) {
            soma += aluno.notas[i];
    }
    aluno.media = soma / 3;
    
    return aluno;
}

main() {
    struct aluno_fundamentos aluno;
    char nome[30];
    int registro_academico;
    float notas[3];

    printf("Informe o nome do aluno: ");
    scanf("%[^\n]s", &nome);
    printf("Informe o RA do aluno: ");
    scanf("%d", &registro_academico);
    printf("Informe 3 notas do aluno: ");
    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);

    aluno = cadastra_aluno(nome, registro_academico, notas);
    aluno = calula_media(aluno);
}
```

Manipular a estrutura por meio de funções permite a **reutilização de código**. Sempre que for preciso fazer uma operação sobre 
a estrutura basta chamar a função responsável. Ex.: em vez de escrever a lógica para cadastrar um aluno várias vezes (uma para cada aluno), eu preciso escrever a lógica apenas uma vez dentro de uma função e depois basta chamar essa função, escrevendo apenas uma linha de código para cada cadastro necessário.

Além da reutilização de código, o código fica mais limpo e fácil de entender. Em vez de ter várias lógicas complexas dentro da função principal, estas lógicas podem ser separadas em funções. Quando você chama uma função dentro do código, quem estiver olhando o código irá ver o nome da função e irá saber o que está sendo feito, em vez de ter que analisar várias linhas de código para entender o que está acontecendo. Para isso é muito importante que:

- A função tenha um nome que represente claramente o seu objetivo (nem que o nome fique um pouco extenso);
- **Cada função deve fazer apenas uma coisa**. Uma função chamada calcula_media() deve exclusivamente fazer um cálculo de média. Ela não deve imprimir informações, atualizar notas, ou realizar qualquer outra tarefa que não seja o cálculo da média.

# Encapsulamento

Quem usa o TAD precisa apenas conhecer suas funcionalidades e não como a estrutura foi implementada. Por exemplo: quando você importa a biblioteca string.h, você pode usar diversas funções: strlen (pegar o tamanho da string), strcpy (copiar o conteúdo de uma string em outra), strcmp (comparar duas strings), etc. Você consegue usar todas essas funcionalidades sem saber como a linguagem implementa uma string internamente.

Da mesma forma, se você criar seu próprio TAD e disponibilizar para outro programador utilizar, ele só vai precisar saber como utilizar as funções que você disponibilizou e não como você criou a estrutura. A vantagem disso é que o usuário só conseguirá manipular a estrutura por meio das funções criadas por você, evitando comportamentos inesperados.

Para garantir este encapsulamento, um TAD é constituído de 3 arquivos:
- arquivo.h: typedefs, protótipos de funções, variáveis globais…
- arquivo.c: structs e funções.
- usa_tad.c: o arquivo que conterá a função main e usará as funcionalidades do TAD.

No código abaixo temos a estrutura Ponto, que tem o objetivo de guardar as coordenadas de um ponto 2D. Existem também algumas funções para manipular a estrutura:

```c
#include <stdio.h>
#include <math.h>

typedef struct ponto Ponto;
static struct ponto {
    float x;
    float y
};

Ponto cria_ponto(float x, float y) {
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

void imprime_ponto(Ponto p) {
    printf("%.2f, %.2f\n", p.x, p.y);
}

float calcula_distancia(Ponto p1, Ponto p2) {
    float dx, dy;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

main() {
   Ponto p1, p2;
   float d;

   p1 = cria_ponto(10, 20);
   p2 = cria_ponto(10, 30);
   imprime_ponto(p1);
   imprime_ponto(p2);

   d = calcula_distancia(p1, p2);
   printf("%.2f", d);
}
```

Vamos reorganizar este código respeitando os conceitos de TADs.

1) Vamos criar um arquivo chamado ponto.h, contendo o typedef para renomear a struct ponto e também os protótipos das funções:

```c
typedef struct ponto Ponto;

Ponto cria_ponto(float x, float y);
void imprime_ponto(Ponto p);
float distancia(Ponto p1, Ponto p2);
```

2) Vamos criar um arquivo chamado ponto.c (o arquivo deve ter o mesmo nome do arquivo anterior, só mudando a extensão). Nele colocaremos a estrutura e as funções que interagem com ela. Também vamos colocar a inclusão das bibliotecas aqui. Vamos adicionar também o arquivo que criamos, ponto.h. Diferente das bibliotecas que já vem com a linguagem, este arquivo que foi criado por nós, não vai estar entre < >. Ele deve estar entre “ “. 

```c
#include <stdio.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto cria_ponto(float x, float y) {
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

void imprime_ponto(Ponto p){
    printf("%.2f, %.2f\n", p.x, p.y);
}

float distancia(Ponto p1, Ponto p2) {
    float dx, dy, dt;
    dx = p1.x - p2.x;
    
    dy = p1.y - p2.y;
    dt = sqrt(pow(dx, 2) + pow(dy, 2));
    return dt;
}
```

3) Finalmente vamos criar um arquivo chamado usa_tad.c que irá conter o programa principal (função main). Adicionaremos também nesse arquivo a inclusão do arquivo ponto.h que criamos. Ele ficará assim:

```c
#include <stdio.h>
#include "ponto.h"

main() {
    Ponto p1, p2;
    float d;

    p1 = cria_ponto(10, 20);
    p2 = cria_ponto(10, 30);
    imprime_ponto(p1);
    imprime_ponto(p2);

    d = distancia(p1, p2);
    printf("%.2f", d);

}
```

Agora vamos compilar o arquivo ponto.c usando o comando:

```diff
gcc -c ponto.c
```

Depois vamos tentar compilar o arquivo usa_tad.c usando o comando:

 ```diff
 gcc -c usa_tad.c
```

Ao fazer isso devemos ser notificados de alguns erros, sendo os dois primeiros:

```diff
usa_tad.c:5:11: error: storage size of ‘p1’ isn’t known
     Ponto p1, p2;
           ^~
usa_tad.c:5:15: error: storage size of ‘p2’ isn’t known
     Ponto p1, p2;
               ^~
```

Isso acontece porque o arquivo usa_tad.c não conhece como a estrutura Ponto foi implementada, ou seja, não tem como saber quanto espaço uma variável do tipo Ponto precisa. Essa é justamente a ideia que vimos quando falamos em encapsulamento: o usuário do TAD não deve conhecer ou ter acesso direto a estrutura, para que ele não possa fazer alterações inesperadas sobre ela. O que podemos fazer é permitir que o usuário acesse ponteiros para estrutura. Assim precisaremos fazer uma alteração em nosso código:

```c
#include <stdio.h>
#include "ponto.h"

main() {
    Ponto *p1, *p2; // p1 e p2 agora são ponteiros
    float d;

    p1 = cria_ponto(10, 20);
    p2 = cria_ponto(10, 30);
    imprime_ponto(p1);
    imprime_ponto(p2);

    d = distancia(p1, p2);
    printf("%.2f", d);
}
```
Perceba que p1 e p2 agora são ponteiros do tipo Ponto. Se o programa for compilado novamente, os erros na declaração de p1 e p2 foram resolvidos, embora ainda existam outros erros. Os próximos erros são:

```c
usa_tad.c:8:10: error: invalid use of incomplete typedef ‘Ponto {aka struct ponto}’
     p1 = cria_ponto(10, 20);
          ^~~~~~~~~~
usa_tad.c:9:10: error: invalid use of incomplete typedef ‘Ponto {aka struct ponto}’
     p2 = cria_ponto(10, 30);
          ^~~~~~~~~~
```

Perceba que p1 e p2 recebem o retorno da função cria_ponto(). Esta função retorna um tipo Ponto, mas p1 é um ponteiro e espera um endereço. Assim, temos uma incompatibilidade de tipos, que pode ser resolvida alterando a função cria_ponto para que ela retorne um ponteiro.

```c
Ponto * cria_ponto(float x, float y)
    Ponto *p = malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}
```

Atente para o uso da função malloc para alocar um endereço de memória para o ponteiro p. Se simplesmente fosse feito isso:

```c
Ponto * cria_ponto(float x, float y) {
    Ponto *p;
    p->x = x; // (*p).x = x;
    p->y = y; // (*p).y = y;
    return p;
}
```

Teríamos um erro, pois p ainda não está inicializado, ou seja, ainda não está vinculado a nenhum endereço de memória: o computador estaria recebendo uma instrução para guardar um valor, mas não saberia onde guardar esse valor.
Como a função cria_ponto foi modificada, será necessário mudar seu protótipo em ponto.h:

```c
Ponto * cria_ponto(float x, float y); 
```

Salve o arquivo ponto.h, compile novamente o arquivo ponto.c e tente compilar novamente o arquivo usa_tad.c. Perceba que os erros referentes a incompatibilidade de tipos foram resolvidos. Os próximos erros são:

```diff
usa_tad.c:10:19: error: type of formal parameter 1 is incomplete
     imprime_ponto(p1);
                   ^~
usa_tad.c:11:19: error: type of formal parameter 1 is incomplete
     imprime_ponto(p2);
                   ^~
```

A função imprime ponto espera como parâmetro uma variável do tipo Ponto, mas o que está sendo passado para ela em sua chamada é um ponteiro. No arquivo ponto.c, altere a função que imprime o ponto para que receba um ponteiro:

```c
void imprime_ponto(Ponto * p){
    printf("%.2f, %.2f\n", p->x, p->y);
}
```

No arquivo ponto.h, atualize o protótipo da função:

```c
void imprime_ponto(Ponto *p);
```

Salve o arquivo ponto.h, compile novamente o arquivo ponto.c e compile o arquivo usa_tad.c. Veja que os erros anteriores foram resolvidos. Entretanto, ainda temos dois últimos erros:

```diff
usa_tad.c:13:19: error: type of formal parameter 1 is incomplete
     d = distancia(p1, p2);
                   ^~
usa_tad.c:13:23: error: type of formal parameter 2 is incomplete
     d = distancia(p1, p2);
                       ^~
```

É o mesmo caso do erro anterior: a função espera um tipo Ponto mas está recebendo um ponteiro do tipo Ponto. Assim, a função distancia() precisa ser alterada para receber ponteiros:

```c
float distancia(Ponto *p1, Ponto *p2) {
    float dx, dy, dt;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    dt = sqrt(pow(dx, 2) + pow(dy, 2));
    return dt;
}
```

Assim como o seu protótipo no arquivo Ponto.h:

```c
float distancia(Ponto *p1, Ponto *p2);
```

Salve o arquivo ponto.h, compile novamente o arquivo ponto.c e compile novmente o arquivo usa_tadc. O arquivo usa_tad.c agora é compilado sem erros. 

Para finalizar precisamos liberar p1 e p2. Como eles foram alocados dinamicamente usando a função malloc, eles precisam ser liberados manualmente. Vamos criar uma nova função no arquivo ponto.c:

```c
void libera_ponto(Ponto *p) {
    free(p);
}
```

E em ponto.h, vamos adicionar o protótipo da função:

```c
void libera_ponto(Ponto *p);
```

Ao final da função main(), no arquivo usa_tad.c, basta adicionar:

```c
libera_ponto(p1);
libera_ponto(p2);
```

Salve o arquivo ponto.h, compile novamente o arquivo ponto.c e o arquivo usa_tad.c e então gere um novo executável. Não haverá alteração na saída do programa, mas agora temos a garantia que os endereços estão sendo liberados.

# Considerações

Vimos que TADs prezam pelo encapsulamento dos dados, por isso o usuário nunca vai conseguir criar uma variável desta forma:

```c
Ponto p;
```

Ele conseguirá apenas criar um ponteiro para um tipo Ponto:

```c
Ponto *p;
```

Também não lhe será permitido atribuir valores diretamente para um tipo Ponto:

```c
(*p).x = 10;
```

ou:

```c
p->x = 10;
```

Ao tentar fazer isso irá ocorrer um erro. A atribuição só poderá ser feita através da função criar_ponto(), por exemplo.

Perceba que se você decidir mudar algo na estrutura ou otimizar o funcionamento de alguma função, somente o arquivo ponto.c irá precisar ser recompilado. O arquivo onde estão as implementações do usuário do seu TAD não vai ser afetado.
