#ifndef EVA00_RESTAURANTE_H
#define EVA00_RESTAURANTE_H
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
typedef struct noR* ListaR;
typedef struct restaurante Restaurante;
typedef struct restaurante{
    char nomeRest[30];
    char categoria[30];
    char CNPJ[19];
    char email[30];
    int senha;
    int identificacao;
    ListaP *cardapio;
    FilaPed *pedidos;
}Restaurante;

ListaR *criarRest(); //feito

int inserirRest(ListaR *l, Restaurante rest); //feito

int removerRest(ListaR *l, Restaurante rest); //feito

int buscaEmailRest(ListaR *l, char *em); //feito
int buscaItemRest(ListaR *l, char *it); //feito
int buscaRest(ListaR *l, char *aux, Restaurante *rest); //feito

int listaVaziaR(ListaR *l); //feito

void mostrarR(ListaR *l, char *cat); //feito
void mostrarPratosRest(ListaR *l); //feito

void liberarmemoriaR(ListaR *l); //feito

int tamanhoR (ListaR *l); //feito
#endif //EVA00_RESTAURANTE_H
