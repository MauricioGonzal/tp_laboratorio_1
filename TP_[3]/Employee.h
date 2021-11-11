




#ifndef employee_H_INCLUDED

#define employee_H_INCLUDED
#include "input.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(Employee* empleado);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int CrearEmpleado(Employee* pEmpleado);
int BuscarMayorId(LinkedList* pArrayEmpleados, int* id );
int AsignarId (LinkedList* pArrayEmpleados);

int employee_compareByName(void*, void*);
int editEmployee(LinkedList* pArrayListEmployee);

#endif // employee_H_INCLUDED
