# Structs
Na disciplina Fundamentos de Programação, estudamos estruturas de dados homogêneas: vetores, matrizes, strings. Dizemos que essas estruturas são homogêneas pois todos os dados armazenados nelas são do mesmo tipo. Por exemplo: em um vetor de tamanho 10, declarado com tipo int, todos os 10 elementos serão do tipo int.

As estruturas heterogêneas, são estruturas que podem guardar diferentes tipos de dados. Imagine o seguinte problema: precisamos escrever um programa para armazenar dados sobre os alunos da UTFPR. Será necessário guardar informações como nome do aluno, registro acadêmico (RA) e coeficiente de rendimento. O nome do aluno deve ser uma string, o RA deve ser do tipo int e o coeficiente de rendimento deve ser do tipo float. Como criar uma estrutura para armazenar esses dados na linguagem C?

Na linguagem C, as estruturas heterogêneas são representadas pelo tipo **struct**, que tem a seguinte forma:

```c
struct  nome_da_struct  {  
	tipo_do_dado campo_1;  
	tipo_do_dado campo_2;  
	...  
	tipo_do_dado campo_n;  
};
```
  

A palavra chave struct é usada para indicar que será definido um novo de tipo de dados. Ao lado dessa palavra chave podemos definir o nome desejado para a struct. Dentro do bloco da struct escrevemos as variáveis desejadas (da mesma maneira que declaramos variáveis na função main). Cada variável é chamada de membro ou campo da struct. Os campos da struct podem ser de qualquer tipo. Exemplo:

```c
struct  aluno {  
	char nome[30];  
	int RA;  
	float coeficiente;  
};  
```

A declaração de uma estrutura não aloca memória, simplesmente é introduzido um novo tipo de dados. Essa declaração é feita normalmente fora da função main, próxima ao topo do arquivo. Assim, todo o código poderá usar o novo tipo de dados.

```c
#include <stdio.h>  
	  
struct  aluno  {  
	char nome[30];  
	int RA;  
	float coeficiente;  
};  
	
main()  {  
	printf("Hello world!");  
}
```

# Declarando uma variável de um tipo struct

Assim como na declaração de qualquer tipo de variável, é preciso informar o tipo do dado e seu identificador. O tipo do dado no exemplo acima será “struct aluno”:

```c
struct  aluno  aluno_1;
```

Ao declarar uma variável do tipo “struct aluno” será alocada memória suficiente para armazenar uma string de tamanho 30, um int e um float.


# Typedef

Para simplificar os códigos, existe a palavra chave **typedef**. Ela permite definir um novo nome (ou um apelido) para um tipo de dados. No exemplo abaixo é definido um novo nome para a struct aluno:

```c
typedef  struct  aluno  Aluno;  
  
struct  aluno  {  
  char nome[30];  
  int RA;  
  float coeficiente;  
};
```

Assim, cada vez que for preciso declarar uma variável do tipo struct aluno, em vez de usar:

```c
struct  aluno  aluno_1;
```

basta usar:

```c
Aluno aluno_1;
```

Outra forma de usar o typedef é a seguinte:
```c
typedef struct  aluno  {  
  char nome[30];  
  int RA;  
  float coeficiente;  
} Aluno;
```
  
O uso de structs deixa o código mais sucinto e menos confuso. Imagine que você precisa guardar as informações de 3 alunos. Sem conhecer structs, uma possível solução seria:

```c
char nome_1[30], nome_2[30]; nome_3[30];  
int RA_1, RA_2, RA_3;  
float coeficiente_1, coeficiente_2, coeficiente_3;
```
  
Seria necessário tomar cuidado para sempre acessar os dados do aluno certo. Não pegar nome_1, RA_1 e coeficiente_2 por engano, por exemplo. Usando structs, o código fica mais sucinto e os dados de cada aluno ficam “empacotados” em um só lugar, facilitando o acesso:

```c
Aluno aluno_1, aluno_2, aluno_3;
```
  
