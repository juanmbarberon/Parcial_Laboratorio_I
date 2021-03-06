
#include "zona.h"

void InicializarZona(Zona* lista, int tam)
{

    if(lista != NULL && tam > 0)
    {
        for(int i = 0;i < tam; i++)
        {
        lista[i].isEmpty = 1; // se inicializan el array con el campo Isempty en 1 = vacio
       }
    }
}

int BuscarPrimerEspacio(Zona* lista, int tam){
	int i;
	int index;

	index = -1;
	for(i = 0; i<tam; i++){
		if(lista[i].isEmpty == 1)
		{
			index = i;
			break;
		}

	}
	if(index == -1){
		printf("La lista esta ocupada\n");
	}
	return index;
}

int incrementarIdZonas (int valor)
{
  static int id;
  static int flagValorInicial = 0;
  if (flagValorInicial == 0)
    {
      id = valor;
      flagValorInicial = 1;
    }
  id++;
  return id;
}




int ingresarZona (Zona * Listado, int tam)
{

  int retorno = -1;



  int index = BuscarPrimerEspacio (Listado, tam);
  if (index != -1)
    {

      Listado[index].idZona = incrementarIdZonas (4000);
      Listado[index].idLocalidad = enteroValidado("Ingrese localidad 1=LANUS, 2=AVELLANEDA, 3=GERLI : ","Error!! puede ser 1=LANUS, 2=AVELLANEDA, 3=GERLI: ", 1 , 3);
      getStringAlfaNumerico (Listado[index].calleUno, "Ingrese calle uno: ", 51);
      getStringAlfaNumerico (Listado[index].calleDos, "Ingrese calle dos: ", 51);
      getStringAlfaNumerico (Listado[index].calleTres, "Ingrese calle tres: ", 51);
      getStringAlfaNumerico (Listado[index].calleCuatro, "Ingrese calle cuatro: ", 51);
      Listado[index].censadosInSitu=0;
      Listado[index].censadosVirtual=0;
      Listado[index].ausentes=0;
      Listado[index].estadoZona = 0;
      Listado[index].isEmpty = 0;
      retorno = 0;
    }
  return retorno;

}

int MostrarZonas (Zona* Listado, int tam)
{
    int retorno = -1;
    char auxiliar[50];
    char auxiliarLocalidad[50];
    int i;
      printf("\nZona\tLocalidad\t1? Calle\t2? Calle\t3? Calle\t4? Calle\tEstado\t\tIn situ\tVirtuales\tAusentes\n");
    for(i=0;i<tam;i++)
	            {

	                if(Listado[i].isEmpty==0)
	                {
	                	retorno = 0;
	                    switch(Listado[i].idLocalidad)
	                    {
	                        case 1:
	                        strcpy(auxiliarLocalidad, "Lanus");
	                        break;
	                        case 2:
	                        strcpy(auxiliarLocalidad, "Avellaneda");
	                        break;
	                        case 3:
	                        strcpy(auxiliarLocalidad, "Gerli");
	                        break;
	                    }
	                    switch(Listado[i].estadoZona)
	                    {
                            case PENDIENTE:
                            strcpy(auxiliar, "Pendiente");
                             printf ("\n%-d %15s %15s %15s %15s %15s %15s %10d %10d %10d ",Listado[i].idZona,auxiliarLocalidad, Listado[i].calleUno,Listado[i].calleDos, Listado[i].calleTres,Listado[i].calleCuatro, auxiliar,
                             Listado[i].censadosInSitu, Listado[i].censadosVirtual, Listado[i].ausentes);
                            break;
                            case FINALIZADO:
                            strcpy(auxiliar, "Finalizado");
                            printf ("\n%-d %15s %15s %15s %15s %15s %15s %10d %10d %10d ",Listado[i].idZona,auxiliarLocalidad, Listado[i].calleUno,Listado[i].calleDos, Listado[i].calleTres,Listado[i].calleCuatro, auxiliar,
                             Listado[i].censadosInSitu, Listado[i].censadosVirtual, Listado[i].ausentes);
                            break;
	                    }

	                }
	            }
    if(retorno == -1)
    {
    	printf("No hay datos");
    }

    return retorno;
}





