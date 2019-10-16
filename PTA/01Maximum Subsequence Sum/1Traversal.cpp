//枚举法改进版
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int k=0;
    int max=0;
    cin>>k;
    vector<int> num;
    for(int i=0;i<k;++i)
    {
        int temp=0;
        cin>>temp;
        num.push_back(temp);
    }
   // cout<<num.size()<<endl;
    for(int i=0;i<k;++i)
    {
        int temp=0;
        for(int j=i;j<k;++j)
        {
            temp+=num[j];
            if(temp>max)
            {
                max=temp;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}