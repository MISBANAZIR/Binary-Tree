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

struct node *iterativeLCA(struct node *root, int p, int q)
{
    while(root != NULL)
    {
        if(root -> val > p && root -> val > q)
            root = root -> left;
        else if(root -> val < p && root -> val < q)
            root = root -> right;
        else 
            break;
    }
    return root;
}

int main()
{
    struct node *root;
    root = insert(20);
    root -> left = insert(7);
    root -> right = insert(21);
    root -> left -> left = insert(3);
    root -> left -> right = insert(11);
    root -> left -> right -> left = insert(9);
    root ->left -> right -> right = insert(13);
    struct node *lca = iterativeLCA(root, 3,11);
    cout<<"LCA of 7 and 21 is "<<lca -> val;
    

    return 0;
}

// time complexity = O(n)
// space complexity = O(1)
    