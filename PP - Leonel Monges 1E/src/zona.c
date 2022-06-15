/*
 * zona.h
 *
 *  Created on: May 18, 2022
 *      Author: Leo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "zona.h"

static int autoincrementarIdZona();
static int buscarEspacioLibre(Zona pArray[], int len);

/**
 * @fn int autoincrementarIdZona()
 * @brief Autoincrementa el ID de la Zona.
 *
 * @return ID
 */
static int autoincrementarIdZona()
{
	static int valor = VALOR_ID_ZONA;
	valor++;
	return valor;
}

/**
 * @fn int buscarEspacioLibre(Zona[], int)
 * @brief Se encarga de buscar/encontrar un lugar o posicion libre en el array.
 *
 * @param pArray: Array del tipo de dato estructura Zona a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return i == SI ENCONTRO LA POSICION || -1 == ERROR!
 */
static int buscarEspacioLibre(Zona pArray[], int len)
{
	int retorno = -1;

	if(pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

// ---------------------------------------------------------------------- //

/**
 * @fn int inicializarZona(Zona[], int)
 * @brief Inicializa los campos isEmpty(estaVacio) en 1,
 * 		  correspondientes al array del tipo de dato estructura Zona.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return 0 == OK || -1 == ERROR!
 */
int inicializarZona(Zona pArray[], int len)
{
	int retorno = -1;

	if(pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			pArray[i].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @fn int cargarZona(Zona[], int)
 * @brief
 *
 * @param pArray
 * @param len
 * @return
 */
int cargarZona(Zona pArray[], int len)
{
	int retorno = -1;
	int index;
	Zona auxZona;

	if(pArray != NULL && len > 0)
	{
		index = buscarEspacioLibre(pArray, len);
		if(index != -1)
		{
			if(	utn_getNombre(auxZona.calle1, MSJ_ZONA_INPUT_CALLE1, LEN_CALLE, REINTENTOS) == 0 &&
				utn_getNombre(auxZona.calle2, MSJ_ZONA_INPUT_CALLE2, LEN_CALLE, REINTENTOS) == 0 &&
				utn_getNombre(auxZona.calle3, MSJ_ZONA_INPUT_CALLE3, LEN_CALLE, REINTENTOS) == 0 &&
				utn_getNombre(auxZona.calle4, MSJ_ZONA_INPUT_CALLE4, LEN_CALLE, REINTENTOS) == 0 &&
				utn_getInt(&auxZona.localidad, MSJ_ZONA_INPUT_LOCALIDAD, ERROR_MSJ, 1, 5, REINTENTOS) == 0)
			{
				strncpy(pArray[index].calle1, auxZona.calle1, LEN_CALLE);
				strncpy(pArray[index].calle2, auxZona.calle2, LEN_CALLE);
				strncpy(pArray[index].calle3, auxZona.calle3, LEN_CALLE);
				strncpy(pArray[index].calle4, auxZona.calle4, LEN_CALLE);
				pArray[index].localidad = auxZona.localidad;
				pArray[index].idZona = autoincrementarIdZona();
				pArray[index].estadoZona = PENDIENTE;
				pArray[index].cantCensadosPresencial = 0;
				pArray[index].cantCensadosVirtual = 0;
				pArray[index].cantAusentes = 0;
				pArray[index].isEmpty = 0;
				retorno = index;
			}
		}
		else
		{
			printf(MSJ_ERROR_NO_HAY_ESPACIO);
		}
	}

	return retorno;
}

/**
 * @fn void formatearLocalidades(int, char*)
 * @brief Asigna a una cadena de caracteres el nombre de la localidad
 * 		  segun el numero que corresponda de dicho lugar.
 *
 * @param numLocalidad: numero de localidad a emplear.
 * @param localidad: cadena de caracteres a asignar.
 */
void formatearLocalidades(int numLocalidad, char* localidad)
{
	switch (numLocalidad)
	{
		case 1:
			strncpy(localidad,LOCALIDAD_1_QUILMES, LEN_LOCALIDAD);
			break;
		case 2:
			strncpy(localidad, LOCALIDAD_2_BERNAL, LEN_LOCALIDAD);
			break;
		case 3:
			strncpy(localidad, LOCALIDAD_3_EZPELETA, LEN_LOCALIDAD);
			break;
		case 4:
			strncpy(localidad, LOCALIDAD_4_BERAZATEGUI, LEN_LOCALIDAD);
			break;
		case 5:
			strncpy(localidad, LOCALIDAD_5_WILDE, LEN_LOCALIDAD);
			break;
	}
}

/**
 * @fn void formatearEstadoZona(int, char*)
 * @brief Asigna a una cadena de caracteres el estado de la zona
 * 		  segun el numero que corresponda de dicho estado.
 *
 * @param numEstado: numero de estado a emplear.
 * @param estado: cadena de caracteres a asignar.
 */
void formatearEstadoZona(int numEstado, char* estado)
{
	switch(numEstado)
	{
	case PENDIENTE:
		strcpy(estado, "PENDIENTE");
		break;
	case FINALIZADO:
		strcpy(estado, "FINALIZADO");
		break;
	}
}

/**
 * @fn void formatearCamposCensadosZona(int, int, int, int, char*, char*, char*)
 * @brief
 *
 * @param estado
 * @param cantPresencial
 * @param cantVirtual
 * @param cantAusentes
 * @param strCantPresencial
 * @param strCantVirtual
 * @param strCantAusentes
 */
void formatearCamposCensadosZona(int estado,
		int cantPresencial,
		int cantVirtual,
		int cantAusentes,
		char* strCantPresencial,
		char* strCantVirtual,
		char* strCantAusentes)
{
	if(	estado == PENDIENTE &&
		cantPresencial == 0 &&
		cantVirtual == 0 &&
		cantAusentes == 0)
	{
		strcpy(strCantPresencial, "NO CENSADO");
		strcpy(strCantVirtual, "NO CENSADO");
		strcpy(strCantAusentes, "NO CENSADO");
	}
	else
	{
		sprintf(strCantPresencial, "%d", cantPresencial);
		sprintf(strCantVirtual, "%d", cantVirtual);
		sprintf(strCantAusentes, "%d", cantAusentes);
	}
}

/**
 * @fn void altaForzadaZona(Zona[], int, char*, char*, char*, char*, int, int, int, int, int)
 * @brief
 *
 * @param pArray
 * @param index
 * @param calle1
 * @param calle2
 * @param calle3
 * @param calle4
 * @param localidad
 * @param estadoZona
 * @param cantCensadosPresencial
 * @param cantCensadosVirtual
 * @param cantAusentes
 */
void altaForzadaZona(Zona pArray[], int index,
		char* calle1,
		char* calle2,
		char* calle3,
		char* calle4,
		int localidad,
		int estadoZona,
		int cantCensadosPresencial,
		int cantCensadosVirtual,
		int cantAusentes)
{
	strncpy(pArray[index].calle1, calle1, LEN_DIRECCION);
	strncpy(pArray[index].calle2, calle2, LEN_DIRECCION);
	strncpy(pArray[index].calle3, calle3, LEN_DIRECCION);
	strncpy(pArray[index].calle4, calle4, LEN_DIRECCION);
	pArray[index].localidad = localidad;
	pArray[index].estadoZona = estadoZona;
	pArray[index].cantCensadosPresencial = cantCensadosPresencial;
	pArray[index].cantCensadosVirtual = cantCensadosVirtual;
	pArray[index].cantAusentes = cantAusentes;
	pArray[index].idZona = autoincrementarIdZona();
	pArray[index].isEmpty = 0;
}

/**
 * @fn void mostrarCabeceraDatosZona()
 * @brief  Muestra el encabezado de la Zona.
 *
 */
void mostrarCabeceraDatosZona()
{
	printf("\n | %-4s | %-20s | %-10s | %-11s | %-15s | %-15s | %-15s | %-15s | %16s | %13s | %14s |\n",
			CABECERA_ID_ZONA,
			CABECERA_NOMBRE_APELLIDO_CENSISTA,
			CABECERA_ESTADO,
			CABECERA_LOCALIDAD,
			CABECERA_CALLE1,
			CABECERA_CALLE2,
			CABECERA_CALLE3,
			CABECERA_CALLE4,
			CABECERA_CANT_PRESENCIAL,
			CABECERA_CANT_VIRTUAL,
			CABECERA_CANT_AUSENTES);
	printf(CABECERA_LINEA_SEPARADORA_ZONA);
}

/**
 * @fn int buscarIndexZonaPorId(Zona[], int, int)
 * @brief Se encarga de encontrar el indice del dato guardado mediante el uso del su ID.
 *
 * @param pArray: Array del tipo de dato estructura Zona a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @param idCensista: Campo a comparar en array.
 * @return i == SI ENCONTRO EL USUARIO || -1 == ERROR!
 */
int buscarIndexZonaPorId(Zona pArray[], int len, int idZona)
{
	int retorno = -1;

	if(pArray != NULL && len > 0 && idZona > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(pArray[i].idZona == idZona && pArray[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
