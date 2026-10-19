#include "ListaD.h"
#include "../../practica2/Cancion.h"

ListaD inicializarListaD(void)
{
	return (ListaD){.inicio=NULL,.fin=NULL,.cant=0,.orden=NINGUNO,.comparar=NULL,.bucle=0};
}
void insertarOrdenadoD(ListaD *lista,void *dato)
{
	if(!lista->inicio || lista->comparar(dato,lista->inicio->dato) < 0)
		insertarInicioD(lista,dato);
	else if( lista->comparar(dato,lista->fin->dato) > 0)
		insertarFinalD(lista,dato);
	else
	{
		Nodod *nuevo = crearNodod(dato);
		Nodod *q = lista->inicio;
		Nodod *p = q->sig;
		while( lista->comparar(dato,p->dato) > 0) 
		{
			q = p;
			p = p->sig;
		}
		q->sig = nuevo;
		nuevo->ant = q;
		nuevo->sig = p;
		p->ant = nuevo;
		lista->cant++;
	}	
}

void imprimirListaIFD(ListaD lista,fn_imprimir imprimir)
{
	if(!lista.inicio) return;
	Nodod *aux = lista.inicio;
	do
	{
		printf("\n");
		imprimir(aux->dato);
		aux = aux->sig;
	}while( aux && aux!= lista.inicio);
}
void imprimirListaFID(ListaD lista,fn_imprimir imprimir)
{
	if(!lista.inicio) return;
	Nodod *aux = lista.fin;
	do
	{
		printf("\n");
		imprimir(aux->dato);
		aux = aux->ant;
	}while( aux && aux!= lista.fin);
}


void eliminarListaD(ListaD *lista,fn_free liberar)
{
	
}

void insertarInicioD(ListaD *lista,void *dato)
{
	Nodod *nuevo = crearNodod(dato);
	if(!lista->inicio)
		lista->inicio = lista->fin = nuevo;
	else
	{
		nuevo->sig = lista->inicio;
		lista->inicio->ant = nuevo;
		lista->inicio = nuevo;
	}
	lista->cant++;
}

void insertarFinalD(ListaD *lista,void *dato)
{
	Nodod *nuevo = crearNodod(dato);
	if(!lista->inicio)
		lista->inicio = lista->fin = nuevo;
	else
	{
		nuevo->ant = lista->fin;
		lista->fin->sig = nuevo;
		lista->fin = nuevo;
	}
	lista->cant++;
	
}
void eliminarDatoD(ListaD *lista,void *dato,fn_comparar comparar)
{
	
}
int buscarDatoD(ListaD lista,void *dato,fn_comparar comparar)
{
	return 0;
}
void ordenarListaD(ListaD *lista,fn_comparar comparar,Orden orden)
{
	
}


void mostrarListaR(ListaD lista, Nodod *nodod){
	if(!lista.inicio || !nodod){
		printf("\n %-10s %10s %-10s %-10s %-10s \n", 
			"Ninguna", "<<--", "Ninguna", "-->>", "Ninguna");
		return;
	}

	Nodod *act = lista.inicio;
	do{
		if(act == nodod){
			printf("\n");
			if(!act->ant) printf(" %-20s ", "Ninguna");
			else imprimirNombre(act->ant->dato);
			imprimirNombre(act->dato);
			if(!act->sig) printf(" %-20s ", "Ninguna");
			else imprimirNombre(act->sig->dato);
			printf("\n");				
		}
		act = act->sig;
	}while(act && act != lista.inicio);
}

void bucle(ListaD *lista){
	if(!lista->inicio){
		printf("\n Lista vacia \n");
		return;
	}

	if(lista->bucle == 0){
		lista->inicio->ant = lista->fin;
		lista->fin->sig = lista->inicio;
		lista->bucle = 1;
	} else {
		lista->inicio->ant = NULL;
		lista->fin->sig = NULL;
		lista->bucle = 0;
	}
}

Nodod* anterior(ListaD lista, Nodod *nodod){
	if(!lista.inicio || !nodod){
		printf("\n Lista vacia \n");
		return nodod;
	}

	Nodod *act = lista.inicio;
	do{
		if(act == nodod && act->ant != NULL){
			return act->ant;
		} else if(act == nodod && act->ant == NULL){
			printf("\n No hay cancion anterior \n");
			return nodod;
		}
		act = act->sig;
	}while(act && act != lista.inicio);	
	return nodod;
}

