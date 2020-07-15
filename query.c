#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"
#include "query.h"
#include <errno.h>
#include <stdio.h>
#define EPSILON 0.01

int compare(double num1, double num2)
{
    return num1*100 - num2*100;  // Multiplicamos por 100 porque sabemos que estan truncados a dos decimales.
}

queryList addInOrder(queryList list, double elem, const char * name, int * error)
{
    int c;
    if (list == NULL || (c = compare(elem, list->elem)) > 0 )
    {
        queryList aux = calloc(1,sizeof(qNode));
        if (errno == ENOMEM)  // Verifico que no haya error de memoria.
        {
            *error = 1;
            return list;
        }
        aux->elem = elem;
        strncpy(aux->name, name, MAX_NAME);
        aux->tail = list;
        return aux;
    }
    if (c <= 0)
        list->tail = addInOrder(list->tail, elem, name, error);
    return list;
}

double division (double a, double b) 
{
    if (abs(b) < EPSILON) // verifico division por 0
    {
        return -1;   
    }
    return  ((int) ((a/b)*100))/100.0;
}

int makeQueries12(const listADT list, queryList * query1, queryList * query2) 
{
    int error = 0;
    toBegin(list);
    while (hasNext(list) && !error)
    {
        char * name = getNAME(list);
        int count = getCOUNT(list);
        double div = division(count, getELEM(list));
        if (div == -1)
        {
            error = 2; // verifico division por 0
            break;   
        }
        *query1 = addInOrder(*query1, count, name, &error);
        *query2 = addInOrder(*query2, div ,name, &error);
        // No verificamos el return de las funciones getNAME, getELEM y getCOUNT porque si falla la validacion del hasNext se corta el while,
        // mientras que hasNext devulva que el nodo usado para obtener la informacion es valido, las funciones getNAME, getELEM y getCOUNT no fallaran.
        next(list);
    }
    return error;
}

int makeQuery3 (const listADT list, queryList * query3) 
{
    int error = 0;
    toBegin(list);
    while (hasNext(list) && !error)
    {
        double div = division(getELEM(list), getCOUNT(list));
        if (div == -1)
        {
            error = 2; // verifico division por 0
            break;
        }
        *query3 = addInOrder(*query3, div, getNAME(list), &error);
        // No verificamos el return de las funciones getNAME, getELEM y getCOUNT porque si falla la validacion del hasNext se corta el while,
        // mientras que hasNext devulva que el nodo usado para obtener la informacion es valido, las funciones getNAME, getELEM y getCOUNT no fallaran.
        next(list);
    }
    return error;
}

void freeQuery (queryList query)
{
    if (query == NULL)
        return;
    freeQuery(query->tail);
    free(query);
}