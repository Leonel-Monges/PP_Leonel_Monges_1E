/*
 * controller.c
 *
 *  Created on: 13 jun. 2022
 *      Author: Sistemas4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "utn.h"

int cargarMenu(void)
{
	setbuf(stdout, NULL);

	cargarMenuPrincipal();

	return EXIT_SUCCESS;
}

/**
 * @fn void cargarMenuPrincipal()
 * @brief Muestra el menu principal del programa.
 *
 */
void cargarMenuPrincipal()
{
	int opcion;
	int auxId;
	int respuesta;
	int auxIndex = 0;
	int auxIndexZona = 0;

	Censista arrayCensistas[LEN_CENSISTAS];
	Zona arrayZonas[LEN_ZONAS];
	inicializarCensista(arrayCensistas, LEN_CENSISTAS);
	inicializarZona(arrayZonas, LEN_ZONAS);

	altaForzadaCensista(arrayCensistas, auxIndex++, "Jose", "Ortigueira", 3, 8, 1985, "Ascasubi", 325, ACTIVO, 0);
	altaForzadaCensista(arrayCensistas, auxIndex++, "Maria", "Barrionuevo", 16, 2, 1992, "Lavalle", 1658, ACTIVO, 0);
	altaForzadaCensista(arrayCensistas, auxIndex++, "Marcos", "Garcia", 25, 12, 1989, "Mitre", 3425, ACTIVO, 0);
	altaForzadaCensista(arrayCensistas, auxIndex++, "Mel", "Gibson", 27, 7, 1961, "Ayacucho", 654, ACTIVO, 0);
	altaForzadaCensista(arrayCensistas, auxIndex++, "Rick", "Ashley", 5, 9, 1970, "Calchaqui", 5246, ACTIVO, 0);
	altaForzadaCensista(arrayCensistas, auxIndex++, "Alexandra", "Britez", 14, 2, 1998, "Garibaldi", 768, ACTIVO, 0);

	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", 1, 1, 0, 0, 0);
	altaForzadaZona(arrayZonas, auxIndexZona++, "Conesa", "Libertad", "Colon", "Belgrano", 1, 1, 0, 0, 0);
	altaForzadaZona(arrayZonas, auxIndexZona++, "Zapiola", "Arenales", "Yapeyu", "Rodriguez Penia", 2, 1, 0, 0, 0);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "9", "147", "10", "146", 4, 2, 5, 23, 6);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", LOCALIDAD_1_QUILMES, 1, 0, 0, 0);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", LOCALIDAD_1_QUILMES, 1, 0, 0, 0);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", LOCALIDAD_1_QUILMES, 1, 0, 0, 0);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", LOCALIDAD_1_QUILMES, 1, 0, 0, 0);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", LOCALIDAD_1_QUILMES, 1, 0, 0, 0);
//	altaForzadaZona(arrayZonas, auxIndexZona++, "Alsina", "Rivadavia", "Moreno", "San Martin", LOCALIDAD_1_QUILMES, 1, 0, 0, 0);

	do
		{
			utn_getInt(&opcion, MSJ_INPUT_MENU, ERROR_MSJ, 1, 9, REINTENTOS);
			switch(opcion)
			{
				case 1: // ALTA CENSISTA
					cargarCensista(arrayCensistas, LEN_CENSISTAS);
					break;
				case 2: // MODIFICACION CENSISTA
					listarCensistas(arrayCensistas, LEN_CENSISTAS);
					if(utn_getInt(&auxId, MSJ_INPUT_ID, ERROR_MSJ, VALOR_ID, 9999, REINTENTOS) == 0)
					{
						respuesta = modificarCensista(arrayCensistas, LEN_CENSISTAS, auxId);
						if(respuesta == SI)
						{
							printf(MSJ_MODI_CONFIRMACION);
						}
						else if(respuesta == NO)
						{
							printf(MSJ_MODI_CONFIRMACION_ABORTADA);
						}
						else
						{
							printf(MSJ_ERROR_NO_SE_ENCONTRO_USUARIO);
						}
					}
					break;
				case 3: // BAJA CENSISTA
					if(utn_getInt(&auxId, MSJ_INPUT_ID, ERROR_MSJ, VALOR_ID, 9999, REINTENTOS) == 0)
					{
						respuesta = bajaCensista(arrayCensistas, LEN_CENSISTAS, auxId);
						if(respuesta == SI)
						{
							printf(MSJ_BAJA_CONFIRMACION);
						}
						else if(respuesta == NO)
						{
							printf(MSJ_BAJA_CONFIRMACION_ABORTADA);
						}
						else
						{
							printf(MSJ_ERROR_NO_SE_ENCONTRO_USUARIO);
						}
					}
					break;
				case 4: // ALTA ZONA
					auxIndex = cargarZona(arrayZonas, LEN_ZONAS);
					if(auxIndex != -1)
					{
						mostrarZonaEncontrada(MSJ_ALTA_ZONA_CONFIRMACION,
								arrayZonas[auxIndex],
								arrayCensistas,
								LEN_CENSISTAS);
					}
					break;
				case 5: // ASIGNACION DE ZONA A CENSISTA
					asignarCensistaAZona(arrayZonas, LEN_ZONAS, arrayCensistas, LEN_CENSISTAS);
					break;
				case 6: // CARGA DE DATOS
					break;
				case 7: // MOSTRAR CENSISTAS
					listarCensistas(arrayCensistas, LEN_CENSISTAS);
					break;
				case 8: // MOSTRAR ZONAS
					listarZonas(arrayZonas, arrayCensistas, LEN_ZONAS, LEN_CENSISTAS);
					break;
				case 9: // SALIR
					printf(MSJ_FINAL);
					break;
			}

		}while(opcion != 9);

}

