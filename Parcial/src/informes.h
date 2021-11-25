/*
 * informes.h
 *
 *  Created on: 17 oct. 2021
 *      Author: Mauri
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "pedido.h"
#include "input.h"
#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMDATOS 25
#define VACIO 0
#define CARGADO 1
#define PENDIENTE 0
#define COMPLETADO 1

/// @fn int PromediarKilosPolipropileno(eCliente[], ePedido[], int, int)
/// @brief divide la cantidad de kilos procesados de PP y la cantidad de clientes
/// @param listaClientes
/// @param listaPedidos
/// @param tamUno
/// @param tamDos
/// @return -1 si el puntero es NULL o los tamaños son menores a 1, o 0 si esta ok
int PromediarKilosPolipropileno(eCliente listaClientes[], ePedido listaPedidos[], int tamUno, int tamDos);
/// @fn int ImprimirPedidos(ePedido[], eCliente[], int, int, int)
/// @brief imprime los pedidos dependiendo la variable indicacion, en estado pendiente o los pedidos en estado procesado
/// @param listaPedidos
/// @param listaClientes
/// @param tamUno
/// @param tamDos
/// @param indicacion 1 si queremos imprimir los pedidos pendientes, 2 si queremso imprimir pedidos procesados
/// @return  -1 si el puntero es NULL o los tamaños son menores a 1, o 0 si esta ok
int ImprimirPedidos(ePedido listaPedidos[], eCliente listaClientes[], int tamUno, int tamDos, int indicacion );

#endif /* INFORMES_H_ */
