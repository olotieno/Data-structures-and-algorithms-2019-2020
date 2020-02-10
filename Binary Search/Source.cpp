#include <iostream>
using namespace std;

int binarySearchFirstOccurance(int* arr, int start, int end, int x)
{
	int result = -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (x == arr[mid])
		{
			result = mid;
			end = mid - 1;
		}
		else if (x > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return result;
}

int binarySearchLastOccurance(int* arr, int start, int end, int x)
{
	int result = -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (x == arr[mid])
		{
			result = mid;
			start = mid + 1;
		}
		else if (x > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return result;
}

bool binary(int* arr, int start, int end, int x)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == x)
		{
			return true;
		}
		else if (x > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return false;
}
int main()
{	//Find the first occurrence of x in sorted array with n elements.
	int arr[10] = { 3, 3, 3, 6, 7, 8, 9, 13, 13, 13 };
	cout << binarySearchFirstOccurance(arr, 0, 9, 3) << endl;
	
	//Find the last occurrence of x in sorted array with n elements.
	cout << binarySearchLastOccurance(arr, 0, 9, 13) << endl;
	
	//Find if there are two elements with difference x in an array with n elements
	int x;
	cin >> x;
	bool found = false;
	for (int i = 0; i < 10; i++)
	{
		if (binary(arr, 0, 9, arr[i] + x))
		{
			cout << "yes";
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "no";
	}

	int y;
	cin >> y;
	return 0;
}

