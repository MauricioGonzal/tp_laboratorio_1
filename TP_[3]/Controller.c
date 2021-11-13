#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	retorno=-1;
	pFile= fopen(path, "r");
	if(pFile!=NULL && pArrayListEmployee!=NULL && path!=NULL)
	{
		retorno=1;
		parser_EmployeeFromText(pFile, pArrayListEmployee);
	}

	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
    FILE* pFile;
    FILE* pF;
    Employee empleadoAux;
    pF=fopen(path, "rb");
    if(fread(&empleadoAux, sizeof(Employee), 1, pF)!=1){
    	retorno=-1;
    }
    fclose(pF);

    if(retorno!=-1){
    pFile= fopen(path, "rb");
    if(pFile!=NULL){
    if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)!=0){
    	printf("no se pudo convertir");
    }
    fclose(pFile);
    }
    }


	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int maxId;
	int retorno;
	Employee* pEmpleado;
	FILE* pFile;
	FILE* pf;
	pFile= fopen("maxId.txt", "r");
	retorno= -1;


	if(pArrayListEmployee!=NULL)
	{
	retorno=1;

	pEmpleado= employee_new();
	if(pEmpleado!=NULL)
	{
	CrearEmpleado(pEmpleado);
	parser_maxIdFromText(pFile, &maxId);
	fclose(pFile);
	maxId= maxId+1;
	pEmpleado->id= maxId;
	pf= fopen("maxId.txt", "w");
	fprintf(pf, "%d", maxId);
	fclose(pf);

	ll_add(pArrayListEmployee, pEmpleado);
	retorno=0;
	}


	}

	return retorno;;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno=-1;
	if(pArrayListEmployee!=NULL){
	retorno= editEmployee(pArrayListEmployee);

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	char idStr[6];
	int idAux;
	int maxId;
	int len;
	int i;
	Employee* empleado;
	FILE* pFile;
	FILE* pf;
	retorno=-1;

	if(pArrayListEmployee!=NULL){
		retorno=1;
	pFile= fopen("maxId.txt", "r");

	parser_maxIdFromText(pFile, &maxId);
	fclose(pFile);


		len= ll_len(pArrayListEmployee);

		PedirYValidarNumero(idStr, "Ingrese el Id del empleado que quiere eliminar.", &idAux);
		empleado= buscarIdEmpleado(pArrayListEmployee, len, idAux, &i);
		if(empleado!=NULL)
		{


			retorno=0;
				ll_remove(pArrayListEmployee, i);
				employee_delete(empleado);
				if(idAux>maxId){
					maxId= idAux;
					pf= fopen("maxId.txt", "w");
					fprintf(pf, "%d", maxId);
					fclose(pf);
				}

			}

		return retorno;
	}





	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int len;
	int retorno;
	Employee* empleado;
	int id;
	char nombre[60];
	int sueldo;
	int horas;
	len= ll_len(pArrayListEmployee);
	retorno=-1;

	if(pArrayListEmployee!=NULL)
	{
	for(int i=0; i<len; i++)
	{
		empleado= ll_get(pArrayListEmployee, i);
		if(empleado!=NULL)
		{
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);
		printf("%d %s %d %d\n", id, nombre, horas, sueldo);
		retorno=0;
	}
	}
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int opcionDos;
	int retorno;
	retorno=-1;
	if(pArrayListEmployee!=NULL){
	elegirCriterioDeOrdenamiento(&opcion, &opcionDos);
	retorno=0;
	switch(opcion){
	case 1:
		ll_sort(pArrayListEmployee, employee_compareById, opcionDos);
		break;
	case 2:
		ll_sort(pArrayListEmployee, employee_compareByName, opcionDos);
		break;
	case 3:
		ll_sort(pArrayListEmployee, employee_compareBySalary, opcionDos);
		break;
	case 4:
		ll_sort(pArrayListEmployee, employee_compareByHours, opcionDos);
		break;

	}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile= fopen(path, "w");
		Employee* pEmpleado;
		int len= ll_len(pArrayListEmployee);
		if(pFile!=NULL){
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0; i<len; i++){
			pEmpleado= ll_get(pArrayListEmployee, i);
			if(pEmpleado!= NULL){

			fprintf(pFile, "%d, %s, %d, %d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);
			}
			else{
				printf("no se pudo");
			}
			}
		}
		else{
			printf("no");
		}

		fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile= fopen(path, "wb");
		Employee* pEmpleado;
		int len= ll_len(pArrayListEmployee);
		printf("%d", len);
		if(pFile!=NULL){

		for(int i=0; i<len; i++){
			pEmpleado= ll_get(pArrayListEmployee, i);
			if(pEmpleado!= NULL){
			fwrite(&pEmpleado->id, sizeof(int), 1, pFile);
			fwrite(&pEmpleado->nombre, sizeof(pEmpleado->nombre), 1, pFile);
			fwrite(&pEmpleado->horasTrabajadas, sizeof(int), 1, pFile);
			fwrite(&pEmpleado->sueldo, sizeof(int), 1, pFile);
			}
			else{
				printf("no se pudo");
			}
			}
		}
		else{
			printf("no");
		}

		len= ll_len(pArrayListEmployee);
		printf("%d", len);

		fclose(pFile);
    return 1;
}



