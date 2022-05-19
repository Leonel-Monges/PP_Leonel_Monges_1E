/*
 * utn.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Sistemas4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static int myGets(char* cadena, int len);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena, int limite);
static int esLetra(char* caracter);
static int esNombreValido(char* cadena, int limite);
static int esAlfaNumerico(char* cadena, int limite);
static int esSioNo(int opcion);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);

/**
 * @fn int myGets(char*, int)
 * @brief myGets(): Recibe un string con limite.
 *
 * @param char* cadena: Cadena donde dejo la informacion.
 * @param int longitud: Cuantos caracteres quiero leer.
 * @return 0 == OK || -1 == ERROR!
 */
static int myGets(char* cadena, int len)
{
	int retorno = -1;

	if(cadena != NULL && len > 0)
	{
		fflush(stdin); //__fpurge(stdin); Linux
		fgets(cadena, len, stdin);
		cadena[strlen(cadena)-1] = '\0';
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int esNumerica(char*)
 * @brief Recibe una cadena de caracteres y devuelve 1
 * 		  en el caso de que el texto este compuesto solo por números.
 *
 * @param cadena: Cadena de caracteres a ser analizada.
 * @param limite: Limite de la cadena a ser analizada.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // Valor en OK!

	if(cadena != NULL && limite > 0 && strlen(cadena) > 0)
	{
		for(int i = 0; i < limite && cadena[i] != '\0' ; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0; // Valor en ERROR!
				break;
			}
		}
	}

	return retorno;
}

/**
 * @fn int esFlotante(char*)
 * @brief Verifica si la cadena/buffer son solo numeros flotantes
 *        (Se incluyen ejemplos como: 3.14 +3.14 -3.14 .314 +.314 -.314 314. +314. -314.)
 * @param cadena: Cadena de caracteres a ser analizada.
 * @param limite: Limite de la cadena a ser analizada.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int esFlotante(char* cadena, int limite)
{
	int retorno = 1; // Valor en OK!
	int i = 0;
	int contadorPuntos = 0; // No tiene que haber mas de 2 puntos.

	if(cadena != NULL && limite > 0 && strlen(cadena) > 0)
	{
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0; // Valor en ERROR!
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * @fn int esLetra(char*)
 * @brief Verifica si la variable es una letra.
 *
 * @param caracter: Variable char a verificar.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int esLetra(char* caracter)
{
	int respuesta = 1; // Valor en OK!

	if(caracter != NULL)
	{
		if(	(*caracter < 'a' || *caracter > 'z') &&
			(*caracter < 'A' || *caracter > 'Z'))
		{
			respuesta = 0; // Valor en ERROR!
		}
	}

	return respuesta;
}

/**
 * @fn int esNombreValido(char*, int)
 * @brief Verifica si la cadena esta compuesto por letras y espacios
 * 		  para nombres.
 *
 * @param cadena: Cadena a analizar.
 * @param limite: Indica la cantidad de caracteres maxima de la cadena.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int esNombreValido(char* cadena, int limite)
{
	int respuesta = 1; // Valor en OK!

	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i <= limite && cadena[i] != '\0'; i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				 cadena[i] != ' ')
			{
				respuesta = 0; // Valor en ERROR!
				break;
			}
		}
	}

	return respuesta;
}

/**
 * @fn int esAlfaNumerico(char*, int)
 * @brief Verifica si la cadena/buffer son solo letras y numeros
 * 		  (incluye tambien los espacios  y guiones).
 * @param cadena: Cadena a analizar.
 * @param limite: Indica la cantidad de caracteres maxima de la cadena.
 * @return 1 == OK/SI || 0 == ERROR!/NO
 */
static int esAlfaNumerico(char* cadena, int limite)
{
	int respuesta = 1; // Valor en OK!

	if(cadena != NULL && limite > 0 && strlen(cadena) > 0)
	{
		for(int i = 0; i <= limite && cadena[i] != '\0'; i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				(cadena[i] < '0' || cadena[i] > '9'))
			{
				respuesta = 0; // Valor en ERROR!
				break;
			}
		}
	}

	return respuesta;
}

/**
 * @fn int esSioNo(int)
 * @brief Verifica que el caracter sea s/S o n/N.
 *
 * @param opcion: Caracter ingresado a analizar.
 * @return 1 == SI || 0 == NO
 */
