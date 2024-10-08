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

//Função que insere um elemento no topo da pilha
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a alocação de memória falhou
char push(struct no** l, int valor) {
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

    novo->prox = *l;
    *l = novo;

    return 0;
}

//Função que retira um elemento do topo da pilha
//Retorna 0 se a inserção foi bem sucedida
//Retorna 1 se a pilha está vazia
char pop(struct no** l) {
    if (ehVazia(*l)) {
        return 1;
    }

    struct no* aux = *l;

    *l = (*l)->prox;
    free(aux);

    return 0;
}

//Função que mostra o elemento do topo da pilha
//Retorna 0 se a pilha não está vazia
//Retorna 1 se a pilha está vazia
char peek(struct no* l) {
    if (ehVazia(l)) {
        return 1;
    }

    printf("Topo da pilha: %d", l->dado);
}

int main() {
    struct no* p = NULL;
    int escolha, rtrn;

    do {
        printf("\nMenu\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Checar\n");
        printf("4. Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &escolha);
                rtrn = push(&p, escolha);
                if (rtrn == 1) {
                    printf("Erro ao inserir valor\n");
                }
                break;
            case 2:
                rtrn = pop(&p);
                if (rtrn == 1) {
                    printf("Pilha Vazia\n");
                }
                break;
            case 3:
                rtrn = peek(p);
                if (rtrn == 1) {
                    printf("Pilha vazia\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (escolha != 4);

}