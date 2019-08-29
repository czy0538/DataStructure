//为有头结点的链表
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ERROR -1
typedef struct node *ptrToNode;
typedef int elementType;
struct node
{
    elementType data;
    ptrToNode next;
};
typedef ptrToNode position; //代表节点的地址
typedef ptrToNode list;

int length(list l)
{
    position p;
    int cnt = 0;
    p = l->next;
    while (p)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

elementType findKth(list l, int k) //下标（伪）查找
{
    position p;
    int cnt = 0;
    p = l->next;
    while (p && cnt < k)
    {
        p = p->next;
        cnt++;
    }
    if (cnt == k && p)
    {
        return p->data;
    }
    else
        return ERROR;
}

position find(list l, elementType x)
{
    position p = l->next;
    while (p && p->data != x)
    {
        p = p->next;
    }
    return p;
}

bool insert(list l, elementType x, int i)
{
    position temp, pre;
    temp = (position)calloc(1, sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    int cnt = 0;
    pre = l->next;
    while (pre && cnt < i)
    {
        pre = pre->next;
        cnt++;
    }
    if (pre == NULL || cnt != i)
    {
        printf("这里不能插\n");
        free(temp);
        return false;
    }
    else
    {
        {
            temp->next = pre->next;
            pre->next = temp;
            return true;
        }
    }
}

bool delete (list l, int i)
{
    position temp, pre;
    int cnt = 0;
    pre = l->next;
    while (pre && cnt < i)
    {
        pre = pre->next;
        cnt++;
    }
    if (pre == NULL || cnt != i || pre->next == NULL)
    {
        printf("删除位置参数错误\n");
        return false;
    }
    else
    {
        temp = pre->next;
        pre->next = temp->next;
        free(temp);
        return true;
    }
}