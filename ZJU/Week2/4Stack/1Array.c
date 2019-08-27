#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define elementType int
#define ERROR -233
typedef int position;
typedef struct SNode *ptrToSNode;
struct SNode
{
    elementType *data;
    position top;
    int maxSize;
};
typedef ptrToSNode Stack;

Stack createStack(int maxSize);
bool isFull(Stack s);
bool push(Stack s, elementType x);
bool isEmpty(Stack s);
elementType pop(Stack s);

Stack createStack(int maxSize)
{
    Stack s = (Stack)calloc(1, sizeof(struct SNode));
    s->data = (elementType *)calloc(maxSize, sizeof(elementType));
    s->top = -1;
    s->maxSize = maxSize;
    return s;
}

bool isFull(Stack s)
{
    return (s->top == s->maxSize - 1);
}

bool push(Stack s, elementType x)
{
    if (isFull(s))
    {
        printf("¶ÑÕ»Âú\n");
        return false;
    }
    else
    {
        s->data[++(s->top)] = x;
        return true;
    }
}

bool isEmpty(Stack s)
{
    return (s->top == -1);
}

elementType pop(Stack s)
{
    if (isEmpty(s))
    {
        printf("¶ÑÕ»¿Õ\n");
        return ERROR;
    }
    else
    {
        return (s->data[(s->top)--]);
    }
}