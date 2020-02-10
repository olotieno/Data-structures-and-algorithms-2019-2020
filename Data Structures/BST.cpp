#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int value;
	Node* leftChild;
	Node* rightChild;
	Node(int val)
	{
		this->value = val;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
};

class BST
{
private:
	Node* root;
	int size = 0;

	Node* findMax(Node* curr)
	{
		while (curr->rightChild != NULL)
		{
			curr = curr->rightChild;
		}
		return curr;
	}
	Node* _insert(Node* curr, int val)
	{
		if (curr == NULL)
		{
			this->size++;
			return new Node(val);
		}
		else if (curr->value < val)
		{
			curr->rightChild = _insert(curr->rightChild, val);
		}
		else if (curr->value > val)
		{
			curr->leftChild = _insert(curr->leftChild, val);
		}

		return curr;
	}
	Node* _remove(Node* curr, int val)
	{
		if (curr == NULL)
		{
			return NULL;
		}
		if (curr->value > val)
		{
			curr->leftChild = _remove(curr->leftChild, val);
		}
		else if (curr->value < val)
		{
			curr->rightChild = _remove(curr->rightChild, val);
		}
		else
		{
			if (curr->leftChild == NULL)
			{
				Node* tmp = curr->rightChild;
				delete curr;
				return tmp;
			}
			else
			{
				Node* tmp = findMax(curr->leftChild);
				curr->value = tmp->value;
				curr->leftChild = _remove(curr->leftChild, curr->value);
				return curr;
			}
		}
		return curr;
	}
	void inorder(Node* curr)
	{
		if (curr == NULL)
		{
			return;
		}
		inorder(curr->leftChild);
		cout << curr->value << " ";
		inorder(curr->rightChild);
	}
	void preorder(Node* curr)
	{
		if (curr == NULL)
		{
			return;
		}
		cout << curr->value << " ";
		preorder(curr->leftChild);
		preorder(curr->rightChild);
	}
	void postOrder(Node* curr)
	{
		if (curr == NULL)
		{
			return;
		}
		postOrder(curr->rightChild);
		postOrder(curr->leftChild);
		cout << curr->value << " ";
	}

public:
	BST()
	{
		this->root = NULL;
	}
	void insert(int val)
	{
		Node* newNode = new Node(val);
		if (size == 0)
		{
			this->size++;
			this->root = newNode;
		}
		else
		{
			_insert(root, val);
		}
	}
	void remove(int val)
	{
		if (this->size == 1 && this->root->value == val)
		{
			Node* oldRoot = this->root;
			this->root = NULL;
			delete oldRoot;
		}
		else
		{
			_remove(root, val);
		}
	}
	void inorderPrint()
	{
		inorder(this->root);
		cout << endl;
	}
	void printByLayers()
	{
		queue<Node*> nextToPrint;
		nextToPrint.push(this->root);
		while (!nextToPrint.empty())
		{
			Node* curr = nextToPrint.front();
			cout << curr->value << " ";
			nextToPrint.pop();
			if (curr->leftChild != NULL)
			{
				nextToPrint.push(curr->leftChild);
			}
			if (curr->rightChild != NULL)
			{
				nextToPrint.push(curr->rightChild);
			}
		}
		cout << "\n";
	}
	void preorderPrint() // root-left-right
	{
		preorder(this->root);
		cout << endl;
	}
	void postorderPrint() //righ-left-root
	{
		postOrder(this->root);
		cout << endl;
	}
};


int main()
{
	//5
	//6 4 2 5 3
	BST* bst = new BST();
	bst->insert(10);
	bst->insert(15);
	bst->insert(13);
	bst->insert(12);
	bst->insert(14);
	bst->insert(7);
	bst->insert(9);
	bst->insert(6);
	bst->insert(4);
	bst->inorderPrint();
	bst->remove(10);
	bst->inorderPrint();

	int x;
	cin >> x;
	return 0;
}
