#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define K_NARY 3

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}

//left_child of i=i*k-(k-2)
//parent index of l=(l+k-2)/k

void insert_max_heap(HeapType *h, element item, int k)
{
	//k-max-heap(자식이 k개인 완전 k-nary tree를 이용한 heap))이 되도록 자료를 입력
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[(i + k - 2) / k].key))
	{
		h->heap[i] = h->heap[(i + k - 2) / k];
		i = (i + k - 2) / k;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
int max(element heap[], int start, int number)
{
	//heap의 start에서 number 개 만큼의 원소 중 가장 key가 큰 원소의 index를 반환하다.
	int temp = 0;
	for (int i = 0; i < number; i++)
		temp = (heap[start + i].key > temp) ? heap[start + i].key : temp;
	return temp;
}
element delete_max_heap(HeapType *h, int k)
{
	//k-max-heap에서 가장 key가 큰 원소를 반환한다. 반환 후 k-max-heap을 유지한다. 위의 max함수를 이용
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		// 현재 노드의 자식노드중 더 큰 자식노드를 찾는다.
		for (int i = 0; i < k; i++)
			if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
				child++;
		if (temp.key >= h->heap[child].key)
			break;

		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * k - (k - 2);
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n, int k)
{ //k-max-heap을 이용하여 정렬한다.
	int i;
	HeapType h;
	init(&h);
	for (i = 0; i < n; i++) 
		insert_max_heap(&h, a[i], k);
	for (i = n - 1; i >= 0; i--) 
		a[i] = delete_max_heap(&h, k);
}
void print_heap(HeapType *h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("< %d > ", h->heap[i].key);
	printf("\n");
}

void main()
{
	//사이즈 10이상인 정렬 되지 않은 정수형 배열을 위의 heap_sort를 이용하여 
	//정렬하시오. k값을 여러 가지 경우로 해서 test해 보시오.
	element e[13] = { { 10 },{ 40 },{ 30 },{ 5 },{ 12 },{ 6 },{ 15 },{ 9 },{ 60 },{ 99 },{ 75 },{ 89 },{ 48 } };
	HeapType heap;	// 히프 생성
	init(&heap);		// 초기화
	for (int i = 0; i < 13; i++)
		insert_max_heap(&heap, e[i], K_NARY);
	print_heap(&heap);
	printf("\n");

	delete_max_heap(&heap, K_NARY);
	print_heap(&heap);
	printf("\n");

	printf("%d\n", max(e, 3, 6));
	printf("\n");

	heap_sort(e, 13, K_NARY);
	for (int i = 0; i < 13; i++)
		printf("< %d > ", e[i].key);
	printf("\n");
	printf("\n");

	printf("%d\n", max(e, 3, 6));
	printf("\n");
}