Nodod* siguiente(ListaD lista, Nodod *nodod){
	if(!lista.inicio || !nodod){
		printf("\n Lista vacia \n");
		return nodod;
	}

	Nodod *act = lista.inicio;
	do{
		if(act == nodod && act->sig != NULL){
			return act->sig;
		} else if(act == nodod && act->sig == NULL){
			printf("\n No hay cancion siguiente \n");
			return nodod;
		}
		act = act->sig;
	}while(act && act != lista.inicio);	
	return nodod;
}

void imprimirCancionesD(ListaD lista,fn_imprimir imprimir)
{
	if(!lista.inicio) return;
	Nodod *aux = lista.inicio;
	int i = 1;
	do
	{
		printf("\n");
		printf(" [%d] ", i);
		imprimir(aux->dato);
		aux = aux->sig;
		i++;
	}while( aux && aux!= lista.inicio);
}

void insertarPosicionD(ListaD *lista, void *dato, int pos, Nodod **nodod){
	
	if(!dato) return;

	Nodod *nuevo = crearNodod(dato);
	
	if(!lista->inicio){
		lista->inicio = lista->fin = nuevo;
		lista->cant++;
		*nodod = lista->inicio;
		return;
	}

	if(pos == 0){
		nuevo->sig = lista->inicio;
		lista->inicio->ant = nuevo;
		lista->inicio = nuevo;
		
		if(lista->bucle == 1){
			nuevo->ant = lista->fin;
			lista->fin->sig = nuevo;
		} else
			nuevo->ant = NULL;
	
		lista->cant++;
		return;
	}

	if(pos == lista->cant){
		nuevo->ant = lista->fin;
		lista->fin->sig = nuevo;
		lista->fin = nuevo;
		if(lista->bucle == 1){
			nuevo->sig = lista->inicio;
			lista->inicio->ant = nuevo;
		} else 
			nuevo->sig = NULL;
		lista->cant++;
		return;
	}
	
	Nodod *actual = lista->inicio;

	for(int i = 0; i < pos; i++){
		actual = actual->sig;
	}

	Nodod *anterior = actual->ant;

	nuevo->sig = actual;
	nuevo->ant = anterior;
	actual->ant = nuevo;
	anterior->sig = nuevo;
	lista->cant++;
}

void eliminarPosicionD(ListaD *lista, int pos, Nodod **nodod){
    
    if (!lista || !lista->inicio){
        return;
    }

    Nodod *liberar = NULL;

    if (lista->inicio == lista->fin){
        liberar = lista->inicio;
        lista->inicio = NULL;
        lista->fin = NULL;
        lista->cant = 0;
        free(liberar);
        if (nodod != NULL) {
            *nodod = NULL;
        }
        return;
    }

    if (pos == 0){
        liberar = lista->inicio;
        if (lista->bucle == 1){
            lista->fin->sig = liberar->sig;
            liberar->sig->ant = lista->fin;
        } else {
            liberar->sig->ant = NULL;
        }
        lista->inicio = liberar->sig;
    } 
    else if (pos == lista->cant - 1){
        liberar = lista->fin;
        if (lista->bucle == 1){
            lista->inicio->ant = liberar->ant;
            liberar->ant->sig = lista->inicio;
        } else {
            liberar->ant->sig = NULL;
        }
        lista->fin = liberar->ant;
    } 
    else {
        liberar = lista->inicio;
        for (int i = 0; i < pos; i++){
            liberar = liberar->sig;
        }

        Nodod *anterior = liberar->ant;
        Nodod *siguiente = liberar->sig;

        anterior->sig = siguiente;
        siguiente->ant = anterior;
    }

    if (nodod != NULL && *nodod == liberar) {
        if (liberar->sig != NULL) {
            *nodod = liberar->sig;
        } else {
            *nodod = liberar->ant;
        }
    }

    free(liberar);
    lista->cant--;
}

void liberarListaD(ListaD *lista) {
    if (!lista || !lista->inicio) {
        return;
    }

    if (lista->bucle == 1) {
        lista->fin->sig = NULL;
        lista->inicio->ant = NULL;
		lista->bucle = 0;
    }

    Nodod *actual = lista->inicio;
    Nodod *siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }

    lista->inicio = NULL;
    lista->fin = NULL;
    lista->cant = 0;
}