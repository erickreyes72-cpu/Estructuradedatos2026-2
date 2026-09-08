#ifndef ALUMNO_H
#define ALUMNO_H
#define MAX 64

typedef struct
{
	unsigned int matricula;
	char nombre[MAX];
	int semestres;
	float promedio;
}Alumno;

//funciones
Alumno *crearAlumno(unsigned int matricula); //registrar
void imprimirAlumno(void*a); //mostrar

int compararMatricula(void *a, void *b); 
int compararNombre(void *a, void *b);
int compararSemestres(void *a, void *b);
int compararPromedio(void *a, void *b);

void liberarAlumno(void *a); //libera memoria

#endif