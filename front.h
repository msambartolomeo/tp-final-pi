#ifndef FRONT_H
#define FRONT_H

#include "libraryADT.h"
#include "query.h"

// Recibe el path a un archivo .csv, las columnas que son importantes en dicho archivo,
// y una funcion encargada de almacenar los valores de las columnas elegidas. Devuelve 1 si hubo errores, 0 sino.
int readFile(const char * path, const int * columnas, int (*storage) (const int * columnas, char * linea, listADT * listas), listADT * listas);

// Recibe las columnas pertinentes de un archivo tipo barrio y una linea de ese archivo,
// y extrae la informacion de estas columnas para guardarla donde corresponda. Devuelve 1 si hubo errores, 0 sino.
int storageBarrio(const int * columnas, char * linea, listADT * listas);

// Recibe las columnas pertinentes de un archivo tipo arboles y una linea de ese archivo,
// y extrae la informacion de estas columnas para guardarla donde corresponda. Devuelve 1 si hubo errores, 0 sino.
int storageArboles(const int * columnas, char * linea, listADT * listas);

// Recibe una lista, el nombre del archivo a crear, el encabezado, y el formato a imprimir,
// e imprime en dicho archivo los datos de la lista luego del encabezado. Devuelve 1 si hubo errores, 0 sino.
int writeFile(queryList lista, const char * name, const char * encabezado, const char * formato);

#endif