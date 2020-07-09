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

#endif
