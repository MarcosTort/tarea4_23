/* 4882351 - 4872106 */
#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/cola_prioridad.h"
#include <stdlib.h>
#include <stdio.h>


struct Elem {
	prio_t prio;
	info_t info;
};

struct rep_cola_prioridad { 
	Elem * array;
	unsigned int tamanio;
	unsigned int cant;	
	//prio_t max_prio;
	unsigned int *prioridades;
};

typedef Elem elem_t;


cola_prioridad_t crear_cp(unsigned int tamanio, prio_t max_prioridad) {
  	cola_prioridad_t cp = new rep_cola_prioridad();

  	cp->array = new Elem[tamanio + 1];
  	cp->tamanio = tamanio;
  	cp->cant = 0;
  	cp->prioridades = new unsigned int[max_prioridad + 2];
  	cp->array[0].prio = max_prioridad + 1;
  	cp->array[0].info = NULL;

  	for (unsigned int i = 0 ; i <= max_prioridad +1; i++) {
  		cp->prioridades[i] = 0;
  	}

  	for (unsigned int i = 0 ; i <= tamanio; i++) {
  		cp->array[i].prio =  max_prioridad +1;
  	}
  
  	return cp;
}

void insertar_en_cp(info_t i, prio_t p, cola_prioridad_t &cp) {

	cp->cant = cp->cant + 1;
	//cp->prioridades[p] = true;
	unsigned int iter = cp->cant;
	cp->prioridades[p] = iter;
	cp->array[iter].info = i;
	cp->array[iter].prio = p;
	cp->prioridades[p] = iter;

	while ((cp->array[iter/2].prio > cp->array[iter].prio ) && (cp->array[iter/2].info != NULL)) {
		elem_t aux = cp->array[iter/2];
		cp->array[iter/2] = cp->array[iter];
		cp->prioridades[cp->array[iter/2].prio] = iter/2;
		cp->array[iter] = aux;
		cp->prioridades[cp->array[iter].prio] = iter;
		iter = iter/2;
	}

}

void priorizar(prio_t p, cola_prioridad_t &cp) {

	
	unsigned int iter = cp->prioridades[p];
		//	printf("dadasndfksdjdgkjgskjdgsklaaSDFGHJFAD %i\n", iter );
	cp->prioridades[p] = 0;
	cp->prioridades[p/2] = iter;
	cp->array[iter].prio = p/2;

	while ((cp->array[iter/2].prio > cp->array[iter].prio ) && (cp->array[iter/2].info != NULL)) {
		elem_t aux = cp->array[iter/2];
		cp->array[iter/2] = cp->array[iter];
		cp->prioridades[cp->array[iter/2].prio] = iter/2;
		cp->array[iter] = aux;
		cp->prioridades[cp->array[iter].prio] = iter;
		iter = iter/2;
	}
	
}


void despriorizar(prio_t p, cola_prioridad_t &cp) {

	//elem_t ult_elem = cp->array[cp->cant];

	unsigned int iter = cp->prioridades[p];


	unsigned int new_prio = ((p + (cp->array[0].prio - 1)) /2);
	cp->array[iter].prio = new_prio;

	elem_t aux = cp->array[iter];
	unsigned int hijo = iter*2;
	//unsigned int i;
	cp->prioridades[p] = 0;
	cp->prioridades[new_prio] = iter;

	while ( iter*2 <= cp->cant) {
		hijo = iter*2;

		if ( (hijo != cp->cant) && (cp->array[hijo +1 ].prio < cp->array[hijo].prio)) {
			hijo++;
		}
	
		if ( cp->array[iter].prio > cp->array[hijo].prio) {
			cp->array[iter] = cp->array[hijo];
			cp->prioridades[cp->array[iter].prio] = iter;
			cp->array[hijo] = aux;
			cp->prioridades[cp->array[hijo].prio] = hijo;
			iter = hijo;
		} else {
			break;
		}
	}

}

void eliminar_prioritario(cola_prioridad_t &cp) {

	elem_t min_elem = cp->array[1];
	elem_t ult_elem = cp->array[cp->cant];

	unsigned int i = 1;
	unsigned int hijo = i*2;

	for (i=1; i*2 <= cp->cant; i=hijo ) {

		hijo = i*2;

		if ( (hijo != cp->cant) && (cp->array[hijo +1 ].prio < cp->array[hijo].prio)) {
			hijo++;
		}

		if ( ult_elem.prio > cp->array[hijo].prio) {
			cp->array[i] = cp->array[hijo];
			cp->prioridades[cp->array[i].prio]= i;

		} else {
			break;
		}
	}

	cp->array[i] = ult_elem;

	liberar_info(min_elem.info);
	cp->prioridades[min_elem.prio] = 0;
	cp->cant--;

}

void liberar_cp(cola_prioridad_t &cp) {

	if (!es_vacia_cp(cp)) {
		for (unsigned int i=1 ; i <= (cp->cant); i++) {
			liberar_info(cp->array[i].info);
		}
	}
	
	delete[] cp->array;
	delete[] cp->prioridades;
	delete cp;

}

bool es_vacia_cp(cola_prioridad_t cp) {
  return (cp->cant==0);

}

bool es_llena_cp(cola_prioridad_t cp) {
  return (cp->cant == cp->tamanio);
}

bool hay_prioridad(prio_t p, cola_prioridad_t cp) {
 return (cp->prioridades[p] != 0);
}

info_t prioritario(cola_prioridad_t cp) {
  return (cp->array[1].info);
}

prio_t prioridad_prioritario(cola_prioridad_t cp) {
  return (cp->array[1].prio);
}

prio_t max_prioridad(cola_prioridad_t cp) {
  return (cp->array[0].prio -1);
}
