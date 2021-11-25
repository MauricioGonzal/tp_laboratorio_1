/*
 * input.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString(char* cadena, char* mensaje, char* mensajeError, int longitud){
	int retorno=-1;
	char bufferString[4096];
	printf("%s", mensaje);
	if(cadena!= NULL && longitud>0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL){
			if(bufferString[strlen(bufferString)-1]== '\n'){
				bufferString[strlen(bufferString)-1]='\0';
			}
			if(strlen(bufferString)<= longitud){
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
			else{

				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

float LoadFloat(char message[]){
    float option;
    printf("%s", message);
    scanf("%f", &option);
    while(option <0)
    {
    printf("\nERROR.%s", message);
    scanf("%f", &option);
    }
    return option;
}

int LoadInt(char message[]){
    int option;
    printf("%s\n", message);
    scanf("%d", &option);

    return option;
}

int LoadIntRange(char message[], int* opcion, int num){
	int retorno;
	int option;
    if(message!=NULL && opcion!= NULL){
	printf("%s", message);
    scanf("%d", &option);
    *opcion= option;
    while(option <0 || option > num){
        printf("\nERROR.%s", message);
        scanf("%d", &option);
        }
    retorno=0;
    }
    return retorno;
}

void LoadString(char message[], char loadedString[]){


	printf("%s\n", message);
    fflush(stdin);
    scanf("%[^\n]", loadedString);

}

int LoadStringValidado(char message[], char loadedString[]){
    char buffer[51];
    int retorno;
    retorno=0;
	printf("%s\n", message);
    fflush(stdin);
    scanf("%[^\n]", buffer);

    for(int i=0;i<strlen(buffer); i++){
    	if(isdigit(buffer[i])!=0){
    		retorno=-1;
    		break;
    	}
    }
    if(retorno==0){
    strcpy(loadedString, buffer);
    }

    return retorno;
}

int SalirDelPrograma(){
	int opcion;
	printf("seguro desea salir del programa?\n1.SI\n2.NO");
	scanf("%d", &opcion);

	return opcion;
}

void VerificacionRetorno(int retorno, char mensajeCorrecto[], char mensajeError[]){

	if(retorno==0){
		printf("%s", mensajeCorrecto);
	}
	else{
		if(retorno==-1){
		printf("%s", mensajeError);
	}
	}
}

void VerificarTresRetornos(int retorno, char mensajeCorrecto[], char mensajeNoExiste[], char mensajeError[]){

	if(retorno==0){
			printf("%s", mensajeCorrecto);
		}
		else{
			if(retorno==1){
				printf("%s", mensajeNoExiste);
			}
			else{
			printf("%s", mensajeError);
		}
		}
}



void Menu (){
	printf("MENU\n");
		printf("1) Alta de cliente.\n2) Modificar datos de cliente.\n3) Baja de cliente.\n4) Crear pedido de recolección.\n5) Procesar residuos.\n6) Imprimir Clientes.\n"
				"7) Imprimir Pedidos pendientes.\n8) Imprimir Pedidos procesados.\n9) Buscar cantidad de pedidos pendientes por localidad.\n"
				"10) Cantidad de kilos de polipropileno reciclado promedio por cliente. \n11)Buscar cliente con mas pedidos pendientes\n12)Buscar cliente con mas pedidos completados\n13) SALIR\n");
}


/*int ordenarArrayInt(int* pArray, int limite){
	int flagSwap;
	int i;
	int contador;
	int retorno;
	int buffer;
	int nuevoLimite;

	if(pArray!= NULL && limite>0)
	{
		nuevoLimite= nuevoLimite-1;
		do{
			flagSwap=0;
			for(i=0;i<limite-1;i++){
				contador++;
				if(pArray[i]<pArray[i+1]){
					flagSwap=1;
					buffer = pArray[i];
					pArray[i]= pArray[i+1];
					pArray[i+1]= buffer;
				}
				nuevoLimite--;
			}
		}while(flagSwap);
		retorno=contador;
	}
	return retorno;
}*/

int ValidarNumero(char numeros[]){
	int retorno=0;
	for(int i=0;i<strlen(numeros);i++){
		if(isdigit(numeros[i])==0){
			printf("\nEl dato ingresado no es numerico");
			retorno=-1;
			break;
		}
	}
	return retorno;

}


int PedirYValidarNumero(char numeros[], char mensaje[]){
	int retorno;
	char buffer[11];

	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		retorno=0;
	for(int i=0;i<strlen(buffer);i++){
		if(isdigit(buffer[i])==0){
			printf("El dato ingresado no es numerico.");
			retorno=-1;

			break;
		}



	}

	}while(retorno!=0);
	retorno=0;
	strcpy(numeros, buffer);

	return retorno;

}
