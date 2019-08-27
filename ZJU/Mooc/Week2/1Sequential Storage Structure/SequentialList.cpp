#include <iostream>
#include"SequentialList.h"
using namespace std;
int main()
{
    int l[5] = {1, 2, 3, 4, 5};
    SequentialList<int> list(10, l, 5);
    list.show();

    return 0;
}

template <typename T>
SequentialList<T>::~SequentialList()
{
    delete[] data;
}
template <typename T>
SequentialList<T>::SequentialList(int len, T l[], int lenL) : size(len)
{
    data = new T[len];
    for (int i = 0; i < lenL; i++)
    {
        data[i] = l[i];
    }
    last = lenL - 1;
}

template <typename T>
SequentialList<T>::SequentialList(int len) : size(len)
{
    data = new T[len];
}
template <typename T>
SequentialList<T>::SequentialList()
{
    data = new T[defaultSize];
}

template <typename T>
void SequentialList<T>::show()
{
    for (int i = 0; i <= last; ++i)
    {
        cout << i << ":" << data[i] << endl;
    }
}
template <typename T>
int SequentialList<T>::find(T x)
{
    for (int i = 0; i <= last; ++i)
    {
        if (x == data[i])
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
T SequentialList<T>:: get(int pos)
{
    if(pos<=last)
    {
        return data[pos];
    }
    else
    {
        cout<<"输入错误！"<<endl;
        return -1;
    }
}

template <typename T>
bool SequentialList<T>::insert(T x,int pos)
{
    if(pos>=size||last==size=1||pos<0)
    {
        return false;
    }
    for(int i=last;j>pos-1;--j)
    {
        
    }
}