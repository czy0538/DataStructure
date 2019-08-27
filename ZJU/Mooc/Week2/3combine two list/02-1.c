#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    List L3; //得返回这个啊，怎么能忘记  //要初始化么？
    //(假象空间，实际利用L1，L2空间）
    L3 = (List)malloc(sizeof(struct Node)); //必须申请一个新头节点（L1，L2清空）
    List p1, p2, p3;
    p3 = L3;
    p1 = L1->Next;
    p2 = L2->Next;
    while (p1 && p2)
    { //No p1&&p2!=0
        if (p1->Data < p2->Data)
        { //谁小就连在L3后面
            p3->Next = p1;
            p3 = p1;
            p1 = p1->Next;
        }
        else
        {

            p3->Next = p2;
            p3 = p2;
            p2 = p2->Next;
        }
    }
    for (; p1 != NULL; p1 = p1->Next)
    {
        p3->Next = p1;
        p3 = p1;
    }
    for (; p2 != NULL; p2 = p2->Next)
    {
        p3->Next = p2;
        p3 = p2;
    }

    p3->Next = NULL;
    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
}