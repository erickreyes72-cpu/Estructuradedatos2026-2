#include "Lista.h"

void imprimirLista(Lista lista,fn_imprimir imprimir)
{
	Nodo *aux;
	if(!lista.inicio)
	{
		printf("\n Lista vacia");
		return;
	}	
	printf("\n [CANT %zu]Lista:\n ",lista.cant);
	aux = lista.inicio;
	while( aux )
	{
		imprimir(aux->dato);
		aux = aux->sig;
	}
}

void eliminarLista(Lista *lista)
{
	if( !lista->inicio) return;
	Nodo *aux;
	while( lista->inicio)
	{
		aux = lista->inicio;
		lista->inicio = lista->inicio->sig;
		free(aux);
	}
	lista->fin = lista->inicio;
	lista->cant = 0;
}

void insertarFinal(Lista *lista,void *dato)
{
	if(!lista->inicio)
	{
		lista->inicio = lista->fin = crearNodo(dato);
		lista->cant++;
		return;
	}
	lista->fin->sig = crearNodo(dato);
	lista->fin = lista->fin->sig;
	lista->cant++;
}

void insertarOrdenado(Lista *lista, void *dato, fn_comparar comparar)
{
	//si la lista esta vacia
	if(!lista->inicio) 
	{
		lista->inicio = lista->fin = crearNodo(dato); //Hace que inicio y fin apunten al nodo creado
		lista->cant++; 
		return;
	}
	
	//si el nuevo dato es menor que el primero
	if(comparar(dato, lista->inicio->dato)<0)  //accedemos al primer nodo de la lista y luego accedemos al dato de ese nodo
	{										  //y comparamos si es menor que 0 para si dio -1 entonces seria menor el nuevo dato
											  //si es menor debe ir antes del primer nodo
		Nodo *nuevo = crearNodo(dato);		 //creamos nuevo nodo
		nuevo->sig = lista->inicio;			//Conectamos nuevo con el antiguo inicio y luego 
		lista->inicio = nuevo;				//hacemos que inicio apunte a nuevo
		lista->cant++;						//sumamos el nodo que agregamos				
		return;
	}
	
	Nodo *ant = NULL;	//Va recorriendo una posicion atras de act por que necesitamos la posicion del nodo anterior y el nodo de despues donde va ir el nodo nuevo
	Nodo *act = lista->inicio; //act apunt al inicio de la lista para que la vaya recorriendo y buscando la posicion exacta para insertar nuevo
	
	
	while(act &&((lista->orden == ASCENDENTE && comparar(dato, act->dato) > 0) || (lista->orden == DESCENDENTE && comparar(dato, act->dato) < 0)))
{
    ant = act;
    act = act->sig;
}

	Nodo *nuevo = crearNodo(dato); //
	nuevo->sig = act;			   //sabiendo donde va, crea el nuevo nodo
	ant ->sig= nuevo;              //y lo inserta entre ant y act				//				
	lista->cant++;			      //
	
	if(act == NULL)
	{
		lista->fin = nuevo; //El ultimo nodo es el nuevo el mayor
	}
}

void eliminarDato(Lista *lista,void *dato,fn_comparar comparar)
{	
	if(!lista->inicio)
		return;
	
	for(Nodo *ant=NULL,*elim=lista->inicio ; elim ; ant = elim , elim = elim->sig)
	{
		if( comparar( dato , elim->dato ) == 0)
		{
			if( lista->inicio == elim)
				lista->inicio = elim->sig;
			else
				ant->sig = elim->sig;
			if( lista->fin == elim)
				lista->fin = ant;
			free(elim);
			lista->cant--;
			return;
		}
	}	
}

int buscarDato(Lista lista,void *dato,fn_comparar comparar)
{
	if(!lista.inicio)
		return 0;
	while(lista.inicio)
	{
		if(comparar( dato, lista.inicio->dato ) == 0)
			return 1;
		lista.inicio = lista.inicio->sig;
	}
	
	return 0;
}

Lista inicializarLista(void)
{
	Lista lista;
	
	lista.cant =0;
	lista.inicio = NULL;
	lista.fin = NULL;		//crea lista nueva
	lista.orden = ASCENDENTE;	//=1
	lista.comparar = NULL;
	return lista;			//Regresa la lista completa, inicializada
	
	
}

void ordenarLista(Lista *lista, fn_comparar comparar, Orden orden)
{
	lista->comparar = comparar;
	lista->orden = orden;

	if(!lista->inicio || !lista->inicio->sig) //comprueba si la lista esta vacia o tiene un solo nodo para no ordenarlo
	return;
	
	int cambio; //variable para saber cuando terminar de ordenar
	
	do{
		cambio=0;
	
		Nodo *ant = NULL;
		Nodo *act = lista->inicio;//Recorren la lista busscando nodos que esten fuera de orden y acommodarlos
		Nodo *sig = act->sig;
		
		while(sig) //mientras siga existendo un nodo siguiente seguiremos comparando
		{
			if((orden == ASCENDENTE && comparar(act->dato, sig->dato) > 0) || (orden == DESCENDENTE && comparar(act->dato, sig->dato) < 0))
			{
				// aquí después vamos a intercambiar los nodos
				act->sig = sig->sig;
				sig->sig = act;

				if(ant == NULL)
				{
					lista->inicio = sig;  
				}
				else
				{
					ant->sig = sig;
				}

				if(act->sig == NULL)
				{
					lista->fin = act;
				}
				
				cambio =1; //para cuando sea 0 es por que ya se hicieron todos los cambios y el dowhile acaba
							//pero mientras va seguir cambiando pares en cada iteracion
				act = sig;
				sig = act->sig;
			}
			else
			{
				ant = act;
				act = sig;
				sig = sig->sig;
			}
		}
	}while(cambio);
}
		
		
	