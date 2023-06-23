#include "../include/persona.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_persona
{
    nat id;
    nat edad;
    char nombre[100];
    TAgendaLS agenda;
};

TPersona crearTPersona(nat id, nat edad, const char nombre[100], TAgendaLS agenda)
{

    TPersona persona = new rep_persona;
    persona->id = id;
    persona->edad = edad;
    strcpy(persona->nombre, nombre);
    persona->agenda = agenda;
    return persona;
}

void liberarTPersona(TPersona &persona)
{
    liberarAgendaLS(persona->agenda);
    delete persona;
}

// Imprime a la persona utilizando printf e imprimeAgendaLS
void imprimirTPersona(TPersona persona)
{
    if (persona != NULL)
    {
        printf("Persona %d: %s, %d años\n", persona->id, persona->nombre, persona->edad);

        imprimirAgendaLS(persona->agenda);
    }
}

nat idTPersona(TPersona persona)
{
    return persona->id;
}

nat edadTPersona(TPersona persona)
{
    return persona->edad;
}

char *nombreTPersona(TPersona persona)
{
    return persona->nombre;
}

TAgendaLS agendaTPersona(TPersona persona)
{
    return persona->agenda;
}

void agregarEventoATPersona(TPersona &persona, TEvento evento)
{
    agregarEnAgendaLS(persona->agenda, evento);
}

void posponerEventoEnTPersona(TPersona &persona, int id, nat n)
{
    posponerEnAgendaLS(persona->agenda, id, n);
}

void removerEventoDeTPersona(TPersona &persona, int id)
{
    removerDeAgendaLS(persona->agenda, id);
}

bool estaEnAgendaDeTPersona(TPersona persona, int id)
{
    return estaEnAgendaLS(persona->agenda, id);
}

TEvento obtenerDeAgendaDeTPersona(TPersona persona, int id)
{
    return obtenerDeAgendaLS(persona->agenda, id);
}

TPersona copiarTPersona(TPersona persona)
{
    TPersona copia = crearTPersona(persona->id, persona->edad, persona->nombre, copiarAgendaLS(persona->agenda));
    return copia;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoDeTPersona(TPersona persona){
    return primerEventoAgendaLS(persona->agenda);
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
