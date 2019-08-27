#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

typedef struct Polynomial
{
    int coefficient;
    int index;
    bool operator()(Polynomial a, Polynomial b)
    {
        return a.index > b.index;
    }

} l;

class Deal
{
private:
    vector<l> polynomial1;
    vector<l> polynomial2;
    vector<l> Add;
    vector<l> Multiplie;

    int len1 = 0;
    int len2 = 0;

public:
    Deal()
    {
        input(polynomial1);
        input(polynomial2);
    }
    void input(vector<l> &p)
    {
        int len = 0;
        cin >> len;
        for (int i = 0; i < len; ++i)
        {
            int coefficient;
            int index;
            cin >> coefficient >> index;
            l t{coefficient, index};
            p.push_back(t);
        }
    }
    void display(vector<l> p)
    {
        for (const auto &i : p)
        {
            cout << i.coefficient << ":" << i.index << endl;
        }
    }
    void add(vector<l> p1, vector<l> p2)
    {
        int j = 0;
        int i = 0;
        while (true)
        {

            if (p1[j].index < p2[i].index)
            {
                Add.push_back(p2[i]);
                ++i;
            }
            else if (p1[j].index > p2[i].index)
            {
                Add.push_back(p1[j]);
                ++j;
            }
            else if (p1[j].index == p2[i].index)
            {
                Add.push_back(p1[j]);
                Add.push_back(p2[i]);
                i++;
                j++;
            }
            if (i == p1.size())
            {
                for (; j < p2.size(); ++j)
                {
                    Add.push_back(p2[j]);
                }
            }
            else if (j == p2.size())
            {
                for (; i < p1.size(); ++i)
                {
                    Add.push_back(p1[i]);
                }
            }
            else if (i == p1.size() && j == p2.size())
            {
                break;
            }
        }
    }
    void start()
    {
        display(polynomial1);
        display(polynomial2);

        add(polynomial1,polynomial2);
        display(Add);
    }
};

int main()
{
    Deal d;
    d.start();
    cout << "happy" << endl;

    return 0;
}