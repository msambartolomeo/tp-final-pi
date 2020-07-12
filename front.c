#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"
#include "query.h"

#define MAX_LINE_LENGTH 500
#define DELIM ";"

int readFile(const char * path, const int * columnas, int (*storage) (const int * columnas, char * linea, listADT * listas), listADT * listas)
{
    FILE * archivo = fopen(path, "r");
    if (archivo == NULL)
    {
        fprintf(stderr,"Error: Can't open file\n");
        return 2;
    }
    char linea[MAX_LINE_LENGTH];
    int error = 0;
    fgets(linea, MAX_LINE_LENGTH, archivo);        // Salteamos la primera linea que contiene los encabezados.
    while (fgets(linea, MAX_LINE_LENGTH, archivo) && !error)
    {
        error = storage(columnas, linea, listas);
    }
    fclose(archivo);
    if (error)
    {
        fprintf(stderr, "Memory allocation failure\n");
        return 1;
    }
    return 0;
}

int storageBarrio(const int * columnas, char * linea, listADT * listas)
{
    int i, flag;
    char * token, barrio[MAX_NAME];
    double habitantes;
    for (token = strtok(linea, DELIM), i = 1; i <= columnas[1]; i++, token = strtok(NULL, DELIM))
    {
        if (i == columnas[0])
        {
            strcpy(barrio, token);
        }
        else if (i == columnas[1])
        {
            habitantes = atof(token);
        }
    }
    flag = addElem(listas[0], barrio, habitantes); // Verifico error de memoria
    return flag; // return addElem(...) no se eligio por claridad del codigo.
}

int storageArboles(const int * columnas, char * linea, listADT * listas)
{
    int i, flag;
    char * token, barrio[MAX_NAME], nombre[MAX_NAME];
    double diametro;
    for (token = strtok(linea, DELIM), i = 1; i <= columnas[2]; i++, token = strtok(NULL, DELIM))
    {
        if (i == columnas[0])
        {
            strcpy(barrio, token);
        }
        else if (i == columnas[1])
        {
            strcpy(nombre, token);
        }
        else if (i == columnas[2])
        {
            diametro = atof(token);
        }
    }
    addCount(listas[0],barrio);
    flag = addAll(listas[1], nombre, diametro); // Verifico errores de memoria
    return flag;   
}

int writeFile(queryList lista, const char * name, const char * encabezado, const char * formato)
{
    FILE * archivo = fopen(name,"w");
    if (archivo == NULL)
    {
        fprintf(stderr,"Error: Can't open file");
        return 1;
    }
    fprintf(archivo,"%s\n",encabezado);
    queryList aux = lista;
    while (aux != NULL)
    {    
        fprintf(archivo, formato, aux->name, aux->elem);
        aux = aux->tail;
    }
    fclose(archivo);
    return 0;
}