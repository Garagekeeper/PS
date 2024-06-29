#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <string.h>
#include <tuple>

using namespace std;
#define MAX 100
int M, N, H;
int curx, cury;
int destx, desty;

int map[MAX][MAX][MAX] = { 0, };
bool visited[MAX][MAX][MAX] = { 0, };

struct Pos
{
	int z;
	int x;
	int y;
};

queue<Pos> q;
void GetInput()
{
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int temp;
				cin >> temp;
				map[i][j][k] = temp;
				if (temp == 1)
				{
					visited[i][j][k] = true;
					q.push({ i,j,k });
				}
			}
		}
	}
}

bool CanGo(int z, int x, int y)
{
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= M) return false;
	if (z < 0 || z >= H) return false;
	if (map[z][x][y] == -1) return false;
	if (visited[z][x][y]) return false;
	return true;
}

void BFS()
{
	int dx[6] = { 0, 1, 0,-1, 0, 0 };
	int dy[6] = { 1, 0,-1, 0, 0, 0 };
	int dz[6] = { 0, 0, 0, 0 ,1 ,-1 };

	while (!q.empty())
	{
		int frtX = q.front().x;
		int frtY = q.front().y;
		int frtZ = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = frtX + dx[i];
			int ny = frtY + dy[i];
			int nz = frtZ + dz[i];

			if (CanGo(nz, nx, ny))
			{
				visited[nz][nx][ny] = true;
				map[nz][nx][ny] = map[frtZ][frtX][frtY] + 1;

				q.push({ nz,nx,ny });
			}
		}
	}

}

void PrintAns()
{
	int cnt = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (map[i][j][k] == 0)
				{
					printf("-1\n");
					return;
				}
				cnt = max(cnt, map[i][j][k]);
			}
		}
	}
	printf("%d", cnt - 1);
}

int main()
{
	GetInput();
	BFS();
	PrintAns();

	return 0;
}
