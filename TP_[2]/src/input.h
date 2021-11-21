/*
 * input.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

/// @fn int getString(char*, char*, char*, int)
/// @brief obtiene una cadena de chars
///
/// @param cadena
/// @param mensaje
/// @param mensajeError
/// @param longitud
/// @return -1 si si el puntero cadena es NULL o la longitud es menor a 1, 0 si esta ok, 1 si son numeros
int getString(char* cadena, char* mensaje, char* mensajeError, int longitud);

/// @fn float LoadFloat(char[])
/// @brief obtiene un flotante
///
/// @param message
/// @return el numero obtenido
float LoadFloat(char message[]);

/// @fn int SalirDelPrograma()
/// @brief verifica si el usuario quiere salir del programa
///
/// @return la opcion obtenida y validada
int SalirDelPrograma();

/// @fn void VerificacionRetorno(int, char[], char[])
/// @brief analiza que mensaje imprimir de acuerdo a dos retornos posibles(-1 o 0)
///
/// @param retorno
/// @param mensajeCorrecto
/// @param mensajeError
void VerificacionRetorno(int retorno, char mensajeCorrecto[], char mensajeError[]);

/// @fn void VerificarTresRetornos(int, char[], char[], char[])
/// @brief analiza que mensaje imprimir de acuerdo a tres retornos posibles(-1, 0 o 1)
///
/// @param retorno
/// @param mensajeCero
/// @param mensajeUno
/// @param mensajeError
void VerificarTresRetornos(int retorno, char mensajeCero[], char mensajeUno[], char mensajeError[]);

/// @fn void Menu()
/// @brief imprime el menu en pantalla
///
void Menu ();

/// @fn int ValidarNumero(char[])
/// @brief valida que una cadena de chars sean solo numeros
///
/// @param numeros
/// @return 0 si son numeros, -1 si hay alguna letra
int ValidarNumero(char numeros[]);

/// @fn int validarStringLetras(char[])
/// @brief valida que una cadena sean solo letras
///
/// @param string
/// @return 0 si ok, -1 si es numero
int validarStringLetras(char string[]);

int PedirYValidarNumero(char mensaje[], int* numeroConvertido);

/// @fn int validarRango(int, int, int)
/// @brief valida que el numero parametro este dentro del rango
///
/// @param numero
/// @param minimo
/// @param maximo
/// @return 0 si ok, -1 si esta fuera del rango
int validarRango(int numero, int minimo, int maximo);

/// @fn int PedirYValidarNumeroMejorado(char[], int*, int, int)
/// @brief version 2 de la funcion pedir y validar numero
///
/// @param mensaje
/// @param numeroConvertido
/// @param min el minimo que puede tener el numero ingresado
/// @param max el maximo que puede tener el numero ingresado
/// @return solo retorna 0 si esta ok
int PedirYValidarNumeroMejorado(char mensaje[], int* numeroConvertido, int min, int max);
#endif /* INPUT_H_ */

