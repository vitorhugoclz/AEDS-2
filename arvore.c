#include "arvore.h"

/*@funcao cria uma nova estrutura de no para ser alocada */
noArvore * criar_no(char nome[30], int rg, char cpf[12]) {
    noArvore * no;
    no = malloc(sizeof (noArvore));
    strcpy(no->nome, nome);
    no->rg = rg;
    strcpy(no->cpf, cpf);
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

/*@funcao inserir um novo nó na arvore ao percorrela segundo os RGs*/
noArvore * insere_abb_rg(noArvore * arvore, noArvore * pai, noArvore * novo, int *prof) {
    if (arvore == NULL) {
        novo->pai = pai;
        return novo;
    }
    if (arvore->rg > novo->rg)
    {
        (*prof)++;
        arvore->esq = insere_abb_rg(arvore->esq, arvore, novo, prof);
    }
    else if (arvore->rg < novo->rg)
    {
        (*prof)++;
        arvore->dir = insere_abb_rg(arvore->dir, arvore, novo, prof);
    }
    return arvore;
}

/*@funcao faz a busca dos dados de uma pessoa segundo seu RG ao percorrer a arvore*/
noArvore * busca_abb_rg(noArvore * arvore, long int rg, int * prof) {
    if (arvore == NULL)
        return arvore;
    if (arvore->rg > rg)
    {
        (*prof)++;
        return busca_abb_rg(arvore->esq, rg, prof);
    }
    else {
        if (arvore->rg < rg)
        {
            (*prof)++;
            return busca_abb_rg(arvore->dir, rg, prof);
        }
        else
            return arvore;
    }
}

//bloco de funções referente a dados relacionados a CPF

/*@funcao faz a inserção de um novo nó ao percorrer a arvore segundo os CPFs */
noArvore * insere_abb_cpf(noArvore * arvore, noArvore * pai, noArvore * novo, int * prof) {
    if (arvore == NULL) {
        novo->pai = pai;
        return novo;
    }
    if (strcmp(arvore->cpf, novo->cpf) > 0)
    {
        (*prof)++;
        arvore->esq = insere_abb_cpf(arvore->esq, arvore, novo, prof);
    }
    else if (strcmp(arvore->cpf, novo->cpf) < 0)
    {
        (*prof)++;
        arvore->dir = insere_abb_cpf(arvore->dir, arvore, novo, prof);
    }
    return arvore;
}

/*@funcao busca os dados de uma pessoa segundo seu CPF*/
noArvore * busca_abb_cpf(noArvore * arvore, char cpf[12], int * prof) {
    if (arvore == NULL)
        return arvore;
    if (strcmp(arvore->cpf, cpf) < 0)
    {
        (*prof)++;
        return busca_abb_cpf(arvore->dir, cpf, prof);
    }
    else {
        if (strcmp(arvore->cpf, cpf) > 0)
        {
            (*prof)++;
            return busca_abb_cpf(arvore->esq, cpf, prof);
        }
        else
            return arvore;
    }
}

noArvore * insere_abb_nome(noArvore * arvore, noArvore * pai, noArvore * novo, int * prof) {
    if (arvore == NULL) {
        novo->pai = pai;
        return novo;
    }
    if (strcmp(arvore->nome, novo->nome) > 0)
    {
        (*prof)++;
        arvore->esq = insere_abb_nome(arvore->esq, arvore, novo, prof);
    }
    else if (strcmp(arvore->nome, novo->nome) < 0)
    {
        (*prof)++;
        arvore->dir = insere_abb_nome(arvore->dir, arvore, novo, prof);
    }
    return arvore;
}

noArvore * busca_abb_nome(noArvore * arvore, char nome[30], int  * prof) {
    if (arvore == NULL)
        return arvore;
    if (strcmp(arvore->nome, nome) > 0)
    {
        (*prof)++;
        return busca_abb_nome(arvore->esq, nome, prof);
    }
    else {
        if (strcmp(arvore->nome, nome) < 0)
        {
            (*prof)++;
            return busca_abb_nome(arvore->dir, nome, prof);
        }
        else
            return arvore;
    }
}
noArvore * remover_raiz(noArvore * arvore, noArvore **aux) {
    noArvore *p, *q;
    if (arvore == NULL) {
        *aux = NULL;
        return arvore;
    }
    if (arvore->esq == NULL) {
        *aux = arvore;
        arvore = arvore->dir;
        return arvore;
    }
    p = arvore;
    q = arvore->esq;
    while (q->dir != NULL) {
        p = q;
        q = q->dir;
    }
    if (p != arvore) {
        p->dir = q->esq;
        q->esq = arvore->esq;
    }
    q->dir = arvore->dir;
    (*aux) = arvore;
    return q;
}

noArvore * remover_no(noArvore * no)
{
    if(no->esq == NULL)
    {
        noArvore * aux = no->dir;
        if(aux != NULL)
            aux->pai = no->pai;
        free(no);
        return aux;
    }
    else
    {
        noArvore *p, *q;
        p = no;
        q = no->esq;
        while(q->dir != NULL)
        {
            p = q;
            q = q->dir;
        }
        if(p != no)
        {
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
        if(q != NULL)
            q->pai = no->pai;
        free(no);
        return q;
    }
}
