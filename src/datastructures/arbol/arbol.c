#include "arbol.h"


size_t altura(Arbol arbol)
{
	Arbol arbol_izq,arbol_dch;
	size_t hd,hi;
	if(!arbol.raiz) 
		return 0;
	if(!arbol.raiz->izq && !arbol.raiz->dch)
		return 1;
	arbol_izq.raiz = arbol.raiz->izq;
	arbol_dch.raiz = arbol.raiz->dch;
	hi = altura(arbol_izq);
	hd = altura(arbol_dch);
	if( hi>hd )
		return hi + 1;
	else
		return hd + 1;
}

size_t alturaI(Arbol arbol)
{
	size_t max_altura = 0;
	
	if (!arbol.raiz)
		return max_altura;

	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			push(&pila, actual);
			
			if (pila.cant > max_altura)
				max_altura = pila.cant;
			
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = peek(pila);
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
				ultimo_visitado = pop(&pila);
		}
	}

	return max_altura;
}


void preordenI(Arbol arbol,fn_imprimir imprimir)
{
	if (!arbol.raiz)
		return ;
	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			printf(" ");
			imprimir(actual->dato);
			push(&pila, actual);
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = peek(pila);			
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
				ultimo_visitado = pop(&pila);
		}
	}
}


void ordenI(Arbol arbol,fn_imprimir imprimir)
{
	if (!arbol.raiz)
		return ;
	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			push(&pila, actual);
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = pop(&pila);			
			printf(" ");
			imprimir(padre->dato);
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
				ultimo_visitado = padre;
		}
	}
}

void postordenI(Arbol arbol,fn_imprimir imprimir)
{
	if (!arbol.raiz)
		return ;
	Pila pila = inicializarPila(-1);
	Nodoa *actual = arbol.raiz;
	Nodoa *ultimo_visitado = NULL;

	while (actual != NULL || !pilaVacia(pila))
	{
		if (actual != NULL)
		{
			push(&pila, actual);
			actual = actual->izq;
		}
		else
		{
			Nodoa *padre = peek(pila);			
			if (padre->dch != NULL && ultimo_visitado != padre->dch)
				actual = padre->dch;
			else
			{
				printf(" ");
				imprimir(padre->dato);
				ultimo_visitado = pop(&pila);
			}
		}
	}
}


void preorden(Nodoa *raiz,void (*imprimir)(void*)){
	if(!raiz) return;
	printf(" ");
	imprimir(raiz->dato);
	preorden(raiz->izq,imprimir);
	preorden(raiz->dch,imprimir);
}

void orden(Nodoa *raiz,void (*imprimir)(void*)){
	if(!raiz) return;
	orden(raiz->izq,imprimir);
	printf(" ");
	imprimir(raiz->dato);
	orden(raiz->dch,imprimir);	
}

void inverso(Nodoa *raiz,void (*imprimir)(void*)){
	if(!raiz) return;
	inverso(raiz->dch,imprimir);	
	printf(" ");
	imprimir(raiz->dato);
	inverso(raiz->izq,imprimir);
}

void postorden(Nodoa *raiz,void (*imprimir)(void*)){
	if(!raiz) return;
	postorden(raiz->izq,imprimir);
	postorden(raiz->dch,imprimir);
	printf(" ");
	imprimir(raiz->dato);	
}


void imprimirOrden(Arbol arbol,fn_imprimir imprimir,int opcion)
{
	switch(opcion)
	{
		case PREORDEN: 
			//preorden(arbol.raiz,imprimir);
			preordenI(arbol,imprimir);
			break;
		case ORDEN: 
			//orden(arbol.raiz,imprimir);
			ordenI(arbol,imprimir);
			break;
		case INVERSO: 
			inverso(arbol.raiz,imprimir);
			break;
		case POSTORDEN: 
			//postorden(arbol.raiz,imprimir);			
			postordenI(arbol,imprimir);
			break;
	}
}

void imprimir_arbol(Nodoa* nodo, int nivel,fn_imprimir imprimir){
    int i;
    if (nodo != NULL){
        printf(" ");
		imprimir(nodo->dato);
        if(nodo->dch){
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                if(i==nivel)
                    printf(" |____R ");
                else
                    printf(" |      ");
            }
            imprimir_arbol(nodo->dch, nivel + 1,imprimir);
        }
        if(nodo->izq){
            printf("\n");
            for (i = 0; i < nivel+1; i++)
                printf(" |      ");
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                if(i==nivel)
                    printf(" |____L ");
                else
                    printf(" |      ");
            }
            imprimir_arbol(nodo->izq, nivel + 1,imprimir);
        }
    }
}

