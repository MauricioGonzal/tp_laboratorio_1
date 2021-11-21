/*
 * input.c
 *
 *  Created on: 6 nov. 2021
 *      Author: Mauri
 */

#include "input.h"

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


	if(cadena!= NULL && longitud>0){
		retorno=1;
		fflush(stdin);
		do{
			printf("\n%s", mensaje);

		if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL && validarStringLetras(bufferString)==0){

			if(bufferString[strlen(bufferString)-1]== '\n'){
				bufferString[strlen(bufferString)-1]='\0';
			}
			if(strlen(bufferString)<= longitud){
				strcpy(cadena, bufferString);
				retorno=0;
			}
		}
			else{

				printf("%s", mensajeError);
			}
		}while(retorno!=0);

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

int validarStringLetras(char string[]){

    int retorno;
    retorno=0;


    for(int i=0;i<strlen(string); i++){
    	if(isdigit(string[i])){
    		retorno=-1;
    		break;
    	}
    }


    return retorno;
}

int SalirDelPrograma(){
	int opcion;
	PedirYValidarNumeroMejorado("seguro desea salir del programa?\n1.SI\n2.NO", &opcion, 1, 2);

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

void VerificarTresRetornos(int retorno, char mensajeCero[], char mensajeUno[], char mensajeError[]){

	if(retorno==0){
			printf("%s", mensajeCero);
		}
		else{
			if(retorno==1){
				printf("%s", mensajeUno);
			}
			else{
			printf("%s", mensajeError);
		}
		}
}



int ValidarNumero(char numeros[]){
	int retorno=0;
	for(int i=0;i<strlen(numeros);i++){

		if(!isdigit(numeros[i])){
			printf("\nEl dato ingresado no es numerico/entero.\n");
			retorno=-1;
			break;
		}
	}
	return retorno;

}

int validarRango(int numero, int minimo, int maximo){
	int retorno;
	retorno=0;

	if(numero>maximo || numero<minimo){
		printf("el numero esta fuera de rango");
		retorno=-1;
	}

	return retorno;
}

int PedirYValidarNumeroMejorado(char mensaje[], int* numeroConvertido, int min, int max){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumero(buffer)==0)
		{
			retorno=1;

			*numeroConvertido= atoi(buffer);
			if(validarRango(*numeroConvertido, min, max)==0){
				retorno=0;
			}

		}
	}while(retorno!=0);

	return retorno;

}

int PedirYValidarNumero(char mensaje[], int* numeroConvertido){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumero(buffer)==0)
		{
			retorno=1;

			*numeroConvertido= atoi(buffer);
			retorno=0;

		}
	}while(retorno!=0);

	return retorno;

}
