#include "arrayEmployees.h"


int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
			list[i].isEmpty = TRUE;
			list[i].id = 0;
		}
		retorno = 0;
	}

 return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == TRUE){
				list[i].id = id;
				list[i].isEmpty = FALSE;
				strncpy(list[i].lastName, lastName,sizeof(list[i].lastName));
				strncpy(list[i].name, name,sizeof(list[i].name));
				list[i].salary = salary;
				list[i].sector = sector;
				retorno = 0;
				break;
			}
		}
	}
 return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>0 && id>0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == FALSE && list[i].id == id){
				retorno = i;
				break;
			}
		}
	}
 return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > 0){
		for(i=0; i<len; i++){
			if(list[i].id == id && list[i].isEmpty == FALSE){
				list[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}
 return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{

 return 0;
}

int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	int i;

	if(list != NULL && length > 0){
		printf("\n id  NOMBRE	APELLIDO   SALARIO    SECTOR\n");
		for(i=0; i<length; i++){
			if(list[i].isEmpty==FALSE){

				MostrarEmpleado(list[i]);
				retorno = 0;
			}
		}
	}
 return retorno;
}

void MostrarEmpleado(Employee list){
	printf(" %-3d %-10s %-10s %-8.2f %5d \n",list.id,list.name,list.lastName,list.salary,list.sector);
}

int ModificarListaEmpleado(Employee* list,int tam, int id){
	int retorno = -1;
	int opcion;
	int i;

	if(list != NULL && tam > 0 && id > 0){
			printf("\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");
			getNumero(&opcion,"OPCION: ");

			for(i=0; i<tam; i++){
				if(list[i].id  == id && list[i].isEmpty == FALSE){
					switch(opcion){
					case 1:
						GetString("\nModifique el nombre: ",list[i].name,TN);
						break;

					case 2:
						GetString("\nModifique el apellido: ",list[i].lastName,TA);
						break;

					case 3:
						getNumeroFloat(&list[i].salary,"\nModifique el salario: ");
						break;

					case 4:
						getNumero(&list[i].sector,"\nModifique el sector: ");
						break;
					}
					retorno = 0;
					break;
				}
			}
	}
	return retorno;
}

int OrdenarEmpleadosPorApellido(Employee* list, int tam){
	int retorno = -1;
	Employee auxiliarApellido;

	if(list != NULL && tam>0){
		for(int i=0; i<tam-1;i++){
			for(int j = i+1; j<tam; j++){
				if(list[i].isEmpty == FALSE){
					if(strncmp(list[i].lastName,list[j].lastName,sizeof(list[i].lastName))>0){
						auxiliarApellido = list[i];
						list[i] = list[j];
						list[j] = auxiliarApellido;
					}else{
						if(strncmp(list[i].lastName,list[j].lastName,sizeof(list[i].lastName))== 0 && list[i].sector > list[j].sector){
								auxiliarApellido = list[i];
								list[i] = list[j];
								list[j] = auxiliarApellido;
						}
					}
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int CalcularPromedio(Employee* list,int tam,float* promedio, int* contadorSalarioPromedio, float* totalSalario){
	int retorno = -1;
	float acumuladorSalario = 0;
	int auxiliarContador = 0;
	int contadorSalarioProm = 0;
	int salarioPromedioAR = 39000;
	int i;

	if(list != NULL && tam>0 && promedio != NULL && contadorSalarioPromedio != NULL && totalSalario != NULL){
		for(i=0; i<tam; i++){
			if(list[i].isEmpty == FALSE){
				acumuladorSalario = acumuladorSalario + list[i].salary;
				auxiliarContador++;
				if(list[i].salary >= salarioPromedioAR){
					contadorSalarioProm++;
				}
				retorno = 0;
			}
		}
		*promedio = acumuladorSalario/auxiliarContador;
		*totalSalario = acumuladorSalario;
		*contadorSalarioPromedio = contadorSalarioProm;
	}
	return retorno;
}

int MostrarIdMayor(Employee* list,int len){
	int retorno;
	int banderaIdMayor = 1;
	int auxiliarId;
	int i;

	for(i=0;i<len;i++){
		if(banderaIdMayor == 1){
			banderaIdMayor = 0;
			auxiliarId = list[i].id;
		}else{
			if(list[i].id>=auxiliarId){
			auxiliarId = list[i].id;
			}
		}
	}
	retorno = auxiliarId;
	return retorno;
}



