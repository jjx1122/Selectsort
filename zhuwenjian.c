#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
//顺序表
typedef struct list{
	int* arr;
	int size;//顺序表长度
}List;
int Init(List *L) {
	L->arr = (int*)malloc(MaxSize * sizeof(int));
	if (!L->arr)
		return 0;
	//else printf("1");
	L->size = 0;
	return 1;
}
void display(List* L,int k) {
	for (int i = 0; i < k; i++) {
		printf("%d ", L->arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//选择排序
void selectSort(List* L) {
	int i;
	int j;
	int small;//最小的下标
	for (i = 0; i < L->size; i++) {
		small = i;
		for (j = i + 1; j < L->size; j++) {
			if (L->arr[j] < L->arr[small])
				small = j;
		}
		swap(&L->arr[i], &L->arr[small]);
	}
}
int main() {
	/*do
	{
		scanf("%d", &n);
		a[i++] = n;
	} while (getchar()!='\n');*/
	List* L = new List;
	Init(L);//初始化
	int i = 0;
	int n;
	int k;
	do
	{
		scanf("%d", &n);
		L->arr[i] = n;
		i++;
		L->size++;
	} while (getchar()!='\n');
	display(L,L->size);
	selectSort(L);
	printf("输入要显示前k个整数\n");
	scanf("%d", &k);
	display(L,k);
	return 0;
}
