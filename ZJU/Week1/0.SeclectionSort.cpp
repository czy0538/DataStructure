#include <iostream>
using namespace std;
template <typename T>
void swap(int pos1, int pos2, T list[])
{
    T t = list[pos1];
    list[pos1] = list[pos2];
    list[pos2] = t;
}
template <typename T>
void selectionSearch(T list[], int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (list[min] > list[j])
                min = j;
        }
        swap<T>(i, min, list);
    }
}

// int main()
// {
//     int list[10];
//     for (int i = 0; i < 10; ++i)
//     {
//         list[i] = i;
//     }
//     selectionSearch<int>(list, 10);
//     for (const auto &i : list)
//     {
//         cout << i << endl;
//     }
// }