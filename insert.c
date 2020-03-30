#include "insert.h"

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