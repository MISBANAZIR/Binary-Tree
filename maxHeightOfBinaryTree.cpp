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
}

int MaxDepth(struct node *root)
{
if(root == NULL)
{
    return 0;
}
else {
    int lheight = MaxDepth(root -> left);
    int rheight = MaxDepth(root -> right);
    if(lheight > rheight)
        return (lheight+1);
        else return (rheight+1);
        
    
    }
}

int main()
{
    struct node *root = insert(1);
    root -> left = insert(2);
    root -> right = insert(3);
    root -> left -> left = insert(4);
   // root -> left -> right = insert(5);
   // root -> right -> left = insert(6);
   // root -> right -> right = insert(7);
   root -> left -> left -> left = insert(8);
   root -> left -> left -> left -> left = insert(9);
    cout<<"the max height of the tree is "<<MaxDepth(root);
    return 0;
}
// time complexity = O(n);
// space complexity = O(n);