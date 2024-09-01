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

//Função que inicializa a lista
void inicializar(struct lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

//Função que verifica se a lista está vazia
//Retorna 0 se a lista não está vazia
//Retorna 1 se a lista está vazia
char ehVazia(struct lista *l) {
    if (l->inicio == NULL)
        return 1;
    return 0;
}

//Inserção ordenada na lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_ordenado(struct lista *l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;

    if (ehVazia(l)) { //Inserção na lista vazia
        novo->prox = NULL;
        novo->ant = NULL;
        l->inicio = novo;
        l->fim = novo;
        return 0;
    }

    struct no* aux = l->inicio;

    if (aux->dado >= valor) { //Inserção no início
        novo->prox = aux;
        novo->ant = NULL;
        aux->ant = novo;
        l->inicio = novo;
        return 0;
    }

    while (aux->prox != NULL && aux->prox->dado < valor) {
        aux = aux->prox;
    }

    if (aux->prox == NULL) { //Inserção no fim
        novo->prox = NULL;
        novo->ant = aux;
        aux->prox = novo;
        l->fim = novo;
        return 0;
    }

    novo->prox = aux->prox; //Inserção no meio
    novo->ant = aux;
    aux->prox->ant = novo;
    aux->prox = novo;

    return 0;

}

//Remoção do início da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_inicio(struct lista *l) {
    if (ehVazia(l)) {
        return 1;
    }

    struct no *aux = l->inicio;
    
    if (l->inicio == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        return 0;
    }

    l->inicio = l->inicio->prox;
    l->inicio->ant = NULL;
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

    struct no *aux = l->fim;

    if (l->inicio == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        return 0;
    }

    l->fim = l->fim->ant;
    l->fim->prox = NULL;
    free(aux);

    return 0;
}

//Função que mostra os elementos da lista
void mostrar(struct lista *l) {
    struct no *aux = l->inicio;

    if (ehVazia(l)) {
        printf("Lista vazia\n");
        return;
    }

    printf("\nLista:\n");
    while (aux != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }

    printf("NULL\n");
}

int main() {
    struct lista l;
    inicializar(&l);

    int escolha, rtrn;

    do {
        printf("\nMenu:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover no inicio\n");
        printf("3 - Remover no fim\n");
        printf("4 - Mostrar\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &rtrn);
                inserir_ordenado(&l, rtrn);
                break;
            case 2:
                remover_inicio(&l);
                break;
            case 3:
                remover_fim(&l);
                break;
            case 4:
                mostrar(&l);
                break;
            case 5:
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (escolha != 5);
}