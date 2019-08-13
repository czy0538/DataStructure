#pragma one
#include <iostream>
using namespace std;
template <typename T>
class SequentialList
{
private:
    int size = 0;
    T *data = nullptr;
    int last = -1;
    int defaultSize = 10;

public:
    SequentialList();
    SequentialList(int len, T l[], int lenL);
    SequentialList(int len);
    ~SequentialList();
    int find(T x);
    void show();
    T get(int pos);
    bool insert(T x, int pos);
};