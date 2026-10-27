#ifndef ARBOL_H
#define ARBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <Nodo.h>
#include <Pila.h>


#define PREORDEN 1
#define ORDEN 2
#define POSTORDEN 3
#define INVERSO 4
#define IZQUIERDA 0
#define DERECHA 1

typedef struct
{
	Nodoa *raiz;
	size_t cant;
	fn_comparar comparar;
	Orden orden;
}Arbol;

size_t altura(Arbol);
size_t alturaI(Arbol);
void imprimirOrden(Arbol arbol,fn_imprimir,int opcion);
void imprimirArbol(Arbol arbol,fn_imprimir imprimir);

//Funciones de taller 4
void insertarArbolO(Arbol *arbol, void *dato);
void flipArbol(Arbol *arbol);
void *buscarArbol(Arbol *arbol, void *dato);

//funciones de practica 5
void eliminarArbolO(Arbol *arbol, void *dato);
void liberarArbol(Arbol *arbol);
void equilibrarArbol(Arbol *arbol);
#endif