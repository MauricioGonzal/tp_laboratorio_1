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

int IngresarOperandos(float* operando, char* mensaje){
	int bandera;
	float op;
	bandera=1;
	printf("%s", mensaje);
	scanf("%f", &op);
	*operando= op;
	return bandera;
}



void SumarOperandos (float primerOp, float segundoOp, float* resultadoSuma){
	float suma;
	suma= primerOp+segundoOp;
	*resultadoSuma= suma;
}

void RestarOperandos(float primerOp, float segundoOp, float* resta){
	float resultadoResta;
	resultadoResta= primerOp-segundoOp;
	*resta= resultadoResta;
}

int DividirOperandos(float primerOp, float segundoOp, float* division){
	int banderaDivision;
	banderaDivision=0;
	float resultadoDivision;
	if(segundoOp!=0){
		resultadoDivision= primerOp/segundoOp;
		*division= resultadoDivision;
		banderaDivision=1;
	}

	return banderaDivision;
}

void MultiplicarOperandos( float primerOp, float segundoOp, float* multiplicacion){
	float resultadoMultiplicacion;
	resultadoMultiplicacion= primerOp*segundoOp;
	*multiplicacion= resultadoMultiplicacion;
}


int CalcularFactorial (float operador){
	int numero;
	int factorial;
	int op;
	op= (int)operador;
	factorial=1;
	if(op!=0 && op!=1){
	for(numero=op; numero>0; numero--){
		factorial= factorial*numero;


	}
	}

	return factorial;
}

void MostrarResultados (int banderaDivision, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, int factorialPrimerOperando, int factorialSegundoOperando, float primerOp, float segundoOp){
	printf("El resultado de %.2f + %.2f es: %.2f\n", primerOp, segundoOp, resultadoSuma);
	printf("El resultado de %.2f - %.2f es: %.2f\n", primerOp, segundoOp, resultadoResta);
	printf("El resultado de %.2f  %.2f es: %.2f\n", primerOp, segundoOp, resultadoDivision);
	if(banderaDivision!=1){
		printf("No se puede dividir por cero\n");
	}
	else{
		printf("El resultado de %.2f / %.2f es: %.2f\n", primerOp, segundoOp, resultadoDivision);
	}
	printf("El resultado de %.2f * %.2f es: %.2f\n", primerOp, segundoOp, resultadoMultiplicacion);
	printf("El factorial de %.2f es: %d\nEl factorial de %.2f es: %d\n", primerOp, factorialPrimerOperando, segundoOp, factorialSegundoOperando);

}

