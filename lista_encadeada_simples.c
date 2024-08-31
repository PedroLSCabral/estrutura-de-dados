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
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;
    novo->prox = *l;

    *l = novo;

    return 0;
}

//Inserção no fim da lista
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char inserir_fim(struct no** l, int valor) {
    struct no* novo = (struct no*)malloc(sizeof(struct no));

    if (novo == NULL) {
        return 1;
    }

    novo->dado = valor;
    novo->prox = NULL;

    if (ehVazia(*l)) {
        *l = novo;
        return 0;
    }

    struct no* aux = *l;

    while (aux->prox != NULL) {
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

//Função que limpa o terminal
void clrscr() {
    printf("\e[1;1H\e[2J");
}

int main() {
    struct no* l1 = NULL;
    int escolha, rtrn;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir valor no inicio da lista\n");
        printf("2. Inserir valor no fim da lista\n");
        printf("3. Remover valor do inicio da lista\n");
        printf("4. Remover valor do fim da lista\n");
        printf("5. Mostrar lista\n");
        printf("6. Sair\n");
        scanf("%d", &escolha);
        clrscr();

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                int valor;
                scanf("%d", &valor);
                rtrn = inserir_inicio(&l1, valor);
                if (rtrn == 1) {
                    printf("Erro ao alocar memoria\n");
                }
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                rtrn = inserir_fim(&l1, valor);
                if (rtrn == 1) {
                    printf("Erro ao alocar memoria\n");
                }
                clrscr();
                break;
            case 3:
                rtrn = remover_inicio(&l1);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                clrscr();
                break;
            case 4:
                rtrn = remover_fim(&l1);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                clrscr();
                break;
            case 5:
                rtrn = mostrar(l1);
                if (rtrn == 1) {
                    printf("Lista vazia\n");
                }
                break;
            case 6:
                break;
            default:
                printf("Opção invalida\n");
        }

    } while (escolha != 6);

    return 0;
}
