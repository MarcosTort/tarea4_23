/*
  Módulo de definición de 'TColaDePrioridadPersona'.

  Los elementos de tipo 'TColaDePrioridadPersona' son colas de prioridad cuyos
  elementos son de tipo 'TPersona' y cuya prioridad se define por la fecha del
  primer evento de la agenda de la persona.

  Las personas son únicas, por lo que no es posible que haya dos personas con el
  mismo id ni con el mismo nombre.
  Se asume que los ids de las personas están acotados entre 1 y N, siendo N el
  tamaño de la cola.

  El criterio para establecer la prioridad entre personas es, de manera
  predeterminada, que una persona es prioritaria ante otra si la fecha de su 
  primer evento en la agenda es menor que la fecha del primer evento de la otra persona.
  Este criterio se puede modificar, haciendo que la persona prioritaria sea la de
  evento con fecha mayor.

  Si la 'TColaDePrioridadPersona' no es vacía hay una persona considerada la
  prioritaria, según el criterio de prioridad. Si hay más de una persona con la
  misma fecha cualquiera de ellas es la prioritaria.


  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _CP_H
#define _CP_H

#include "utils.h"
#include "persona.h"

// Representación de 'TColaDePrioridadPersona'
// Se debe definir en colaDePrioridadPersona.cpp
// struct _rep_colaDePrioridadPersona;
// Declaración del tipo 'TColaDePrioridadPersona'
typedef struct rep_colaDePrioridadPersona *TColaDePrioridadPersona;

/*
  Devuelve una 'TColaDePrioridadPersona' vacía (sin elementos) que puede
  contener hasta N personas.
  La prioridad entre dos personas se define por la que tenga fecha menor en el primer
  evento de la agenda.
  El tiempo de ejecución en el peor caso es Theta(N).
 */
TColaDePrioridadPersona crearCP(nat N);

/*
  Modifica el criterio de prioridad: si el prioritario era la persona que tenía asociada
  la fecha menor pasa a ser la que tiene asociada la fecha mayor, y viceversa.
  Debe modificar la cola de forma de que se respete el nuevo criterio de prioridad.
  Se pide que el tiempo de ejecución en el peor caso sea O(n*log n), siendo 'n' la cantidad de
  elementos de 'cp'. Sin embargo, existe una solución que lo hace en O(n).
 */
void invertirPrioridad(TColaDePrioridadPersona &cp);

/*
  Libera la memoria asignada a 'cp' y a cada uno de sus elementos.
  Es decir, libera la memoria asociada a todas las personas que estén en la cola.
  El tiempo de ejecución en el peor caso es O(N*m), siendo 'N' el parámetro
  pasado en crearCP y 'm' la cantidad de eventos en la agenda con mayor cantidad
  de eventos.
 */
void liberarCP(TColaDePrioridadPersona &cp);

/*
  Inserta 'persona' en 'cp'.
  El tiempo de ejecución en el peor caso es Theta(log N) donde 'N' el parámetro pasado en crearCP.
  PRE: !estaEnCP(persona, cp)
  PRE: 1 <= idPersona <= N, siendo 'N' el parámetro pasado en crearCP.
 */
void insertarEnCP(TPersona persona, TColaDePrioridadPersona &cp);

/*
  Devuelve 'true' si y solo si en 'cp' no hay elementos.
  El tiempo de ejecución en el peor caso es Theta(1).
 */
bool estaVaciaCP(TColaDePrioridadPersona cp);

/*
  Devuelve la persona prioritaria de 'cp'.
  El tiempo de ejecución en el peor caso es O(1).
  PRE: !estaVaciaCP(cp).
 */
TPersona prioritaria(TColaDePrioridadPersona cp);

/*
  Elimina de 'cp' la persona prioritaria y libera la memoria asociada.
  Si estaVacioCP(cp) la operación no tiene efecto.
  El tiempo de ejecución en el peor caso es Theta(log N), siendo 'N' el parámetro
  pasado en crearCP.
 */
void eliminarPrioritaria(TColaDePrioridadPersona &cp);

/*
  Devuelve 'true' si y solo si la persona con 'id' es un elemento de 'cp'.
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaEnCP(nat id, TColaDePrioridadPersona cp);

/*
  Devuelve el valor de prioridad (la fecha) asociada a la persona con 'id'.
  Precondición: estaEnCp(id, cp).
  El tiempo de ejecución en el peor caso es O(1).
 */
TFecha prioridad(nat id, TColaDePrioridadPersona cp);

#endif
