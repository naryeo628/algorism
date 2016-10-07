#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 200

typedef struct
{
	char key[20];
	int id;
}element;
typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}
void insert_max_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (strcmp((item.key), h->heap[i / 2].key) == 1))	//strcmp�Լ� ���� ũ�� 1 �ڰ� ũ�� -1 ������ 0
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (strcmp((item.key), h->heap[i / 2].key) == -1))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		// ���� ����� �ڽĳ���� �� ū �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (strcmp(h->heap[child].key, h->heap[child + 1].key) == -1))
			child++;
		if (strcmp(temp.key, h->heap[child].key) >= 0) //if (temp.key >= h->heap[child].key)
			break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (strcmp(h->heap[child].key, h->heap[child + 1].key) == 1))
			child++;
		if (strcmp(temp.key, h->heap[child].key) <= 0)
			break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void print_heap(HeapType *heap)
{
	for (int i = 1; i <= heap->heap_size; i++)
		printf("<\"%s\",%d> ", heap->heap[i].key, heap->heap[i].id);
	printf("\n");
}
void sort_heap(element a[], int n)
{
	int i;
	HeapType h;
	init(&h);
	for (i = n - 1; i >= 0; i--)
		insert_min_heap(&h, a[i]);
	for (i = 0; i < n; i++)
		a[i] = delete_min_heap(&h);
}

void main()
{
	element e[3] = { { "aegg", 1234 }, { "bstructure", 321 }, { "cepic", 4885 } };
	HeapType heap;	// ���� ����
	init(&heap);		// �ʱ�ȭ
	insert_max_heap(&heap, e[0]);
	print_heap(&heap);
	insert_max_heap(&heap, e[1]);
	print_heap(&heap);
	insert_max_heap(&heap, e[2]);
	print_heap(&heap);
	printf("\n");

	sort_heap(e, 3);
	for (int i = 0; i < 3; i++)
		printf("<\"%s\",%d> ", e[i].key, e[i].id);
	printf("\n");


}