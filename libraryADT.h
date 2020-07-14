#ifndef libraryADT_h
#define libraryADT_h

#define MAX_NAME 50

typedef struct listCDT * listADT;

// Crea una listADT nueva.
listADT newList();

// Libera todos los recursos usados en el TAD.
void freeList(listADT list);

// Recibe una listADT, un string y un parametro del tipo double positivo para agregarlos a la estructura,
// y setea el contador en 0. Devuelve 1 si hubo errores de memoria, 0 sino.
int addElem(listADT list, const char * name, double elem);

// Recibe una listADT y un string para compararlo con aquellos presentes en la estructura,
// y setea el contador en 1 para incrementar. Devuelve 1 si hubo errores, 0 sino.
int addCount(listADT list, const char * name);

// Recibe una listADT, un string y un parametro del tipo double positivo para agregarlos a estructura,
// y setea el contador en 1. Devuelve 1 encuentra un string nuevo, 0 sino.
int addAll(listADT list, const char * name, double elem);

// Devuelve un 1 si el current node es distinto de NULL, 0 sino.
int hasNext(const listADT list);

// Redirecciona el puntero current a la direccion de memoria donde apunta el first.
void toBegin(listADT list);

// Devuelve en su nombre el campo count del current node existente,
// o devuelve -1 si no hay current node.
int getCOUNT(const listADT list);

// Devuelve en su nombre el campo elem del current node existente,
// o devuelve -1 si no hay current node.
double getELEM(const listADT list);

// Devuelve en su nombre el campo name del current node existente,
// o devuelve NULL si no hay current node.
char * getNAME(const listADT list);

// Redirecciona el puntero current a la direccion de memoria del siguiente nodo.
// Devuelve un 1 si no puede pasar al siguiente nodo, 0 sino.
int next(listADT list);

#endif