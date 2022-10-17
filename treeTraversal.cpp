#include<iostream>
using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node *newNode(int val)
{
    struct node *temp;
    temp = new node;
    temp -> val = val;
    temp -> left = temp -> right = NULL;
    return temp;
}

// tree traversal 
// preOrderTravesal

void preOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root -> val<<"\t";
    preOrder(root -> left);
    preOrder(root -> right);
}

// post order traversal

void postOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> val<<"\t";
}

// in order traversal

void inOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root -> left);
    cout<<root -> val<<"\t";
    inOrder(root -> right);
}

int main()
{
    struct node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(8);
    cout<<"\nPre Order Traversal"<<endl;
    preOrder(root);
    cout<<"\nPost Order Traversal"<<endl;
    postOrder(root);
    cout<<"\nIn Order Traversal"<<endl;
    inOrder(root);
    return 0;
}