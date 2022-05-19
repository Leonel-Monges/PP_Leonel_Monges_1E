/*
 * zona.h
 *
 *  Created on: May 18, 2022
 *      Author: Leo
 */

#ifndef ZONA_H_
#define ZONA_H_

// #include "censista.h"

#define LEN_ZONAS 10
#define LEN_CALLE 30
#define LEN_LOCALIDAD 20

#define VALOR_ID_ZONA 5000

#define MSJ_ZONA_INPUT_CALLE1 "\n > Ingrese el nombre de la calle N1: "
#define MSJ_ZONA_INPUT_CALLE2 "\n > Ingrese el nombre de la calle N2: "
#define MSJ_ZONA_INPUT_CALLE3 "\n > Ingrese el nombre de la calle N3: "
#define MSJ_ZONA_INPUT_CALLE4 "\n > Ingrese el nombre de la calle N4: "
#define MSJ_ZONA_INPUT_LOCALIDAD "\n > Seleccione la opcion correspondiente a la localidad:\n\n 1. QUILMES\n 2. BERNAL\n 3. EZPELETA\n 4. BERAZATEGUI\n 5. WILDE\n\n > Ingrese opcion: "

#define LOCALIDAD_1_QUILMES "QUILMES"
#define LOCALIDAD_2_BERNAL "BERNAL"
#define LOCALIDAD_3_EZPELETA "EZPELETA"
#define LOCALIDAD_4_BERAZATEGUI "BERAZATEGUI"
#define LOCALIDAD_5_WILDE "WILDE"

#define PENDIENTE 1
#define FINALIZADO 2

#define MSJ_ERROR_NO_HAY_ESPACIO " [x] Error! No hay espacio libre\n"


#define CABECERA_ID_ZONA "ID"
#define CABECERA_NOMBRE_APELLIDO_CENCISTA "CENCISTA ENCARGADO"
#define CABECERA_ESTADO "ESTADO"
#define CABECERA_LOCALIDAD "LOCALIDAD"
#define CABECERA_CALLE1 "CALLE 1"
#define CABECERA_CALLE2 "CALLE 2"
#define CABECERA_CALLE3 "CALLE 3"
#define CABECERA_CALLE4 "CALLE 4"
#define CABECERA_CANT_PRESENCIAL "CENS. PRESENCIAL"
#define CABECERA_CANT_VIRTUAL "CENS. VIRTUAL"
#define CABECERA_CANT_AUSENTES "CANT. AUSENTES"

#define CABECERA_LINEA_SEPARADORA_ZONA " |------|----------------------|------------|-------------|-----------------|-----------------|-----------------|-----------------|------------------|---------------|----------------|\n"

#define MSJ_ALTA_ZONA_CONFIRMACION "\n ~ Carga de Zona realizada!\n"

typedef struct
{
	int idZona;
	char calle1[LEN_CALLE];
	char calle2[LEN_CALLE];
	char calle3[LEN_CALLE];
	char calle4[LEN_CALLE];
	int localidad;
	int estadoZona; // PENDIENTE || FINALIZADO (si esta finalizado, el estado del censista es LIBERADO)
	int cantCensadosPresencial;
	int cantCensadosVirtual;
	int cantAusentes;
	int isEmpty;
} Zona;

int inicializarZona(Zona pArray[], int len);
int cargarZona(Zona pArray[], int len);
void formatearLocalidades(int numLocalidad, char* localidad);
void formatearEstadoZona(int numEstado, char* estado);
// void formatearAsignacionZona(int estado, Censista unCensista, char* asignacion);
void mostrarZona(Zona unaZona);

// int buscarIndexPorIdZona(Censista pArray[], int len, int idZona);

int listarZonas(Zona pArray[], int len);

void mostrarZonaEncontrada(Zona unaZona, char* mensaje);

void formatearCamposCensadosZona(int estado,
		int cantPresencial,
		int cantVirtual,
		int cantAusentes,
		char* strCantPresencial,
		char* strCantVirtual,
		char* strCantAusentes);

void altaForzadaZona(Zona pArray[], int index,
		char* calle1,
		char* calle2,
		char* calle3,
		char* calle4,
		int localidad,
		int estadoZona,
		int cantCensadosPresencial,
		int cantCensadosVirtual,
		int cantAusentes);

#endif /* ZONA_H_ */
