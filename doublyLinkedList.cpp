#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
Node *head;
void insertAtHead(int value)
{
    Node *temp = new Node();
    temp->data = value;

    if (head == NULL)
    {
        head = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
};
void printReverse()
{
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {

        temp = temp->next;
    } // Get Last Element

    while (temp != NULL)
    {

        cout << temp->data << endl;
        temp = temp->prev;
    }
};

int main()
{
    head = NULL;
    insertAtHead(2);
    insertAtHead(6);
    printReverse();
}