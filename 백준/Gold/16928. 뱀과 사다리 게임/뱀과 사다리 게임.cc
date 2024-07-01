#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;
#define MAX 101
int M, N, H;
int curx, cury;
int destx, desty;

int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };
map<int, int> ladder;
map<int, int> snake;

void GetInput()
{
	cin >> N >> M;

	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		ladder.insert({ x,y });
	}
	for (int j = 0; j < M; j++)
	{
		cin >> x >> y;
		snake.insert({ x,y });
	}
}

bool CanGo(int x)
{
	if (x < 0 || x >= MAX) return false;
	if (visited[x]) return false;
	return true;
}

void BFS(int x)
{
	queue<int> q;
	visited[x] = true;
	arr[x] = 0;
	q.push(x);


	while (!q.empty())
	{

		int frtX = q.front();
		q.pop();

		auto itr1 = ladder.find(frtX);
		auto itr2 = snake.find(frtX);

		int nx = frtX;

		if (itr1 != ladder.end())
		{
			nx = itr1->second;
		}
		else if (itr2 != snake.end())
		{
			nx = itr2->second;
		}


		for (int i = 1; i < 7; i++)
		{
			nx += 1;
			if (!CanGo(nx)) continue;
			visited[nx] = true;
			arr[nx] = arr[frtX] + 1;
			q.push(nx);
		}

	}
}

void PrintAns()
{
	cout << arr[100];
}

int main()
{

	GetInput();
	BFS(1);
	PrintAns();

	return 0;
}
