#include <stdio.h>
#include <stdlib.h>
#include <iostring.h>
#include <arbol.h>
#include <Nodo.h>

int *crearEntero(int);
void imprimir(void*);


int main(void)
{
/*	Nodoa *raiz = crearNodoa( crearEntero(4) );
	raiz->izq = crearNodoa(crearEntero(2) );
	raiz->izq->izq = crearNodoa(crearEntero(1) );
	raiz->izq->dch = crearNodoa(crearEntero(3) );
	raiz->dch =  crearNodoa(crearEntero(6) );	
	raiz->dch->izq =  crearNodoa(crearEntero(5) );
	raiz->dch->dch = crearNodoa(crearEntero(7) );
	Arbol arbol;
	arbol.raiz = raiz;
	printf("\n Altura %lld", altura(arbol));
	printf("\n Altura %lld", alturaI(arbol));
	printf("\n PREORDEN");
	imprimirOrden(arbol,imprimir,PREORDEN);
	printf("\n ORDEN");
	imprimirOrden(arbol,imprimir,ORDEN);
	printf("\n POSTORDEN");
	imprimirOrden(arbol,imprimir,POSTORDEN);
*/
	Arbol arbol = {NULL, 0, NINGUNO};
	insertarArbolO(&arbol, crearEntero(5));
	insertarArbolO(&arbol, crearEntero(7));
	insertarArbolO(&arbol, crearEntero(9));
	insertarArbolO(&arbol, crearEntero(15));
	insertarArbolO(&arbol, crearEntero(2));
	insertarArbolO(&arbol, crearEntero(20));
	insertarArbolO(&arbol, crearEntero(4));
	insertarArbolO(&arbol, crearEntero(3));
	insertarArbolO(&arbol, crearEntero(6));
	insertarArbolO(&arbol, crearEntero(8));
	insertarArbolO(&arbol, crearEntero(1));
	

	printf("\n Arbol\n");
	imprimirArbol(arbol,imprimir);

	
	printf("\n\n");
	flipArbol(&arbol);
	printf("\n Arbol\n");
	imprimirArbol(arbol, imprimir);


	printf("\n\n");
	flipArbol(&arbol);
	printf("\n Arbol\n");
	imprimirArbol(arbol, imprimir);

	int num = 10;
	void *buscando = buscarArbol(&arbol, &num);
	if(buscando != NULL){
		printf("\n\n Encontrado: %d", *(int*)buscando);
	} else {
		printf("\n\n No Encontrado");
	}
    printf("\n\n FIN DE PROGRAMA\n\n");
    return 0;
}


int *crearEntero(int num)
{
	int *dato = calloc(1,sizeof(int));
	*dato = num;
	return dato;
}

void imprimir(void *dato)
{
	printf("%d",*(int*)dato);
}