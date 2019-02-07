/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flavio
 *
 * Created on 6 de Novembro de 2018, 15:21
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/**
 * funcao pre ordem recursiva.
 * @param n = ponteiro para a raiz da arvore.
 */
void pre_ordem(noArvore * n) {
	if (n) {
		printf("%c ", n->valor);
		pre_ordem(n->esq);
		pre_ordem(n->dir);
	}
}

/**
 * funcao pre ordem iterativa, fazendo uso de uma pilha.
 * @param n = ponteiro para a raiz da arvore.
 */
void pre_ordem_i(noArvore * n) {
	noPilha * inicio = NULL;
	inserir(&inicio, n);

	while (1) {
		noArvore* x = remover(&inicio);
		if (x) {
			printf("%c ", x->valor);
			inserir(&inicio, x);
			inserir(&inicio, x->esq);
		} else {
			if (!inicio) break;
			x = remover(&inicio);
			inserir(&inicio, x->dir);
		}
	}
	liberar(&inicio);
}

/**
 * funcao em ordem recursiva.
 * @param n = ponteiro para a raiz da arvore.
 */
void em_ordem(noArvore * n) {
	if (n) {
		em_ordem(n->esq);
		printf("%c ", n->valor);
		em_ordem(n->dir);
	}
}

/**
 * funcao em ordem iterativa, fazendo uso de uma pilha.
 * @param n = ponteiro para a raiz da arvore.
 */
void em_ordem_i(noArvore * n) {
	noPilha * inicio = NULL;
	inserir(&inicio, n);

	while (1) {
		noArvore* x = remover(&inicio);
		if (x) {
			inserir(&inicio, x);
			inserir(&inicio, x->esq);
		} else {
			if (!inicio) break;
			x = remover(&inicio);
			printf("%c ", x->valor);
			inserir(&inicio, x->dir);
		}
	}
	liberar(&inicio);
}

/**
 * funcao pos ordem recursiva.
 * @param n = ponteiro para a raiz da arvore.
 */
void pos_ordem(noArvore * n) {
	if (n) {
		pos_ordem(n->esq);
		pos_ordem(n->dir);
		printf("%c ", n->valor);
	}
}

/**
 * funcao pos ordem iterativa, fazendo uso de duas pilhas.
 * @param n = ponteiro para a raiz da arvore.
 */
void pos_ordem_i(noArvore * n) {
	noPilha * pilha1 = NULL;
	noPilha * pilha2 = NULL;
	inserir(&pilha1, n);
	noArvore* x;
	while (pilha1) {
		x = remover(&pilha1);
		inserir(&pilha2, x);
		if (x->esq)
			inserir(&pilha1, x->esq);
		if (x->dir)
			inserir(&pilha1, x->dir);
	}
	x = remover(&pilha2);
	while (x) {
		printf("%c ", x->valor);
		x = remover(&pilha2);
	}
}

/**
 * funcao pos ordem iterativa, fazendo uso de uma pilha.
 * @param n = ponteiro para a raiz da arvore.
 */
void pos_ordem_iv2(noArvore * raiz) {
	if (!raiz)
		return;

	noPilha * pilha = NULL;

	int primeiro = 1;

	while (pilha || primeiro) {
		primeiro = 0;
		while (raiz) {
			if (raiz->dir)
				inserir(&pilha, raiz->dir);
			inserir(&pilha, raiz);
			raiz = raiz->esq;
		}
		raiz = remover(&pilha);
		if (raiz->dir && pilha && raiz->dir == pilha->no) {
			remover(&pilha);
			inserir(&pilha, raiz);
			raiz = raiz->dir;
		} else {
			printf("%c ", raiz->valor);
			raiz = NULL;
		}
	}
}

noArvore * constroi() {
	char c[2];
	scanf("%[^\n]%*c", &c);

	if (c[0] == '.') {
		return NULL;
	} else {
		noArvore * n;
		n = malloc(sizeof (noArvore));
		n->valor = c[0];
		n->esq = constroi();
		n->dir = constroi();
		return n;
	}
}

void desaloca(noArvore * arvore) {
	noArvore * n = arvore;
	if (n != NULL) {
		desaloca(n->esq);
		desaloca(n->dir);
		free(n);
	}
}

int main() {
	noArvore * arvore;
	arvore = constroi();
	printf("pre_ordem: ");
	pre_ordem(arvore);
	printf("\n");

	printf("pre_ordem iterativo: ");
	pre_ordem_i(arvore);
	printf("\n");

	printf("em_ordem: ");
	em_ordem(arvore);
	printf("\n");

	printf("em_ordem iterativo: ");
	em_ordem_i(arvore);
	printf("\n");

	printf("pos_ordem: ");
	pos_ordem(arvore);
	printf("\n");

	printf("pos_ordem iterativo: ");
	pos_ordem_i(arvore);
	printf("\n");

	printf("pos_ordem iterativo v2: ");
	pos_ordem_iv2(arvore);
	printf("\n");
	
	desaloca(arvore);
	return (EXIT_SUCCESS);
}

