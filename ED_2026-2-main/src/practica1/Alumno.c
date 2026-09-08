#include "Alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
								
Alumno *crearAlumno(unsigned int matricula)
{
	Alumno *nuevo = calloc(1, sizeof(Alumno)); //Creamos apuntador a un alumno y liberamos espacio en memoria
	
	nuevo->matricula = matricula; //guarda la matricula que recibe la funcion
	
	inputCadena("Captura nombre:", nuevo->nombre, MAX);
	inputEntero("Captura semestre:", &nuevo->semestres); //Capturas de datos 
	inputFloat("Captura promedio:", &nuevo->promedio);
	
	return nuevo;
}

void imprimirAlumno(void*a) //a contiene la direccion de Alumno
{
	Alumno *alumno = (Alumno*)a; //conversion de tipo a Alumno
	printf("%u |", alumno->matricula); 
	printf("%-20s |", alumno->nombre); //20 caracteres
	printf("%3d |", alumno->semestres);//123
	printf("%.2f |\n", alumno->promedio);//90.12
}
int compararMatricula(void *a, void *b)
{
	Alumno *alumnoA = (Alumno*)a;	//Convertimos "a" en un puntero a Alumno y lo guardamos en alumnoA
	Alumno *alumnoB = (Alumno*)b;	//lo mismo para alumnoB
	
	if(alumnoA->matricula > alumnoB->matricula) //A mayor =1
		return 1;
	
	if(alumnoA->matricula < alumnoB->matricula) //A menor =-1
		return -1;	
	
	return 0;									//IGUALES = 0
}

int compararNombre(void *a, void *b)
{
	int res;
	Alumno *alumnoA = (Alumno*)a;
	Alumno *alumnoB = (Alumno*)b;
	
	res = strcmpIC(alumnoA->nombre, alumnoB->nombre); //comparamos nombres sin distincion de mayus y minus
	
	return res;
}

int compararSemestres(void *a, void *b)
{
	Alumno *alumnoA = (Alumno*)a;
	Alumno *alumnoB = (Alumno*)b;
	
	if(alumnoA->semestres > alumnoB->semestres)
		return 1;
	
	if(alumnoA->semestres < alumnoB->semestres)
		return -1;
	
	return 0;
	
}

int compararPromedio(void *a, void *b)
{
	Alumno *alumnoA = (Alumno*)a;
	Alumno *alumnoB = (Alumno*)b;
	
	if(alumnoA->promedio > alumnoB->promedio)
		return 1;
	
	if(alumnoA->promedio < alumnoB->promedio)
		return -1;
	
	return 0;	
}

void liberarAlumno(void *a) //libera memoria
{
	free(a);
}
