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
	opcion= ValidarOpcion(opcion, 1, 5);
	return opcion;
}

int ValidarOpcion(int opcion, int min, int max){
	int numeroValidado;
	if(opcion<min || opcion>max){
			printf("Opcion incorrecta. Reingrese una opcion entre %d y %d: ", min, max);
			scanf("%d", &numeroValidado);
			numeroValidado= ValidarOpcion(numeroValidado, 1, 5);
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


int CalcularFactorial (float operador, unsigned long* factorialOperando){
	int numero;
	unsigned long factorial;
	int op;
	int banderaFactorialPermitido;
	op= operador;

	if(operador-op || op<0){
		banderaFactorialPermitido=1;
	}
	else{
		banderaFactorialPermitido=0;
		factorial=1;
		*factorialOperando= factorial;
			if(op!=0 && op!=1 && op>0){
			for(numero=op; numero>0; numero--){
				factorial= factorial*numero;


			}
			*factorialOperando= factorial;
			}


	}

	return banderaFactorialPermitido;
}

void MostrarResultadosFlotantes(char* mensaje, char signo, float resultado, float primerOp, float segundoOp){
	printf("%s %.2f %c %.2f es %.3f\n", mensaje, primerOp, signo, segundoOp, resultado);

}

void MostrarResultadosEnteros(char* mensaje, unsigned long resultado, float operando){
	int op;
	op=operando;
	printf("%s %d es %lu\n", mensaje, op, resultado);
}

int SalirDelPrograma (){
	int opcionSalir;
	printf("Seguro que desea salir?\nIngrese el numero de opcion que corresponda:\n1. Si, estoy seguro.\n2. No, quiero seguir operando.\n");
	scanf("%d", &opcionSalir);
	return opcionSalir;
}

