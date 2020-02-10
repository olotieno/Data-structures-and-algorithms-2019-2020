#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
	vector<int> arr;
	int size = 0;

	int parent(int index)
	{
		return (index - 1) / 2;
	}
	int leftChild(int index)
	{
		return index * 2 + 1;
	}
	int rightChild(int index)
	{
		return index * 2 + 2;
	}
	bool hasLeftChild(int index)
	{
		return leftChild(index) < size;
	}
	bool hasRightChild(int index)
	{
		return rightChild(index) < size;
	}

	void pullUp(int index)
	{
		while (arr[index] > arr[parent(index)] && index > 0)
		{
			swap(arr[index], arr[parent(index)]);
			index = parent(index);
		}
	}
	void heapify(int index)
	{
		while (index < size)
		{
			int maxChild = leftChild(index);
			if (hasRightChild(index) && arr[rightChild(index)] > arr[maxChild])
			{
				maxChild = rightChild(index);
			}
			if (hasLeftChild(index) && arr[index] < arr[maxChild])
			{
				swap(arr[index], arr[maxChild]);
				index = maxChild;
			}
			else
			{
				break;
			}
		}
	}

public:
	Heap()
	{
		this->size = 0;
	}
	void insert(int value)
	{
		if (size == 0)
		{
			arr.push_back(value);
			size++;
		}
		else
		{
			arr.push_back(value);
			pullUp(size);
			size++;
		}
	}
	void extractMax()
	{
		swap(arr[0], arr[size - 1]);
		size--;
		heapify(0);
	}
	int getMax()
	{
		return arr[0];
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
};

int main()
{
	Heap* heap = new Heap();
	heap->insert(10);
	heap->insert(11);
	heap->insert(7);
	heap->insert(8);
	heap->insert(5);
	heap->insert(4);
	heap->insert(3);
	cout << heap->getMax() << "\n";
	heap->extractMax();
	heap->print();


	int x;
	cin >> x;
	return 0;
}
