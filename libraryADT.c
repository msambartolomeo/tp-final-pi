#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"

typedef struct node
{
    char name[MAX_NAME]; //char * name;
    unsigned int count; //Contador de cantidad de árboles por barrio o de cantidad de árboles cada especie
    double elem; //Almacenar la cantidad de habitantes por barrio o la suma de todos los diametros de los arboles de una especie
    struct node * tail;
} tNode;

typedef struct listCDT
{
    tNode * first;
    tNode * current; //Iterador para recorrer la lista e imprimirla
} listCDT;

listADT newList()
{
    listADT new = calloc(1, sizeof(listCDT));
    if (new == NULL)
        //Código de error, insuficiente memoria. IF CON ;
    return new;   
}

static void freeRec (tNode * first)
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
    //No es necesario liberar current ya que apuntará a alguno de los nodos y será liberado automáticamente
}

//El flag indica si se debe copiar la infomacion en un nuevo nodo o solamnete prestarle atencion a los contadores cuando son iguales
static tNode * addRec(tNode * first, char * name, double elem, unsigned int count, int flag, int * error)
{
    int c;
    if ( first == NULL || (c = strcmp(name,first->name)) < 0 ) {
        if (flag)
        {
            tNode * aux = calloc(1,sizeof(tNode));
            if (aux == NULL)
            {
                *error = 1;
                return first;
            }
            strcpy(aux->name,name); //aux->name = name;
            aux->elem += elem;
            aux->count += count;
            aux->tail = first;
            return aux;
        }
        else
            return first;
    }
    if ( c == 0 )
            first->count += count;  //si son iguales los strings debo sumar los contadores pero no volver a pegar la informacion
            first->elem += elem;
            return first;
    if ( c > 0)
        first->tail = addRec(first, name, elem, count, flag, error);
    return first;
}

int addSinCount(listADT list, char * name, double elem)
{
    int error = 0;
    list->first = addRec(list->first, name, elem, 0, 1, &error);
    return error;
}

int addSinElem(listADT list, char * name)
{
    int error = 0;
    list->first = addRec(list->first, name, 0, 1, 0, &error);
    return error;
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
        fprintf(stderr,"Error: No current node"); //mensaje de error?
        exit(1);
    }
    return list->current->count;
}

double getELEM(listADT list)
{
    if ( !hasNext(list) )
    {
        fprintf(stderr,"Error: No current node"); //menasaje de error?
        exit(1);
    }
    return list->current->elem;
}

char * getNAME(listADT list)
{
    if ( !hasNext(list) )
    {
        fprintf(stderr,"Error: No current node"); //menasaje de error?
        exit(1);
    }
   return list->current->name;
}

void next(listADT list)
{
    if ( !hasNext(list) )
    {
        fprintf(stderr,"Error: No current node"); //menasaje de error?
        exit(1);
    }
    list->current = list->current->tail;
}