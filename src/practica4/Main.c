#include <stdio.h>
#include <stdlib.h>
#include <Pila.h>
#include <iostring.h>
#include "Laberinto.h"

Pila* resolverLab(Laberinto lab, Coordenada origen,Coordenada destino);

int main(void)
{
    Laberinto lab = crear_laberinto();
	Coordenada origen = {1,1}; 
	Coordenada destino = {25,24};
	unsigned int nuevasCoor = 0;	
	inputEnteroSinSigno("\n Nuevas coordendas? (1:SI 0:NO) : ",&nuevasCoor);
	if(nuevasCoor)
	{
		inputEntero("\n Captura Origen X: ",&origen.x);
		inputEntero(" Captura Origen Y: ",&origen.y);
		inputEntero("\n Captura Destino X: ",&destino.x);
		inputEntero(" Captura Destino Y: ",&destino.y);
	}
	setOrigen(lab,origen);
	setDestino(lab,destino);	
	
	Pila *pila = resolverLab(lab,origen,destino);
	
	imprimirLab(lab);
	liberarLaberinto(lab);
	eliminarPila(pila,free);
	free(pila);
    printf("\n\n FIN DE PROGRAMA\n\n");
    return 0;
}

Pila* resolverLab(Laberinto lab, Coordenada origen,Coordenada destino)
{
	Pila *pila = crearPila();
	*pila = inicializarPila(-1);
	Coordenada *punto;

	punto = crearCoordenada(origen.x,origen.y);
	push(pila,punto);
	
	while(!pilaVacia(*pila))
	{
		//printf("\n Presione enter para continuar....");
		//clear_buffer();
		//imprimirLab(lab);

		punto = (Coordenada*)peek(*pila);
		if(punto->x == destino.x && punto->y == destino.y)
			break;

		Movimientos mov = movimientosPosibles(lab, *punto);
		
		if(bloqueado(mov)){
			lab[punto->x][punto->y] = 'o';
			Coordenada *descartado = (Coordenada*)pop(pila);
			free(descartado);
		} else {
			Coordenada *nuevo = NULL;

			if(mov.right){
				nuevo = crearCoordenada(punto->x, punto->y + 1);
			}else if(mov.left){
				nuevo = crearCoordenada(punto->x, punto->y - 1);
			}else if(mov.down){
				nuevo = crearCoordenada(punto->x + 1, punto->y);
			}else if(mov.up){
				nuevo = crearCoordenada(punto->x - 1, punto->y);
			}

			if(lab[nuevo->x][nuevo->y] == '*')
				lab[nuevo->x][nuevo->y] = '.';

			push(pila, nuevo);
		}
		
	}
	return pila;
}