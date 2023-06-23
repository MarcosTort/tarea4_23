/*
  Módulo de definición de 'TAgendaLS'.

  Los elementos de tipo TAgendaLS almacenan una serie de TEventos con una estructura de lista simple.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef AGENDA_H
#define AGENDA_H

#include "evento.h"

// Definición de tipo TAgendaLS como un puntero a rep_agenda
typedef struct rep_agendaLS* TAgendaLS;

// Función para crear un elemento de tipo TAgendaLS
// Devuelve una agenda vacía
// La función es Theta(1) peor caso
TAgendaLS crearAgendaLS();

// Función para agregar un evento a una agenda
// Recibe un elemento de tipo TAgendaLS y un elemento de tipo TEvento y lo agrega a la agenda en orden por fecha (de menor a mayor)
// Si dos eventos tienen la misma fecha, deben ordenarse por orden de creación, de más nuevo a más antiguo
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
void agregarEnAgendaLS(TAgendaLS& agenda, TEvento evento);

// Función para imprimir todos los eventos de una agenda
// Recibe un elemento de tipo TAgendaLS e imprime sus eventos en orden cronológico
// El formato en el que se debe imprimir la agenda es utilizando de forma secuencial la función ImprimirTEvento
// Si la agenda está vacía no imprime nada
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
void imprimirAgendaLS(TAgendaLS agenda);

// Función para liberar una agenda
// Recibe una referencia a un elemento de tipo TAgendaLS y libera su memoria
// Libera además la memoria de cada uno de los eventos en la agenda
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
void liberarAgendaLS(TAgendaLS& agenda);

// Funcion para verificar si una agenda es vacia, retorna True si y solo si agenda es vacia
// La función es Theta(1) peor caso
bool esVaciaAgendaLS(TAgendaLS agenda);

// Retorna una copia de la agenda pasada por parámetro, donde los eventos de la copia son copias de los eventos de la agenda original
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
TAgendaLS copiarAgendaLS(TAgendaLS agenda);

// Función para verificar si un elemento de tipo TEvento existe en una agenda
// Recibe una agenda y un identificador del evento y regresa un booleano indicando su existencia
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
bool estaEnAgendaLS(TAgendaLS agenda, int id);

// Función para obtener un evento de una agenda
// Recibe una agenda y un identificador del evento y regresa el evento con ese id
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
// PRE: El evento debe estar en la agenda
TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id);

// Función para posponer un evento en una agenda
// Recibe una agenda, el identificador del evento y un número de días y pospone el evento con ese identificador en la agenda
// El evento pospuesto debe reubicarse en la agenda según el criterio de orden establecido
// En caso de que la nueva fecha del evento pospuesto coincida con la de otro evento en la agenda, el evento con la fecha 
// modificada debe quedar inmediatamente antes en la agenda que todos los de fecha igual o posterior.
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
// PRE: El evento debe estar en la agenda
void posponerEnAgendaLS(TAgendaLS& agenda, int id, nat n);

// Función para imprimir todos los eventos de una agenda que ocurren en una fecha determinada
// Recibe una agenda y una fecha e imprime los eventos que ocurren en esa fecha por orden de creación (más nuevo a más antiguo)
// Si no hay eventos con esa fecha no imprime nada
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha);

// Función que determina si existe algún evento en la agenda con la fecha pasada por parámetro.
// Recibe una agenda y una fecha e indica si hay algún evento en la agenda que ocurre en esa fecha
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha);

// Función para remover un evento de una agenda
// Recibe una agenda y el identificador del evento y elimina el evento con ese identificador de la agenda
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda
// PRE: El evento debe estar en la agenda
void removerDeAgendaLS(TAgendaLS& agenda, int id);

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Función para obtener el primer evento de una agenda
// Recibe una agenda y devuelve el primer evento de la agenda
// La función es Theta(1) peor caso
// PRE: La agenda no debe ser vacía
TEvento primerEventoAgendaLS(TAgendaLS agenda);

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#endif  // AGENDA_H