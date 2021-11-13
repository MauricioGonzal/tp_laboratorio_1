
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new(){


	Employee* empleado= NULL;
	empleado= (Employee*) malloc(sizeof(Employee));
	if(empleado!=NULL){

	employee_setId(empleado, 0);
	employee_setNombre(empleado, "");
	employee_setHorasTrabajadas(empleado, 0);
	employee_setSueldo(empleado, 0);
	}

	return empleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){
	Employee* pEmpleado= NULL;
	pEmpleado= employee_new();
	if(pEmpleado!=NULL){
		pEmpleado->id= atoi(idStr);
		strncpy(pEmpleado->nombre, nombreStr, sizeof(pEmpleado->nombre));
		pEmpleado->horasTrabajadas= atoi(horasTrabajadasStr);
		pEmpleado->sueldo= atoi(sueldo);
	}
	return pEmpleado;
}


int employee_delete(Employee* this){


	int retorno;
	retorno=-1;
	if(this!=NULL){
		free(this);
		retorno=0;
	}
	return retorno;

}



int employee_setId(Employee* this,int id){
	int retorno;
	retorno=-1;
	if(this!=NULL){
	this->id= id;
	retorno=0;
	}

	return retorno;

}


int employee_getId(Employee* this,int* id){
	int retorno;
	retorno=-1;
	if(this!=NULL && id!=NULL){
	*id= this->id;
	retorno=0;
	}

	return retorno;


}


int employee_setNombre(Employee* this,char* nombre){
	int retorno;
		retorno=-1;
		if(this!=NULL){
		strcpy(this->nombre, nombre);
		retorno=0;
		}

		return retorno;
}


int employee_getNombre(Employee* this,char* nombre){
	int retorno;
		retorno=-1;
		if(this!=NULL && nombre!=NULL){
		strcpy(nombre, this->nombre);
		retorno=0;
		}

		return retorno;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno;
			retorno=-1;
			if(this!=NULL){
			this->horasTrabajadas= horasTrabajadas;
			retorno=0;
			}

			return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno;
		retorno=-1;
		if(this!=NULL && horasTrabajadas!=NULL){
		*horasTrabajadas= this->horasTrabajadas;
		retorno=0;
		}

		return retorno;
}


int employee_setSueldo(Employee* this,int sueldo){
	int retorno;
				retorno=-1;
				if(this!=NULL){
				this->sueldo= sueldo;
				retorno=0;
				}

				return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
	int retorno;
			retorno=-1;
			if(this!=NULL && sueldo!=NULL){
			*sueldo= this->sueldo;
			retorno=0;
			}

			return retorno;
}


int CrearEmpleado(Employee* pEmpleado){
	int retorno;
	char auxNombre[50];
	int sueldo;
	int horas;
	retorno= -1;




		if(pEmpleado!= NULL){
		retorno=1;
		if(getString(auxNombre, "Ingrese el nombre del nuevo empleado.", "Error. Dato incorrecto", sizeof(auxNombre))==0)
		{
			retorno=0;
			employee_setNombre(pEmpleado, auxNombre);

			PedirYValidarNumero("Ingrese el sueldo:\n", &sueldo);
			pEmpleado->sueldo= sueldo;

			PedirYValidarNumero("Ingrese las horas trabajadas", &horas);


			pEmpleado->horasTrabajadas= horas;
			retorno=0;
		}






		}

	return retorno;
}



int editEmployee(LinkedList* pArrayListEmployee){
	int retorno;
		int idAux;
		int sueldoInt;
		int horasInt;
		int len;
		int i;
		char nombre[15];
		retorno= -1;
		len= ll_len(pArrayListEmployee);
		Employee* empleado;

		if(pArrayListEmployee!=NULL)
		{
		retorno=1;
		PedirYValidarNumero("ingrese el id del empleado que desea modificar", &idAux);
		empleado= buscarIdEmpleado(pArrayListEmployee, len, idAux, &i);
			if(empleado!=NULL){
				retorno=0;
				empleado= (Employee*)ll_get(pArrayListEmployee, i);
				employee_getNombre(empleado, nombre);
				printf("El empleado a editar es: %s\n", nombre );
				PedirYValidarNumero("ingrese el nuevo sueldo", &sueldoInt);

				employee_setSueldo(empleado, sueldoInt);
				PedirYValidarNumero("ingrese las nuevas horas trabajadas", &horasInt);

				employee_setHorasTrabajadas(empleado, horasInt);

			}
		}

		return retorno;
}


int employee_compareByName(void* e1, void* e2){
	int retorno;
	retorno=0;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	if(e1!= NULL && e2!=NULL){
	unEmpleado= (Employee*) e1;
	otroEmpleado = (Employee*)e2;
	if(strcmp(unEmpleado->nombre, otroEmpleado->nombre)<0)
	{
		retorno=-1;
	}
	else{
		if(strcmp(unEmpleado->nombre, otroEmpleado->nombre)>0)
		{
			retorno=1;
		}
	}
	}



	return retorno;



}

