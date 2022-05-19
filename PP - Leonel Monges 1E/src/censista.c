/*
 * cencista.c
 *
 *  Created on: 17 may. 2022
 *      Author: Sistemas4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "censista.h"

static int autoincrementarIdCencista();
static int buscarEspacioLibre(Censista pArray[], int len);
static void mostrarCabeceraDatoCensista();
static void mostrarCensistaEncontrado(Censista unCensista, char* mensaje);
static int calcularEdad(int anioDeNacimiento, int anioActual);
static int subMenuModificacion(Censista* unCensista);
static int subMenuCampoFecha(Censista* unCensista);
static int subMenuCampoDireccion(Censista* unCensista);
static void altaForzadaCensista(Censista pArray[], int index,
		char* nombre,
		char* apellido,
		int fechaDia,
		int fechaMes,
		int fechaAnio,
		char* direccion,
		int direccionNumero,
		int estado,
		int asignacion);

/**
 * @fn int autoincrementarIdCencista()
 * @brief Autoincrementa el ID del censista.
 *
 * @return ID
 */
static int autoincrementarIdCencista()
{
	static int valor = VALOR_ID;
	valor++;
	return valor;
}

/**
 * @fn int buscarIndexPorId(Censista[], int, int)
 * @brief Se encarga de encontrar el indice del dato guardado mediante el uso del su ID.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @param idCencista: Campo a comparar en array.
 * @return i == SI ENCONTRO EL USUARIO || -1 == ERROR!
 */
int buscarIndexPorId(Censista pArray[], int len, int idCencista)
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

/**
 * @fn int buscarEspacioLibre(Censista[], int)
 * @brief Se encarga de buscar/encontrar un lugar o posicion libre en el array.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return i == SI ENCONTRO LA POSICION || -1 == ERROR!
 */
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

/**
 * @fn void mostrarCabeceraDatoCensista()
 * @brief Muestra el encabezado del usuario Censista.
 *
 */
static void mostrarCabeceraDatoCensista()
{
	printf("\n | %-5s | %-15s | %-15s | %10s | %2s | %-26s | %-8s | %-13s |\n",
			CABECERA_ID,
			CABECERA_NOMBRE,
			CABECERA_APELLIDO,
			CABECERA_FECHA_NACIMIENTO,
			CABECERA_EDAD,
			CABECERA_DIRECCION,
			CABECERA_ESTADO,
			CABECERA_ASIGNACION);
	printf(CABECERA_LINEA_SEPARADORA);
}

/**
 * @fn void mostrarCensistaEncontrado(Censista, char*)
 * @brief Muestra los datos de un usuario Censista.
 *
 * @param unCensista: Tipo de dato estructura Censista a mostrar.
 * @param mensaje: Mensaje a ser mostrado al usuario, junto con el datos encontrados.
 */
static void mostrarCensistaEncontrado(Censista unCensista, char* mensaje)
{
	printf(mensaje);
	mostrarCabeceraDatoCensista();
	mostrarCensista(unCensista);
}

/**
 * @fn int calcularEdad(int, int)
 * @brief Calcula edad de un un usuario Censista a partir de su fecha de nacimiento
 * 		  (realiza el uso del campo anio para su respectivo calculo).
 *
 * @param anioDeNacimiento: Campo del anio de nacimiento a emplear.
 * @param anioActual: Campo del anio actual a tener en cuenta.
 * @return VALOR DE EDAD
 */
static int calcularEdad(int anioDeNacimiento, int anioActual)
{
	return anioActual - anioDeNacimiento;
}

/**
 * @fn int subMenuCampoFecha(Censista*)
 * @brief Muestra un submenu para modificar a seleccion,
 * 		  los datos de fecha de nacimiento correspondientes a un usuario Censista.
 *
 * @param unCensista: Tipo de dato estructura Censista a emplear.
 * @return 0 == OK || -1 == ERROR!
 */
