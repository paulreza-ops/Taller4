#include "Cancion.h"


Canciones cargarCanciones(void)
{
	static Cancion biblioteca[] = 
	{
		(Cancion){"Despacito","Luis Fonsi",2017},
		(Cancion){"Gangnam Style","PSY",2012},
		(Cancion){"Fein","Travis Scott",2023}	
	};	
	static Canciones canciones;
	canciones.cancion = biblioteca;
	canciones.cant = sizeof(biblioteca)/sizeof(Cancion);
	return canciones;
}

void imprimirCanciones(Canciones canciones)
{
	printf("\n Canciones TOTAL:%lld",canciones.cant);
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