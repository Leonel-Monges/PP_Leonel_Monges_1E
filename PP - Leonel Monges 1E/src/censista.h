/*
 * cencista.h
 *
 *  Created on: 17 may. 2022
 *      Author: Sistemas4
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include "zona.h"

#define VALOR_ID 1000
#define LEN_CENSISTAS 10
#define LEN_NOMBRE 30

// Mensaje Inicio
#define MSJ_INPUT_MENU "\n\n --- PP Leonel Monges (1E) ---\n --- Sistema de censos 2022 ---\n\n 1. Ingresar datos de un nuevo censista\n 2. Modificar datos del censista\n 3. Eliminar datos de un censista\n 4. Cargar zona\n 5. Asignar  zona a censista\n 6. Carga de datos\n 7. Mostrar censistas.\n 8. Mostrar zonas\n 9. Salir\n\n > Ingrese opcion: "

// Campos Imputs
#define MSJ_INPUT_NOMBRE "\n > Ingrese nombre: "
#define MSJ_INPUT_APELLIDO " > Ingrese apellido: "
#define MSJ_INPUT_FECHA " ~ Ingrese los datos de su fecha de nacimiento:\n"
#define MSJ_INPUT_DIRECCION " > Ingrese direccion de domicilio: "
#define MSJ_INPUT_NUMERO_DE_DIRECCION " > Ingrese Nro de direccion: "
#define MSJ_INPUT_ESTADO "\n > Seleccione el estado del usuario censista:\n\n 1. ACTIVO\n 2. INACTIVO\n 3. LIBERADO\n 4. Salir\n\n > Ingrese opcion: "
#define MSJ_INPUT_ID "\n > Ingrese ID del usuario censista: "

// Fecha
#define LIMITE_ANIO_MINIMO 1900
#define LIMITE_ANIO_MAXIMO 2022

// Direccion
#define LIMITE_DIRECCION_NUMERO 99999

// Impresion de datos
#define CABECERA_ID "ID"
#define CABECERA_NOMBRE "NOMBRE"
#define CABECERA_APELLIDO "APELLIDO"
#define CABECERA_FECHA_NACIMIENTO "FECHA NAC."
#define CABECERA_EDAD "EDAD"
#define CABECERA_DIRECCION "DIRECCION & NUMERO"
#define CABECERA_ESTADO "ESTADO"
#define CABECERA_ASIGNACION "ZONA ASIGNADA"
#define CABECERA_LINEA_SEPARADORA " |-------|-----------------|-----------------|------------|------|----------------------------|----------|---------------|\n"

// ABM
#define MSJ_INPUT_RESPUESTA "\n > Ingrese s/S o n/N: "
#define MSJ_ALTA "\n ~ OK! Se creo un nuevo usuario censista con los siguientes datos:\n"

#define MSJ_BAJA_PREGUNTA "\n ~ OK! Desea eliminar los datos del usuario censista seleccionado?\n"
#define MSJ_BAJA_CONFIRMACION "\n ~ OK! Usuario censista eliminado!\n"
#define MSJ_BAJA_CONFIRMACION_ABORTADA "\n ~ OK! No se realizo la baja del usuario censista\n"

#define MSJ_MODI_PREGUNTA "\n ~ OK! Desea modificar los datos del usuario censista seleccionado?\n"
#define MSJ_MODI_CONFIRMACION "\n ~ OK! Datos actualizados!\n"
#define MSJ_MODI_CONFIRMACION_ABORTADA "\n ~ OK! No se realizo ninguna modificacion del usuario censista\n"
#define MSJ_MODI_INPUT_SUBMENU "\n Seleccione el campo o dato a modificar:\n\n 1. Nombre\n 2. Apellido\n 3. Fecha de Nacimiento\n 4. Direccion\n 5. Estado\n 6. Salir\n\n > Ingrese opcion: "
#define MSJ_MODI_INPUT_SUBMENU_FECHA "\n > Que campo de la fecha de nacimiento quisiera modificar?\n\n 1. Dia\n 2. Mes\n 3. Anio\n 4. Volver\n\n > Ingrese opcion: "
#define MSJ_MODI_INPUT_SUBMENU_DIRECCION "\n > Que campo de direccion quisiera modificar?\n\n 1. Direccion\n 2. Numero de direccion\n 3. Volver\n\n > Ingrese opcion: "
#define MSJ_MODI_SUBMENU_CONFIMACION_DIA "\n ~ Se realizo el cambio de dia!\n"
#define MSJ_MODI_SUBMENU_CONFIMACION_MES "\n ~ Se realizo el cambio de mes!\n"
#define MSJ_MODI_SUBMENU_CONFIMACION_ANIO  "\n ~ Se realizo el cambio de anio!\n"

// Otros
#define MSJ_ERROR_NO_HAY_ESPACIO " [x] Error! No hay espacio libre\n"
#define MSJ_FINAL "\n ~ Gracias!_Vuelva_prontos.jpg"
#define MSJ_ERROR_NO_SE_ENCONTRO_USUARIO " [x] Error! No se encontro al usuario censista!"
#define SI 0
#define NO 1

// Estado
#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

#define PENDIENTE 1

typedef struct {
	int idCencista;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_NOMBRE];
	eFecha fechaNacimiento;
	int edad;
	eDireccion direccion;
	int idZona;
	int estado;
	int isEmpty;
}Censista;

void cargarMenuPrincipal();
int buscarIndexPorId(Censista pArray[], int len, int idCencista);
int inicializarCensista(Censista pArray[], int len);
int cargarCensista(Censista pArray[], int len);
int bajaCensista(Censista pArray[], int len, int idCencista);
int modificarCensista(Censista pArray[], int len, int idCencista);
void mostrarCensista(Censista unCencista);
int listarCensistas(Censista pArray[], int len);

int asignarCensistaAZona(Zona pArrayZonas[], int lenZonas, Censista pArrayCensistas[], int lenCensistas);

//void altaForzadaCensista(Censista pArray[], int index,
//		char* nombre,
//		char* apellido,
//		int fechaDia,
//		int fechaMes,
//		int fechaAnio,
//		char* direccion,
//		int direccionNumero,
//		int estado);

#endif /* CENSISTA_H_ */
