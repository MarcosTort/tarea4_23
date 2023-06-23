#include "../include/agendaLS.h"

struct rep_agendaLS
{
    TEvento evento;
    rep_agendaLS *sig;
};

TAgendaLS crearAgendaLS()
{
    return NULL;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento)
{
    TAgendaLS nuevoNodo = new rep_agendaLS;
    nuevoNodo->evento = evento;
    nuevoNodo->sig = NULL;

    if (agenda == NULL) {
        agenda = nuevoNodo;
    } else {
        TAgendaLS actual = agenda;
        TAgendaLS anterior = NULL;
        while (actual != NULL && compararTFechas(fechaTEvento(actual->evento), fechaTEvento(evento)) < 0) {
            anterior = actual;
            actual = actual->sig;
        }

        if (anterior == NULL) {
            nuevoNodo->sig = agenda;
            agenda = nuevoNodo;
        } else {
            anterior->sig = nuevoNodo;
            nuevoNodo->sig = actual;
        }
    }
}




void imprimirAgendaLS(TAgendaLS agenda)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        imprimirTEvento(aux->evento);
        aux = aux->sig;
    }
}

void liberarAgendaLS(TAgendaLS &agenda)
{
    TAgendaLS aux = agenda;
    while (aux != NULL )
    {
        TAgendaLS aux2 = aux;
        aux = aux->sig;
        liberarTEvento(aux2->evento);
        delete aux2;
    }
    agenda = NULL;
}

bool esVaciaAgendaLS(TAgendaLS agenda)
{
    return agenda == NULL;
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda)
{

    TAgendaLS copia = crearAgendaLS();
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        agregarEnAgendaLS(copia, copiarTEvento(aux->evento));
        aux = aux->sig;
    }
    return copia;
}

bool estaEnAgendaLS(TAgendaLS agenda, int id)
{

    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (idTEvento(aux->evento) == id)
        {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (idTEvento(aux->evento) == id)
        {
            return aux->evento;
        }
        aux = aux->sig;
    }
    return aux->evento;
}

void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n)
{
    TAgendaLS aux = agenda;
    TEvento eventoARemover = aux->evento;
    while (idTEvento(aux->evento) != id)
    {
        aux = aux->sig;
    };
    eventoARemover = aux->evento;
    TEvento nuevoEvento = copiarTEvento(eventoARemover);
    removerDeAgendaLS(agenda, id);
    posponerTEvento(nuevoEvento, n);
    agregarEnAgendaLS(agenda, nuevoEvento);
    
}

void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (compararTFechas(fechaTEvento(aux->evento), fecha) == 0)
        {
            imprimirTEvento(aux->evento);
        }
        aux = aux->sig;
    }
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (compararTFechas(fechaTEvento(aux->evento), fecha) == 0)
        {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

void removerDeAgendaLS(TAgendaLS &agenda, int id)
{

    if (agenda == NULL) { // Si la lista está vacía, no se hace nada
        return;
    }

    if (idTEvento(agenda->evento) == id) { // Si el evento está en el primer nodo
        TAgendaLS aux = agenda;
        agenda = agenda->sig;
        liberarTEvento(aux->evento);
        delete aux;
        return;
    }

    TAgendaLS aux = agenda;
    while (aux->sig != NULL)
    {
        if (idTEvento(aux->sig->evento) == id)
        {
            TAgendaLS aux2 = aux->sig;
            aux->sig = aux->sig->sig;
            liberarTEvento(aux2->evento);
            delete aux2;
            return;
        }
        aux = aux->sig;
    }
}

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEvento primerEventoAgendaLS(TAgendaLS agenda){
    return agenda->evento;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////