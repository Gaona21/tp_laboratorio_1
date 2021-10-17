#include "arrayEmployees.h"
#ifndef NEXO_H_
#define NEXO_H_

/// @fn void MostrarMenu()
/// @brief muestra el menu de opciones
///
void MostrarMenu();

/// @fn void EjecutarOpcion(Employee*, int, int)
/// @brief segun la opcion que eligio el usuario va a ejecutar y mostrarle los datos.
///
/// @param list
/// @param len
/// @param opcion
void EjecutarOpcion(Employee* list, int len,int opcion);

void MostrarCasoUno(Employee* list, int len);
void MostrarCasoDos(Employee* list,int len);
void MostrarCasoTres(Employee* list, int len);
void MostrarCasoCuatro(Employee* list, int len);

#endif /* NEXO_H_ */
