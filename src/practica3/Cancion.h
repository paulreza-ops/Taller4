#ifndef CANCION_H
#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
#include <string.h>

#define MAXCADENA 20

typedef struct 
{
    char nombre[MAXCADENA];
    char autor[MAXCADENA];
    short int release_date;
}Cancion;

typedef struct
{
	Cancion *cancion;
	size_t cant;
}Canciones;


Canciones cargarCanciones(void); 
void imprimirCanciones(Canciones);
void imprimirCancion(void*);
void imprimirNombre(void*);

#endif