static int esSioNo(int opcion)
{
	int retorno = -1;

	switch(opcion)
	{
		case 's':
		case 'S':
			retorno = 1;
			break;
		case 'n':
		case 'N':
			retorno = 2;
			break;
	}

	return retorno;
}

/**
 * @fn int getInt(int*)
 * @brief Obtiene el dato como una cadena de caracteres, para luego
 * 	      validarlo y parsear/formatear el dato a una variable entera.
 *
 * @param pResultado: Puntero a entero, con el valor a setear.
 * @return 1 == OK
 */
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(	myGets(buffer, sizeof(buffer)) == 0 &&
		esNumerica(buffer, sizeof(buffer)) == 1)
	{
		*pResultado = atoi(buffer);
		retorno = 1;
	}

	return retorno;
}

/**
 * @fn int getFloat(float*)
 * @brief Obtiene el dato como una cadena de caracteres, para luego
 * 	      validarlo y parsear/formatear el dato a una variable flotante.
 *
 * @param pResultado: Puntero a entero, con el valor a setear.
 * @return 1 == OK
 */
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(	myGets(buffer, sizeof(buffer)) == 0 &&
		esFlotante(buffer, sizeof(buffer)) == 1)
	{
		*pResultado = atof(buffer);
		retorno = 1;
	}

	return retorno;
}

// ---------------------------------------------------------------------------------------- //

