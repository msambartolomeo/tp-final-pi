#include "read_file.h"
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
    listADT barrios = newList();
    listADT arboles = newList();
    listADT listas[2] = {barrios, arboles};
    readFile(argv[1], columnasBarrio, storageBarrio, listas);
    readFile(argv[2], columnasArboles, storageArboles, listas);
    // make query 12
    // make query 3
    freeList(barrios);
    freeList(arboles);
    writeFile(query1, "query1.csv", "BARRIO;ARBOLES", "%s;%.0f\n");
    writeFile(query2, "query2.csv", "BARRIO;ARBOLES_POR_HABITANTE", "%s;%.2f\n");
    writeFile(query3, "query3.csv", "NOMBRE_CIENTIFICO;PROMEDIO_DIAMETRO", "%s;%.2f\n");
    // free queries
    return 0;
}
