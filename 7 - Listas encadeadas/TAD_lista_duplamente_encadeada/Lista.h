typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista * cria_lista_vazia();
int verifica_lista_vazia(Lista *l);
void inserir_inicio(Lista *l, int chave);
void imprime_esq_dir(Lista *l);
void imprime_dir_esq(Lista *l);
void insere_final(Lista *l, int chave);
void insere_meio(Lista *l, int chave_b, int chave_i);
void remove_por_chave(Lista *l, int chave);
void inverte_lista(Lista *l);
void libera_lista(Lista *l);

