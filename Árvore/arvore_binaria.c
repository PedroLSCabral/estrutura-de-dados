#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    int dado;
    struct no *dir;
};

//Função que inicializa a árvore
void inicializar(struct no *raiz) {
    raiz = NULL;
}

//Função que verifica se a árvore está vazia
//Retorna 0 se a árvore não está vazia
//Retorna 1 se a árvore está vazia
char ehVazia(struct no *raiz) {
    if (raiz == NULL)
        return 1;
    return 0;
}

//Função que mostra a árvore
void mostra_in(struct no *raiz) {
    if(raiz) {
        mostra_in(raiz->esq);
        printf("%d\n", raiz->dado);
        mostra_in(raiz->dir);
    }
    else return;
}

//Função que insere um valor na árvore
struct no* inserir(struct no *raiz, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if (novo == NULL) {
        return raiz;
    }

    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (ehVazia(raiz)) {
        raiz = novo;
        return raiz;
    }

    struct no* aux = raiz;

    while (1) {
        if (valor < aux->dado) {
            if (aux->esq == NULL) {
                aux->esq = novo;
                return raiz;
            }
            aux = aux->esq;
        } else {
            if (aux->dir == NULL) {
                aux->dir = novo;
                return raiz;
            }
            aux = aux->dir;
        }
    }
}

//Função que limpa a árvore
void limpa(struct no *raiz) {
    if (raiz) {
        limpa(raiz->esq);
        limpa(raiz->dir);
        free(raiz);
    }
    else return;
}


//Função que conta o número de nós da árvore
int conta_nos(struct no *raiz) {
    if (raiz) {
        return (conta_nos(raiz->esq) + conta_nos(raiz->dir) + 1);
    }
    else return 0;
}

//Função que retorna a altura da árvore
int altura(struct no* raiz) {
    if (raiz) {
        int a = altura(raiz->esq);
        int b = altura(raiz->dir);
        if (a> b) {
            return (a+1);
        }
        else return (b+1);
    }
}

int main() {
    struct no* arvore = 0;

    arvore = inserir(arvore, 3);
    arvore = inserir(arvore, 1);
    arvore = inserir(arvore, 5);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 4);
    
    mostra_in(arvore);

    printf("\n%d\n", conta_nos(arvore));

    printf("%d", altura(arvore));

    return 0;

}