/*
 * parser.h
 *
 *  Created on: 7 nov. 2021
 *      Author: Mauri
 */

#include <string.h>

#ifndef PARSER_H_
#define PARSER_H_
/// @fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// @brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
/// @param pFile puntero a archivo
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si algun puntero parametro es NULL, 1 si no se encuentra espacio y 0 si ok
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @brief  Parsea los datos de los empleados desde el archivo data.csv (modo binario).
/// @param pFile puntero a archivo
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si algun puntero parametro es NULL, 1 si no se encuentra espacio y 0 si ok
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_maxIdFromText(FILE*, int*)
/// @brief parsea el id que se encuentra en el archivo maxId.txt a tipo entero
///
/// @param pFile puntero al archivo
/// @param id puntero
/// @return retorna lo que devuelva el scanf que lee el archivo, -1 si no hay nada cargado, 1 si existe el dato en el archivo
int parser_maxIdFromText(FILE* pFile, int* id);


#endif /* PARSER_H_ */
