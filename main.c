#include "front.h"
#include "libraryADT.h"
#include "query.h"
#include <stdio.h>

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
    listas[0] = newList(); // Lista de barrios, con cantidad de habitantes y arboles.
    listas[1] = newList(); // Lista de especies, con sumatoria de diametros y cantidad de arboles.

    int error;
    error = readFile(argv[1], columnasBarrio, storageBarrio, listas);
    if (error)
    {    
        freeList(listas[0]);
        freeList(listas[1]);
        return 1;
    }    

    error = readFile(argv[2], columnasArboles, storageArboles, listas);
    if (error)
    {
        freeList(listas[0]);
        freeList(listas[1]);
        return 1;
    }

    queryList query1 = NULL, query2 = NULL, query3 = NULL;
    
    error = makeQueries12(listas[0], &query1, &query2);
    freeList(listas[0]);
    if (error)
    {
        freeList(listas[1]);
        freeQuery(query1);
        freeQuery(query2);
        fprintf(stderr, "Error: Cannot allocate memory");
        return 1;
    }

    error = makeQuery3(listas[1], &query3);
    freeList(listas[1]);
    if (error)
    {
        freeQuery(query1);
        freeQuery(query2);
        freeQuery(query3);
        fprintf(stderr, "Error: Cannot allocate memory");
        return 1;
    }
    

    error = writeFile(query1, "query1.csv", "BARRIO;ARBOLES", "%s;%.0f\n");
    freeQuery(query1);
    if (error)
    {
        freeQuery(query2);
        freeQuery(query3);
        return 1;
    }
    
    error = writeFile(query2, "query2.csv", "BARRIO;ARBOLES_POR_HABITANTE", "%s;%.2f\n");
    freeQuery(query2);
    if (error)
    {
        freeQuery(query3);
        return 1;
    }

    error = writeFile(query3, "query3.csv", "NOMBRE_CIENTIFICO;PROMEDIO_DIAMETRO", "%s;%.2f\n");
    freeQuery(query3);
    if (error)
    {
        return 1;
    }
    return 0;
}