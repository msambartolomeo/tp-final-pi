#include "read_file.h"
#include "libraryADT.h"

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
    char columnasBarrio[2] = {BARRIO, HABITANTES};
    char columnasArboles[3] = {BARRIO_ARBOLES, NOMBRE, DIAMETRO};
    listADT barrios = newList();
    listADT arboles = newList();
    listADT listas[2] = {barrios, arboles};
    readFile(argv[1], columnasBarrio, storageBarrio, listas);
    readFile(argv[2], columnasArboles, storageArboles, listas);
    return 0;
}
