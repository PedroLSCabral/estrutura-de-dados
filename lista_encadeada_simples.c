#include <stdio.h>

struct no {
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
    return 0;
}

char removerInicio(struct no* l) {
    struct no* aux = l;

    if (l == NULL)
        return 1;

    l = l->prox;
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
        free(aux);
        return 0;
    }

    for (int i = 0; i < pos; i++) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = aux->prox;
    free(aux);
    return 0;
}

char limpar(struct no* l) {
    struct no* aux = l;
    struct no* ant = NULL;

    if (l == NULL)
        return 1;

    while (aux != NULL) {
        ant = aux;
        aux = aux->prox;
        free(ant);
    }

    l = NULL;
    return 0;
}

char mostrar(struct no* l) {
    struct no* aux = l;

    if (l == NULL)
        return 1;

    while (aux != NULL) {
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }

    return 0;
}

int main() {
    struct no* lista;
    lista = NULL;

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
                int num;
                scanf("%d", &num);
                rtrn = inserirFim(lista, num);
                if (rtrn == 1)
                    printf("Erro ao inserir valor no fim da lista\n");
                break;
            case 2:
                rtrn = removerFim(lista);
                if (rtrn == 1)
                    printf("Erro ao remover valor do fim da lista\n");
                break;
            case 3:
                printf("Digite a posição do valor a ser removido: ");
                int pos;
                scanf("%d", &pos);
                rtrn = removerMeio(lista, pos);
                if (rtrn == 1)
                    printf("Erro ao remover valor da posição %d\n", pos);
                break;
            case 4:
                rtrn = limpar(lista);
                if (rtrn == 1)
                    printf("Erro ao limpar a lista\n");
                break;
            case 5:
                rtrn = mostrar(lista);
                if (rtrn == 1)
                    printf("Erro ao mostrar a lista\n");
                break;
            case 6:
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (escolha != 6);

}