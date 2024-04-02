#ifndef EVA00_CLIENTE_H
#define EVA00_CLIENTE_H
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
typedef struct noC* ListaC;
typedef struct cliente Cliente;
struct cliente {
    char cpf[15];
    char nome[30];
    char email[30];
    char senha[10];
    ListaP *carrinho;
};

ListaC *criarCliente();

int inserirCliente(ListaC *l, Cliente cli);
int removerInicioC(ListaC *l);
int removerCliente(ListaC *l, Cliente cli);

int buscaEmailCliente(ListaC *l, char *em);
int buscaCliente(ListaC *l, char *em, Cliente *cli);
int procuraCliente(ListaC *l, char *aux);

int listaVaziaC(ListaC *l);

void mostrarC(ListaC *l);

void liberarmemoriaC(ListaC *l);

int tamanhoC (ListaC *l);
#endif //EVA00_CLIENTE_H