#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"

#define MAX_LINE_LENGTH 300
#define MAX_NAME_LENGTH 50
#define DELIM ";"

int readFile(const char * path, const char * columnas, void (*storage) (const char * columnas, char * linea/*, listADT * listas */)/*, listADT * listas*/)
{
    FILE * archivo = fopen(path, "r");
    if (archivo == NULL)
    {
        printf("Error: Can't open file\n");
        return 1;
    }
    char linea[MAX_LINE_LENGTH];
    fgets(linea, MAX_LINE_LENGTH, archivo); // salteamos la primera linea que contiene los encabezados
    while (fgets(linea, MAX_LINE_LENGTH, archivo))
    {
        storage(columnas, linea/*, listas */);
    }
    fclose(archivo);
    return 0;
}

void storageBarrio(const char * columnas, char * linea/*, listADT * listas */)
{
    int i;
    char * token;
    for (token = strtok(linea, DELIM), i = 1; i <= linea[1]; i++, token = strtok(NULL, DELIM))
    {
        if (i == linea[0])
        {
            char barrio[MAX_NAME_LENGTH] = token;
        }
        else if (i == linea[1])
        {
            double habitantes = atof(token);
        }
    }
    // add listADT
}

void storageArboles(const char * columnas, char * linea/*, listADT * listas */)
{
    int i;
    char * token;
    for (token = strtok(linea, DELIM), i = 1; i <= linea[2]; i++, token = strtok(NULL, DELIM))
    {
        if (i == linea[0])
        {
            char barrio[MAX_NAME_LENGTH] = token;
        }
        else if (i == linea [1])
        {
            char nombre[MAX_NAME_LENGTH] = token;
        }
        else if (i == linea [2])
        {
            double diametro = atof(token);
        }
    }
    // add listADT 
}