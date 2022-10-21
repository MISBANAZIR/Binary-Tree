#include<iostream>
using namespace std;
#define MAX 500
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

struct node **createQueue(int *rear, int *front)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *) *MAX);
    *rear = *front = 0;
    return queue;
}

void enqueue(struct node **queue, int *rear, struct node *insert)
{
    queue[*(rear)++] = insert;
}

struct node *dequeue(struct node **queue, int *front)
{
    return queue[*(front)++];
}

int isNotEmpty(int *front, int *rear)
{
    return ((*rear) == (*front));
}

void levelOrderTraversal(struct node *root)
{
    int front, rear;
    if(root != NULL)
    {
        struct node **queue = createQueue(&front, &rear);
        struct node *temp;
        enqueue(queue, &rear, root);
        while(isNotEmpty(&front, &rear) != NULL)
        {
            temp = dequeue(queue, &front);
            cout<<temp -> val<<"\t";
            if(temp -> left)
                enqueue(queue, &rear, root -> left);
            if(temp -> right)
                enqueue(queue, &rear, root -> right);
        }

    }
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
    levelOrderTraversal(root);
    return 0;
}

// Time Complexity = O(n)
// Space complexity = O(n)