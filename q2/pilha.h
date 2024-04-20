typedef struct pilha Pilha;

/*Fun��o que cria uma pilha.*/
Pilha* pilha_cria(void);

/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p);

/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info);

/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);

/*Fun��o que imprime os elementos de uma pilha;*/
void pilha_imprime(Pilha *p);

/*Libera o espa�o alocado para uma pilha.*/
void pilha_libera(Pilha *p);

/* Fun��o para ordenar uma pilha em ordem crescente.*/
void pilha_ordenar(Pilha *p);

/*a) Retorna o valor armazenado em seu topo.*/
int topo(Pilha* p);

/*b) Retornar o n�mero de elementos da pilha que possuem o campo info com valor �mpar.*/
int impares(Pilha* p);

/*c) Verificar quais s�o os elementos pares de uma pilha p1 e que os empilhe em ordem crescente em uma pilha p2.*/
Pilha* empilha_pares(Pilha* p1, Pilha* p2);