int employee_compareById(void* e1, void* e2){
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	retorno=0;
	unEmpleado= (Employee*) e1;
	otroEmpleado = (Employee*)e2;
	if(unEmpleado->id<otroEmpleado->id){
		retorno=-1;
	}
	else{
		if(unEmpleado->id>otroEmpleado->id){
			retorno=1;
		}
	}
	return retorno;

}

int employee_compareBySalary(void* e1, void* e2){
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	retorno=0;
	unEmpleado= (Employee*) e1;
	otroEmpleado = (Employee*)e2;
	if(unEmpleado->sueldo<otroEmpleado->sueldo){
		retorno=-1;
	}
	else{
		if(unEmpleado->sueldo>otroEmpleado->sueldo){
			retorno=1;
		}
	}
	return retorno;

}

int employee_compareByHours(void* e1, void* e2){
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;
	retorno=0;
	unEmpleado= (Employee*) e1;
	otroEmpleado = (Employee*)e2;
	if(unEmpleado->horasTrabajadas<otroEmpleado->horasTrabajadas){
		retorno=-1;
	}
	else{
		if(unEmpleado->horasTrabajadas>otroEmpleado->horasTrabajadas){
			retorno=1;
		}
	}
	return retorno;

}

int elegirCriterioDeOrdenamiento(int* opcion, int* opcionDos){
	int retorno;
	int auxOpcion;
	int auxOpcionDos;
	retorno=-1;
	if(opcion!=NULL &&  opcionDos!=NULL)
	{
		retorno=0;
	PedirYValidarNumeroMejorado("Elija el criterio de ordenamiento.\n1.Por Id.\n2.Por nombre.\n3.Por sueldo.\n4.por horas trabajadas", &auxOpcion, 1, 4);
	PedirYValidarNumeroMejorado("Elija 0 para ordenar de forma descendente o 1 de forma ascendente",  &auxOpcionDos, 1, 2);



		*opcion= auxOpcion;
		*opcionDos= auxOpcionDos;
	}
	return retorno;
}


Employee* buscarIdEmpleado(LinkedList* pArrayListEmployee, int len, int id, int* auxI){
	Employee* empleado;
	int auxId;
	int encontro;
	encontro=-1;
	for(int i=0; i<len; i++){
		empleado= (Employee*)ll_get(pArrayListEmployee, i);
		if(empleado!=NULL && employee_getId(empleado, &auxId)==0 && auxId==id)
		{
			*auxI= i;
			encontro=0;
			break;
		}
	}

	if(encontro!=0)
	{
		empleado= NULL;
	}

	return empleado;
}


int guardarArchivo(LinkedList* lista, FILE* pFile, int indicacion, int len){
	Employee* pEmpleado;
	int retorno;
	retorno=-1;
	if(lista!=NULL && pFile!=NULL)
	{
		retorno=1;

	if(indicacion==0){
		for(int i=0; i<len; i++){
					pEmpleado= ll_get(lista, i);
					if(pEmpleado!= NULL){
					fwrite(&pEmpleado->id, sizeof(int), 1, pFile);
					fwrite(&pEmpleado->nombre, sizeof(pEmpleado->nombre), 1, pFile);
					fwrite(&pEmpleado->horasTrabajadas, sizeof(int), 1, pFile);
					fwrite(&pEmpleado->sueldo, sizeof(int), 1, pFile);
					retorno=0;
					}


				}
	}
	else{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
				for(int i=0; i<len; i++){
					pEmpleado= ll_get(lista, i);
					if(pEmpleado!= NULL){
						retorno=0;
					fprintf(pFile, "%d, %s, %d, %d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);

					}
				}

	}


	}

	return retorno;

}

void employee_listarUnEmpleado(Employee* empleado){

	int id;
	int horas;
	char nombre[51];
	int sueldo;

			employee_getId(empleado, &id);
			employee_getNombre(empleado, nombre);
			employee_getHorasTrabajadas(empleado, &horas);
			employee_getSueldo(empleado, &sueldo);
			printf("%d %s %d %d\n", id, nombre, horas, sueldo);





}

int employee_listarEmpleados(LinkedList* lista, int len){
	int retorno;
	Employee* empleado;
	retorno=-1;
	if(lista!=NULL)
	{
	for(int i=0; i<len; i++)
		{	retorno=1;
			empleado= ll_get(lista, i);
			if(empleado!=NULL){
				retorno= 0;
				employee_listarUnEmpleado(empleado);
			}

		}
	}

	return retorno;
}
