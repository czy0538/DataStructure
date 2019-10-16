#include <iostream>
using namespace std;
typedef struct Node
{
    int index;
    int coefficient;
    Node *next;

} * position;

typedef struct PosNode
{
    position ptr;
    PosNode *next;
} * pos;

// 当输入的为过多的 0 1时就崩了
position creat(int n)
{
    position head = new Node;
    position p = head;
    head->next = nullptr;
    for (int i = 0; i < n; i++)
    {
        position temp = new Node;
        temp->next = nullptr;
        cin >> temp->coefficient >> temp->index;
        p->next = temp;
        p = temp;
    }
    p = head->next;
    delete head;
    return p;
}

void traversing(position head)
{
    if (head)//处理长度为0的节点
    {
        while (head && head->next)
        {
            cout << head->coefficient << " " << head->index << " ";
            head = head->next;
        }
        cout << head->coefficient << " " << head->index << endl;
    }
    else
    {
        cout << 0 << " " << 0 << endl;
    }
}

position add(position head1, position head2)
{
    position front, rear, temp;
    rear = new Node;
    front = rear;
    rear->next = nullptr;
    while (head1 && head2)
    {
        if (head1->index > head2->index)
        {
            rear->next = head1;
            rear = head1;
            head1 = head1->next;
        }
        else if (head1->index < head2->index)
        {
            rear->next = head2;
            rear = head2;
            head2 = head2->next;
        }
        else
        {
            int sum = head1->coefficient + head2->coefficient;
            if (sum)
            {
                position p = new Node;
                p->next = nullptr;
                p->coefficient = sum;
                p->index = head1->index;
                rear->next = p;
                rear = p;
            }

            position p1, p2;
            p1 = head1;
            head1 = head1->next;
            p2 = head2;
            head2 = head2->next;
            delete p1;
            delete p2;
        }
    }
    while (head1)
    {
        rear->next = head1;
        head1 = head1->next;
    }
    while (head2)
    {
        rear->next = head2;
        head2 = head2->next;
    }
    //去头结点
    temp = front->next;
    delete front;
    return temp;
}

position multiplication(position p1, position p2) //不会破坏结构
{
    pos posHead = new PosNode; //带头节点
    pos posFirst = posHead;
    posHead->next = nullptr;
    if (p1)
    {

        while (p1)
        {
            position temp_p2 = p2;
            //相乘产生的子链
            position tempHead = new Node; //带头节点
            position front = tempHead;
            tempHead->next = nullptr;
            while (temp_p2)
            {
                position tempNode = new Node;
                tempNode->next = nullptr;
                tempNode->coefficient = p1->coefficient * temp_p2->coefficient;
                tempNode->index = p1->index + temp_p2->index;
                tempHead->next = tempNode;
                tempHead = tempNode;
                temp_p2 = temp_p2->next;
            }
            tempHead = front;
            front = front->next; //去头结点
            delete tempHead;
            //逐个存放乘法后的各个链表；
            pos posTemp = new PosNode;
            posTemp->ptr = front;
            posTemp->next = nullptr;
            posHead->next = posTemp;
            posHead = posTemp;
            p1 = p1->next;
        }
        //去头结点
        posHead = posFirst;
        posFirst = posFirst->next;
        delete posHead;

        position temp_start = posFirst->ptr;
        posFirst = posFirst->next;
        while (posFirst)
        {
            temp_start = add(temp_start, posFirst->ptr);
            posFirst = posFirst->next;
        }
        return temp_start;
    }
    else
    {
        //处理长度为0的节点
        position temp = new Node;
        temp->coefficient = 0;
        temp->index = 0;
        temp->next = nullptr;

        return temp;
    }
}

int main()
{
    int len1, len2;
    cin >> len1;
    position t1 = creat(len1);
    cin >> len2;
    position t2 = creat(len2);

    // if(len1==1&&len2==1)
    // {
    //     if(t1->index==0&&t2->index==0)
    //     {
    //         cout<<0<<" "<<0<<endl;
    //         cout << 0 << " " << 0 ;
    //     }
    // }

    traversing(multiplication(t1, t2));


    traversing(add(t1, t2));
    // cout << "test";
    // system("pause");
    return 0;
}