int asignarCensista (Zona* Listado, int tam, Censista* listaCensista, int tamCensista)
{
    int i;
    int retorno = -1;
    int auxIdZona;
    int indexCensista;
    int censistaAsignar;

    printf("\n++++++++ LISTADO ID CENSISTA LIBERADOS +++++++++\n");
    MostrarCensistasLiberados(listaCensista,tamCensista);
    printf("\n++++++++ LISTADO ZONAS +++++++++++++++\n");
    MostrarZonas(Listado,tam);
    auxIdZona=IngresarEntero("\nA Que zona quieres asignarle un censista: ");

    for(i=0;i<tam;i++)
    {

        if(Listado[i].isEmpty==0 && Listado[i].idZona==auxIdZona && Listado[i].estadoZona==PENDIENTE )
        {

            censistaAsignar = IngresarEntero ("\nIngrese el ID del censista a asignar: ");

            for (i = 0; i < tamCensista; i++)
            {
            if (listaCensista[i].isEmpty == 0 && listaCensista[i].idCensista == censistaAsignar && listaCensista[i].estado == LIBERADO)
                {

                Listado[i].idCensista=censistaAsignar;
                indexCensista=buscarIndexPorId(listaCensista, tamCensista, listaCensista[i].idCensista);
                listaCensista[i].estado=2;
                retorno = 1;
                break;

                }
            }
        }
    }
    if(retorno == 1)
    {
        printf("\nLa zona %d tiene asignado al censista %d su nombre es %s", auxIdZona, censistaAsignar, listaCensista[indexCensista].nombre );
    }

    if(retorno == -1)
    {
        printf("\nLa zona ingresada no existe");
    }
   return retorno;
}

int cargaDeDatos (Zona* Listado, int tam, Censista* listaCensista, int tamCensista)
{
    int zonaCensada;
    int censistaAsignado=0;
    int i;
    int retorno=0;

    zonaCensada=IngresarEntero("\nIngrese zona censada : ");
    for(i=0;i<tam;i++)
    {

    	if(Listado[i].isEmpty==0 && Listado[i].idZona==zonaCensada && Listado[i].estadoZona==PENDIENTE && Listado[i].idCensista>0 )
        {

         Listado[i].censadosInSitu=enteroValidado("Ingresar cantidad de censados in situ: ","\nError!! Debe ser numero positivo",0,99999);
         Listado[i].censadosVirtual=enteroValidado("Ingresar cantidad de censados virtuales: ","\nError!! Debe ser numero positivo",0,99999);
         Listado[i].ausentes=enteroValidado("Ingresar cantidad de ausentes: ","\nError!! Debe ser numero positivo",0,99999);
         Listado[i].estadoZona=FINALIZADO;
         censistaAsignado=Listado[i].idCensista;
         retorno=1;
         break;
        }
    }


    	for(i=0;i<tamCensista;i++)
    	{
    		if(listaCensista[i].isEmpty==0 && listaCensista[i].idCensista==censistaAsignado)// && listaCensista[i].estado==2)
    		{
            listaCensista[i].estado=1;
            retorno = 1;
            break;
    		}
        }



    if(retorno == 1){
        printf("Se cargaron los datos de la zona %d, y se libero al censista %d",zonaCensada, censistaAsignado);
    }else
        {
        printf("No se cargaron datos, error en zona revisar");
        }
    return retorno;
}

void localidadHardcodeada(Localidad* pArray)
{


        pArray[0].idLocalidad=1;
        strcpy(pArray[0].descripcion,"Lanus");
        pArray[0].isEmpty=0;
        pArray[1].idLocalidad=2;
        strcpy(pArray[1].descripcion,"Avellaneda");
        pArray[1].isEmpty=0;
        pArray[2].idLocalidad=3;
        strcpy(pArray[2].descripcion,"Gerli");
        pArray[2].isEmpty=0;
        pArray[3].idLocalidad=4;
        strcpy(pArray[3].descripcion,"Banfield");
        pArray[3].isEmpty=0;

}

