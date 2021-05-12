#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool arePair(char opening, char closing)
{
    if (opening == '[' && closing == ']')
        return true;
    else if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else
        return false;
}
bool check(string word)
{

    stack<char> Stack;

    for (int i = 0; i < word.length(); i++)
    {

        if (word[i] == '(' || word[i] == '[' || word[i] == '{')
        {
            Stack.push(word[i]);
        }
        else if (word[i] == ')' || word[i] == ']' || word[i] == '}')
        {
            if (Stack.empty() && !arePair(Stack.top(), word[i]))
            {
                cout << "Invalid";
                return false;
            }
            else
            {
                Stack.pop();
            }
        }
    }
    return Stack.empty() ? true : false;
}
int main()
{
    string word;
    cin >> word;
    if (check(word))
    {
        cout << "valid";
    }
    else
    {
        cout << "Invalid";
    }
}