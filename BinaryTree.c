#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*p,*temp;
struct node *create()
{
	int x;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf(" data of the node(enter -1 for no node): ");
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;
	}
	newnode->data=x;
	printf("\nEnter %d th left child",x);
	newnode->left=create();
	printf("\nEnter %d th right child",x);
	newnode->right=create();
	return newnode;
}
void inordertraversal(struct node *root)
{
	if(root!=NULL)
	{
		inordertraversal(root->left);
		printf("%d ",root->data);
		inordertraversal(root->right);
	}
	
}
void preordertraversal(struct node *root)
{
	if(root!=NULL)
	{
	printf("%d ",root->data);
	preordertraversal(root->left);
	preordertraversal(root->right);
   }
}
void postordertraversal(struct node *root)
{
    if(root!=NULL)
    {
 	postordertraversal(root->left);
	postordertraversal(root->right);
	printf("%d ",root->data);	
   }
}
struct node *minvalue(struct node *root)
{
	p=root;
	while(p!=NULL && p->left!=NULL)
	{
		p=p->left;
	}
	return p;
}
struct node *maxvalue(struct node *root)
{
	p=root;
	while(p!=NULL && p->right!=NULL)
	{
		p=p->right;
	}
	return p;
}
struct node *delete(struct node *root,int key)
{
	if(root==NULL)
	{
		return root;
	}
	if(key<root->data)
	{
		root->left=delete(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=delete(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}
		temp=minvalue(root->right);
		root->data=temp->data;
		root->right=delete(root->right,temp->data);
		return root;
	}
}
int searching(struct node *root,int key)
{
	if(root==NULL)
	{
		printf("There is empty.\n");
	}
	while(root!=NULL)
    {
	if(key<root->data)
	{
		root=root->left;
	}
	else if(key>root->data)
	{
		root=root->right;
	}
	else
	{
	return 1;
    }
  }
    return 0;
}
int num_nodes(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return (num_nodes(root->left)+num_nodes(root->right)+1);
	}
}
int num_internalnodes(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return 0;
	}
	else
	{
		return (num_internalnodes(root->left)+num_internalnodes(root->right)+1);
	}
}
int num_externalnodes(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return 1;
	}
	else
	{
		return (num_externalnodes(root->left)+num_externalnodes(root->right));
	}
}
int max_depth(struct node *root)
{
	int lDepth,RDepth;
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		lDepth=max_depth(root->left);
		RDepth=max_depth(root->right);
	}
	if(lDepth>RDepth)
	{
		return lDepth+1;
	}
	else
	{
		return RDepth+1;
	}
}
void main()
{
	int ops,key,search,total_nodes,total_internalnodes,externalnodes,Height;
	struct node *root;
	struct node *min;
	struct node *max;
	root=NULL;
	root=create();
	do
	{
	printf("\n1.In-Ordertraversal\n2.Pre-Ordertraversal\n3.Post-Ordertraversal\n4.Delete\n5.Searching\n6.Minimum-Value in the tree\n7.Maximum-Value\n8.Total no.of nodes in tree\n9.No.of internal nodes in tree\n10.No of external nodes\n11.Depth of the tree(Height)\n");
	printf("Enter your option:\n");
	scanf("%d",&ops);
	switch(ops)
	{
		case 1:
	        printf("Elements in inorder-traversal are:\n");
	        inordertraversal(root);
	        break;
	    case 2:
	        printf("Elements in pre-order traversal are:\n");
	        preordertraversal(root);
	        break;
	    case 3:
			printf("Elements in post-order traversal are:\n");
            postordertraversal(root);
            break;
        case 4:
        	printf("Enter the key value\n");
        	scanf("%d",&key);
        	delete(root,key);
        	break;
        case 5:
        	printf("Enter the key you wnat to search:\n");
        	scanf("%d",&key);
        	//search=searching(root,key);
        	if(searching(root,key)==1)
        	{
        		printf("Searching is successfull.\n");
			}
			else 
			{
				printf("Searching is unsuccessfull.\n");
			}
			break;
		case 6:
            min=minvalue(root);
            printf("The minimum value in the tree=%d\n",min->data);
            break;
        case 7:
            max=maxvalue(root);
            printf("The maximum value in the tree=%d\n",max->data);
            break;
        case 8:
        	total_nodes=num_nodes(root);
        	printf("Total no of nodes present in the tree are %d\n",total_nodes);
        	break;
        case 9:
        	total_internalnodes=num_internalnodes(root);
        	printf("No of internal nodes in the tree are %d\n",total_internalnodes);
        	break;
        case 10:
        	externalnodes=num_externalnodes(root);
        	printf("No of external nodes in the tree are %d\n",externalnodes);
        	break;
        case 11:
        	Height=max_depth(root);
        	printf("The maximum depth of the tree is %d\n",Height);
        	break;
		default:
        	printf("You entered Invalid option,......");
    }
  }while(ops>0);
}
