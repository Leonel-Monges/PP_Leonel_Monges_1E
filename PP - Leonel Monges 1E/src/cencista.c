/*
 * cencista.c
 *
 *  Created on: 17 may. 2022
 *      Author: Sistemas4
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cencista.h"

static int autoincrementarIdCencista();
static int buscarIndexPorId(Censista pArray[], int len, int idCencista);
static int buscarEspacioLibre(Censista pArray[], int len);

static int autoincrementarIdCencista()
{
	static int valor = VALOR_INICIAL;
	valor++;
	return valor;
}

static int buscarIndexPorId(Censista pArray[], int len, int idCencista)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && idCencista > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(pArray[i].idCencista == idCencista && pArray[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

static int buscarEspacioLibre(Censista pArray[], int len)
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

// ----------------------------------------------------------------------- //

/**
 * @fn int inicializarAuto(Cencista[], int)
 * @brief Inicializa los campos del isEmpty (estaVacio) en 1, bajo el tipo de dato estructura Cencista.
 *
 * @param pArray: Array a recorrer.
 * @param len: lenght/longitud del array a recorrer.
 * @return 0 == OK || -1 == ERROR!
 */
int inicializarCensista(Censista pArray[], int len)
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

int cargarCensista(Censista pArray[], int len)
{
	int retorno = -1;
	int indexLibre;
	if(pArray != NULL && len > 0)
	{
		indexLibre = buscarEspacioLibre(pArray, len);
		if(indexLibre != -1)
		{
			// Codigo de Carga
			pArray[indexLibre].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

int bajaCensista(Censista pArray[], int len, int idCencista)
{
	int retorno = -1;
	int index;
	if(pArray != NULL && len > 0 && idCencista > 0)
	{
		index = buscarIndexPorId(pArray, len, idCencista);
		if(index != -1)
		{
			// Imprimir el dato y preguntar si quiere baja
			mostrarCensista(pArray[index]);
			pArray[index].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

int modificarCensista(Censista pArray[], int len, int idCencista)
{
	int retorno = -1;
	int indexLibre;
	if(pArray != NULL && len > 0 && idCencista > 0)
	{
		indexLibre = buscarIndexPorId(pArray, len, idCencista);
		if(indexLibre != -1)
		{
			// Imprimo el dato que encontre y submenu de campos a modificar
			mostrarCensista(pArray[indexLibre]);
			retorno = 0;
		}
	}
	return retorno;
}

void mostrarCensista(Censista unCencista)
{
	if(unCencista.isEmpty == 0)
	{
		// printf(campos)
	}
}

int listarCensista(Censista pArray[], int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			mostrarCensista(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int estaCargado(Censista pArray[], int len)
{
	int retorno = 0;
	if(pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

//int ordenarCensistaPorCampo(Censista pArray[], int len)
//{
//	int retorno = -1;
//	int i;
//	Cencista aux;
//	int estaOrdenado;
//
//	if (pArray != NULL && len > 0)
//	{
//		do
//		{
//			estaOrdenado = 1;
//			len--;
//			for (i = 0; i < len; i++)
//			{
//				if(strcmp(pArray[i].campo, pArray[i + 1].campo) < 0)
//				{
//					aux = pArray[i];
//					pArray[i] = pArray[i + 1];
//					pArray[i + 1] = aux;
//					estaOrdenado = 0;
//				}
//				else if(strcmp(pArray[i].campo, pArray[i + 1].campo) == 0 &&
//					pArray[i].campo2 < pArray[i + 1].campo2)
//				{
//					pArray[i] = pArray[i + 1];
//					pArray[i + 1] = aux;
//					estaOrdenado = 0;
//				}
//			}
//		}while (estaOrdenado == 0);
//		retorno = 0;
//	}
//	return retorno;
//}
