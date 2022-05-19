

#ifndef INFORMES_H_
#define INFORMES_H_

#include "censista.h"
#include "zona.h"

void MostrarZonasConCensistas (Zona* ListadoZona, int tam, Censista* list, int tamList );
int MostrarCensistas(Censista* list, int tam);
void localidadConMasAusentes(Zona pArray[], int lenZona);
int censistasActivoYPendiente(Zona pArray[], int lenZona,Censista lista[], int lenLista );
int buscarIdConMasCensadosTotal(Zona pArray[], int tam, int idCensista);
int informarIdConMasCensados(Zona pArray[], int lenZona, Censista censistas[], int lenCensistas);

#endif /* INFORMES_H_ */
