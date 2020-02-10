#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node(int val)
	{
		this->value = val;
		this->next = NULL;
	}
};

class myList
{
private:
	int size = 0;
	Node* head;
	Node* tail;
public:
	myList()
	{
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}
	int getSize()
	{
		return this->size;
	}
	void pushBack(int val)
	{
		if (this->size == 0)
		{
			Node* newNode = new Node(val);
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			Node* newNode = new Node(val);
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->size++;
	}
	void pushFront(int val)
	{
		if (this->size == 0)
		{
			Node* newNode = new Node(val);
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			Node* newNode = new Node(val);
			newNode->next = head;
			this->head = newNode;
		}
		this->size++;
	}
	void pushAt(int val, int pos)
	{
		if (pos > size || pos < 0)
		{
			return;
		}
		int cnt = 0;
		Node* curr = this->head;
		Node* prev = curr;
		while (cnt < pos - 1)
		{
			curr = curr->next;
			cnt++;
		}
		Node* newNode = new Node(val);
		Node* nextToNewNode = curr->next;
		newNode->next = nextToNewNode;
		curr->next = newNode;
		this->size++;
	}
	void print()
	{
		Node* curr = this->head;
		while (curr != NULL)
		{
			cout << curr->value << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	void popFront()
	{
		if (this->size <= 1)
		{
			this->tail = NULL;
			this->head = NULL;
			this->size = 0;
		}
		if (this->size > 1)
		{
			Node* toDel = this->head;
			this->head = this->head->next;
			delete toDel;
			this->size--;
		}
	}
	void popBack()
	{
		if (this->size <= 1)
		{
			this->tail = NULL;
			this->head = NULL;
			this->size = 0;
		}
		else if (this->size > 1)
		{
			Node* curr = this->head;
			while (curr->next->next != NULL)
			{
				curr = curr->next;
			}
			this->tail = curr;
			curr->next = NULL;
			this->size--;
		}
	}
	void removeAt(int pos)
	{
		int cnt = 0;
		if (pos == 0)
		{
			this->popFront();
			return;
		}
		if (pos == this->size - 1)
		{
			this->popBack();
			return;
		}
		Node*  curr = this->head;
		if (pos > size || pos < 0)
		{
			return;
		}
		while (cnt < pos - 1)
		{
			curr = curr->next;
			cnt++;
		}
		this->size--;
		curr->next = curr->next->next;
	}
	void removeComplex(int num)
	{
		int pos = 0;
		Node* curr = this->head;
		while (curr != NULL)
		{
			Node* nextOne = curr->next;
			if (curr->value % num == 0)
			{
				removeAt(pos);
				pos--;
			}
			curr = nextOne;
			pos++;
		}
	}
	void reverse()
	{
		Node* nextOne = NULL;
		Node* prevOne = NULL;
		Node* curr = this->head;
		this->tail = curr;
		while (curr != NULL)
		{
			nextOne = curr->next;
			curr->next = prevOne;
			prevOne = curr;
			curr = nextOne;
		}
		this->head = prevOne;
	}
};

int main()
{
	myList* l = new myList();

	int n;
	cin >> n;
	int number;
	for (int i = 0; i < n; i++) {
		cin >> number;
		l->pushBack(number);
	}
	l->print();
	l->reverse();
	l->print();
	l->popFront();
	l->popBack();
	l->print();

	int x;
	cin >> x;
	return 0;
}
