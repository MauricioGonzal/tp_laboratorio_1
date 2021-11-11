
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new(){
	Employee* empleado= NULL;
	empleado= (Employee*) malloc(sizeof(Employee));
	empleado->id=0;
	strcpy(empleado->nombre, "");
	empleado->horasTrabajadas= 0;
	empleado->sueldo=0;


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
		LoadString("Ingrese el nombre del nuevo empleado", auxNombre);
		employee_setNombre(pEmpleado, auxNombre);
		while(PedirYValidarNumero(auxSueldo, "Ingrese el nuevo sueldo")!=0){
			PedirYValidarNumero(auxSueldo, "Ingrese el nuevo sueldo");
		}
		while(PedirYValidarNumero(auxHoras, "Ingrese las horas trabajadas")!=0){
			PedirYValidarNumero(auxHoras, "Ingrese las horas trabajadas");
		}

		sueldo= atoi(auxSueldo);
		horas= atoi(auxHoras);
		pEmpleado->sueldo= sueldo;

		pEmpleado->horasTrabajadas= horas;


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
		}

		*id= mayorId;

		return retorno;

}

int AsignarId (LinkedList* pArrayEmpleados){
	int retorno;
	int id;
	if(pArrayEmpleados!=NULL){
		BuscarMayorId(pArrayEmpleados, &id);
		id++;
	}

	return id;
}

int editEmployee(LinkedList* pArrayListEmployee){
	int retorno;
		int idAux;
		char sueldo[10];
		char horasTrabajadas[5];
		int sueldoInt;
		int horasInt;
		int len;
		retorno= -1;
		len= ll_len(pArrayListEmployee);
		Employee* empleado;
		idAux= LoadInt("ingrese el id del empleado que desea modificar");
		for(int i=0; i<len; i++){
			empleado= (Employee*)ll_get(pArrayListEmployee, i);
			if(empleado!=NULL){
				retorno=1;
				if(idAux== empleado->id ){
				PedirYValidarNumero(sueldo, "ingrese el nuevo sueldo");
				sueldoInt= atoi(sueldo);
				employee_setSueldo(empleado, sueldoInt);
				PedirYValidarNumero(horasTrabajadas,"ingrese las nuevas horas trabajadas");
				horasInt= atoi(horasTrabajadas);
				employee_setHorasTrabajadas(empleado, horasInt);
				retorno=0;
				break;
				}
			}
		}
		return retorno;
}


int employee_compareByName(void* e1, void* e2){
	Employee* unEmpleado;
	Employee* otroEmpleado;
	unEmpleado= (Employee*) e1;
	otroEmpleado = (Employee*)e2;




}
