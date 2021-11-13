




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

/// @fn Employee employee_new*()
/// @brief	reserva memoria dinamica para un dato de tipo employee
///
/// @return
Employee* employee_new();

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldo
/// @return
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/// @fn int employee_delete(Employee*)
/// @brief
///
/// @param empleado
/// @return
int employee_delete(Employee* empleado);

/// @fn int employee_setId(Employee*, int)
/// @brief
///
/// @param this
/// @param id
/// @return
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @brief
///
/// @param this
/// @param id
/// @return
int employee_getId(Employee* this,int* id);

/// @fn int employee_setNombre(Employee*, char*)
/// @brief
///
/// @param this
/// @param nombre
/// @return
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @brief
///
/// @param this
/// @param nombre
/// @return
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief
///
/// @param this
/// @param horasTrabajadas
/// @return
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief
///
/// @param this
/// @param horasTrabajadas
/// @return
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @brief
///
/// @param this
/// @param sueldo
/// @return
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief
///
/// @param this
/// @param sueldo
/// @return
int employee_getSueldo(Employee* this,int* sueldo);

/// @fn int CrearEmpleado(Employee*)
/// @brief
///
/// @param pEmpleado
/// @return
int CrearEmpleado(Employee* pEmpleado);

/// @fn int BuscarMayorId(LinkedList*, int*)
/// @brief
///
/// @param pArrayEmpleados
/// @param id
/// @return
//int BuscarMayorId(LinkedList* pArrayEmpleados, int* id );

/// @fn int AsignarId(LinkedList*)
/// @brief
///
/// @param pArrayEmpleados
/// @return
//int AsignarId (LinkedList* pArrayEmpleados);

/// @fn int employee_compareByName(void*, void*)
/// @brief
///
/// @param e1
/// @param e2
/// @return
int employee_compareByName(void* e1, void* e2);

/// @fn int employee_compareById(void*, void*)
/// @brief
///
/// @param e1
/// @param e2
/// @return
int employee_compareById(void* e1, void* e2);

/// @fn int employee_compareBySalary(void*, void*)
/// @brief
///
/// @param e1
/// @param e2
/// @return
int employee_compareBySalary(void* e1, void* e2);

/// @fn int employee_compareByHours(void*, void*)
/// @brief
///
/// @param e1
/// @param e2
/// @return
int employee_compareByHours(void* e1, void* e2);

/// @fn int editEmployee(LinkedList*)
/// @brief
///
/// @param pArrayListEmployee
/// @return
int editEmployee(LinkedList* pArrayListEmployee);

/// @fn int elegirCriterioDeOrdenamiento(int*, int*)
/// @brief
///
/// @param opcion
/// @param opcionDos
/// @return
int elegirCriterioDeOrdenamiento(int *opcion, int* opcionDos);

int buscarId(Employee* this, int id);
Employee* buscarIdEmpleado(LinkedList* pArrayListEmployee, int len, int id, int* auxI);
int guardarArchivo(LinkedList* lista, FILE* pFile, int indicacion, int len);
int employee_listarEmpleados(LinkedList* lista, int len);
void employee_listarUnEmpleado(Employee* empleado);

#endif // employee_H_INCLUDED
