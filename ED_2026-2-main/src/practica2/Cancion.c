#include "Cancion.h"


Canciones cargarCanciones(void)
{
	static Cancion biblioteca[] = 
	{
		(Cancion){"Despacito","Luis Fonsi",2017},
		(Cancion){"Gangnam Style","PSY",2012},
		(Cancion){"Fein","Travis Scott",2023},	
		(Cancion){"Amor Tumbado", "Natanael Cano", 2021},
		(Cancion){"Billie Jean", "Michael Jackson", 1982},
		(Cancion){"Beat It", "Michael Jackson", 1982},
		(Cancion){"Thriller", "Michael Jackson", 1982},
		(Cancion){"Smooth Criminal", "Michael Jackson", 1987},
		(Cancion){"Can't Help...", "Elvis Presley", 1961},
		(Cancion){"Jailhouse Rock", "Elvis Presley", 1957},
		(Cancion){"Suspicious Minds", "Elvis Presley", 1969},
		(Cancion){"Love Me Tender", "Elvis Presley", 1956},
		(Cancion){"El Triste", "Jose Jose", 1970},
		(Cancion){"La Nave del Olvido", "Jose Jose", 1970},
		(Cancion){"Lo Dudo", "Jose Jose", 1983},
		(Cancion){"El Amor Acaba", "Jose Jose", 1983},
		(Cancion){"Amar y Querer", "Jose Jose", 1977},
		(Cancion){"Gavilan o Paloma", "Jose Jose", 1977},
		(Cancion){"Si Me Dejas Ahora", "Jose Jose", 1979},
		(Cancion){"Historia de un Amor", "Carlos Eleta", 1956},
		(Cancion){"Besame Mucho", "Consuelo Velázquez", 1940},
		(Cancion){"Sabor a Mi", "Alvaro Carrillo", 1959},
		(Cancion){"Stand by Me", "Ben E. King", 1961},
		(Cancion){"My Way", "Frank Sinatra", 1969},	
	};	
	static Canciones canciones;
	canciones.cancion = biblioteca;
	canciones.cant = sizeof(biblioteca)/sizeof(Cancion);
	return canciones;
}

void imprimirCanciones(Canciones canciones)
{
	printf("\n Canciones TOTAL:%d",canciones.cant);
	for(int i = 0 ; i< canciones.cant; i++)
	{
		printf("\n[%d]",i);
		imprimirCancion(&canciones.cancion[i]);
	}
}

void imprimirCancion(void *dato)
{
	Cancion *cancion = dato;
	printf(" %-20s ",cancion->nombre);
	printf("| %-20s ",cancion->autor);
	printf("| %hu ",cancion->release_date);
}
void imprimirNombre(void *dato)
{
	Cancion *cancion = dato;
	printf(" %-20s ",cancion->nombre);	
}