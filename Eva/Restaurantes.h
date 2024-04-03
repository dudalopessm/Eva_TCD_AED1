#ifndef EVA_RESTAURANTES_H
#define EVA_RESTAURANTES_H
#include "Pedido.h"
#include "Feedback.h"
#include "Prato.h"
#include "Clientes.h"
typedef struct noR* ListaR;
typedef struct restaurante Restaurante;
typedef struct restaurante{
    char nomeRest[30];
    char categoria[30];
    char CNPJ[19];
    char email[30];
    char senha[10];
    int identificacao;
    ListaP *cardapio;
    Fila *pedidos;
    //ListaF *feedback;
}Restaurante;

ListaR *criarRest();

int inserirRest(ListaR *l, Restaurante rest);
int removerRest(ListaR *l, Restaurante rest);

int buscaEmailRest(ListaR *l, char *em);
int buscaItemRest(ListaR *l, char *it);
int buscaRest(ListaR *l, char *aux, Restaurante *rest);
int achaRest(ListaR *l, int id, Restaurante *rest);
int achaRestId(ListaR *l, int id);
int acharPrato(ListaR *l, int cod, Restaurante *rest);

int listaVaziaR(ListaR *l);

void mostrarR(ListaR *l, char *cat);
void mostrarPratosRest(ListaR *l);
//consertado, uma funcao incluida e funcoes removidas
#endif //EVA_RESTAURANTES_H