#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define elementType int
#define MAXSIZE 5
#define ERROR -1
typedef int position;
typedef struct node *ptrToNode;
typedef ptrToNode list;
struct node
{
    elementType data[MAXSIZE];
    position last;
};
list makeEmpty()
{
    list l;
    l = (list)malloc(sizeof(struct node));
    l->last = -1;
    return l;
}
position find(list l, elementType x)
{
    position i = 0;
    for (; i <= l->last; i++)
    {
        if (l->data[i] == x)
            return i;
    }
    return ERROR;
}
//在i插入一个元素
bool insert(list l, elementType x, int i) //i为数组下标
{
    position j;
    if (l->last == MAXSIZE - 1)
    {
        printf("啊，我满了，插不进来了\n");
        return false;
    }

    if (i < 0 || i > l->last + 1)
    {
        printf("这里不能插啊啊啊\n");
        return false;
    }
    for (j = l->last; j >= i; j--)
    {
        l->data[j + 1] = l->data[j];
    }
    l->data[i] = x;
    l->last++;
    return true;
}

bool delete (list l, position i)
{
    position j;
    if (i < 0 || i > l->last)
    {
        printf("人家不在这啊\n");
        return false;
    }
    for (j = i; j < l->last; j++)
    {
        l->data[j] = l->data[j + 1];
    }
    l->last--;
    return true;
}

int view(list l)
{
    int i;
    int size = 0;
    for (i = 0; i < l->last + 1; i++)
    {
        printf("%d\n", l->data[i]);
        size++;
    }
    return size;
}

int main()
{
    list l = makeEmpty();
    int i;
    for (i = 0; i < 4; i++)
    {
        insert(l, i, i);
    }
    view(l);
    insert(l, 233, 2);
    view(l);
    printf("%d\n", find(l, 233));
    printf("%d\n", find(l, 23));
    delete (l, 2);
    view(l);
    getchar();
    return 0;
}