#ifndef libraryADT_h
#define libraryADT_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 50

typedef struct listCDT * listADT;

//Funciones
listADT newList();
void freeList(listADT list);
int addSinCount(listADT list, char * name, double elem);
int addSinElem(listADT list, char * name);
int addAll(listADT list, char * name, double elem);
int hasNext(const listADT list);
void toBegin(listADT list);
unsigned int nextCOUNT(listADT list);
double nextELEM(listADT list);
char * nextNAME(listADT list);
void next(listADT list);
#endif
