#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZES 20

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	int *sorted=(int*)malloc(sizeof(int)*(right+1));

	/* 분할 정렬된 list의 합병 */
   while(i<=mid && j<=right){
     if(list[i]<=list[j])
	    sorted[k++] = list[i++];
	 else
	    sorted[k++] = list[j++];
   }
   if(i>mid)	/* 남아 있는 레코드의 일괄 복사 */
	  for(l=j; l<=right; l++)
  	     sorted[k++] = list[l];
   else	/* 남아 있는 레코드의 일괄 복사 */
	  for(l=i; l<=mid; l++)
 	     sorted[k++] = list[l];
   /* 배열 sorted[]의 리스트를 배열 list[]로 재복사 */
   for(l=left; l<=right; l++)
      list[l] = sorted[l];

  // delete []sorted;
   free(sorted);
}
void merge_sort(int list[], int left, int right)
{  
   int mid;
   if(left<right){
      mid = (left+right)/2;     /* 리스트의 균등 분할 */
      merge_sort(list, left, mid);    /* 부분 리스트 정렬 */
      merge_sort(list, mid+1, right); /* 부분 리스트 정렬 */
	  merge(list, left, mid, right);    /* 합병 */
   }
}

void main()
{
	int list[10]={6,56,3,2,47,4,5,12,23,10};
//	int list[MAX_SIZES];

 int	n=10;
 int i;
	/*
	int n=MAX_SIZES;
	int i;
	for( i=0;i<n;i++)
		list[i]=rand()%n;
*/
	clock_t start,finish;
	double duration;
	start=clock();
	merge_sort(list,0,n-1);
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("duration=%f\n ",duration);

	printf("after sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",list[i]);
	printf("\n");
	
}