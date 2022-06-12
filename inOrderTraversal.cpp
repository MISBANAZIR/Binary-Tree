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

int inOrderTraversal(node *root)
{
	if(root == NULL)
	{
		return 0;
	}
 inOrderTraversal(root -> left);
 inOrderTraversal(root -> right);
 printf("%d", root -> data);
}

int main ()
{
	node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	inOrderTraversal(root);
	return 0;
}
