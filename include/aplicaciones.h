/*
  Módulo de definición de 'aplicaciones'.

  El módulo de acplicaciones es para practicar el USO de TADs.
  Durante la implementación sólo se deben utilizar los TADs.
  Nunca se puede acceder a la representación de los datos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef APLICACIONES_H
#define APLICACIONES_H

#include "tablaPersonas.h"

#define MAX_ID 10

/*
  Dada una tabla de personas 't' y un arreglo de nombres 'nombres' de
  longitud 'n', imprime en pantalla los datos de las personas en 'nombres'
  que están en 't', en orden de fecha de su evento más próximo.
  Se  asume que los IDs de las personas están acotados entre 1 y MAX_ID.
  El tiempo de ejecución en promedio es O(n*log n+ n*m), siendo 'n' la cantidad de nombres y 
  'm' es la cantidad de eventos de la agenda con mas eventos entre todas las personas de la tabla.
  Se debe utilizar una cola de prioridad auxiliar para resolver el problema.
 */
void listarEnOrden(TTablaPersonas t, char** nombres, nat n);


#endif  // APLICACIONES_H
