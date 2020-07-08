#ifndef READ_FILE__H
#define READ_FILE__H

// Recibe el path a un archivo .csv, las columnas que son importantes en dicho archivo,
// y una funcion encargada de almacenar los valores de las columnas elegidas.
int readFile(const char * path, const char * columnas, void (*storage) (const char * columnas, char * linea));

// Recibe las columnas pertinentes de un archivo tipo barrio y una linea de ese archivo 
// y extrae la informacion de estas columnas para guardarla donde corresponda
void storageBarrio(const char * columnas, char * linea);

// Recibe las columnas pertinentes de un archivo tipo arboles y una linea de ese archivo 
// y extrae la informacion de estas columnas para guardarla donde corresponda
void storageArboles(const char * columnas, char * linea);

#endif