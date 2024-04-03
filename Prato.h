#ifndef EVA_PRATO_H
#define EVA_PRATO_H
#include "Prato.h"
typedef struct noP* ListaP;
typedef struct pratos Pratos;
struct pratos {
    int codigo;
    char nome[30];
    char ingredientes[300];
    float preco;
    int quantidade;
    int restauranteorigem;
};

ListaP *criarP();

int inserirPrato(ListaP *l, Pratos it);
int removerPrato(ListaP *l, Pratos it);

int listaVaziaP(ListaP *l);

int alteraPrato(ListaP *l, Pratos it);

int buscaItemPrato(ListaP *l, int cod);
int buscaPrato(ListaP *l, int cod, Pratos *it);

float carrinho(ListaP *l);

void mostrarPratos(ListaP *l);
void mostrarPCliente(ListaP *l);
void retornarPrato(ListaP *l, Pratos *it);
//adicionado dois campos na struct, adicionadas funcoes e removidas outras funcoes
#endif //EVA_PRATO_H