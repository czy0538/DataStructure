#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10
#define ElementType int
typedef struct SNode *Statck;
struct SNode
{
    ElementType Data[MaxSize];
    int top;
};

Statck creataStack()
{
    return (Statck)calloc(1, sizeof(struct SNode));
}
void push(Statck p, ElementType item)
{
    if (p->top == MaxSize - 1)
    {
        printf("堆栈满！\n");
        return;
    }
    else
    {
        p->Data[++(p->top)] = item;
        return;
    }
}

ElementType pop(Statck p)
{
    if(p->top==-1)
    {
        printf("空堆栈");
        return NULL;
    }
    else
    {
        return(p->Data[(p->top)--]);
    }

}

int main()
{
    Statck p=creataStack();
    push(p,233);
    printf("%d",p->Data[1]);
    getchar();
    return 0;
}
