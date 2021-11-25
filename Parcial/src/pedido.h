/*
 * pedido.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include <stdio.h>


typedef struct{
	int id;
	int estado;
	int isEmpty;
	float kilosTotales;
	float kilosARecolectar;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int idCliente;
}ePedido;

/// @fn int InicializarPedidos(ePedido[], int)
/// @brief inicializa los campos isEmpty, kilosTotales, kilosPP, kilosHDPE, kilosLDPE en 0
/// @param listaPedidos
/// @param tam
/// @return 0 si esta todo ok, -1 si el puntero es NULL o el tam es menor a 1
int InicializarPedidos(ePedido listaPedidos[], int tam);

/// @fn int ProcesarResiduos(ePedido[], int)
/// @brief pide un id y procesa un pedido pendiente si los encuentra y lo cambia a estado COMPLETADO
/// @param listaPedidos
/// @param tam
/// @return 0 si esta OK, -1 si el puntero es NULL o el tam es menor a 1, o 1 si no se encontro el pedido con el id ingresado




#endif /* PEDIDO_H_ */
