#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

//Função que verifica se a lista está vazia
//Retorna 0 se a lista não está vazia
//Retorna 1 se a lista está vazia
char ehVazia(struct no* l) {
    if (l == NULL)
        return 1;
    return 0;
}

//Inserção no início da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_inicio(struct no** l, int valor) {
    struct no *novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;

    if (ehVazia(*l)) {
        novo->prox = novo;
        *l = novo;
        return 0;
    }

    novo->prox = *l;
    struct no *aux = *l;

    while (aux->prox != *l) {
        aux = aux->prox;
    }

    aux->prox = novo;
    *l = novo;

    return 0;
}

//Inserção no fim da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_fim(struct no** l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;

    if (ehVazia(*l)) {
        *l = novo;
        novo->prox = novo;
        return 0;
    }

    novo->prox = *l;
    struct no* aux = *l;

    while (aux->prox != *l) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return 0;
}

//Remoção do início da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_inicio(struct no** l) {
    if (ehVazia(*l)) {
        printf("Lista vazia\n");
        return 1;
    }

    struct no* aux = *l;
    struct no* ultimo = *l;

    while (ultimo->prox != *l) {
        ultimo = ultimo->prox;
    }

    *l = (*l)->prox;
    ultimo->prox = *l;
    free(aux);

    return 0;
}

//Remoção do fim da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_fim(struct no** l) {
    if (ehVazia(*l)) {
        printf("Lista vazia\n");
        return 1;
    }

    struct no* aux = *l;
    struct no* ant = NULL;

    while (aux->prox != *l) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = *l;
    free(aux);

    return 0;
}

//Função que mostra os elementos da lista
void mostrar(struct no* l) {
    struct no* aux = l;

    if (ehVazia(l)) {
        printf("Lista vazia\n");
        return;
    }

    printf("\nLista:\n");

    do {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    } while (aux != l);

    printf("Inicio\n");
}

int main() {
    struct no* lista = NULL;

    int escolha = 0, rtrn;

    do {
        printf("\nMenu\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Remover do fim\n");
        printf("5 - Mostrar lista\n");
        printf("6 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &rtrn);
                if (inserir_inicio(&lista, rtrn)) {
                    printf("Erro ao inserir\n");
                }
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &rtrn);
                if (inserir_fim(&lista, rtrn)) {
                    printf("Erro ao inserir\n");
                }
                break;
            case 3:
                if (remover_inicio(&lista)) {
                    printf("Erro ao remover\n");
                }
                break;
            case 4:
                if (remover_fim(&lista)) {
                    printf("Erro ao remover\n");
                }
                break;
            case 5:
                mostrar(lista);
                break;
            case 6:
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (escolha != 6);
}