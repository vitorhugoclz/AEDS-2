/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilha.h
 * Author: flavio
 *
 * Created on 6 de Novembro de 2018, 15:42
 */

#ifndef PILHA_H
#define PILHA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

typedef struct noArvore_ noArvore;

struct noArvore_ {
	char valor;
	noArvore * esq;
	noArvore * dir;
};

typedef struct noPilha_ noPilha;

struct noPilha_ {
	noArvore * no;
	noPilha * prox;
};

void inserir(noPilha** cabeca, noArvore * nA);
noArvore * remover(noPilha** cabeca);
void liberar(noPilha** cabeca);

#endif /* PILHA_H */

