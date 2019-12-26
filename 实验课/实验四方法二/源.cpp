#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<string>
constexpr int MAXWORDSIZE = 100;
using namespace std;
class InvertedIndex
{
private:
	typedef struct Node
	{
		string data = "-1";//标记空白
		bool paper[MAXWORDSIZE];
	}WordsTable[MAXWORDSIZE];

	WordsTable words;
public:
	unsigned int BKDRHash(const char* str)
	{
		unsigned int seed = 131;
		unsigned int hash = 0;

		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return ((hash & 0x7FFFFFFF) % MAXWORDSIZE);
	}
	 int find(string s)
	{
		//处理冲突
		auto i = BKDRHash(s.c_str());
		while (words[i].data != "-1")
		{
			if (words[i].data == s)
			{
				return i;//成功返回地址
			}
			else
			{
				i = (i + 1) % MAXWORDSIZE;
			}
		}
		return -1;//失败返回0
	}
	unsigned int insert(string s)
	{
		//之前这里直接的返回了未处理的hash值
		auto h = find(s);
		if (h!=-1)
		{
			return h;
		}
		auto i = BKDRHash(s.c_str());
		if (words[i].data == "-1")
		{
			words[i].data = s;

		}
		else
		{
			while (words[i].data != "-1")
			{
				i = (i + 1) % MAXWORDSIZE;
			}
			words[i].data = s;

		}
		return i;
	}
	void creatTable()
	{
		int N;//文件数
		cin >> N;
		//初始化bool paper节点
		for (int i = 0; i < MAXWORDSIZE; i++)
		{

			for (int j = 0; j < N; ++j)
			{
				words[i].paper[j] = false;//设置有该单词为true，没有为false
			}
		}
		for (int i = 0; i < N; i++)
		{

			/*while (true)
			{
				string temp;
				getline(cin, temp);
				cout << temp.size() << endl;

				stringstream ss;
				ss << temp;
				if (temp == "#")
				{
					break;
				}
				else
				{
					while (!ss.eof())
					{
						ss >> temp;
						string t;
						int k;
						for (k = 0; k < temp.size(); ++k)
						{
							if (isalpha(temp[k]))
							{
								temp[k] = (char)tolower(temp[k]);
							}
							else
							{
								++k;
								t = temp.substr(k, temp.size() - k);
								temp = temp.substr(0, k - 1);
								ss << t;
								break;
							}
						}
						if (temp.size() > 10)
						{
							temp = temp.substr(0, 10);
						}
						auto hash1 = insert(temp);
						words[hash1].paper[i] = true;
						for (int j = 0; j < t.size(); j++)
						{
							if (isalpha(t[j]))
							{
								t[j] = (char)tolower(t[j]);
							}
						}
						if (t.size() > 0)
						{
							if (t.size() > 10)
							{
								t = t.substr(0, 10);
							}
							auto hash2 = insert(t);
							words[hash2].paper[i] = true;
						}

					}

				}
			}*/
			char ch;
			string temp;
			while (true)
			{
				ch = (char)cin.get();
				if (ch == '#')
					break;
				if (isalpha(ch))
				{
					ch = (char)tolower(ch);
					temp += ch;
				}
				else
				{
					if (!temp.empty())
					{
						if (temp.size() > 10)
						{
							temp = temp.substr(0, 10);
						}
						if (temp.size() < 3)
						{
							temp.clear();
							continue;
						}
						auto hash = insert(temp.c_str());
						words[hash].paper[i] = true;
						words[hash].data = temp;
						//cout << temp << endl;
						temp.clear();
						
					}
					continue;
				}
				
			}

		}
	}
	void printAll()
	{
		for (int i = 0; i < MAXWORDSIZE; i++)
		{
			if (words[i].data != "-1")
				cout << i << ":" << words[i].data << endl;
		}
	}
	void count()
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			//读入比较文件号并使其匹配
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			int countAll = 0;
			int countRepeat = 0;
			for (int j = 0; j < MAXWORDSIZE; ++j)
			{
				if (words[j].paper[a] || words[j].paper[b])
				{
					countAll++;
				}
				if (words[j].paper[a] && words[j].paper[b])
				{
					countRepeat++;
				}
			}
			cout <<  fixed << setprecision(1)<<100*( (double)countRepeat / (double)countAll)<<"%" << endl;

		}
	}
};

int main()
{
	InvertedIndex ii;
	ii.creatTable();
	//ii.printAll();
	ii.count();
	/*vector<string> s;
	s.push_back("these");
	s.push_back("two");
	s.push_back("files");
	s.push_back("are");
	s.push_back("the");
	s.push_back("same");
	for (auto t : s)
	{
		cout << ii.BKDRHash(t.c_str()) << endl;
	}*/
	
	return 0;
}