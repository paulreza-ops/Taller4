#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <ListaD.h>
#include "Cancion.h"


int main(void)
{
        int option,corre_programa,seleccion,pos;
	Canciones canciones = cargarCanciones();
        corre_programa=1;
        
        ListaD lista = inicializarListaD();
        Nodod *actual = NULL;

        while(corre_programa)
        {       
                mostrarListaR(lista, actual);
                printf("\n\r");
                printf("\n\r [0] BUCLE");
                printf("\n\r [1] ANTERIOR");
                printf("\n\r [2] SIGUIENTE");
                printf("\n\r [3] AGREGAR CANCION");
                printf("\n\r [4] MOSTRAR LISTA DE REPRODUCCION");
                printf("\n\r [5] QUITAR CANCION");
                printf("\n\r [6] REINICIAR REPRODUCCION");
                printf("\n\r [7] TERMINAR PROGRAMA");

                printf("\n\r Escoge opcion: ");
                scanf("%d",&option);
                        clear_buffer();
                        switch(option)
                {
                case 0:
                        bucle(&lista);
                        break;
                case 1:
                        actual = anterior(lista, actual);
                        break;
                case 2:
                        actual = siguiente(lista, actual);
                        break;
                case 3:
                        imprimirCanciones(canciones);
                        printf("\n Selecciona la cancion a agregar: ");
                        scanf("%d", &seleccion);
                        if(seleccion < 0 || seleccion > canciones.cant){
                                printf(" \n Seleccion invalida \n");
                                break;
                        }
                        imprimirCancionesD(lista, imprimirCancion);
                        printf("\n Selecciona la posicion de la nueva cancion:");
                        scanf("%d", &pos);
                        if(pos <= 0 || pos - 1 > lista.cant){
                                printf(" \n Posicion invalida \n");
                                break;
                        }                        
                        insertarPosicionD(&lista, &canciones.cancion[seleccion], pos - 1, &actual);
                        break;
                case 4:
                        imprimirCancionesD(lista, imprimirCancion);
                        break;
                case 5:
                        if(!lista.inicio){
                                printf("\n Lista vacia \n");
                                break;
                        }
                        imprimirCancionesD(lista, imprimirCancion);
                        printf("\n Selecciona la cancion a eliminar:");
                        scanf("%d", &pos);
                        if(pos <= 0 || pos > lista.cant){
                                printf(" \n Posicion invalida \n");
                                break;
                        }
                        eliminarPosicionD(&lista, pos - 1, &actual);
                        break;
                case 6:
                        actual = lista.inicio;
                        break;
                case 7:
                        corre_programa=0;
                        liberarListaD(&lista);
                        break;
                default:
                        break;
                }
                        printf("\n ENTER PARA CONTINUAR...");
                        clear_buffer();
                        printf("\n");
        }
        printf("\n FIN DE PROGRAMA \n\r");
        return 0;
}