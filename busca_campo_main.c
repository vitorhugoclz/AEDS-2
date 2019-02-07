/*Projeto de busca de campo em Arvore Binaria de Busca
 Equipe:Vitor Hugo (2018.1.08.023)
        Luiz Gustavo (2018.1.08.025)*/

#include "arvore.h"

noArvore * menu_rg(noArvore * arvore) {
    int opcao;
    printf("\n[0] Inserir\n");
    printf("[1] Buscar\n");
    printf("[2] Retornar\n");
    scanf(" %d", &opcao);
    switch (opcao) {
            noArvore * novo;
            long int rg;
            char cpf[12], nome[30];
        case 0:
            if ((arvore != NULL) && (arvore->tipo == RG)) {
                int prof = 0;
                printf("Digite o RG: ");
                scanf("%ld", &rg);
                printf("Digite o nome completo: ");
                scanf(" %s", nome);
                printf("Digite o CPF com 11 digitos: ");
                scanf(" %s", cpf);
                novo = criar_no(nome, rg, cpf);
                arvore = insere_abb_rg(arvore, NULL, novo, &prof);
                printf("\nProfundidade da inserção: %d", prof);
            } else {
                printf("Digite o RG: ");
                scanf("%ld", &rg);
                printf("Digite o nome completo: ");
                scanf(" %s", nome);
                printf("Digite o CPF com 11 digitos: ");
                scanf(" %s", cpf);
                novo = criar_no(nome, rg, cpf);

                noArvore * aux = NULL, *temporaria = NULL;
                int prof = 0;
                while (arvore != NULL) {
                    arvore = remover_raiz(arvore, &aux);
                    aux->dir = NULL;
                    aux->esq = NULL;
                    temporaria = insere_abb_rg(temporaria, NULL, aux, &prof);
                }
                arvore = temporaria;
                prof = 0;
                arvore = insere_abb_rg(arvore, NULL, novo, &prof);
                arvore->tipo = RG;
                printf("\nProfundidade da inserção: %d", prof);
                return arvore;
            }
            break;
        case 1:
            printf("Digite o valor de RG que deseja buscar: ");
            scanf(" %ld", &rg);
            if ((arvore != NULL) && (arvore->tipo == RG)) {
                int prof = 0;
                novo = busca_abb_rg(arvore, rg, &prof);
                if (novo != NULL) {
                    printf("Dados encontrado:\n");
                    printf("Nome: %s\nRG: %ld\nCPF: %s", novo->nome, novo->rg, novo->cpf);
                    printf("\nProfudidande da busca: %d", prof);
                    printf("\nSe deseja excluir esse registro digite 1:\n");
                    scanf(" %d", &opcao);
                    if (opcao == 1) {
                        if (novo != arvore) {
                            noArvore * pai = novo->pai;
                            if (pai->esq == novo)
                                pai->esq = remover_no(novo);
                            else
                                pai->dir = remover_no(novo);
                        } else {
                            novo = remover_no(novo);
                            return novo;
                        }
                    }
                } else
                    printf("Não uma pessoa com esse RG registrada\nRetornando ao menu principal\n");
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
                if (arvore != NULL)
                    arvore->tipo = RG;
                prof = 0;
                novo = busca_abb_rg(arvore, rg, &prof);
                if (novo != NULL) {
                    printf("Dados encontrado:\n");
                    printf("Nome: %s\nRG: %ld\nCPF: %s", novo->nome, novo->rg, novo->cpf);
                    printf("\nProfundidade da busca: %d", prof);
                    printf("\nSe deseja excluir esse registro digite 1 ou 0 para sair:\n");
                    scanf(" %d", &opcao);
                    if (opcao == 1) {
                        if (novo != arvore) {
                            noArvore * pai = novo->pai;
                            if (pai->esq == novo)
                                pai->esq = remover_no(novo);
                            else
                                pai->dir = remover_no(novo);
                        } else {
                            novo = remover_no(novo);
                            if(novo != NULL)
                                novo->tipo = RG;
                            return novo;
                        }
                    }
                } else
                    printf("Não uma pessoa com esse RG registrada\nRetornando ao menu principal\n");
                return arvore;
            }
            break;
        default:
            break;
    }
    return arvore;
}

