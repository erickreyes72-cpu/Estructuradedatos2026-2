#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
#include <Lista.h>
#include <Nodo.h>
#include "Alumno.h"

int main(void)
{	
	Lista lista = inicializarLista();
	lista.comparar = compararMatricula;
	lista.orden = ASCENDENTE;
	
	int selector;
	
	do{
		printf("\n\n===== MENU =====");
        printf("\n[1] Registrar Alumno");
        printf("\n[2] Desplegar Alumnos");
        printf("\n[3[ Reordenar");
        printf("\n[4] Buscar Alumno");
        printf("\n[5] Borrar Alumno");
        printf("\n[6] Salir");

        printf("\n\nSelecciona una opcion: ");
        scanf("%d", &selector);
        clear_buffer();
		
		switch(selector)
		{
			case 1:
			{
				unsigned int matricula;
				printf("\nCaptura Matricula:"); //pedimos la matricula
				scanf("%u",&matricula);
				clear_buffer();
				
				Alumno buscado;
				buscado.matricula = matricula;  //creamos alumno temporal
				
				if(buscarDato(lista, &buscado, compararMatricula)) //busca y compara la matricula de cada alumno con la ingresada
				{
					printf("\nLa matriucla ya existe");
				}
				else
				{
					Alumno *nuevo = crearAlumno(matricula);				//una vez comprobado que no existe se crea el alumno real
					insertarOrdenado(&lista, nuevo, lista.comparar);
					printf("\nAlumno registrado correctamente.");
				}
			}
				break;
			
			
			
			case 2:
			imprimirLista(lista, imprimirAlumno);
				break;
			
			case 3:
			{
					int opcion;
					int orden;
					
					printf("Reordenar por:");
					printf("\n[1] Matricula");
					printf("\n[2] Nombre");
					printf("\n[3] Semestre");
					printf("\n[4] Promedio");

					printf("\nOpcion: ");
					scanf("%d", &opcion);
					clear_buffer();
					
					printf("\nOrden:");
					printf("\n[1] Ascendente");
					printf("\n[2] Descendente");
					
					printf("\nOpcion :");
					scanf("%d", &orden);
					clear_buffer();
					
					switch(opcion)
					{
						 case 1:
						ordenarLista(&lista, compararMatricula, orden);
							break;

						case 2:
						ordenarLista(&lista, compararNombre, orden);
							break;

						case 3:
						ordenarLista(&lista, compararSemestres, orden);
							break;

						case 4:
						ordenarLista(&lista, compararPromedio, orden);
							break;

						default:
						printf("\nOpcion invalida.");
					}
			}

				break;
		
			case 4:
			{
				Nodo *aux;
				Alumno buscado;
				int opcion;
				
				printf("\nBuscar por:");
				printf("\n[1] Matricula");
				printf("\n[2] Nombre");
				printf("\n[3] Semestra");
				printf("\n[4] Promedio");
				
				printf("\nOpcion");
				scanf("%d", &opcion);
				clear_buffer();
				
				switch(opcion)
				{
					case 1:
						printf("\nMatricula: ");
						scanf("%u", &buscado.matricula);
						clear_buffer();
						
						aux = lista.inicio;
						
						while(aux != NULL)
						{
							if(compararMatricula(&buscado, aux->dato)==0)
							{
								printf("\nAlumno encontrado:");
								imprimirAlumno(aux->dato);
								break;
							}
							aux = aux->sig;
						}
						if(aux == NULL)
							printf("\nAlumno no encontrado");
						break;
						
					case 2:
						printf("\nNombre: ");
						fgets(buscado.nombre, MAX, stdin);
						buscado.nombre[strcspn(buscado.nombre, "\n")] = '\0';
						
						aux = lista.inicio;
						
						while(aux!=NULL)
						{
							if(compararNombre(&buscado, aux->dato)==0)
							{
								printf("\nAlumno encontrado:\n");
								imprimirAlumno(aux->dato);
								break;
							}
							aux = aux->sig;
						}
						
						if (aux == NULL)
						{
							printf("Alumno no encontrado.");
						}
						
						break;
						
					case 3:
						printf("\nSemestre:");
						scanf("%d", &buscado.semestres);
						clear_buffer();
						
						aux = lista.inicio;
						
						while(aux != NULL)
						{
							 if(compararSemestres(&buscado, aux->dato) == 0)
							{
								printf("\nAlumno encontrado:\n");
								imprimirAlumno(aux->dato);
								break;
							}

							aux = aux->sig;
						}

						if(aux == NULL)
							printf("\nAlumno no encontrado.");

						break;
					case 4:
						printf("\nPromedio:");
						scanf("%f", &buscado.promedio);
						clear_buffer();
						
						aux = lista.inicio;
						
						while(aux != NULL)
						{
							if(compararPromedio(&buscado, aux->dato) == 0)
							{
								printf("\nAlumno encontrado:\n");
								imprimirAlumno(aux->dato);
								break;
							}
							aux = aux->sig;
						}
						if(aux == NULL)
						printf("\nAlumno no encontrado.");
						break;
						default:
						printf("NO encontrado, lo snetimos.");
				}
				break;
			}
		
			
			case 5:
			{
				Alumno buscado;

				printf("\nMatricula del alumno a borrar: ");
				scanf("%u", &buscado.matricula);
				clear_buffer();

				eliminarDato(&lista, &buscado, compararMatricula);
					break;
			}
				
			case 6:
			printf("\nTerminando programa...");
				break;
			
			default:
			printf("Opcion invalida.");
		}
		
   }while(selector != 6);
   
   eliminarLista(&lista);
   
   return 0;
}

