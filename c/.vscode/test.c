#include <stdlib.h>
#include <stdio.h>

typedef struct Data
{

    double a;
    double b;
    double c;
    double d;
    double f;
    double g;
    struct Data *next;
} * position;
int main()
{
    position p1 = (position)malloc(8);
    p1->a=1;
    p1->b=2;
    p1->c=3;
    p1->d=4;
    p1->f=5;
    p1->g=6;
    printf("%lf\n", p1->a);
    printf("%lf\n", p1->b);
    printf("%lf\n", p1->c);
    printf("%lf\n", p1->d);
    printf("%lf\n", p1->f);
    printf("%lf\n",p1->g);

    // position p2 = (struct Data *)malloc(sizeof(struct Data));
    // position p3 = (position)malloc(sizeof(struct Data *));
    // void* p4=malloc(sizeof(16));
    // printf("%d\n", sizeof(p4));
    // printf("%d\n", sizeof(*p4));



    // printf("%d\n", sizeof(p1));//8
    // printf("%d\n", sizeof(*p1));//??? 56
    // printf("%d\n", sizeof(p2));//8
    // printf("%d\n", sizeof(*p2));//56
    // printf("%d\n", sizeof(position));//8
    return 0;
}