#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
#define NMAX 1001
#define MMAX 1001

int N, M;

vector<vector<int>> stage;
vector<vector<bool>> visited(NMAX, vector<bool>(MMAX, false));
vector<vector<bool>> Breakvisited(NMAX, vector<bool>(MMAX, false));

bool isBreak = false;

struct Pos
{
	int x;
	int y;
	int distance;
	bool _isBreak;

	bool operator==(Pos operand)
	{
		return ((operand.x == x) && (operand.y == y));
	}

	bool operator!=(Pos operand) { return !(*this == operand); }
};

Pos parent[NMAX][MMAX];
stack<Pos> route;

constexpr Pos START_POS = { 0, 0, 1, false };

bool CanGo(int x, int y, bool &_isBreak)
{
	// x y 좌표가 지정된 구역을 넘어서면 종료료
	if (x < 0 || x >= N)
		return false;
	if (y < 0 || y >= M)
		return false;

	// 0. 벽을 부수지 않은 경우
	if (!_isBreak)
	{
		// 0-1 벽을 부수지 않고 도달한 경로가 있다면 건너뜀
		if (visited[x][y] == true)
		{
			return false;
		}
		// 0-2 벽을 부수지 않고 도달한 경로가 없는 경우
		else if (visited[x][y] == false)
		{
			// 벽을 부숴서 이미 도달한 경우
			if (Breakvisited[x][y] == true)
			{
				// 벽을 부수지 않고 도달할 수 있으면 벽을 부수지
				// 않는 것으로 교체
				if (stage[x][y] == 0)
				{
					visited[x][y] = true;
					Breakvisited[x][y] = false;
					_isBreak = false;
					return true;
				}
			}
			// 아무도 방문하지 않은 것
			else if (Breakvisited[x][y] == false)
			{
				// 막힌곳이면 벽을 부숨, 아니면 그냥 방문
				if (stage[x][y] == 1)
				{
					_isBreak = true;
					Breakvisited[x][y] = true;
					return true;
				}
				else
				{
					visited[x][y] = true;
					return true;
				}
			}
		}
	}
	// 1. 이미 벽을 부순 경우
	else if (_isBreak)
	{
		// 0-1 어떤 경우든 이미 도달했다면 건너뜀
		if (visited[x][y] || Breakvisited[x][y])
		{
			return false;
		}
		else
		{
			if (Breakvisited[x][y] == false && stage[x][y] == 0)
			{
				Breakvisited[x][y] = true;
				return true;
			}
		}
	}
	return false;
}

int BFS()
{
	queue<Pos> q;
	Pos EndPos { N - 1, M - 1 };

	bool found = false;
	// 시작점 추가가
	q.push(START_POS);
	visited[0][0] = true;

	while (true)
	{
		// Queue가 비었으면 종료
		if (q.size() == 0)
			break;

		// 큐에서 하나 뽑아옴
		Pos posHead = q.front();

		if (posHead == EndPos)
		{
			found = true;
			break;
		}

		q.pop();
		// R D L U 순으로 탐색
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };

		for (int i = 0; i < 4; i++)
		{
			int nx = posHead.x + dx[i];
			int ny = posHead.y + dy[i];
			bool HeadBreak = posHead._isBreak;

			if (CanGo(nx, ny, HeadBreak))
			{
				q.push(Pos { nx, ny, posHead.distance+1,
				    HeadBreak });
			}
		}
	}

	if (!found)
	{
		return -1;
	}

	return q.front().distance;
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	stage.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			stage[i][j] = s[j] - '0';
		}
	}
	int res = BFS();

	cout << res << endl;
}
