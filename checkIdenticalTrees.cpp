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

int checkIdenticalTrees(node *root1 , node *root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return 1;
	}
if(root1 && root2)
{
	return (root1 -> data == root2 -> data)&&
	checkIdenticalTrees(root1 -> left , root2 -> left) &&
	checkIdenticalTrees(root1 -> right , root2 -> right);
	
}
return 0;
}

int main()
{
	node *root1 = NULL;
	node *root2 = NULL;
	root1 = newNode(5);
	root1 -> left = newNode(6);
	root1 -> right = newNode(7);
	root1 -> left -> left = newNode(8);
	root1 -> left -> right = newNode(9);
	root1 -> right -> left = newNode(10);
	root1 -> right -> right = newNode(11);
	root2 = newNode(5);
	root2 -> left = newNode(6);
	root2 -> right = newNode(7);
	root2 -> left -> left = newNode(8);
	root2 -> left -> right = newNode(9);
    root2 -> right -> left = newNode(10);
	root2 -> right -> right = newNode(11);

	if (checkIdenticalTrees(root1 , root2))
	{
	printf(" BSTs are identical ");
}
  else {

    
		printf("not identical");
}
	
    return 0;	
}
