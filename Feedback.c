#include "Feedback.h"
#include "Clientes.h"
#include "Prato.h"
#include "Restaurantes.h"
#include <stdio.h>
#include <stdlib.h>
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
    if (no->item.pedentregues == NULL) no->item.pedentregues = criarP(); //verificar se ta criando a lista se tiver dando erro
    if (no->item.restavaliados == NULL) no->item.restavaliados = criarRest();
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
    while (no != NULL && no->item.pedentregues != it.pedentregues) {
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

int achaFeed(ListaF *l, int id, Feedback *it) {
    if (l == NULL) return 1;
    if(listaVaziaF(l) == 0) return 2;
    NoF *no = (*l);
    while (no != NULL) {
        if (no->item.alvo.identificacao != id) {
            no = no->prox;
        } else {
            break;
        }
    }
    *it = no->item;
    return 0;
}

void mostrarFeedRest(ListaF *l) {
    if (l != NULL) {
    NoF *noLista = (*l);
    printf("\n");
    while (noLista != NULL) {
        noLista->item.avaliacao[strcspn(noLista->item.avaliacao,"\n")] = '\0';
        noLista->item.estrelas[strcspn(noLista->item.estrelas,"\n")] = '\0';
        noLista->item.user.nome[strcspn(noLista->item.user.nome,"\n")] = '\0';
        printf("\nUsuario: %s", noLista->item.user.nome);
        printf("\nEstrelas: %s", noLista->item.estrelas);
        printf("\nAvaliacao: %s", noLista->item.avaliacao);
        printf("\n");
        noLista = noLista->prox;
    }
    printf("\n");
    }
}

void mostrarFeedCli(ListaF *l) {
    if (l != NULL) {
    NoF *noLista = (*l);
    printf("\n");
    while (noLista != NULL) {
        noLista->item.avaliacao[strcspn(noLista->item.avaliacao,"\n")] = '\0';
        noLista->item.estrelas[strcspn(noLista->item.estrelas,"\n")] = '\0';
        noLista->item.alvo.nomeRest[strcspn(noLista->item.alvo.nomeRest,"\n")] = '\0';
        printf("\nCodigo do pedido: %d", noLista->item.pedentregues);
        printf("\nRestaurante: %s", noLista->item.alvo.nomeRest);
        printf("\nEstrelas: %s", noLista->item.estrelas);
        printf("\nAvaliacao: %s", noLista->item.avaliacao);
        printf("\n");
        noLista = noLista->prox;
    }
    printf("\n");
    }
}

void mostrarFeedTodos(ListaF *l) {
    if (l != NULL) {
    NoF *noLista = (*l);
    printf("\n");
    while (noLista != NULL) {
        noLista->item.avaliacao[strcspn(noLista->item.avaliacao,"\n")] = '\0';
        noLista->item.estrelas[strcspn(noLista->item.estrelas,"\n")] = '\0';
        noLista->item.alvo.nomeRest[strcspn(noLista->item.alvo.nomeRest,"\n")] = '\0';
        noLista->item.user.nome[strcspn(noLista->item.user.nome,"\n")] = '\0';
        printf("\nUsuario: %s", noLista->item.user.nome);
        printf("\nRestaurante: %s", noLista->item.alvo.nomeRest);
        printf("\nEstrelas: %s", noLista->item.estrelas);
        printf("\nAvaliacao: %s", noLista->item.avaliacao);
        printf("\n");
        noLista = noLista->prox;
    }
    printf("\n");
    }
}