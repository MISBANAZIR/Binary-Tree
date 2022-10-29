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

void printNodes(struct node *root, int key, int dist)
{
    if(root == NULL)
    {
        return;
    }
    if(key == dist)
    {
        cout<<root -> val<<endl;
        return;
    }
    printNodes(root -> left, key, dist + 1);
    printNodes(root -> right, key, dist + 1);
    }


int main()
{
    struct node *root = insert(1);
    root -> left = insert(2);
    root -> right = insert(3);
    root -> left -> left = insert(4);
    root -> left -> right = insert(5);
    root -> right -> left = insert(6);
    root -> right -> right = insert(7);
    printNodes(root, 2, 0);
    return 0;
}
// time complexity = O(n)
// space complexity = O(n)