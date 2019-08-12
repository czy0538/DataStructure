#include <stdio.h>
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
Position BinarySearch(List L, ElementType X)
{
    int left = 1;
    int right = L->Last;
    ElementType *list = L->Data;
    while (left <= right)
    {

        int middle = left + ((right - left) >> 1); //右移相当于除以2
        if (list[middle] > X)
        {
            right = middle - 1;
        }
        else if (list[middle] < X)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}