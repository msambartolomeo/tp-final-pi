#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"
#include "query.h"
#include <errno.h>
#include <stdio.h>

int compare(double num1, double num2)
{
    return num1*100 - num2*100;  // Multiplicamos por 100 porque sabemos que estan truncados a dos decimales.
}

queryList addInOrder(queryList list, double elem, char * name, int * error)
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
        strcpy(aux->name, name);
        aux->tail = list;
        
        return aux;
        
    }
    if (c <= 0)
        list->tail = addInOrder(list->tail, elem, name, error);
    return list;
}

double division (double a, double b) 
{
    return  ((int) ((a/b)*100))/100.0;
}

int makeQueries12(listADT list, queryList * query1, queryList * query2) 
{
    int error = 0;
    toBegin(list);
    while (hasNext(list) && !error)
    {
        char * name = getNAME(list);
        int count = getCOUNT(list);
        double elem = getELEM(list);
        if (name == NULL || count == -1 || elem || -1)
        {
            return 1;   // Error: no se pudo obtener los parametros deseados.
        }
        *query1 = addInOrder(*query1, count, name, &error);
        *query2 = addInOrder(*query2, division(count, elem),name, &error);
        next(list);
    }
    return error;
}

int makeQuery3 (listADT list, queryList * query3) 
{
    int error = 0;
    toBegin(list);
    while (hasNext(list) && !error)
    {
        char * name = getNAME(list);
        int count = getCOUNT(list);
        double elem = getELEM(list);
        if (name == NULL || count == -1 || elem || -1)
        {
            return 1;   // Error: no se pudo obtener los parametros deseados.
        }
        *query3 = addInOrder(*query3, division(elem, count), name, &error);
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