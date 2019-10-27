#include <iostream>
#include <string>
#include <stack>
using namespace std;
void lineEdit()
{
    string statement = {"whli##ilr#e(s#*s)\noutcha@putchar(*s=#++);\n"};
    stack<char> c;
    stack<char> temp;
    auto itr = statement.cbegin();
    while (itr != statement.end())
    {
        char ch = *itr;

        if (ch == '\n')
        {
            while (!c.empty())
            {
                temp.push(c.top());
                c.pop();
            }
            while (!temp.empty())
            {
                cout << temp.top();
                temp.pop();
            }
            cout << endl;

            // continue;
        }
        else
        {
            switch (ch)
            {
            case '#':
                c.pop();
                break;
            case '@':
                while (!c.empty())
                {
                    c.pop();
                }
                break;
            default:
                c.push(ch);
                break;
            }
        }
        itr++;
    }
}
int main()
{
    lineEdit();
    return 0;
}