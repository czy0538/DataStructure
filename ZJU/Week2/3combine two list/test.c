#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int i;
    //float j;
};
int* fun()
{
    int *p=(int*)malloc(10*sizeof(int));
    int *t=p;
    int i=0;
    for(;i<10;i++)
    {
        *p=i;
        ++p;
    }
    return t;
}

int main()
{
    // int *p=fun();
    // for(int i=0;i<10;++i)
    // {
    //     printf("%d", *p);
    //     p++;
    // }
    // free(p-10);
    printf("%d",sizeof(struct Node));
    return 0;
}
