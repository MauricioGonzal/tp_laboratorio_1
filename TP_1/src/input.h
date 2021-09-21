/*
 * input.h
 *
 *  Created on: 15 sep. 2021
 *      Author: Mauri
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

/// @fn int IngresarOpcion()
/// @brief pide un numero al usuario para elegir una opcion del menu
///
/// @return numero validado
int IngresarOpcion();

/// @fn int ValidarOpcion(int)
/// @brief valida si el numero ingresado esta entre 1 y 5
///
/// @param numero ingresado por el usuario
/// @return numero validado
int ValidarOpcion(int);

/// @fn int IngresarOperandos(float*, char*)
/// @brief pide operandos al usuario, puede ser el primero o el segundo
///
/// @param espacio en memoria referido al operando
/// @param cadena de caracteres para indicar si es el primer o segundo operando
/// @return operando
int IngresarOperandos(float*, char*);

/// @fn void SumarOperandos(float, float, float*)
/// @brief suma los operandos ingresados
///
/// @param primerOp
/// @param segundoOp
/// @param lugar en memoria de la variable resultadoSuma
void SumarOperandos (float primerOp, float segundoOp, float*);

/// @fn void RestarOperandos(float, float, float*)
/// @brief resta los operandos ingresados
///
/// @param primerOp
/// @param segundoOp
/// @param  resta
void RestarOperandos(float primerOp, float segundoOp, float* resta);

/// @fn int DividirOperandos(float, float, float*)
/// @brief divide los operandos ingresados
///
/// @param primerOp
/// @param segundoOp
/// @param division
/// @return !=1 si la division es por cero
int DividirOperandos(float primerOp, float segundoOp, float* division);

/// @fn void MultiplicarOperandos(float, float, float*)
/// @brief multiplica los operandos ingresados
///
/// @param primerOp
/// @param segundoOp
/// @param multiplicacion
void MultiplicarOperandos( float primerOp, float segundoOp, float* multiplicacion);


/// @fn int CalcularFactorial(float)
/// @brief calcula el factorial de un numero flotante
///
/// @param operador
/// @return factorial del operador indicado como parametro
int CalcularFactorial (float operador);
/// @fn void MostrarResultados(int, float, float, float, float, int, int, float, float)
/// @brief muestra todos los resultados de las operaciones
///
/// @param banderaDivision
/// @param resultadoSuma
/// @param resultadoResta
/// @param resultadoDivision
/// @param resultadoMultiplicacion
/// @param factorialPrimerOperando
/// @param factorialSegundoOperando
/// @param primerOp
/// @param segundoOp
void MostrarResultados (int banderaDivision, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, int factorialPrimerOperando, int factorialSegundoOperando, float primerOp, float segundoOp);



#endif /* INPUT_H_ */
