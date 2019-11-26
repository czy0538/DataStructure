#include <iostream>
#include <stack>
#include <queue>
#define NOINFO '0'
using namespace std;

using T = char;
class BinTree
{
private:
    typedef struct TreeNode
    {
        T data;
        TreeNode *left;
        TreeNode *right;
    } * position;
    //typedef TreeNode *position;
    position root = nullptr;

public:
    void preOrderTravelsal(position pos)
    {
        if (pos)
        {
            cout << pos->data << endl;
            preOrderTravelsal(pos->left);
            preOrderTravelsal(pos->right);
        }
    }
    //前序
    void preOrderTravelsal()
    {
        preOrderTravelsal(root);
    }

    void stack_preOrderTravelsal()
    {
        position pos = root;
        stack<position> s;
        while (pos || !s.empty())
        {
            while (pos)
            {
                cout << pos->data << endl;
                s.push(pos);
                pos = pos->left;
            }
            if (!s.empty())
            {
                pos = s.top()->right;
                s.pop();
            }
        }
    }
    //中序
    void inOrderTravelsal()
    {
        inOrderTravelsal(root);
    }
    void inOrderTravelsal(position pos)
    {
        if (pos)
        {
            inOrderTravelsal(pos->left);
            cout << pos->data << endl;
            inOrderTravelsal(pos->right);
        }
    }

    void stack_inOrderTravelsal()
    {
        position pos = root;
        stack<position> s;
        while (pos || !s.empty())
        {
            while (pos)
            {
                s.push(pos);
                pos = pos->left;
            }
            if (!s.empty())
            {
                pos = s.top();
                s.pop();
                cout << pos->data << endl;
                pos = pos->right;
            }
        }
    }
    //后序
    void postOrderTravelsal()
    {
        postOrderTravelsal(root);
    }
    void postOrderTravelsal(position pos)
    {

        if (pos)
        {
            postOrderTravelsal(pos->left);
            postOrderTravelsal(pos->right);
            cout << pos->data << endl;
        }
    }

    void stack_postOrderTravelsal()
    {
        //通过结构体记录指针和第几次访问该节点
        struct PosData
        {
            bool flag = false;
            position pos = nullptr;
        };
        position pos = root;
        stack<PosData> s;
        PosData pd;
        while (pos || !s.empty())
        {
            while (pos)
            {
                //第一次访问到底
                pd.flag = false;
                pd.pos = pos;
                s.push(pd);
                pos = pos->left;
            }
            if (!pos)
            {

                pd = s.top();
                s.pop();
                pos = pd.pos;
                if (!pd.flag)
                {
                    //第二次取出后再放回
                    pd.flag = true;
                    s.push(pd);
                    pos = pos->right;
                }
                else
                {
                    //第三次取出
                    cout << pos->data << endl;
                    pos = nullptr;//必须赋空，否则会被重复压入
                }
            }
        }
    }


    //创建树
    void creatTree()
    {
        queue<position> q;
        T data;
        cin >> data;
        if (data == NOINFO)
        {
            root = nullptr;
        }
        else
        {
            root = new TreeNode;
            root->data = data;
            root->left = root->right = nullptr;
            q.push(root);
        }
        while (!q.empty())
        {
            position temp = q.front();
            q.pop();
            cin >> data;
            if (data == NOINFO)
            {
                temp->left = nullptr;
            }
            else
            {
                temp->left = new TreeNode;
                temp->left->data = data;
                q.push(temp->left);
            }
            cin >> data;
            if (data == NOINFO)
            {
                temp->right = nullptr;
            }
            else
            {
                temp->right = new TreeNode;
                temp->right->data = data;
                q.push(temp->right);
            }
        }
    }
};

int main()
{
    BinTree tree;
    tree.creatTree();
    // tree.preOrderTravelsal();
    // tree.stack_preOrderTravelsal();
    tree.postOrderTravelsal();
    tree.stack_postOrderTravelsal();

    system("pause");
    return 0;
}