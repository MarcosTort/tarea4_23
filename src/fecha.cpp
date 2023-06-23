#include "../include/fecha.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 3 //////
///////////////////////////////////

struct rep_fecha
{
    nat dia;
    nat mes;
    nat anio;
};
nat diasDelMes(TFecha fecha)
{
    nat mes = fecha->mes;
    nat anio = fecha->anio;
    nat res = 0;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        res = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        res = 30;
        break;
    case 2:
        if (anio % 4 == 0)
        {
            res = 29;
        }
        else
        {
            res = 28;
        }
        break;
    }
    return res;
}

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha)
{
    delete fecha;
    fecha = NULL;
}
void imprimirTFecha(TFecha fecha)
{
    printf("%d/%d/%d", fecha->dia, fecha->mes, fecha->anio);
    printf("\n");
}

void aumentarTFecha(TFecha &fecha, nat dias)
{

    fecha->dia += dias;
    while (fecha->dia > diasDelMes(fecha))
    {
        fecha->dia -= diasDelMes(fecha);
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes -= 12;
            fecha->anio++;
        }
    }
}

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    if (fecha1 == NULL || fecha2 == NULL)
    {
        return 0;
    }
    nat res = 0;
    if (fecha1->anio > fecha2->anio)
    {
        res = 1;
    }
    else if (fecha1->anio < fecha2->anio)
    {
        res = -1;
    }
    else
    {
        if (fecha1->mes > fecha2->mes)
        {
            res = 1;
        }
        else if (fecha1->mes < fecha2->mes)
        {
            res = -1;
        }
        else
        {
            if (fecha1->dia > fecha2->dia)
            {
                res = 1;
            }
            else if (fecha1->dia < fecha2->dia)
            {
                res = -1;
            }
        }
    }
    return res;
}
TFecha copiarTFecha(TFecha fecha)
{
    TFecha copia = crearTFecha(fecha->dia, fecha->mes, fecha->anio);
    return copia;
}

/////////////////////////////////
////// FIN CÓDIGO TAREA 3 //////
/////////////////////////////////
