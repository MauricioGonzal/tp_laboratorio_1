/*
 ============================================================================
 Name        : TP_1.c
 Author      : Mauricio Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1 Enunciado
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funcione
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float primerOperando;
	float segundoOperando;
	int banderaPrimerOperando;
	int banderaSegundoOperando;

	do{
		printf("MENU\n");

		if(banderaPrimerOperando==1){
			printf("1. Ingresar primer operando: =%.2f\n", primerOperando);
		}
		else{
			printf("1. Ingresar primer operando:\n");
		}
		if(banderaSegundoOperando==1){
			printf("2. Ingresar segundo operando: =%.2f\n", segundoOperando);
		}
		else{
			printf("2. Ingresar segundo operando:\n");
		}
		printf("3. Calcular todas las operaciones:\n");
		printf("4. Informar los resultados:\n");
		printf("5. Salir\n");

		opcion= IngresarOpcion();

		switch(opcion){
		case 1:
			banderaPrimerOperando= IngresarPrimerOperando(&primerOperando);
			break;
		case 2:
			banderaSegundoOperando= IngresarSegundoOperando(&segundoOperando);
			break;
		}

	}while(opcion!=5);
	return EXIT_SUCCESS;
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









