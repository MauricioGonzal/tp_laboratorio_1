/*
 ============================================================================
 Name        : TP_1.c
 Author      : Mauricio Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"



int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionSalida;
	float primerOperando;
	float segundoOperando;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaDivision;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	int factorialPrimerOperando;
	int factorialSegundoOperando;
	opcionSalida=0;

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
			banderaPrimerOperando= IngresarOperandos(&primerOperando, "Ingrese primer operando: ");
			break;
		case 2:
			banderaSegundoOperando= IngresarOperandos(&segundoOperando, "Ingrese segundo operando: ");
			break;
		case 3:
			if(banderaPrimerOperando==1 && banderaSegundoOperando==1){
			SumarOperandos(primerOperando, segundoOperando, &resultadoSuma);
			RestarOperandos(primerOperando, segundoOperando, &resultadoResta);
			banderaDivision= DividirOperandos(primerOperando, segundoOperando, &resultadoDivision);

			MultiplicarOperandos(primerOperando, segundoOperando, &resultadoMultiplicacion);
			factorialPrimerOperando= CalcularFactorial(primerOperando);
			factorialSegundoOperando= CalcularFactorial(segundoOperando);
			}
				else{
				printf("Para calcular las operaciones se deben ingresar ambos operandos. Ingrese operando/s nuevamente.\n");
			}

			break;
		case 4:
			if(banderaPrimerOperando==1 && banderaSegundoOperando==1){
			MostrarResultados(banderaDivision, resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion, factorialPrimerOperando, factorialSegundoOperando, primerOperando, segundoOperando);
			}
			else{
				printf("Error. No se pueden mostrar operaciones. Ingrese todos los operandos.\n");
			}
			break;
		case 5:
			printf("Seguro que desea salir?\nIngrese el numero de opcion que corresponda\n1. Si, estoy seguro.\n2. No, quiero seguir operando\n");
			scanf("%d", &opcionSalida);
			break;



		}
	}while(opcionSalida!=1);

	printf("Gracias por utilizar nuestros servicios");

	return EXIT_SUCCESS;
}











