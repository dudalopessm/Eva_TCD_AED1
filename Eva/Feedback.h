#ifndef EVA_FEEDBACK_H
#define EVA_FEEDBACK_H
#include "Clientes.h"
#include "Restaurantes.h"
#include "Pedido.h"
typedef struct noF* ListaF;
typedef struct feedback Feedback;
typedef struct feedback {
    char estrelas[2]; //cliente avalia estabelecimento ou pedido de 0 a 5 estrelas
    char avaliacao[300]; //cliente escreve avaliacao
    ListaC *cliente;
    //ListaR *restaurante;
    Fila  *pedidos;
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
#endif //EVA_FEEDBACK_H