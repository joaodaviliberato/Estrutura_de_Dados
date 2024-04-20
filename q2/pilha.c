#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "pilha.h"

#define MAX 10

typedef struct pilha{
	int n;
	int v[MAX];
}Pilha;

/*Função que cria uma pilha.*/
Pilha* pilha_cria(void){
 	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
 	if(p==NULL){
 		printf("Memoria insuficiente!!!\n");
 		exit(1);
 	}
 	p->n = 0;
 	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
 	if(p->n==MAX){
 		printf("Capacidade da Pilha Estourou!!!\n");
 		exit(1); 
 	}
	p->v[p->n]= info;
 	p->n = p->n + 1;
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
 	int i;
 	for(i = p->n-1; i>=0;i--){
 	printf("%d\n",p->v[i]);
 	}
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
 	free(p);
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
 	return p->n==0;
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
 	int a;
 	if(pilha_vazia(p)){
 		printf("Pilha Vazia!!!\n");
 		exit(1);
 	}
 	a = p->v[p->n-1];
 	p->n--;
 	return a;
}

/* Função para ordenar uma pilha em ordem crescente.*/
void pilha_ordenar(Pilha *p) {
    Pilha *pilha_aux = pilha_cria(); 
    while (!pilha_vazia(p)) { 
        int temp = pilha_pop(p); 
        while (!pilha_vazia(pilha_aux) && topo(pilha_aux) > temp) { 
            pilha_push(p, pilha_pop(pilha_aux)); 
        }
        pilha_push(pilha_aux, temp); 
    }
    while (!pilha_vazia(pilha_aux)) { 
        pilha_push(p, pilha_pop(pilha_aux)); 
    }
    pilha_libera(pilha_aux); 
}

/*a) Retorna o valor armazenado em seu topo.*/
int topo(Pilha* p){
	if(pilha_vazia(p)){
 		printf("Pilha Vazia!!!\n");
 		exit(1);
 	}
	return (p->v[(p->n-1)]);
}

/*b) Retornar o número de elementos da pilha que possuem o campo info com valor ímpar.*/
int impares(Pilha* p){
	int count = 0;
	int i;
	for(i = p->n-1; i >= 0; i--){
		if(p->v[i] % 2 != 0)
			count++;
	}
	return count;
}

/*c) Verificar quais são os elementos pares de uma pilha p1 e que os empilhe em ordem crescente em uma pilha p2.*/
Pilha* empilha_pares(Pilha* p1, Pilha* p2){
	if (p2 == NULL) {
        p2 = pilha_cria(); 
    }
	int i;
	for(i = p1->n-1; i >= 0; i--){
		if(p1->v[i] % 2 == 0){
			pilha_push(p2, p1->v[i]);
		}
	}
	pilha_ordenar(p2);
	return p2;
}


