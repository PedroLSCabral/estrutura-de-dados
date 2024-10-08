#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

char ehVazia(struct no* l) {
    if (l == NULL)
        return 1;
    return 0;
};

char push(struct no** l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;
    novo->prox = NULL;

    if (ehVazia(*l)) {
        novo->prox = NULL;
        *l = novo;
        return 0;
    };

    struct no* aux = *l;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return 0;
};

char pop(struct no** l) {
    if (ehVazia(*l)) {
        return 1;
    }

    struct no* aux = *l;

    *l = (*l)->prox;
    free(aux);
    return 0;
};


char peek(struct no* l) {
    if (ehVazia(l)) {
        printf("Fila vazia\n");
        return 1;
    }

    printf("Topo da fila: %d\n", l->dado);
};

char show(struct no** l) {
    if (ehVazia(*l)) {
        printf("Fila vazia\n");
        return 1;
    }

    printf("\nFila:\n");

    while (!ehVazia(*l)) {
        printf("%d\n", (*l)->dado);
        pop(l);
    }
};

int main() {
    struct no* f = NULL;
    
    push(&f, 1);
    push(&f, 2);
    push(&f, 3);
    push(&f, 4);
    push(&f, 5);

    printf("Elementos inseridos\n");

    peek(f);

    show(&f);

    peek(f);

    return 0;
};