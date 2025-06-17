#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define COLOR_R 1
#define COLOR_B 2

int K, V, E;
vector<vector<int>> graph;
vector<int> visited;

bool BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = COLOR_R;

	while (true)
	{
		if (q.size() == 0)
			break;
		int front = q.front();
		q.pop();

		for (int i = 0; i < graph[front].size(); i++)
		{
			int v = graph[front][i];
			if (visited[v] == 0)
			{
				if (visited[front] == COLOR_R)
				{
					visited[v] = COLOR_B;
					q.push(v);
				}
				else if (visited[front] == COLOR_B)
				{
					visited[v] = COLOR_R;
					q.push(v);
				}
			}
			else if (visited[v] == visited[front])
			{
				return false;
			}
		}
	}
	return true;
}

bool isBipartite()
{
	bool done = false;
	while (true)
	{
		if (done)
			break;

		for (int i = 1; i <= V; i++)
		{
			if (!visited[i])
			{
				bool res = BFS(i);
				if (!res)
					return false;
				else
					i = 0;
			}
			else
			{
				if (i == V)
					done = true;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		graph.assign(V + 1, vector<int>());
		visited.assign(V + 1, 0);

		for (int j = 0; j < E; j++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		cout << (isBipartite() ? "YES" : "NO") << "\n";
	}
}