#include<iostream>
using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node *insert(int val)
{
    struct node *temp = new node;
    temp -> val = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

int main()
{
    struct node *root = NULL;
    root = insert(10);
    root -> left = insert(20);
    root -> right = insert(30);
    root -> left -> left = insert(40);
    root -> left -> left -> right = insert(50);
    root -> right -> left = insert(60);
    root -> right -> right = insert(70);
    cout<<root -> left -> val;
    
    return 0;
}
