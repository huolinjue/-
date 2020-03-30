#include "bubble.h"
#include "stdio.h"


/**
*ð������
ʱ�临�Ӷȣ�
	1.ƽ�������O(n^2)
	2.��������O(n)
	3.������O(n2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�

ð�������㷨���������£����Ӻ���ǰ��
1)�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�����������
2)��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ�����һ�㣬����Ԫ��Ӧ�û�����������
3)������е�Ԫ���ظ����ϵĲ��裬�������һ����
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