//10����ת����n����
#include <iostream>
#include <stack>
using namespace std;

void hexConvert(int num)
{

    cout << "��������Ҫת���ɵĽ���:";
    int n;
    cin >> n;
    if (n <= 0)
    {
        throw "Please input a int num,which below 2";
    }

    stack<int> hex;
    while (num)
    {
        hex.push(num % n);
        num /= n;
    }
    cout << "��Ӧ��" << n << "������Ϊ��";
    while (!hex.empty())
    {
        cout << hex.top();
        hex.pop();
    }
    cout << endl;
}
int main()
{
    try
    {
        hexConvert(1348);
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
        hexConvert(1348);
    }
}