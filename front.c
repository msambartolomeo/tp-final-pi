#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryADT.h"
#include "query.h"

#define MAX_LINE_LENGTH 300
#define DELIM ";"

int readFile(const char * path, const int * columnas, int (*storage) (const int * columnas, char * linea, listADT * listas), listADT * listas)
{
    FILE * archivo = fopen(path, "r");
    if (archivo == NULL)
    {
        fprintf(stderr,"Error: Can't read file\n");
        return 1;
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
        fprintf(stderr, "Error: Memory allocation failure\n");
        return 1;
    }
    return 0;
}

int storageBarrio(const int * columnas, char * linea, listADT * listas)
{
    int i, error;
    char * token, * barrio;
    double habitantes;
    for (token = strtok(linea, DELIM), i = 1; i <= columnas[1]; i++, token = strtok(NULL, DELIM))
    {
        if (i == columnas[0])
        {
            barrio = token;
        }
        else if (i == columnas[1])
        {
            habitantes = atof(token);
        }
    }
    error = addElem(listas[0], barrio, habitantes); // Verifico error de memoria.
    return error; // return addElem(...) no se eligio por claridad del codigo.
}

int storageArboles(const int * columnas, char * linea, listADT * listas)
{
    int i, error;
    char * token, * barrio, * nombre;
    double diametro;
    for (token = strtok(linea, DELIM), i = 1; i <= columnas[2]; i++, token = strtok(NULL, DELIM))
    {
        if (i == columnas[0])
        {
            barrio = token;
        }
        else if (i == columnas[1])
        {
            nombre = token;
        }
        else if (i == columnas[2])
        {
            diametro = atof(token);
        }
    }
    error = addCount(listas[0],barrio);
    if (error)
    {
        printf("Barrio en archivo arboles no perteneciente al archivo barrios");
    }
    error = addAll(listas[1], nombre, diametro); // Verifico errores de memoria.
    return error;   
}

int writeFile(queryList lista, const char * name, const char * encabezado, const char * formato)
{
    FILE * archivo = fopen(name,"w");
    if (archivo == NULL)
    {
        fprintf(stderr,"Error: Can't write on file");
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