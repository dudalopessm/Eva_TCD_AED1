#include "Feedbacks.h"
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct noF {
    Feedback item;
    struct noF *prox;
}NoF;

typedef struct noF* ListaF;

ListaF *criarF() {
    ListaF *l = (ListaF*)malloc(sizeof(ListaF));
    (*l) = NULL;
    return l;
}

void liberarmemoriaF(ListaF *l) {
    if (l != NULL) {
        NoF *atual = (*l);
        while (atual != NULL) {
            NoF *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}

int listaVaziaF(ListaF *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

int tamanhoF(ListaF *l) {
    if (l == NULL) return 1;
    if (listaVaziaF(l) == 0) return 0;
    int p = 0;
    NoF *no = (*l);
    while (no != NULL) {
        p++;
        no = no->prox;
    }
    return p;
}

int inserirFeed(ListaF *l, Feedback it) {
    if (l == NULL) return 2;
    NoF *no = (NoF*)malloc(sizeof(NoF));
    if (no == NULL) return 1;
    no->item = it;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int removerFeed(ListaF *l, Feedback it) {
    if (l == NULL) return 2;
    if (listaVaziaF(l) == 0) return 1;
    NoF *ant;
    NoF *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL && no->item.cliente != it.cliente) {
        ant = no;
        no = no->prox;
    }
    if (no == (*l)) {
        (*l) = no->prox;
    } else {
        ant->prox = no->prox;
    }
    free(no);
    return 0;
}

int buscaFeedRest(ListaF *l, Feedback it) {
    if (l == NULL) return 2;
    if (listaVaziaF(l) == 0) return 3;
    NoF *noLista = (*l);
    while (noLista != NULL) {
        if (noLista->item.restaurante != it.restaurante) {
            noLista = noLista->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int buscaFeedPed(ListaF *l, Feedback it) {
    if (l == NULL) return 2;
    if (listaVaziaF(l) == 0) return 3;
    NoF *noLista = (*l);
    while (noLista != NULL) {
        if (noLista->item.pedidos != it.pedidos) {
            noLista = noLista->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

void mostrarFeedRest(ListaF *l, Feedback it) {
    if (l != NULL) {
        NoF *noLista = (*l);
        printf("\n-------------------------------------------------------------");
        while (noLista != NULL) {
            mostrarC(noLista->item.cliente);
            printf("\n");
            printf("\n %s estrelas", noLista->item.estrelas);
            printf("\n");
            printf("\n %s", noLista->item.avaliacao);
            printf("\n");
            noLista = noLista->prox;
        }
        printf("\n-------------------------------------------------------------");
    }
}

void mostrarFeedPed(ListaF *l, Feedback it); //DEPENDE DO TAD FILA PEDIDOS