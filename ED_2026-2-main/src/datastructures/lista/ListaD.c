#include "ListaD.h"

ListaD inicializarListaD(void)
{
	return (ListaD){.inicio=NULL,.fin=NULL,.cant=0,.orden=NINGUNO,.comparar=NULL};
}
void insertarOrdenadoD(ListaD *lista,void *dato)
{
	if(!lista->inicio || lista->comparar(dato,lista->inicio->dato) < 0)
		insertarInicioD(lista,dato);
	else if( lista->comparar(dato,lista->fin->dato) > 0)
		insertarFinalD(lista,dato);
	else
	{
		Nodod *nuevo = crearNodod(dato);
		Nodod *q = lista->inicio;
		Nodod *p = q->sig;
		while( lista->comparar(dato,p->dato) > 0) 
		{
			q = p;
			p = p->sig;
		}
		q->sig = nuevo;
		nuevo->ant = q;
		nuevo->sig = p;
		p->ant = nuevo;
		lista->cant++;
	}	
}

void imprimirListaIFD(ListaD lista,fn_imprimir imprimir)
{
	if(!lista.inicio) return;
	Nodod *aux = lista.inicio;
	do
	{
		printf("\n");
		imprimir(aux->dato);
		aux = aux->sig;
	}while( aux && aux!= lista.inicio);
}
void imprimirListaFID(ListaD lista,fn_imprimir imprimir)
{
	if(!lista.inicio) return;
	Nodod *aux = lista.fin;
	do
	{
		printf("\n");
		imprimir(aux->dato);
		aux = aux->ant;
	}while( aux && aux!= lista.fin);
}





void eliminarListaD(ListaD *lista,fn_free liberar)
{
	
}

void insertarInicioD(ListaD *lista,void *dato)
{
	Nodod *nuevo = crearNodod(dato);
	if(!lista->inicio)
		lista->inicio = lista->fin = nuevo;
	else
	{
		nuevo->sig = lista->inicio;
		lista->inicio->ant = nuevo;
		lista->inicio = nuevo;
	}
	lista->cant++;
}

void insertarFinalD(ListaD *lista,void *dato)
{
	Nodod *nuevo = crearNodod(dato);
	if(!lista->inicio)
		lista->inicio = lista->fin = nuevo;
	else
	{
		nuevo->ant = lista->fin;
		lista->fin->sig = nuevo;
		lista->fin = nuevo;
	}
	lista->cant++;
	
}
void eliminarDatoD(ListaD *lista,void *dato,fn_comparar comparar)
{
	
}
int buscarDatoD(ListaD lista,void *dato,fn_comparar comparar)
{
	return 0;
}
void ordenarListaD(ListaD *lista,fn_comparar comparar,Orden orden)
{
	
}

