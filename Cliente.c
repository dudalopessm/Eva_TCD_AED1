#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct noC {
    Cliente item;
    struct noC *prox;
}NoC;

typedef struct noC* ListaC;

ListaC *criarCliente() {
    ListaC *l = (ListaC*)malloc(sizeof(ListaC));
    (*l) = NULL;
    return l;
}

void liberarmemoriaC(ListaC *l) { //talvez nao seja necessaria?
    if (l != NULL) {
        NoC *atual = (*l);
        while (atual != NULL) {
            NoC *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}

int inserirCliente(ListaC *l, Cliente cli) {
    if (l == NULL) return 2;
    NoC *no = (NoC*)malloc(sizeof(NoC));
    if (no == NULL) return 1;
    no->item = cli;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int removerCliente(ListaC *l, Cliente cli) {
    if (l == NULL) return 2;
    if (listaVaziaC(l) == 0) return 1;
    NoC *ant;
    NoC *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL && no->item.cpf != cli.cpf) {
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

int buscaCliente(ListaC *l, char *em, Cliente *cli) {
    if (l == NULL) return 2;
    if (listaVaziaC(l) == 0) return 3;
    NoC *noLista = (*l);
    while (noLista != NULL) {
        if (strcmp(noLista->item.email, em) != 0) {
            noLista = noLista->prox;
        } else {
            break;
        }
    }
    *cli = noLista->item;
    return 0;
}

int buscaEmailCliente(ListaC *l, char *em) {
    if (l == NULL) return 2;
    if (listaVaziaC(l) == 0) return 3;
    NoC *noLista = (*l);
    while (noLista != NULL) {
        if (strcmp(noLista->item.email, em) != 0) {
            noLista = noLista->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int procuraCliente(ListaC *l, char *aux) {
    if (l == NULL) return 2;
    if (listaVaziaC(l) == 0) return 3;
    NoC *noLista = (*l);
    while (noLista != NULL) {
        if (strcmp(noLista->item.cpf, aux) != 0) {
            noLista = noLista->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int listaVaziaC(ListaC *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

void mostrarC(ListaC *l) {
    if (l != NULL) {
        printf("[");
        NoC *noLista = (*l);
        while (noLista != NULL) {
            printf(" {%s}",noLista->item.nome);
            noLista = noLista->prox;
        }
        printf("]");
    }
}

int tamanhoC (ListaC *l) {
    if (l == NULL) return 1;
    if (listaVaziaC(l) == 0) return 0;
    int p = 0;
    NoC *no = (*l);
    while (no != NULL) {
        p++;
        no = no->prox;
    }
    return p;
}