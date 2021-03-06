/*
 ============================================================================
 Name        : Parcial_Laboratorio_I.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "censista.h"
#include "zona.h"
#include "informes.h"
#define TAM_CEN 5
#define TAM_ZON 5
#define TAM_LOC 4

int main()
{
    setbuf(stdout, NULL);
    int opcion;
    int retornoUno = 0;
    int retornoCuatro = 0;
    char informe;
    int contadorNueve=0;
    //Censista censistas[TAM_CEN];
    //Zona zonas[TAM_ZON];
    Localidad localidades[TAM_LOC];
    localidadHardcodeada(localidades);
    //cargaForzadaCensistas(censistas);
    //cargaZonasForzada(zonas);

    Censista censistas[TAM_CEN]={{1,"Hernan","Magico",22,1,"Madrid 127",10,10,2000,0},
                            {2,"Roberto","Alvarez",28,2,"Saveedra 287",12,01,1994,0},
                            {3,"Luis","Perez",30,3,"Sarmiento 87",14,12,1992,0},
                            {4,"Enrique","Perez",39,1,"Italia 887",01,05,1983,0},
                            {5,"Adolfo","Lopez",43,2,"Peru 981",20,03,1979,0}};

    Zona zonas[TAM_ZON]={ {11,1,"calle 1", "calle 2", "calle 300", "calle 400",20,51,30,0,1,0},
                        {12,2,"calle 12", "calle 20", "calle 30", "calle 40",20,52,20,1,2,0},
                        {13,3,"calle 13", "calle 21", "calle 31", "calle 41",20,53,220,1,3,0},
                        {14,1,"calle 14", "calle 22", "calle 32", "calle 42",20,54,50,0,4,0},
                        {15,2,"calle 15", "calle 23", "calle 33", "calle 43",20,54,610,0,5,0}};

    //InicializarListaCensistas(censistas,TAM_CEN);
    //InicializarZona(zonas,TAM_ZON);

    do
    {
    printf("\n+++++++++++++++++++ MENU ++++++++++++++++++++++++\n");
    printf("\n1. Cargar\n");
    printf("2. Modificar\n");
    printf("3. Dar de baja\n");
    printf("4. Cargar Zona\n");
    printf("5. Asignar zona a censar\n");
    printf("6. Carga de datos\n");
    printf("7. Mostrar censistas\n");
    printf("8. Mostrar zonas\n");
    printf("9. Informes\n");

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    opcion=enteroValidado("Elija una opcion: ","La opcion debe ser del 1 al 9: ", 1,9);

    switch(opcion)
        {
        case 1:
        ingresarCensista(censistas,TAM_CEN);
        retornoUno++;
        break;
        case 2:
        if(retornoUno != 0)
        	{
        	modificarCensista(censistas,TAM_CEN);
        	}else{
        		printf("No se realizo ninguna carga en el punto 1");
        	}
        break;
        case 3:
        	if(retornoUno != 0)
        	{
        darDeBaja(censistas,TAM_CEN);
        	}else{
        		printf("No se realizo ninguna carga en el punto 1");
        	}
        break;
        case 4:
        ingresarZona(zonas,TAM_ZON);
        retornoCuatro++;
        break;
        case 5:
        	if(retornoCuatro != 0)
        		{
        asignarCensista (zonas,TAM_ZON,censistas,TAM_CEN);
        		}else{
        			printf("No hay cargada ninguna zona. Cargar en punto 4 1");
        		}
        break;
        case 6:
        cargaDeDatos(zonas,TAM_ZON,censistas,TAM_CEN);
        break;
        case 7:
        printf("\n++++++++++++++++++++++++++++++++++++++ Datos Censista ++++++++++++++++++++++++++++++++++++++\n");
        MostrarCensistas(censistas,TAM_CEN);
        break;
        case 8:
        printf("\n++++++++++++++++++++++++++++++++++++++++++++ Zonas con Censista ++++++++++++++++++++++++++++++++++++++++++++++\n");
        MostrarZonasConCensistas (zonas,TAM_ZON, censistas,TAM_CEN );
        break;
        case 9:
                contadorNueve=0; // declararlo al principio , reinicia el valor a 0 cada vez que se ingresa al punto 9, para despues dar salida
                do{


                    printf("\na. Informar cantidad de censistas en estado Activo con zona Pendiente. \n");
                    printf("b.Mostrar el listado de censistas ordenado alfabeticamente \n");
                    printf("c.Informar nombre de localidad con m?s casas ausentes. \n");
                    printf("d.Informar el censista cuya zona fue la m?s censada \n");
                    printf("e.Informar el promedio de censos por censista/zona  \n");

                    informe=IngreseCaracter("\nIngrese opcion de informe: ");

                    switch(informe){
                        case 'a':
                        	censistasActivoYPendiente(zonas,TAM_ZON,censistas,TAM_CEN );
                            contadorNueve++;
                            break;
                        case 'b':

                            contadorNueve++;
                            break;
                        case 'c':
                        	localidadConMasAusentes(zonas,TAM_ZON);
                            contadorNueve++;
                            break;
                        case 'd':
                        	informarIdConMasCensados(zonas,TAM_ZON,censistas,TAM_CEN);
                            contadorNueve++;
                            break;
                        case 'e':

                        	contadorNueve++;
                            break;
                    	}
                    }while(contadorNueve != 1);

                	break;

        }

    }while(opcion!=10);

    return EXIT_SUCCESS;

}
