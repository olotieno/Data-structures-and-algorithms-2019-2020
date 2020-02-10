#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	list<int> neighbours;

	void addNeighbour(int to)
	{
		neighbours.push_back(to);
	}
};

class Graph
{
private:
	vector<Node> nodes;
	void _topologicalSort(int curr, vector<char>& visited, list<int>& result)
	{
		visited[curr] = 'o';
		for (auto i : nodes[curr].neighbours)
		{
			if (visited[i] == 'u')
			{
				visited[i] = 'o';
				_topologicalSort(i, visited, result);
			}
			else if (visited[i] == 'o')
			{
				cout << "cycle between " << i << " and " << curr << endl;
			}
		}
		visited[curr] = 'c';
		result.push_back(curr);
	}
public:
	Graph(int size)
	{
		nodes.resize(size);
	}
	void connect(int from, int to)
	{
		nodes[from].addNeighbour(to);
	}
	list<int> topologicalSort()
	{
		vector<char> visited;
		visited.resize(nodes.size(), 'u');
		list <int> sorted;
		for (int i = 0; i < nodes.size(); i++)
		{
			if (visited[i] == 'u')
			{
				_topologicalSort(i, visited, sorted);
			}
		}
		return sorted;
	}
};

int main()
{
	Graph g(5);
	g.connect(4, 3);
	g.connect(4, 2);
	g.connect(1, 3);
	g.connect(2, 0);
	list<int> res = g.topologicalSort();
	for (auto i : res)
	{
		cout << i << " ";
	}
	int x;
	cin >> x;
	return 0;
}
