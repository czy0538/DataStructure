//默认有头结点的单向列表
#include <stdio.h>
#include <stdlib.h>
typedef int elementType;
typedef struct node *ptrToNode;
struct node
{
    elementType data;
    ptrToNode next;
};
typedef ptrToNode list;

list newList(elementType x)
{
    ptrToNode p = (ptrToNode)calloc(1, sizeof(struct node));
    p->data = x;
    p->next = NULL;
    return p;
}

void insertNode(list l, elementType x) //l为要插入节点的前驱节点
{
    list p = newList(x);
    p->next = l->next;
    l->next = p;
}

void deleteNode(list p) //p为要删除节点的前驱节点
{
    list t = p->next;
    p->next = t->next;
    free(t);
}

int ergodicNode(list t)
{
    t=t->next;
    int size = 0;
    while (t->next != NULL)
    {
        //do something
        printf("%d\n",t->data);
        t = t->next;
        size++;
    }
    return size;
}

int main()
{
    list head = newList(0);
    list p = head;
    int i = 0;
    int j = 5;
    //尾插法
    for (; i < 5; i++)
    {
        p->next = newList(j);
        p=p->next;
        j -= 2;
    }
    printf("%d",ergodicNode(head));
    //头插法
    for(i=0;i<5;i++)
    {
        list t=newList(j);
        t->next=head->next;
        head->next=t;
        j+=2;
    }
    printf("%d", ergodicNode(head));
    return 0;


}