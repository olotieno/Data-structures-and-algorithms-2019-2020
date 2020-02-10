#include <iostream>
using namespace std;


//BIBBLE SORT
void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//INSERTION SORT
void insertionSort(int* arr, int n)
{//5 4 10 8 9
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//SELECTION SORT
void selectionSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}
}

//COUNTING SORT
void countingSort(int* arr, int length)
{
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int* counting = new int[max + 1];
	for (int i = 0; i < max + 1; i++)
	{
		counting[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		counting[arr[i]] ++;
	}
	for (int i = max; i >= 0; i--)
	{
		for (int j = 0; j < counting[i]; j++)
		{
			cout << i << " ";
		}
	}
}

//MERGE SORT
void merge(int* arr, int start, int middle, int end)
{
	int l1 = middle - start + 1;
	int l2 = end - middle;

	int* arr1 = new int[l1];
	int* arr2 = new int[l2];
	for (int i = 0; i < l1; i++)
	{
		arr1[i] = arr[start + i];
	}
	for (int i = 0; i < l2; i++)
	{
		arr2[i] = arr[middle + 1 + i];
	}
	int k = start;
	int i = 0, j = 0;
	while (i < l1 && j < l2)
	{
		if (arr1[i] > arr2[j])
		{
			arr[k] = arr2[j];
			k++;
			j++;
		}
		else
		{
			arr[k] = arr1[i];
			k++;
			i++;
		}
	}
	while (i < l1)
	{
		arr[k] = arr1[i];
		k++;
		i++;
	}
	while (j < l2)
	{
		arr[k] = arr2[j];
		k++;
		j++;
	}
}

void mergeSort(int* arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int middle = (start + end) / 2;
	mergeSort(arr, start, middle);
	mergeSort(arr, middle + 1, end);
	merge(arr, start, middle, end);
}
//QUICK SORT
int partition(int* arr, int start, int end)
{//5 4 10 8 9
	int pivotIndex = start;
	int pivot = arr[end];
	for (int i = start; i < end; i++)
	{
		if (arr[i] < pivot)
		{
			swap(arr[i],arr[pivotIndex]);
			pivotIndex ++;
		}
	}
	swap(arr[end], arr[pivotIndex]);
	return pivotIndex;
}

void quickSort(int* arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pi = partition(arr, start, end);
	quickSort(arr, start, pi - 1);
	quickSort(arr, pi + 1, end);


}

int main()
{
	int arr[] = { 5, 4, 10, 8, 9 };
	insertionSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	int x;
	cin >> x;
	return 0;
}