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

ListaP *criarP(); //feito

int inserirPrato(ListaP *l, Pratos it); //feito
int removerPrato(ListaP *l, Pratos it); //feito

int listaVaziaP(ListaP *l); //feito

int alteraPrato(ListaP *l, Pratos it);
int buscaItemPrato(ListaP *l, int cod); //feito
int buscaPrato(ListaP *l, int cod, Pratos *it); //feito
int tamanhoP(ListaP *l); //feito

void mostrarPratos(ListaP *l); //feito

void liberarmemoriaP(ListaP *l); //feito
#endif //EVA00_PRATOS_H
