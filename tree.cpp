#include <iostream>
using namespace std;
class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode *insertANode(BstNode *root, int value)
{

    if (root == NULL)
    {
        root = GetNewNode(value);
    }
    else if (value <= root->data)
    {
        root->left = insertANode(root->left, value);
    }
    else
    {
        root->right = insertANode(root->right, value);
    }
    return root;
}
bool searchTree(BstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return searchTree(root->left, data);
    }
    else
    {
        return searchTree(root->right, data);
    }
}
int main()
{
    BstNode *root = NULL;

    root = insertANode(root, 20);
    root = insertANode(root, 10);
    root = insertANode(root, 15);
    root = insertANode(root, 11);
    root = insertANode(root, 16);
    int number;
    cout << "Enter a number";
    cin >> number;
    if (searchTree(root, number) == true)
        cout << "yes";
}