#ifndef _LISTA_H
#define _LISTA_H 

typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria(); 

/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l); 

/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info);
 
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info); 

/* Imprime uma lista.*/
void lst_imprime(Lista *l); 

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info); 

/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);

/* Verifica se duas listas t�m a mesma sequ�ncia de elementos recursivamente*/
int lst_igual_rec(Lista *l1,Lista *l2);

/* Libera a lista recursivamente*/
void lst_libera_rec(Lista *l);

/* Remove um elemento da lista recursivamente*/
Lista* lst_remove_rec(Lista *l, int info);

/* Imprime os elementos da lista recursivamente invertido*/
void lst_imprime_invertida_rec(Lista* l);

/* Imprime os elementos da lista recursivamente*/
void lst_imprime_rec(Lista* l);

/*a) Calcula o n�mero de n�s de uma lista.*/
int comprimento(Lista* l);

/*b) Retorna o n�mero de n�s da lista que possuem o campo info com valor
menor que n.*/
int menores(Lista* l, int n);

/*c) Soma os valores do campo info de todos os n�s.*/
int soma(Lista* l);

/*d) Retorna o n�mero de n�s da lista que possuem o campo info com
n�mero primo.*/
int primos(Lista* l);

/*e)  Cria uma lista que � a concatena��o de uma lista l2 no final de uma lista
l1.*/
Lista* lst_conc(Lista* l1, Lista* l2);

/*f) Fazer a diferen�a de duas listas L1 e L2.*/
Lista* lst_diferenca(Lista* l1, Lista* l2);

#endif

