

#include "informes.h"

void MostrarZonasConCensistas (Zona* Listado, int tam, Censista* list, int tamList )
{
    int indexCensista;
    char auxiliar[50];
    int i;
      printf("Zona\t1° Calle\t2° Calle\t3° Calle\t4° Calle\tEstado\t\tNombre\t\tApellido\n");
    for(i=0;i<tam;i++)
	            {
	                indexCensista=buscarIndexPorId(list, tamList, Listado[i].idCensista);
	                if(Listado[i].isEmpty==0 && Listado[i].idCensista > 0)
	                {

	                    switch(Listado[i].estadoZona)
	                    {
                            case PENDIENTE:
                            strcpy(auxiliar, "Pendiente");
                             printf ("\n%-d %15s %12s %12s %12s %12s %15s %15s ",Listado[i].idZona, Listado[i].calleUno,Listado[i].calleDos, Listado[i].calleTres,Listado[i].calleCuatro, auxiliar,
                             list[indexCensista].nombre, list[indexCensista].apellido);
                            break;
                            case FINALIZADO:
                            strcpy(auxiliar, "Finalizado");
                            printf ("\n%-d %12s %12s %12s %12s %12s %15s %15s ",Listado[i].idZona, Listado[i].calleUno,Listado[i].calleDos, Listado[i].calleTres,Listado[i].calleCuatro, auxiliar,
                             list[indexCensista].nombre, list[indexCensista].apellido);
                            break;
	                    }

	                }
	                if(Listado[i].idZona>0 && Listado[i].estadoZona==PENDIENTE && Listado[i].idCensista== 0)
	               	          {
	               	          printf("\nLa zona %d no tiene censista asignado", Listado[i].idZona);
	               	          }
	            }
}

int MostrarCensistas (Censista * list, int tam)
{

  int flagListaVacia = -1;

  for (int i = 0; i < tam; i++)
    {
      if (list[i].isEmpty == 0)
	{

	  flagListaVacia = 0;
	}
    }
  if (flagListaVacia == 0)
    {
      printf
	("\nId\tNombre\t\tApellido\t\tEdad\tEstado\tDireccion\tFechaNacimiento\n");
      Mostrar (list, tam);
    }
  else
    {
	  printf
	 	("\nId\tNombre\t\tApellido\t\tEdad\tEstado\tDireccion\tFechaNacimiento\n");
      puts ("No hay datos de censistas cargados.\n");
    }
  return flagListaVacia;
}




///////////////////// segunda parte

/*Informes:
a. Informar cantidad de censistas en estado Activo con zona Pendiente.
b. Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield
ordenados alfabéticamente por apellido y nombre.
c. Informar nombre de localidad con más casas ausentes. //
d. Informar el censista cuya zona fue la más censada (total censados presencial y virtual)
e. Informar el promedio de censos por censista/zona.*/

void localidadConMasAusentes(Zona pArray[], int lenZona)
{
    //int retorno=-1;
    int censadosAusentesUno=0;
    int censadosAusentesDos=0;
    int censadosAusentesTres=0;
    int censadosAusentesCuatro=0;

    if(pArray!=NULL && lenZona>0 )
    {

        for(int i=0;i<lenZona;i++)
        {
        	switch(pArray[i].idLocalidad)
        	            {
        	            case 1:
        	            censadosAusentesUno=censadosAusentesUno + pArray[i].ausentes;
        	            break;
        	            case 2:
        	            censadosAusentesDos=censadosAusentesDos + pArray[i].ausentes;
        	            break;
        	            case 3:
        	            censadosAusentesTres=censadosAusentesTres + pArray[i].ausentes;
        	            break;
        	            case 4:
        	            censadosAusentesCuatro=censadosAusentesCuatro + pArray[i].ausentes;
        	            break;
        	            }

        }
    }
    if(censadosAusentesUno > censadosAusentesDos && censadosAusentesUno > censadosAusentesTres && censadosAusentesUno > censadosAusentesCuatro)
    {
    	printf("La localidad con mas ausentes es Lanus");
    }
    if(censadosAusentesDos > censadosAusentesUno && censadosAusentesDos > censadosAusentesTres && censadosAusentesDos > censadosAusentesCuatro)
    {
        	printf("La localidad con mas ausentes es Avellaneda");
     }
    if(censadosAusentesTres > censadosAusentesUno && censadosAusentesTres > censadosAusentesDos && censadosAusentesTres > censadosAusentesCuatro)
    {
            	printf("La localidad con mas ausentes es Gerli");
    }
    if(censadosAusentesCuatro > censadosAusentesUno && censadosAusentesCuatro > censadosAusentesDos && censadosAusentesCuatro > censadosAusentesTres)
    {
                	printf("La localidad con mas ausentes es Banfield");
     }

}

//a. Informar cantidad de censistas en estado Activo con zona Pendiente.

int censistasActivoYPendiente(Zona pArray[], int lenZona,Censista lista[], int lenLista )
{
    int retorno=-1;

    int contador=0;


    if(pArray!=NULL && lenZona>0 && lista!= NULL && lenLista > 0)
    {
        for(int i=0;i<lenZona;i++)
        {
        	for(i =0 ; i<lenLista;i++)
        		{
        		if(lista[i].estado == ACTIVO && pArray[i].estadoZona==PENDIENTE)
        			{
        			contador++;
        			}
        		}

        }
    }
    printf("La cantidad de censistas activo con zona pendiente son %d ", contador);
    return retorno;
}
//Informar el censista cuya zona fue la más censada (total censados presencial y virtual)
int buscarIdConMasCensadosTotal(Zona pArray[], int tam, int idCensista)
{
    int retorno=-1;
   // int contador=0;
    int totalCensados=0;

    if(pArray!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {

         if(pArray[i].idCensista==idCensista)
           {
               totalCensados=totalCensados +pArray[i].censadosInSitu  + pArray[i].censadosVirtual;
           }
        }
        retorno=totalCensados;

    }

    return retorno;
}

int informarIdConMasCensados(Zona pArray[], int lenZona, Censista censistas[], int lenCensistas)
{
    int retorno=-1;
    int contador=0;
    int contadorMaximoActual=0;
    int auxiliarId;
    char auxNombre[50];
    char auxApellido[50];



    if(pArray!=NULL && censistas!=NULL && lenZona>0 && lenCensistas>0)
    {
        for(int i=0;i<lenCensistas;i++)
        {
            contador=buscarIdConMasCensadosTotal(pArray, lenZona, censistas[i].idCensista);
            if(contador>contadorMaximoActual)
            {
                auxiliarId=censistas[i].idCensista;
                strcpy(auxNombre,censistas[i].nombre);
                strcpy(auxApellido,censistas[i].apellido);
                contadorMaximoActual=contador;
            }

        }

    }
     printf("el id %d con mas censados fue : %s %s con un total de: %d", auxiliarId, auxNombre, auxApellido, contadorMaximoActual);

    return retorno;
}
