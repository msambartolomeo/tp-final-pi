#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"
#include "query.h"
#define EPSILON 0.01

// Devuleve 0 si los numeros son iguales, < 0 si num1 < num2, > 0 si num1 > num2.
int compare(double num1, double num2)
{
    double resta = num1 - num2;
    if (abs(resta) < EPSILON)
        return 0;
    return resta;
}

// Recibe una queryList, un elem del tipo double y un string,
 // al agregar ordena por el valor de elem descendientemente.
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

// Devuelve la division de dos numeros reales truncados a dos decimales.
double division (double a, double b) 
{
    return  ( (int) ((a/b)*100))/100.0;
}

void queries12 (listADT list, queryList list1, queryList list2) 
{
    while (hasNext(list))
    {
        addInOrder(list1, getCOUNT(list), getNAME(list));
        addInOrder(list2, division(getCOUNT(list), getELEM(list)), getNAME(list));
        next(list);
    }
}

void query3 (listADT list, queryList list3) 
{
    while (hasNext(list))
    {
        addInOrder(list3, division(getELEM(list), getCOUNT(list)), getNAME(list));
        next(list);
    }
}