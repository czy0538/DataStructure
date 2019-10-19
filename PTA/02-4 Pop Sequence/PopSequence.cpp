#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        vector<int> num;
        //读入判断序列

        for (int j = 1; j <= N; ++j)
        {
            int temp;
            cin >> temp;
            num.push_back(temp);
        }
        stack<int> s;
        int t = 1;
        int j = 0;
        bool flag = true;
        while (j < N && t <= M)
        {
            if (t == num[j])
            {
                t++;
                j++;
                continue;
            }
            else
            {
                if (!s.empty())
                {
                    if (s.top() == num[j])
                    {
                        j++;
                        s.pop();
                        continue;
                    }
                    else
                    {
                        while (t != num[j])
                        {
                            ++t;
                            s.push(t);
                            if (s.size() > M || t > N)
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    while (t != num[j])
                    {
                        ++t;
                        s.push(t);
                        if (s.size() > M || t > N)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if (flag == false)
            {
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