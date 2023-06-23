#include "../include/colaDePrioridadPersona.h"
#include "../include/utils.h"
#include "../include/evento.h"
#include "../include/fecha.h"
struct Elem
{
  TPersona persona;
  TFecha fechaPrioridad;
};
struct rep_colaDePrioridadPersona
{
  Elem *array;
  nat tamanio;
  nat cant;
  TFecha *prioridades;
  bool invertido;
};
TFecha obtenerFechaPrioridad(TPersona persona)
{
  return fechaTEvento(primerEventoDeTPersona(persona));
}
TColaDePrioridadPersona crearCP(nat N)
{
  TColaDePrioridadPersona cp = new rep_colaDePrioridadPersona();
  cp->array = new Elem[N + 1];
  cp->tamanio = N;
  cp->cant = 0;
  cp->prioridades = new TFecha[N + 2];
  cp->array[0].fechaPrioridad = NULL;
  cp->array[0].persona = NULL;
  cp->invertido = false;
  for (nat i = 0; i <= N + 1; i++)
  {
    cp->prioridades[i] = NULL;
  }
  for (nat i = 0; i <= N; i++)
  {
    cp->array[i].fechaPrioridad = NULL;
    cp->array[i].persona = NULL;
  }
  return cp;
}
void imprimirColaDePrioridadPersona(TColaDePrioridadPersona cp)
{
  printf("##############\n");

  for (nat i = 1; i <= cp->cant; i++)
  {
    imprimirTPersona(cp->array[i].persona);
    printf("Prioridad: ");
    imprimirTFecha(cp->array[i].fechaPrioridad);
    printf("\n");
  }
  printf("##############\n");
}
int compararConInversion(TFecha fecha1, TFecha fecha2, bool invertido)
{
  if (invertido)
  {
    return -1 * compararTFechas(fecha1, fecha2);
  }
  return compararTFechas(fecha1, fecha2);
}

void filtradoAscendente(TColaDePrioridadPersona &cp, nat i)
{
  nat iter = i;
  Elem swap = cp->array[iter];
  while (iter > 1 && (compararConInversion(cp->prioridades[idTPersona(cp->array[iter / 2].persona)], cp->prioridades[idTPersona(swap.persona)], cp->invertido) == 1))
  {
    printf("Iter: %d\n", iter);
    cp->array[iter] = cp->array[iter / 2];
    iter = iter / 2;
  }
  cp->array[iter] = swap;
}
void invertirPrioridad(TColaDePrioridadPersona &cp)
{
  imprimirColaDePrioridadPersona(cp);
  cp->invertido = !cp->invertido;
  nat tope = cp->cant;
  for (nat i = tope; (nat)tope / 2 < i; --i)
  {
    filtradoAscendente(cp, i);
  }
  imprimirColaDePrioridadPersona(cp);
}

void liberarCP(TColaDePrioridadPersona &cp)
{
  if (!estaVaciaCP(cp))
  {
    for (nat i = 1; i <= cp->cant; i++)
    {
      liberarTPersona(cp->array[i].persona);
    }
  }
  delete[] cp->array;
  delete[] cp->prioridades;
  delete cp;
}

void insertarEnCP(TPersona persona, TColaDePrioridadPersona &cp)
{
  cp->cant = cp->cant + 1;
  cp->array[cp->cant].persona = persona;
  cp->array[cp->cant].fechaPrioridad = obtenerFechaPrioridad(persona);
  cp->prioridades[idTPersona(persona)] = obtenerFechaPrioridad(persona);
  nat i = cp->cant;
  while ((compararConInversion(cp->array[i / 2].fechaPrioridad, cp->array[i].fechaPrioridad, cp->invertido) == 1) && (cp->array[i / 2].persona != NULL))
  {
    Elem aux = cp->array[i / 2];
    cp->array[i / 2] = cp->array[i];
    cp->array[i] = aux;
    i = i / 2;
  }
}

bool estaVaciaCP(TColaDePrioridadPersona cp)
{
  return cp->cant == 0;
}

TPersona prioritaria(TColaDePrioridadPersona cp)
{

  return cp->array[1].persona;
}

void eliminarPrioritaria(TColaDePrioridadPersona &cp)
{
  if (estaVaciaCP(cp))
  {
    return;
  }
  Elem min = cp->array[1];
  Elem ult = cp->array[cp->cant];
  nat iter = 1;
  nat hijo = iter * 2;
  for (iter = 1; iter * 2 <= cp->cant; iter = hijo)
  {
    hijo = iter * 2;
    if (hijo != cp->cant && compararConInversion(cp->array[hijo].fechaPrioridad, cp->array[hijo + 1].fechaPrioridad, cp->invertido) == 1)
    {
      hijo++;
    }
    if (compararConInversion(cp->array[hijo].fechaPrioridad, ult.fechaPrioridad, cp->invertido) == 1)
    {
      break;
    }
    cp->array[iter] = cp->array[hijo];
  }
  cp->array[iter] = ult;
  cp->prioridades[idTPersona(min.persona)] = NULL;
  liberarTPersona(min.persona);

  cp->cant--;
}

bool estaEnCP(nat id, TColaDePrioridadPersona cp)
{

  return cp->prioridades[id] != NULL;
}

TFecha prioridad(nat id, TColaDePrioridadPersona cp)
{
  return cp->prioridades[id];
}