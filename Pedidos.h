#ifndef EVA00_PEDIDOS_H
#define EVA00_PEDIDOS_H
#include "Pedidos.h"
#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"

typedef struct filaPed FilaPed;

FilaPed *criarFila();

void limpaFila(FilaPed *f);

#endif //EVA00_PEDIDOS_H