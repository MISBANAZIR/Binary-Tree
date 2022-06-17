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

int maxHeight(node *root)
{
	if(root == NULL)
	{
		return 0;
	}
 else {
 	int lheight = maxHeight(root -> left);
 	int rheight = maxHeight(root -> right);
 	
 if (lheight > rheight)
 return (lheight + 1);
 else return (rheight + 1);
 }
}

int main ()
{
	node *root = newNode(4);
	root -> left = newNode(2);
	root -> right = newNode(6);
	root -> left -> left = newNode(1);
	root -> left -> left -> left = newNode(5);
//	root -> left -> right = newNode(3);
//	root -> right -> left = newNode(5);
//	root -> right -> right = newNode(7);
	 int temp = maxHeight(root);
	printf("%d", temp);
	return 0;
}
