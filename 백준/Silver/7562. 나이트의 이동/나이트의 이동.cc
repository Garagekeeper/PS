#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
#define MAX 300
int T, N;
int curx, cury;
int destx, desty;

int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };

void GetInput()
{
	cin >> N;
	cin >> curx >> cury;
	cin >> destx >> desty;
}

bool CanGo(int x, int y)
{
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	if (visited[x][y]) return false;
	return true;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	visited[x][y] = true;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int frtX = q.front().first;
		int frtY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = frtX + dx[i];
			int ny = frtY + dy[i];

			if (CanGo(nx, ny))
			{
				visited[nx][ny] = true;
				map[nx][ny] = map[frtX][frtY] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

void PrintAns()
{
	cout << map[destx][desty] << "\n";
}

int main()
{
	cin >> T;
	while (T--)
	{
		GetInput();
		BFS(curx, cury);
		PrintAns();

		for (int i = 0; i < N; i++)
		{
			memset(map[i], 0, sizeof(map[i]));
			memset(visited[i], 0, sizeof(visited[i]));
		}
	}

	return 0;
}
