/*
 * nexo.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "localidad.h"
#include "pedido.h"
#include "input.h"
#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMDATOS 25
#define VACIO 0
#define CARGADO 1
#define PENDIENTE 0
#define COMPLETADO 1

/// @fn int CrearPedido(ePedido[], eCliente[], int, int, int*, int)
/// @brief busca el primer lugar vacio en la lista pedidos y lo introduce creando un id automatico
/// @param listaPedidos
/// @param listaClientes
/// @param tam
/// @param tamDos
/// @param id puntero
/// @param idValor pasaje por valor
/// @return 0 si esta todo ok, -1 si algun puntero es NULL o si algun tam es menor que 1
int CrearPedido(ePedido listaPedidos[], eCliente listaClientes[], int tam, int tamDos, int* id, int idValor);




int AltaDeCliente(eCliente listaClientes[], eLocalidad localidades[], int tam, int* id, int idValor, int tamDatos);
int AdjudicarLocalidad(eCliente cliente, char clienteLocalidad[], eLocalidad listaLocalidades[], int tam);
int ProcesarResiduos(ePedido listaPedidos[], eCliente listaClientes[], int tam, int tamDos);


#endif /* NEXO_H_ */
