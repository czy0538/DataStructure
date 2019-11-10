#include <iostream>
#include <stack>
#include <queue>
#define NOINFO '0'
using namespace std;

using T = char;
class BinTree
{
private:
    struct TreeNode
    {
        T data;
        TreeNode *left;
        TreeNode *right;
    };
    typedef TreeNode *position;
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
                s.push(pos); //first
                cout << pos->data << endl;
                pos = pos->left;
            }
            if (!s.empty())
            {
                pos = s.top(); //second
                s.pop();
                pos = pos->right;
            }
        }
    }
    //中序
    void inOrderTraversal()
    {
        inOrderTravelsal(root);
    }
    void inOrderTravelsal(position pos)
    {
        if (pos)
        {
            preOrderTravelsal(pos->left);
            cout << pos->data << endl;
            preOrderTravelsal(pos->right);
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
                s.push(pos); //first
                pos = pos->left;
            }
            if (!s.empty())
            {
                pos = s.top(); //second
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
            preOrderTravelsal(pos->left);
            preOrderTravelsal(pos->right);
            cout << pos->data << endl;
        }
    }

    void stack_postOrderTravelsal()
    {
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
    tree.preOrderTravelsal();

    system("pause");
    return 0;
}