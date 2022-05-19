#include "censista.h"
#include "informes.h"

void InicializarListaCensistas(Censista *lista, int tam) {

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			lista[i].isEmpty = 1;// se inicializan el array con el campo Isempty en 1 = vacio

		}
	}
}

int BuscarPrimerEspacioLibre(Censista *lista, int tam) {
	int i;
	int index;

	index = -1;
	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == 1) {
			index = i;
			break;
		}

	}
	if (index == -1) {
		printf("La lista esta ocupada\n");
	}
	return index;
}

int incrementarIdCensista(int valor) {
	static int id;
	static int flagValorInicial = 0;
	if (flagValorInicial == 0) {
		id = valor;
		flagValorInicial = 1;
	}
	id++;
	return id;
}

int ingresarCensista(Censista *Listado, int tam) {

	int retorno = -1;

	int index = BuscarPrimerEspacioLibre(Listado, tam);
	if (index != -1) {

		Listado[index].idCensista = incrementarIdCensista(1000);
		getString(Listado[index].nombre, "Ingrese nombre: ", 51);
		getString(Listado[index].apellido, "Ingrese apellido: ", 51);

		Listado[index].estado = 1;
		getStringAlfaNumerico(Listado[index].datoComplementario.direccion,
				"Ingrese direccion: ", 51);
		Listado[index].datoComplementario.fechaNacimiento.diaNacimiento =
				enteroValidado("Ingresar dia de nacimiento: ",
						"\nError!!! Dias del 1 al 31 :  ", 1, 31);
		Listado[index].datoComplementario.fechaNacimiento.mesNacimiento =
				enteroValidado("Ingresar mes de nacimiento: ",
						"\nError!!! Meses del 1 al 12 : ", 1, 12);
		Listado[index].datoComplementario.fechaNacimiento.anioNacimiento =
				enteroValidado("Ingresar anio de nacimiento: ",
						"\nError!!! AC1o del 1958 al 2004 : ", 1958, 2004);
		Listado[index].isEmpty = 0;
		Listado[index].edad =
				ANIOACTUAL
						- Listado[index].datoComplementario.fechaNacimiento.anioNacimiento;
		retorno = 0;
	}
	return retorno;

}





void Mostrar(Censista Listado[], int tam) {
	char auxiliar[50];

	for (int i = 0; i < tam; i++) {
		if (Listado[i].isEmpty == 0) {
			switch (Listado[i].estado) {
			case LIBERADO:
				strcpy(auxiliar, "Liberado");
				printf("\n%d %10s %17s %20d %12s %12s %8d/%d/%d ",
						Listado[i].idCensista, Listado[i].nombre,
						Listado[i].apellido, Listado[i].edad, auxiliar,
						Listado[i].datoComplementario.direccion,
						Listado[i].datoComplementario.fechaNacimiento.diaNacimiento,
						Listado[i].datoComplementario.fechaNacimiento.mesNacimiento,
						Listado[i].datoComplementario.fechaNacimiento.anioNacimiento);
				break;
			case ACTIVO:
				strcpy(auxiliar, "Activo");
				printf("\n%d %10s %17s %20d %12s %12s %8d/%d/%d ",
						Listado[i].idCensista, Listado[i].nombre,
						Listado[i].apellido, Listado[i].edad, auxiliar,
						Listado[i].datoComplementario.direccion,
						Listado[i].datoComplementario.fechaNacimiento.diaNacimiento,
						Listado[i].datoComplementario.fechaNacimiento.mesNacimiento,
						Listado[i].datoComplementario.fechaNacimiento.anioNacimiento);
				break;
			case INACTIVO:
				strcpy(auxiliar, "Inactivo");
				printf("\n%d %10s %17s %20d %12s %12s %8d/%d/%d ",
						Listado[i].idCensista, Listado[i].nombre,
						Listado[i].apellido, Listado[i].edad, auxiliar,
						Listado[i].datoComplementario.direccion,
						Listado[i].datoComplementario.fechaNacimiento.diaNacimiento,
						Listado[i].datoComplementario.fechaNacimiento.mesNacimiento,
						Listado[i].datoComplementario.fechaNacimiento.anioNacimiento);
				break;
			}
		}
	}
}

void MostrarCensistasLiberados(Censista* lista, int tam)
{
	printf("\n\tId\tNombre\t\tApellido\tEdad\tEstado\n");
	for (int i = 0; i < tam; i++)
	{
			if (lista[i].isEmpty == 0 && lista[i].estado == 1)
			{

			printf("\n%d %10s %17s %20d %12s ",	lista[i].idCensista, lista[i].nombre,
					lista[i].apellido, lista[i].edad,"Liberado");
			}
	}
}

