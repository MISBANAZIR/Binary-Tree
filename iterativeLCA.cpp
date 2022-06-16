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

node *iterativeLCA(node *root, int p , int q)
{
	while(root)
	{
		if(root -> data > p && root -> data > q)
		root = root -> left;
	  else if (root -> data < p && root -> data < q)
	 root = root -> right;
	 else break;
	}
 return root;
}

int main ()
{
	node *root = newNode(20);
	root -> left = newNode(7);
	root -> right = newNode(21);
	root -> left -> left = newNode(3);
	root -> left -> right = newNode(24);
	root -> right -> left = newNode(14);
	root -> right -> right = newNode(23);
	node *temp;
temp = 	iterativeLCA(root , 24, 14);
	printf("%d", temp -> data);
	return 0;
}
