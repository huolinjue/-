#include "insert.h"


/**
*��������
ʱ�临�Ӷȣ�
	1.ƽ�������O(n^2)
	2.��������O(n)
	3.������O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�

ֱ�Ӳ�������ԭ�����£��ӵ�һ��Ԫ�ؿ�ʼ,��Ԫ���Ѿ��ź���,����ȡԪ�����ź����Ԫ�����ν��бȽ�,
����Ļ����뵽��ǰһ����Ⱥ�һ��С��λ��,Ȼ���ظ���������,ֱ������Ԫ��Ϊֹ.
*/
void insert_sort(int arr[], int n)
{
	int current = 0;
	int i, j;
	for (i = 1; i < n; i++)
	{
		current = arr[i];
		j = i - 1;
		while (j >= 0 && current < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
	}
}

void insert_sort_sencond(int arr[],int n)
{
	int left = 0;
	int right = n - 1;
	int mid = 0;
	int i = 0;
	int key = 0;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		left = 0;
		right = i - 1;
		//���ַ����Ҵ�����Ԫ�ص�λ��
		while (left <= right)
		{
			mid = (left + right) >> 1;//�൱�ڳ���2
			if (key < arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		//����left�Ժ�λ�õ�Ԫ��
		right = i - 1;
		while (right >= left)
		{
			arr[right + 1] = arr[right];
			right--;
		}
		//����Ԫ��
		arr[left] = key;
	}
}