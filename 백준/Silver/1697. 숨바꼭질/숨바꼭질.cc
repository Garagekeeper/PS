#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100001
int N, K;

int map[MAX] = { 0, };
bool visited[MAX] = { 0, };

void GetInput()
{
	cin >> N >> K;

}

bool CanGo(int x)
{
	if (x < 0 || x >= MAX) return false;
	if (visited[x]) return false;
	return true;
}

void Bfs(int x)
{
	queue<int> q;
	int dx[3] = { 1, -1, 2};
	map[x] = 0;
	visited[x] = true;
	q.push(x);

	while (!q.empty())
	{
		int frt = q.front();
		q.pop();
		if (frt == K) break;

		for (int i = 0; i < 3; i++)
		{
			int nx = (i == 2) ? frt * dx[i] : frt + dx[i];
			if (CanGo(nx))
			{
				visited[nx] = true;
				map[nx] = map[frt] + 1;
				q.push(nx);
			}
		}
	}
}

void PrintAns()
{
	cout << map[K] <<"\n";
}

int main()
{
	GetInput();
	Bfs(N);
	PrintAns();

	return 0;
}
