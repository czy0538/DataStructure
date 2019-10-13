#include <iostream>
using namespace std;
typedef struct Node
{
    int index;
    int coefficient;
    Node *next;

} * position;

position creat(int n)
{
    position head = new Node;
    position p = head;
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
    while (head)
    {
        cout << head->coefficient << " " << head->index << endl;
        head = head->next;
    }
}

position add(position head1, position head2)
{
    position front, rear, temp;
    rear = new Node;
    front = rear;
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
                rear=p;
            }

            position p1, p2;
            p1 = head1;
            head1 = head1->next;
            p2 = head2;
            head2 = head2->next;
            delete p1, p2;
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
    temp = front->next;
    delete front;
    return temp;
}

int main()
{
    cout << "hello world" << endl;
    position t1 = creat(5);
    traversing(t1);
    position t2 = creat(4);
    //traversing(t2);
    traversing(add(t1, t2));
    system("pause");
    return 0;
}