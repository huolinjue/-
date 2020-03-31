#include "shell.h"
#include "stdio.h"
#include "common.h"

/**
*希尔排序
时间复杂度：
	1.平均情况：O(n^1.3)
	2.最好情况：O(n)
	3.最坏情况：O(n^2)
空间复杂度：O(1)
稳定性：不稳定

希尔排序原理如下：把记录按下标的一定增量分组，对每组分别使用直接插入排序；
随着增量逐渐减少，每组包含的关键词越来越多，当增量减少到1时，整个文件
被恰好分为1组，算法便终止
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
//该程序严格按照希尔排序的定义来写
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
		/*该段程序简化希尔排序，以第二次为例，原来每次是1A到1E,从2A到2E，现在可以改成从1B开始，先和1A比较,
		然后2B和2A比较，再取1C与前面自己组内的数据比较。。。,这种每次从数组第gap个元素开始，每个元素与自己组内
		的数据进行直接插入排序显然也是正确的
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
		//更简洁化的实现
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
				swap(&arr[j], &arr[j + gap]);
		}
#endif
		gap = gap / 2;
	}
	
}