# Acessando os campos de uma struct

O acesso aos campos de uma struct se dá através do operador ponto. Considerando o exemplo da struct aluno:

```c
main()  {  
  Aluno  aluno_1;  
  aluno_1.coeficiente = 0.925;  
  aluno_1.RA = 123;  
  strcpy(aluno_1.nome, "Maria");  
  
  printf("Nome: %s\n", aluno_1.nome);  
  printf("RA: %d\n", aluno_1.RA);  
  printf("Coeficiente: %.4f\n", aluno_1.coeficiente);  
}
```

ou ainda, fazendo a leitura dos dados:

```c
main()  {  
  Aluno  aluno_1;  
  printf("Nome: ");  
  scanf("%[^\n]s", aluno_1.nome);  
  printf("RA: ");  
  scanf("%d", &aluno_1.RA);  
  printf("Coeficiente: ");  
  scanf("%f", &aluno_1.coeficiente);  
  
  printf("\nNome: %s\n", aluno_1.nome);  
  printf("RA: %d\n", aluno_1.RA);  
  printf("Coeficiente: %.4f\n", aluno_1.coeficiente);  
}
```

Obs.: em C, não é possível atribuir um array para outro array. Ex.:
```c
  char tomate[] = "tomate";
  tomate = "cebola";
  printf("%s\n", tomate);
```

Isto irá gerar um erro:

```diff
teste.c:6:10: error: assignment to expression with array type
   tomate = "cebola";
          ^
```

É preciso copiar item por item. No caso de strings, já existe a função strcpy(), da biblioteca string.h. Ela copia o contdúeo de uma string de origem para uma string de destino. Ela deve ser usada da seguinte forma: strcpy(destino, origem); Portanto, o trecho de código acima pode ser corrigido como é mostrado abaixo:

```c
  char tomate[] = "tomate";
  strcpy(tomate, "cebola");
  printf("%s\n", tomate);
```

# Inicialização de uma struct

Assim como qualquer outra variável do tipo, int, float, char, etc., é possível inicializar uma struct no momento da declaração. Essa inicialização é parecida com a inicialização de um vetor. Por exemplo:

```c
main()  {  
  Aluno  aluno_1 = {"Maria", 123, 0.925};  
  printf("\nNome: %s\n", aluno_1.nome);  
  printf("RA: %d\n", aluno_1.RA);  
  printf("Coeficiente: %.4f\n", aluno_1.coeficiente);  
}
```

Lembrando que neste caso, os valores precisam estar na mesma ordem de declaração dos campos da struct.

# Atribuição entre structs

É possível atribuir uma struct diretamente em outra somente quando as duas structs forem do mesmo tipo. Cada campo da primeira struct será copiado em seu campo correspondente na segunda struct.  
  
```c  
main()  {  
  Aluno  aluno_1, aluno_2;  
  
  strcpy(aluno_1.nome, "Maria");  
  aluno_1.RA = 1;  
  aluno_1.coeficiente = 0.925;  
  
  aluno_2 = aluno_1;  
  
  printf("Nome: %s\n", aluno_2.nome);  
  printf("RA: %d\n", aluno_2.RA);  
  printf("Coeficiente: %.4f\n", aluno_2.coeficiente);  
}  
```

No exemplo abaixo existem duas structs, Aluno e Estudante. Elas tem exatamente os mesmos campos. A variável aluno_1 é do tipo Aluno e a variável aluno_2 é do tipo Estudante. Ao tentar atribuir aluno_1 para aluno_2 irá acontecer um erro:

