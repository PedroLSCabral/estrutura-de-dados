#include <stdio.h>

struct no {
    int dado;
    struct no *prox;
};

struct lista {
    struct no *inicio;
    struct no *fim;
};

char ehCheio(struct lista* l) {
    if (l->inicio == NULL)
        return 0;
    return 1;
}

char ehVazio(struct lista* l) {
    if (l->inicio == NULL)
        return 0;
    return 1;
}

char insere(struct lista* l, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL)
        return 1;

    novo->dado = num;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
        return 0;
    }

    l->fim->prox = novo;
    l->fim = novo;
    return 0;
}

char removeNo(struct lista* l, int num) {
    struct no* aux = l->inicio;
    struct no* ant = NULL;

    if (l->inicio == NULL)
        return 1;

    while (aux != NULL) {
        if (aux->dado == num) {
            if (aux == l->inicio) {
                l->inicio = aux->prox;
                free(aux);
                return 0;
            } else if (aux == l->fim) {
                l->fim = ant;
                l->fim->prox = NULL;
                free(aux);
                return 0;
            } else {
                ant->prox = aux->prox;
                free(aux);
                return 0;
            }
        }
        ant = aux;
        aux = aux->prox;
    }
    return 1;
}

void imprime(struct lista* l) {
    struct no* aux = l->inicio;

    if (ehVazio(l)) {
        while (aux != NULL) {
            printf("%d\n", aux->dado);
            aux = aux->prox;
        }
    }
}

int main() {
    struct lista l;
    l.inicio = NULL;
    l.fim = NULL;

    int opcao, dado;

    do {
        printf("Menu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir lista\n");
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
                imprime(&l);
                break;
        }
    } while (opcao != 0);

    return 0;
}