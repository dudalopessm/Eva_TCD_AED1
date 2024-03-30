#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noR {
    Restaurante item;
    struct noR *prox;
}NoR;

typedef struct noR* ListaR;

ListaR *criarRest() {
    ListaR *l = (ListaR*)malloc(sizeof(ListaR));
    (*l) = NULL;
    return l;
}

void liberarmemoriaR(ListaR *l) {
    if (l != NULL) {
        NoR *atual = (*l);
        while (atual != NULL) {
            NoR *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}

int inserirRest(ListaR *l, Restaurante rest) {
    if (l == NULL) return 2;
    NoR *no = (NoR*)malloc(sizeof(NoR));
    no->item = rest;
    no->prox = (*l);
    (*l) = no;
    return 0;
} //insere no inicio

int removerRest(ListaR *l, Restaurante rest) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    NoR *ant;
    NoR *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL && no->item.CNPJ != rest.CNPJ) {
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

int buscaEmailRest(ListaR *l, char *em) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 3;
    NoR *no = (*l);
    while (no != NULL) {
        if (strcmp(no->item.email, em) != 0) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int buscaItemRest(ListaR *l, char *it) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 3;
    NoR *no = (*l);
    while (no != NULL) {
        if (strcmp(no->item.CNPJ, it) != 0) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int buscaRest(ListaR *l, char *aux, Restaurante *rest) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    NoR *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL) {
        if (strcmp(no->item.email, aux) != 0) {
            no = no->prox;
        } else {
            break;
        }
    }
    *rest = no->item;
    return 0;
}
int listaVaziaR(ListaR *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

void mostrarR(ListaR *l, char *cat) {
    if (l != NULL) {
        NoR *no = (*l);
        if (strcmp(cat, "Nao listado") == 0) {
            while (no != NULL) {
                printf("\n- %s", no->item.nomeRest);
                no = no->prox;
            }
        } else {
            while (no != NULL) {
                if (strcmp(no->item.categoria, cat) == 0) {
                    printf("\n- %s - %s", no->item.nomeRest, no->item.categoria);
                }
                no = no->prox;
            }
        }
    }
}

void mostrarPratosRest(ListaR *l) {
    if (l != NULL) {
        NoR *no = (*l);
        while (no != NULL) {
            mostrarPratos(no->item.cardapio);
            no = no->prox;
        }
    }
}

int tamanhoR (ListaR *l) {
    if (l == NULL) return 1;
    if (listaVaziaR(l) == 0) return 0;
    int p = 0;
    NoR *no = (*l);
    while (no != NULL) {
        p++;
        no = no->prox;
    }
    return p;
}