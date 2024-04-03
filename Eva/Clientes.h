#ifndef EVA_CLIENTES_H
#define EVA_CLIENTES_H
#include "Clientes.h"
#include "Prato.h"
typedef struct noC* ListaC;
typedef struct cliente Cliente;
struct cliente {
    char cpf[15];
    char nome[30];
    char email[30];
    char senha[10];
    ListaP *carrinho;
    ListaP *pedidos;
    ListaP *entregues;
};

ListaC *criarCliente();

int inserirCliente(ListaC *l, Cliente cli);
int removerCliente(ListaC *l, Cliente cli);

int buscaEmailCliente(ListaC *l, char *em);
int buscaCliente(ListaC *l, char *em, Cliente *cli);
int procuraCliente(ListaC *l, char *aux);

int listaVaziaC(ListaC *l);

void mostrarC(ListaC *l);
//diminui tamanho do tad, acrescentei ListaP pedidos na struct
#endif //EVA_CLIENTES_H