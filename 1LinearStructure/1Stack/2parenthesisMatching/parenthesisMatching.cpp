#include <stack>
#include <iostream>
//¿®∫≈∆•≈‰À„∑®
using namespace std;
bool parenthesisMatching()
{
    char left[] = {'{', '(', '['};
    char right[] = {'}', ')', ']'};
    stack<int> op;
    string statement = "[(3+5))";
    auto iter = statement.cbegin();
    while (iter != statement.cend())
    {
        for (int i=0 ;i<3;i++)
        {
            if (left[i] == *iter)
            {
                op.push(i);
                break;
            }
        }
        for (int i=0;i<3 ;i++)
        {
            if (right[i] == *iter)
            {
                if (op.empty())
                {
                    cout << "”“¿®∫≈∂‡”Î◊Û¿®∫≈" << endl;
                    return false;
                }
                int c = op.top();
                op.pop();
                if (c != i)
                {
                    cout << "¿®∫≈Ωª≤Ê" << endl;
                    return false;
                }
                break;
            }
        }
        iter++;
    }
    if (op.empty())
    {
        return true;
    }
    cout << "◊Û¿®∫≈∂‡”⁄”“¿®∫≈" << endl;
    return false;
}
int main()
{
    if (parenthesisMatching())
    {
        cout << "∆•≈‰" << endl;
    }
    return 0;
}