```c
typedef  struct  aluno  Aluno;  
typedef  struct  estudante  Estudante;  
  
struct  aluno {  
  char nome[30];  
  int RA;  
  float coeficiente;  
};  
  
struct  estudante  {  
  char nome[30];  
  int RA;  
  float coeficiente;  
};  
  
main()  {  
  Aluno aluno_1;  
  Estudante aluno_2;  
  
  strcpy(aluno_1.nome, "Maria");  
  aluno_1.RA = 1;  
  aluno_1.coeficiente = 0.925;  
  
  aluno_2 = aluno_1;  
  
  printf("Nome: %s\n", aluno_2.nome);  
  printf("RA: %d\n", aluno_2.RA);  
  printf("Coeficiente: %.4f\n", aluno_2.coeficiente);  
}
```
 O erro informa que os tipos são incompatíveis:

```diff
error: incompatible types when assigning to type ‘Estudante {aka struct estudante}’ from type ‘Aluno {aka struct aluno}’|
```

Apesar de as estruturas Aluno e Estudante serem iguais internamente, elas são tipos de dados diferentes e não é possível fazer essa atribuição.

# Arrays de struct

É possível criar arrays de struct, assim como é feito em qualquer outro tipo de dados. Ao percorrer o array de struct, primeiro deve-se acessar a posição desejada através do índice e depois acessar o campo desejado usando o operador ponto:

```c
main()  {  
  int i, n = 5;  
  Aluno  alunos[n];  
  
  for(i = 0; i < n; i++)  {  
    __fpurge(stdin); // limpeza do buffer, equivalente ao fflush no windows
    printf("Nome: ");  
    scanf("%[^\n]s", alunos[i].nome);  
    printf("RA: ");  
    scanf("%d", &alunos[i].RA);  
    printf("Coeficiente: ");  
    scanf("%f", &alunos[i].coeficiente);  
  }  
  
  for(i = 0; i < n; i++)  {  
    printf("\nNome: %s\n", alunos[i].nome);  
    printf("RA: %d\n", alunos[i].RA);  
    printf("Coeficiente: %.4f\n", alunos[i].coeficiente);  
  }   
}
```

# Structs como argumentos de função

Assim como em qualquer outro tipo de dados, as structs podem ser passadas como parâmetros para funções.

```c
void  imprime_dados_aluno(Aluno a)  {  
  printf("Nome: %s\n", a.nome);  
  printf("RA: %d\n", a.RA);  
  printf("Coeficiente: %.4f\n", a.coeficiente);  
}
```
 
e a chamada da função:

```c
main()  {  
  int i, n = 5;  
  Aluno  alunos[n];  
  
  for(i = 0; i < n; i++)  {  
    __fpurge(stdin);
    printf("Nome: ");  
    scanf("%[^\n]s", alunos[i].nome);  
    printf("RA: ");  
    scanf("%d", &alunos[i].RA);  
    printf("Coeficiente: ");  
    scanf("%f", &alunos[i].coeficiente);  
  }  
  
  for(i = 0; i < n; i++)  {  
    imprime_dados_aluno(alunos[i]);  
  }  
}
```

# Structs como valor de retorno

Assim como em qualquer outro tipo de dados, é possível ter funções retornando uma struct.

```c
Aluno  cadastra_aluno()  {  
  Aluno  a;  
  printf("Nome: ");  
  scanf("%[^\n]s", a.nome);  
  printf("RA: ");  
  scanf("%d", &a.RA);  
  printf("Coeficiente: ");  
  scanf("%f", &a.coeficiente);  
  return a;  
}
```
e a chamada de função:

```c
main()  {  
  int i, n = 1;  
  struct  aluno  alunos[n];  
  
  for(i = 0; i < n; i++)  {  
    alunos[i] = cadastra_aluno();  
  }  
  
  for(i = 0; i < n; i++)  {  
    imprime_dados_aluno(alunos[i]);  
  }  
}
```

Exemplo de função que recebe e retorna uma struct:

```c
Aluno  atualiza_coeficiente_aluno(Aluno a, float coeficiente)  {  
  a.coeficiente = coeficiente;  
  return a;  
}
```
 
e a chamada da função:

