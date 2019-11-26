#include <stack>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct fuck
{
    int i;
} * hehe;
int main()
{
    hehe a = new fuck;
    a->i = 0;
    cout << a->i;
    return 0;
}