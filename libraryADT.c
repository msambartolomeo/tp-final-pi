#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "libraryADT.h"

typedef struct node
{
    char name[MAX_NAME];
    unsigned int count;  // Contador de cantidad de árboles por barrio o de cantidad de árboles cada especie.
    double elem;         // Almacenar la cantidad de habitantes por barrio o la suma de todos los diametros de los arboles de una especie.
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
    if (errno == ENOMEM) // Verifico que no haya error de memoria
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

// Recibe un tNode, un string, un elem del tipo double, un count (1 o 0), un flag (1 o 0) y un puntero a error.
// El flag indica si se debe copiar la infomacion en un nuevo nodo o solamnete incrementar los contadores,
// cuando el string recibido es igual a un ya existente en la lsta.
static tNode * addRec(tNode * first, char * name, double elem, unsigned int count, int flag, int * error)
{
    int c;
    if (first == NULL || (c = strcmp(name, first->name)) < 0)
    {
        if (flag)
        {
            tNode * aux = calloc(1,sizeof(tNode));
            if (errno == ENOMEM) // Verifico que no haya error de memoria 
            {
                *error = 1;
                return first;
            }
            strcpy(aux->name, name);
            aux->count += count;
            aux->elem += elem;
            aux->tail = first;
            return aux;
        }
        else
        {
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

int addElem(listADT list, char * name, double elem)
{
    int error = 0;
    list->first = addRec(list->first, name, elem, 0, 1, &error); // El flag esta en 1 porque hay agregar.
    return error;
}

void addCount(listADT list, char * name)
{
    list->first = addRec(list->first, name, 0, 1, 0, NULL); // Elem y el flag son 0 para que solo cambie el campo de count.
    return; // No es necesario que devuelva el error porque, por cómo está diseñada, nunca puede fallar. Si no encuentra el nodo, lo ignora y no lo añade a la lista.
}

int addAll(listADT list, char * name, double elem)
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

unsigned int getCOUNT(listADT list)
{
    if ( !hasNext(list) )
    {
        //validacion del mensaje de error
        //fprintf(stderr,"Error: No current node");
        //exit(1);
    }
    return list->current->count;
}

double getELEM(listADT list)
{
    if ( !hasNext(list) )
    {
        //validacion del mensaje de error
        //fprintf(stderr,"Error: No current node");
        //exit(1);
    }
    return list->current->elem;
}

char * getNAME(listADT list)
{
    if ( !hasNext(list) )
    {
        //validacion del mensaje de error
        //fprintf(stderr,"Error: No current node");
        //exit(1);
    }
   return list->current->name;
}

void next(listADT list)
{
    if ( !hasNext(list) )
    {
        //validacion del mensaje de error
        //fprintf(stderr,"Error: No current node");
        //exit(1);
    }
    list->current = list->current->tail;
}