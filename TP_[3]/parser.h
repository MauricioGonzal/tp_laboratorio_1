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
/// @brief convierte el contenido de un archivo en struct de tipo employee
/// @param pFile
/// @param pArrayListEmployee
/// @return 0 si esta ok, -1 si hubo error
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// @brief
/// @param pFile
/// @param pArrayListEmployee
/// @return
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


int parser_maxIdFromText(FILE* pFile, int* id);


#endif /* PARSER_H_ */
