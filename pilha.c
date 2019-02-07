#include<stdlib.h>
#include "pilha.h"

void inserir(noPilha** cabeca, noArvore * nA){
	noPilha * n = malloc(sizeof(noPilha));
	n->no = nA;
	n->prox = *cabeca;
	*cabeca = n;
}
noArvore * remover(noPilha** cabeca){
	if(*cabeca == NULL)
		return NULL;
	
	noArvore * na;
	na = (*cabeca)->no;
	*cabeca = (*cabeca)->prox;

	return na;
}

void liberar(noPilha** cabeca){
	while(*cabeca != NULL){
		noPilha *n = *cabeca;
		*cabeca = (*cabeca)->prox;
		free(n);
	}
}
