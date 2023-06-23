#include "../include/aplicaciones.h"
#include "../include/fecha.h"
#include "../include/colaDePrioridadPersona.h"
#include "../include/tablaPersonas.h"
// Dada una tabla de personas 't' y un arreglo de nombres 'nombres' de
// longitud 'n', imprime en pantalla los datos de las personas en 'nombres'
// que están en 't', en orden de fecha de su evento más próximo.
// Se asume que los IDs de las personas están acotados entre 1 y MAX_ID.
// El tiempo de ejecución en promedio es O(n*log n+ n*m), siendo 'n' la cantidad de nombres y
// 'm' es la cantidad de eventos de la agenda con mas eventos entre todas las personas de la tabla.
// Se debe utilizar una cola de prioridad auxiliar para resolver el problema.
void listarEnOrden(TTablaPersonas t, char** nombres, nat n) {
    TColaDePrioridadPersona cp = crearCP(MAX_ID);

    for (nat i = 0; i < n; i++) {
        if (perteneceATTablaPersonas(t, nombres[i])) {
            TPersona persona = obtenerPersonaDeTTablaPersonas(t, nombres[i]);
            insertarEnCP(persona, cp);
        }
    }

    // while (!estaVaciaCP(cp)) {
    //     TPersona persona = prioritaria(cp);
    //     imprimirTPersona(persona);
    //     printf("\n");
    //     eliminarPrioritaria(cp);
    // }

    liberarCP(cp);
}