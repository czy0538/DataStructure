#include <stdio.h>
#include <stdlib.h>
typedef int elementType;
typedef struct node *ptrToNode;
struct node
{
    elementType data;
    ptrToNode next;
    ptrToNode previous;
};
typedef ptrToNode list;