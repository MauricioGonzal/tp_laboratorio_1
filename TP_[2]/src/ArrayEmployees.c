/*
 * input.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Mauri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define CARGADO 0
#define VACIO 1

int initEmployees(eEmployee* empleados, int len)
{
	int retorno=-1;
	if(empleados!=NULL && len>0){
	retorno=0;
	for(int i=0; i<len; i++){
		empleados[i].isEmpty=VACIO;
	}
	}


 return retorno;
}



int addEmployee(eEmployee empleados[], int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno;
	retorno=-1;
	for(int i=0; i<len; i++){
		if(empleados[i].isEmpty==VACIO){
			empleados[i].id= id;
			strcpy(empleados[i].name, name);
			strcpy(empleados[i].lastName, lastName);
			empleados[i].salary= salary;
			empleados[i].sector= sector;
			empleados[i].isEmpty= CARGADO;
			retorno=0;
			break;
		}

	}
 return retorno;
}


void CargarEmpleado (int* id, eEmployee empleados[], int tam){
	char name[51];
		 char lastName[51];
		 float salary;
		 int sector;
		 int auxId;
		 auxId=0;

	LoadString("ingrese el nombre: ", name);
	LoadString("\ningrese el apellido:", lastName);
	salary= LoadFloat("\nIngrese el salario:");
	sector= LoadInt("\ningrese el sector:");
	auxId= auxId+1;
	*id= auxId;
	addEmployee(empleados, tam, auxId, name, lastName, salary, sector);

}

void Imprimir (eEmployee lista[], int tam){
	for(int i=0;i<tam; i++){
		if(lista[i].isEmpty==0){
			ImprimirUno(lista[i]);
			break;
		}
	}
}


void ImprimirUno(eEmployee lista){
	printf("%4d %15s %15s  %6.2f \n", lista.id, lista.lastName, lista.name, lista.salary);
}
