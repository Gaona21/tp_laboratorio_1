#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int respuesta;

	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListEmployee != NULL){
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){
			respuesta = parser_EmployeeFromText(pArchivo, pArrayListEmployee);

			if(respuesta == 0){
				printf("\nSe cargaron los datos correctamente.\n\n");
				retorno = 0;
			}
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int respuesta;

	FILE* pArchivo;

	if(path != NULL && pArrayListEmployee != NULL){
		pArchivo = fopen(path,"rb");

		if(pArchivo != NULL){
			respuesta = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
			if(respuesta == 0){
				printf("\nSe cargaron los datos correctamente.\n\n");
				retorno = 0;
			}
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

int cargarIdTxt(char* path , LinkedList* pArrayListEmployee){
	int retorno = -1;
	int respuesa;
	int idfinal;
	char auxId[11];

	FILE* pArchivo = NULL;

	if(path!=NULL && pArrayListEmployee!=NULL){
		pArchivo = fopen(path,"r");
		if(pArchivo!=NULL){
			respuesa = parser_idEmployeeFrmomtxt(pArchivo, pArrayListEmployee, auxId);
			if(respuesa == 0){
				idfinal = atoi(auxId);
				retorno = idfinal;
			}
		}
	}
	return retorno;
}

int guardarIdTxt(char* path , LinkedList* pArrayListEmployee,char* id){
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path!=NULL && pArrayListEmployee!=NULL){
		pArchivo = fopen(path,"w");

		if(pArchivo!=NULL){
			fprintf(pArchivo,"%s\n",id);
		}
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int respueta;
	int len;

	char id[50];
	char nombre[150];
	char horasTrabajadas[50];
	char sueldo[50];

	Employee* pEmpleado;

	if(pArrayListEmployee != NULL){
		pEmpleado = employee_new();

		len = ll_len(pArrayListEmployee);
		if(len>0){
			len = cargarIdTxt("id.txt", pArrayListEmployee);
			len++;
			sprintf(id,"%d",len);

			guardarIdTxt("id.txt", pArrayListEmployee,id);
			respueta = employee_addText(pEmpleado, id, nombre, horasTrabajadas, sueldo);

			if(respueta == 0){
				pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				respueta = ll_add(pArrayListEmployee, pEmpleado);

				if(respueta == 0){
					printf("\nSe guardo los datos del empleado.\n\n");
				}else{
					printf("\nNo se pudo guardar los datos del empleado.\n\n");
				}

			}
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idIngresado;
	int len;
	int opcion;
	int respuesta;

	int idEmpleado;

	Employee* pEmpleado = NULL;

	if(pArrayListEmployee){
		getNumero(&idIngresado, "ingrese el ID a buscar: ");

		len = ll_len(pArrayListEmployee);
		if(len>0){
			for(int i=0; i<len; i++){
				pEmpleado = ll_get(pArrayListEmployee, i);

				respuesta = employee_getId(pEmpleado, &idEmpleado);

				if(respuesta == 0){
					if(idEmpleado == idIngresado){
						employee_MostrarUnEmpleado(pEmpleado);

						printf("Menu Modificar:\n1.Nombre\n2.Horas\n3.Sueldo\n4.Salir\n");
						getNumero(&opcion,"Opcion:\n");

						switch (opcion) {
							case 1:
								GetString("Ingrese nombre: \n", pEmpleado->nombre, sizeof(pEmpleado->nombre));
								break;

							case 2:
								getNumero(&pEmpleado->horasTrabajadas, "Ingrese horas trabajadas: \n");
								break;

							case 3:
								getNumero(&pEmpleado->sueldo, "Ingrese sueldo: \n");
								break;
							default:
								printf("Opcion incorreta\n");
								break;
						}
						printf("\nSe modifico el empleado.\n\n");
						retorno = 0;
						break;
					}else{
						printf("\nNo se encontro el id ingresado.\n\n");
					}
				}
			}
		}else{
			printf("\nNo hay datos cargado.\n\n");
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int respuesta;
	int idIngresado;
	int len;

	int idEmpleado;

	Employee* pEmpleado = NULL;
	LinkedList* auxarray;

	if(pArrayListEmployee!=NULL){
		getNumero(&idIngresado, "Ingrese el Id a eliminar:\n");

		auxarray = ll_clone(pArrayListEmployee);
		len = ll_len(auxarray);

		if(len>0){
			for(int i=0; i<len;i++){
				pEmpleado = ll_get(auxarray, i);
				respuesta = employee_getId(pEmpleado, &idEmpleado);

				if(respuesta == 0 && idIngresado == idEmpleado){
					employee_MostrarUnEmpleado(pEmpleado);

					do{
						printf("¿Quiere eliminar los datos de este empleado?\n1.Si\t2.No\n");
						getNumero(&respuesta, "opcion:");
					}while(respuesta < 1 || respuesta >2);

					if(respuesta == 1){
						respuesta = ll_remove(pArrayListEmployee, i);
						employee_delete(pEmpleado);

						if(respuesta == 0){
							printf("\nSe elimino correctamente.\n");
							ll_deleteLinkedList(auxarray);
						}else{
							printf("\nNo se pudo eliminar.\n");
						}
					}else{
						printf("\nNo se elimino.\n");
					}
				}
			}
		}else{
			printf("\nNo hay datos cargado.\n\n");
		}
	}
    return retorno;
}
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int len;

	Employee* pEmpleado = NULL;

	if(pArrayListEmployee != NULL){
		len = ll_len(pArrayListEmployee);

		if(len>0){
			for(i=0; i<len; i++){
				pEmpleado = ll_get(pArrayListEmployee, i);
				employee_MostrarUnEmpleado(pEmpleado);
				//printf("%d--%s--%d--%d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
			}
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno= -1;
	int len;

	if(pArrayListEmployee!=NULL){
		len = ll_len(pArrayListEmployee);
		if(len>0){
			ll_sort(pArrayListEmployee, employee_compareByName,1);
			retorno = 0;
		}else{
			printf("\nPrimero debe cargar los datos.\n\n");
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int len;

	Employee* pEmpleado = NULL;
	FILE* pArchivo = NULL;

	if(pArrayListEmployee!=NULL){
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL){
			len = ll_len(pArrayListEmployee);

			if(len>0){
				for(int i=0; i<len;i++){
					pEmpleado = ll_get(pArrayListEmployee, i);
					fprintf(pArchivo,"%d,%s,%d,%d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
				}
			}else{
				printf("\nNo hay nada para guardar.\n\n");
			}
			retorno = 0;

		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int len;

	Employee* pEmpleado = NULL;
	FILE* pArchivo;

	if(pArrayListEmployee!=NULL){
		pArchivo = fopen(path,"wb");

		if(pArchivo!=NULL){
			len = ll_len(pArrayListEmployee);

			if(len>0){
				for(int i=0; i<len; i++){
					pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
					if(pEmpleado != NULL){
						fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
					}else{
						break;
					}
				}
			}else{
				printf("\nNo hay nada para guargar.\n\n");
			}
			retorno = 0;
		}else{
			printf("\nNo se encontro el archivo.\n\n");
		}
	}
	fclose(pArchivo);
    return retorno;
}

