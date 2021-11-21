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
#define TAMLISTA 1000



 int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int auxId;
	int retorno;
	int id=0;
	int auxOpcion;
	float promedio;
	float total;
	int cantidadEmpleadosSalarioAlto;
	Employee lista[TAMLISTA];
	initEmployees(lista, TAMLISTA);
	do{
		Menu();
		PedirYValidarNumero("\nIngrese una opcion", &opcion);
		switch(opcion){
		case 1:
			createEmployee(lista, TAMLISTA, &id);
			break;
		case 2:
			printEmployees(lista, TAMLISTA);
			PedirYValidarNumero("Ingrese el id del empleado a modificar", &auxId );
			retorno= findEmployeeById(lista, TAMLISTA, auxId);
			if(retorno!=-1){
				modificarEmployee(lista, TAMLISTA, retorno);
			}
			else{
				printf("No existe empleado con el id ingresado");
			}
			break;
		case 3:
			printEmployees(lista, TAMLISTA);
			PedirYValidarNumero("Ingrese el id del empleado a eliminar", &auxId);
			removeEmployee(lista, TAMLISTA, auxId);
			break;
		case 4:
			PedirYValidarNumero("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector..\n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.", &auxOpcion);
			switch(auxOpcion){
			case 1:

				break;
			case 2:
				cantidadEmpleadosSalarioAlto= informesSalary(lista, TAMLISTA, &total, &promedio);
				printf("Total salarios:%f\nPromedio salarios:%f\nCantidad de empleados que superan el salario promedio:%d\n", total, promedio, cantidadEmpleadosSalarioAlto);
				break;
			}
			break;
		}
	}while(opcion!=5);




	return EXIT_SUCCESS;
}












