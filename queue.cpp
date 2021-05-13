
#include <iostream>

#include <list>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node *front = NULL;
    Node *rear = NULL;
    void enQueue(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = NULL;
        if (isEmpty())
        {

            front = rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    void deQueue()
    {
        Node *temp = front;
        if (front == NULL)
            return;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        delete (temp);
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        return false;
    }
    void printAList()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Node queue;
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.deQueue();
    queue.printAList();
}

// Array implementation of queue
// class arrQueue
// {
// private:
//     int queue[20];
//     int front = -1;
//     int rear = -1;

// public:
//     bool isEmpty()
//     {
//         if (front == -1 && rear == -1)
//         {
//             return true;
//         }
//         return false;
//     };
//     void enQueue(int value)
//     {
//         if ((rear + 1) % 20 == front)
//         {
//             cout << "Queue is full sorry";
//             return;
//         }
//         if (isEmpty())
//         {

//             front = rear = 0;
//             queue[rear] = value;
//         }
//         else
//         {
//             rear = (rear + 1) % 20;
//             queue[rear] = value;
//         }
//     }
//     void deQueue()
//     {
//         if (isEmpty())
//         {
//             return;
//         }

//         else if (front == rear)
//         {
//             front = rear = -1;
//         }
//         else
//         {
//             front = (front + 1) % 20;
//         }
//     }
//     int front()
//     {
//         return queue[front];
//     }
// };