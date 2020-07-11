#ifndef READ_FILE__H
#define READ_FILE__H

#include "libraryADT.h"
#include "query.h"
// Recibe el path a un archivo .csv, las columnas que son importantes en dicho archivo,
// y una funcion encargada de almacenar los valores de las columnas elegidas.
int readFile(const char * path, const int * columnas, void (*storage) (const int * columnas, char * linea, listADT * listas), listADT * listas);

// Recibe las columnas pertinentes de un archivo tipo barrio y una linea de ese archivo 
// y extrae la informacion de estas columnas para guardarla donde corresponda
void storageBarrio(const int * columnas, char * linea, listADT * listas);

// Recibe las columnas pertinentes de un archivo tipo arboles y una linea de ese archivo 
// y extrae la informacion de estas columnas para guardarla donde corresponda
void storageArboles(const int * columnas, char * linea, listADT * listas);

// Recibe una lista, el nombre del archivo a crear, el encabezado, y el formato a imprimir 
// y imprime en dicho archivo los datos de la lista luego del encabezado
int writeFile(queryList lista, const char * name, const char * encabezado, const char * formato);

#endif