int modificarCensista(Censista *lista, int tam) {
	int i;
	int censitaAModificar;
	int edadAcambiar;
	int estadoACambiar;
	char nombreACambiar[51];
	char apellidoACambiar[51];
	char direccionACambiar[50];
	int diaACambiar;
	int mesACambiar;
	int anioACambiar;

	int retorno;
	int opcionMenu;
	char opcionSubmenu;
	int contador = 0;
	int contadorSubMenu = 0;

	retorno = -1;
	MostrarCensistas(lista, tam);
	censitaAModificar = IngresarEntero(
			"\nIngrese el ID del censita a modificar: ");

	for (i = 0; i < tam; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idCensista == censitaAModificar) {

			do {

				printf("\n1. Modificar Nombre\n");
				printf("2. Modificar Apellido\n");
				printf("3. Modificar edad\n");
				printf("4. Modificar estado del censista\n");
				printf("5. Modificar Otros datos \n");
				printf("6. Volver al menu anterior\n");
				opcionMenu = enteroValidado("Seleccione opcion: ",
						"Se puede seleccionar del 1 al 6 ", 1, 6);

				switch (opcionMenu) {
				case 1:
					getString(nombreACambiar, "Ingrese nuevo nombre: ", 51);
					strcpy(lista[i].nombre, nombreACambiar);
					retorno = 1;
					printf("ID %d modificado ", censitaAModificar);
					contador++;
					break;
				case 2:
					getString(apellidoACambiar, "Ingrese nuevo apellido: ", 51);
					strcpy(lista[i].apellido, apellidoACambiar);
					retorno = 1;
					printf("ID %d modificado ", censitaAModificar);
					contador++;
					break;
				case 3:
					edadAcambiar = enteroValidado("\nIngrese la edad nueva: ",
							"La edad debe ser entre >= a 18 y <= a 64: ", 18,
							64);
					lista[i].edad = edadAcambiar;
					retorno = 1;
					printf("ID %d modificado ", censitaAModificar);
					contador++;
					break;
				case 4:
					estadoACambiar =
							enteroValidado("Ingresar el estado del censista: ",
									"Error!!! \nEl estado puede ser 1=Liberado 2=Activo 3=Inactivo: ",
									1, 3);
					lista[i].estado = estadoACambiar;
					retorno = 1;
					printf("ID %d modificado ", censitaAModificar);
					contador++;
					break;
				case 5:
					printf("++++++++Otros datos a modificar++++++++++");
					printf("\na. Modificar Direccion\n");
					printf("b. Modificar Dia de nacimiento\n");
					printf("c. Modificar Mes de nacimiento\n");
					printf("d. Modificar AC1o de nacimiento\n");
					printf("e. Volver para atras\n");
					opcionSubmenu = IngreseCaracter("Ingrese opcion:");
					switch (opcionSubmenu) {
					case 'a':
						getStringAlfaNumerico(direccionACambiar,
								"Ingrese direccion nueva: ", 51);
						strcpy(lista[i].datoComplementario.direccion,
								direccionACambiar);
						retorno = 1;
						printf("ID %d modificado ", censitaAModificar);
						contadorSubMenu++;
						break;
					case 'b':
						diaACambiar = enteroValidado("\nIngrese el dia: ",
								"El dia debe ser entre: ", 1, 31);
						lista[i].datoComplementario.fechaNacimiento.diaNacimiento =
								diaACambiar;
						retorno = 1;
						printf("ID %d modificado ", censitaAModificar);
						contadorSubMenu++;
						break;
					case 'c':
						mesACambiar = enteroValidado("\nIngrese el mes: ",
								"El mes debe ser entre: ", 1, 12);
						lista[i].datoComplementario.fechaNacimiento.mesNacimiento =
								mesACambiar;
						retorno = 1;
						contadorSubMenu++;
						break;
					case 'd':
						anioACambiar = enteroValidado("\nIngrese el mes: ",
								"El mes debe ser entre: ", 1, 12);
						lista[i].datoComplementario.fechaNacimiento.anioNacimiento =
								anioACambiar;
						retorno = 1;
						contadorSubMenu++;
						break;
					case 'e':
						printf("Se volvio para atras");
						contadorSubMenu++;
						break;
					}
					break;
				case 6:
					printf("Volviste al menu\n");
					retorno = 1;
					contador++;
					break;
				}
			} while (contador != 1);
		}
	}
	if (retorno == -1) {
		printf("\nEl ID ingresado no existe");
	}
	return retorno;
}

int darDeBaja(Censista *list, int tam) {
	int i;
	int auxCensista = -1;
	int idCensista;
	MostrarCensistas(list, tam);
	idCensista = IngresarEntero("\nIngrese el Id del censista a borrar: ");

	for (i = 0; i < tam; i++) {
		if (list[i].isEmpty == 0 && list[i].idCensista == idCensista
				&& list[i].estado != 2) {
			list[i].isEmpty = 1;
			list[i].estado = 3;
			auxCensista = 0;
			printf("ID %d dado de baja", idCensista);
			break;
		}
		if (list[i].isEmpty == 0 && list[i].idCensista == idCensista
				&& list[i].estado == 2) {
			list[i].estado = 3;
			auxCensista = 0;
			printf("El censista %d se paso a estado Inactivo", idCensista);
			break;
		}

	}
	if (auxCensista == -1) {
		printf("\nEl ID ingresado no existe");
	}

	return auxCensista;
}

