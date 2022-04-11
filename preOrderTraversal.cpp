
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
preOrderTraversal(node *root)
{
 if(root == NULL)
 {
	return;
 }
printf("%d", root -> data);
preOrderTraversal(root -> left);
preOrderTraversal(root -> right);

}


int main()
{
	node *root = NULL;
	root = newNode(10);
	root -> left = newNode(20);
	root -> right = newNode(30);
	root -> left -> left = newNode(40);
	root -> left -> right = newNode(50);
	root -> right -> left = newNode(60);
	root -> right -> right = newNode(70);
	int preOrder;
	preorder = preOrderTraversal(root);
	printf("%d", preorder -> data);
	
	return 0;
}
