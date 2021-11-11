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
	//llama a parsertext
	FILE* pFile;

	pFile= fopen(path, "r");
	if(pFile!=NULL && pArrayListEmployee!=NULL && path!=NULL){

		parser_EmployeeFromText(pFile, pArrayListEmployee);

	}
	fclose(pFile);


	return 1;
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

	Employee* pEmpleado;
	FILE* pFile;
	FILE* pf;
	pFile= fopen("maxId.txt", "r");
	int maxId;
	int len;
	len= ll_len(pArrayListEmployee);
	printf("%d", len);
	if(pArrayListEmployee!=NULL){




	if(pArrayListEmployee!=NULL){
	pEmpleado= employee_new();
	CrearEmpleado(pEmpleado);
	parser_maxIdFromText(pFile, &maxId);
	fclose(pFile);
	maxId= maxId+1;
	pEmpleado->id= maxId;
	pf= fopen("maxId.txt", "w");
	fprintf(pf, "%d", maxId);
	fclose(pf);

	ll_add(pArrayListEmployee, pEmpleado);
	}
	}
	else{
		printf("no");
	}

	len= ll_len(pArrayListEmployee);
	printf("%d", len);

	return 1;
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
	int idAux;
	char sueldo[10];
	char horasTrabajadas[5];
	int sueldoInt;
	int horasInt;
	int len;
	len= ll_len(pArrayListEmployee);
	Employee* empleado;
	idAux= LoadInt("ingrese el id del empleado que desea modificar");
	for(int i=0; i<len; i++){
		empleado= (Employee*)ll_get(pArrayListEmployee, i);
		if(empleado!=NULL && idAux== empleado->id ){
			PedirYValidarNumero(sueldo, "ingrese el nuevo sueldo");
			sueldoInt= atoi(sueldo);
			employee_setSueldo(empleado, sueldoInt);
			PedirYValidarNumero(horasTrabajadas,"ingrese las nuevas horas trabajadas");
			horasInt= atoi(horasTrabajadas);
			employee_setHorasTrabajadas(empleado, horasInt);
			break;
		}
	}


    return 1;
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
	int idAux;
	int maxId;
	FILE* pFile;
	FILE* pf;
	pFile= fopen("maxId.txt", "r");
	parser_maxIdFromText(pFile, &maxId);
	fclose(pFile);

		int len;
		len= ll_len(pArrayListEmployee);
		Employee* empleado;
		idAux= LoadInt("ingrese el id del empleado que desea eliminar");
		for(int i=0; i<len; i++){
			empleado= (Employee*)ll_get(pArrayListEmployee, i);
			if(empleado!=NULL && idAux== empleado->id ){
				ll_remove(pArrayListEmployee, i);
				if(empleado->id>maxId){
					maxId= empleado->id;
					pf= fopen("maxId.txt", "w");
					fprintf(pf, "%d", maxId);
					fclose(pf);
				}
				break;
			}
		}





	return 1;
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
	Employee* empleado;
	int id;
	char nombre[60];
	int sueldo;
	int horas;
	len= ll_len(pArrayListEmployee);
	printf("%d", len);
	if(pArrayListEmployee!=NULL){
	for(int i=0; i<len; i++){
		empleado= ll_get(pArrayListEmployee, i);
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);
		printf("%d %s %d %d\n", id, nombre, horas, sueldo);
	}
	}

    return 1;
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
    return 1;
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