int buscarIndexPorId(Censista *listaCensista, int len, int id) {
	int retorno = -1;
	if (listaCensista != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {
			if (listaCensista[i].idCensista == id
					&& listaCensista[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void cargaForzadaCensistas(Censista* censistas)
{
	censistas[0].idCensista = 1200;
	strcpy(censistas[0].nombre, "Pedro");
	strcpy(censistas[0].apellido, "Alvarez");
	censistas[0].estado = LIBERADO;
	strcpy(censistas[0].datoComplementario.direccion,"Laprida 120");
	censistas[0].datoComplementario.fechaNacimiento.diaNacimiento =10;
	censistas[0].datoComplementario.fechaNacimiento.mesNacimiento = 10;
	censistas[0].datoComplementario.fechaNacimiento.anioNacimiento =1990;
	censistas[0].isEmpty = 0;
	censistas[0].edad =ANIOACTUAL- censistas[0].datoComplementario.fechaNacimiento.anioNacimiento;

	censistas[1].idCensista = 1201;
	strcpy(censistas[1].nombre, "Erica");
	strcpy(censistas[1].apellido, "Baez");
	censistas[1].estado = ACTIVO;
	strcpy(censistas[1].datoComplementario.direccion,"Meeks 740");
	censistas[1].datoComplementario.fechaNacimiento.diaNacimiento =8;
	censistas[1].datoComplementario.fechaNacimiento.mesNacimiento = 8;
	censistas[1].datoComplementario.fechaNacimiento.anioNacimiento =1978;
	censistas[1].isEmpty = 0;
	censistas[1].edad =ANIOACTUAL- censistas[1].datoComplementario.fechaNacimiento.anioNacimiento;

	censistas[2].idCensista = 1201;
	strcpy(censistas[2].nombre, "Samuel");
	strcpy(censistas[2].apellido, "Lopez");
	censistas[2].estado = ACTIVO;
	strcpy(censistas[2].datoComplementario.direccion,"Mitre 55");
	censistas[2].datoComplementario.fechaNacimiento.diaNacimiento =5;
	censistas[2].datoComplementario.fechaNacimiento.mesNacimiento = 4;
	censistas[2].datoComplementario.fechaNacimiento.anioNacimiento =1999;
	censistas[2].isEmpty = 0;
	censistas[2].edad =ANIOACTUAL- censistas[2].datoComplementario.fechaNacimiento.anioNacimiento;

	censistas[3].idCensista = 1202;
	strcpy(censistas[3].nombre, "Mariel");
	strcpy(censistas[3].apellido, "Pratto");
	censistas[3].estado = INACTIVO;
	strcpy(censistas[3].datoComplementario.direccion,"Chile 155");
	censistas[3].datoComplementario.fechaNacimiento.diaNacimiento =27;
	censistas[3].datoComplementario.fechaNacimiento.mesNacimiento = 12;
	censistas[3].datoComplementario.fechaNacimiento.anioNacimiento =2002;
	censistas[3].isEmpty = 0;
	censistas[3].edad =ANIOACTUAL- censistas[3].datoComplementario.fechaNacimiento.anioNacimiento;

	censistas[4].idCensista = 1203;
	strcpy(censistas[4].nombre, "Manuel");
	strcpy(censistas[4].apellido, "Chad");
	censistas[4].estado = LIBERADO;
	strcpy(censistas[4].datoComplementario.direccion,"Chile 155");
	censistas[4].datoComplementario.fechaNacimiento.diaNacimiento =15;
	censistas[4].datoComplementario.fechaNacimiento.mesNacimiento = 10;
	censistas[4].datoComplementario.fechaNacimiento.anioNacimiento =1988;
	censistas[4].isEmpty = 0;
	censistas[4].edad =ANIOACTUAL- censistas[4].datoComplementario.fechaNacimiento.anioNacimiento;

}
/*Censista censistas[TAM_CEN]={{{1,"Hernan","Magico",22,1,"Madrid 127",10,10,2000,0},
                        {2,"Roberto","Alvarez",28,2,"Saveedra 287",12,01,1994,0},
                        {3,"Luis","Perez",30,3,"Sarmiento 87",14,12,1992,0},
                        {4,"Enrique","Perez",39,1,"Italia 887",01,05,1983,0},
                        {5,"Adolfo","Lopez",43,1,"Peru 981",20,03,1979,0}}};*/


