#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
 	int info;
 	Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
 	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
 	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
 	Lista* ln = (Lista*)malloc(sizeof(Lista));
 	ln->info = info;
 	ln->prox = l;
	return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
 	Lista* lAux = l;
 	while(lAux!=NULL){
	 	if(lAux->info == info)
		 	return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
 	while(lAux!=NULL){
 		printf("Info = %d\n",lAux->info);
 		lAux = lAux->prox;
 	}
}

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
 		if(l->info==info){
 			free(l);
 			return lAux;
 		}else{
 			Lista* lAnt = l;
 			while(lAux!=NULL){
 				if(lAux->info == info){
 					lAnt->prox = lAux->prox;
 					free(lAux);
 					break;
 				}else{
	 				lAnt = lAux;
	 				lAux = lAux->prox;
	 			}
	 		} 
	 	} 
	}
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
 	Lista* lProx;
 	while(l!=NULL){
 		lProx = l->prox;
 		free(l);
 		l = lProx;
 	}
}

/* Insere um elemento na lista ordenado.*/
Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
 		lNew->prox = NULL;
 		return lNew;
	}else if(l->info>=info){
 		lNew->prox = l;
 		return lNew;
	}else{
 		Lista *lAnt = l;
 		Lista *lProx = l->prox; 
 		while(lProx!=NULL && lProx->info<info) {
			lAnt = lProx;
 			lProx = lProx->prox;
 		}
 	lAnt->prox = lNew;
 	lNew->prox = lProx;
 	return l;
	}
}

/* Insere um elemento no final da lista.*/
Lista* lst_insere_final(Lista *l, int info){
    Lista* lNew = (Lista*)malloc(sizeof(Lista));
    lNew->info = info;
    lNew->prox = NULL; 
    if (l == NULL) {
        return lNew;
    }
    Lista* finalLista = l;
    while (finalLista->prox != NULL) {
        finalLista = finalLista->prox;
    }
    finalLista->prox = lNew;
    return l;
}

/* Imprime os elementos da lista recursivamente*/
void lst_imprime_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		printf("info: %d\n",l->info);
		lst_imprime_rec(l->prox);
	}
}
		
/* Imprime os elementos da lista recursivamente invertido*/
void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
 	}
 }

/* Libera a lista recursivamente*/
void lst_libera_rec(Lista *l){
 	if(!lst_vazia(l)){
	lst_libera_rec(l->prox);
	free(l);
 	}
}

/* Verifica se duas listas têm a mesma sequência de elementos recursivamente*/
int lst_igual_rec(Lista *l1,Lista *l2){
	if(lst_vazia(l1) && lst_vazia(l2))
		return 1;
	else if (lst_vazia(l1) || lst_vazia(l2))
		return 0;
	else{
		return (l1->info==l2->info && 
		lst_igual_rec(l1->prox,l2->prox));
 	}
}

/* Remove um elemento da lista recursivamente*/
Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l)){
 		if(l->info==info){
			Lista* lAux = l;
 			l = l->prox;
			free(lAux);
 		}
 		else{
			l->prox = lst_remove_rec(l->prox,info);
		}
	}
	return l; 
}

/*a) Calcula o número de nós de uma lista.*/
int comprimento(Lista* l) {
	int count = 0;
	Lista* lAux = l;
	while(lAux!=NULL){
		count++;
		lAux = lAux->prox;
	}
	return count;
}

/*b) Retorna o número de nós da lista que possuem o campo info com valor menor que n.*/
int menores(Lista* l, int n){
	int count = 0;
	Lista* lAux = l;
	while(lAux!=NULL){
		if(lAux->info < n)
			count++;
		lAux = lAux->prox;
	}
	return count;
}

/*c) Soma os valores do campo info de todos os nós.*/
int soma(Lista* l){
	int soma = 0;
	Lista* lAux = l;
	while(lAux!=NULL){
		soma += lAux->info;
		lAux = lAux->prox;
	}
	return soma;
}

/*d) Retorna o número de nós da lista que possuem o campo info com
número primo.*/
int numeroPrimo(int numero){
	if (numero <= 1) {
        return 0;
    }
    int i;
    for (i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

int primos(Lista* l){
	int count = 0;
	Lista* lAux = l;
	while(lAux!=NULL){
		if(numeroPrimo(lAux->info))
			count++;
		lAux = lAux->prox;
	}
	return count;
}

/*e)  Cria uma lista que é a concatenação de uma lista l2 no final de uma lista
l1.*/
Lista* lst_conc(Lista* l1, Lista* l2){
	if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL){
    	return l1;
	}
	Lista* listaConc = lst_cria();
	Lista* lAux1 = l1;
	Lista* lAux2 = l2;
	while(lAux1!=NULL){
		listaConc = lst_insere_final(listaConc, lAux1->info);
		lAux1 = lAux1->prox;
	}
	while(lAux2!=NULL){
		listaConc = lst_insere_final(listaConc, lAux2->info);
		lAux2 = lAux2->prox;
	}
	return listaConc;
}

/*f) Fazer a diferença de duas listas L1 e L2.*/
Lista* lst_diferenca(Lista* l1, Lista* l2){
	Lista* lAux1 = l1;
	Lista* listaDiferenca = lst_cria();
	
	if(l1 == NULL)
		return NULL;
	if(l2 == NULL)
		return l1;

	while(lAux1 != NULL){
		if(lst_busca(l2, lAux1->info) == NULL){
			listaDiferenca = lst_insere_final(listaDiferenca, lAux1->info);
		}
		lAux1 = lAux1->prox;
	}
	return listaDiferenca;
}


