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
	printf("%s", mensaje);

	if(cadena!= NULL && longitud>0){

		fflush(stdin);
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

int validarStringLetras(char string[]){

    int retorno;
    retorno=0;


    for(int i=0;i<strlen(string); i++){
    	if(isdigit(string[i])){
    		retorno=-1;
    		break;
    	}
    }
    printf("%d", retorno);

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



void Menu (){
	printf("MENU\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf(" 3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir");
}


int ValidarNumero(char numeros[]){
	int retorno=0;
	for(int i=0;i<strlen(numeros);i++){

		if(!isdigit(numeros[i])){
			printf("\nEl dato ingresado no es numerico.\n");
			retorno=-1;
			break;
		}
	}
	return retorno;

}


int PedirYValidarNumero(char numeros[], char mensaje[], int* numeroConvertido){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumero(buffer)==0)
		{
			strcpy(numeros, buffer);
			*numeroConvertido= atoi(numeros);
			retorno=0;
		}
	}while(retorno!=0);

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

int PedirYValidarNumeroMejorado(char mensaje[], int* numeroConvertido){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumero(buffer)==0)
		{

			*numeroConvertido= atoi(buffer);
			retorno=0;
		}
	}while(retorno!=0);

	return retorno;

}
