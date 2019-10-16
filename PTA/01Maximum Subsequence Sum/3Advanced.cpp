#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k = 0;
    int thisSum = 0;
    int maxSum = 0;
    cin >> k;
    vector<int> now;
    vector<int> min;
    int beg=0;
    int end=0;
    bool flag = false;
    for (int i = 0; i < k; ++i)
    {


        int temp = 0;
        cin >> temp;
        if (i == 0)
        {
            beg=temp;
        }
        if(i==k-1)
        {
            end=temp;
        }
        if(temp>=0)
        {
            flag=true;
        }

        thisSum += temp;
        now.push_back(temp);
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            min=now;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
            now.clear();
        }
    }

    if(maxSum==0)
    {
        if(flag)

{
    cout << 0 << " " << 0 << " " << 0;
}
else
{
    {
        cout << 0 << " " << beg << " " << end;
    }
}
    }
    else
    {
        cout << maxSum<<" "<<*(min.begin())<<" "<<*(min.end()-1);
    }
    system("pause");

    return 0;
}