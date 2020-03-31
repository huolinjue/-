#include "quick.h"
#include "common.h"
#include "stdio.h"


/**
*��������
ʱ�临�Ӷȣ�
	1.ƽ�������O(nlgn)
	2.��������O(n)
	3.������O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�

��������ԭ�����£���ȡ�������е�ĳһԪ����Ϊ��׼ֵ��һ��ȡ����ߵĵ�һ��Ԫ��Ϊ��׼ֵ��,���ոû�׼ֵ,
�������򼯺Ϸָ������������,��ߵ����бȻ�׼ֵС,�ұߵıȻ�׼ֵ��.Ȼ��������������ظ���������.ֱ������Ϊֹ
*/



/*
�ڿ�����Ե�һ��Ԫ��Ϊ��׼ֵ�����������ߣ��ҵ�����С��Ȼ�����һ�������棬Ȼ���ٴ��������ߣ��ҵ��Ȼ�׼ֵ���
���һ������Դ�����
*/
int AdjustArray(int arr[], int l, int r)
{
	int i = l;
	int j = r;
	int x = arr[l];
	//���������ҵ�С��x��������s[i]
	while (i < j)
	{
		while (i < j && arr[j] >= x)
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] <= x)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = x;
	return i;
}


void quick_sort1(int arr[], int l,int r)
{
	if (l < r)
	{
		int i = AdjustArray(arr, l, r);
		quick_sort1(arr, l, i - 1);
		quick_sort1(arr, i + 1, r);
	}
}

/*
��������ѡ��һ��Ϊ���ŵĻ�׼����Ȼ������ұ�j�������ұ������׼С��(j--)��i�����������ѡ��������׼���(i++)��
Ȼ������������ֱ��i��j������i=j����Ȼ���ٶԱ������i(j)��Ԫ�����׼�Ĵ�С����Ϊÿ�ζ��Ǵ�j��ʼ�ƶ�����ô�����
����ʱ���ֵһ���Ȼ�׼С�����Ժͻ�׼����
�ο����ģ�https://blog.csdn.net/vayne_xiao/article/details/53508973?depth_1-utm_source=distribute.pc_relevant_right.none-task&utm_source=distribute.pc_relevant_right.none-task
*/
void quick_sort2(int arr[], int l, int r)
{
	int i = l, j = r;
	int x = arr[l];
	if (i > j)
		return ;
	while (i < j)
	{
		while (arr[j] >= x && i < j)
			j--;
		while (arr[i] <= x && i < j)
			i++;
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[l], &arr[i]);
	quick_sort2(arr, l, i - 1);
	quick_sort2(arr, i + 1, r);
}