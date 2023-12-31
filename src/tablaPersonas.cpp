#include "../include/tablaPersonas.h"
#include "../include/personasLDE.h"

struct rep_tablaPersonas
{
    TPersonasLDE *array;
    nat tamanio;
    nat cant;
};

nat funcionDeDispersion(const char nombre[100])
{
    nat res = 0;
    nat i = 0;
    while (i < 100 && nombre[i] != '\0')
    {
        res += nat(nombre[i]);
        i++;
    }
    return res;
}

TTablaPersonas crearTTablaPersonas(int max)
{

    TTablaPersonas tabla = new rep_tablaPersonas;
    tabla->tamanio = max;
    tabla->cant = 0;
    tabla->array = new TPersonasLDE[max];
    for (nat i = 0; i < nat(max); i++)
    {
        tabla->array[i] = crearTPersonasLDE();
    }
    return tabla;
}

void insertarPersonaEnTabla(TTablaPersonas &tabla, TPersona persona)
{
    nat pos = funcionDeDispersion(nombreTPersona(persona)) % tabla->tamanio;
    insertarTPersonasLDE(tabla->array[pos], persona, 1);
    tabla->cant++;
}

void eliminarPersonaDeTTablaPersonas(TTablaPersonas &tabla, const char nombre[100])
{
    nat pos = funcionDeDispersion(nombre) % tabla->tamanio;
    eliminarPersonaConNombreTPersonasLDE(tabla->array[pos], nombre);
    tabla->cant--;
}

bool perteneceATTablaPersonas(TTablaPersonas tabla, const char nombre[100])
{
    nat pos = funcionDeDispersion(nombre)% tabla->tamanio;
    return estaPersonaConNombreEnTPersonasLDE(tabla->array[pos], nombre);
}

TPersona obtenerPersonaDeTTablaPersonas(TTablaPersonas tabla, const char nombre[100])
{
    nat pos = funcionDeDispersion(nombre)% tabla->tamanio;
    return obtenerPersonaConNombreTPersonasLDE(tabla->array[pos], nombre);
}

void liberarTTablaPersonas(TTablaPersonas &tabla)
{
    for (nat i = 0; i < tabla->tamanio; i++)
    {
        liberarTPersonasLDE(tabla->array[i]);
    }
    delete[] tabla->array;
    delete tabla;
    tabla = NULL;
}

void imprimirTTablaPersonas(TTablaPersonas tabla)
{
    for (nat i = 0; i < tabla->tamanio; i++)
    {
        imprimirTPersonasLDE(tabla->array[i]);
    }
}