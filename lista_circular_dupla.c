#include <stdio.h>

struct no {
    struct no *ant;
    int dado;
    struct no *prox;
};

struct lista {
    struct no *inicio;
    struct no *fim;
};

char ehVazio(struct lista* l) {
    if (l == NULL)
        return 0;
    return 1;
}

void inicializa(struct lista* l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void insere(struct lista* l, int dado) {
    struct no *novo = (struct no*) malloc(sizeof(struct no));
    novo->dado = dado;
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
        novo->prox = novo;
        novo->ant = novo;
    } else {
        novo->prox = l->inicio;
        novo->ant = l->fim;
        l->fim->prox = novo;
        l->inicio->ant = novo;
        l->fim = novo;
    }
}

void imprime(struct lista* l) {
    struct no *aux = l->inicio;
    if (ehVazio(l)) {
        do {
            printf("%d\n", aux->dado);
            aux = aux->prox;
        } while (aux != l->inicio);
    }
}

void imprimeReverso(struct lista* l) {
    struct no *aux = l->fim;
    if (ehVazio(l)) {
        do {
            printf("%d\n", aux->dado);
            aux = aux->ant;
        } while (aux != l->fim);
    }
}

void removeNo(struct lista* l, int dado) {
    struct no *aux = l->inicio;
    if (ehVazio(l)) {
        do {
            if (aux->dado == dado) {
                if (aux == l->inicio) {
                    l->inicio = aux->prox;
                    l->fim->prox = l->inicio;
                    l->inicio->ant = l->fim;
                    free(aux);
                    return;
                } else if (aux == l->fim) {
                    l->fim = aux->ant;
                    l->inicio->ant = l->fim;
                    l->fim->prox = l->inicio;
                    free(aux);
                    return;
                } else {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux);
                    return;
                }
            }
            aux = aux->prox;
        } while (aux != l->inicio);
    }
}

int main() {
    struct lista l;
    inicializa(&l);
    
    int opcao, dado;
    
    do {
        printf("Menu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Imprimir lista reversa\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &dado);
                insere(&l, dado);
                printf("Elemento inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &dado);
                removeNo(&l, dado);
                printf("Elemento removido com sucesso!\n");
                break;
            case 3:
                printf("Lista:\n");
                imprime(&l);
                break;
            case 4:
                printf("Lista reversa:\n");
                imprimeReverso(&l);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);
    
    return 0;
}