#ifndef libraryADT_h
#define libraryADT_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 50

typedef struct listCDT * listADT;

//Funciones
listADT new ();
void free (listADT list);

#endif
