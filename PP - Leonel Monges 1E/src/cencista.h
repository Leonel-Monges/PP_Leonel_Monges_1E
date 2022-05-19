/*
 * cencista.h
 *
 *  Created on: 17 may. 2022
 *      Author: Sistemas4
 */

#ifndef CENCISTA_H_
#define CENCISTA_H_

#define VALOR_INICIAL 1000
#define LEN_NOMBRE 30
#define INACTIVO 0
#define ACTIVO 1

//277589

typedef struct {
	int idCencista;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_NOMBRE];
	eFecha fechaNacimiento;
	int edad;
	eDireccion direccion;
	int isEmpty;
}Censista;

int inicializarCensista(Censista pArray[], int len);
int cargarCensista(Censista pArray[], int len);
int bajaCensista(Censista pArray[], int len, int idCencista);
int modificarCensista(Censista pArray[], int len, int idCencista);
void mostrarCensista(Censista unCencista);
int listarCensista(Censista pArray[], int len);

#endif /* CENCISTA_H_ */
