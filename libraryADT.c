#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "libraryADT.h"

typedef struct node
{
    char name[MAX_NAME];
    int count;    // Contador de cantidad de árboles por barrio o de cantidad de árboles cada especie.
    double elem; // Almacenar la cantidad de habitantes por barrio o la suma de todos los diametros de los arboles de una especie.
    struct node * tail;
} tNode;

typedef struct listCDT
{
    tNode * first;
    tNode * current; // Iterador para recorrer la lista e imprimirla.
} listCDT;

listADT newList()
{
    listADT new = calloc(1, sizeof(listCDT));
    if (errno == ENOMEM) // Verifico que no haya error de memoria.
        return NULL;
    return new;   
}

// Libera cada uno de los nodos de la estructura.
static void freeRec(tNode * first)
{
    if (first == NULL)
        return;
    freeRec(first->tail);
    free(first);
}

void freeList(listADT list)
{
    freeRec(list->first);
    free(list);
    // No es necesario liberar current ya que apuntará a alguno de los nodos y será liberado automáticamente.
}

// Recibe un tNode, un string, un elem del tipo double, un count, un flag (1 o 0) y un puntero a error.
// El valor count indica cuanto sumarle al campo utilizado como 
// El flag indica si se debe copiar la informacion en un nuevo nodo o solamenete incrementar los contadores,
// cuando el string recibido es igual a uno ya existente en la lista.
static tNode * addRec(tNode * first, const char * name, double elem, int count, int flag, int * error)
{
    int c;
    if (first == NULL || (c = strcmp(name, first->name)) < 0)
    {
        if (flag)
        {
            tNode * aux = calloc(1,sizeof(tNode));
            if (errno == ENOMEM) // Verifico que no haya error de memoria.
            {
                *error = 1;
                return first;
            }
            strncpy(aux->name, name, MAX_NAME);
            aux->count += count;
            aux->elem += elem;
            aux->tail = first;
            return aux;
        }
        else
        {
            *error = 1;
            return first;
        }
    }
    if ( c == 0 )
    {
        first->count += count;  // Si los strings son iguales, incremento los contadores,
        first->elem += elem;    // pero no se vuelve a insertar el resto de la informacion.
        return first;
    }
    if ( c > 0)
    {
        first->tail = addRec(first->tail, name, elem, count, flag, error);
    }
    return first;
}

int addElem(listADT list, const char * name, double elem)
{
    int error = 0;
    list->first = addRec(list->first, name, elem, 0, 1, &error); // El flag esta en 1 porque hay agregar.
    return error;                                                // El count esta en 0 porque no se quiere incrementar el contador.
}

int addCount(listADT list, const char * name)
{
    int error = 0;
    list->first = addRec(list->first, name, 0, 1, 0, &error); // Elem y el flag son 0 para que solo incrementar el campo de count.
    return error; // Si el name del nodo es distinto a los ya presentes en la lista, no lo agrega y devuelve 1. Nunca agrega nodos nuevos.
}

int addAll(listADT list, const char * name, double elem)
{
    int error = 0;
    list->first = addRec(list->first, name, elem, 1, 1, &error);
    return error;
}

int hasNext(const listADT list)
{
    return list->current != NULL;
}

void toBegin(listADT list)
{
    list->current = list->first;
}

int getCOUNT(const listADT list)
{
    if ( !hasNext(list) )
    {
        return -1;
    }
    return list->current->count;
}

double getELEM(const listADT list)
{
    if ( !hasNext(list) )
    {
        return -1;      // El campo elem es considerado posivito.
    }
    return list->current->elem;
}

char * getNAME(const listADT list)
{
    if ( !hasNext(list) )
    {
        return NULL;
    }
   return list->current->name;
}

int next(listADT list)
{
    if ( !hasNext(list) )
    {
        return 1;
    }
    list->current = list->current->tail;
    return 0;
}