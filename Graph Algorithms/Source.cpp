#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Pair
{
	int value;
	int distance;
	Pair(int val, int dist)
	{
		this->value = val;
		this->distance = dist;
	}
	bool operator<(const Pair* other) const
	{
		return distance > other->distance;
	}
};

struct Node
{
	list<Pair*> neighbours;

	void addNeighbour(int to, int dist)
	{
		this->neighbours.push_back(new Pair(to, dist));
	}

};

class Graph
{
private:
	vector<Node> nodes;
	
public:
	Graph(int size)
	{
		nodes.resize(size);
	}
	void connect(int from, int to, int weight)
	{
		nodes[from].addNeighbour(to, weight);
	}
	void dijkstra(int start)
	{
		vector<bool> visited;
		visited.resize(nodes.size(), false);
		vector<int> distances;
		distances.resize(nodes.size(), INT_MAX);
		priority_queue<Pair*> nextToProcess;
		distances[start] = 0;
		visited[start] = true;
		nextToProcess.push(new Pair(start, 0));
		while (!nextToProcess.empty())
		{
			Pair* curr = nextToProcess.top();
			nextToProcess.pop();
			int currNode = curr->value;
			int currDist = curr->distance;
			if (visited[currNode])
			{
				continue;
			}
			visited[currNode] = true;
			distances[currNode] = true;

			for (auto i : nodes[currNode].neighbours)
			{
				if (!visited[i->value])
				{
					int distToNeigh = currDist + i->distance;
					if (distToNeigh < distances[i->value])
					{
						distances[i->value] = distToNeigh;
						nextToProcess.push(i);
					}
				}
			}
		}
	}

};

int main()
{

	int x;
	cin >> x;
	return 0;
}