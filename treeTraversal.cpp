#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
void breadthFirstTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << endl;
        if (current->left != NULL)
        {
            Q.push(current->left);
        }

        if (current->right != NULL)
        {
            Q.push(current->right);
        }

        Q.pop();
    }
}
Node *insertANode(Node *root, int value)
{
    Node *temp = new Node();
    temp->data = value;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        if (value <= root->data)
        {
            root->left = insertANode(root->left, value);
        }
        else
        {
            root->right = insertANode(root->left, value);
        }
    }
    return root;
}
void depthFirstPreOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << ' ';

    depthFirstPreOrder(root->left);

    depthFirstPreOrder(root->right);
}

bool isBinarySearchTree(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->data >= minValue && root->data <= maxValue)
    {
        isBinarySearchTree(root->left, minValue, root->data);
        isBinarySearchTree(root->right, root->data, maxValue);
    }

    else
        return false;
}
Node *minNode(Node *root)
{
    while (root != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteANode(Node *root, int value)
{
    if (root == NULL)
        return root;

    else if (root->data > value)
        root->left = deleteANode(root->left, value);
    else if (root->data < value)
        root->right = deleteANode(root->right, value);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteANode(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    root = insertANode(root, 50);
    root = insertANode(root, 25);
    root = insertANode(root, 15);

    // root->breadthFirstTraversal(root);

    depthFirstPreOrder(root);
    deleteANode(root, 15);
    depthFirstPreOrder(root);
    root = insertANode(root, 10);
    depthFirstPreOrder(root);
}