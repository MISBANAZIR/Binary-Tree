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

int sumTree(node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root -> left  == NULL && root -> right == NULL)
	{
		return root -> data;
	}
	int leftsum = sumTree(root -> left);
	int rightsum = sumTree(root -> right);
	if(leftsum == -1 ||  rightsum == -1)
	return -1;
	int sum = leftsum + rightsum;
	if( root -> data == sum)
	{
		return 2*root -> data;
	}
	return -1;
}

int main()
{
	node *root = newNode(50);
	root -> left = newNode(15);
	root -> right = newNode(10);
	root -> left -> left = newNode(10);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(7);
	root -> right -> right = newNode(3);
	if(sumTree(root) != -1)
	printf("the given binary tree is sum tree");
	else 
    printf("the given binary tree is not sum tree");	
	return 0;
}
