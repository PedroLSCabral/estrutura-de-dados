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

//Inserção no início da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_inicio(struct lista *l, int valor) {
    struct no *novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;
    novo->prox = l->inicio;
    novo->ant = NULL;

    if (ehVazia(l)) {
        l->inicio = novo;
        l->fim = novo;
        return 0;
    }

    l->inicio->ant = novo;
    l->inicio = novo;

    return 0;
}

//Inserção no fim da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_fim(struct lista *l, int valor) {
    struct no *novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (ehVazia(l)) {
        l->inicio = novo;
        l->fim = novo;
        return 0;
    }

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
        printf("\n1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Remover do fim\n");
        printf("5 - Mostrar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor: ");
                int valor;
                scanf("%d", &valor);
                rtrn = inserir_inicio(&l, valor);
                if (rtrn == 1) {
                    printf("Erro ao alocar memoria\n");
                }
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                rtrn = inserir_fim(&l, valor);
                if (rtrn == 1) {
                    printf("Erro ao alocar memoria\n");
                }
                break;
            case 3:
                rtrn = remover_inicio(&l);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                break;
            case 4:
                rtrn = remover_fim(&l);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                break;
            case 5:
                mostrar(&l);
                break;
            case 0:
                break;
            default:
                printf("Opção invalida\n");
        }
    } while (escolha != 0);
}