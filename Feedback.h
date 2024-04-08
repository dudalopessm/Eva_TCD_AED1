#ifndef EVA_FEEDBACK_H
#define EVA_FEEDBACK_H
#include "Clientes.h"
#include "Restaurantes.h"
#include "Pedido.h"
typedef struct noF* ListaF;
typedef struct feedback Feedback;
typedef struct feedback {
    Cliente user;
    Restaurante alvo;
    char estrelas[2]; //cliente avalia estabelecimento ou pedido de 0 a 5 estrelas
    char avaliacao[300]; //cliente escreve avaliacao
    ListaR *restavaliados; //restaurantes avaliados pelo usuario
    ListaP *pedentregues; //vou avaliar o pedido, a avaliacao vai para o restaurante e fica disponivel para visualizacao para o cliente e o proprietario
}Feedback;

ListaF *criarF();

int tamanhoF(ListaF *l);

int inserirFeed(ListaF *l, Feedback it);
int removerFeed(ListaF *l, Feedback it);

int achaFeed(ListaF *l, int id, Feedback *it);

int listaVaziaF(ListaF *l);

void mostrarFeedRest(ListaF *l);
void mostrarFeedCli(ListaF *l);
void mostrarFeedTodos(ListaF *l);
#endif //EVA_FEEDBACK_H