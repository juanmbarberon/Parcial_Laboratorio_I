/*
 * zona.h
 *
 *  Created on: 15 may 2022
 *      Author: Compumar
 */

#ifndef ZONA_H_
#define ZONA_H_

#define FINALIZADO 1
#define PENDIENTE 0

#include "input.h"
#include "censista.h"
//#include "localidad.h"


typedef struct{
    int idLocalidad;
    char descripcion[50];
    int isEmpty;
}Localidad;


typedef struct{
    int idZona;
    int idLocalidad;
    char calleUno[50];
    char calleDos[50];
    char calleTres[50];
    char calleCuatro[50];
    int censadosInSitu;
    int censadosVirtual;
    int ausentes;
    int estadoZona;
    int idCensista;
    int isEmpty;
}Zona;



void InicializarZona(Zona* lista, int tam);
int BuscarPrimerEspacio(Zona* lista, int tam);
int ingresarZona (Zona * Listado, int tam);
int MostrarZonas (Zona* Listado, int tam);
int asignarCensista (Zona* Listado, int tam, Censista* listaCensista, int tamCensista);
int cargaDeDatos (Zona* Listado, int tam, Censista* listaCensista, int tamCensista);
void localidadHardcodeada(Localidad* pArray);
int incrementarIdZonas (int valor);
void cargaZonasForzada(Zona* zonas);


#endif  /* ZONA_H_ */
