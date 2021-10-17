#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nexo.h"

#define T 5
#define TN 51
#define TA 51

int main(void) {

	setbuf(stdout,NULL);

	Employee listEmploye[T];
	int opcion;
	int respuesta;

	initEmployees(listEmploye,T);

	do{
		MostrarMenu();
		respuesta = getNumero(&opcion,"OPCION: ");

		if(respuesta == 0 && opcion!=5 ){
			EjecutarOpcion(listEmploye,T,opcion);
		}
	}while(opcion!=5);

	return EXIT_SUCCESS;
}
