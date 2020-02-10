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
	void _DFS(int curr, vector<bool> visited)
	{
		visited[curr] = true;
		cout << curr << " ";
		for (auto i : nodes[curr].neighbours)
		{
			if (!visited[i])
			{
				_DFS(i, visited);
			}
		}
	}
public:
	Graph(int size)
	{
		nodes.resize(size);
	}
	void connect(int from, int to)
	{
		nodes[from].addNeighbour(to);
		nodes[to].addNeighbour(from);
	}

	void DFS(int start)
	{
		vector<bool> visited;
		visited.resize(nodes.size());
		_DFS(start, visited);
	}
};

int main()
{
	Graph g(10);
	g.connect(0, 1);
	g.connect(1, 2);
	g.connect(1, 3);
	g.connect(0, 4);
	g.connect(4, 5);
	g.connect(5, 6);
	g.connect(6, 7);
	g.DFS(0);
	int x;
	cin >> x;
	return 0;
}
