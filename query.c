#include "libraryADT.h"
#include <stdlib.h>
#include <string.h>
#include "query.h"
#define EPSILON 0.01

//asegurar que el listADT este en el primer nodo (toBegin)
//crear una lista para cada query

void queries12 (listADT list, queryList list1, queryList list2) 
{
    while (hasNext(list))
    {
            add(list1, getCOUNT(list), getNAME(list)); //lo que recibe la lista 1
            add(list2, division(getCOUNT(list), getELEM(list)), getNAME(list));  //lo que recibe la lista 2
        next(list);
    }
}

void query3 (listADT list, queryList list3) 
{
    while (hasNext(list))
    {
        add(list3, division(getELEM(list), getCOUNT(list)), getNAME(list)); //lo que recibe la lista 3
        next(list);
    }
}

double division (double a, double b) 
{
    return  ( (int) ((a/b)*100))/100.0;
}

int compare(double num1, double num2)
{
    double resta = num1 - num2;
    if (abs(resta) < EPSILON)
        return 0;
    return resta;
}

// Ordena por el valor de elem descendientemente
queryList addInOrder(queryList list, double elem, char * name)
{
    int c;
    if(list == NULL || (c = compare(elem, list->elem)) > 0 )
    {
        queryList aux = malloc(sizeof(qNode));
        //validacion del malloc
        aux->elem = elem;
        strcpy(aux->name, name);
        aux->tail = list;
        return aux;
    }
    if (c <= 0)
        list->tail = add(list->tail, elem, name);
    return list;
}