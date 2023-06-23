#include "../include/personasLDE.h"
struct nodo
{
    TPersona persona;
    nodo *anterior;
    nodo *siguiente;
};
typedef nodo *Nodo;
struct rep_personasLDE
{

    Nodo inicio;
    Nodo fin;
};

TPersonasLDE crearTPersonasLDE()
{
    TPersonasLDE personas = new rep_personasLDE;
    personas->inicio = NULL;
    personas->fin = NULL;
    return personas;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos)
{
    Nodo nuevo = new nodo;
    nuevo->persona = persona;

    if (pos == 1)
    { // insertar al inicio de la lista vacia
        if (personas->inicio == NULL)
        {
            personas->inicio = nuevo;
            personas->fin = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
        }
        else
        {
            // insertar al inicio de la lista no vacia
            nuevo->siguiente = personas->inicio;
            personas->inicio->anterior = nuevo;
            nuevo->anterior = NULL;
            personas->inicio = nuevo;
        }
    }
    else
    {
        // insertar la persona despues del inicio
        Nodo aux = personas->inicio;
        if (aux != NULL)
        {
            // buscar la posicion
            nat i = 1;

            while (aux->siguiente != NULL && pos >= i)
            {
                aux = aux->siguiente;
                i++;
            }
            // insertar al final
            if (pos != i)
            {
                nuevo->anterior = personas->fin;
                personas->fin->siguiente = nuevo;
                personas->fin = nuevo;
                nuevo->siguiente = NULL;
            }
            // insertar en la posicion
            else

            {
                nuevo->anterior = aux->anterior;
                aux->anterior->siguiente = nuevo;
                nuevo->siguiente = aux;
                aux->anterior = nuevo;
            }
        }
        // insertar al inicio de la lista vacia
        else

        {
            personas->inicio = nuevo;
            personas->fin = nuevo;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
        }
    }
}

void liberarTPersonasLDE(TPersonasLDE &personasLDE)
{
    Nodo a_borrar;
    while (personasLDE->inicio != NULL)
    {
        a_borrar = personasLDE->inicio;
        personasLDE->inicio = personasLDE->inicio->siguiente;
        liberarTPersona(a_borrar->persona);
        delete (a_borrar);
    }
    delete personasLDE;
    personasLDE = NULL;
}

void imprimirTPersonasLDE(TPersonasLDE personas)
{

    Nodo aux = personas->inicio;
    while (aux != NULL && aux->persona != NULL)
    {
        imprimirTPersona(aux->persona);
        aux = aux->siguiente;
    }
}

nat cantidadTPersonasLDE(TPersonasLDE personas)
{
    nat cant = 0;
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        cant++;
        aux = aux->siguiente;
    }
    return cant;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas)
{
    Nodo a_borrar = personas->inicio;
    if (a_borrar != NULL)
    {

        if (a_borrar == personas->fin)
        {
            personas->fin = NULL;
            personas->inicio = NULL;
        }
        else
        {
            personas->inicio = a_borrar->siguiente;
            a_borrar->siguiente->anterior = NULL;
        }

        liberarTPersona(a_borrar->persona);
        delete a_borrar;
    }
}

void eliminarFinalTPersonasLDE(TPersonasLDE &personas)
{

    Nodo a_borrar = personas->fin;
    if (a_borrar != NULL)
    {

        if (a_borrar == personas->inicio)
        {

            personas->fin = NULL;
            personas->inicio = NULL;
            liberarTPersona(a_borrar->persona);
            delete a_borrar;
        }
        else
        {

            personas->fin = a_borrar->anterior;
            a_borrar->anterior->siguiente = NULL;
            liberarTPersona(a_borrar->persona);
            delete a_borrar;
        }
    }
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id)
{
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (id == idTPersona(aux->persona))
        {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id)
{
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (id == idTPersona(aux->persona))
        {
            return aux->persona;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2)
{
    TPersonasLDE personas = crearTPersonasLDE();
    if (personas1->inicio != NULL && personas2->inicio != NULL)
    {
        personas->inicio = personas1->inicio;
        personas->fin = personas2->fin;
        personas1->fin->siguiente = personas2->inicio;
        personas2->inicio->anterior = personas1->fin;
    }
    else
    {
        if (personas1->inicio != NULL)
        {
            personas->inicio = personas1->inicio;
            personas->fin = personas1->fin;
        }
        else
        {
            personas->inicio = personas2->inicio;
            personas->fin = personas2->fin;
        }
    }
    delete personas1;
    delete personas2;
    return personas;
}
///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void insertarInicioDeTPersonasLDE(TPersonasLDE &personas, TPersona persona)
{

    insertarTPersonasLDE(personas, persona, 1);
}

void insertarFinalDeTPersonasLDE(TPersonasLDE &personas, TPersona persona)
{

    if (personas->inicio == NULL)
    {
        insertarTPersonasLDE(personas, persona, 1);
    }
    else
    {
        Nodo nuevo = new nodo;
        nuevo->persona = persona;
        nuevo->anterior = personas->fin;
        personas->fin->siguiente = nuevo;
        personas->fin = nuevo;
        nuevo->siguiente = NULL;
    }
}

TPersona obtenerInicioDeTPersonasLDE(TPersonasLDE personas)
{
    return personas->inicio->persona;
}

TPersona obtenerFinalDeTPersonasLDE(TPersonasLDE personas)
{
    return personas->fin->persona;
}
///////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void eliminarPersonaConNombreTPersonasLDE(TPersonasLDE &personas, const char nombre[100])
{

    if (personas->inicio == NULL)
    {
        return;
    }

    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (strcmp(nombre, nombreTPersona(aux->persona)) == 0)
        {
            if (aux == personas->inicio)
            {
                eliminarInicioTPersonasLDE(personas);
            }
            else if (aux == personas->fin)
            {
                eliminarFinalTPersonasLDE(personas);
            }
            else
            {
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
                liberarTPersona(aux->persona);
                delete aux;
            }
        }
        aux = aux->siguiente;
    }
}

bool estaPersonaConNombreEnTPersonasLDE(TPersonasLDE personas, const char nombre[100])
{
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (strcmp(nombre, nombreTPersona(aux->persona)) == 0)
        {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

TPersona obtenerPersonaConNombreTPersonasLDE(TPersonasLDE personas, const char nombre[100])
{
    Nodo aux = personas->inicio;
    while (aux != NULL)
    {
        if (strcmp(nombre, nombreTPersona(aux->persona)) == 0)
        {
            return aux->persona;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