/**
 * @fn int utn_getInt(int*, char*, char*, int, int, int)
 * @brief Solicita un número entero al usuario y lo valida.
 *
 * @param pResultado: Puntero a entero donde se escribirá
 * 		  			  el valor ingresado en el caso de ser correcto.
 * @param mensaje: Puntero a cadena de caracteres con mensaje
 * 				   a imprimir antes de pedirle al usuario datos por consola.
 * @param mensajeError: Puntero a cadena de caracteres con mensaje de error
 * 						en el caso de que el dato ingresado no sea válido.
 * @param minimo: Valor mínimo admitido (inclusive).
 * @param maximo: Valor máximo admitido (inclusive).
 * @param reintentos: Cantidad de veces que se le volverá a pedir al usuario
 * 					  que ingrese un dato en caso de error.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(	pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 1)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					retorno = 0;
					*pResultado = bufferInt;
					break;
				}
				else
				{
					fflush(stdin);
					reintentos--;
					printf(mensajeError);
					printf(" [!] Solo se admiten valores del %d al %d!\n", minimo, maximo);
				}
			}
			else
			{
				fflush(stdin);
				reintentos--;
				printf(ERROR_MSJ_SOLO_NUMEROS);
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/**
 * @fn int utn_getFloat(float*, char*, char*, int, int, int)
 * @brief Solicita un número entero al usuario y lo valida.
 *
 * @param pResultado: Puntero a flotante donde se escribirá
 * 		  			  el valor ingresado en el caso de ser correcto.
 * @param mensaje: Puntero a cadena de caracteres con mensaje
 * 				   a imprimir antes de pedirle al usuario datos por consola.
 * @param mensajeError: Puntero a cadena de caracteres con mensaje de error
 * 						en el caso de que el dato ingresado no sea válido.
 * @param minimo: Valor mínimo admitido (inclusive).
 * @param maximo: Valor máximo admitido (inclusive).
 * @param reintentos: Cantidad de veces que se le volverá a pedir al usuario
 * 					  que ingrese un dato en caso de error.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(	pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 1)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					retorno = 0;
					*pResultado = bufferFloat;
					break;
				}
				else
				{
					fflush(stdin);
					reintentos--;
					printf("%s", mensajeError);
					printf(" [!] Solo se admiten valores del %d al %d!\n", minimo, maximo);
				}
			}
			else
			{
				fflush(stdin);
				reintentos--;
				printf(ERROR_MSJ_SOLO_NUMEROS);
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/**
 * @fn int utn_getChar(char*, char*, char*, int)
 * @brief Solicita un caracter al usuario.
 *
 * @param pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * @param mensaje: Es el mensaje a ser mostrado al usuario.
 * @param mensajeError: Es el mensaje de error a ser mostrado al usuario.
 * @param rangoInicial: Rango minimo de letras admitido.
 * @param rangoFinal: Rango maximo de letras admitido.
 * @param reintentos: Cantidad de oportunidades para ingresar el dato.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char rangoInicial, char rangoFinal, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(	pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		rangoInicial <= rangoFinal &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			bufferChar = getchar();
			if(	esLetra(&bufferChar) == 1 &&
				bufferChar >= rangoInicial &&
				bufferChar <= rangoFinal)
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/**
 * @fn int utn_getString(char*, char*, char*, int, int)
 * @brief Solicita un texto/cadena al usuario.
 *
 * @param pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * @param mensaje: Es el mensaje a ser mostrado al usuario.
 * @param mensajeError: Es el mensaje de error a ser mostrado al usuario.
 * @param limite: Indica la cantidad de letras maxima de la cadena.
 * @param reintentos: Cantidad de oportunidades para ingresar el dato.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];

	if(	pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		limite > 0 &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(	myGets(bufferString,sizeof(bufferString)-1) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1) <= limite)
			{
				strncpy(pResultado, bufferString, limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/**
 * @fn int utn_getNombre(char*, char*, char*, int, int)
 * @brief Solicita un nombre al usuario.
 *
 * @param mensaje: Es el mensaje a ser mostrado al usuario.
 * @param pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * @param limite: Indica la cantidad de letras maxima del nombre.
 * @param reintentos: Cantidad de oportunidades para ingresar el dato.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getNombre(char* pResultado, char* mensaje, int limite, int reintentos)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];

	if(	pResultado != NULL &&
		mensaje != NULL &&
		limite > 0 &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(	myGets(bufferString,sizeof(bufferString)-1) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1) <= limite)
			{
				if(esNombreValido(bufferString,limite) == 1)
				{
					if(strlen(bufferString) > 1) // Valida que tenga al menos mas de 1 caracter para un nombre.
					{
						strlwr(bufferString); // Convierto toda a minusculas.
						bufferString[0] = toupper(bufferString[0]); // Capitalizo el primer caracter.
						strncpy(pResultado,bufferString,limite);
						retorno = 0;
						break;
					}
					else
					{
						printf(ERROR_MSJ_MAS_DE_UN_CARACTER);
						reintentos--;
					}
				}
				else
				{
					printf(ERROR_MSJ_SOLO_LETRAS_NOMBRE);
					reintentos--;
				}
			}
//			else
//			{
//				printf("%s", mensajeError);
//				reintentos--;
//			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/**
 * @fn int utn_getAlfaNumerico(char*, char*, char*, int, int)
 * @brief Solicita una cadena alfanumerica al usuario.
 *
 * @param pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * @param mensaje: Es el mensaje a ser mostrado al usuario.
 * @param mensajeError: Es el mensaje de error a ser mostrado al usuario.
 * @param limite: Indica la cantidad de letras maxima de la cadena.
 * @param reintentos: Cantidad de oportunidades para ingresar el dato.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getAlfaNumerico(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER_STRING];

	if(	pResultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		limite > 0 &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(	myGets(bufferString, sizeof(bufferString)-1) == 0 &&
				strnlen(bufferString, sizeof(bufferString)-1) <= limite &&
				esAlfaNumerico(bufferString, sizeof(bufferString)-1) == 1)
			{
				strncpy(pResultado, bufferString, limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * @fn int utn_getPorcentaje(float*, int, float, int)
 * @brief Realiza el incremento/decremento de un valor numerico,
 * 		  ingresando el porcentaje solicitado.
 *
 * @param pResultado: Puntero a flotante, con el valor a setear.
 * @param valorIngresado: Valor original a emplear.
 * @param porcentaje: Valor del porcentaje a emplear.
 * @param opcion: 0 para Incremento || 1 para Decremento.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getPorcentaje(float* pResultado, float valorIngresado, float porcentaje, int opcion)
{
	int retorno = -1;

	if(pResultado != NULL && valorIngresado > 0 && porcentaje > 0)
	{
		switch(opcion)
			{
				case 0:
					valorIngresado = valorIngresado + (valorIngresado * porcentaje);
					*pResultado = valorIngresado;
					retorno = 0;
					break;
				case 1:
					valorIngresado = valorIngresado - (valorIngresado * porcentaje);
					*pResultado = valorIngresado;
					retorno = 0;
					break;
			}
	}

	return retorno;
}

/**
 * @fn int utn_calcularOperacion(float*, float, float, int)
 * @brief Realiza la operacion matematica de 2 valores numericos,
 *		  contando con la seleccion de dicha operacion que el usuario estipule.
 *
 * @param pResultado: Puntero a flotante, con el valor de la operacion realizada a setear.
 * @param numero1: Primer valor numerico a pasar para dicha operacion.
 * @param numero2: Segundo valor numerico a pasar para dicha operacion.
 * @param operacion: Opciones a elegir para cada operacion (1-4)
 * 					1. + (Suma)
 *		  			2. - (Resta)
 *		  			3. * (Multiplicacion)
 *		  			4. / (Division)
 * @return 0 = OK || -1 = ERROR!
 */
