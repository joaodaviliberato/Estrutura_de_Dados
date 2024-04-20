#ifndef _FILA_H
#define _FILA_H 

typedef struct lista Lista;
typedef struct fila Fila;

/*Fun��o que cria uma Fila.*/
Fila* fila_cria(void);

/*Testa se uma Fila � vazia.*/
int fila_vazia(Fila *f);

/*Fun��o que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info);

/*Fun��o que remove um elemento de uma Fila.*/
int fila_remove(Fila *f);

/*Fun��o que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f);

/*Libera o espa�o alocado para uma Fila.*/
void fila_libera(Fila *f);

/*a) Retorna o n�mero de elementos da fila com valor maior que n.*/
int qtd_maior(Fila* f, int n);

/*b) Cria uma fila com os elementos da fila f na ordem inversa.*/
Fila* inverte(Fila* f);

/*c) Cria uma fila com os elementos da fila f na ordem inversa.*/
int pares(Fila* f);

#endif