static int subMenuCampoFecha(Censista* unCensista)
{
	int retorno = -1;
	int opcion;
	int auxCampo;

	do
	{
		if(utn_getInt(&opcion, MSJ_MODI_INPUT_SUBMENU_FECHA, ERROR_MSJ, 1, 4, REINTENTOS) == 0)
		{
			switch(opcion)
			{
			case 1: // DIA
				if(utn_getInt(&auxCampo, " > Ingrese el dia de nacimiento: ", ERROR_MSJ, 1, 31, REINTENTOS) == 0)
				{
					unCensista->fechaNacimiento.dia = auxCampo;
					printf(MSJ_MODI_SUBMENU_CONFIMACION_DIA);
					retorno = 0;
				}
				break;
			case 2: // MES
				if(utn_getInt(&auxCampo, " > Ingrese el mes de nacimiento: ", ERROR_MSJ, 1, 12, REINTENTOS) == 0)
				{
					unCensista->fechaNacimiento.mes = auxCampo;
					printf(MSJ_MODI_SUBMENU_CONFIMACION_MES);
					retorno = 0;
				}
				break;
			case 3: // ANIO
				if(utn_getInt(&auxCampo, " > Ingrese el anio de nacimiento: ", ERROR_MSJ, LIMITE_ANIO_MINIMO, LIMITE_ANIO_MAXIMO, REINTENTOS) == 0)
				{
					unCensista->fechaNacimiento.anio = auxCampo;
					unCensista->edad = calcularEdad(unCensista->fechaNacimiento.anio, LIMITE_ANIO_MAXIMO); // Actualizacion de edad
					printf(MSJ_MODI_SUBMENU_CONFIMACION_ANIO);
					retorno = 0;
				}
				break;
			}
		}
	}while(opcion != 4);

	return retorno;
}

/**
 * @fn int subMenuCampoDireccion(Censista*)
 * @brief Muestra un submenu para modificar a seleccion,
 * 		  los datos de direccion correspondientes a un usuario Censista.
 *
 * @param unCensista: Tipo de dato estructura Censista a emplear.
 * @return 0 == OK || -1 == ERROR!
 */
static int subMenuCampoDireccion(Censista* unCensista)
{
	int retorno = -1;
	int opcion;
	eDireccion auxDireccion;

	do
	{
		if(utn_getInt(&opcion, MSJ_MODI_INPUT_SUBMENU_DIRECCION, ERROR_MSJ, 1, 3, REINTENTOS) == 0)
		{
			switch(opcion)
			{
			case 1: // DIRECCION
				if(utn_getNombre(auxDireccion.direccion, " > Ingrese la direccion: ", LEN_DIRECCION, REINTENTOS) == 0)
				{
					strncpy(unCensista->direccion.direccion, auxDireccion.direccion, LEN_DIRECCION);
					retorno = 0;
				}
				break;
			case 2: // NUMERO DE DIRECCION
				if(utn_getInt(&auxDireccion.numero, " > Ingrese el Nro de direccion: ", ERROR_MSJ, 1, LIMITE_DIRECCION_NUMERO, REINTENTOS) == 0)
				{
					unCensista->direccion.numero = auxDireccion.numero;
					retorno = 0;
				}
				break;
			}
		}
	}while(opcion != 3);

	return retorno;
}

/**
 * @fn int subMenuModificacion(Censista*)
 * @brief Muestra un submenu para modificar a seleccion,
 * 		  los datos generales correspondientes a un usuario Censista.
 *
 * @param unCensista: Tipo de dato estructura Censista a emplear.
 * @return 0 == OK || -1 == ERROR!
 */
