#include <iostream>
#include "0.SeclectionSort.cpp"
#define len 5
using namespace std;

template <typename T>
class BinarySort
{
private:
	T *list;
	T target;

public:
	BinarySort(T list[])
	{
		cout << "输入你要查找的元素:";
		cin >> target;
		this->list = list;
		selectionSearch(this->list, len);
		show();
		binarySort();
	}
	int binarySort()
	{
		int left = 0;//首元素位置
		int right = len - 1;//尾元素位置
		while (left <= right)
		{
			int middle = left + ((right - left) >> 1); //右移相当于除以2
			if (list[middle] > target)
			{
				right = middle - 1;
			}
			else if (list[middle] < target)
			{
				left = middle + 1;
			}
			else
			{
				cout << "position is:" << middle << endl;
				return 0;
			}
		}
		cout << "没找到!" << endl;
		return -1;
	}
	void show()
	{
		for (int i = 0; i < len; i++)
		{
			cout << i << ":" << list[i] << endl;
		}
	}
};
int main()
{
	int list[10];
	for (int i = 0; i < 10; ++i)
	{
		list[i] = 11 - i;
	}
	BinarySort<int> b(list);
	return 0;
}