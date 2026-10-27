#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
#include "arbol.h"
#include "Nodo.h"

int *crearEntero(int);
void imprimir(void*);
int comparar(void *, void *);

int main(void)
{
	int opcion;
	Arbol arbol={0};
	arbol.comparar = comparar;
	
	do
	{
		printf("-- MENU --\n");
		printf("[1] Insertar dato\n");
        printf("[2] Eliminar dato\n");
        printf("[3] Equilibrar arbol\n");
        printf("[4] Mostrar arbol\n");
        printf("[5] Terminar\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1:
			{
				int numero;
				
				printf("Ingresa un numero entero:");
				scanf("%d", &numero);
				
				int *dato = crearEntero(numero);
				insertarArbolO(&arbol, dato);
				
				printf("Dato insertado.\n");
			}
				break;
				
			case 2:
			{
				int numero;
				
				printf("Ingresa numero que quieres eliminar:");
				scanf("%d", &numero);
				
				int *dato = crearEntero(numero);
				eliminarArbolO(&arbol, dato);
				free(dato);
				break;
			}
			case 3:
				equilibrarArbol(&arbol);
				printf("Arbol equilibrado.\n");
				break;
				
			case 4:
				printf("\nArbol binario\n");
				imprimirArbol(arbol, imprimir); 
				printf("\n");
				break;
				
			case 5:
				liberarArbol(&arbol);
				printf("Memmoria liberada. Terminando proframa...\n");
				break;
				
			default:
				printf("Opcion no validan");
		}
	}while(opcion != 5);
	
	return 0;
}

int comparar(void *a, void *b)
{
    int valA = *(int *)a;
    int valB = *(int *)b;

    return valA - valB;
}

void imprimir(void *dato)
{
	printf("%d",*(int*)dato);
}

int *crearEntero(int num)
{
	int *dato = calloc(1,sizeof(int));
	*dato = num;
	return dato;
}