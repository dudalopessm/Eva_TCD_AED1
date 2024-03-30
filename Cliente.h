#ifndef EVA00_CLIENTE_H
#define EVA00_CLIENTE_H
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
typedef struct noC* ListaC;
typedef struct cliente Cliente;
struct cliente {
    char cpf[12];
    char nome[30];
    char email[30];
    int senha;
    ListaP *carrinho;
};

ListaC *criarCliente(); //feito

int inserirCliente(ListaC *l, Cliente cli); //feito

int removerInicioC(ListaC *l); //feito
int removerCliente(ListaC *l, Cliente cli); //feito
int removerPosicaoC (ListaC *l, int pos); //feito

int buscaEmailCliente(ListaC *l, char *em); //feito
int buscaCliente(ListaC *l, char *em, Cliente *cli); //feito
int procuraCliente(ListaC *l, char *aux); //feito

int listaVaziaC(ListaC *l); //feito

void mostrarC(ListaC *l); //feito

void liberarmemoriaC(ListaC *l); //feito


int tamanhoC (ListaC *l); //feito
#endif //EVA00_CLIENTE_H
