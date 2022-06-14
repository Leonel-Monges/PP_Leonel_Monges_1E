/*
 ============================================================================
 Name        : PP.c
 Author      : Leonel Monges
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

int main(void)
{
	setbuf(stdout, NULL);

	cargarMenuPrincipal();

	return EXIT_SUCCESS;
}




//	int respuesta;
//
//	while(1)
//	{
//		respuesta = utn_getRespuesta("> Ingrese S o N: ");
//		if(respuesta == 1)
//		{
//			printf(" Dijo que SI!");
//		}
//		else
//		{
//			printf(" Dijo que NO!");
//		}
//	}

//	eDireccion dire;
//
//	if(utn_getDireccion(&dire, " Ingrese direccion: ", " Ingrese numero de direccion: ") == 0)
//	{
//		printf("\nLa direccion es: %s %d", dire.direccion, dire.numero);
//	}
//	else
//	{
//		printf(" lo siento man");
//	}

//	char name[31];
//
//	utn_getNombre(name, " Ingresa un nombre pa: ", 31, 2);
//	printf("El nombre es: %s", name);

//	eFecha f;
//
//	if(utn_getFecha(&f, " Ingrese la fecha de nacimiento:\n", 1900, 2022) == 0)
//	{
//		printf("\nLa fecha actual es: %d/%d/%d", f.dia, f.mes, f.anio);
//	}
//	else
//	{
//		printf(" lo siento man");
//	}
