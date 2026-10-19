#include "Cancion.h"


Canciones cargarCanciones(void)
{
	static Cancion biblioteca[] = 
	{
		(Cancion){"Despacito","Luis Fonsi",2017},
		(Cancion){"Gangnam Style","PSY",2012},
		(Cancion){"Fein","Travis Scott",2023},
		(Cancion){"Imagine","John Lennon",1971},
		(Cancion){"Bohemian Rhapsody","Queen",1975},
		(Cancion){"Billie Jean","Michael Jackson",1982},
		(Cancion){"Like a Prayer","Madonna",1989},
		(Cancion){"Wonderwall","Oasis",1995},
		(Cancion){"Livin la Vida Loca","Ricky Martin",1999},
		(Cancion){"Crazy in Love","Beyonce",2003},
		(Cancion){"Hotel California","Eagles",1976},
		(Cancion){"Stayin Alive","Bee Gees",1977},
		(Cancion){"In the End","Linkin Park",2000},
		(Cancion){"I Will Survive","Gloria Gaynor",1978},
		(Cancion){"Viva la Vida","Coldplay",2008}
	};	
	static Canciones canciones;
	canciones.cancion = biblioteca;
	canciones.cant = sizeof(biblioteca)/sizeof(Cancion);
	return canciones;
}

void imprimirCanciones(Canciones canciones)
{
	printf("\n Canciones TOTAL: %lld",canciones.cant);
	for(int i = 0 ; i < canciones.cant; i++)
	{
		printf("\n [%d]",i);
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