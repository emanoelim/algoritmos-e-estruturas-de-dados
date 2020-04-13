
# Lista duplamente encadeada

Na lista encadeada estudada anteriormente, cada célula guarda um item e um ponteiro para próxima célula. Em uma lista duplamente encadeada, uma célula também deve guardar um ponteiro para quem é a célula anterior. Portanto, teremos a seguinte estrutura:
```c
struct item {
  int chave;
  // demais campos
};
struct celula {
  Item item;
  Celula *ant;
  Celula *prox; // a célula também guarda quem é sua anterior
};
struct lista {
  Celula *primeira;
};
```
Que pode ser visualizada pela figura abaixo:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada.png)

### Criação de lista vazia
Se a lista está vazia, o ponteiro primeira deve guardar NULL. Assim, este método fica semelhante a criação da lista vazia simples:
```c
Lista * cria_lista_vazia() {
  Lista *l = malloc(sizeof(Lista));
  l->primeira = NULL;
  return l;
}
```

### Verificação de lista vazia
Consequentemente, para verificar se a lista está vazia podemos usar a seguinte lógica:
```c
// retorna 1 se está vazia, ou 0 se não está
int verifica_lista_vazia(Lista *l) {
  return l->primeira == NULL;
}
```

### Inserção no início da lista
- a próxima da nova célula é aquela que era a primeira;
- a anterior da nova célula é NULL (ela será a primeira, então não tem anterior);
- a célula que era a primeira terá a nova célula como sua anterior (exceto em uma lista que estava vazia, pois a primeira seria o NULL);
- o ponteiro primeira agora deve apontar para a nova célula.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_insere_ini.png)

Pensando nisso, podemos implementar a função da seguinte forma:
```c
void inserir_inicio(Lista *l, int chave) {
  Item novo;
  novo.chave = chave;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->ant = NULL;
  nova->prox = l->primeira;
  // se a lista não está vazia, a anterior da que era a primeira será a nova
  if(!verifica_lista_vazia(l))
    l->primeira->ant = nova;
  l->primeira = nova;
}
```
### Inserção no fim da lista
- a próxima da nova célula será NULL;
- anterior da nova célula será aquela que era a última;
- a célula que era a última terá a nova como próxima.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_insere_fim.png)

Obs.: se a lista estiver vazia, a inserção deve se comportar como a inserção no início;

```c
void insere_final(Lista *l, int chave) {
  if(verifica_lista_vazia(l))
    inserir_inicio(l, chave);
  else {
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;
    Celula *ultima = l->primeira;
    while(ultima->prox != NULL) {
      ultima = ultima->prox;
    }
    nova->ant = ultima;
    ultima->prox = nova;
  }
}
```

### Inserção no meio (após uma determinada célula)

Vamos adotar a ideia de buscar uma célula pela sua chave e adicionar a nova célula na sequência. Para isso pode ser conveniente criar uma função que busca uma célula por sua chave:
```c
Celula * busca_chave(Lista *l, int chave) {
  Celula *aux = l->primeira;
  while(aux != NULL && aux->item.chave != chave) {
    aux = aux->prox;
  }
  return aux;
}
```
Se a célula foi encontrada (se a função não retornou NULL) deve-se fazer o seguinte tratamento:
- a anterior da nova célula deve ser aquela que foi encontrada;
- a próxima da nova célula deve ser aquela que era a próxima da célula que foi encontrada;
- a próxima da célula encontrada deve ser a nova célula;
- a célula que era a próxima da que foi encontrada deve ter a nova célula como anterior (caso a próxima não seja igual a NULL).

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_insere_meio.png)

Implementação:

```c
void insere_meio(Lista *l, int chave_b, int chave_i) {
  Celula *anterior = busca_chave(l, chave_b);
  if(anterior == NULL) {
    printf("Chave não encontrada ou lista vazia.\n");
    return;
  }
  Item novo;
  novo.chave = chave_i;
  
  Celula *proxima = anterior->prox;
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->ant = anterior;
  nova->prox = proxima;
  
  anterior->prox = nova;
  if(proxima != NULL) // somente caso proxima não seja NULL, pois NULL não tem anterior
    proxima->ant = nova; 
}
```

