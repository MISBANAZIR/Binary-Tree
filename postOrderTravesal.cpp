#include<stdio.h>
#include<Stdlib.h>

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

int postOrderTraversal(node *root)
{
	if (root == NULL)
	{
		return 0;
	}
postOrderTraversal(root -> left);
printf("%d", root -> data);
postOrderTraversal(root -> right);	

}

int main()
{
	node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	postOrderTraversal(root);
}
