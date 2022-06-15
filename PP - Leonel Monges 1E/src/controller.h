/*
 * controller.h
 *
 *  Created on: 13 jun. 2022
 *      Author: Sistemas4
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "censista.h"
#include "zona.h"

int cargarMenu(void);
void cargarMenuPrincipal();
int asignarCensistaAZona(Zona pArrayZonas[], int lenZonas, Censista pArrayCensistas[], int lenCensistas);
void mostrarZona(Zona unaZona, Censista pArrayCensistas[], int lenArrayCensistas);
int listarZonas(Zona pArrayZonas[], Censista pArrayCensistas[], int lenZonas, int lenCensistas);
void mostrarZonaEncontrada(char* mensaje, Zona unaZona, Censista pArrayCensistas[], int lenArrayCensistas);
void formatearAsignacionZonaXCensista(char* censistaAsignado, Zona unaZona, Censista pArrayCensistas[], int lenCensistas);
int cargarDatos(Zona pArrayZonas[], Censista pArrayCensistas[], int lenZonas, int lenCensistas);
int submenuCargaDatos(Zona* unaZona, Censista* unCensista);

#endif /* CONTROLLER_H_ */
