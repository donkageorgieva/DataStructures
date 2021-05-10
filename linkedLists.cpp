#include <iostream>
#include <string>
#include <list>
using namespace std;

// void display(void *value, char type)

// {
//     switch (type)
//     {
//     case 'i':
//         cout << *((int *)(value)) << endl;
//         break;
//     case 'c':
//         cout << *((char *)(value)) << endl;
//         break;
//     }
// }
// void getMinAndMax(int numbers[], int size, int *min, int *max)
// {

//     for (int i = 1; i < size; i++)
//     {
//         if (numbers[i] > *max)

//             *max = numbers[i];

//         if (numbers[i] < *min)

//             *min = numbers[i];
//     };
// };
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
void removeFromList(int position)
{

    Node *temp1 = head;
    if (position == 1)
    {
        head = temp1->next;
        delete (temp1);
        return;
    }

    for (int i = 0; i < position - 2; i++)
    {
        temp1 = temp1->next;
    }

    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete (temp2);
};
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
};
void reverseList()
{
    Node *current = head;
    Node *prev = NULL;

    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main()
{
    head = NULL;
    insert(2, 1);
    insert(3, 2);
    insert(4, 3);
    insert(2000, 4);
    insert(10000, 5);

    // print();

    reverseList();
    print();
}

// head = NULL;
// cout << "How many numbers";
// int n;
// cin >> n;
// for (int i = 0; i <= n; i++)
// {
//     int num;
//     cin >> num;
//     insert(num);
//     print();
// }