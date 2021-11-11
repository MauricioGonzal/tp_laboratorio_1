/*
 * input.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Mauri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int LoadIntRange(char message[], int num){
    int option;
    printf("%s", message);
    scanf("%d", &option);
    while(option <0 || option > num){
        printf("\nERROR.%s", message);
        scanf("%d", &option);
        }
    return option;
}

int LoadInt(char message[]){
    int option;
    printf("%s", message);
    scanf("%d", &option);

    return option;
}

void LoadString(char message[], char loadedString[]){
    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", loadedString);
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

int esNumerica(char* cadena, int limite){
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0){
		retorno=1;
		for(i=0; i<limite && cadena[i]!='\0'; i++){
				if(i==0 && (cadena[i]=='-' || cadena[i]=='-')){
					continue;
					}

				if(cadena[i]>'9' || cadena[i]<'0'){
					retorno=0;
					break;
				}
			}
	}
	return retorno;
}

/*int getInt(int* pResultado){

	int retorno=-1;
	char buffer[4096];
	fflush(stdin);
	scanf("%s", buffer);

	if(pResultado!=NULL && getString(buffer, sizeof(buffer))==0 && esNumerica(buffer, sizeof(buffer))){
		retorno=0;
		*pResultado= atoi(buffer);
	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
		printf("%s", mensaje);

		if(getInt(&buffer)==0 && buffer>=minimo && buffer <= maximo){
			*pResultado= buffer;
			retorno=0;
			break;
		}
		else{
			printf("%s", mensajeError);
			reintentos--;
		}
	}while(reintentos>=0);
	}

	return retorno;
}

int esLetra(char* cadena, int limite){
	int retorno=-1;
	char bufferString[4096];
	int i;
	if(cadena!=NULL && limite>0 && getString(bufferString, limite)==0){
		retorno=1;
		for(i=0; i<limite && cadena[i]!='\0'; i++){


				if((cadena[i]>90 && cadena[i]<97) || cadena[i]<65 || cadena[i]>122 ){
					retorno=0;
					break;
				}
			}
	}

	return retorno;
}

int utn_getDatoPalabra(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int longitud){
	char bufferString[4096];
	int retorno=-1;
	if(pResultado != NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0){

		do{
		printf("%s", mensaje);

		if(esLetra(&bufferString, longitud)==0){
			*pResultado= bufferString;
			retorno=0;
			break;
		}
		else{
			printf("%s", mensajeError);
			reintentos--;
		}
	}while(reintentos>=0);
	}

	return retorno;
}

void AlertMessage(int num, char messageA[], char messageB[]){
    char enter;
    if(num==0){
        printf("%s\n",messageA);
    } else{
        printf("%s\n",messageB);
    }
    printf("presione cualquier tecla para continuar.");
    __fpurge(stdin);
    scanf("%c", &enter);

    printf("\n\n");

}*/
