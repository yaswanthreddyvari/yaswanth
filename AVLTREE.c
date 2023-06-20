#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
int getHeight(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return root->height;
}
struct node *createNode(int key)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int getbalancefactor(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return getHeight(root->left)-getHeight(root->right);
}
struct node *rightRotate(struct node *y)
{
	struct node *x=y->left;
	struct node *T2=x->right;
	x->right=y;
	y->left=T2;
	y->height=max(getHeight(y->right),getHeight(y->left))+1;
	x->height=max(getHeight(x->right),getHeight(x->left))+1;
	return x;
}
struct node *leftRotate(struct node *x)
{
	struct node *y=x->right;
	struct node *T2=y->left;
	y->left=x;
	x->right=T2;
	y->height=max(getHeight(y->right),getHeight(y->left))+1;
	x->height=max(getHeight(x->right),getHeight(x->left))+1;
	return y;
}
struct node *insert(struct node *node,int key)
{
	if(node==NULL)
	{
		return (createNode(key));
	}
	if(key<node->data)
	{
		node->left=insert(node->left,key);
	}
	else if(key>node->data)
	{
		node->right=insert(node->right,key);
	}
	return node;
	node->height=1+max(getHeight(node->left),getHeight(node->right));
	int bf=getbalancefactor(node);
	//left left case
    if(bf>1 && key<node->left->data)
    {
    	return rightRotate(node);
	}
	//right right case
	if(bf<-1 && key>node->right->data)
	{
		return leftRotate(node);
	}
	//Left Right case
	if(bf>1 && key>node->left->data)
    {
    	node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	//Right Left Case
	if(bf<-1 && key<node->right->data)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
struct node *PreOrderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}
int main()
{
	struct node *root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,3);
	PreOrderTraversal(root);
	return 0;
}
