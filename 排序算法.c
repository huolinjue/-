﻿#include <stdio.h>
#include "bubble.h"
#include "insert.h"

int main() {
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int len = (int)sizeof(arr) / sizeof(*arr);
	//bubble_sort(arr, len);
	//insert_sort(arr, len);
	insert_sort_sencond(arr, len);
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return 0;
}