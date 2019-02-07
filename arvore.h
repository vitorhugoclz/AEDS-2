/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvore_binaria_busca.h
 * Author: vitor
 *
 * Created on 29 de Novembro de 2018, 13:22
 */

#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    #define RG 0
    #define NOME 1
    #define CPF 2

    typedef struct arvore_{
        int tipo;
        long int rg;
        char nome[30];
        char cpf[12];
        struct arvore_ * pai;
        struct arvore_ * esq;
        struct arvore_ * dir;
    }noArvore;
    
void pre_ordem(noArvore * no, int opcao);
void em_ordem(noArvore * no, int opcao);
void pos_ordem(noArvore * no, int opcao);
noArvore * abrir_arq();
void escrever(noArvore * arvore);
noArvore * criar_no(char nome[30], int rg, char cpf[12]);
noArvore * insere_abb_rg(noArvore * arvore,noArvore * pai, noArvore * novo, int * prof);
noArvore * busca_abb_rg(noArvore * arvore,long int rg, int * prof);
noArvore * insere_abb_cpf(noArvore * arvore,noArvore * pai, noArvore * novo, int * prof);
noArvore * busca_abb_cpf(noArvore * arvore,char cpf[12], int * prof);
noArvore * insere_abb_nome(noArvore * arvore, noArvore * pai, noArvore * novo, int *prof);
noArvore * busca_abb_nome(noArvore * arvore, char nome[30], int * prof);
noArvore * remover_raiz(noArvore * arvore, noArvore **aux);
noArvore * remover_no(noArvore * no);
noArvore * menu_rg(noArvore * arvore);
noArvore * menu_cpf(noArvore * arvore);
noArvore * menu_nome(noArvore * arvore);

#ifdef __cplusplus
}
#endif

#endif /* ARVORE_BINARIA_BUSCA_H */

