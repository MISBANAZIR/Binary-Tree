#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *left;
	node *right;
};


node *newNode(int data)
{
	node *temp =(node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> left = temp -> right = NULL;
	return temp;
}

int sizeOfTree(node *root)
{
	if(root == NULL)
	{
		return 0;
	}
 else {
 	return root ? (1 + sizeOfTree(root -> left) + sizeOfTree(root -> right)): 0;
 }
}

int main ()
{
	node *root = NULL;
	root = newNode(5);
	root -> left = newNode(6);
	root -> right = newNode(7);
	root -> left -> left = newNode(8);
	root -> left -> right = newNode(9);
	root -> right -> left = newNode(10);
	root -> right -> right = newNode(11);
	root -> left -> left -> left = newNode(12);
	root -> left -> left -> right = newNode(13);
	printf("%d", sizeOfTree (root));
	return 0;
}