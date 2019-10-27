#include <iostream>
using namespace std;
typedef int elementType; //数据类型
/*
若用c语言，sizeof一定要加上struct，或者使用typedef别名，malloc一定sizeof结构体而不是结构体指针
*/
//单向链表
typedef struct Node
{
    elementType data;
    Node *next;
} * position; //结构体指针

position create(int len)
{
    position front;
    position ptr = new Node;
    ptr->next = nullptr;
    front = ptr; //头节点
    for (int i = 0; i < len; i++)
    {
        //若不带头结点第一次输入需要判断，比较麻烦
        position temp = new Node;
        cin >> temp->data;
        temp->next = nullptr;
        ptr->next = temp;
        ptr = temp;
    }
    return front;
    //去头节点
    // ptr=front->next;
    // delete front;
    // return ptr;
}

void traversing(position front)
{
    position ptr = front->next;
    while (ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
//将元素插入进pos位置，从0开始
bool insert(position front, int pos)
{
    position temp = new Node;
    cin >> temp->data;
    temp->next = nullptr;
    if (pos == 0)
    {
        temp->next = front->next;
        front->next = temp;
        return true;
    }
    else
    {
        int i = 0;
        position p = front->next;
        while (p && i < pos - 1)
        {
            p = p->next;
            ++i;
        }
        if (p == nullptr || i != pos - 1)
        {
            cout << "插入位置错误" << endl;
            delete temp;
            return false;
        }
        else
        {
            temp->next = p->next;
            p->next = temp;
            return true;
        }
    }
}

bool deleteNode(position front,int pos)
{
    if(pos==0)
    {
        front->next=front->next->next;
        delete front->next;
        return true;
    }
    else
    {
        int i=0;
        position p=front->next;
        while(p&&i<pos-1)
        {
            p=p->next;
            ++i;
        }
        if(p==nullptr||i!=pos-1)
        {
            cout<<"wrong position"<<endl;
            return false;
        }
        else
        {
            position temp=p->next;
            p->next=temp->next;
            delete temp;
            return true;
        }
    }

}

int main()
{
    position p = create(5);
    traversing(p);
    insert(p, 0);
    insert(p, 6);
    traversing(p);
    deleteNode(p,6);
    traversing(p);

    system("pause");
    return 0;
}