### Imprimir lista
Na lista simplesmente encadeada só existia um ponteiro para a próxima célula, então só era possível imprimir a lista no sentido da esquerda para a direita (a não ser que fosse usada uma função recursiva). Como a lista duplamente encadeada mantém um ponteiro para a próxima e outra para a anterior, fica fácil imprimir a lista nos dois sentidos:

```c
void imprime_esq_dir(Lista *l) {
  Celula *aux = l->primeira;
  while(aux != NULL) {
    printf("Chave: %d\n", aux->item.chave);
    aux = aux->prox;
  }
}

void imprime_dir_esq(Lista *l) {
  // ir até a última célula
  Celula *aux = l->primeira;
  while(aux->prox != NULL) { 
    aux = aux->prox;
  }
  while(aux != NULL) {
    printf("Chave: %d\n", aux->item.chave);
    aux = aux->ant;
  }
}
```

### Remover item
Em uma lista é permitido remover itens de qualquer lugar (início, meio ou fim). Seguindo a mesma ideia que foi feita na lista simplesmente encadeada, vamos criar uma função que remove um item com uma determinada chave, fazendo o tratamento adequado de acordo com a posição desse item. 

**Remover do início**: se o item encontrado está no começo da lista:
- o ponteiro primeira deve apontar para a próxima da que vai ser removida;
- a célula que passa a ser a primeira deve ter NULL como anterior.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_remove_ini.png)

**Remover do meio**: se o item encontrado está em uma posição do meio da lista:
- a anterior à célula que vai ser removida deve receber a próxima dela;
- a próxima à célula que vai ser removida deve receber a anterior dela.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_remove_meio.png)

**Remover do fim**: se o item encontrado é o último da lista:
- basta fazer com que a anterior da célula que vai ser removida receba a próxima dela.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_remove_fim.png)

**Cuidado**: se a célula que vai ser removida é a única célula da lista, a anterior é NULL e a próxima também é NULL (NULL não tem campo anterior nem campo próxima), portanto basta fazer com que primeira aponte para NULL;

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/duplamente_encadeada_remove_unica_celula.png)


Teremos o seguinte código:
```c
void remove_por_chave(Lista *l, int chave) {
	Celula *remover = busca_chave(l, chave);
	if(remover == NULL) {
		printf("Item não encontrado ou lista vazia.\n");
		return;
	}
	if(remover->ant == NULL && remover->prox == NULL) // é a única
		l->primeira = NULL;
	else if(remover == l->primeira) { // remover do inicio
		l->primeira = remover->prox;
		l->primeira->ant = NULL;		
	}
	else {	// remover do meio ou fim
		Celula *proxima = remover->prox;
		Celula *anterior = remover->ant;
		anterior->prox = proxima;
		if(proxima != NULL) 
			proxima->ant = anterior;
	}
	free(remover);
}
```

### Liberar lista
A liberação da lista duplamente encadeada pode ser feita de maneira semelhante às outras listas já estudadas:
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
}
```

### Vantagens
- Permite percorrer a lista nos dois sentidos;
- Fica mais fácil para remover itens, não é necessário um ponteiro extra para recuperar o item anterior;
- Facilidade para interver a lista.

### Desvantagens
- Ocupa mais memória para guardar o ponteiro para a célula anterior;
- Para inserir e retirar itens é necessário ter mais cuidado, pois existem mais ponteiros que precisam ser modificaodos.

### Aplicações
Listas duplamente encadeadas são usadas por aplicações que exigem navegação nos dois sentidos (de frente para trás ou de trás para frente). Exemplos:
- Utilizada por navegadores para implementar funcionalidades de voltar para a página anterior ou ir para a próxima página;
- Utilizada por players para avançar ou voltar músicas, vídeos, etc;
- Utilizada por programas de tem opção de desfazer e refazer (mantém uma lista de estados);
- Utilizada por programas que precisam manter uma lista do que foi usado mais recentemente;
