#include <stdio.h>
#include <string.h>
#include "inputs.h"
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TRUE 1
#define FALSE 0
#define TN 51
#define TA 51

struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

/// @fn int initEmployees(Employee*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all position of the array
///
/// @param list
/// @param len
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initEmployees(Employee* list, int len);

/// @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// @brief add in a existing list of employees the values received as parameters in the first empty position
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/// @fn int findEmployeeById(Employee*, int, int)
/// @brief find an Employee by Id en returns the index position in array.
///
/// @param list
/// @param len
/// @param id
/// @return  Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
int findEmployeeById(Employee* list, int len,int id);

/// @fn int removeEmployee(Employee*, int, int)
/// @brief Remove a Employee by Id (put isEmpty Flag in 1)
///
/// @param list
/// @param len
/// @param id
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
int removeEmployee(Employee* list, int len, int id);

/// @fn int sortEmployees(Employee*, int, int)
/// @brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
///
/// @param list
/// @param len
/// @param order
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortEmployees(Employee* list, int len, int order);

/// @fn int printEmployees(Employee*, int)
/// @brief print the content of employees array
///
/// @param list
/// @param length
/// @return
int printEmployees(Employee* list, int length);

/// @fn void MostrarEmpleado(Employee)
/// @brief Muestra un empleado
///
/// @param list
void MostrarEmpleado(Employee list);

/// @fn int ModificarListaEmpleado(Employee*, int, int)
/// @brief pide un id y si lo encuentra modifica lo que es usuario pida.
///
/// @param list
/// @param tam
/// @param id
/// @return -1 si no pudo ejecutar y 0 si modifico correctamete.
int ModificarListaEmpleado(Employee* list,int tam, int id);

/// @fn int OrdenarEmpleadosPorApellido(Employee*, int)
/// @brief ordena la lista empleado por el apellido alfabeticamente y si son iguales lo ordena segun el sector.
///
/// @param list
/// @param tam
/// @return -1 si no ejecuto y 0 se ordeno correctamete.
int OrdenarEmpleadosPorApellido(Employee* list, int tam);

/// @fn int CalcularPromedio(Employee*, int, float*, int*, float*)
/// @brief calcula el total del salario, el promedio y cuantos empleados tienen un sueldo promedio en argentina.
///
/// @param list
/// @param tam
/// @param promedio
/// @param contadorSalarioPromedio
/// @param totalSalario
/// @return -1 si no pudo ejecutar y 0 si calculo correctamente.
int CalcularPromedio(Employee* list,int tam,float* promedio, int* contadorSalarioPromedio, float* totalSalario);

/// @fn int MostrarIdMayor(Employee*, int)
/// @brief Muestra el id mayor que hay en la lista empleado
///
/// @param list
/// @param len
/// @return retorna el id mayor y -1 si no encontro id mayor.
int MostrarIdMayor(Employee* list,int len);
#endif /* ARRAYEMPLOYEES_H_ */