```c
main()  {  
  Aluno  aluno_1;  
  strcpy(aluno_1.nome, "Maria");  
  aluno_1.RA = 1;  
  aluno_1.coeficiente = 0.925;  
  imprime_dados_aluno(aluno_1);  
  
  aluno_1 = atualiza_coeficiente_aluno(aluno_1, 0.890);  
  imprime_dados_aluno(aluno_1);  
}
```
  
# Aninhamento de structs

Como definido anteriormente, os campos de uma struct podem ser de qualquer tipo, portanto é possível ter uma struct como campo de outra. Por exemplo:

```c
#include <stdio.h>  
  
typedef  struct  ponto  Ponto;  
typedef  struct  segmento_reta  Segmento;  
  
struct  ponto  {  
  int x;  
  int y;  
};  
  
struct  segmento_reta  {  
  Ponto ponto_ini;  
  Ponto ponto_fin;  
};  
  
main() {  
  Ponto ponto_a, ponto_b;  
  Segmento reta;  
  
  ponto_a.x = 4;  
  ponto_a.y = 2;  
  ponto_b.x = 6;  
  ponto_b.y = 2;  
  
  reta.ponto_ini = ponto_a;  
  reta.ponto_fin = ponto_b;

  printf("Inicio da reta: %d, %d\n", reta.ponto_ini.x, reta.ponto_ini.y);  
  printf("Final da reta: %d, %d\n", reta.ponto_fin.x, reta.ponto_fin.y);  
}
```  

Cuidado ao acessar os campos de structs aninhadas: a variável "reta" é uma struct do tipo Segmento, e contém os campos "ponto_ini" e "ponto_fin", que não são tipos simples de dados, são structs do tipo Ponto. Portanto, não conseguimos imprimir ou fazer alguma operação aritmética com "reta.ponto_ini" e "reta.ponto_fin". É preciso utilizar o operador ponto até chegar no tipo simples de dados: "reta.ponto_ini.x" ou "reta.ponto_ini.y", por exemplo.

Outro exemplo:
  
```c
#include <stdio.h>  
  
typedef  struct  data  Data;  
typedef  struct  pessoa  Pessoa;  
  
struct  data  {  
  int dia;  
  int mes;  
  int ano;  
};  
  
struct  pessoa  {  
  char nome[30];  
  Data  data_nascimento;  
}  
  
main()  {  
  Pessoa contato_1;  
  int idade;  

  strcpy(contato_1.nome, "Maria");  
  contato_1.data_nascimento.dia = 1;  
  contato_1.data_nascimento.mes = 1;  
  contato_1.data_nascimento.ano = 1990;  
  
  idade = 2019 - contato_1.data_nascimento.ano;  
  
  printf("Aniversario da Maria: %d/%d. Ela vai fazer %d anos.",  
  contato_1.data_nascimento.dia, contato_1.data_nascimento.mes, idade);  
}
```
Também é possível ter em uma struct, um campo que é um array de struct, como no exemplo abaixo:
```c
#include <stdio.h>

typedef struct ponto{
    int x;
    int y;
} Ponto;

typedef struct triangulo{
    Ponto pontos[3];
} Triangulo;

int main(void) {
    Triangulo t;
    t.pontos[0].x = 0;
    t.pontos[0].y = 0;
    t.pontos[1].x = 5;
    t.pontos[1].y = 0;
    t.pontos[2].x = 1;
    t.pontos[2].y = 5;

    for(int i = 0; i < 3; i++)
        printf("%d, %d\n", t.pontos[i].x, t.pontos[i].y);

    return 0;
}

```

# Links recomendados

* Video aulas professor André Backes: [https://www.youtube.com/watch?v=MatsUCe5uZw](https://www.youtube.com/watch?v=MatsUCe5uZw)
    
* Notas de aula Profa. Carmem Hara e Prof. Wagner Zola: [http://www.inf.ufpr.br/nicolui/Docs/Livros/C/ArmandoDelgado/notas-27_Estruturas.html](http://www.inf.ufpr.br/nicolui/Docs/Livros/C/ArmandoDelgado/notas-27_Estruturas.html)
