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

node *findlca_BT(node *root, int p, int q)
{
	if (!root)
	{
		return root;
	}
 if(root -> data == p || root -> data == q)
 {
 	return root;
 }
 node *left_LCA = findlca_BT(root -> left, p, q);
 node *right_LCA = findlca_BT(root -> right, p, q);
 if(left_LCA && right_LCA)
 return root;
 return (left_LCA ? left_LCA : right_LCA);
}

int main()
{
	node *root = newNode(20);
	root -> left = newNode(7);
	root -> right = newNode(21);
	root -> left -> left = newNode(3);
	root -> left -> right = newNode(11);
	root -> right -> left = newNode(9);
	root -> right -> right = newNode(13);
	 node *temp = findlca_BT(root, 11, 9);
	 printf("%d", temp -> data);
	return 0;
	
}
