# Structs e ponteiros

Assim como com qualquer outro tipo de dados, é possível criar ponteiros para tipos de dados criados por nós, as structs. Considere uma estrutra que guarda nome, rua e número da casa de um cliente:

```c
typedef struct cliente Cliente;

struct cliente {
    char nome[30];
    char rua[30];
    int numero;
};
```

Para criar um ponteiro tipo Cliente na função main, utilizamos o * antes do nome da variável, assim como foi visto para tipos como int e char:

```c
int main(void) {
    Cliente c1;
    Cliente *c2;

    strcpy(c1.nome, "Maria");
    strcpy(c1.rua, "Guarani");
    c1.numero = 123;
    
    c2 = &c1;
    
    return 0;
}
```

No exemplo acima, c2 é uma variável do tipo ponteiro que aponta para c1.

Considere agora que você deseja alterar o número da casa de Maria através do ponteiro c2:

```c
int main(void) {
    Cliente c1;
    Cliente *c2;

    strcpy(c1.nome, "Maria");
    strcpy(c1.rua, "Guarani");
    c1.numero = 123;
    
    c2 = &c1;
    c2.numero = 234;
    
    return 0;
}
```

Um erro irá acontecer, uma vez que o ponteiro c2 não possui um campo chamado “numero”. Ele possui apenas um endereço. O campo “numero” faz parte do conteúdo guardado no endereço apontado pelo ponteiro c2:

![alt text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/ponteiro_struct.png)

Por isso, antes de tentar alterar o valor de um campo, é necessário fazer uma operação de deferência para acessar o conteúdo apontado por c2. Se simplesmente fizermos isso:

```
int main(void) {
    Cliente c1;
    Cliente *c2;

    strcpy(c1.nome, "Maria");
    strcpy(c1.rua, "Guarani");
    c1.numero = 123;
    
    c2 = &c1;
    *c2.numero = 234; // incluído operador de deferência antes de c2
    
    return 0;
}
```

O código continuará com erro, pois, o perador ponto tem maior prioridade. Isso quer dizer que a linha que gera erro é interpretada como:

```c
*(c2.numero) = 234;
```

Para corrigir este erro, usamos parênteses para alterar a ordem de precedência dos operadores:

```c
(*c2).numero = 234;
```

A linha acima pode ser reescrita da seguinte forma:

```c
c2->numero = 234;
```

As duas formas são equivalentes, porém, a segunda forma elimina o uso de parênteses, deixando o código mais claro. 

# Ponteiros de struct como parâmetros de funções

Na linguagem C é possível criar funções que recebem ponteiros para estruturas ou que retornam ponteiros para estruturas. Considere ainda a estrutura Cliente dos exemplos anteriores:

```c
typedef struct cliente Cliente;

struct cliente {
    char nome[30];
    char rua[30];
    int numero;
};
```

O código abaixo cadastra e imprime um cliente:

```c
main() {
    Cliente cliente;
    strcpy(cliente.nome, "Maria");
    strcpy(cliente.rua, "Rua Guarani");
    cliente.numero = 10;

    printf("\nNome: %s\n", cliente.nome);
    printf("Rua: %s\n", cliente.rua);
    printf("Numero: %d\n", cliente.numero);
}
```

Imagine agora que queremos escrever uma função responsável por alterar o endereço de um cliente. Se escrevermos a função da seguinte forma:

```c
void altera_endereco(Cliente cliente, char rua[], int num) {
    strcpy(cliente.rua, rua);
    cliente.numero = num;
}
```

Ao chamar a função altera_endereco na função main, nada irá acontecer, pois os parâmetros da função são passados por cópia. Qualquer alteração feita dentro dessa função será feita em cima de uma cópia do cliente e só terá efeito no escopo dessa função. Podemos contornar esse problema de duas formas.

1. Retornando o cadastro atualizado (usando uma função que retorna uma estrutura):

```c
Cliente altera_endereco(Cliente cliente, char rua[], int num) {
    strcpy(cliente.rua, rua);
    cliente.numero = num;
    return cliente;
}
```

2. Usando uma função que recebe ponteiros:

```c
void altera_endereco(Cliente *cliente, char rua[], int num) {
    strcpy(cliente->rua, rua);
    cliente->numero = num;
}
```

Assim como nos exemplos com tipos de dados primitivos, basta adicionar um asterísco antes do nome do parâmetro que será um ponteiro. 

Na função main, a segunda função seria usada da seguinte forma:

```c
int main(void) {
    Cliente c1;

    strcpy(c1.nome, "Maria");
    strcpy(c1.rua, "Rua Guarani");
    c1.numero = 10;

    printf("\nNome: %s\n", c1.nome);
    printf("Rua: %s\n", c1.rua);
    printf("Numero: %d\n", c1.numero);

    altera_endereco(&c1, "Avenida Tupy", 20); // a função espera um endereço, usamos & antes da variável

    printf("\nNome: %s\n", c1.nome);
    printf("Rua: %s\n", c1.rua);
    printf("Numero: %d\n", c1.numero);

    return 0;
}

```

Após a chamada da função será possível verificar que o endereço foi atualizado com sucesso. 

Para evitar códigos duplicados, a parte de imprimir os dados também pode ser feita dentro de uma função. Uma função que tem o objetivo de simplesmente imprimir dados, sem manipulá-los, não tem necessidade de receber ponteiros. Entretanto, no caso de o parâmetro ser uma struct, pode ser mais vantajoso passar um ponteiro pelo seguinte motivo: quando uma struct é passada por cópia para uma função, todos os campos da struct precisam ser copiados, o que pode ser custoso se a struct tiver muitos campos. De modo geral, passar um ponteiro para estrutura em vez de passar uma cópia da estrutura toda é mais eficiente.

```c
void imprime_cliente(Cliente *cliente) {
    printf("\nNome: %s\n", cliente->nome);
    printf("Rua: %s\n", cliente->rua);
    printf("Numero: %d\n", cliente->numero);
}
```

Por fim, temos uma versão mais organizada do código:

```c
int main(void) {
    Cliente c1;

    strcpy(c1.nome, "Maria");
    strcpy(c1.rua, "Rua Guarani");
    c1.numero = 10;

    imprime_cliente(&c1);
    altera_endereco(&c1, "Avenida Tupy", 789); // a função espera um endereço
    imprime_cliente(&c1);

    return 0;
}
```

# Ponteiros de structs como retorno de funções

Para ter uma função que retorna um ponteiro de struct, basta adicionar o asterísco após o tipo, por exemplo.:
```c
Cliente * retorna_cliente() {
...
```
Exemplos mais práticos poderão ser vistos após o conteúdo de alocação dinâmica de memória.

