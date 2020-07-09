#include"libraryADT.h"

typedef struct node
{
    char name[MAX_NAME]; 
    unsigned int count; //Utilizado para cantidad de habitantes de cada barrio o cantidad de árboles de cada especie
    double elem; //Contador utilizado para cantidad de árboles por barrio, cociente árboles/habitantes, y promedio de diámetros por especie
    struct node * tail;
} tNode;

typedef struct listCDT
{
    tNode * first;
    tNode * current; //Iterador para recorrer la lista e imprimirla
} listCDT;

listADT newList()
{
    listADT new = calloc(1, sizeof(listCDT));
    if (new == NULL) ;
        //Código de error, insuficiente memoria. IF CON ;
    return new;   
}

static void freeRec (tNode * first)
{
    if (first == NULL)
        return;
    freeRec(first->tail);
    free(first);
}

void freeList(listADT list)
{
    freeRec(list->first);
    free(list);
    //No es necesario liberar current ya que apuntará a alguno de los nodos y será liberado automáticamente
}

static tNode * addRec(tNode * first, char * name, double elem, unsigned int count, int flag, int * error)
{
    
}

int add1(listADT list, char * name, double elem)
{
    int error = 0;
    list->first = addRec(list->first, name, elem, 0, 1, &error);
    return error;
}

int add2(listADT list, char * name, unsigned int count)
{
    int error = 0;
    list->first = addRec(list->first, name, 0, count, 0, &error);
    return error;
}

int add3(listADT list, char * name, double elem, unsigned int count)
{
    int error = 0;
    list->first = addRec(list->first, name, elem, count, 1, &error);
    return error;
}