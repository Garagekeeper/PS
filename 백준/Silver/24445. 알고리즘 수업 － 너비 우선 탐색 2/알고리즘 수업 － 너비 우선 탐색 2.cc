#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;

void bfs(int R);

vector<vector<int>> G;
vector<bool> visited;
int res[100001] = { 0, };
int cnt = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> R;

	visited.resize(N + 1, false);
	G.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 0; i < G.size(); i++)
	{
		sort(G[i].begin(), G[i].end(),greater<int>());
	}

	bfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << res[i] << "\n";
	}
	return 0;
}

void bfs(int R)
{
	queue<int> Q;

	visited[R] = true;
	res[R] = cnt++;

	for (int i : G[R])
	{
		Q.push(i);
		visited[i] = true;
		res[i] = cnt++;
	}

	while (!Q.empty())
	{
		int temp = Q.front();
		Q.pop();

		for (int i : G[temp])
		{
			if (visited[i]) continue;
			visited[i] = true;
			res[i] = cnt++;
			Q.push(i);

		}
	}
}
