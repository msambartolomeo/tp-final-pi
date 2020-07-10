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

void queries12 (listADT list, queryList list1, queryList list2);
void query3 (listADT list, queryList list3);

#endif