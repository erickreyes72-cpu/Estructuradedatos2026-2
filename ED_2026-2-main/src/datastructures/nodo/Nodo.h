#ifndef NODO_H
#define NODO_H

#include <stdlib.h>

typedef int (*fn_comparar)(void*,void*);
typedef void (*fn_imprimir)(void*);

typedef enum
{
	DESCENDENTE = -1,
	NINGUNO = 0,
	ASCENDENTE = 1	
}Orden;

typedef struct nodo
{
	void *dato;
	struct nodo *sig;
}Nodo;

Nodo* crearNodo(void *dato);

#endif