#include <stdio.h>
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_


/// @fn float IngresarEntero(char[])
/// @brief esta funcio sirve para ingresar un numero
///
/// @param pide ingresar un mensaje que se va a mostrar
/// @return retorna un numero con coma, el numero ingresando
float IngresarEntero(char []);

/// @fn void MostrarEntero(char[], int)
/// @brief Muestra un mensaje y el numero ingresado
///
/// @param pide ingresar el mensaje que se va a mostrar
/// @param el numero que se va a mostrar
void MostrarEntero(char [], int);

/// @fn int DeterminarSimbolo(int)
/// @brief determina si es negativo o positivo
///
/// @param toma el numero a determinar
/// @return retorna un 0 si es negativo o un 1 si es positivo
int DeterminarSimbolo(int);

/// @fn int DeterminarParidad(int)
/// @brief determina si el numero es par o impar
///
/// @param toma como valor un numero
/// @return retorna 1 si es par o 0 si es impar
int DeterminarParidad(int);

float CalcularSuma(float, float);
float CalcularResta(float, float);
float CalcularMultiplicacion(float, float);
float CalcularDivision(float, float);
float CalcularFactorial(float);

#endif /* BIBLIOTECA_H_ */
