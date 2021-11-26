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
#include "input.h"
#include "ArrayEmployees.h"
#define CARGADO 0
#define VACIO 1

 void Menu (){
	 printf("1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.\n2. MODIFICAR: Se ingresará el Número de Id, "
			 "permitiendo modificar: o Nombre o Apellido o Salario o Sector.\n3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema. \n4. INFORMAR: 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
			 "             2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n\n5.SALIR");
 }


 int initEmployees(Employee* list, int len){
	 int retorno;
	 retorno=-1;
	 if(list!=NULL && len>0){
		 retorno=0;
		 for(int i=0; i<len; i++){
			 list[i].isEmpty=VACIO;
		 }
	 }
	 return retorno;
 }


 int addEmployee(Employee* list, int len, int id, char name[],char
 lastName[],float salary,int sector){
	 int retorno;
	 retorno=-1;
	 if(list!=NULL && len>0){
		 for(int i=0;i<len;i++){
			 if(list[i].isEmpty==VACIO){
				 list[i].id= id;
				 strcpy(list[i].lastName, lastName);
				 strcpy(list[i].name, name);
				 list[i].salary= salary;
				 list[i].sector= sector;
				 list[i].isEmpty= CARGADO;
				 retorno=0;
				 break;
			 }
		 }
	 }

	 return retorno;
 }


 int createEmployee(Employee list[], int len, int* id){
 	int retorno;
 	char name[51];
 	char lastName[51];
 	int sector;
 	int auxId;
 	float salary;
 	retorno=-1;
 	if(list!=NULL && len>0)
 	{

 	if(getString(name, "Ingrese el nombre", "error", sizeof(name), 5)==0 && getString(lastName, "Ingrese el apellido", "ERROR", sizeof(lastName), 5)==0 &&
  	PedirYValidarNumeroFlotante("Ingrese el salario", &salary, 5)==0 && PedirYValidarNumero("Ingrese el sector", &sector,5)==0
	){
 	 	auxId= *id;
 	 	auxId++;

 		if(addEmployee(list, len, auxId, name, lastName, salary, sector)==0){
 			*id=auxId;
 			retorno=0;
 		}


 	}

 	}

 	return retorno;

 }


 int printEmployees(Employee* list, int length){
	 int retorno;
	 retorno=-1;
	 if(list!=NULL && length>0){
		 retorno=1;
    	printf("ID,APELLIDO,NOMBRE,SALARIO,SECTOR\n\n");
		 for(int i=0; i<length; i++){
		 if(list[i].isEmpty==CARGADO){
			 printOneEmployee(list[i]);
			 retorno=0;
		 }
		 }
	 }

	 if(retorno!=0){
		 printf("No hay empleados activos");
	 }
	 return retorno;
 }


void printOneEmployee(Employee employee){
	printf("%-5d %-10s %-10s %-10.2f %-10d\n", employee.id, employee.lastName, employee.name, employee.salary, employee.sector);
}


int findEmployeeById(Employee* list, int len,int id){
	 int i;
	 int retorno;
	 retorno=-1;
	 if(list!=NULL && len>0){
		 for(i=0; i<len; i++){
			 if(list[i].isEmpty==CARGADO && list[i].id==id){
				 retorno=i;

				 break;
			 }
		 }
	 }
	 return retorno;
}


int modificarEmployee(Employee list[], int len){
	int retorno;
	int opcion;
	int id;
	int i;
	float salary;
	retorno=-1;


	if(list!=NULL && len>0){
		PedirYValidarNumero("Ingrese el id del empleado a modificar", &id, 5 );
		i=findEmployeeById(list, len, id);
		retorno=1;
		if(i!=-1){
			retorno=0;;

		PedirYValidarNumeroMejorado("Ingrese que campo quiere modificar.\n1.NOMBRE\n2.APELLIDO.\n3.SALARIO.\n4.SECTOR\n", &opcion, 1, 4, 5);
		switch(opcion){
		case 1:
			getString(list[i].name, "Ingrese el nombre", "ERROR", sizeof(list[i].name),5);
			break;
		case 2:
			getString(list[i].lastName, "Ingrese el nuevo apellido", "ERROR", sizeof(list[i].lastName), 5);
			break;
		case 3:
			PedirYValidarNumeroFlotante("Ingrese el nuevo salario", &salary, 5);
			list[i].salary= salary;
			break;
		default:
			PedirYValidarNumero("Ingrese el nuevo sector", &list[i].sector, 5);
			break;
		}
		}
	}
	return retorno;
}


int removeEmployee(Employee* list, int len, int id){
	 int retorno;
	 int auxRetorno;
	 retorno=-1;
	 if(list!=NULL && len>0){
		 auxRetorno= findEmployeeById(list, len, id);
		 if(auxRetorno!=-1){
			 list[auxRetorno].isEmpty=VACIO;
			 retorno=0;
		 }
	 }

	 return retorno;
}


int informesSalary(Employee list[], int len, float* total, float* promedio){
	int retorno;
	int cantidadEmpleados;
	float auxTotal;
	float auxPromedio;
	auxTotal=0;
	cantidadEmpleados=0;
	retorno=-1;
	if(list!=NULL && len>0 ){
		retorno=0;
		for(int i=0; i<len; i++){
			if(list[i].isEmpty==CARGADO){
				auxTotal= auxTotal+ list[i].salary;
				cantidadEmpleados++;

			}
		}
		auxPromedio= auxTotal/cantidadEmpleados;
		*total= auxTotal;


		for(int i=0;i<len;i++){
			if(list[i].isEmpty==CARGADO && list[i].salary>auxPromedio){
				retorno++;
			}
		}

		*promedio= auxPromedio;
	}

	return retorno;
}


int sortEmployees(Employee* list, int len, int order){
	 int retorno;
	 int opcion;
	 Employee buffer;

	 retorno=-1;
	 PedirYValidarNumeroMejorado("Ingrese que campo quiere ordenar:\n1.NOMBRE\n2.SECTOR", &opcion, 1, 2, 5);

	 if(list!=NULL && len>0){
		 retorno=0;
		 if(opcion==1){
	 for(int i=0;i<len-1;i++)
	 {	if(list[i].isEmpty==CARGADO){
		 for(int j=i+1; j<len; j++)
		 {
			 if(order==1){
			if(strcmp(list[i].lastName, list[j].lastName)>0)
			{
				buffer= list[i];
				list[i]= list[j];
				list[j]=buffer;
			}
			 }
			 else{
				 if(strcmp(list[i].lastName, list[j].lastName)<0)
				 			{
				 				buffer= list[i];
				 				list[i]= list[j];
				 				list[j]=buffer;
				 			}
			 }
		 }
	 }
	 }
	 }
		 else{
			 for(int i=0;i<len-1;i++)
			 {	if(list[i].isEmpty==CARGADO){
				 for(int j=i+1; j<len; j++)
				 {
					 if(order==1){
					if(list[i].sector>list[j].sector)
					{
						buffer= list[i];
						list[i]= list[j];
						list[j]=buffer;
					}
					 }
					 else{
						 if(list[i].sector<list[j].sector)
						 			{
						 				buffer= list[i];
						 				list[i]= list[j];
						 				list[j]=buffer;
						 			}
					 }
				 }
			 }
			 }
		 }
	 }
	 return retorno;
}
