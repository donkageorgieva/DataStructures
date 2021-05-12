#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <cstring>
#include <sstream>
#include <vector>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
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

// class Node
// {
// private:
//     int data;
//     Node *next;

// public:
//     void push(int value)
//     {
//         Node *temp = new Node();
//         temp->data = value;
//         temp->next = top;
//         top = temp;
//     }
// };
// class Stack
// {
// private:
//     int top = -1;
//     char A[101];

// public:
//     void Push(int x)
//     {
//         top++;
//         A[top] = x;
//     };
//     void Pop();
//     bool isEmpty();
//     int Top();
// };
void reverseAString(char *C, int length)
{
    stack<char> S;
    for (int i = 0; i < length; i++)
    {
        S.push(C[i]);
    }
    for (int i = 0; i < length; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}
bool IsNumericDigit(char C)
{
    if (C >= '0' && C <= '9')
        return true;

    return false;
}
bool isOperator(char C)
{
    if (C == '-' || C == '+' || C == '/' || C == '*')
        return true;
    return false;
}
void performOperation(int operand1, int operand2, char operatorType)
{
    switch (operatorType)
    {
    case '-':
        cout << operand1 - operand2;
        break;
    case '*':
        cout << operand1 * operand2;
        break;
    case '/':
        cout << operand1 / operand2;
        break;
    case '+':
        cout << operand1 + operand2;
        break;
    }
}
void postFixOperation(string exp)
{
    stack<int> S;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ' || exp[i] == ',')
            continue;
        if (IsNumericDigit(exp[i]))
        {

            S.push(exp[i] - '0');
        }
        else if (isOperator(exp[i]))
        {
            int operand1 = S.top();
            S.pop();
            int operand2 = S.top();
            S.pop();
            performOperation(operand1, operand2, exp[i]);
        }
    }
};
void inFixToPostFix(string exp)
{
    stack<char> S;
    string expression;
    for (int i = 0; i < exp.length(); i++)
    {
        if (!isOperator(exp[i]))
        {
            expression.push_back(exp[i]);
        }

        else if (isOperator(exp[i]))
        {
            if (S.empty())
            {
                S.push(exp[i]);
            }
            else
            {
                switch (exp[i])
                {
                case '+':
                    if (S.top() == '*' || S.top() == '/')
                    {
                        expression.push_back(exp[i]);
                        expression.push_back(S.top());
                        S.pop();
                    }
                    break;
                case '-':
                    if (S.top() == '*' || S.top() == '/')
                    {
                        expression.push_back(exp[i]);
                        expression.push_back(S.top());
                        S.pop();
                    }
                    else
                    {
                        S.push(exp[i]);
                    }
                    break;
                default:
                    S.push(exp[i]);
                }
            }
        }
    }
    while (!S.empty())
    {
        char current = S.top();
        expression.push_back(current);
        S.pop();
    }
    cout << expression;
}
// Node *top;
int main()
{
    // top = NULL;
    // char C[5];
    // cout << "Enter a string";
    // cin >> C;
    // reverseAString(C, strlen(C));
    // cout << C;

    // cout << isdigit('a');
    string expression;
    cin >> expression;
    // postFixOperation(expression);
    inFixToPostFix(expression);
    // push(2);
    // push(4);
    // push(4);
    // push(8);
    // topElement();
}