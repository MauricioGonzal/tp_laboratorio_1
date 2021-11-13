
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new(){


	Employee* empleado= NULL;
	empleado= (Employee*) malloc(sizeof(Employee));
	if(empleado!=NULL){

	employee_setId(empleado, 0);
	strcpy(empleado->nombre, "");
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
	char auxSueldo[10];
	int sueldo;
	char auxHoras[4];
	int horas;
	retorno= -1;




		if(pEmpleado!= NULL){
		retorno=1;
		if(getString(auxNombre, "Ingrese el nombre del nuevo empleado.", "Error. Dato incorrecto", sizeof(auxNombre))==0)
		{

			employee_setNombre(pEmpleado, auxNombre);

			PedirYValidarNumero(auxSueldo, "Ingrese el nuevo sueldo", &sueldo);


			PedirYValidarNumero(auxHoras, "Ingrese las horas trabajadas", &horas);
			pEmpleado->sueldo= sueldo;

			pEmpleado->horasTrabajadas= horas;
			retorno=0;
		}






		}

	return retorno;
}


int BuscarMayorId(LinkedList* pArrayEmpleados, int* id ){

	int retorno;
	int auxId;
	retorno=-1;
		Employee* empleado;
		int len;
		int mayorId;
		len= ll_len(pArrayEmpleados);
		if(pArrayEmpleados!=NULL && id!=NULL){
			retorno=0;
			if(len==0){
				*id=1000;
			}
			else{
		for(int i=0; i<len; i++){
			empleado= (Employee*)ll_get(pArrayEmpleados, i);
			if(i==0){
				employee_getId(empleado, &auxId);
				mayorId= auxId;
			}
			else{
				if(mayorId<empleado->id){
					employee_getId(empleado, &auxId);
					mayorId= auxId;
				}
			}
		}
		*id= mayorId;
		}


		}

		return retorno;

}

int AsignarId (LinkedList* pArrayEmpleados)
{
	int retorno;
	int id;
	if(pArrayEmpleados!=NULL)
	{
		BuscarMayorId(pArrayEmpleados, &id);
		id++;
	}

	return id;
}

int editEmployee(LinkedList* pArrayListEmployee){
	int retorno;
		int idAux;
		char idStr[5];
		char sueldo[10];
		char horasTrabajadas[5];
		int sueldoInt;
		int horasInt;
		int len;
		int i;
		char nombre[15];
		retorno= -1;
		len= ll_len(pArrayListEmployee);
		Employee* empleado;
		PedirYValidarNumero(idStr, "ingrese el id del empleado que desea modificar", &idAux);
		empleado= buscarIdEmpleado(pArrayListEmployee, len, idAux, &i);
			if(empleado!=NULL){
				retorno=0;
				empleado= (Employee*)ll_get(pArrayListEmployee, i);
				employee_getNombre(empleado, nombre);
				printf("El empleado a editar es: %s", nombre );
				PedirYValidarNumero(sueldo, "ingrese el nuevo sueldo", &sueldoInt);

				employee_setSueldo(empleado, sueldoInt);
				PedirYValidarNumero(horasTrabajadas,"ingrese las nuevas horas trabajadas", &horasInt);

				employee_setHorasTrabajadas(empleado, horasInt);
				retorno=0;
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
	int retornoDos;
	int auxOpcion;
	int auxOpcionDos;
	retorno=0;
	retornoDos=0;
	char numeros[2];

		do{
			PedirYValidarNumero(numeros, "Eliga el criterio de ordenamiento.\n1.Por Id.\n2.Por nombre.\n3.Por sueldo.\n4.por horas trabajadas", &auxOpcion);

		if(validarRango(auxOpcion, 1, 4)!=0){
			retorno=-1;
		}

		}while(retorno!=0);

		do{
			PedirYValidarNumero(numeros, "Elija 0 para ordenar de forma descendente o 1 de forma ascendente", &auxOpcionDos);
					if(validarRango(auxOpcionDos, 0, 1)!=0){
						retornoDos=-1;
					}
		}while(retornoDos!=0);

		*opcion= auxOpcion;
		*opcionDos= auxOpcionDos;
	return retorno;
}

int buscarId(Employee* this, int id){
	int retorno;
	retorno=-1;
	if(this->id==id){
		retorno=0;
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

	if(indicacion==0){
		for(int i=0; i<len; i++){
					pEmpleado= ll_get(lista, i);
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
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
				for(int i=0; i<len; i++){
					pEmpleado= ll_get(lista, i);
					if(pEmpleado!= NULL){

					fprintf(pFile, "%d, %s, %d, %d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);
					}
					else{
						printf("no se pudo");
					}
					}
				}






	return retorno;

}


