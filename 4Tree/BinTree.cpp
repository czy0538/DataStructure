#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class BinTree
{
private:
    typedef struct TreeNode *position;
    struct TreeNode
    {
        T data;
        position left;
        position right;
    };
    position root = nullptr;

public:
    //前序
    void preOrderTravelsal()
    {
        position pos = root;
        if (pos)
        {
            cout << pos->data << endl;
            preOrderTravelsal(pos->left);
            preOrderTravelsal(pos->right);
        }
    }

    void stack_preOrderTravelsal()
    {
        position pos = root;
        stack<position> s;
        while (pos || !s.empty())
        {
            while (pos)
            {
                s.push(pos); //first
                cout << pos->data << endl;
                pos = pos->left;
            }
            if (!s.empty())
            {
                pos = s.pop(); //second
                pos = pos->right;
            }
        }
    }
    //中序
    void inOrderTravelsal()
    {
        position pos = root;
        if (pos)
        {
            preOrderTravelsal(pos->left);
            cout << pos->data << endl;
            preOrderTravelsal(pos->right);
        }
    }

    void stack_inOrderTravelsal()
    {
        position pos=root;
        stack<position> s;
        while(pos||!s.empty())
        {
            while(pos)
            {
                s.push(pos);//first
                pos=pos->left;
            }
            if(!s.empty())
            {
                pos=s.pop();//second
                cout<<pos->data<<endl;
                pos=pos->right;
            }
        }
    }
    //后序
    void postOrderTravelsal()
    {
        position pos = root;
        if (pos)
        {
            preOrderTravelsal(pos->left);
            preOrderTravelsal(pos->right);
            cout << pos->data << endl;
        }
    }

    void stack_postOrderTravelsal()
    {
        position pos = root;
        stack<position> s;
        while (pos || !s.empty())
        {
            while (pos)
            {
                s.push(pos); //first
                pos = pos->left;
            }
            if (!s.empty())
            {
                pos = s.pop(); //second
                pos = pos->right;
            }
        }
        while(!s.empty())
        {
            cout<<s.pop()<<endl;
        }
    }

};