void cargaZonasForzada(Zona* zonas)
{
	zonas[0].idZona=incrementarIdZonas(4300);
	zonas[0].idLocalidad = 1;
	strcpy (zonas[0].calleUno, "Chimento");
	strcpy (zonas[0].calleDos, "Saavedra");
	strcpy (zonas[0].calleTres, "Brown");
	strcpy (zonas[0].calleCuatro, "Rivera");
	zonas[0].censadosInSitu=100;
	zonas[0].censadosVirtual=150;
	zonas[0].ausentes=85;
	zonas[0].estadoZona = FINALIZADO;
	zonas[0].idCensista = 0;
	zonas[0].isEmpty = 0;

	zonas[1].idZona=incrementarIdZonas(4301);
	zonas[1].idLocalidad = 2;
	strcpy (zonas[1].calleUno, "Peru");
	strcpy (zonas[1].calleDos, "Esmeralda");
	strcpy (zonas[1].calleTres, "Primo");
	strcpy (zonas[1].calleCuatro, "Meeks");
	zonas[1].censadosInSitu=0;
	zonas[1].censadosVirtual=0;
	zonas[1].ausentes=0;
	zonas[1].estadoZona = PENDIENTE;
	zonas[1].idCensista = 0;
	zonas[1].isEmpty = 0;

	zonas[2].idZona=incrementarIdZonas(4302);
	zonas[2].idLocalidad = 3;
	strcpy (zonas[2].calleUno, "Lima");
	strcpy (zonas[2].calleDos, "Chile");
	strcpy (zonas[2].calleTres, "Primo");
	strcpy (zonas[2].calleCuatro, "Uruguay");
	zonas[2].censadosInSitu=211;
	zonas[2].censadosVirtual=252;
	zonas[2].ausentes=85;
	zonas[2].estadoZona = FINALIZADO;
	zonas[2].idCensista = 0;
	zonas[2].isEmpty = 0;

	zonas[3].idZona=incrementarIdZonas(4303);
	zonas[3].idLocalidad = 4;
	strcpy (zonas[3].calleUno, "India");
	strcpy (zonas[3].calleDos, "Porto");
	strcpy (zonas[3].calleTres, "San Martin");
	strcpy (zonas[3].calleCuatro, "Rio Negro");
	zonas[3].censadosInSitu=99;
	zonas[3].censadosVirtual=153;
	zonas[3].ausentes=85;
	zonas[3].estadoZona = FINALIZADO;
	zonas[3].idCensista = 0;
	zonas[3].isEmpty = 0;

	zonas[4].idZona=incrementarIdZonas(4304);
	zonas[4].idLocalidad = 1;
	strcpy (zonas[4].calleUno, "India");
	strcpy (zonas[4].calleDos, "Porto");
	strcpy (zonas[4].calleTres, "San Martin");
	strcpy (zonas[4].calleCuatro, "Rio Negro");
	zonas[4].censadosInSitu=0;
	zonas[4].censadosVirtual=0;
	zonas[4].ausentes=0;
	zonas[4].estadoZona = PENDIENTE;
	zonas[4].idCensista = 0;
	zonas[4].isEmpty = 0;
}


/*Zona zonas[TAM_ZON]={ {11,1,"calle 1", "calle 2", "calle 300", "calle 400",20,51,60,0,1,0},
                    {12,2,"calle 12", "calle 20", "calle 30", "calle 40",20,52,60,1,2,0},
                    {13,3,"calle 13", "calle 21", "calle 31", "calle 41",20,53,60,1,3,0},
                    {14,1,"calle 14", "calle 22", "calle 32", "calle 42",20,54,60,0,4,0},
                    {15,2,"calle 15", "calle 23", "calle 33", "calle 43",20,54,60,0,5,0}};

Localidad localidades[TAM_LOC]={{1,"Lanus",0},
		   	   	   	   	   	   	   {2,"Avellaneda",0},
								   {3,"Gerli",0}};*/
