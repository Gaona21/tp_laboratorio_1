/*
Emanuel Gaona Correa
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	char opcion;
	float numeroA;
	float numeroB;

	float suma;
	float resta;
	float division;
	float multiplicacion;
	float factorialA;
	float factorialB;
	int flagInicIalizarValor = 1;
	setbuf(stdout,NULL);

	do{
		printf("\tMENU");
		if(flagInicIalizarValor == 1){
			flagInicIalizarValor = 0;
			numeroA = 0;
			numeroB = 0;
			printf("\n1.Ingresar 1er operando (A=x)");
			printf("\n2.Ingresar 2do operando (B=y)");

		}else{
			printf("\n1.Ingresar 1er operando (A=%.2f)",numeroA);
			printf("\n2.Ingresar 2do operando (B=%.2f)",numeroB);
		}

		printf("\n3.Calcular todas las operaciones");

		printf("\n4.Informar resultados");

		printf("\n5.Salir");

		printf("\nOpcion: ");
		fflush(stdin);
		scanf("%c",&opcion);

		switch(opcion){
		case '1':
			numeroA = IngresarEntero("\nIngresar 1er operando: ");
			break;

		case '2':
			numeroB = IngresarEntero("\nIngresar 2do operando: ");
			break;

		case '3':

			if(numeroA == 0 && numeroB == 0){
				printf("\nTodavia no ingreso valores a calcular\n\n");
			}else{

			suma=CalcularSuma(numeroA, numeroB);
			resta = CalcularResta(numeroA, numeroB);
			division = CalcularDivision(numeroA, numeroB);
			multiplicacion = CalcularMultiplicacion(numeroA, numeroB);
			factorialA = CalcularFactorial(numeroA);
			factorialB = CalcularFactorial(numeroB);

			printf("\n a)Calcular la suma (%.2f+%.2f)",numeroA,numeroB);
			printf("\n b)Calcular la resta (%.2f-%.2f)",numeroA,numeroB);
			printf("\n c)Calcular la division (%.2f/%.2f)",numeroA,numeroB);
			printf("\n d)Calcular la multiplicacion (%.2f*%.2f)",numeroA,numeroB);
			printf("\n e)Calcular el factorial  (%.2f!)",numeroA);
			printf("\n f)Calcular el factorial (%.2f!) \n\n",numeroB);

			}

			break;

		case '4':
			printf("\n a)El resultado de %.2f+%.2f es: %.2f",numeroA,numeroB,suma);
			printf("\n b)El resultado de %.2f-%.2f es: %.2f",numeroA,numeroB,resta);

			if(numeroB==0){
				printf("\n No es posible dividir por cero");
			}else{
				printf("\n c)El resultado de %.2f/%.2f es:  %.2f ",numeroA,numeroB,division);
			}

			printf("\n d)El resultado de %.2f*%.2f es: %.2f",numeroA,numeroB,multiplicacion);

			if((numeroA<15 && numeroB<15) && (numeroA>=0 && numeroB>=0)){
					printf("\n e)El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f\n\n",numeroA,factorialA,numeroB,factorialB);
			}else{
				printf(" \ne)Lo siento!! No puedo calcular el factorial de un numero mayor a 14 ni de negativos.\n\n");
			}

			break;

		case '5':
			break;

		default: printf("\nOpcion incorrecta\n\n");

		}

	}while(opcion!='5');

	return EXIT_SUCCESS;
}
