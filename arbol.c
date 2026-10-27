#include "arbol.h"
static void guardarEnOrden(Nodoa *nodo, Nodoa **nodos, size_t *indice);
static Nodoa *construirEquilibrado(Nodoa **nodos, size_t inicio, size_t fin);

size_t altura(Arbol arbol)
{
	Arbol arbol_izq,arbol_dch;
	size_t hd,hi;
	if(!arbol.raiz) 
		return 0;
	if(!arbol.raiz->izq && !arbol.raiz->dch)
		return 1;
	arbol_izq.raiz = arbol.raiz->izq;
	arbol_dch.raiz = arbol.raiz->dch;
	hi = altura(arbol_izq);
	hd = altura(arbol_dch);
	if( hi>hd )
		return hi + 1;
	else
		return hd + 1;
}




size_t alturaI(Arbol arbol)
{
	size_t max_altura = 0;
	
	if (!arbol.raiz)
		return max_altura;

	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			//SE RECORREN LOS HIJOS IZQUIERDOS
			// Apilar nodo padre antes del bajar
			push(&pila, actual);
			
			// Actualizar la altura máxima según la profundidad de la pila
			if (pila.cant > max_altura)
				max_altura = pila.cant;
			
			actual = actual->izq;
		}
		else
		{
			//Se consulta el padre
			Nodoa *padre = peek(pila);
			
			// Si existe hijo derecho y aún no lo hemos visitado, recorrer
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
			{
				actual = padre->dch;
			}
			else
			{
				// Remover si ya se recorrieron los hijos
				ultimo_visitado = pop(&pila);
			}
		}
	}

	return max_altura;
}


void preordenI(Arbol arbol,fn_imprimir imprimir)
{
	if (!arbol.raiz)
		return ;
	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			printf(" ");
			imprimir(actual->dato);
			push(&pila, actual);
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = peek(pila);			
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
				ultimo_visitado = pop(&pila);
		}
	}
}


void ordenI(Arbol arbol,fn_imprimir imprimir)
{
	if (!arbol.raiz)
		return ;
	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			push(&pila, actual);
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = pop(&pila);			
			printf(" ");
			imprimir(padre->dato);
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
				ultimo_visitado = padre;
		}
	}
}



void postordenI(Arbol arbol,fn_imprimir imprimir)
{
	if (!arbol.raiz)
		return ;
	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			push(&pila, actual);
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = peek(pila);			
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
			{
				printf(" ");
				imprimir(padre->dato);
				ultimo_visitado = pop(&pila);
			}
		}
	}
}


void preorden(Nodoa *raiz,void (*imprimir)(void*))
{
	if(!raiz)
		return;
	printf(" ");
	imprimir(raiz->dato);
	preorden(raiz->izq,imprimir);
	preorden(raiz->dch,imprimir);
}

void orden(Nodoa *raiz,void (*imprimir)(void*))
{
	if(!raiz)
		return;
	orden(raiz->izq,imprimir);
	printf(" ");
	imprimir(raiz->dato);
	orden(raiz->dch,imprimir);	
}


void inverso(Nodoa *raiz,void (*imprimir)(void*))
{
	if(!raiz)
		return;
	inverso(raiz->dch,imprimir);	
	printf(" ");
	imprimir(raiz->dato);
	inverso(raiz->izq,imprimir);
}

void postorden(Nodoa *raiz,void (*imprimir)(void*))
{
	if(!raiz)
		return;
	postorden(raiz->izq,imprimir);
	postorden(raiz->dch,imprimir);
	printf(" ");
	imprimir(raiz->dato);	
}


void imprimirOrden(Arbol arbol,fn_imprimir imprimir,int opcion)
{
	switch(opcion)
	{
		case PREORDEN: 
			//preorden(arbol.raiz,imprimir);
			preordenI(arbol,imprimir);
			break;
		case ORDEN: 
			//orden(arbol.raiz,imprimir);
			ordenI(arbol,imprimir);
			break;
		case INVERSO: 
			inverso(arbol.raiz,imprimir);
			break;
		case POSTORDEN: 
			//postorden(arbol.raiz,imprimir);			
			postordenI(arbol,imprimir);
			break;
	}
}




void imprimir_arbol(Nodoa* nodo, int nivel,fn_imprimir imprimir)
{
    int i;
    if (nodo != NULL)
        {
        printf(" ");
		imprimir(nodo->dato);
        if(nodo->dch)
        {
            printf("\n");
            for (i = 0; i < nivel+1; i++)
            {
                if(i==nivel)
                    printf(" |____R ");
                else
                    printf(" |      ");
            }
            imprimir_arbol(nodo->dch, nivel + 1,imprimir);
        }
        if(nodo->izq)
        {
            printf("\n");
            for (i = 0; i < nivel+1; i++)
            {
                printf(" |      ");
                //printf(" |      ");
            }
            printf("\n");
            for (i = 0; i < nivel+1; i++)
            {
                if(i==nivel)
                    printf(" |____L ");
                else
                    printf(" |      ");
            }
            imprimir_arbol(nodo->izq, nivel + 1,imprimir);
        }
    }
}