static int subMenuModificacion(Censista* unCensista)
{
	int retorno = -1;
	Censista auxCensista;
	int opcion;

	do
	{
		utn_getInt(&opcion, MSJ_MODI_INPUT_SUBMENU, ERROR_MSJ, 1, 6, REINTENTOS);
		switch(opcion)
		{
			case 1: // NOMBRE
				if(utn_getNombre(auxCensista.nombre, MSJ_INPUT_NOMBRE, LEN_NOMBRE, REINTENTOS) == 0)
				{
					strncpy(unCensista->nombre, auxCensista.nombre, LEN_NOMBRE);
					printf(" ~ OK! Se modifico el nombre a %s\n", unCensista->nombre);
					retorno = 0;
					break;
				}
				break;
			case 2: // APELLIDO
				if(utn_getNombre(auxCensista.apellido, MSJ_INPUT_APELLIDO, LEN_NOMBRE, REINTENTOS) == 0)
				{
					strncpy(unCensista->apellido, auxCensista.apellido, LEN_NOMBRE);
					printf(" ~ OK! Se modifico el apellido a %s\n", unCensista->apellido);
					retorno = 0;
					break;
				}
				break;
			case 3: // FECHA DE NACIMIENTO
				if(subMenuCampoFecha(unCensista) == 0)
				{
					retorno = 0;
				}
				break;
			case 4: // DIRECCION
				if(subMenuCampoDireccion(unCensista) == 0)
				{
					retorno = 0;
				}
				break;
			case 5: // ESTADO
				if(utn_getInt(&opcion, MSJ_INPUT_ESTADO, ERROR_MSJ, 1, 4, REINTENTOS) == 0)
				{
					switch(opcion)
					{
					case ACTIVO:
						unCensista->estado = ACTIVO;
						retorno = 0;
						break;
					case INACTIVO:
						unCensista->estado = INACTIVO;
						retorno = 0;
						break;
					case LIBERADO:
						unCensista->estado = LIBERADO;
						retorno = 0;
						break;
					}
				}
				break;
			case 6: // SALIR
				retorno = 0;
				break;
		}
	}while(opcion != 6);

	return retorno;
}

// ----------------------------------------------------------------------- //

/**
 * @fn void altaForzadaCensista(Censista[], int, char*, char*, int, int, int, char*, int, int)
 * @brief Realiza la carga de datos forzados para harcodeo/testing del programa.
 *
 * @param pArray: Array del tipo de dato estructura Censista a asignar los datos forzados.
 * @param index: Indice o posicion del dato a guardar.
 * @param nombre: Campo nombre a forzar.
 * @param apellido: Campo apellido a forzar.
 * @param fechaDia: Campo dia a forzar.
 * @param fechaMes: Campo mes a forzar.
 * @param fechaAnio: Campo anio a forzar.
 * @param direccion: Campo nombre de direccion a forzar.
 * @param direccionNumero: Campo numero de direccion a forzar.
 * @param estado: Campo estado a forzar.
 */
static void altaForzadaCensista(Censista pArray[], int index,
		char* nombre,
		char* apellido,
		int fechaDia,
		int fechaMes,
		int fechaAnio,
		char* direccion,
		int direccionNumero,
		int estado,
		int asignacion)
{
	strncpy(pArray[index].nombre, nombre, LEN_NOMBRE);
	strncpy(pArray[index].apellido, apellido, LEN_NOMBRE);
	pArray[index].fechaNacimiento.dia = fechaDia;
	pArray[index].fechaNacimiento.mes = fechaMes;
	pArray[index].fechaNacimiento.anio = fechaAnio;
	pArray[index].edad = calcularEdad(pArray[index].fechaNacimiento.anio, LIMITE_ANIO_MAXIMO);
	strncpy(pArray[index].direccion.direccion, direccion, LEN_DIRECCION);
	pArray[index].direccion.numero = direccionNumero;
	pArray[index].idCencista = autoincrementarIdCencista();
	pArray[index].estado = estado;
	pArray[index].idZona = asignacion;
	pArray[index].isEmpty = 0;
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
						mostrarZonaEncontrada(arrayZonas[auxIndex], MSJ_ALTA_ZONA_CONFIRMACION);
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
					listarZonas(arrayZonas, LEN_ZONAS);
					break;
				case 9: // SALIR
					printf(MSJ_FINAL);
					break;
			}

		}while(opcion != 9);

}

/**
 * @fn int inicializarCensista(Cencista[], int)
 * @brief Inicializa los campos isEmpty(estaVacio) en 1,
 * 		  correspondientes al array del tipo de dato estructura Cencista.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
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

/**
 * @fn int cargarCensista(Censista[], int)
 * @brief Realiza el alta de un usuario Censista.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return 0 == OK || -1 == ERROR!
 */
