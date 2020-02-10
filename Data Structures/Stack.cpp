#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next = nullptr;
	Node(int val)
	{
		this->value = val;
	}
};
class Stack
{
private:
	int size = 0;
	Node* head = nullptr;
public:
	Stack()
	{

	}
	void push(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = this->head;
		size++;
		this->head = newNode;
	}
	int top()
	{
		return this->head->value;
	}
	void pop()
	{
		Node* curr = this->head;
		this->head = curr->next;
		delete curr;
	}
};

int main()
{
	Stack stack;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		stack.push(a);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
	int x;
	cin >> x;
	return 0;
}
