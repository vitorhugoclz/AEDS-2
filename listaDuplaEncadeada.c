/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vitor
 *
 * Created on 22 de Outubro de 2018, 16:28
 * Lista Duplamente  Encadeada -- versão 1 (final).
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;

struct no_ {
	int valor;
	no * prox;
        no *ant;
};

/**
 * 
 * @param inicio = ponteiro para o inicio da lista.
 * @param elemento = valor a ser inserido.
 * @return 1 caso seja possivel inserir, e 0 caso contrario.
 *
 */
int inserir(no ** inicio, no **fim, int elemento) {
	//lista vazia
	if (*inicio == NULL) {
		*inicio = malloc(sizeof (no));
                *fim = *inicio;
		(*(*inicio)).valor = elemento;
		(*(*inicio)).prox = NULL;
                (*(*inicio)).ant = NULL;
	} else {
		no * atual;
		no * anterior;
		atual = *inicio;

		//procura pela posicao de insercao
		while (elemento > (*atual).valor && (*atual).prox != NULL)
			atual = (*atual).prox;

		//testa se elemento ja existe
		if ((*atual).valor == elemento) {
			return 0;
		} else {
			//criando o novo no a ser inserido
			no * n;
			n = malloc(sizeof (no));
			(*n).valor = elemento;

			if (elemento < (*atual).valor) {//insere no inicio ou no meio da lista
				if (*inicio == atual) {//insere no inicio
                                    n->prox = atual;
                                    (*atual).ant = n;
                                    (*(inicio)) = n;
                                    n->ant = NULL;
				} else {//insere no meio
					(*atual).ant->prox = n;
                                        (*n).ant = atual->ant;
                                        (*atual).ant = n;
                                        (*n).prox = atual;
				}
				
			} else {//insere no final da lista
                            n->ant = (*fim);   
                            (*(*fim)).prox = n;
                            (*n).prox = NULL;
                            (*fim) = n;
			}
		}
	}

	return 1;
}

/**
 * 
 * @param inicio = ponteiro para o inicio da lista.
 * @param valor = valor que se deseja remover da lista.
 * @return = ponteiro para o no removido, ou NULL caso nao seja possivel remover.
 */
no * removePorValor(no ** inicio, no **fim, int valor) {
	if (*inicio == NULL)
		return NULL;

	no * atual = *inicio;
	no * anterior = *inicio;

	//checa se e possivel caminhar mais pela lista
	//ou se o valor encontrado ja esta no primeiro no,
	//caso onde anterior == atual
	while (anterior->prox != NULL || anterior == atual) {
		if (atual->valor == valor) {//valor encontrado
			if (atual == anterior) {//primeiro no
                            if(*fim == atual){
                                *inicio = atual->prox;
                                *fim = *inicio;
                            } else {
				*inicio = atual->prox;
                                (*(*inicio)).ant = NULL;
                            }
			} else {//encontrado em outro no
                            if(*fim == atual){
                                anterior->prox = NULL;
                                (*fim) = anterior;
                            } else {
				anterior->prox = atual->prox;
                                atual->prox->ant = atual->ant;
                            }
			}

			return atual;
		}
		anterior = atual;
		atual = atual->prox;
	}
	//nao foi encontrado
	return NULL;
}

/**
 * 
 * @param inicio = ponteiro para o inicio da lista.
 * @param indice = indice do no que se deseja remover da lista (comecando em 0).
 * @return = ponteiro para o no removido, ou NULL caso nao seja possivel remover.
 */
no * removePorIndice(no ** inicio, no **fim, int indice) {
	if (*inicio == NULL)
		return NULL;
        int i = 0;
	no * atual = *inicio;
	no * anterior = *inicio;
	
	//checa se e possivel caminhar mais pela lista
	//ou se o valor encontrado ja esta no primeiro no,
	//caso onde anterior == atual
	while ( (atual != NULL) && (i != indice) ) {
            i++;
            anterior = atual;
            atual = atual->prox;
        }
	if (atual != NULL) {//no encontrado
            if (i == 0) //primeiro no
            {
                if(*fim == atual)
                {//se somente ouver um no
                    (*inicio) = NULL;
                    (*fim) = (*inicio);
                }
                else
                {
                    atual->prox->ant = NULL;
                    *inicio = atual->prox;
                }
            } else {//encontrado em outro no
                if (*fim == atual) {
                    anterior->prox = NULL;
                    (*fim) = anterior;
                } 
                else
                {
                        anterior->prox = atual->prox;
                        atual->prox->ant = atual->ant;                                
                }
            }
            return atual;
	}
	//no nao encontrado
	return NULL;
}

/**
 * 
 * @param inicio = ponteiro para o inicio da lista.
 */
void escrever(no * inicio, no *fim, int tipo) {
	if (inicio == NULL) {
		printf("Lista vazia.");
	}
        if (tipo == 3){ //escreve em ordem crescente
		while (inicio != NULL) {
			printf("%d", inicio->valor);
			if (inicio->prox != NULL)
				printf(" --> ");

			inicio = inicio->prox;
		}
	}
        else {//escreve em ordem decrescente
		while (fim != NULL) {
			printf(" %d", fim->valor);
			if (fim->ant != NULL)
				printf(" --> ");

			fim = fim->ant;
		}            
        }
	printf("\n\n");
}

/**
 * 
 * @param inicio = ponteiro para o inicio da lista.
 */
void desaloca(no * inicio){
	while(inicio != NULL){
		no * n = inicio;
		inicio = inicio->prox;
		free(n);
	}
}

int main() {
	no * inicio;
        no * fim;
	no * n;
	inicio = NULL;
        fim = NULL;
	int elemento;
	int indice;
	int ans = 0;

	do {
		printf("Informe operacao: \n");
		printf("0 --> inserir \n");
		printf("1 --> remover por valor \n");
		printf("2 --> remover por indice \n");
		printf("3 --> escrever crescente \n");
                printf("4 --> escrever decrescente\n");
		printf("5 --> sair \n");
		scanf("%d", & ans);

		switch (ans) {
			case 0:
				printf("Informe o elemento a ser inserido: ");
				scanf("%d", &elemento);
				if (inserir(&inicio, &fim, elemento)) {
					printf("Elemento inserido.\n");
				} else {
					printf("Elemento nao inserido.\n");
				}

				break;
			case 1:
				printf("Informe o elemento a ser removido: ");
				scanf("%d", &elemento);

				n = removePorValor(&inicio, &fim, elemento);
				if (n != NULL) {
					printf("Elemento removido: %d.\n", n->valor);
					free(n);
				} else {
					printf("Elemento nao existente.\n");
				}

				break;
			case 2:
				printf("Informe o indice do elemento a ser removido: ");
				scanf("%d", &indice);

				n = removePorIndice(&inicio, &fim, indice);
				if (n != NULL) {
					printf("Elemento removido: %d.\n", n->valor);
					free(n);
				} else {
					printf("Elemento nao existente.\n");
				}

				break;
			case 3:
				escrever(inicio, fim, ans);
				
				break;
                        case 4:
				escrever(inicio, fim, ans);
				
				break;                            
			case 5:
				desaloca(inicio);
				
				break;
			default:
				printf("Opcao invalida.\n");
				
				break;
		}
	} while (ans != 5);

	return (EXIT_SUCCESS);
}