void imprimirArbol(Arbol arbol,fn_imprimir imprimir)
{
	imprimir_arbol(arbol.raiz,0,imprimir);
}

void insertarArbolO(Arbol *arbol, void *dato)
{
	//comprobar que sean direcciones validas
	if(arbol == NULL || dato == NULL || arbol->comparar == NULL)
	{
		return;
	}
	
	//Crear nuevo nodo
	Nodoa *nuevo = crearNodoa(dato);
	if(nuevo == NULL)
	{
		return;
	}
	
	//Asignar el nuevo nodo a la raiz del arbol si esta NULL1
	if(arbol->raiz == NULL)
	{
		arbol->raiz = nuevo;
		arbol->cant++; //aumentamos cantidad de nodos en arbol
		return;
	}
	
	Nodoa *actual = arbol->raiz; //Nodo que va guiarnos cada paso
	Nodoa *padre = NULL; //Guardara el ultmo nodo valido que visitamos
	
	while(actual != NULL)//Mientras actual apunte a un nodo existente
	{
		padre = actual; //Antes guardamos el nodo que estamos comparando
		
		if(arbol->comparar(dato, actual->dato) < 0) //Si el dato nuevo es menor al actual
		{
			actual = actual->izq; //Menor al actual a la izquierda
		}
		else
		{
			actual = actual->dch; //Mayor o igual al actual a la derecha
		}
	}
	
	if(arbol->comparar(dato, padre->dato) < 0)//misma comparacion de arriba
	{
		padre->izq = nuevo; //insertamos a la izquierda si es menor al actual
	}
	else
	{
		padre->dch = nuevo; //a la derecha si es mayor o igual
	}
	
	arbol->cant++; //incrementa cantidad de nodos
}

void flipArbol(Arbol *arbol)
{
	if (arbol == NULL || arbol->raiz == NULL)
		return;
	
	Pila pila = inicializarPila(-1); //Crea pila sin limite fijo
	push(&pila, arbol->raiz);  //pone la raiz del arbol en la pila 
	
	while(!pilaVacia(pila)) 
	{
		Nodoa *actual = (Nodoa *)pop(&pila); 
	
		Nodoa *temporal = actual->izq;
		actual->izq = actual->dch;
		actual->dch = temporal;
		
		if(actual->izq != NULL)
			push(&pila, actual->izq);
		
		if(actual->dch != NULL)
			push(&pila, actual->dch);
	}
}

void *buscarArbol(Arbol *arbol, void *dato)
{
	if(arbol == NULL || arbol->raiz == NULL || dato == NULL || arbol->comparar == NULL)
		return NULL;
	
	Nodoa *actual = arbol->raiz;
	
	while(actual != NULL)
	{
		if(arbol->comparar(dato, actual->dato) == 0) //Si el dato es igual le hacemso return
		{
			return actual->dato;
		}
		
		if(arbol->comparar(dato, actual->dato) < 0)//Si el dato es menor, apuntamos al izq
		{
			actual = actual->izq;
		}
		else
		{
			actual = actual->dch;
		}
	}	
	
	return NULL; //La busqueda termino
	
}

