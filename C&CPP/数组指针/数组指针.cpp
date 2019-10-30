#include<iostream>
using namespace std;
int main()
{
	int a[3][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = i * 10 + j;
		}
	}
	cout <<*a << endl;
	cout << **a << endl;
	cout << *(a + 1) << endl;
	int* p0 = a[0];
	int* p1 = a[1];
	cout << p0 << endl;
	cout << p1 << endl;
	cout << a[1] << endl;
	cout << endl;
	cout << &a[1][1] << endl;
	cout << (++p1) << endl;
	cout << a[2] << endl;
	cout << *p0 << endl;
	cout << *p1 << endl;
	cout << *(++p1) << endl;
	return 0;
}