#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <Lista.h>
#include <ListaD.h>
#include "alumno.h"

void imprimir(void *dato);
int comparar(void *,void*);

int main(void)
{	
	/*
	Lista lista  = inicializarLista();
	int i =3;
	
	printf("\n %d", strcmpIC("Pablo","Pepe"));
	printf("\n %d", strcmpIC("Pepe","Pablo"));
	while(i--)
	{
		Alumno temp;
		printf("\n Captura matricula: ");
		scanf("%u",&temp->matricula);
		clear_buffer();
		//SE REQUIERE UN ALUMNO TEMPORAR PARA COMPARAR/BUSCAR
		//buscarDato(lista,&temp,compararMatricula);
		Alumno *nuevo = crearAlumno(mat);
		insertarFinal(&lista,nuevo);
		imprimirLista(lista,imprimirAlumno);
	}
	eliminarLista(&lista,free);
	*/
	int arreglo[6] = {4,3,6,1,2,3};
	ListaD lista = inicializarListaD();
	lista.comparar = comparar;
	for(int i=0;i<6;i++)
	{
		insertarOrdenadoD(&lista,&arreglo[i]);
	}
	
	imprimirListaFID(lista,imprimir);
	printf("\n ");
	imprimirListaIFD(lista,imprimir);
	
	
	
	
	printf("\n\n FIN DE PROGRAMA :)\n");
	return 0;
}

void imprimir(void *dato)
{
	int a = *(int*)dato;
	printf("%d ",a);
}

int comparar(void *pa,void *pb)
{
	int a = *(int*)pa;
	int b = *(int*)pb;
	if(a<b)return -1;
	if(a>b)return 1;
	else return 0;
}
