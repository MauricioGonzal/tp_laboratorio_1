/*
 * input.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Mauri
 */

#include "input.h"

int IngresarOpcion(){
	int opcion;
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);
	opcion= ValidarOpcion(opcion);
	return opcion;
}

int ValidarOpcion(int opcion){
	int numeroValidado;
	if(opcion<1 || opcion>5){
			printf("opcion incorrecta. Reingrese opcion");
			scanf("%d", &numeroValidado);
			numeroValidado= ValidarOpcion(numeroValidado);
		}
	else{
		numeroValidado= opcion;
	}
	return numeroValidado;

}

int IngresarPrimerOperando(float* primerOperando){
	int banderaPrimerOperando;
	float primerOp;
	banderaPrimerOperando=1;
	printf("ingrese el primer operando: ");
	scanf("%f", &primerOp);
	*primerOperando= primerOp;
	return banderaPrimerOperando;
}

int IngresarSegundoOperando(float* segundoOperando){
	int banderaSegundoOperando;
	float segundoOp;
	banderaSegundoOperando=1;
	printf("ingrese el segundo operando: ");
	scanf("%f", &segundoOp);
	*segundoOperando= segundoOp;
	return banderaSegundoOperando;
}
