#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define elementType int
#define ERROR -1
typedef int position;
typedef struct node *ptrToNode;
struct node
{
    elementType *data;
    position top;
    int maxSize;
};
typedef ptrToNode stack;
stack creatStack(int maxSize)
{
    stack s = (stack)calloc(maxSize, sizeof(struct node));
    s->data = (elementType *)calloc(maxSize, sizeof(elementType));
    s->top = -1;
    s->maxSize = maxSize;
    return s;
}
bool isFull(stack s)
{
    return s->top == s->maxSize - 1;
}

bool push(stack s, elementType x)
{
    if (isFull(s))
    {
        printf("stack has fulled!\n");
        return false;
    }
    else
    {
        s->data[++(s->top)] = x;
        return true;
    }
}

bool isEmpty(stack s)
{
    return s->top==-1;
}

elementType pop(stack s)
{
    if(isEmpty(s))
    {
        printf("堆栈空，无法删除\n");
        return ERROR;
    }
    else
    {
        return (s->data[(s->top)--]);
    }

}