#include<stack>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    stack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    cout<<test.size()<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<test.top()<<endl;
        test.pop();
    }
    return 0;
}