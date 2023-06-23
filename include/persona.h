/*
  Módulo de definición de 'persona'.

  Los elementos de tipo TPersona son elementos que almacenan un id, un nombre, una edad y una agenda.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef PERSONA_H
#define PERSONA_H

#include <string.h>
#include "utils.h"
#include "agendaLS.h"

// Definición de tipo TPersona como un puntero a rep_persona
typedef struct rep_persona *TPersona;

// Función para crear una persona
// Devuelve una persona con el id, nombre, edad y agenda pasados por parámetro
// La función es Theta(1) peor caso
TPersona crearTPersona(nat id, nat edad, const char nombre[100], TAgendaLS agenda);

// Función para liberar la memoria asignada a una persona
// La función es Theta(n) peor caso, donde n es la cantidad de eventos en la agenda de la persona
void liberarTPersona(TPersona &persona);

// Función para imprimir una persona con el siguiente formato:
// "Persona *id*:  *nombre*, *edad* años\n"
// [agenda de la persona]
// Por ejemplo, si tenemos a la persona "Persona1" con id 1 y edad 20, y dos eventos en la agenda la función imprimirá:
// "Persona 1: Persona1, 20 años
// Evento 1:  Descripcion uno
// Fecha: 22/3/2023
// Evento 2:  Descripcion dos
// Fecha: 23/3/2023"
// La función es Theta(n) peor caso, donde n es la cantidad de eventos en la agenda de la persona
void imprimirTPersona(TPersona persona);

// Función para obtener el id de una persona
// La función es Theta(1) peor caso
nat idTPersona(TPersona persona);

// Función para obtener la edad de una persona
// La función es Theta(1) peor caso
nat edadTPersona(TPersona persona);

// Función para obtener el nombre de una persona
// La función es Theta(1) peor caso
char* nombreTPersona(TPersona persona);

// Función para obtener la agenda de una persona
// La función es Theta(1) peor caso
TAgendaLS agendaTPersona(TPersona persona);

// Función para agregar un evento a la agenda de una persona
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda de la persona
void agregarEventoATPersona(TPersona &persona, TEvento evento);

// Función para posponer un evento de la agenda de una persona
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda de la persona
// PRE: el evento está en la agenda de la persona
void posponerEventoEnTPersona(TPersona &persona, int id, nat n);

// Función para remover un evento de la agenda de una persona
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda de la persona
// PRE: el evento está en la agenda de la persona
void removerEventoDeTPersona(TPersona &persona, int id);

// Función para determinar si un evento está en la agenda de una persona
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda de la persona
bool estaEnAgendaDeTPersona(TPersona persona, int id);

// Función para obtener un evento de la agenda de una persona
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda de la persona
// PRE: el evento está en la agenda de la persona
TEvento obtenerDeAgendaDeTPersona(TPersona persona, int id);

// Función para copiar una persona
// La función es Theta(n) peor caso, siendo n la cantidad de eventos en la agenda de la persona
TPersona copiarTPersona(TPersona persona);

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Función para obtener el primer evento de la agenda de una persona
// La función es Theta(1) peor caso.
// PRE: la agenda de la persona no está vacía
TEvento primerEventoDeTPersona(TPersona persona);

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#endif