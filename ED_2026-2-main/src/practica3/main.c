#include <stdio.h>
#include <iostring.h>
#include "practica3.h"

int main(void)
{
    int option;

    do
    {
        printf("\n[1] PALINDROMO");
        printf("\n[2] VERIFICAR PARENTESIS");
        printf("\n[3] TERMINAR");

        printf("\nSelecciona opcion:");
        scanf("%d", &option);
        clear_buffer();

        switch(option)
        {
            case 1:
                palindromo();
                break;

            case 2:
                verificarParentesis();
                break;

            case 3:
                printf("Terminando programa...");
                break;

            default:
                printf("\nOpcion invalida.");
        }

    } while(option != 3);

    return 0;
}