int utn_calcularOperacion(float* pResultado, float numero1, float numero2, int opcionOperacion)
{
	int resultado = -1;
	float bufferResultado;

	if(pResultado != NULL && opcionOperacion > 0 && opcionOperacion <= 4)
	{
		switch(opcionOperacion)
		{
		case 1: // Suma
			bufferResultado = numero1 + numero2;
			*pResultado = bufferResultado;
			resultado = 0;
			break;
		case 2: // Resta
			bufferResultado = numero1 - numero2;
			*pResultado = bufferResultado;
			resultado = 0;
			break;
		case 3: // Multiplicacion
			bufferResultado = numero1 * numero2;
			*pResultado = bufferResultado;
			resultado = 0;
			break;
		case 4: // Division
			if(numero2 != 0)
			{
				bufferResultado = numero1 / numero2;
				*pResultado = bufferResultado;
				resultado = 0;
			}
			else
			{
				printf(" [x] Error! El divisor no puede ser 0!\n");
			}
			break;
		}
	}

	return resultado;
}

/**
 * @fn int utn_getFecha(eFecha*, char*, int, int)
 * @brief Solicita los datos correspondientes a una fecha.
 *
 * @param fecha: Puntero a estructura fecha.
 * @param mensaje: Es el mensaje a ser mostrado al usuario.
 * @param desdeAnio: Rango minimo de anio admitido.
 * @param hastaAnio: Rango maximo de anio admitido.
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getFecha(eFecha* fecha, char* mensaje, int desdeAnio, int hastaAnio)
{
	int retorno = -1;
	eFecha auxFecha;

	if(fecha != NULL && mensaje != NULL)
	{
		printf(mensaje);
		if(	utn_getInt(&auxFecha.dia, MSJ_INGRESE_DIA, ERROR_MSJ, 1, 31, REINTENTOS) == 0 &&
			utn_getInt(&auxFecha.mes, MSJ_INGRESE_MES, ERROR_MSJ, 1, 12, REINTENTOS) == 0 &&
			utn_getInt(&auxFecha.anio, MSJ_INGRESE_ANIO, ERROR_MSJ, desdeAnio, hastaAnio, REINTENTOS) == 0)
		{
			fecha->dia = auxFecha.dia;
			fecha->mes = auxFecha.mes;
			fecha->anio = auxFecha.anio;
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @fn int utn_getDireccion(eDireccion*, char*, char*)
 * @brief
 *
 * @param direccion:
 * @param mensajeDireccion:
 * @param mensajeNumero:
 * @return 0 == OK || -1 == ERROR!
 */
int utn_getDireccion(eDireccion* direccion, char* mensajeDireccion, char* mensajeNumero)
{
	int retorno = -1;
	eDireccion auxDireccion;

	if(	direccion != NULL &&
		mensajeDireccion != NULL &&
		mensajeNumero != NULL)
	{
		if(	utn_getNombre(auxDireccion.direccion, mensajeDireccion, LEN_DIRECCION, REINTENTOS) == 0 &&
			utn_getInt(&auxDireccion.numero, mensajeNumero, ERROR_MSJ, 1, 99999, REINTENTOS) == 0)
		{
			strncpy(direccion->direccion, auxDireccion.direccion, LEN_DIRECCION);
			direccion->numero = auxDireccion.numero;
//			printf(" Direccion ingresada: %s %d", direccion->direccion, direccion->numero);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @fn int utn_getRespuesta(char*)
 * @brief Solicita una respuesta al usuario, ingresando solo s/S o n/N
 *
 * @param mensaje: Es el mensaje a ser mostrado al usuario.
 * @return 1 == SI || 2 == NO || -1 == ERROR!
 */
int utn_getRespuesta(char* mensaje)
{
	char opcion;
	int retorno;
	int reintentos = 3;

	if(mensaje != NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			opcion = getchar();
			if(esSioNo(opcion) == 1) // SI
			{
				retorno = 1;
				break;
			}
			else if(esSioNo(opcion) == 2) // NO
			{
				retorno = 2;
				break;
			}
			else
			{
				reintentos--;
				printf(ERROR_MSJ_SOLO_SI_O_NO);
			}
		}while(reintentos > 0);
	}

	return retorno;
}