void imprimirArbol(Arbol arbol,fn_imprimir imprimir)
{
	imprimir_arbol(arbol.raiz,0,imprimir);
}

int compararInt(void *ap, void *bp){
	int a = *(int *)ap;
	int b = *(int *)bp;
	if(a < b) return 1;
	else if (a > b) return -1;
	else return 0;
}

/*
Nodoa* _insertarRecursivo(Nodoa *actual, void *dato) {
    if (actual == NULL)
        return crearNodoa(dato);

    if (compararInt(actual->dato, dato) == 1)
        actual->dch = _insertarRecursivo(actual->dch, dato);
    else
        actual->izq = _insertarRecursivo(actual->izq, dato);

    return actual;
}

void insertarArbolO(Arbol *arbol, void *dato) {
    if (!arbol) return;
    arbol->raiz = _insertarRecursivo(arbol->raiz, dato);
}
*/

void insertarArbolO(Arbol *arbol, void *dato){
	Nodoa *insertar = crearNodoa(dato);

	if(!arbol->raiz){
		arbol->raiz = insertar;
		return;
	}

	Nodoa *actual = arbol->raiz;

	while(1){
		if(compararInt(actual->dato, dato) == 1){
			if(!actual->dch){
				actual->dch = insertar;
				return;
			}
			actual = actual->dch;
		} else {
			if(!actual->izq){
				actual->izq = insertar;
				return;
			}
			actual = actual->izq;
		}
	}
}

/*
void invertirNodos(Nodoa *nodo) {
    if (nodo == NULL) return;
    
    invertirNodos(nodo->izq);
    invertirNodos(nodo->dch);
    
    Nodoa *temp = nodo->izq;
    nodo->izq = nodo->dch;
    nodo->dch = temp;
}

void flipArbol(Arbol *arbol){
    if(!arbol || !arbol->raiz) return;
    invertirNodos(arbol->raiz);
}
*/

void flipArbol(Arbol *arbol){
	if(!arbol || !arbol->raiz) return;

	Pila pila = inicializarPila(-1);
	push(&pila, arbol->raiz);

	while(!pilaVacia(pila)){
		Nodoa *actual = pop(&pila);

		Nodoa *temp = actual->izq;
		actual->izq = actual->dch;
		actual->dch = temp;

		if(actual->izq != NULL)
			push(&pila, actual->izq);
		if(actual->dch != NULL)
			push(&pila, actual->dch);
	}
}

/*
void* _buscarRecursivo(Nodoa *actual, void *dato) {
    if (actual == NULL)
        return NULL;

    int cmp = compararInt(actual->dato, dato);

    if (cmp == 0)
        return actual->dato;
    
    if (cmp == 1)
        return _buscarRecursivo(actual->dch, dato);
    else
        return _buscarRecursivo(actual->izq, dato);
}

void* buscarArbol(Arbol *arbol, void *dato) {
    if (!arbol || !arbol->raiz) return NULL;
    return _buscarRecursivo(arbol->raiz, dato);
}
*/

void* buscarArbol(Arbol *arbol, void *dato){
	if(!arbol->raiz) return NULL;

	Nodoa *actual = arbol->raiz;

	while(actual != NULL){
		int cmp = compararInt(actual->dato, dato);

		if(cmp == 0)
			return actual->dato;
		
		if(cmp == 1)
			actual = actual->dch;
		else
			actual = actual->izq;
	}

	return NULL;
}

/*
void liberarArbol(Nodoa *nodo){
	if(nodo == NULL) return;
	liberarArbol(nodo->izq);
	liberarArbol(nodo->dch);
	free(nodo);
}
*/

void liberarArbolI(Nodoa *raiz){
	if(raiz == NULL) return;

	Pila pila = inicializarPila(-1);
	push(&pila, raiz);

	while(!pilaVacia(pila)){
		Nodoa *actual = pop(&pila);

		if(actual->dch != NULL)
			push(&pila, actual->dch);
		if(actual->izq != NULL)
			push(&pila, actual->izq);
		free(actual->dato);
		free(actual);
	}
}

