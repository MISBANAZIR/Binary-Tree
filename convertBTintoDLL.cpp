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

node *convertBTintoDLL(node *root)
{
	if(root -> left)
	{
	node *ltree = convertBTintoDLL(root -> left);
	for(;ltree -> right; ltree = ltree -> right);
	ltree -> right = root;	
	root -> left = ltree;	
	}
if (root -> right)
{
	node *rtree = convertBTintoDLL(root -> right);
	for(;rtree -> left; rtree = rtree -> left);
	rtree -> left = root;
	root -> right = rtree;
}
return root;
}



int main ()
{
	node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	 node *temp = convertBTintoDLL(root);
	printf("%d ", temp -> data);
	while (temp -> left != NULL) temp = temp -> left;
	root = temp;
	while(root != NULL)
	{
		printf("%d ", root -> data);
		root = root -> right;
	}
	return 0;
}


