#include "bubble.h"
#include "stdio.h"


/**
*冒泡排序
时间复杂度：
	1.平均情况：O(n^2)
	2.最好情况：O(n)
	3.最坏情况：O(n2)
空间复杂度：O(1)
稳定性：稳定

冒泡排序算法的运作如下：（从后往前）
1)比较相邻的元素。如果第一个比第二个大，就交换他们两个
2)对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
3)针对所有的元素重复以上的步骤，除了最后一个。
*/

void swap(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int arr[], int n)
{
	if (n <= 0)
		return NULL;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				/*
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				*/
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}