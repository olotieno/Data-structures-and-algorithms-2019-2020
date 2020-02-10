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
	void _BFS(int curr, vector<bool> visited)
	{
		queue<int> nextToProcess;
		nextToProcess.push(curr);
		visited[curr] = true;
		while (!nextToProcess.empty())
		{
			int currNode = nextToProcess.front();
			nextToProcess.pop();
			cout << currNode << " ";
			for (auto i : nodes[currNode].neighbours)
			{
				if (!visited[i])
				{
					nextToProcess.push(i);
					visited[i] = true;
				}
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

	void BFS(int start)
	{
		vector<bool> visited;
		visited.resize(nodes.size());
		_BFS(start, visited);
	}
};

int main()
{
	Graph g(10);
	g.connect(0, 1);
	g.connect(1, 2);
	g.connect(1, 3);
	g.connect(3, 2);
	g.connect(0, 4);
	g.connect(4, 5);
	g.connect(5, 6);
	g.connect(6, 7);
	g.connect(6, 4);
	g.BFS(0);
	int x;
	cin >> x;
	return 0;
}
