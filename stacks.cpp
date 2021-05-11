#include <iostream>
#include <string>
#include <list>
using namespace std;

// int stack[10];
// int top = -1;
// void push(int x)
// {
//     if (top == 10 - 1)
//     {
//         return;
//     }
//     top++;
//     stack[top] = x;
// };
// void pop()
// {
//     if (top == -1)
//     {
//         return;
//     }
//     top--;
// };
// void topElement()
// {
//     cout << stack[top];
// }

class Node
{
private:
    int data;
    Node *next;

public:
    void push(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
    }
};
Node *top;
int main()
{
    top = NULL;
    // push(2);
    // push(4);
    // push(4);
    // push(8);
    // topElement();
}