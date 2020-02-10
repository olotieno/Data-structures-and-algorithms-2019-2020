#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next = NULL;
	Node(int val)
	{
		this->value = val;
	}
};

class Queue
{
private:
	int size = 0;
	Node* head = NULL;
	Node* tail = NULL;
public:
	Queue()
	{

	}
	void push(int val)
	{
		if (size == 0)
		{
			this->head = this->tail = new Node(val);
		}
		else
		{
			Node* curr = new Node(val);
			this->tail->next = curr;
			this->tail = curr;
		}
		this->size++;
	}
	void pop()
	{
		if (size = 0)
		{
			return;
		}
		if (size == 1)
		{
			this->size = 0;
			this->head = this->tail = NULL;
		}
		else
		{
			Node* old = this->head;
			this->head = this->head->next;
			delete old;
			this->size--;
		}
	}
	int top()
	{
		return this->head->value;
	}
	bool isEmpty()
	{
		return this->size == 0;
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
};

int main()
{
	Queue* q = new Queue();
	q->push(10);
	q->pop();
	q->push(10);
	q->push(11);
	q->push(12);
	q->push(13);
	q->push(14);
	q->push(15);
	cout << q->top() << "\n";
	q->print();
	q->pop();
	cout << q->top() << "\n";
	q->print();
	int x;
	cin >> x;
	return 0;
}