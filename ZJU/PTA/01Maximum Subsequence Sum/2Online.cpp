//在线处理法，o(n)
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int k = 0;
    int thisSum=0;
    int maxSum=0;
    cin >> k;
    vector<int> num;
    for (int i = 0; i < k; ++i)
    {
        int temp = 0;
        cin >> temp;
        thisSum+=temp;
        if(thisSum>maxSum)
        {
            maxSum=thisSum;
        }
        else if (thisSum<0)
        {
            thisSum=0;
        }

    }
    cout<<maxSum<<endl;
    return 0;
}