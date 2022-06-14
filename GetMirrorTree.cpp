#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	node *left;
	node *right;
};

node *newNode(int data)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp -> data = data;
	temp -> left = temp -> right = NULL;
	return temp;
}

void getMirrorTree(node *root)
{
	if(root == NULL)
	{
		return;
	}
 getMirrorTree(root -> left);
 getMirrorTree(root -> right);
 node *temp;
 temp = root -> left;
 root -> left = root -> right;
 root -> right = temp;
}
void inOrder(node *root)
{
	if(root == NULL)
	{
		return;
	}
 inOrder(root -> left);
 printf("%d", root -> data);
 inOrder(root -> right);
}

int main()
{
	node*root = newNode(5);
	root -> left = newNode(4);
	root -> right = newNode(6);
//	getMirrorTree(root);
	inOrder(root);
	return 0;
}
