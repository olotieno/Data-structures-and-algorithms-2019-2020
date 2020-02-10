#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int from, to, weight;
	Edge(int from, int to, int weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}
	bool operator<(const Edge& other) const 
	{
		return this->weight < other.weight;
	}
};
int depth[1000];
int parents[1000];
int edgesUsed = 0;
vector<Edge> edges;

void init()
{
	for (int i = 0; i < 1000; i++)
	{
		depth[i] = 1;
		parents[i] = i;
	}
}

int find(int curr)
{
	if (curr == parents[curr])
	{
		return curr;
	}
	return parents[curr] = find(parents[curr]);
}

int Union(Edge e)
{
	int r1 = find(e.from);
	int r2 = find(e.to);
	if (r1 == r2)
	{
		return 0;
	}
	else
	{
		if (depth[r1] < depth[r2])
		{
			swap(r1, r2);
		}
		parents[r2] = r1;
		if (depth[r2] == depth[r1])
		{
			depth[r1]++;
		}
		edgesUsed++;
		return e.weight;
	}
}

int main()
{
	int ans = 0;
	int n, m;
	cin >> n >> m;
	int from, to, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> from >> to >> w;
		edges.push_back({ from - 1, to - 1, w });
	}
	init();
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); ++i)
	{
		ans += Union(edges[i]);

	}
	if (edgesUsed == n - 1)
		cout << ans << endl;
	else
		cout << -1 << endl;

}