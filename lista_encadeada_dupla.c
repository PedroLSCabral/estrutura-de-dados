#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *ant;
    int dado;
    struct no *prox;
};

struct lista {
    struct no *inicio;
    struct no *fim;
};

//Função que verifica se a lista está vazia
char ehVazia(struct lista *l) {
    if (l->inicio == NULL)
        return 1;
    return 0;
}

//Função que inicializa a lista
void inicializar(struct lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

//Inserção no início da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_inicio(struct lista *l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;

    if (ehVazia(l)) {
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
        l->fim = novo;
        return 0;
    }

    novo->prox = l->inicio;
    novo->ant = l->fim;
    l->inicio->ant = novo;
    l->fim->prox = novo;
    l->inicio = novo;

    return 0;
}

//Inserção no fim da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_fim(struct lista *l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;

    if (ehVazia(l)) {
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
        l->fim = novo;
        return 0;
    }

    novo->prox = l->inicio;
    novo->ant = l->fim;
    l->inicio->ant = novo;
    l->fim->prox = novo;
    l->fim = novo;

    return 0;
}

//Remoção do início da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_inicio(struct lista *l) {
    if (ehVazia(l)) {
        return 1;
    }

    struct no* aux = l->inicio;

    if (l->inicio == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        return 0;
    }

    l->inicio = l->inicio->prox;
    l->inicio->ant = l->fim;
    l->fim->prox = l->inicio;
    free(aux);

    return 0;
}

//Remoção do fim da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_fim(struct lista *l) {
    if (ehVazia(l)) {
        return 1;
    }

    struct no* aux = l->fim;

    if (l->inicio == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        return 0;
    }

    l->fim = l->fim->ant;
    l->fim->prox = l->inicio;
    l->inicio->ant = l->fim;
    free(aux);

    return 0;
}

//Função que mostra os elementos da lista
void mostrar(struct lista *l) {
    struct no* aux = l->inicio;

    if (ehVazia(l)) {
        printf("Lista vazia\n");
        return;
    }

    if (l->inicio == l->fim) {
        printf("\nLista:\n");
        printf("%d -> Inicio\n", l->inicio->dado);
        return;
    }

    printf("\nLista:\n");
    do {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    } while (aux != l->inicio);

    printf("Inicio\n");
}

int main() {
    struct lista l;
    inicializar(&l);

    int escolha, rtrn;

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
                if (inserir_inicio(&l, rtrn)) {
                    printf("Erro ao inserir\n");
                }
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &rtrn);
                if (inserir_fim(&l, rtrn)) {
                    printf("Erro ao inserir\n");
                }
                break;
            case 3:
                if (remover_inicio(&l)) {
                    printf("Erro ao remover\n");
                }
                break;
            case 4:
                if (remover_fim(&l)) {
                    printf("Erro ao remover\n");
                }
                break;
            case 5:
                mostrar(&l);
                break;
            case 6:
                break;
            default:
                printf("Opção invalida\n");
        }
    } while (escolha != 6);
}