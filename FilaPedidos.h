#ifndef EVA00_FILAPEDIDOS_H
#define EVA00_FILAPEDIDOS_H
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Feedbacks.h"
#include "FilaPedidos.h"
typedef struct fila Fila;

Fila *criarFilaPed();

void limparmemoriaFila (Fila *f);

int inserirPedido(Fila *f, Cliente cli, Pratos p);

int removerPedido(Fila *f, Cliente *cli, Pratos *p);

int tamanhoFila(Fila *f);

void mostrarPedidos(Fila *f);

int filaVazia(Fila *f);

#endif //EVA00_FILAPEDIDOS_H