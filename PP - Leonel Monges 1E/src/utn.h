/*
 * utn.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Sistemas4
 */

#ifndef UTN_H_
#define UTN_H_

#define REINTENTOS 2
#define ERROR_MSJ " [x] Error!\n"
#define ERROR_MSJ_SOLO_NUMEROS " [x] Error! Se admite solo numeros!\n"
#define ERROR_MSJ_SOLO_LETRAS_NOMBRE " [x] Error! Se admite solo letras y espacios!\n"
#define ERROR_MSJ_MAS_DE_UN_CARACTER " [x] Error! Al menos se debe ingresar mas de un caracter!\n"
#define ERROR_REINTENTOS "\n [!] Lo sentimos! Intentelo mas tarde...\n <<< Redireccionando al menu principal...\n"
#define ERROR_MSJ_SOLO_SI_O_NO " [x] Error! Solo se admite ingresar s/S o n/N!\n"
#define LIMITE_BUFFER_STRING 2048
#define LEN_DIRECCION 64
#define MSJ_INGRESE_DIA " > Ingrese el dia: "
#define MSJ_INGRESE_MES " > Ingrese el mes: "
#define MSJ_INGRESE_ANIO " > Ingrese el anio: "

typedef struct
{
	int dia, mes, anio;
} eFecha;

typedef struct
{
	char direccion[LEN_DIRECCION];
	int numero;
} eDireccion;

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char rangoInicial, char rangoFinal, int reintentos);
int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos);
int utn_getAlfaNumerico(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos);
int utn_getNombre(char* pResultado, char* mensaje, int limite, int reintentos);
int utn_getPorcentaje(float* pResultado, float valorIngresado, float porcentaje, int opcion);
int utn_calcularOperacion(float* pResultado, float numero1, float numero2, int opcionOperacion);
int utn_getFecha(eFecha* fecha, char* mensaje, int desdeAnio, int hastaAnio);
int utn_getDireccion(eDireccion* direccion, char* mensajeDireccion, char* mensajeNumero);

int utn_getRespuesta(char* mensaje);

#endif /* UTN_H_ */
