/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Mauricio Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"
#define VACIO 1
#define CARGADO 0
#define TAM 10
#define SEGUNDOTAM 20


 int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int id;
	id=0;
	eEmployee empleados[TAM];
	initEmployees(empleados, TAM);


	do{
		printf("MENU DE OPCIONES");
		printf("1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.\n"
				"2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector"
				"\n3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema. \n4. INFORMAR: \n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector."
				"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n 5.SALIR");
		opcion= LoadIntRange("Ingrese una opcion", 5);
		switch(opcion){
		case 1:
			CargarEmpleado(&id, empleados, TAM);
			break;
		case 5:
			Imprimir(empleados, TAM);
			break;
		}
	}while(opcion!=5);




	return EXIT_SUCCESS;
}








