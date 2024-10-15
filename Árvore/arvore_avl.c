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

//Função que retorna o fator de balanceamento
int fator_balanceamento(struct no* raiz) {
    return (altura(raiz->esq) - altura(raiz->dir));
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
        printf("Inserido na raiz\n");
        return raiz;
    }

    struct no* aux = raiz;

    while (1) {
        if (valor < aux->dado) {
            if (aux->esq == NULL) {
                aux->esq = novo;
                printf("Inserido %d a esquerda de %d\n", valor, aux->dado);
                return raiz;
            }
            aux = aux->esq;
        } else {
            if (aux->dir == NULL) {
                aux->dir = novo;
                printf("Inserido %d a direita de %d\n", valor, aux->dado);
                return raiz;
            }
            aux = aux->dir;
        }
    }
}

//Função que faz a rotação simples esquerda
struct no* RR(struct no* raiz) { //Rotação esquerda
    struct no* aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    return aux;
}

//Função que faz a rotação simples direita
struct no* LL(struct no* raiz) { //Rotação direita
    struct no* aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    return aux;
}

//Função que faz os balanceamentos necessários
struct no* balancear(struct no* raiz) {
    if (raiz) {
        raiz->esq = balancear(raiz->esq);
        raiz->dir = balancear(raiz->dir);
        if (fator_balanceamento(raiz) > 1) {
            if (fator_balanceamento(raiz->esq) > 0) {
                //Rotação simples à direita
                printf("Rotacao simples a direita\n");
                return LL(raiz);
            }
            else {
                //Rotação dupla à direita
                printf("Rotacao dupla a direita\n");
                raiz->esq = RR(raiz->esq);
                return LL(raiz);
            }
        }
        else if (fator_balanceamento(raiz) < -1) {
            if (fator_balanceamento(raiz->dir) < 0) {
                //Rotação simples à esquerda
                printf("Rotacao simples a esquerda\n");
                return RR(raiz);
            }
            else {
                //Rotação dupla à esquerda
                printf("Rotacao dupla a esquerda\n");
                raiz->dir = LL(raiz->dir);
                return RR(raiz);
            
            }
        }
        else {
            printf("Arvore balanceada\n");
            return raiz;

        }
    }
    else return raiz;
    
}

//Função que insere um valor na árvore AVL
struct no* insercao_avl(struct no* raiz, int valor) {
    struct no* aux = raiz;
    aux = inserir(aux, valor);
    aux = balancear(aux);
    return aux;
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

int main() {
    struct no* arvore = 0;

    arvore = insercao_avl(arvore, 10);
    arvore = insercao_avl(arvore, 5);
    arvore = insercao_avl(arvore, 15);
    arvore = insercao_avl(arvore, 14);
    arvore = insercao_avl(arvore, 13);
    
    mostra_in(arvore);

    printf("\n%d\n", conta_nos(arvore));

    printf("%d\n", altura(arvore));

    printf("%d\n", fator_balanceamento(arvore));
    printf("%d\n", fator_balanceamento(arvore->dir));


    return 0;

}