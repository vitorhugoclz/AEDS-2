#include "arvore.h"

noArvore * abrir_arq() {
    noArvore * novo, * arvore = NULL;
    long int rg;
    int prof = 0;
    char nome[30], cpf[12];
    FILE * arq;
    arq = fopen("entrada.txt", "r");
    if (arq != NULL) {
        while (!feof(arq)) {
            fscanf(arq, "%ld %s %s", &rg, nome, cpf);
            novo = criar_no(nome, rg, cpf);
            arvore = insere_abb_rg(arvore, NULL, novo, &prof);
        }
        arvore->tipo = RG;
    }
    fclose(arq);
    return arvore;
}

void pre_ordem(noArvore * no, int opcao) {
    if (opcao == RG) {
        if (no != NULL) {
            printf("%s ", no->nome);
            printf("%ld ", no->rg);
            printf("%s ", no->cpf);
            printf("\n");
            pre_ordem(no->esq, opcao);
            pre_ordem(no->dir, opcao);
        }
    } else if (opcao == NOME) {
        if (no != NULL) {
            printf("%s ", no->nome);
            printf("%ld ", no->rg);
            printf("%s ", no->cpf);
            printf("\n");
            pre_ordem(no->esq, opcao);
            pre_ordem(no->dir, opcao);
        }
    } else {
        if (no != NULL) {
            printf("%s ", no->nome);
            printf("%ld ", no->rg);
            printf("%s ", no->cpf);
            printf("\n");
            pre_ordem(no->esq, opcao);
            pre_ordem(no->dir, opcao);
        }

    }

}

void escrever(noArvore * arvore) {
    FILE *arq;
    if (arvore->tipo == RG) {
        arq = fopen("saida.txt", "w");
        while (arvore != NULL) {
            fprintf(arq, "%ld %s %s\n", arvore->rg, arvore->nome, arvore->cpf);
            arvore = remover_no(arvore);
        }
    } else {
        noArvore * aux = NULL, *temporaria = NULL;
        int prof = 0;
        while (arvore != NULL) {
            arvore = remover_raiz(arvore, &aux);
            aux->dir = NULL;
            aux->esq = NULL;
            temporaria = insere_abb_rg(temporaria, NULL, aux, &prof);
        }
        arvore = temporaria;
        arvore->tipo = RG;
        arq = fopen("saida.txt", "w");
        while (arvore != NULL) {
            fprintf(arq, "%ld %s %s\n", arvore->rg, arvore->nome, arvore->cpf);
            arvore = remover_no(arvore);
        }
    }
    fclose(arq);
}