noArvore * menu_cpf(noArvore * arvore) {
    int opcao;
    printf("\n[0] Inserir\n");
    printf("[1] Buscar\n");
    printf("[2] Retornar\n");
    scanf(" %d", &opcao);
    switch (opcao) {
            noArvore * novo;
            long int rg;
            char cpf[12], nome[30];
        case 0:
            if ((arvore != NULL) && (arvore->tipo == CPF)) {
                printf("Digite o RG: ");
                scanf("%ld", &rg);
                printf("Digite o nome completo: ");
                scanf(" %s", nome);
                printf("Digite o CPF com 11 digitos: ");
                scanf(" %s", cpf);
                novo = criar_no(nome, rg, cpf);
                int prof = 0;
                arvore = insere_abb_cpf(arvore, NULL, novo, &prof);
                printf("\nA profundidade da inserção: %d\n", prof);
            } else {
                printf("Digite o RG: ");
                scanf("%ld", &rg);
                printf("Digite o nome completo: ");
                scanf(" %s", nome);
                printf("Digite o CPF com 11 digitos: ");
                scanf(" %s", cpf);
                novo = criar_no(nome, rg, cpf);

                noArvore * aux = NULL, *temporaria = NULL;
                int prof = 0;
                while (arvore != NULL) {
                    arvore = remover_raiz(arvore, &aux);
                    aux->dir = NULL;
                    aux->esq = NULL;
                    temporaria = insere_abb_cpf(temporaria, NULL, aux, &prof);
                }
                arvore = temporaria;
                prof = 0;
                arvore = insere_abb_cpf(arvore, NULL, novo, &prof);
                arvore->tipo = CPF;
                printf("\nA profundidade da inserção: %d\n", prof);
                return arvore;
            }
            break;
        case 1:
            printf("Digite o valor de CPF que deseja buscar: ");
            scanf(" %s", cpf);
            if ((arvore != NULL) && (arvore->tipo == CPF)) {
                int prof = 0;
                novo = busca_abb_cpf(arvore, cpf, &prof);
                if (novo != NULL) {
                    printf("Dados encontrados: \n");
                    printf("Nome: %s\nRG: %ld\nCPF: %s", novo->nome, novo->rg, novo->cpf);
                    printf("\nProfundidade da busca: %d", prof);
                    printf("\nSe deseja excluir esse registro digite 1 ou 0 para sair:\n");
                    scanf(" %d", &opcao);
                    if (opcao == 1) {
                        if (novo != arvore) {
                            noArvore * pai = novo->pai;
                            if (pai->esq == novo)
                                pai->esq = remover_no(novo);
                            else
                                pai->dir = remover_no(novo);
                        } else {
                            novo = remover_no(novo);
                            return novo;
                        }
                    }
                } else
                    printf("Não há uma pessoa com esse CPF registrado\nRetornando ao menu principal\n");
            } else {
                noArvore * aux = NULL, *temporaria = NULL;
                int prof = 0;
                while (arvore != NULL) {
                    arvore = remover_raiz(arvore, &aux);
                    aux->dir = NULL;
                    aux->esq = NULL;
                    temporaria = insere_abb_cpf(temporaria, NULL, aux, &prof);
                }
                arvore = temporaria;
                if (arvore != NULL)
                    arvore->tipo = CPF;
                prof = 0;
                novo = busca_abb_cpf(arvore, cpf, &prof);
                if (novo != NULL) {
                    printf("Dados encontrado:\n");
                    printf("Nome: %s\nRG: %ld\nCPF: %s", novo->nome, novo->rg, novo->cpf);
                    printf("\nProfundidade da busca: %d", prof);
                    printf("\nSe deseja excluir esse registro digite 1 ou 0 para sair:\n");
                    scanf(" %d", &opcao);
                    if (opcao == 1) {
                        if (novo != arvore) {
                            noArvore * pai = novo->pai;
                            if (pai->esq == novo)
                                pai->esq = remover_no(novo);
                            else
                                pai->dir = remover_no(novo);
                        } else {
                            novo = remover_no(novo);
                            if(novo != NULL)
                                novo->tipo = CPF;
                            return novo;
                        }
                    }
                } else
                    printf("Não uma pessoa com esse CPF registrado\nRetornando ao menu principal\n");
                return arvore;
            }
            break;
        default:
            break;
    }
    return arvore;
}

