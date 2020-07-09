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

listADT new ()
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

void free (listADT list)
{
    freeRec(list->first);
    free(list);
    //No es necesario liberar current ya que apuntará a alguno de los nodos y será liberado automáticamente
}

tNode * addRec (tNode * first, char * name, int data, char flag)
{
    
}

void add (listADT list, char * name, int data, int (*func) (char a[], char b[]) )
{

}