#include "alumno.h"


Alumno *crearAlumno(size_t matricula)
{
	Alumno *nuevo = calloc(1,sizeof(Alumno));
	nuevo->matricula = matricula;
	inputCadena("Captura nombre: ",nuevo->nombre,MAX);
	inputEntero("Captura semestre: ",&nuevo->semestre);
	inputFloat("Captura promedio: ",&nuevo->promedio);
	return nuevo;
}


void imprimirAlumno(void *a)
{	
	Alumno alumno = *(Alumno*)a;
	printf("%-8u | ",alumno.matricula);
	printf("%-20s | ",alumno.nombre);
	printf("%3d | ",alumno.semestre);
	printf("%.2f | ",alumno.promedio);
}

int compararMatricula(void *a, void *b)
{
	return 0;
}
int compararNombre(void *a, void *b)
{
	return 0;	
}
int compararSemestre(void *a, void *b)
{
	return 0;
}
int compararCompararPromedio(void *a, void *b)
{
	return 0;	
}