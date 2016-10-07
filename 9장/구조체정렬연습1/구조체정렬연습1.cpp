#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

typedef struct
{
	int id;
	char name[20];
}element;

void selection_sort(element* list,int n)
{
	int i,j,least,temp;
	for(i=0; i < n; i++)
	{
		least = i;
		for(j=i+1;j<n;j++)
			if(list[least].id > list[j].id)
				least = j;
		SWAP(list[i].id, list[least].id, temp);
	}
}

void selection_sort2(element list[], int n)
{ 
	//이름 순으로 정렬
}
void insertion_sort(element* list, int n)
{
	int i, j, key;
	for(i = 1; i < n; i++)
	{
		key = list[i].id;
		for(j = i - 1; j >= 0 && list[j].id > key; j--)
			list[j + 1].id = list[j].id;
		list[j + 1].id = key;
	}
}

void main()
{
	int i;
	element list[MAX_SIZE]={{45,"Kwon"},{30,"Lee"},{25,"Park"},{54,"Kim"},{13,"Choi"}};
	int n=MAX_SIZE;

		
	selection_sort2(list,n);
//	insertion_sort(list,n);
	for(i=0;i<n;i++)
		printf("%d, %s\n ",list[i].id,list[i].name);
	printf("\n");

  
}