#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7};
    v1 = v2;
    cout << "v1:" << endl;
    for (auto i : v1)
    {
        cout << i << endl;
    }
    cout << "v2:" << endl;
    for (auto i : v1)
    {
        cout << i << endl;
    }
    v1.push_back(233);
    cout << "v1:" << endl;
    for (auto i : v1)
    {
        cout << i << endl;
    }
    cout << "v2:" << endl;
    for (auto i : v2)
    {
        cout << i << endl;
    }
    cout << endl;
    cout << *(v1.end() - 1) << endl;
    system("pause");
    return 0;
}