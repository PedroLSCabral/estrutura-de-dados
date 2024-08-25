#include <stdio.h>

struct no {
    struct no *ant;
    int dado;
    struct no *prox;
};

char ehCheio(struct no* l) {
    if (l == NULL)
        return 0;
    return 1;
}

char ehVazio(struct no* l) {
    if (l == NULL)
        return 0;
    return 1;
}

char inserirInicio(struct no* l, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL)
        return 1;

    novo->dado = num;
    novo->prox = l;
    novo->ant = NULL;
    l = novo;
    return 0;
}

char inserirFim(struct no* l, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    struct no* aux = l;

    if (novo == NULL)
        return 1;

    novo->dado = num;
    novo->prox = NULL;

    if (l == NULL) {
        l = novo;
        return 0;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    novo->ant = aux;
    return 0;
}

char inserirMeio(struct no* l, int num, int pos) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    struct no* aux = l;
    struct no* ant = NULL;

    if (novo == NULL)
        return 1;

    novo->dado = num;

    for (int i = 0; i < pos; i++) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = novo;
    novo->prox = aux;
    novo->ant = ant;
    aux->ant = novo;
    return 0;
}

char removerInicio(struct no* l) {
    struct no* aux = l;

    if (l == NULL)
        return 1;

    l = l->prox;
    l->ant = NULL;
    free(aux);
    return 0;
}

char removerFim(struct no* l) {
    struct no* aux = l;
    struct no* ant = NULL;

    if (l == NULL)
        return 1;

    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;
    free(aux);
    return 0;
}

char removerMeio(struct no* l, int pos) {
    struct no* aux = l;
    struct no* ant = NULL;

    if (l == NULL)
        return 1;

    if (pos == 0) {
        l = l->prox;
        l->ant = NULL;
        free(aux);
        return 0;
    }

    for (int i = 0; i < pos; i++) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = aux->prox;
    aux->prox->ant = ant;
    free(aux);
    return 0;
}

void mostrar(struct no* l) {
    struct no* aux = l;

    if (l == NULL) {
        printf("Lista vazia\n");
        return;
    }

    while (aux != NULL) {
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
}

int main() {
    struct no* l1 = NULL;
    int escolha, rtrn;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir valor no fim da lista\n");
        printf("2. Remover valor do fim da lista\n");
        printf("3. Remover valor da posicao X\n");
        printf("4. Limpar lista\n");
        printf("5. Mostrar lista\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &rtrn);
                if (inserirFim(l1, rtrn) == 1)
                    printf("Erro ao inserir valor\n");
                break;
            case 2:
                if (removerFim(l1) == 1)
                    printf("Erro ao remover valor\n");
                break;
            case 3:
                printf("Digite a posicao do valor a ser removido: ");
                scanf("%d", &rtrn);
                if (removerMeio(l1, rtrn) == 1)
                    printf("Erro ao remover valor\n");
                break;
            case 4:
                if (limpar(l1) == 1)
                    printf("Erro ao limpar lista\n");
                break;
            case 5:
                mostrar(l1);
                break;
            case 6:
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (escolha != 6);

    return 0;
}  