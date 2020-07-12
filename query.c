#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"
#include "query.h"
#include <errno.h>
#define EPSILON 0.01

int compare(double num1, double num2)
{
    double resta = num1 - num2;
    if (abs(resta) < EPSILON)
        return 0;
    return resta;
}

queryList addInOrder(queryList list, double elem, char * name, int * error)
{
    int c;
    if(list == NULL || (c = compare(elem, list->elem)) > 0 )
    {
        queryList aux = malloc(sizeof(qNode));
        if (errno == ENOMEM)
        {
            *error = 1;
            return aux;
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
    return  ( (int) ((a/b)*100))/100.0;
}

int makeQueries12 (listADT list, queryList list1, queryList list2) 
{
    int error = 0;
    while (hasNext(list) && !error)
    {
        addInOrder(list1, getCOUNT(list), getNAME(list), &error);
        addInOrder(list2, division(getCOUNT(list), getELEM(list)), getNAME(list), &error);
        next(list);
    }
    return error;
}

int makeQuery3 (listADT list, queryList list3) 
{
    int error = 0;
    while (hasNext(list) && !error)
    {
        addInOrder(list3, division(getELEM(list), getCOUNT(list)), getNAME(list), &error);
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