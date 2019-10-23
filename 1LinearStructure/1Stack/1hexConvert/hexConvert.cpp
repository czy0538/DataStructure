//10进制转换成n进制
#include <iostream>
#include <stack>
using namespace std;

void hexConvert(int num)
{

    cout << "请输入你要转换成的进制:";
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
    cout << "对应的" << n << "进制数为：";
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