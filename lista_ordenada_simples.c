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

char inserir_ordenado(struct no** l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;

    if (ehVazia(*l)) {
        novo->prox = NULL;
        *l = novo;
        return 0;
    }

    struct no* aux = *l;

    if (aux->dado >= valor) {
        novo->prox = aux;
        *l = novo;
        return 0;
    }

    while (aux->prox != NULL && aux->prox->dado < valor) {
        aux = aux->prox;
    }

    if (aux->prox == NULL) {
        novo->prox = NULL;
        aux->prox = novo;
        return 0;
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    return 0;
}

//Remoção do início da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_inicio(struct no** l) {
    if (ehVazia(*l)) {
        return 1;
    }

    struct no* aux = *l;

    *l = (*l)->prox;
    free(aux);

    return 0;

}

//Remoção do fim da lista
//Retorna 0 se a remoção foi bem sucedida
//Retorna 1 se a lista estava vazia
char remover_fim(struct no** l) {
    if (ehVazia(*l)) {
        return 1;
    }

    struct no* aux = *l;

    if (aux->prox == NULL) {
        *l = NULL;
        free(aux);
        return 0;
    }

    struct no* ant = NULL;

    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;
    free(aux);
}

//Função que mostra os elementos da lista
//Retorna 0 se a lista foi mostrada com sucesso
//Retorna 1 se a lista está vazia
char mostrar(struct no* l) {
    struct no* aux = l;

    if (ehVazia(l)) {
        printf("Lista vazia\n");
        return 1;
    }

    printf("\nLista:\n");
    while (aux != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }

    printf("NULL\n");

    return 0;
}

int main() {
    struct no* l = NULL;

    int escolha, rtrn;

    do {
        printf("\nMenu\n");
        printf("1 - Inserir\n");
        printf("2 - Remover no inicio\n");
        printf("3 - Remover no fim\n");
        printf("4 - Mostrar\n");
        printf("5 - Sair\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor: ");
                int valor;
                scanf("%d", &valor);
                rtrn = inserir_ordenado(&l, valor);
                if (rtrn == 1) {
                    printf("Erro ao alocar memoria\n");
                }
                break;
            case 2:
                rtrn = remover_inicio(&l);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                break;
            case 3:
                rtrn = remover_fim(&l);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                break;
            case 4:
                rtrn = mostrar(l);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                break;
            case 5:
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (escolha != 5);
}