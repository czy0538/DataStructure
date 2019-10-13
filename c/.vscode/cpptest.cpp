#include<iostream>
#include<stdlib.h>
using namespace std;

//typedef struct Data *position;
struct Data
{
    int fuck;
    Data* next;
};
typedef Data* position;

position fun1()
{
    return new Data;
}

position fun2()
{
    return (position)malloc(sizeof(position));
}

position fun3()
{
    return new struct Data;
}


position fun4()
{
    return  (position) malloc(sizeof(Data));
}

position fun5()
{
    return (position)malloc(sizeof(struct Data));
}

int main()
{
    position pos1=fun5();
    position pos2=fun2();
    pos1->fuck=10;
    cout<<pos1->fuck<<endl;
    delete pos1;
    pos2->fuck=23;
    cout<<(*pos2).fuck<<endl;
    free(pos2);
    return 0;
}