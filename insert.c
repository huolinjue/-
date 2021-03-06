#include "insert.h"


/**
*插入排序
时间复杂度：
	1.平均情况：O(n^2)
	2.最好情况：O(n)
	3.最坏情况：O(n^2)
空间复杂度：O(1)
稳定性：稳定

直接插入排序原理如下：从第一个元素开始,该元素已经排好序,继续取元素与排好序的元素依次进行比较,
升序的话插入到比前一个大比后一个小的位置,然后重复上述步骤,直到插完元素为止.
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
		//二分法查找待加入元素的位置
		while (left <= right)
		{
			mid = (left + right) >> 1;//相当于除以2
			if (key < arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		//搬移left以后位置的元素
		right = i - 1;
		while (right >= left)
		{
			arr[right + 1] = arr[right];
			right--;
		}
		//插入元素
		arr[left] = key;
	}
}