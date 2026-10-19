#ifndef LISTAD_H
#define LISTAD_H

#include <stdio.h>
#include <stdlib.h>
#include <Nodo.h>

typedef struct
{	
	Nodod *inicio;
	Nodod *fin;
	size_t cant;
	Orden orden;
	fn_comparar comparar;
	int bucle;
}ListaD;

ListaD inicializarListaD(void);
void insertarOrdenadoD(ListaD *lista,void *dato);
void imprimirListaIFD(ListaD lista,fn_imprimir imprimir);
void imprimirListaFID(ListaD lista,fn_imprimir imprimir);
void eliminarListaD(ListaD *lista,fn_free liberar);
void eliminarDatoD(ListaD *lista,void *dato,fn_comparar comparar);
void insertarInicioD(ListaD *lista,void *dato);
void insertarFinalD(ListaD *lista,void *dato);
int buscarDatoD(ListaD lista,void *dato,fn_comparar comparar);
void ordenarListaD(ListaD *lista,fn_comparar comparar,Orden orden);

void mostrarListaR(ListaD lista, Nodod *nodod);
void bucle(ListaD *lista);
Nodod* anterior(ListaD lista, Nodod *nodod);
Nodod* siguiente(ListaD lista, Nodod *nodod);
void imprimirCancionesD(ListaD lista,fn_imprimir imprimir);
void insertarPosicionD(ListaD *lista, void *dato, int pos, Nodod **nodod);
void eliminarPosicionD(ListaD *lista, int pos, Nodod **nodod);
void liberarListaD(ListaD *lista);

#endif