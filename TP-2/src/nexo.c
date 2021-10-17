#include "nexo.h"
void MostrarMenu(){
	printf("\nMENU DE OPCIONES:\n");
	printf("1.ALTAS\n");
	printf("2.MODIFICAR\n");
	printf("3.BAJA\n");
	printf("4.INFORMAR\n");
	printf("5.SALIR\n");
}

void EjecutarOpcion(Employee* list, int len,int opcion){
	int id = MostrarIdMayor(list,len);
	switch(opcion){
		case 1:
			MostrarCasoUno(list,len);
			break;

		case 2:
			if(id != 0){
				MostrarCasoDos(list,len);
			}else{
				printf("\nNo se cargaron datos aun\n");
			}
			break;

		case 3:
			if(id != 0){
				MostrarCasoTres(list,len);
			}else{
				printf("\nNo se cargaron datos aun\n");
			}
			break;

		case 4:
			if(id != 0){
				MostrarCasoCuatro(list,len);
			}else{
				printf("\nNo se cargaron datos aun\n");
			}

			break;

		default:
			printf("\nOpcion incorrecta.\n");
	}
}

void MostrarCasoUno(Employee* list, int len){
	int id;
	char name[TN];
	char lastName[TA];
	float salary;
	int sector;
	int respuesta;

	id=MostrarIdMayor(list,len);
	id++;
	GetString("Ingrese su nombre: ",name,TN);
	GetString("Ingrese el apellido: ",lastName,TA);
	getNumeroFloat(&salary,"Ingrese el salario: ");
	getNumero(&sector,"Ingrese el sector: ");

	respuesta = addEmployee(list,len,id,name,lastName,salary,sector);

	if(respuesta!=0){
		printf("\nNo hay espacio guardar los datos.\n");
		id--;
	}else{
		printf("\nSe cargo correctamente.\n");
	}
}

void MostrarCasoDos(Employee* list,int len){
	int idIngresado;
	int respuesta;
	do{
		getNumero(&idIngresado,"Ingrese el id a modificar: ");
		respuesta = findEmployeeById(list,len,idIngresado);

		if(respuesta!=-1){
			MostrarEmpleado(list[respuesta]);
			respuesta = ModificarListaEmpleado(list,len,idIngresado);

			if(respuesta==0){
				printf("\nSe modifico correctamente.\n");
			}else{
				printf("\nNo se pudo modificar\n");
			}
		}else{
			printf("ID incorrecta : ");
		}
	}while(respuesta==-1);
}

void MostrarCasoTres(Employee* list, int len){
	int idIngresado;
	int respuesta;
	do{
		getNumero(&idIngresado,"Ingrese el id a eliminar: ");
		respuesta = findEmployeeById(list,len,idIngresado);

		if(respuesta!=-1){
			removeEmployee(list,len,idIngresado);
			printf("\nSe elimino correctamente.\n");
		}else{
			printf("ID incorrecta : ");
		}
	}while(respuesta==-1);
}

void MostrarCasoCuatro(Employee* list, int len){
	float promedio;
	int contadorSalarioPromedio;
	float totalSalario;
	int respuesta;

	OrdenarEmpleadosPorApellido(list,len);
	printEmployees(list,len);

	respuesta = CalcularPromedio(list,len,&promedio,&contadorSalarioPromedio,&totalSalario);
	if(respuesta == 0){
		printf("\nTOTAL SALARIO:%.2f\nPROMEDIO SALARIO:%.2f\nCANTIDAD DE SALARIO PROMEDIO:%d\n",totalSalario,promedio,contadorSalarioPromedio);
	}
}
