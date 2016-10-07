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
	//k-max-heap(�ڽ��� k���� ���� k-nary tree�� �̿��� heap))�� �ǵ��� �ڷḦ �Է�
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[(i + k - 2) / k].key))
	{
		h->heap[i] = h->heap[(i + k - 2) / k];
		i = (i + k - 2) / k;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
int max(element heap[], int start, int number)
{
	//heap�� start���� number �� ��ŭ�� ���� �� ���� key�� ū ������ index�� ��ȯ�ϴ�.
	int temp = 0;
	for (int i = 0; i < number; i++)
		temp = (heap[start + i].key > temp) ? heap[start + i].key : temp;
	return temp;
}
element delete_max_heap(HeapType *h, int k)
{
	//k-max-heap���� ���� key�� ū ���Ҹ� ��ȯ�Ѵ�. ��ȯ �� k-max-heap�� �����Ѵ�. ���� max�Լ��� �̿�
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		// ���� ����� �ڽĳ���� �� ū �ڽĳ�带 ã�´�.
		for (int i = 0; i < k; i++)
			if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
				child++;
		if (temp.key >= h->heap[child].key)
			break;

		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * k - (k - 2);
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n, int k)
{ //k-max-heap�� �̿��Ͽ� �����Ѵ�.
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
	//������ 10�̻��� ���� ���� ���� ������ �迭�� ���� heap_sort�� �̿��Ͽ� 
	//�����Ͻÿ�. k���� ���� ���� ���� �ؼ� test�� ���ÿ�.
	element e[13] = { { 10 },{ 40 },{ 30 },{ 5 },{ 12 },{ 6 },{ 15 },{ 9 },{ 60 },{ 99 },{ 75 },{ 89 },{ 48 } };
	HeapType heap;	// ���� ����
	init(&heap);		// �ʱ�ȭ
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