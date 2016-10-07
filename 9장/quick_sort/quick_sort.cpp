#include <stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 10

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do
	{
		do
		{
			low++;
		}while(low <= right && list[low] < pivot);
		do
		{
			high--;
		}while(high >= left && list[high] > pivot);
		if(low < high) SWAP(list[low], list[high], temp);
	}while(low < high);

	SWAP(list[left], list[high], temp);
	return high;
}
void quickSort(int list[], int left, int right)
{
	if(left < right)
	{
		int q=partition(list, left, right);
		quickSort(list, left, q-1);   
		quickSort(list, q+1, right);
	}
}
void printList(int list[],int left, int right)
{
	int i;
	for(i=left;i<=right;i++)
		printf(" %d  ",list[i]);
	printf("\n");
}

void main()
{
	int list[MAX_SIZE]={5,3,8,4,9,1,6,2,7,10};
	int n=MAX_SIZE;
	quickSort(list,0,n-1);
	printList(list,0,n-1);
}