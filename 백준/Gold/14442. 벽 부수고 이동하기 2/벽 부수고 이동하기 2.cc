#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
#define NMAX 1001
#define MMAX 1001

struct Pos
{
	int x;
	int y;
	int distance;
	int _breakCnt;

	bool operator==(Pos &operand)
	{
		return ((operand.x == x) && (operand.y == y));
	}

	bool operator!=(Pos &operand) { return !(*this == operand); }
};

int N, M, K;
int stage[NMAX][MMAX]; // 맵 정보
bool visited[NMAX][MMAX][11];
Pos parent[NMAX][MMAX][2];

bool CanGo(int x, int y, const Pos &head, int &nb)
{
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	// 목표 지점이 벽이 아님
	if (stage[x][y] == 0 && !visited[x][y][head._breakCnt])
	{
		visited[x][y][head._breakCnt] = true;
		nb = head._breakCnt;
		return true;
	}
	// 목표 지점이 벽임
	else if (stage[x][y] == 1 && head._breakCnt < K && !visited[x][y][head._breakCnt+1])
	{
		// 현재까지 K번 미만으로 벽을 부쉈고
		// 현재보다 1개 더 부순 상태에서 이미 방문하지 않은 경우
		// 벽을 부숨
		visited[x][y][head._breakCnt + 1] = true;
		nb = head._breakCnt + 1;
		return true;
	}
	return false;
}

int BFS()
{
	queue<Pos> q;
	Pos EndPos { N - 1, M - 1 };
	Pos StartPos { 0, 0, 1, false };

	bool found = false;
	// 시작점 추가
	q.push(StartPos);
	visited[0][0][0] = true;

	while (true)
	{
		if (q.size() == 0)
			break;

		Pos posHead = q.front();
		q.pop();

		if (posHead == EndPos)
		{
			return posHead.distance;
		}

		// R D L U 순으로 탐색
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };

		for (int i = 0; i < 4; i++)
		{
			int nx = posHead.x + dx[i];
			int ny = posHead.y + dy[i];
			int nb;

			if (CanGo(nx, ny, posHead, nb))
			{
				q.push(
				    Pos { nx, ny, posHead.distance + 1, nb });
			}
		}
	}

	return -1;
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
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
	cout << res << "\n";

    return 0;
}