int cargarCensista(Censista pArray[], int len)
{
	int retorno = -1;
	int index;
	Censista auxCensista;
	eDireccion auxDireccion;
	eFecha auxFecha;

	if(pArray != NULL && len > 0)
	{
		index = buscarEspacioLibre(pArray, len);
		if(index != -1)
		{
			if(	utn_getNombre(auxCensista.nombre, MSJ_INPUT_NOMBRE, LEN_NOMBRE, REINTENTOS) == 0 &&
				utn_getNombre(auxCensista.apellido, MSJ_INPUT_APELLIDO, LEN_NOMBRE, REINTENTOS) == 0 &&
				utn_getFecha(&auxFecha, MSJ_INPUT_FECHA, LIMITE_ANIO_MINIMO, LIMITE_ANIO_MAXIMO) == 0 &&
				utn_getDireccion(&auxDireccion, MSJ_INPUT_DIRECCION, MSJ_INPUT_NUMERO_DE_DIRECCION) == 0)
			{
				strncpy(pArray[index].nombre, auxCensista.nombre, LEN_NOMBRE);
				strncpy(pArray[index].apellido, auxCensista.apellido, LEN_NOMBRE);
				pArray[index].fechaNacimiento = auxFecha;
				pArray[index].edad = calcularEdad(pArray[index].fechaNacimiento.anio, LIMITE_ANIO_MAXIMO);
				pArray[index].direccion = auxDireccion;
				pArray[index].idCencista = autoincrementarIdCencista();
				pArray[index].estado = ACTIVO;
				pArray[index].idZona = 0;
				pArray[index].isEmpty = 0;

				mostrarCensistaEncontrado(pArray[index], MSJ_ALTA);

				retorno = 0;
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
 * @fn int bajaCensista(Censista[], int, int)
 * @brief  Realiza la baja logica de un usuario Censista.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @param idCencista: Campo a comparar/buscar en array.
 * @return 0 == OK || -1 == ERROR!
 */
int bajaCensista(Censista pArray[], int len, int idCencista)
{
	int retorno = -1;
	int index;
	int respuesta;

	if(pArray != NULL && len > 0 && idCencista > 0)
	{
		index = buscarIndexPorId(pArray, len, idCencista);
		if(index != -1)
		{
			mostrarCensistaEncontrado(pArray[index], MSJ_BAJA_PREGUNTA);

			respuesta = utn_getRespuesta(MSJ_INPUT_RESPUESTA);
			if(respuesta == 1)
			{
				pArray[index].isEmpty = 1;
				retorno = 0;
			}
			else if(respuesta == 2)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

/**
 * @fn int modificarCensista(Censista[], int, int)
 * @brief  Realiza la modificacion de los datos correspondientes a un usuario Censista.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @param idCencista: Campo a comparar/buscar en array.
 * @return 0 == OK || -1 == ERROR!
 */
int modificarCensista(Censista pArray[], int len, int idCencista)
{
	int retorno = -1;
	int index;
	int respuesta;

	if(pArray != NULL && len > 0 && idCencista > 0)
	{
		index = buscarIndexPorId(pArray, len, idCencista);
		if(index != -1)
		{
			mostrarCensistaEncontrado(pArray[index], MSJ_MODI_PREGUNTA);
			respuesta = utn_getRespuesta(MSJ_INPUT_RESPUESTA);
			if(respuesta == 1)
			{
				if(subMenuModificacion(&pArray[index]) == 0)
				{
					retorno = 0;
				}
			}
			else if(respuesta == 2)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

/**
 * @fn void mostrarCensista(Censista)
 * @brief Muestra los datos de un usuario Censista.
 *
 * @param unCensista: Tipo de dato estructura Censista a mostrar.
 */
void mostrarCensista(Censista unCensista)
{
	char auxEstadoCencista[10];
	char auxEstadoAsignacionZona[15];

	switch(unCensista.estado)
	{
		case ACTIVO:
			strcpy(auxEstadoCencista, "ACTIVO");
			break;
		case INACTIVO:
			strcpy(auxEstadoCencista, "INACTIVO");
			break;
		case LIBERADO:
			strcpy(auxEstadoCencista, "LIBERADO");
			break;
	}

	if(unCensista.idZona == 0)
	{
		strcpy(auxEstadoAsignacionZona, "NINGUNA");
	}
	else
	{
		sprintf(auxEstadoAsignacionZona, "%d", unCensista.idZona);
	}


	// ZONA ASIGNADA

	if(unCensista.isEmpty == 0)
	{
		printf(" | %-5d | %-15s | %-15s | %2d/%2d/%4d | %4d | %-20s %5d | %-8s | %-13s |\n",
				unCensista.idCencista,
				unCensista.nombre,
				unCensista.apellido,
				unCensista.fechaNacimiento.dia,
				unCensista.fechaNacimiento.mes,
				unCensista.fechaNacimiento.anio,
				unCensista.edad,
				unCensista.direccion.direccion,
				unCensista.direccion.numero,
				auxEstadoCencista,
				auxEstadoAsignacionZona);
	}
}

/**
 * @fn int listarCensistas(Censista[], int)
 * @brief Muestra el listado completo de los usuarios Censistas.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return 0 == OK || -1 == ERROR!
 */
int listarCensistas(Censista pArray[], int len)
{
	int retorno = -1;

	if(pArray != NULL && len > 0)
	{
		mostrarCabeceraDatoCensista();
		for (int i = 0; i < len; i++)
		{
			mostrarCensista(pArray[i]);
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int estaCargado(Censista[], int)
 * @brief Verifica que el si el campo isEmpty esta ocupado.
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return 1 == OCUPADO || 0 == SIN OCUPAR
 */
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

/**
 * @fn int ordenarCensistaPorCampo(Censista[], int)
 * @brief Ordena el array de acuerdo al campo nombre.
 *		  (En caso de igualdad, se ordena por campoxxx)
 *
 * @param pArray: Array del tipo de dato estructura Censista a recorrer.
 * @param len: Tamanio del array a recorrer.
 * @return 0 == OK || -1 == ERROR!
 */
int ordenarCensistaPorCampo(Censista pArray[], int len)
{
	int retorno = -1;
	int i;
	Censista auxCensista;
	int estaOrdenado;

	if (pArray != NULL && len > 0)
	{
		do
		{
			estaOrdenado = 1;
			len--;
			for (i = 0; i < len; i++)
			{
				if(strcmp(pArray[i].nombre, pArray[i + 1].nombre) < 0)
				{
					auxCensista = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = auxCensista;
					estaOrdenado = 0;
				}
				else if(strcmp(pArray[i].nombre, pArray[i + 1].nombre) == 0 &&
						pArray[i].apellido < pArray[i + 1].apellido)
				{
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = auxCensista;
					estaOrdenado = 0;
				}
			}
		}while (estaOrdenado == 0);
		retorno = 0;
	}

	return retorno;
}

int asignarCensistaAZona(Zona pArrayZonas[], int lenZonas, Censista pArrayCensistas[], int lenCensistas)
{
	int retorno = -1;
	int auxIdZona;
	int auxIdCensista;
	int index;

	listarZonas(pArrayZonas, lenZonas);
	if(utn_getInt(&auxIdZona, " > Ingrese el ID de la zona: ", ERROR_MSJ, VALOR_ID_ZONA, 9999, REINTENTOS) == 0)
	{
		listarCensistas(pArrayCensistas, lenCensistas);
		if(utn_getInt(&auxIdCensista, " > Ingrese el ID del censista a asignar: ", ERROR_MSJ, 1000, 9999, REINTENTOS) == 0)
		{
			index = buscarIndexPorId(pArrayCensistas, lenCensistas, auxIdCensista);
			pArrayCensistas[index].idZona = auxIdZona;
			retorno = 0;
		}
	}

	return retorno;
}

// 3:43 informes: acumulador, un contador, maximo, minimo




