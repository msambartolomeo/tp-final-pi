#include "front.h"
#include "libraryADT.h"
#include "query.h"
#include <stdio.h>

#define BARRIO_ARBOLES 3
#define NOMBRE 8
#define DIAMETRO 12
#define BARRIO 1
#define HABITANTES 2

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Wrong argument quantity");
        return 1;
    }
    int columnasBarrio[2] = {BARRIO, HABITANTES};
    int columnasArboles[3] = {BARRIO_ARBOLES, NOMBRE, DIAMETRO};
    
    listADT listas[2];
    listas[0] = newList(); //Lista de barrios, con cantidad de habitantes y arboles.
    listas[1] = newList(); //Lista de especies, con sumatoria de diametros y cantidad de arboles.

    int error;
    error = readFile(argv[1], columnasBarrio, storageBarrio, listas);
    if (error == 2) //Correspondiente a no poder abrir el archivo.
        return 1;
    if (error == 1) //Correspondiente a error de malloc o calloc
    {
        freeList(listas[0]);
        return 1;
    }

    error = readFile(argv[2], columnasArboles, storageArboles, listas);
    if (error == 2) //Correspondiente a no poder abrir el archivo.
        return 1;
    if (error == 1) //Correspondiente a error de malloc o calloc
    {
        freeList(listas[0]);
        freeList(listas[1]);
        return 1;
    }
    
    // make query 12
    // make query 3

    
    freeList(listas[0]);
    freeList(listas[1]);

    writeFile(query1, "query1.csv", "BARRIO;ARBOLES", "%s;%.0f\n");
    writeFile(query2, "query2.csv", "BARRIO;ARBOLES_POR_HABITANTE", "%s;%.2f\n");
    writeFile(query3, "query3.csv", "NOMBRE_CIENTIFICO;PROMEDIO_DIAMETRO", "%s;%.2f\n");
    // free queries
    return 0;
}
