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

/// @fn int ValidarOpcion(int, int, int)
/// @brief valida si el numero ingresado esta entre 1 y 5
///
/// @param opcion ingresada
/// @param minimo valido
/// @param maximo valido
/// @return opcion validada
int ValidarOpcion(int, int, int);

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


/// @fn int CalcularFactorial(float, unsigned long*)
/// @brief multiplica los numeros del q hasta el operador en caso de que sea valido realizar el factorial
///
/// @param operador
/// @param referencia
/// @return devuelve 1 si no se puede realizar el factorial o 0 si es valido
int CalcularFactorial (float operador, unsigned long*);
/// @fn void MostrarResultadosFlotantes(char*, char, float, float, float)
/// @brief muestra resultados con coma
///
/// @param mensaje
/// @param signo
/// @param resultado
/// @param primerOp
/// @param segundoOp
void MostrarResultadosFlotantes(char* mensaje, char signo, float resultado, float primerOp, float segundoOp);
/// @fn void MostrarResultadosEnteros(char*, unsigned long, float)
/// @brief muestra resultados enteros
///
/// @param mensaje
/// @param resultadoFactorial
/// @param operando
void MostrarResultadosEnteros(char* mensaje, unsigned long resultadoFactorial, float operando);
/// @fn int SalirDelPrograma()
/// @brief en caso que el usuario ingrese como opcion un 5 le pregunta si quiere salir del programa
///
/// @return 1 si esta seguro de salir del programa o 2 si quiere seguir operando
int SalirDelPrograma ();

#endif /* INPUT_H_ */
