#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;
#define MAX 101
int N, M;

string map[MAX];
int distanceArr[MAX][MAX] = { 0, };
bool visitedArr[MAX][MAX] = { false, };

enum Dir
{
	RIGHT = 0,
	DOWN,
	LEFT,
	UP
};

void GetInput()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
}

bool CanGo(int x, int y)
{
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= M) return false;
	if (map[x][y] != '1') return false;
	if (visitedArr[x][y]) return false;

	return true;
}

void Bfs(int x, int y)
{
	queue<pair<int, int>> q;
	int dir = Dir::RIGHT;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	visitedArr[x][y] = true;
	distanceArr[x][y] = 1;

	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int frtX = q.front().first;
		int frtY = q.front().second;
		q.pop();



		for (int i = 0; i < 4; i++)
		{
			int nx = frtX + dx[dir];
			int ny = frtY + dy[dir];
			dir = (dir + 1) % 4;

			if (CanGo(nx, ny))
			{
				distanceArr[nx][ny] = distanceArr[frtX][frtY] + 1;
				visitedArr[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}

	}
}

void PrintAns()
{
	cout << distanceArr[N - 1][M - 1];
}

int main()
{
	GetInput();
	Bfs(0, 0);
	PrintAns();

	return 0;
}