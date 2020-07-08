#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 300
#define DELIM ";"

int readFile(const char * path, const char * columnas, void (*storage) (const char * columnas, char * linea))
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
        storage(columnas, linea);
    }
    fclose(archivo);
    return 0;
}

void storageBarrio(const char * columnas, char * linea)
{
    int i;
    char * token;
    for (token = strtok(linea, DELIM), i = 1; i <= linea[1]; i++, token = strtok(NULL, DELIM))
    {
        if (i == linea[0])
        {
            // guardo nombres de los barrios
        }
        else
        {
            // guardo cantidad de habitantes
        }
    }
}

void storageArboles(const char * columnas, char * linea)
{
    int i;
    char * token;
    for (token = strtok(linea, DELIM), i = 1; i <= linea[2]; i++, token = strtok(NULL, DELIM))
    {
        if (i == linea[0])
        {
            // chequeo nombre del barrio
        }
        else if (i == linea [1])
        {
            // chequeo nombre del arbol
        }
        else if (i == linea [2])
        {
            // chequeo diametro de arbol
        }
    }
    // guardo en aux datos obtenidos
}