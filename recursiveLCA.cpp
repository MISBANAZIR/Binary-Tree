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

node *recursiveLCA(node *root , int p, int q)
{
	if(root == NULL)
	{
		return  NULL;
	
	}
 if (root -> data > p && root -> data > q)
 return recursiveLCA(root -> left , p, q);
 if(root -> data < p && root -> data < q)
 return recursiveLCA(root -> right, p, q);
 
 return root;
}

int main ()
{
	node *root = newNode(25);
	root -> left = newNode(10);
	root -> right = newNode(30);
	root -> left -> left = newNode(5);
	root -> left -> right = newNode(15);
	root -> left -> right -> left = newNode(12);
	node *temp;
	temp = recursiveLCA(root , 5,12);
	printf("%d", temp -> data);
	return 0;
	
}
