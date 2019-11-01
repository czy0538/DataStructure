#include<iostream>
using namespace std;
typedef int atomType;
typedef enum
{
	ATOM,LIST
}elemTag;

typedef struct glNode
{
	elemTag tag;
	typedef union MyUnion
	{
		atomType atom;
		struct glNode* hp;
	}data;
	struct glNode* tp=nullptr;
};
int main()
{
	cout << ATOM;
	cout << LIST;
	elemTag tag;
	cout << tag;

}