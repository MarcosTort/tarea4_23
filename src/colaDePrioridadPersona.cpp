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
  cp->array[0].fechaPrioridad =NULL;
  cp->array[0].persona = NULL;
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

void invertirPrioridad(TColaDePrioridadPersona &cp)
{
  nat inicio = 1;
  nat fin = cp->cant;
  while (inicio < fin)
  {
    Elem aux = cp->array[inicio];
    cp->array[inicio] = cp->array[fin];
    cp->array[fin] = aux;
    inicio++;
    fin--;
  }
  for (nat i = 1; i <= cp->cant; i++)
  {
    cp->prioridades[idTPersona(cp->array[i].persona)] = cp->array[i].fechaPrioridad;
  }
  for (nat i = 1; i <= cp->cant; i++)
  {
    nat iter = i;
    while ((compararTFechas(cp->array[iter / 2].fechaPrioridad, cp->array[iter].fechaPrioridad) == 1) && (cp->array[iter / 2].persona != NULL))
    {
      Elem aux = cp->array[iter / 2];
      cp->array[iter / 2] = cp->array[iter];
      cp->prioridades[idTPersona(cp->array[iter / 2].persona)] = obtenerFechaPrioridad(cp->array[iter / 2].persona);
      cp->array[iter] = aux;
      cp->prioridades[idTPersona(cp->array[iter].persona)] = obtenerFechaPrioridad(cp->array[iter].persona);
      iter = iter / 2;
    }
  }
   
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
  cp->prioridades[idTPersona(persona)] = obtenerFechaPrioridad(persona);
  cp->array[cp->cant].persona = persona;
  cp->array[cp->cant].fechaPrioridad = obtenerFechaPrioridad(persona);
  cp->prioridades[idTPersona(persona)] = obtenerFechaPrioridad(persona);
  nat iter = cp->cant;
  while ((compararTFechas(cp->array[iter / 2].fechaPrioridad, cp->array[iter].fechaPrioridad) == 1) && (cp->array[iter / 2].persona != NULL))
  {
    Elem aux = cp->array[iter / 2];
    cp->array[iter / 2] = cp->array[iter];
    cp->prioridades[idTPersona(cp->array[iter / 2].persona)] = obtenerFechaPrioridad(cp->array[iter / 2].persona);
    cp->array[iter] = aux;
    cp->prioridades[idTPersona(cp->array[iter].persona)] = obtenerFechaPrioridad(cp->array[iter].persona);
    iter = iter / 2;
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
  if(estaVaciaCP(cp)){
    return;
  }
  Elem min = cp->array[1];
  Elem ult = cp->array[cp->cant];
  nat iter = 1;
  nat hijo = iter * 2;
  for(iter = 1; iter*2 <= cp->cant; iter = hijo){
    hijo = iter * 2;
    if(hijo != cp->cant && compararTFechas(cp->array[hijo].fechaPrioridad, cp->array[hijo + 1].fechaPrioridad) == 1){
      hijo++;
    }
    if(compararTFechas(cp->array[hijo].fechaPrioridad, ult.fechaPrioridad) == 1){
      break;
    }
    cp->array[iter] = cp->array[hijo];
    cp->prioridades[idTPersona(cp->array[iter].persona)] = obtenerFechaPrioridad(cp->array[iter].persona);
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