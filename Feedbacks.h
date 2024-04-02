#ifndef EVA00_FEEDBACKS_H
#define EVA00_FEEDBACKS_H
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include "Feedbacks.h"
typedef struct noF* ListaF;
typedef struct feedback Feedback;
typedef struct feedback {
    char estrelas[6];
    char avaliacao[300];
    ListaC *cliente;
    ListaR *restaurante;
    FilaPed *pedidos;
}Feedback;

ListaF *criarF();

int inserirFeed(ListaF *l, Feedback it);
int removerFeed(ListaF *l, Feedback it);

int buscaFeedRest(ListaF *l, Feedback it);
int buscaFeedPed(ListaF *l, Feedback it);

int listaVaziaF(ListaF *l);

void mostrarFeedRest(ListaF *l, Feedback it);
void mostrarFeedPed(ListaF *l, Feedback it); //PENDENTE

int tamanhoF(ListaF *l);

void liberarmemoriaF(ListaF *l);
#endif //EVA00_FEEDBACKS_H