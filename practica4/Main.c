#include <stdio.h>
#include <stdlib.h>
#include <Pila.h>
#include <iostring.h>
#include "Laberinto.h"



Pila* resolverLab(Laberinto lab, Coordenada origen,Coordenada destino);

int main(void)
{
    Laberinto lab = crear_laberinto();
	//Movimientos mov;
	Coordenada origen = {1,1}; 
	Coordenada destino = {25,24};
	printf("\nDestino: [%d,%d]\n", destino.x, destino.y);
	unsigned int nuevasCoor = 0;	
	inputEnteroSinSigno("\n Nuevas coordenadas? (1:SI 0:NO) : ",&nuevasCoor);
	if(nuevasCoor)
	{
		inputEntero("\n Captura Origen X: ",&origen.x);
		inputEntero(" Captura Origen Y: ",&origen.y);
		inputEntero("\n Captura Destino X: ",&destino.x);
		inputEntero(" Captura Destino Y: ",&destino.y);
	}
	setOrigen(lab,origen);
	setDestino(lab,destino);	
	
	Pila *pila = resolverLab(lab,origen,destino);
	imprimirLab(lab);
	printf("\n\nB |");
	imprimirPila(*pila, imprimirCoordenada);
	printf("<-A");
	
	liberarLaberinto(lab);
	eliminarPila(pila,free);
	free(pila);
    printf("\n\n FIN DE PROGRAMA\n\n");
    return 0;
}


Pila* resolverLab(Laberinto lab, Coordenada origen,Coordenada destino)
{
		
	Pila *pila = crearPila();
	*pila = inicializarPila(-1);	
	Coordenada *punto;
	//PUSH INICIAL DEL ORIGEN
	punto = crearCoordenada(origen.x,origen.y);
	push(pila,punto);	
	//CICLO
	
	while( !pilaVacia(*pila))
	{
		punto = (Coordenada*)peek(*pila); //Averiguar donde estamos (punto representa nuestra posicion actual en el laberinto)
		
		if (lab[punto->x][punto->y] == 'B')
		{
			printf("  LLEGAMOS A B!!\n");
			break;
			
		}
		
		Movimientos mov = movimientosPosibles(lab, *punto);//Vemos que opciones tenemos para movernos
		
		if(mov.right == 1) //Si podemos ir a la derecha
		{
			
			//Creamos la coordenada de la derecha y la metemos a la pila
			Coordenada *nueva = crearCoordenada(punto->x, punto->y + 1);
			
			if(lab[nueva->x][nueva->y] == '*')//Preguntamos si nueva es un camino *
			{
				lab[nueva->x][nueva->y] = '.'; //Marcamos hacia donde nos moveremos con un .
			}
			
			push(pila, nueva); //Guardamos en la pila la nueva posicion y nos movemos a esa
			printf("  Posicion: [%d,%d]\n", nueva->x, nueva->y);
		}
		
		else if(mov.down == 1)//Igual pero para abajo ahora
		{
		
			Coordenada *nueva = crearCoordenada(punto->x + 1, punto->y);
			if(lab[nueva->x][nueva->y] == '*')
			{
				lab[nueva->x][nueva->y] = '.';
			}
			
			push(pila, nueva);
			printf("  Posicion: [%d,%d]\n", nueva->x, nueva->y);
		}
		
		else if(mov.left == 1)//Igual pero para izquierda ahora
		{
			
			Coordenada *nueva = crearCoordenada(punto->x, punto->y -1);
			
			if(lab[nueva->x][nueva->y] == '*')
			{
				lab[nueva->x][nueva->y] = '.';
			}
			
			push(pila, nueva);
			printf("  Posicion: [%d,%d]\n", nueva->x, nueva->y);
		}
		
		else if(mov.up == 1)//Igual pero para arriba ahora
		{

			Coordenada *nueva = crearCoordenada(punto->x -1, punto->y);
			
			if(lab[nueva->x][nueva->y] == '*')
			{
				lab[nueva->x][nueva->y] = '.';
			}
			
			push(pila, nueva);
			printf("  Posicion: [%d,%d]\n", nueva->x, nueva->y);
		}
		else //Si no hay ningun camino posible
		{	
			//Eliminamos la posicion en la que estamos para volver a la anterior
			Coordenada *eliminada = pop(pila);
			if(lab[eliminada->x][eliminada->y] != 'B')
			{
				lab[eliminada->x][eliminada->y] = 'o'; //Camino cerrado
			}
			
		    printf("  RETROCEDI: [%d,%d]\n", eliminada->x, eliminada->y);
		   
			free(eliminada); //liberamos la memoria de la coordenada sacada
		}
		
		printf("\n Presione enter para continuar....");
		clear_buffer();
		imprimirLab(lab);		
		//punto = (Coordenada*)peek(*pila);
		//mov = movimientosPosibles(lab,*punto);		
	
	}
	return pila;
}

 //mingw32-make rebuild
 //mingw32-make run

