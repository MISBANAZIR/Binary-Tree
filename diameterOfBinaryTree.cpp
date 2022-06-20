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

int max(int a, int b)
{
	return a > b ? a: b;
}

int diameterOfBinaryTree(node *root, int *height)
{
int lheight = 0, rheight = 0, ldiameter = 0, rdiameter = 0;
	if(root == NULL)
	{
		return 0;
	}

	ldiameter = diameterOfBinaryTree(root -> left, &lheight);
	rdiameter = diameterOfBinaryTree(root -> right, &rheight);
	
   *height = max(lheight, rheight) + 1;	
   return max(lheight + rheight, max(ldiameter, rdiameter)); 	
}

int main()
{
	node *root = newNode(1);
	int height;
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	printf("diameter of binary tree is %d", diameterOfBinaryTree(root, &height));
	return 0;
}
