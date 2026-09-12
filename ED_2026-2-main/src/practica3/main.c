#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <Pila.h>
#include <Cola.h>

void imprimir(void *);

int main(void)
{
	Pila pila = inicializarPila(-1);	
	Cola cola = inicializarCola();
    char cadena[30];
	inputCadena("\n Captura cadena: ",cadena,30);
	
	for(int i=0; cadena[i]!='\0' ; i++)
	{
		push(&pila, &cadena[i]);
		enqueue(&cola, &cadena[i]);
	}
	imprimirPila(pila,imprimir);
	eliminarPila(&pila,NULL);
	imprimirCola(cola,imprimir);
	eliminarCola(&cola,NULL);
	
	
    printf("\n FIN DE PROGRAMA \n\r");
    return 0;
}


void imprimir(void *dato)
{
	printf("%c",*(char*)dato);
}