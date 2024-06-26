/*
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;

void dfs(int R);
void bfs(int R);

vector<vector<int>> G;
vector<bool> visited;
int res[100001] = { 0, };
int cnt = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	R = 1;

	visited.resize(N + 1, false);
	G.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(R);

	int infested=0;
	for (int i = 2; i <= N; i++)
	{
		if (visited[i]) infested++;
	}

	cout << infested;
	return 0;
}


void dfs(int R)
{
	if (visited[R])
		return;
	visited[R] = true;
	cnt++;
	res[R] = cnt;

	for (int i : G[R])
	{
		dfs(i);
	}
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