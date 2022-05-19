

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
	                if(Listado[i].isEmpty==0)
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
