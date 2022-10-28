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

int getLevel(struct node *root, int level, int key)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root -> val == key)
    {
        return level;
    }
    int level2 = getLevel(root -> left, level + 1, key);
    if(level2 != -1)
    {
        return level2;
    }
    return getLevel(root -> right, level + 1, key);
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
    cout<<"the level of the given value is "<<getLevel(root, 1, 3);
    return 0;
}