/**
 * @fn int asignarCensistaAZona(Zona[], int, Censista[], int)
 * @brief
 *
 * @param pArrayZonas
 * @param lenZonas
 * @param pArrayCensistas
 * @param lenCensistas
 * @return
 */
int asignarCensistaAZona(Zona pArrayZonas[], int lenZonas, Censista pArrayCensistas[], int lenCensistas)
{
	int retorno = -1;
	int auxIdZona;
	int auxIdCensista;
	int index;

	listarZonas(pArrayZonas, pArrayCensistas, lenZonas, lenCensistas);
	if(utn_getInt(&auxIdZona, "\n > Ingrese el ID de la zona: ", ERROR_MSJ, VALOR_ID_ZONA, 9999, REINTENTOS) == 0)
	{
//		buscarIndexPorId(pArray, len, idCensista) crear una funcion de buscar el indice  del arrayzona
		listarCensistas(pArrayCensistas, lenCensistas);
		if(utn_getInt(&auxIdCensista, "\n > Ingrese el ID del censista a asignar: ", ERROR_MSJ, 1000, 9999, REINTENTOS) == 0)
		{
			index = buscarIndexPorId(pArrayCensistas, lenCensistas, auxIdCensista);
			pArrayCensistas[index].idZona = auxIdZona;

			mostrarZonaEncontrada(" Asignacion de zona realizada!\n",
					pArrayZonas[auxIdZona], pArrayCensistas, lenCensistas);

			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @fn void mostrarZona(Zona, Censista[], int)
 * @brief
 *
 * @param unaZona
 * @param pArrayCensistas
 * @param lenArrayCensistas
 */
void mostrarZona(Zona unaZona, Censista pArrayCensistas[], int lenArrayCensistas)
{
	char auxLocalidad[15];
	char auxEstadoZona[15];
	char auxCantPresenciales[15];
	char auxCantVirtuales[15];
	char auxCantAusentes[15];
	char auxAsignado[30];

	formatearAsignacionZonaXCensista(auxAsignado, unaZona, pArrayCensistas, lenArrayCensistas);
	formatearEstadoZona(unaZona.estadoZona, auxEstadoZona);
	formatearLocalidades(unaZona.localidad, auxLocalidad);
	formatearCamposCensadosZona(unaZona.estadoZona,
			unaZona.cantCensadosPresencial,
			unaZona.cantCensadosVirtual,
			unaZona.cantAusentes,
			auxCantPresenciales,
			auxCantVirtuales,
			auxCantAusentes);

	if(unaZona.isEmpty == 0)
	{
		printf(" | %-4d | %-20s | %-10s | %-11s | %-15s | %-15s | %-15s | %-15s | %-16s | %-13s | %-14s |\n",
				unaZona.idZona,
				auxAsignado,
				auxEstadoZona,
				auxLocalidad,
				unaZona.calle1,
				unaZona.calle2,
				unaZona.calle3,
				unaZona.calle4,
				auxCantPresenciales,
				auxCantVirtuales,
				auxCantAusentes);
	}
}

/**
 * @fn int listarZonas(Zona[], in)
 * @brief Muestra el listado completo de las Zonas.
 *
 * @param pArray: Array del tipo de dato estructura Zona a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return 0 == OK || -1 == ERROR!
 */
int listarZonas(Zona pArrayZonas[], Censista pArrayCensistas[], int lenZonas, int lenCensistas)
{
	int retorno = -1;

	if(	pArrayZonas != NULL &&
		pArrayCensistas != NULL &&
		lenZonas > 0 &&
		lenCensistas > 0)
	{
		mostrarCabeceraDatosZona();
		for (int i = 0; i < lenZonas; i++)
		{
			mostrarZona(pArrayZonas[i], pArrayCensistas, lenCensistas);
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn void mostrarZonaEncontrada(Zona, char*)
 * @brief
 *
 * @param unaZona: Tipo de dato estructura Zona a mostrar.
 * @param mensaje:  Mensaje a ser mostrado al usuario, junto con el datos encontrados.
 */
void mostrarZonaEncontrada(char* mensaje, Zona unaZona, Censista pArrayCensistas[], int lenArrayCensistas)
{
	printf(mensaje);
	mostrarCabeceraDatosZona();
	mostrarZona(unaZona, pArrayCensistas, lenArrayCensistas);
}

/**
 * @fn void formatearAsignacionZonaXCensista(char*, Zona, Censista[], int)
 * @brief
 *
 * @param censistaAsignado
 * @param unaZona
 * @param pArrayCensistas
 * @param lenCensistas
 */
void formatearAsignacionZonaXCensista(char* censistaAsignado, Zona unaZona, Censista pArrayCensistas[], int lenCensistas)
{
	for(int i = 0; i < lenCensistas; i++)
	{
		if(unaZona.idZona == pArrayCensistas[i].idZona)
		{
			strcpy(censistaAsignado, pArrayCensistas[i].nombre);
			strcat(censistaAsignado, " ");
			strcat(censistaAsignado, pArrayCensistas[i].apellido);
			break;
		}
		else
		{
			strcpy(censistaAsignado, "SIN ASIGNAR");
		}
	}
}
// * @fn void formatearAsignacionZona(int, Censista, char*)
// * @brief
// *
// * @param estado
// * @param unCensista
// * @param asignacion
// */
//void formatearAsignacionZona(int estado, Censista unCensista, char* asignacion)
//{
//	if(estado == PENDIENTE)
//	{
//		strcpy(asignacion, "SIN ASIGNAR");
//	}
//	else
//	{
//		strcpy(asignacion, unCensista.nombre);
//		strcat(asignacion, " ");
//		strcat(asignacion, unCensista.apellido);
//	}
//}
