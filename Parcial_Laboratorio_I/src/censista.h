/*
 * censista.h
 *
 *  Created on: 15 may 2022
 *      Author: Compumar
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_


/*Los estados de los censistas son ACTIVO / INACTIVO / LIBERADO y los de la zona PENDIENTE
/ FINALIZADO.
*/


#include "input.h"



#define LIBERADO 1
#define ACTIVO 2
#define INACTIVO 3
#define ANIOACTUAL 2022




struct Fecha{
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
};

struct Datos{
    char direccion[50];
    struct Fecha fechaNacimiento;
};

typedef struct {
    int idCensista;
    char nombre[50];
    char apellido[50];
    int edad;
    int estado;
    struct Datos datoComplementario;
    int isEmpty;
}Censista;

void InicializarListaCensistas(Censista* lista, int tam);
int BuscarPrimerEspacioLibre(Censista* lista, int tam);
int ingresarCensista(Censista* Listado, int tam);
void Mostrar(Censista Listado[], int tam);
//int MostrarCensistas(Censista* list, int tam);
int modificarCensista(Censista* lista, int tam);
int darDeBaja(Censista* list, int tam);
int buscarIndexPorId(Censista* listaCensista, int len, int id);
int incrementarIdCensista(int valor);
void MostrarCensistasLiberados(Censista* lista, int tam);
void cargaForzadaCensistas(Censista* censistas);

#endif  /* CENSISTA_H_ */
