#include "quick.h"
#include "common.h"
#include "stdio.h"


/**
*快速排序
时间复杂度：
	1.平均情况：O(nlgn)
	2.最好情况：O(n)
	3.最坏情况：O(n^2)
空间复杂度：O(1)
稳定性：不稳定

快速排序原理如下：任取待排序中的某一元素作为基准值（一般取最左边的第一个元素为基准值）,按照该基准值,
将待排序集合分割成两个子序列,左边的序列比基准值小,右边的比基准值大.然后对左右子序列重复上述步骤.直到排完为止
*/



/*
挖坑填法，以第一个元素为基准值，从右往左走，找到比他小的然后填到第一个坑里面，然后再从左往右走，找到比基准值大的
填到上一个坑里，以此类推
*/
int AdjustArray(int arr[], int l, int r)
{
	int i = l;
	int j = r;
	int x = arr[l];
	//从右向左找到小于x的数来填s[i]
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
交换法，选第一个为快排的基准数，然后从最右边j往左走找比这个基准小的(j--)，i最左边往右走选择比这个基准大的(i++)，
然后两个交换，直到i和j相遇（i=j），然后再对比数组第i(j)个元素与基准的大小，因为每次都是从j开始移动，那么最后相
遇的时候的值一定比基准小，所以和基准交换
参考博文：https://blog.csdn.net/vayne_xiao/article/details/53508973?depth_1-utm_source=distribute.pc_relevant_right.none-task&utm_source=distribute.pc_relevant_right.none-task
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