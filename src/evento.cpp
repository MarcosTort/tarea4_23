#include "../include/evento.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 1 //////
///////////////////////////////////

struct rep_evento
{
    int id;
    char descripcion[MAX_DESCRIPCION];
    TFecha fecha;
};

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha)
{
    TEvento nuevoEvento = new rep_evento;
    nuevoEvento->id = id;
    strcpy(nuevoEvento->descripcion, descripcion);
    nuevoEvento->fecha = fecha;

    return nuevoEvento;
}

void imprimirTEvento(TEvento evento)
{
    if (evento->fecha != NULL)
    {
        printf("Evento %d", evento->id);
        printf(": %s\n", evento->descripcion);
        printf("Fecha: ");
        imprimirTFecha(evento->fecha);
    }
}

void liberarTEvento(TEvento &evento)
{

    liberarTFecha(evento->fecha);

    delete evento;
    evento = NULL;
}

int idTEvento(TEvento evento)
{
    nat res = 0;

    res = evento->id;
    return res;
}

TFecha fechaTEvento(TEvento evento)
{
    TFecha fecha = evento->fecha;

    return fecha;
}

void posponerTEvento(TEvento &evento, int dias)
{
    aumentarTFecha(evento->fecha, dias);
}


/////////////////////////////////
////// FIN CÓDIGO TAREA 1 //////
/////////////////////////////////

/*-----------------------------*/

///////////////////////////
////// FUNCION NUEVA //////
///////////////////////////

// Retorna una copia del evento
TEvento copiarTEvento(TEvento evento) {
    TEvento copia = crearTEvento(idTEvento(evento), evento->descripcion, copiarTFecha(evento->fecha));
    return copia;
}
