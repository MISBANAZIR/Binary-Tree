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
 
 int getLevel(node *root, int level, int key)
 {
 	if (root == NULL)
 	{
 		return 0;
	 }
 if (root -> data == key)
 {
 	return level;
 }
 int level2 = getLevel(root -> left , level + 1, key);
 if (level2 != 0)
 {
 	return level2;
 }
 return getLevel(root -> right, level + 1, key);
 }


int main ()
{
	node *root = NULL;
	root= newNode(10);
	root -> left = newNode(15);
	root -> right = newNode(20);
	root -> left -> left = newNode(25);
	root -> left -> right = newNode(30);
	root -> right -> left = newNode(35);
	root -> right -> right = newNode(40);
	int level2;
	 level2 = getLevel(root, 1, 25);
	 printf("%d", level2);
	return 0;
}


