#ifndef EVA00_PRATOS_H
#define EVA00_PRATOS_H
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
typedef struct noP* ListaP;
typedef struct pratos Pratos;
struct pratos {
    int codigo;
    char nome[30];
    char ingredientes[300];
    float preco;
};

ListaP *criarP();

int inserirPrato(ListaP *l, Pratos it);
int removerPrato(ListaP *l, Pratos it);

int listaVaziaP(ListaP *l);

int alteraPrato(ListaP *l, Pratos it);
int buscaItemPrato(ListaP *l, int cod);
int buscaPrato(ListaP *l, int cod, Pratos *it);
int tamanhoP(ListaP *l);

void mostrarPratos(ListaP *l);

void liberarmemoriaP(ListaP *l);
#endif //EVA00_PRATOS_H