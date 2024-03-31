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
    char feedback[100]; //cliente registra em um restaurante
    char senha[10];
    int identificacao;
    ListaP *cardapio;
    FilaPed *pedidos;
}Restaurante;

ListaR *criarRest();

int inserirRest(ListaR *l, Restaurante rest);

int removerRest(ListaR *l, Restaurante rest);

int buscaEmailRest(ListaR *l, char *em);
int buscaItemRest(ListaR *l, char *it);
int buscaRest(ListaR *l, char *aux, Restaurante *rest);
int achaRest(ListaR *l, int id, Restaurante *rest);
int achaRestId(ListaR *l, int id);

int listaVaziaR(ListaR *l);

void mostrarR(ListaR *l, char *cat);
void mostrarPratosRest(ListaR *l);

void liberarmemoriaR(ListaR *l);

int tamanhoR (ListaR *l);
#endif //EVA00_RESTAURANTE_H