noArvore * menu_nome(noArvore * arvore) {
    int opcao;
    printf("\n[0] Inserir\n");
    printf("[1] Buscar\n");
    printf("[2] Retornar\n");
    scanf(" %d", &opcao);
    switch (opcao) {
            noArvore * novo;
            long int rg;
            char cpf[12], nome[30];
        case 0:
            if ((arvore != NULL) && (arvore->tipo == NOME)) {
                int prof = 0;
                printf("Digite o RG: ");
                scanf("%ld", &rg);
                printf("Digite o nome completo: ");
                scanf(" %s", nome);
                printf("Digite o CPF com 11 digitos: ");
                scanf(" %s", cpf);
                novo = criar_no(nome, rg, cpf);
                arvore = insere_abb_nome(arvore, NULL, novo, &prof);
                printf("Profundida da inserção: %d\n", prof);
            } else {
                printf("Digite o RG: ");
                scanf("%ld", &rg);
                printf("Digite o nome completo: ");
                scanf(" %s", nome);
                printf("Digite o CPF com 11 digitos: ");
                scanf(" %s", cpf);
                novo = criar_no(nome, rg, cpf);

                noArvore * aux = NULL, *temporaria = NULL;
                int prof = 0;
                while (arvore != NULL) {
                    arvore = remover_raiz(arvore, &aux);
                    aux->dir = NULL;
                    aux->esq = NULL;
                    temporaria = insere_abb_nome(temporaria, NULL, aux, &prof);
                }
                arvore = temporaria;
                prof = 0;
                arvore = insere_abb_nome(arvore, NULL, novo, &prof);
                arvore->tipo = NOME;
                printf("Profundida da inserção: %d", prof);
                return arvore;
            }
            break;
        case 1:
            printf("Digite o valor o nome que deseja buscar: ");
            scanf(" %s", nome);

            if ((arvore != NULL) && (arvore->tipo == NOME)) {
                int prof = 0;
                novo = busca_abb_nome(arvore, nome, &prof);
                if (novo != NULL) {
                    printf("Dados encontrados: \n");
                    printf("Nome: %s\nRG: %ld\nCPF: %s", novo->nome, novo->rg, novo->cpf);
                    printf("\nProfundidade da busca: %d", prof);
                    printf("\nSe deseja excluir esse registro digite 1 ou 0 para sair:\n");
                    scanf(" %d", &opcao);
                    if (opcao == 1) {
                        if (novo != arvore) {
                            noArvore * pai = novo->pai;
                            if (pai->esq == novo)
                                pai->esq = remover_no(novo);
                            else
                                pai->dir = remover_no(novo);
                        } else {
                            novo = remover_no(novo);
                            return novo;
                        }
                    }
                } else
                    printf("Não uma pessoa com esse CPF registrado\nRetornando ao menu principal\n");
                break;
            } else {
                noArvore * aux = NULL, *temporaria = NULL;
                int prof = 0;
                while (arvore != NULL) {
                    arvore = remover_raiz(arvore, &aux);
                    aux->dir = NULL;
                    aux->esq = NULL;
                    temporaria = insere_abb_nome(temporaria, NULL, aux, &prof);
                }
                arvore = temporaria;
                if (arvore != NULL)
                    arvore->tipo = NOME;
                prof = 0;
                novo = busca_abb_nome(arvore, nome, &prof);
                if (novo != NULL) {
                    printf("Dados encontrado:\n");
                    printf("Nome: %s\nRG: %ld\nCPF: %s", novo->nome, novo->rg, novo->cpf);
                    printf("\nProfundidade da busca: %d", prof);
                    printf("\nSe deseja excluir esse registro digite 1 ou 0 para sair:\n");
                    scanf(" %d", &opcao);
                    if (opcao == 1) {
                        if (novo != arvore) {
                            noArvore * pai = novo->pai;
                            if (pai->esq == novo)
                                pai->esq = remover_no(novo);
                            else
                                pai->dir = remover_no(novo);
                        } else {
                            novo = remover_no(novo);
                            if(novo != NULL)
                                novo->tipo = NOME;
                            return novo;
                        }
                    }
                } else
                    printf("Não uma pessoa com esse nome registrado\nRetornando ao menu principal\n");
                return arvore;
            }
            break;
        default:
            break;
    }
    return arvore;
}

int main(int argc, char** argv) {
    noArvore * arvore = NULL, * novo;
    arvore = abrir_arq();
    int opcao;

    do {
        printf("\n[0] Dados por Rg\n");
        printf("[1] Dados por CPF\n");
        printf("[2] Dados por nome\n");
        printf("[3] Exibir todos os dados\n");
        printf("[4] Sair\n");
        scanf(" %d", &opcao);
        switch (opcao) {
            case 0:
                arvore = menu_rg(arvore);
                break;
            case 1:
                arvore = menu_cpf(arvore);
                break;
            case 2:
                arvore = menu_nome(arvore);
                break;
            case 3:
                if (arvore != NULL) {
                    if (arvore->tipo == RG)
                        printf("Os dados exibidos estarão organizados segundo o RG\n");
                    else 
                    {
                        if (arvore->tipo == CPF)
                        printf("Os dados exibidos estarão organizados segundo o CPF\n");
                        else
                            printf("Os dados exibidos estarão organizados segundo o NOME\n");
                    }
                    printf("A exibição será em modo pré-ordem\n");
                    pre_ordem(arvore, arvore->tipo);
                } else
                    printf("Não há dados na arvore");
                break;
            default:
                break;
        }
    } while (opcao != 4);
    escrever(arvore);
    return (EXIT_SUCCESS);
}