int eliminarDatoArbol(Arbol *arbol, void *dato) {
    if (!arbol->raiz) return 0;

    Nodoa *actual = arbol->raiz;
    Nodoa *padre = NULL;
    int cmp;

    while (actual != NULL) {
        cmp = compararInt(actual->dato, dato);
        if (cmp == 0) break;
        
        padre = actual;
        if (cmp == 1) actual = actual->dch;
        else actual = actual->izq;
    }

    if (actual == NULL) return 0;

    if (actual->izq != NULL && actual->dch != NULL) {

        Nodoa *sucesor = actual->dch;
        Nodoa *padre_sucesor = actual;
        
        while (sucesor->izq != NULL) {
            padre_sucesor = sucesor;
            sucesor = sucesor->izq;
        }

        void *temp = actual->dato;
        actual->dato = sucesor->dato;
        sucesor->dato = temp;

        actual = sucesor;
        padre = padre_sucesor;
    }

    Nodoa *hijo = (actual->izq != NULL) ? actual->izq : actual->dch;

    if (padre == NULL) {
        arbol->raiz = hijo;
    } else if (padre->izq == actual) {
        padre->izq = hijo;
    } else {
        padre->dch = hijo;
    }

    free(actual->dato); 
    free(actual);
    return 1;
}

typedef struct {
    int inicio;
    int fin;
} Rango;

int contarNodosI(Nodoa *raiz) {
    if (raiz == NULL) return 0;
    
    Pila pila = inicializarPila(-1);
    push(&pila, raiz);
    int cant = 0;
    
    while (!pilaVacia(pila)) {
        Nodoa *actual = pop(&pila);
        cant++;
        
        if (actual->dch != NULL) 
			push(&pila, actual->dch);
        if (actual->izq != NULL) 
			push(&pila, actual->izq);
    }
    return cant;
}

void llenarArregloInordenI(Nodoa *raiz, void **arreglo, int *indice) {
    if (raiz == NULL) return;

    Pila pila = inicializarPila(-1);
    Nodoa *actual = raiz;

    while (actual != NULL || !pilaVacia(pila)) {
        if (actual != NULL) {
            push(&pila, actual);
            actual = actual->izq;
        } else {
            Nodoa *padre = pop(&pila);
            arreglo[*indice] = padre->dato;
            (*indice)++;
            actual = padre->dch;
        }
    }
}

void vaciarNodosArbolI(Nodoa *raiz) {
    if (raiz == NULL) return;

    Pila pila = inicializarPila(-1);
    push(&pila, raiz);

    while (!pilaVacia(pila)) {
        Nodoa *actual = pop(&pila);

        if (actual->dch != NULL)
            push(&pila, actual->dch);
        if (actual->izq != NULL)
            push(&pila, actual->izq);

        free(actual);
    }
}

void reconstruirBalanceadoI(Arbol *arbol, void **arreglo, int total_nodos) {
    if (total_nodos == 0) return;

    Pila pila = inicializarPila(-1);
    
    Rango *r_inicial = malloc(sizeof(Rango));
    r_inicial->inicio = 0;
    r_inicial->fin = total_nodos - 1;
    push(&pila, r_inicial);

    while (!pilaVacia(pila)) {
        Rango *r = pop(&pila);
        int inicio = r->inicio;
        int fin = r->fin;
        free(r);

        if (inicio > fin) continue;

        int medio = inicio + (fin - inicio) / 2;
        insertarArbolO(arbol, arreglo[medio]);

        if (medio + 1 <= fin) {
            Rango *r_dch = malloc(sizeof(Rango));
            r_dch->inicio = medio + 1;
            r_dch->fin = fin;
            push(&pila, r_dch);
        }

        if (inicio <= medio - 1) {
            Rango *r_izq = malloc(sizeof(Rango));
            r_izq->inicio = inicio;
            r_izq->fin = medio - 1;
            push(&pila, r_izq);
        }
    }
}

void equilibrarArbol(Arbol *arbol) {
    if (!arbol || !arbol->raiz) return;

    int total_nodos = contarNodosI(arbol->raiz);
    if (total_nodos <= 2) return; 

    void **arreglo = malloc(total_nodos * sizeof(void *));
    int indice = 0;
    
    llenarArregloInordenI(arbol->raiz, arreglo, &indice);
    vaciarNodosArbolI(arbol->raiz);
    arbol->raiz = NULL;
    
    reconstruirBalanceadoI(arbol, arreglo, total_nodos);

    free(arreglo);
}

void liberarArbolPostordenI(Nodoa *raiz) {
    if (raiz == NULL) return;

    Pila pila1 = inicializarPila(-1);
    Pila pila2 = inicializarPila(-1);
    
    push(&pila1, raiz);
    
    while (!pilaVacia(pila1)) {
        Nodoa *actual = pop(&pila1);
        push(&pila2, actual);
        
        if (actual->izq != NULL) push(&pila1, actual->izq);
        if (actual->dch != NULL) push(&pila1, actual->dch);
    }
    
    while (!pilaVacia(pila2)) {
        Nodoa *actual = pop(&pila2);
        free(actual->dato);
        free(actual);
    }
}