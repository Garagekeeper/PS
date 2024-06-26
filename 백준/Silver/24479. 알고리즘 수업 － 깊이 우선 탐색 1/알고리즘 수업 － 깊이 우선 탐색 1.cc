#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;

void dfs(int R);

vector<vector<int>> G;
vector<bool> visited;
int res[100001] = { 0, };
int cnt = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> R;

	visited.resize(N+1, false);
	G.resize(N+1);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 0; i < G.size(); i++)
	{
		sort(G[i].begin(), G[i].end());
	}

	dfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << res[i] << "\n";
	}
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