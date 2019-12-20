#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<cctype>
using namespace std;
static constexpr int MAXLENGTH = 10;//字符串最大长度
static constexpr int MAXWORDLENGTH = 10;
typedef char elementType[MAXLENGTH + 1];//存储字符串
using index = int;

class Hash
{
private:
	//单链表定义
	typedef struct LNode
	{
		elementType data;
		int count;
		LNode* next;
	}*List;
	//散列表定义
	typedef struct TblNode
	{
		int TableSize;
		List heads;
	} *HashTable;

	int talbleSize;
public:
	Hash(int length) :talbleSize(length) {}
	Hash()
	{
		talbleSize = 100;
	}
	HashTable h;

	void createTable()
	{
		h = new TblNode;
		talbleSize = nextPrime(talbleSize);

		h->heads = new LNode[talbleSize];
		for (int i = 0; i < talbleSize; i++)
		{
			h->heads[i].data[0] == '\0';
			h->heads[i].next = nullptr;
		}
	}
	//查找函数
	List find(elementType key)
	{
		List p;
		index pos;
		pos = hash(key);
		p = h->heads[pos].next;
		while (p != nullptr && strcmp(key, p->data))
		{
			p = p->next;
		}
		return p;
	}
	void insert(elementType key)
	{
		List p, newcell;
		index pos;
		p = find(key);
		if (p == nullptr)
		{
			newcell = new LNode;
			strcpy(newcell->data, key);
			newcell->count = 1;
			pos = hash(key);
			newcell->next = h->heads[pos].next;
			h->heads[pos].next = newcell;
			h->heads[pos].count++;

		}
		else
		{
			p->count++;
		}
	}
	~Hash()
	{
		delete[] h->heads;
		delete h;
	}
	//位移映射法求散列函数
	int hash(const char* key)
	{
		int h = 0;
		while (*key != '\0')
		{
			h = (h << 5) + *key++;
		}
		return h % talbleSize;
	}
	//返回大于N且不超过MAXLENGTH的素数
	int nextPrime(int N)
	{
		int p = (N % 2);
		if (p == 0)//从n的下一个奇数开始
		{
			p = N + 1;
		}
		else
		{
			p = N + 2;
		}
		int i;
		while (p <= talbleSize)
		{
			for (i = (int)sqrt(p); i > 2; i--)
			{
				if (!(p % i))
					break;
			}
			if (i == 2)//说明p是素数
				break;
			else
			{
				p += 2;
			}
		}
		return p;
	}
};



class Ex4Search
{
private:
	Hash H;


public:
	Ex4Search()
	{
		H = Hash(100);
	}
	void countWords()
	{
		//有点问题这地方
		int N;
		cin >> N;
		vector<vector<string>> data;
		for (int i = 0; i < N; i++)
		{
			string temp;
			getline(cin, temp);
			stringstream ss;
			ss << temp;
			if (temp == "#")
			{
				continue;
			}
			else
			{
				while (!ss.eof())
				{
					ss >> temp;
					string t;
					int i;
					for (i = 0; i < temp.size(); ++i)
					{
						if (isalpha(temp[i]))
						{
							temp[i] == tolower(temp[i]);
						}
						else
						{
							++i;
							t = temp.substr(i, temp.size() - i);
							temp = temp.substr(0, i - 1);
							break;
						}
					}
					data[i].push_back(temp);
					for (int j = 0; j < t.size(); j++)
					{
						if (isalpha(temp[i]))
						{
							temp[i] == tolower(temp[i]);
						}
					}
				}

			}
		}
	}
	bool isWord(char c)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			return true;
		else return false;
	}
	//string s保证为纯字母字符串
	int getWord(string s, elementType word)
	{
		elementType word;
		int len = 0;
		for (auto ch : s)
		{
			if (isWord(ch))
			{
				word[len++] = ch;
				if (len == MAXWORDLENGTH)
					break;
			}
			else continue;
		}
		word[len] = '\0';
		return len;
	}
};