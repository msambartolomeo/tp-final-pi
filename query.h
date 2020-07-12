#ifndef query_h
#define query_h

#include "libraryADT.h"

typedef struct qNode
{
    char name[MAX_NAME];
    double elem;
    struct qNode * tail;
} qNode;

typedef qNode * queryList;

// Crea una queryList nueva.
queryList newQueryList();

// Devuleve 0 si los numeros son iguales, < 0 si num1 < num2, > 0 si num1 > num2.
int compare(double num1, double num2);

// Recibe una queryList, un elem del tipo double y un string,
// al agregar ordena por el valor de elem descendientemente.
queryList addInOrder(queryList list, double elem, char * name, int * error);

// Devuelve la division de dos numeros reales truncados a dos decimales.
double division (double a, double b);

// Resuelve las queries 1 y 2.
int makeQueries12 (listADT list, queryList list1, queryList list2);

// Resuelve la query 3.
int makeQuery3 (listADT list, queryList list3);

// Libera todos los nodos de la lista.
void freeQuery (queryList query);

#endif