void eliminarArbolO(Arbol *arbol, void *dato)
{
	if(arbol == NULL || arbol->raiz == NULL || dato == NULL || arbol->comparar == NULL)
	{
		return;
	}
	
	Nodoa *actual = arbol->raiz;
	Nodoa *padre = NULL;
	
	 //Mientras actual exista y no hayamos encontrado el dato sigyue el while
	while(actual != NULL && arbol->comparar(dato, actual->dato) != 0)
	{
		padre = actual;
		
		if(arbol->comparar(dato, actual->dato) < 0)
		{
			actual = actual->izq;
		}
		else
		{
			actual = actual->dch;
		}
	}
	
	if(actual == NULL)
	{
		printf("El dato no existe en el arbol.\n");
		return;
	}
	
	if(actual->izq == NULL && actual->dch == NULL) //Si el nodo que vamos a eliminar no tiene hijos
	{
		if(padre == NULL) //El nodo que eliminamos es la raiz, el arbol quedara vacio
		{
			arbol->raiz = NULL; 
		}
		else if (padre->izq == actual) //Desconectamos el nodo de la izquierda 
		{
			padre->izq = NULL;
		}
		else  //desconectamos el nodo de la derecha
		{
			padre->dch = NULL;
		}
		
		free(actual->dato);
		free(actual);	//Liberamos la memoria del entero y el nodo y disminuimos la cantidad de nodos
		arbol->cant--;
		return;
	}
	
	if(actual->izq != NULL && actual->dch == NULL) //si solo tiene un hijo izquierdo
	{
		if(padre == NULL) //si el nodo a eliminar es la raiz
		{
			arbol->raiz = actual->izq; //su hijo izq pasa a ser la nueva raiz
		}
		else if(padre->izq == actual) //si es el hijo izq del padre
		{
			padre->izq = actual->izq;//Hacemos que el nodo izq del padre sea el hijo izq del que vvamos a eliminar(actual)
		}
		else //Si es su hijo dch
		{
			padre->dch = actual->izq; //Hacemos que ahora el hijo dch del padre sea el hijo izq el nodo que bamos a eliminar (actual)
		}
		
		free(actual->dato);
		free(actual);
		arbol->cant--;
		return;
	}
	else if(actual->dch != NULL && actual->izq == NULL) //si solo tiene un hijo derecho
	{
		if (padre == NULL)
		{
			arbol->raiz = actual->dch;
		}
		else if(padre->izq == actual)
		{
			padre->izq = actual->dch;
		}
		else
		{
			padre->dch = actual->dch;
		}
		
		free(actual->dato);
		free(actual);
		arbol->cant--;
		return;
	}
	
	Nodoa *sucesor = actual->dch;
	Nodoa *padreSucesor = actual;
	
	//Para encontrar el valor mas pequeno de los que son mas grandes del que vamos a eliminar por eso hacia la derecha y luego a la izquierda
	while(sucesor->izq != NULL) //Mientras el sucesor tenga hijo izq
	{
		padreSucesor = sucesor; 
		sucesor = sucesor->izq;
	}
	
	
	void *aux = actual->dato; //Guardamos el dato que vamos a eliminar
	actual->dato = sucesor->dato; //El nodo actual recibe el dato del sucesor
	sucesor->dato = aux;//El sucesor recibe el dato que vamos aeliminar
	
	//Si el sucesor tiene hijo derecho hacemos que su padre apunte su izq al hijo derecho y si no apunta a NULL
	if(padreSucesor->izq == sucesor)
	{
		padreSucesor->izq = sucesor->dch;
	}
	else
	{
		padreSucesor->dch = sucesor->dch;
	}
	
	free(sucesor->dato);
	free(sucesor);
	arbol->cant--;
	return;
}

static void liberarNodos(Nodoa *nodo)
{
    if(nodo == NULL)
		return;

    liberarNodos(nodo->izq);
    liberarNodos(nodo->dch);

    free(nodo->dato);
    free(nodo);
}

void liberarArbol(Arbol *arbol)
{
    if(arbol == NULL)
        return;

    liberarNodos(arbol->raiz);

    arbol->raiz = NULL;
    arbol->cant = 0;
}

static void guardarEnOrden(Nodoa * nodo, Nodoa **nodos, size_t *indice)
{
	if (nodo == NULL)//Detiene la llamada cuando ya no hay nodo
	{
		return;
	}
	
	guardarEnOrden(nodo->izq, nodos, indice);//Antes de guardar el nodo actual, recorrer todos los nodos de su lado izq
	nodos[*indice] = nodo;//guarda direccion del nodo actual en el arreglo
	(*indice)++;//Incrementamos el valor al que apunta indice
	
	guardarEnOrden(nodo->dch, nodos, indice);//Recorre la rama derecha
	
}

static Nodoa *construirEquilibrado(Nodoa **nodos, size_t inicio, size_t fin)
{
	if(inicio>fin)
		return NULL;
	
	size_t medio = inicio + (fin-inicio)/2;//Calcular la raiz del arbol
	Nodoa *raiz = nodos[medio];
	
	if(medio > inicio)
		raiz->izq = construirEquilibrado(nodos, inicio, medio-1);//Si hay elementos antes del medio construimos subarbol izq
	else
		raiz->izq = NULL;//Sino asignamos NULL
	
	if(medio<fin)
		raiz->dch = construirEquilibrado(nodos, medio + 1, fin);
	else
		raiz->dch = NULL;
	
	return raiz;
	
}

void equilibrarArbol(Arbol *arbol)
{
	if(arbol == NULL || arbol->raiz == NULL || arbol->cant == 0)//Validar arbol
		return;
	
	Nodoa **nodos = malloc(arbol->cant *sizeof(Nodoa*)); //Reservar espacio para arbol
	
	if(nodos == NULL)
		return;
	
	size_t indice = 0;
	guardarEnOrden(arbol->raiz, nodos, &indice);//Guardamos las direcciones en orden de los nodos
	
	if(indice>0)
		arbol->raiz = construirEquilibrado(nodos,0,indice-1); //Reconstruirlo a partir del arreglo
	
	free(nodos);
}

