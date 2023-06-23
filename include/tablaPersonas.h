/*
  Módulo de definición de 'TTablaPersonas'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef TABLAPRESONAS_H
#define TABLAPRESONAS_H

#include "personasLDE.h"
#include "utils.h"

// Definición de tipo TablaPersona como un puntero a rep_tablaPersonas
typedef struct rep_tablaPersonas *TTablaPersonas;

// Función para crear una nueva Tabla vacía de personas, en la que se estima que se insertarán max personas.
// La función es Theta(max) peor caso.
TTablaPersonas crearTTablaPersonas(int max);

// Función para insertar una persona en la tabla de personas.
// Para calcular la posición en la que se debe insertar a la persona en
// la tabla de dispersión abierta se debe utilizar la función brindada funcionDeDispersion
// (la función está declarada al comienzo de tablaPersonas.cpp.
// Esta función recibe el nombre de una persona y devuelve un natural calculado como
// la suma de los valores ascii de los caracteres que conforman el nombre.
// La persona debe ser insertada en la posición p = funcionDeDispersion(nombrePersona) % tamanio,
// donde % es la operación de módulo y tamanio es el tamaño con el que se creó la tabla de dispersión.
// Por convención se deberá insertar la persona al comienzo de la lista asociada a esa posición.
// La función asocia a la persona con el nombre de la persona.
// PRE: !perteneceATTablaPersonas(tabla, nombreTPersona(persona))
// La función es Theta(1) peor caso
void insertarPersonaEnTabla(TTablaPersonas &tabla, TPersona persona);

// Función para eliminar a la persona de nombre "nombre" de la TTablaPersonas "tabla".
// La función libera la memoria de la persona eliminada. 
// La función es Theta(m) promedio, donde m es la cantidad de eventos en la agenda de la persona con nombre "nombre".
// PRE: perteneceATTablaPersonas(tabla, nombre)
void eliminarPersonaDeTTablaPersonas(TTablaPersonas &tabla, const char nombre[100]);

// Función para verificar si en una TTablaPersonas "tabla" existe una persona con nombre "nombre".
// Devuelve true si existe, false en caso contrario.
// La función es Theta(1) promedio.
bool perteneceATTablaPersonas(TTablaPersonas tabla, const char nombre[100]);

// Función para obtener la persona con nombre "nombre" de la TTablaPersonas "tabla".
// La función es Theta(1) promedio.
// PRE: perteneceATTablaPersonas(tabla, nombre)
TPersona obtenerPersonaDeTTablaPersonas(TTablaPersonas tabla, const char nombre[100]);

// Función para liberar la memoria asignada a una TTablaPersonas (tabla) de personas
// La función es O(n*m + max) peor caso, donde n es la cantidad de personas en la tabla y m es la cantidad de eventos de la agenda con mas eventos entre todas las personas de la tabla.
void liberarTTablaPersonas(TTablaPersonas &tabla);

// Función para imprimir todas las personas de la TTablaPersonas "tabla" .
// Imprime cada persona de la tabla, en orden creciente de posiciones asociadas en la tabla.
// En caso de que haya más de una persona en la misma posición, se deben imprimir por orden
// de ingreso a la tabla, desde la más reciente a la menos.
// La función es Theta(n*m + max) peor caso, donde n es la cantidad de personas en la tabla y m es la cantidad de eventos de la agenda con mas eventos entre todas las personas de la tabla.
void imprimirTTablaPersonas(TTablaPersonas tabla);

#endif  // TABLAPRESONAS_H
