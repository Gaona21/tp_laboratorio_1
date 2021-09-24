float IngresarEntero(char mensaje[]){
	float numeroIngresado;

		printf("%s",mensaje);
		scanf("%f",&numeroIngresado);

	return numeroIngresado;
}
void MostrarEntero(char mensaje[], int valor){

	printf("%s %d",mensaje,valor);
}

int DeterminarSimbolo(int numeroIngresado){
	int respuesta=1;

	if(numeroIngresado<0){
		respuesta = 0;
	}

	return respuesta;
}

int DeterminarParidad(int numeroIngresado){
	int respuesta = 1;
	int resto;

	resto = numeroIngresado%2;

	if(resto!=0){
		respuesta=0;
	}
	return respuesta;
}
//////////////////////////////////////////////////////////////////////////////////////////
float CalcularSuma(float numeroA, float numeroB){
	float suma;

	suma = numeroA+numeroB;

	return suma;
}

float CalcularResta(float numeroA, float numeroB){
	float resta;

	resta=numeroA-numeroB;

	return resta;
}

float CalcularMultiplicacion(float numeroA, float numeroB){
	int multiplicacion;

	multiplicacion = numeroA*numeroB;

	return multiplicacion;
}

float CalcularDivision(float numeroA, float numeroB){
	float division;

	division = numeroA/numeroB;

	return division;
}

float CalcularFactorial(float numero){
	float i;
	float factorial = 1;

	if(numero!=0){
		for(i=1; i<=numero; i++){
			factorial = factorial*i;
		}
	}else{
		factorial = 0;
	}
	return factorial;
}

