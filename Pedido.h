#ifndef EVA_PEDIDO_H
#define EVA_PEDIDO_H
#include "Clientes.h"
#include "Pedido.h"
#include "Prato.h"
typedef struct fila Fila;

Fila *criarFilaPed();

void limparmemoriaFila (Fila *f);

int inserirPedido(Fila *f, Cliente cli, Pratos p);

int removerPedido(Fila *f, Cliente *cli, Pratos *p);

int tamanhoFila(Fila *f);

void mostrarPedidos(Fila *f);

int filaVazia(Fila *f);
#endif //EVA_PEDIDO_H