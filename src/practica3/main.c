#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <ctype.h>
#include <Pila.h>
#include <Cola.h>

void imprimir(void *);
int compararChar(void *, void*);
int compararCierre(void *, void *);

int main(void)
{
	Pila pila = inicializarPila(-1);
    char cadena[30];
	
	int option,corre_programa, i, limite, valido;
	corre_programa = 1;

	while(corre_programa)
	{       
		printf("\n\r");
		printf("\n\r [1] Palindromo");
		printf("\n\r [2] Verificacion de parentesis");
		printf("\n\r [3] Terminar ejecucion");

		printf("\n\r Escoge opcion: ");
		scanf("%d",&option);
		clear_buffer();
		switch(option)
		{
			case 1:
				printf("\n Inserta la cadena a revisar: ");
				fgets(cadena, sizeof(cadena), stdin);
				cadena[strcspn(cadena, "\n")] = '\0';
				
				i = 0;
				while(cadena[i] != '\0'){
					if(cadena[i] != ' '){
						cadena[i] = tolower(cadena[i]);
						push(&pila, &cadena[i]);
					}
					i++;
				}
				
				limite = i;
				for(i = 0; i < limite; i++){
					if(cadena[i] != ' '){
						if(compararChar(pop(&pila), &cadena[i]) != 0){
							printf("\n No es un palindromo");
							break;
						}
						if(!pila.cima){
							printf("\n Es un palindromo");
						}
					}
				}
				while(pila.cima){
					pop(&pila);
				}
				break;
			case 2:
				printf("\n Inserta la cadena a revisar: ");
				fgets(cadena, sizeof(cadena), stdin);
				cadena[strcspn(cadena, "\n")] = '\0';
				
				valido = 1;
				for(i = 0; cadena[i] != '\0'; i++){
					if(cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{')
						push(&pila, &cadena[i]);
					
					if(cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}'){
						if(!pila.cima){
							valido = 0;
							break;
						}
						if(compararCierre(pop(&pila), &cadena[i]) != 0){
							valido = 0;
							break;
						}
					}

				}

				if(valido && !pila.cima)
					printf("\n Cadena valida");
				else 
					printf("\n Cadena invalida");

				while(pila.cima){
					pop(&pila);
				}
				break;
			case 3:
				corre_programa=0;
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

void imprimir(void *dato)
{
	printf(" %c ",*(char*)dato);
}

int compararChar(void *pa, void *pb){
	int a = *(char*)pa;
	int b = *(char*)pb;
	if(a > b) return 1;
	else if (b > a) return -1;
	else return 0;
}

int compararCierre(void *pa, void *pb){
	int a = *(char*)pa;
	int b = *(char*)pb;
	if(a == '(' && b == ')') return 0;
	else if(a == '[' && b == ']') return 0;
	else if(a == '{' && b == '}') return 0;
	else return 1;
}