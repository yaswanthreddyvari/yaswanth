#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL,*p,*temp;
struct node *Create()
{
	int key;
	temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of the node...\n");
	scanf("%d",&key);
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *Insertion(struct node *root,int key)
{
	Create();
	temp=(struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	{
	    root=temp;
	}
	if(key<root->data)
	{
		root->left=Insertion(root->left,key);
	}
	else
	{
		root->right=Insertion(root->right,key);
	}
	return root;
}
void InOrderTraversal(struct node *root)
{
	if(root==NULL)
	{
		printf("Tree is Empty....\n");
	}
	if(root->left!=NULL)
	{
		InOrderTraversal(root->left);
		printf("%d->",root->data);
	}
	if(root->right!=NULL)
	{
		InOrderTraversal(root->right);
	}
}
void PreOrderTraversal(struct node *root)
{
	if(root==NULL)
	{
		printf("Tree is Empty...\n");
	}
	if(root->left!=NULL)
	{
		printf("%d->",root->data);
		PreOrderTraversal(root->left);
	}
	if(root->right!=NULL)
	{
		PreOrderTraversal(root->right);
	}
	//printf("\n");
}
void PostOrderTraversal(struct node *root)
{
	if(root==NULL)
	{
		printf("Tree is empty...\n");
	}
	if(root->left!=NULL)
	{
		PostOrderTraversal(root->left);
	}
	if(root->right!=NULL)
	{
		PostOrderTraversal(root->right);
		printf("%d->",root->data);
	}
	//printf("\n");
}
int main()
{
	int key,opt;
	//struct node *root=NULL;
	//printf("Enter the data of the key value...\n");
	//scanf("%d",&key);
	//printf("Enter the data of the root node..\n");
	//scanf("%d",&root);
	do
	{
	printf("1.Creation\n2.Insertion\n3.InorderTraversal\n4.PreorderTraversal\n5.PostorderTraversal\n");
	printf("Enter your choice...\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
	        Create();
	        break;
	    case 2:
	    	 Insertion(root,key);
	    	 break;
	    case 3:
	    	 InOrderTraversal(root);
	    	 break;
	    case 4:
	    	PreOrderTraversal(root);
	    	 break;
	    case 5:
	    	 PostOrderTraversal(root);
	    	 break;
	    default:
	    	 printf("You entered Invalid option...\n");
   }
  }while(opt>0);
return 0;
}
