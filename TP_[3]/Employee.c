
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/// @fn Employee employee_new*()
/// @brief reserva memoria dinamica para un dato de tipo empleado e inicializa sus campos
///
/// @return el puntero a employee inicializado
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

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief cambia los campos inicializados del employee por los datos de los parametros
///
/// @param idStr id en formato string
/// @param nombreStr nombre
/// @param horasTrabajadasStr horas trabajadas en formato string
/// @param sueldo en formato string
/// @return el puntero a employee creado
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

/// @fn int employee_delete(Employee*)
/// @brief libera el espacio del empleado eliminado
///
/// @param this puntero de tipo employee
/// @return -1 si el puntero parametro es NULL o 0 si esta todo ok
int employee_delete(Employee* this){


	int retorno;
	retorno=-1;
	if(this!=NULL){
		free(this);
		retorno=0;
	}
	return retorno;

}


/// @fn int employee_setId(Employee*, int)
/// @brief setea el campo id
///
/// @param this puntero de tipo employee
/// @param id valor por el que se va a reemplazar el dato del campo id
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setId(Employee* this,int id){
	int retorno;
	retorno=-1;
	if(this!=NULL){
	this->id= id;
	retorno=0;
	}

	return retorno;

}

/// @fn int employee_getId(Employee*, int*)
/// @brief obtiene el campo id
///
/// @param this puntero de tipo employee
/// @param id puntero de tipo entero en donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getId(Employee* this,int* id){
	int retorno;
	retorno=-1;
	if(this!=NULL && id!=NULL){
	*id= this->id;
	retorno=0;
	}

	return retorno;


}

/// @fn int employee_setNombre(Employee*, char*)
/// @brief setea el campo nombre
///
/// @param this puntero de tipo employee
/// @param nombre valor que va a reemplazar al que se encuentra en el campo nombre
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setNombre(Employee* this,char* nombre){
	int retorno;
		retorno=-1;
		if(this!=NULL){
		strcpy(this->nombre, nombre);
		retorno=0;
		}

		return retorno;
}

/// @fn int employee_getNombre(Employee*, char*)
/// @brief obtiene el dato que esta en el campo nombre
///
/// @param this puntero de tipo employee
/// @param nombre puntero de tipo char* en donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getNombre(Employee* this,char* nombre){
	int retorno;
		retorno=-1;
		if(this!=NULL && nombre!=NULL){
		strcpy(nombre, this->nombre);
		retorno=0;
		}

		return retorno;

}

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief setea el campo horasTrabajadas
///
/// @param this puntero de tipo employee
/// @param horasTrabajadas  valor que va a reemplazar al que se encuentra en el campo horasTrabajadas
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno;
			retorno=-1;
			if(this!=NULL){
			this->horasTrabajadas= horasTrabajadas;
			retorno=0;
			}

			return retorno;
}

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief obtiene el valor que se encuentra en el campo horasTrabajadas
///
/// @param this puntero de tipo employee
/// @param horasTrabajadas nombre puntero de tipo int en donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno;
		retorno=-1;
		if(this!=NULL && horasTrabajadas!=NULL){
		*horasTrabajadas= this->horasTrabajadas;
		retorno=0;
		}

		return retorno;
}

/// @fn int employee_setSueldo(Employee*, int)
/// @brief setea el campo sueldo
///
/// @param this ppuntero de tipo employee
/// @param sueldo valor que va a reemplazar al que se encuentra en el campo sueldo
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setSueldo(Employee* this,int sueldo){
	int retorno;
				retorno=-1;
				if(this!=NULL){
				this->sueldo= sueldo;
				retorno=0;
				}

				return retorno;
}

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief obtiene el valor que se encuentra en el campo sueldo
///
/// @param this puntero de tipo employee
/// @param sueldo puntero de tipo int donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno;
			retorno=-1;
			if(this!=NULL && sueldo!=NULL){
			*sueldo= this->sueldo;
			retorno=0;
			}

			return retorno;
}

/// @fn int CrearEmpleado(Employee*)
/// @brief setea los campos del empleado pasado como parametro
///
/// @param pEmpleado puntero de tipo employee
/// @return -1 si el puntero parametro es NULL, 1 si el usuario ingresa numeros en el campo nombre y 0 si esta todo ok
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
			retorno=0;
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

/// @fn int BuscarMayorId(LinkedList*, int*)
/// @brief
///
/// @param pArrayEmpleados
/// @param id
/// @return
/*int BuscarMayorId(LinkedList* pArrayEmpleados, int* id ){

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
}*/

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

		if(pArrayListEmployee!=NULL)
		{
		retorno=1;
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
	for(int i=0; i<len; i++)
		{
			empleado= ll_get(lista, i);
			if(empleado!=NULL){
				retorno= 0;
				employee_listarUnEmpleado(empleado);
			}

		}

	return retorno;
}
