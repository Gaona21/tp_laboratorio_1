#include "Employee.h"

Employee* employee_new(){
	Employee* pAux;
	pAux = (Employee*)malloc(sizeof(Employee));
	if(pAux!=NULL){
		employee_setId(pAux, 0);
		employee_setNombre(pAux, "");
		employee_setHorasTrabajadas(pAux, 0);
		employee_setSueldo(pAux, 0);
	}
	return pAux;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo){
	Employee* pAux;

	pAux = employee_new();
	if(pAux != NULL){
		pAux->id = atoi(idStr);
		strncpy(pAux->nombre,nombreStr,sizeof(pAux->nombre));
		pAux->horasTrabajadas = atoi(horasTrabajadasStr);
		pAux->sueldo = atoi(sueldo);
	}
	return pAux;
}

void employee_delete(Employee* this){
	free(this);
}

int employee_setId(Employee* this,int id){
	int retorno = -1;

	if(this!=NULL && id>0){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno = -1;

	if(this!=NULL && id!=NULL){
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;

	if(this!=NULL && nombre!=NULL){
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;

	if(this!=NULL && nombre!=NULL){
		strncpy(nombre,this->nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;

	if(this!=NULL && horasTrabajadas>=0){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;

	if(this!=NULL && horasTrabajadas>=0){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno = -1;

	if(this!=NULL && sueldo>=0){
			this->sueldo = sueldo;
			retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
	int retorno = -1;

	if(this!=NULL && sueldo>=0){
			*sueldo = this->sueldo;
			retorno = 0;
	}
	return retorno;
}

int employee_addText(Employee* this,char* id,char* nombre,char* horasTrabajadas, char* sueldo){
	int retorno = -1;
	int respuesta;
	int auxHoras;
	int auxSueldo;

	if(this!=NULL && id!=NULL && nombre!=NULL && horasTrabajadas!=NULL && sueldo!=NULL){

		printf("\nCargando datos del empleado:\n\n");

		GetString("ingrese su nombre: ",nombre,LEN_NOMBRE);

		printf("Ingrese las horas trabajadas: ");
		scanf("%s",horasTrabajadas);
		respuesta = esNumerica(horasTrabajadas);

		if(respuesta == 1){
			auxHoras = atoi(horasTrabajadas);
			if(auxHoras<0){
				respuesta = 0;
			}
		}


		while(respuesta!=1){
			printf("Reingrese horas trabajadas: ");
			scanf("%s",horasTrabajadas);
			respuesta = esNumerica(horasTrabajadas);

			if(respuesta == 1){
				auxHoras = atoi(horasTrabajadas);
				if(auxHoras<0){
					respuesta = 0;
				}
			}
		}

		printf("Ingrese su sueldo: ");
		scanf("%s",sueldo);
		respuesta = esNumerica(sueldo);

		if(respuesta == 1){
			auxSueldo = atoi(sueldo);
			if(auxSueldo<0){
				respuesta = 0;
			}
		}

		while(respuesta!=1){
			printf("Reingrese sueldo: ");
			scanf("%s",sueldo);
			respuesta = esNumerica(sueldo);

			if(respuesta == 1){
				auxSueldo = atoi(sueldo);
				if(auxSueldo<0){
					respuesta = 0;
				}
			}
		}

		retorno = 0;
	}
	return retorno;
}

void employee_MostrarUnEmpleado(Employee* this){
	if(this!=NULL){
		printf("%d---%s---%d---%d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
	}
}

int employee_compareByName(void* e1, void* e2){
	int retorno = -1;
	int respuesta;

	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(e1!=NULL && e2!=NULL){
		unEmpleado = (Employee*)e1;
		otroEmpleado = (Employee*)e2;

		respuesta = strcmp(unEmpleado->nombre,otroEmpleado->nombre);

		retorno = respuesta;
	}
	return retorno;
}



