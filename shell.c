#include "shell.h"
#include "stdio.h"
#include "common.h"

/**
*ϣ������
ʱ�临�Ӷȣ�
	1.ƽ�������O(n^1.3)
	2.��������O(n)
	3.������O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�

ϣ������ԭ�����£��Ѽ�¼���±��һ���������飬��ÿ��ֱ�ʹ��ֱ�Ӳ�������
���������𽥼��٣�ÿ������Ĺؼ���Խ��Խ�࣬���������ٵ�1ʱ�������ļ�
��ǡ�÷�Ϊ1�飬�㷨����ֹ
*/

void shell_sort(int arr[], int n) {
	int i = 0;
	int j;
	int key = 0;
	int end = 0;
	//int gap = 3;
	int temp;
	int gap = n / 2;
	while (gap > 0)
	{

#if 0
//�ó����ϸ���ϣ������Ķ�����д
		for (i = 0; i < gap; i++)
		{
			for (j = gap; j < n; j++)
			{
				if (arr[j] < arr[j - gap])
				{
					int temp = arr[j];
					int k = j - gap;
					while (k >= 0 && arr[k] > temp)
					{
						arr[k + gap] = arr[k];
						k = k - gap;
					}
					arr[k + gap] = temp;
				}
			}
		}
#endif

#if 0
		/*�öγ����ϣ�������Եڶ���Ϊ����ԭ��ÿ����1A��1E,��2A��2E�����ڿ��Ըĳɴ�1B��ʼ���Ⱥ�1A�Ƚ�,
		Ȼ��2B��2A�Ƚϣ���ȡ1C��ǰ���Լ����ڵ����ݱȽϡ�����,����ÿ�δ������gap��Ԫ�ؿ�ʼ��ÿ��Ԫ�����Լ�����
		�����ݽ���ֱ�Ӳ���������ȻҲ����ȷ��
		*/
		for (j = gap; j < n; j++)
		{
			if (arr[j] < arr[j - gap])
			{
				int temp = arr[j];
				int k = j - gap;
				while (k >= 0 && arr[k] > temp)
				{
					arr[k + gap] = arr[k];
					k = k - gap;
				}
				arr[k + gap] = temp;
			}
		}
#endif

#if 1
		//����໯��ʵ��
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
				swap(&arr[j], &arr[j + gap]);
		}
#endif
		gap = gap / 2;
	}
	
}
