#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 50000
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

void selection_sort(int list[],int n)
{
	int i,j,least,temp;
	for(i=0; i < n; i++)
	{
		least = i;
		for(j=i+1;j<n;j++)
			if(list[least] > list[j])
				least = j;
		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++)
	{
		key = list[i];
		for(j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for(i = n - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
			if(list[j] > list[j+1])
				SWAP(list[j], list[j + 1], temp);
	}
}

void inc_insertion_sort(int list[],int first,int last,int gap)
{
	int i, j, key;
	for(i = first + gap; i <= last; i = i + gap)
	{
		key = list[i];
		for(j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[],int n)
{
	int i, gap;
	for(gap = n / 2; gap > 0; gap = gap / 2)
	{
		if((gap % 2) == 0)
			gap++;
		for(i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

void sort_int(int list[],int n, int number)
{
	clock_t start,finish;
	double duration;
	start=clock();
	if(number==1) selection_sort(list,n);
	else if(number==2)insertion_sort(list, n);
	else if(number==3) bubble_sort(list,n);
	else shell_sort(list,n);
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("the duration=%f\n",duration);
}

void main()
{
	int i;
	int list[MAX_SIZE];
	int n=MAX_SIZE;
	while(1)
	{
		for(i=0;i<n;i++)
			list[i]=rand();
		/*
		selection_sort(list,n);
		for(i=0;i<n;i++)
		printf("%d ",list[i]);
		printf("\n");

		for(i=0;i<n;i++)
		list[i]=rand()%100;
		insertion_sort(list,n);
		for(i=0;i<n;i++)
		printf("%d ",list[i]);
		printf("\n");

		*/

		int number = 0;
		printf("select the method\n");
		printf("1-selection, 2-insertion,3-bubble, 4-shell\n");
		scanf("%d",&number);

		sort_int(list,n,number);	
	}

}

