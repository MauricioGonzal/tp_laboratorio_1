/*
 * input.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>

int getString(char* cadena, char* mensaje, char* mensajeError, int longitud);
float LoadFloat(char message[]);
int LoadInt(char message[]);
int LoadIntRange(char message[], int* opcion, int num);
void LoadString(char message[], char loadedString[]);
int SalirDelPrograma();
void VerificacionRetorno(int retorno, char mensajeCorrecto[], char mensajeError[]);
void VerificarTresRetornos(int retorno, char mensajeCorrecto[], char mensajeNoExiste[], char mensajeError[]);
void Menu ();
int ordenarArrayInt(int* pArray, int limite);
int ValidarNumero(char numeros[]);
int LoadStringValidado(char message[], char loadedString[]);
int PedirYValidarNumero(char numeros[], char mensaje[]);
#endif /* INPUT_H_ */
