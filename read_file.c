#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"

#define MAX_LINE_LENGTH 300
#define DELIM ";"

int readFile(const char * path, const char * columnas, void (*storage) (const char * columnas, char * linea, listADT * listas), listADT * listas)
{
    FILE * archivo = fopen(path, "r");
    if (archivo == NULL)
    {
        fprintf(stderr,"Error: Can't open file");
        return 1;
    }
    char linea[MAX_LINE_LENGTH];
    fgets(linea, MAX_LINE_LENGTH, archivo); // salteamos la primera linea que contiene los encabezados
    while (fgets(linea, MAX_LINE_LENGTH, archivo))
    {
        storage(columnas, linea, listas);
    }
    fclose(archivo);
    return 0;
}

void storageBarrio(const char * columnas, char * linea, listADT * listas)
{
    int i;
    char * token, barrio[MAX_NAME];
    double habitantes;
    for (token = strtok(linea, DELIM), i = 1; i <= linea[1]; i++, token = strtok(NULL, DELIM))
    {
        if (i == linea[0])
        {
            strcpy(barrio, token);
        }
        else if (i == linea[1])
        {
            habitantes = atof(token);
        }
    }
    addSinCount(listas[0], barrio, habitantes);
}

void storageArboles(const char * columnas, char * linea, listADT * listas)
{
    int i;
    char * token, barrio[MAX_NAME], nombre[MAX_NAME];
    double diametro;
    for (token = strtok(linea, DELIM), i = 1; i <= linea[2]; i++, token = strtok(NULL, DELIM))
    {
        if (i == linea[0])
        {
            strcpy(barrio, token);
        }
        else if (i == linea [1])
        {
            strcpy(nombre, token);
        }
        else if (i == linea [2])
        {
            diametro = atof(token);
        }
    }
    addSinElem(listas[0],barrio);
    addAll(listas[1], nombre, diametro);
}

/*int WriteFile(Tlist lista, char * name, char * encabezado)
{
    FILE * archivo = fopen(name,"w");
    if (archivo == NULL)
    {
        fprintf(stderr,"Error: Can't open file");
        return 1;
    }
    fputs(encabezado,archivo);
    fclose(archivo);
    return 0;
}*/