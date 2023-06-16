#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int array[20],i,n,mid,min,key,top;
	printf("Enter the no of elements you want to insert\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d th element:",i);
		scanf("%d",&array[i]);
	}
	printf("The array elements are...\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",array[i]);
	}
	min=0;
	top=n-1;
	mid=(min+top)/2;
	printf("Enter the key element\n");
	scanf("%d",&key);
	while(min<=top)
	{
		mid=(min+top)/2;
		if(key==array[mid])
		{
			printf("%d is found at %d th index\n",key,mid);
			printf("Searching is successfull\n");
			break;
		}
		else if(key>array[mid])
		{
			min=mid+1;
		}
		else
		{
			top=mid-1;
		}
	}
	if(min>top)
	{
		printf("Key element is not present in the array\n");
	}
}
