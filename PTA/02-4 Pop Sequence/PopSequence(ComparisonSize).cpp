//应用比较大小，但是存在问题
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        vector<int> num ;
        //读入判断序列
        bool flag = true;
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            num.push_back(temp);
        }

        int k = 1;
        stack<int> s;
        for (int j = 0; j <N; j++)
        {
            if (k == num[j])
            {
                k++;
                continue;
            }
            else if (k < num[j])
            {
                while(k<num[j])
                {
                    s.push(k);
                    if (s.size() > M)
                    {
                        flag = false;
                        break;
                    }
                    k++;
                }
                if(k<=N)
                k++;//逻辑问题


            }
            else
            {
                if (s.empty())
                {
                    flag=false;
                    cout << "NO" << endl;
                    break;
                }
                int t = s.top();
                s.pop();
                if (t == num[j])
                {
                    continue;
                }
                else
                {
                    flag = false;
                    cout << "NO" << endl;
                    break;
                }
            }
            if(flag==false)
            {
                cout << "NO" << endl;
                break;
            }
            if(k>N)
            {
                flag = false;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }

    }
    system("pause");
    return 0;
}