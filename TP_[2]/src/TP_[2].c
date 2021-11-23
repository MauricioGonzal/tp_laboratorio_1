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
#define SINCARGAR "Para realizar esta accion se debe cargar al menos un empleado en el sistema\n"



 int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int auxId;
	int retorno;
	int id=0;
	int auxOpcion;
	int bandera;
	float promedio;
	float total;
	int cantidadEmpleadosSalarioAlto;
	int orden;
	int opcionSalida;

	Employee lista[TAMLISTA];
	bandera=0;
	initEmployees(lista, TAMLISTA);
	do{
		Menu();
		PedirYValidarNumero("\nIngrese una opcion\n", &opcion);
		switch(opcion){
		case 1:
			createEmployee(lista, TAMLISTA, &id);

			bandera=1;
			break;

		case 2:
			if(bandera==1){
			printEmployees(lista, TAMLISTA);
			PedirYValidarNumero("Ingrese el id del empleado a modificar", &auxId );
			retorno= findEmployeeById(lista, TAMLISTA, auxId);
			if(retorno!=-1){
				modificarEmployee(lista, TAMLISTA, retorno);
			}
			else{
				printf("No existe empleado con el id ingresado\n");
			}
			}else{
				printf(SINCARGAR);
			}
			break;
		case 3:
			if(bandera==1){
			printEmployees(lista, TAMLISTA);
			PedirYValidarNumero("Ingrese el id del empleado a eliminar", &auxId);
			if(findEmployeeById(lista, TAMLISTA, auxId)!=-1){
			removeEmployee(lista, TAMLISTA, auxId);
			}
			else{
				printf("No existe empleado con el id ingresado\n");
			}
			}else{
				printf(SINCARGAR);
			}
			break;
		case 4:
			if(bandera==1){
			PedirYValidarNumeroMejorado("\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector..\n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.", &auxOpcion,1,2);
			switch(auxOpcion){
			case 1:
				PedirYValidarNumeroMejorado("Ingrese como quiere ordenar los empleados: \n0.DESCENDENTE\n1.ASCENDENTE\n", &orden, 0, 1);

				if(orden==0){
					sortEmployees(lista, TAMLISTA, 0);
				}
				else{
					sortEmployees(lista, TAMLISTA, 1);
				}
				printEmployees(lista, TAMLISTA);



				break;
			case 2:
				cantidadEmpleadosSalarioAlto= informesSalary(lista, TAMLISTA, &total, &promedio);
				printf("Total salarios:%.2f\nPromedio salarios:%.2f\nCantidad de empleados que superan el salario promedio:%d\n", total, promedio, cantidadEmpleadosSalarioAlto);
				break;
			}
			}
			else{
							printf(SINCARGAR);
						}
			break;
		case 5:
			opcionSalida= SalirDelPrograma();
			break;

		}



	}while(opcionSalida!=1);




	return EXIT_SUCCESS;
}














