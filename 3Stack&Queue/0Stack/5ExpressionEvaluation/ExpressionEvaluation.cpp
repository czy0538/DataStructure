#include<iostream>
#include<string>
#include<stack>
#include<iterator>
using namespace std;
static char ops[][2]={'*','/','+','-'};
void expressionEvaluation()
{
    string expression;
    cin>>expression;
    stack<double> optr;
    optr.push('#');
    stack<char>opnd;
    auto itr=expression.cbegin();
    while(itr!=expression.cend())
    {

    }

}