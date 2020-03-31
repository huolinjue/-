#include <stdio.h>
#include "bubble.h"
#include "insert.h"
#include "shell.h"
#include "quick.h"

int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int)sizeof(arr) / sizeof(*arr);
	//bubble_sort(arr, len);
	//insert_sort(arr, len);
	//insert_sort_sencond(arr, len);
	//shell_sort(arr, len);
	//quick_sort1(arr, 0, len - 1);
	quick_sort2(arr, 0, len - 1);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}