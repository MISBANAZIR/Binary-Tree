#include<stdio.h>
#include<stdlib.h>

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

 void printNode(node *root, int k, int dist)
{
	if(root != NULL)
	{
	
		if( k == dist)
		{
			printf("%d ", root -> data);
			return;
		}
	printNode(root -> left, k, dist + 1);
	printNode(root -> right, k, dist + 1);
	}
}


int main()
{
	node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
//	int temp = printNode(root, 3, 1);
	//printf("%d", printNode(root, 3, 1));
	printNode(root , 0, 0);
	return 0;
}
