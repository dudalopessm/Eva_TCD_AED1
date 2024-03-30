#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noP {
    Pratos item;
    struct noP *prox;
}NoP;

typedef struct noP* ListaP;

ListaP *criarP() {
    ListaP *l = (ListaP*)malloc(sizeof(ListaP));
    (*l) = NULL;
    return l;
}

void liberarmemoriaP(ListaP *l) {
    if (l != NULL) {
        NoP *atual = (*l);
        while (atual != NULL) {
            NoP *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}

int inserirPrato(ListaP *l, Pratos it) {
    if (l == NULL) return 2;
    NoP *no = (NoP*)malloc(sizeof(NoP));
    no->item = it;
    no->prox = (*l);
    (*l) = no;
    return 0;
} //insercao no inicio

int removerPrato(ListaP *l, Pratos it) {
    if (l == NULL) return 2;
    if (listaVaziaP(l) == 0) return 1;
    NoP *ant;
    NoP *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL && no->item.codigo != it.codigo) {
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

int alteraPrato(ListaP *l, Pratos it) {
    if (l == NULL) return 2;
    if (listaVaziaP(l) == 0) return 1;
    NoP *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL) {
        if (no->item.codigo != it.codigo) {
            no = no->prox;
        } else {
            break;
        }
    }
    if (it.preco != 0) {
        no->item.preco = it.preco;
    }
    if (it.ingredientes[0] != '-') {
        strcpy(no->item.ingredientes, it.ingredientes);
    }
    if (it.nome[0] != '-') {
        strcpy(no->item.nome, it.nome);
    }
    return 0;
}
int buscaItemPrato(ListaP *l, int cod) {
    if (l == NULL) return 2;
    if (listaVaziaP(l) == 0) return 3;
    NoP *no = (*l);
    while (no != NULL) {
        if (no->item.codigo != cod) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int buscaPrato(ListaP *l, int cod, Pratos *it) {
    if (l == NULL) return 2;
    if (listaVaziaP(l) == 0) return 1;
    NoP *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL) {
        if (no->item.codigo != cod) {
            no = no->prox;
        } else {
            break;
        }
    }
    *it = no->item;
    return 0;
}

int listaVaziaP(ListaP *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

int tamanhoP(ListaP *l) {
    if (l == NULL) return 1;
    if (listaVaziaP(l) == 0) return 0;
    int p = 0;
    NoP *no = (*l);
    while (no != NULL) {
        p++;
        no = no->prox;
    }
    return p;
}

void mostrarPratos(ListaP *l) {
    if (l != NULL) {
        NoP *no = (*l);
        while (no != NULL) {
            printf("\n");
            printf("\n---- Prato (%d) ----", no->item.codigo);
            printf("\nNome: %s", no->item.nome);
            printf("\nIngredientes: %s", no->item.ingredientes);
            printf("\nPreco: %.2f reais", no->item.preco);
            no = no->prox;
        }
    }
}