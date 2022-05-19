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
#define TAM_CEN 1000
#define TAM_ZON 4000
#define TAM_LOC 3

int main()
{
    setbuf(stdout, NULL);
    int opcion;
    int retornoUno = 0;
    int retornoCuatro = 0;

    Censista censistas[TAM_CEN];
    Zona zonas[TAM_ZON];
    Localidad localidades[TAM_LOC];
    localidadHardcodeada(localidades);

    InicializarListaCensistas(censistas,TAM_CEN);
    InicializarZona(zonas,TAM_ZON);

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
    printf("9. Salir\n");

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
        }
    }while(opcion!=9);

    return 0;
}
