#ifndef libraryADT_h
#define libraryADT_h

#define MAX_NAME 50

typedef struct listCDT * listADT;

//Funciones
listADT newList();
void freeList(listADT list);
int addElem(listADT list, char * name, double elem);
int addCount(listADT list, char * name);
int addAll(listADT list, char * name, double elem);
int hasNext(const listADT list);
void toBegin(listADT list);
unsigned int getCOUNT(listADT list);
double getELEM(listADT list);
char * getNAME(listADT list);
void next(listADT list);

#endif