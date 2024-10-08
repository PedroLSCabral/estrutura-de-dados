#include <stdio.h>

#define TAM_LISTA 10

struct lista {
    int dados[TAM_LISTA];
    int controle;
};

void inicializa(struct lista* l) {
    l->controle = -1;
}

char ehVazio(struct lista* l) {
    if (l->controle == -1)
        return 0;
    return 1;
}

char ehCheio(struct lista* l) {
    if (l->controle == TAM_LISTA - 1)
        return 0;
    return 1;
}

void insere(struct lista* l, int dado) {
    if (ehCheio(l)) {
        l->controle++;
        l->dados[l->controle] = dado;
    }
}

void imprime(struct lista* l) {
    if (ehVazio(l)) {
        for (int i = 0; i <= l->controle; i++)
            printf("%d\n", l->dados[i]);
    }
}

void removeNo(struct lista* l, int dado) {
    if (ehVazio(l)) {
        for (int i = 0; i <= l->controle; i++) {
            if (l->dados[i] == dado) {
                for (int j = i; j < l->controle; j++)
                    l->dados[j] = l->dados[j + 1];
                l->controle--;
                return;
            }
        }
    }
}

int main() {
    struct lista l;
    inicializa(&l);
    
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
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
