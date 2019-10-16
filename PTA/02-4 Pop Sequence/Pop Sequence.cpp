#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int maxStack, n, num;
    cin >> maxStack >> n >> num;

    for (int i = 0; i < num; i++)
    {
        vector<int> data;
        cout << i <<"hehe"<< endl;
        for (int j = 0; j < n; ++j)
        {
            int temp;
            cin >> temp;
            data.push_back(temp);
        }
        if (data.size() > 2)
        {

            int last = *(data.end() - 1);
            int last_2 = *(data.end() - 2);
            if (abs(data[0] - data[1]) != 1 || abs(last - last_2 != 1))
            {
                cout << "NO" << endl;
                continue;
            }
            else
            for(int i=1;i<data.size()-1;i++)
            {
                if (abs(data[i - 1] - data[i]) != 1 && abs(data[i + 1] - data[i]) != 1)
                {
                    cout << "NO" << endl;
                    continue;
                }
            }

        }

    }
    system("pause");
    return 0;
}