#include "Pila.h"
#include <stdbool.h>

Pila* crearPila(void)
{
	return calloc(1,sizeof(Pila));
}

Pila inicializarPila(int limite)
{
	return (Pila){.cima=NULL,.cant=0,.limite=limite};
}

int pilaLlena(Pila pila)
{
	if(pila.limite!=-1 && pila.cant == pila.limite)
		return true;
	return false;	
}
int pilaVacia(Pila pila)
{
	return (!pila.cima && pila.cant == 0);
}

void* peek(Pila pila)
{
	if( pilaVacia(pila) ) 
		return NULL;
	return pila.cima->dato;
}

void push(Pila *pila,void *dato)
{
	if( pilaLlena(*pila))
	{
		printf("\n Overflow");
		return;
	}
	Nodo *nuevaCima = crearNodo(dato);
	nuevaCima->sig = pila->cima;
	pila->cima = nuevaCima;
	pila->cant++;	
}

void pushN(Pila *pila,Nodo* nuevaCima)
{
	if( pilaLlena(*pila))
	{
		printf("\n Overflow");
		return;
	}
	nuevaCima->sig = pila->cima;
	pila->cima = nuevaCima;
	pila->cant++;	
}

void* pop(Pila *pila)
{
	void *dato = peek(*pila);
	if(dato)
	{
		Nodo *aux = pila->cima;
		pila->cima = aux->sig;
		pila->cant--;
		free(aux);
	}
	return dato;
}


Nodo* popN(Pila *pila)
{
	Nodo *viejaCima = pila->cima;
	if(viejaCima)
	{
		pila->cima = viejaCima->sig;
		viejaCima->sig = NULL;
		pila->cant--;
	}
	return viejaCima;
}
void imprimirPila(Pila pila,fn_imprimir imprimir)
{
	Pila pilaAux = inicializarPila(pila.limite);
	printf("\n [%lld] Pila:",pila.cant);
	while( !pilaVacia(pila) )
	{
		Nodo *aux = popN(&pila);
		printf("\n");
		imprimir(aux->dato);
		pushN(&pilaAux,aux);
	}
	while( !pilaVacia(pilaAux) )
	{
		pushN(&pila, popN(&pilaAux) );
	}
}

void eliminarPila(Pila *pila,fn_free liberar)
{	
	while( !pilaVacia(*pila) )
	{
		void *aux = pop(pila);
		if(liberar)
			liberar(aux);
	}
}
int buscarDatoPila(Pila pila,void *dato,fn_comparar comparar)
{
	return 0;
}

void hanoiDosPilas(Pila *pila, fn_comparar comparar){
	if(!pila->cima && pila->cant == 0)
		return;

	Pila pilaB = inicializarPila(-1);
	int ordenado = 0;
	int cant = pila->cant;
	int cantAux;
	Nodo *aux = NULL, *aux2 = NULL;
	while(!ordenado){
		cantAux = 0;
		while(pila->cima){
			if(!aux)
				aux = popN(pila);

			if(pila->cima){
				aux2 = popN(pila);
				int res = comparar(aux->dato, aux2->dato);
				if(res == 1)
					pushN(&pilaB, aux2);
				else if(res == -1){
					pushN(&pilaB, aux);
					aux = aux2;
					cantAux++;
				}
				else if(res == 0){
					pushN(&pilaB, aux2);
					cantAux++;
				}
			}

			if(!pila->cima){
				pushN(&pilaB, aux);
				cantAux++;
				aux = NULL, aux2 = NULL;
			}

			if(cantAux == cant)
				ordenado = 1;
		}

		cantAux = 0;
		while(pilaB.cima){
			if(!aux)
				aux = popN(&pilaB);
			
			if(pilaB.cima){
				aux2 = popN(&pilaB);
				int res = comparar(aux->dato, aux2->dato);	
				if(res == -1)
					pushN(pila, aux2);
				else if(res == 1){
					pushN(pila, aux);
					aux = aux2;
					cantAux++;
				}
				else if(res == 0){
					pushN(pila, aux2);
					cantAux++;
				}
			}

			if(!pilaB.cima){
				pushN(pila, aux);
				cantAux++;
				aux = NULL, aux2 = NULL;
			}

			if(cantAux == cant)
				ordenado = 1;
		}
	}
}

void hanoiTresPilas(Pila *pila, fn_comparar comparar){
	if(!pila->cima && pila->cant == 0)
		return;

	Pila pilaB = inicializarPila(-1);
	Pila pilaC = inicializarPila(-1);
	int ordenado = 0;
	int cant = pila->cant;
	int cantAux = 0;
	Nodo *aux = NULL, *aux2 = NULL;
	while(!ordenado){
		while(pila->cima){
			if(!aux)
				aux = popN(pila);

			if(pila->cima){
				aux2 = popN(pila);
				int res = comparar(aux->dato, aux2->dato);
				if(res == 1){
					pushN(&pilaC, aux);
					aux = aux2;
				}
				else if(res == -1){
					pushN(&pilaC, aux2);
				}
				else if(res == 0){
					pushN(&pilaC, aux2);
				}
			}

			if(!pila->cima){
				pushN(&pilaB, aux);
				cantAux++;
				aux = NULL, aux2 = NULL;
			}
		}

		while(pilaC.cima){
			if(!aux)
				aux = popN(&pilaC);
			
			if(pilaC.cima){
				aux2 = popN(&pilaC);
				int res = comparar(aux->dato, aux2->dato);	
				if(res == 1){
					pushN(pila, aux);
					aux = aux2;
				}
				else if(res == -1){
					pushN(pila, aux2);
				}
				else if(res == 0){
					pushN(pila, aux2);
				}
			}

			if(!pilaC.cima){
				pushN(&pilaB, aux);
				cantAux++;
				aux = NULL, aux2 = NULL;
			}

		}

		if(cantAux == cant){
			while(pilaB.cima)
				pushN(pila, popN(&pilaB));
			ordenado = 1;
		}
	}
}