#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

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
                Q.push(current->left);
            if (current->right != NULL)
                Q.push(current->right);
            Q.pop();
        }
    }
};
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
        return;
    cout << root << endl;

    depthFirstPreOrder(root->left);

    depthFirstPreOrder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insertANode(root, 600);
    root = insertANode(root, 500);
    root = insertANode(root, 600);
    root = insertANode(root, 20);
    root = insertANode(root, 8);
    root = insertANode(root, 60);
    root = insertANode(root, 10);
    root = insertANode(root, 15);
    root = insertANode(root, 25);
    depthFirstPreOrder(root);

    root->breadthFirstTraversal(root);
}