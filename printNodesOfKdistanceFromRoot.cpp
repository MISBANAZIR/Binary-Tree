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

void kDist(struct node *root, int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k == 0)
    {
        cout<<root -> val<<"\t";
        return;
    }
    kDist(root -> left, k - 1);
    kDist(root -> right, k - 1);
}

int main()
{
    struct node *root = insert(1);
    root -> left = insert(2);
    root -> right = insert(3);
    root -> left -> left = insert(4);
    root -> left -> right = insert(5);
    kDist(root, 1);

    return 0;
}

/*time complexity = O(n)
space complexity = O(h), h is the height of the binary tree as the number of nodes is n the size of the stake grown as large 
as the size of the tree so in worst case the size of the stake is O(n)*/