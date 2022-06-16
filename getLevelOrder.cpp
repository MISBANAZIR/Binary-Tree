#include<stdio.h>
#include<stdlib.h>
#define MAX 500
struct node {
	int data;
	node *left;
	node *right;
};

node *newNode(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> left = temp -> right = NULL;
	return temp;
}

node **createQueue(int *rear, int *front)
{
	node **queue = (node **)malloc(sizeof(node *)*MAX);
	*rear = *front = 0;
	return queue;
	
}

void *enqueue(node **queue, int *rear, node *newNode)
{
	queue[(*rear)++] = newNode;
}

node *dequeue(node **queue, int *front)
{
	return queue[(*front)++];
}

int isQueueEmpty(int *rear, int *front)
{
	return (*rear == (*front));
	
}

void getLevelOrder(node *root)
{
	int rear, front;
	
	if(root)
	{
		node **queue = createQueue(&front , &rear);
		node *temp;
		enqueue(queue, &rear, root);
		while(!isQueueEmpty(&rear, &front))
		{
		 temp = dequeue(queue, &front);
		 printf("%d ", temp -> data);
		 if(temp -> left)
		 enqueue(queue, &rear, temp -> left);
		 if(temp -> right)
		 enqueue(queue, &rear, temp -> right);
		}
	}
}

int main()
{
	node *root = newNode(5);
	root -> left = newNode(6);
	root -> right = newNode(7);
	root -> left -> left = newNode(8);
	root -> left -> right = newNode(9);
	root -> right -> left = newNode(10);
	root -> right -> right = newNode(11);
	getLevelOrder(root);
	return 0;
}
