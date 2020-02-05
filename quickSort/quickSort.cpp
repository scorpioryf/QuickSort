// quickSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int  input(int *arr) {
	int temp;
	int cnt = 0;
	while (cin >> temp)
	{
		arr[cnt++] = temp;
	}
	return cnt;
}


int getIndex(int low, int high, int *arr) {
	int temp = arr[low];
	while (low<high)
	{
		while (low<high && arr[high] > temp) {
			high--;
		}
		arr[low] = arr[high];
		while (low<high && arr[low] < temp)
		{
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = temp;
	
	return low;
}

void quickSort(int low, int high, int * arr) {
	if (low < high) {
		int key = getIndex(low, high, arr);
		int llow, lhigh, rlow, rhigh;
		lhigh = key - 1;
		llow = low;

		rlow = key + 1;
		rhigh = high;

		quickSort(llow, lhigh, arr);
		quickSort(rlow, rhigh, arr);
	}
}

void printArr(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[100];

	int size = input(arr);

	int low = 0;
	int high = size - 1;
	
	quickSort(low, high, arr);

	printArr(arr, size);
    
	system("PAUSE");
}

