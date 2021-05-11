#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head;
void insert(int num, int position)
{
    Node *temp = new Node();
    temp->data = num;
    temp->next = NULL;
    if (position == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
};
void print(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << endl;
        print(p->next);
    }
};
void printReverse(Node *p)
{

    if (p != NULL)
    {
        printReverse(p->next);
        cout << p->data << endl;
    }
};
void reverseList(Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverseList(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
};
void reverseWithStack()
{
    stack<Node *> S;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        S.push(temp);
        temp = temp->next;
    }
    Node *temp2 = S.top();
    while (!S.empty())
    {
        temp2->next = S.top();
        S.pop();
        temp2 = temp2->next;
        cout << temp2->data << endl;
    }
    temp2->next = NULL;
}
int main()
{
    head = NULL;
    insert(2, 1);
    insert(3, 2);
    insert(4, 3);
    insert(2000, 4);
    insert(10000, 5);

    // print(head);
    // // print();
    reverseWithStack();
    // reverseList();
    // print(head);
    // printReverse(head);
}