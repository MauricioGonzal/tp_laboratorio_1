#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[50];
	char nombre[50];
	char horas[50];
	char sueldo[50];
	Employee* pEmpleado;
	retorno=-1;



	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas,sueldo);
		retorno=1;


	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas,sueldo);
		pEmpleado= employee_newParametros(id, nombre, horas, sueldo);
		if(pEmpleado!=NULL)
		{
			retorno=0;
			ll_add(pArrayListEmployee, pEmpleado);
		}
	}
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleado;
	retorno=-1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
	retorno=1;
	while(!feof(pFile)){

			pEmpleado= employee_new();
			if(pEmpleado!=NULL){
				retorno=0;

				if(fread (pEmpleado, sizeof(Employee), 1, pFile)==1){
					ll_add(pArrayListEmployee, pEmpleado);
				}

			}
		}
	}

    return retorno;
}

int parser_maxIdFromText(FILE* pFile, int* id){

	int retornoScanf;
	int auxId;
	char auxIdStr[5];


	if(pFile!=NULL && id!=NULL)
	{
	retornoScanf=fscanf(pFile, "%s", auxIdStr);
	auxId= atoi(auxIdStr);
	*id= auxId;

	}
	return retornoScanf;

}



