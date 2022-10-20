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
    temp -> left = temp -> right = NULL;
    return temp;
}

struct node *findLCA(struct node *root, int p, int q)
{
    if(!root)
    {
        return root;
    }
    if(root -> val == p || root -> val == q)
    {
        return root;
    }
    struct node *left = findLCA(root -> left, p, q);
    struct node *right = findLCA(root -> right, p, q);
    if(left && right)
    {
        return root;
    }
    return (left ? left : right);
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
    struct node *lca = findLCA(root, 2, 3);
    cout<<"LCA of 2 and 3 is "<<lca -> val;
    return 0;
}

// time complexity = O(n)
// space complexity = O(n)
