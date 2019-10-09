#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
#include <queue>
using namespace std;

template <typename T>
class prefixExpection
{
private:
    stack<string> element;
    T ans = 0;

public:
    T stringToT(const string &s)
    {
        stringstream ss;
        T temp;
        ss << s;
        ss >> temp;
        return temp;
    }
    string TtoString(const T &t)
    {
        stringstream ss;
        string temp;
        ss << t;
        ss >> temp;
        return temp;
    }
    bool isSign(const string &s)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        else
            return false;
    }
    void calcualte()
    {
        while (true)
        {
            string temp;
            cin >> temp;
            if (temp == "quit")
            {
                cout << element.top() << endl;
                cout << " bye" << endl;
                cin.get();
                return;
            }

            else if (!isSign(temp))
            {
                element.push(temp);
            }
            else
            {
                T t1, t2, t;
                t1 = stringToT(element.top());
                element.pop();
                t2 = stringToT(element.top());
                element.pop();
                if (temp == "+")
                {
                    t = t1 + t2;
                }
                else if (temp == "-")
                {
                    t = t1 - t2;
                }
                else if (temp == "*")
                {
                    t = t1 * t2;
                }
                else if (temp == "/")
                {
                    t = t1 / t2;
                }
                else
                {
                    cout << "error" << endl;
                    exit(1);
                }

                element.push(TtoString(t));
            }
        }
    }
    //层序遍历
    void levelOrderTraversal()
    {
        queue<T> q;
        position t=root;
        if(!t)
        {
            return ;
        }
        q.push(t);
        while(!q.empty())
        {
            t=q.front();
            q.pop();
            cout<<t->data<<endl;
            if(t->left)
            {
                q.push(t->left);
            }
            if(t->right)
            {
                q.push(t->right);
            }
        }

    }
};

int main()
{
    prefixExpection<double> p;
    p.calcualte();
    cin.get();
    return 0;
}