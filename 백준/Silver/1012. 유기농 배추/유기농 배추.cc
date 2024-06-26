#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 50

int map[MAX][MAX];
int move_vector[4][2] = {
	{0,1}, //Right
	{0,-1},//Left
	{-1,0},//Up
	{1,0}, //Down
};

vector<int> res;

int T, N, M, K;

//void dfs(int R);
void bfs(int x, int y);

vector<vector<int>> G;
bool visited[MAX][MAX] = { false, };
int cnt = 0;

int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			map[X][Y] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == false)
				{
					bfs(i, j);
				}
			}
		}

		for (int i = 0; i < M; i++)
		{
			memset(map, 0, sizeof(map));
			memset(visited, 0, sizeof(visited));
		}

		cout << cnt << "\n";

		cnt = 0;
	}

	return 0;
}

void bfs(int x, int y)
{

	queue<pair<int, int>> Q;
	if (visited[x][y]) return;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int mx = x + move_vector[i][0];
		int my = y + move_vector[i][1];

		if (mx < 0 || my < 0) continue;
		if (mx >= M || my >= N) continue;
		if (visited[mx][my]) continue;
		if (map[mx][my] != 1) continue;

		Q.push(make_pair(mx, my));
		visited[mx][my] = true;
	}


	while (!Q.empty())
	{
		int qx = Q.front().first;
		int qy = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int mx = qx + move_vector[i][0];
			int my = qy + move_vector[i][1];

			if (mx < 0 || my < 0) continue;
			if (mx >= M || my >= N) continue;
			if (visited[mx][my]) continue;
			if (map[mx][my] != 1) continue;
			visited[mx][my] = true;
			Q.push(make_pair(mx, my));
		}
	}
	cnt++;
}