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

int getLevel(node *root, int data, int level)
{
	if(root == NULL)
	{
		return 0;
	}
	if (root -> data == data)
	{
		return level;
	}
	int level2 = getLevel(root -> left, data, level + 1);
	if(level2 != 0)
	return level2;
	level2 = getLevel(root -> right, data, level + 1);
	return level2;
}

int levelUtil(node *root, int data)
{
	return getLevel(root, data, 1);
}

int main()
{
	node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	 int temp;
	temp = levelUtil(root, 4);
//	if(temp != NULL)
	printf("%d",levelUtil(root , 4));
	return 0;
}
