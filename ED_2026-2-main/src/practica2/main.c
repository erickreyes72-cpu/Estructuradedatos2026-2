#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <ListaD.h>
#include "Cancion.h"


int main(void)
{
	
    int option,corre_programa;
    int circular = 0;
	int seleccion, posicion;
	
	Canciones canciones = cargarCanciones();
	
	ListaD lista = inicializarListaD(); //Creamos la playlist
	Nodod * actual = NULL;
	
	corre_programa=1;
    while(corre_programa)
    {
        printf("\n\r");
        printf("\n\r");
        printf("\n\r [0] BUCLE");
        printf("\n\r [1] ANTERIOR");
        printf("\n\r [2] SIGUIENTE");
        printf("\n\r [3] AGREGAR CANCION");
        printf("\n\r [4] MOSTRAR LISTA DE REPRODUCCION");
        printf("\n\r [5] QUITAR CANCION");
        printf("\n\r [6] REINICIAR REPRODUCCION");
        printf("\n\r [7] TERMINAR PROGRAMA");

        printf("\n\r Escoge opcion: ");
        scanf("%d",&option);
		clear_buffer();
		switch(option)
        {
        case 0:
				if (circular == 0)
				{
					if(lista.inicio == NULL)
					{
						printf("La playlist esta vacia.\n");
						break;
					}
					lista.fin->sig = lista.inicio;
					lista.inicio->ant = lista.fin;
					circular=1;
				}
				else
				{
					lista.fin->sig = NULL;
					lista.inicio->ant = NULL;
					circular = 0;
				}
                break;
        case 1:
				if(actual == NULL)
				{
					printf("La playlist esta vacia.\n");
					break;
				}
				
				if(actual->ant != NULL)
				{
					actual = actual->ant;
				}
				
				imprimirCancion(actual->dato);
                break;
				
        case 2:
               if(actual == NULL)
			   {
				   printf("La playlist esta vacia.\n");
				   break;
			   }
			   
			   if(actual->sig != NULL)
			   {
				   actual = actual->sig;
			   }
			   
			   imprimirCancion(actual->dato);
                break;
        case 3:
               
				imprimirCanciones(canciones);
				printf("\nQue cancion quieres agregar a la playlist:");
				scanf("%d", &seleccion);
				clear_buffer();
				
				if(seleccion < 0 || seleccion >= canciones.cant)
				{
					printf("Seleccion invalida.\n");
					break;
				}
				
				Cancion *cancionSelect = &canciones.cancion[seleccion];
			
				printf("\nEn que posicion quieres agregar la cancion: ");
				scanf("%d", &posicion);
				clear_buffer();
				
				if (posicion < 0 || posicion > lista.cant)
				{
					printf("Posicion invalida.\n");
					break;
				}
				
				if(posicion == 0)
				{
					insertarInicioD(&lista, cancionSelect);
				}
				else if (posicion == lista.cant)
				{
					insertarFinalD(&lista, cancionSelect);
				}
				else
				{
					Nodod *aux = lista.inicio;

					for(int i = 0; i < posicion - 1; i++)
					{
						aux = aux->sig;
					}
					Nodod *siguiente = aux->sig;
					Nodod *nuevo = crearNodod(cancionSelect);
					
					aux->sig = nuevo;
					nuevo->sig = siguiente;
					nuevo->ant = aux;
					siguiente->ant = nuevo;
					lista.cant++;
				}
				
				if(circular == 1)
				{
					lista.fin->sig = lista.inicio;
					lista.inicio->ant = lista.fin;
				}
				
				if(actual == NULL)
				{
					actual = lista.inicio;
				}
				
				
                break;
        case 4:
                imprimirListaIFD(lista, imprimirCancion);
                break;
        case 5:
				if(lista.inicio == NULL)
				{
					printf("La playlist esta vacia.\n");
					break;
				}
                Nodod *aux = lista.inicio;
				int i = 0;
				
				do
				{
					printf("[%d]", i);
					imprimirCancion(aux->dato);
					aux=aux->sig;
					i++;
				}while(aux != NULL && aux != lista.inicio);
				
				printf("\nQue cancion quieres eliminar de la playlist:");
				scanf("%d", &seleccion);
				clear_buffer();
				
				if(seleccion < 0 || seleccion >= lista.cant)
				{
					printf("Posicion invalida.\n");
					break;
				}
				
				aux=lista.inicio;
				for(int i=0; i < seleccion; i++)
				{
					aux=aux->sig;
				}
				
				if(lista.cant == 1)
				{
					lista.inicio = NULL;
					lista.fin = NULL;
					actual = NULL;
				}
				else if(circular == 1)
				{
					if(aux == lista.inicio)
					{
						lista.inicio = aux->sig;
					}
					else if(aux == lista.fin)
					{
						lista.fin = aux->ant;
					}

					aux->ant->sig = aux->sig;
					aux->sig->ant = aux->ant;

					if(actual == aux)
					{
						actual = aux->sig;
					}

					lista.fin->sig = lista.inicio;
					lista.inicio->ant = lista.fin;
				}
				else
				{
					if(aux == lista.inicio)
					{
						lista.inicio = aux->sig;
						lista.inicio->ant = NULL;
					}
					else if(aux == lista.fin)
					{
						lista.fin = aux->ant;
						lista.fin->sig = NULL;
					}
					else
					{
						aux->ant->sig = aux->sig;
						aux->sig->ant = aux->ant;
					}

					if(actual==aux)
					{
						actual=aux->sig;
					}
				}

				free(aux);
				lista.cant--;
				
				
                break;
        case 6:
               actual = lista.inicio;
                break;
        case 7:
                corre_programa=0;
                break;
        default:
                break;
        }
		printf("\n\nENTER PARA CONTINUAR...");
		clear_buffer();
    }
    printf("\n FIN DE PROGRAMA \n\r");
    return 0;
}