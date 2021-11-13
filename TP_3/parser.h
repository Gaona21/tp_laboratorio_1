#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


/// @fn int parser_idEmployeeFrmomtxt(FILE*, LinkedList*, char*)
/// @brief parsea el dato y lo devuelve por puntero
///
/// @param pFile
/// @param pArrayListEmployee
/// @param idtxt
/// @return -1 si no pudo leer el archio y0 si pudo leer el dato.
int parser_idEmployeeFrmomtxt(FILE* pFile , LinkedList* pArrayListEmployee, char* idtxt);

#endif /* PARSER_H_ */
