#include "read_file.h"

#define BARRIO_ARBOLES 3
#define NOMBRE 8
#define DIAMETRO 12
#define BARRIO 1
#define HABITANTES 2

int main(int argc, char const *argv[])
{
    char columnasBarrio[2] = {BARRIO, HABITANTES};
    char columnasArboles[3] = {BARRIO_ARBOLES, NOMBRE, DIAMETRO};
    readFile(argv[1], columnasBarrio, storageBarrio);
    readFile(argv[2], columnasArboles, storageArboles);
    return 0;
}
