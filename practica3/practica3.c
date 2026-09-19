#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <Pila.h>
#include <ctype.h>
#include "practica3.h"


void palindromo(void)
{
    char cadena[50];

    printf("\nPalabra o frase:");
    fgets(cadena, sizeof(cadena), stdin); //capturamos palabra/frase
    cadena[strcspn(cadena, "\n")] = '\0';
	for (int j =0; cadena[j]; j++)
	{
		cadena[j] = tolower(cadena[j]);
	}
	

    Pila pila = inicializarPila(-1); //creamos einicializamos pila
    int palindromo = 1;

    for(int i = 0; i < strlen(cadena); i++) //recorremos cadena y metemnos a la pila los elementos que no sean espacio
    {
        if(cadena[i] != ' ')
        {
            push(&pila, &cadena[i]);
        }
    }

    for(int i = 0;i <strlen(cadena); i++)//recorremos para comparar los elementos de la cdena con los caracteres sacados de la pila
    {
        if(cadena[i] != ' ')
        {
            char *caracter = pop(&pila);

            if(cadena[i] != *caracter)
            {
                palindromo = 0; //si son dif no es palindromo
            }
        }
    }

    if(palindromo)
    {
        printf("\nEs palindromo.");
    } else{
        printf("\nNo es palindromo.");
    }
}

void verificarParentesis(void)
{
    char cadena[50];
    int valido = 1;

    printf("\nEscribe cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    Pila pila = inicializarPila(-1);

    for(int i = 0; i < strlen(cadena); i++) //recorremos la cadena
    {
		//buscamos solo signos de apertura y los metemos a la pila
        if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[')
        {
            push(&pila, &cadena[i]);
        }else if(cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']') //si encontramos un cierre
        {
            if(pilaVacia(pila)) //si no hay apertura en la pila, no es valida la cadena
            {
                valido = 0;
            }
            else
            {
                char *apertura = pop(&pila);
				//comparamos el simbolo de apertura con el de cierre
                if(*apertura == '(' && cadena[i] != ')')
                {
                    valido = 0;
                }

                if(*apertura == '[' && cadena[i] != ']')
                {
                    valido = 0;
                }

                if(*apertura == '{' && cadena[i] != '}')
                {
                    valido = 0;
                }
            }
        }
    }

    if(!pilaVacia(pila)) //si quedaron simbolos de apertura es que no habia de cerradura
    {
        valido = 0;
    }
	
    if(valido)
    {
        printf("\nLa cadena es valida.");
    }
    else{
        printf("\nLa cadena no es valida.");
    }
}

//mingw32-make rebuild
//..\..\bin\practica3.exe