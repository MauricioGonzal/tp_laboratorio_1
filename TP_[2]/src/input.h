/*
 * input.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Mauri
 */

#ifndef INPUT_H_
#define INPUT_H_

int getString(char* cadena, char* mensaje, char* mensajeEror, int longitud);
int esNumerica(char* cadena, int longitud);
int getInt(int* pResultado);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esLetra(char* cadena, int limite);
int utn_getDatoPalabra(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int longitud);
int LoadIntRange(char message[], int num);
void LoadString(char message[], char loadedString[]);
float LoadFloat(char message[]);
int LoadInt(char message[]);


#endif /* INPUT_H_ */
