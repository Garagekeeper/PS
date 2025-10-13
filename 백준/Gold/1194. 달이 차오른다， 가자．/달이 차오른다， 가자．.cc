#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Pos
{
    int x;
    int y;
    int keyStatus = 0;
    int distance = 0;
};

int N, M;
const int INF = 987654321;
vector<string> maze;
vector<vector<vector<bool>>> visited;
Pos startPos;

void GetKey(Pos& pos, int index)
{
    pos.keyStatus |= 1 << index;
}

bool KeyCheck(int keyStatus, int doorIndex)
{
    if ((keyStatus & 1 << doorIndex) == 0)
    {
        return false;
    }

    return true;
}

bool MoveToNextCell(Pos& next)
{
    // x,y 범위 넘으면 실패
    if (0 > next.x || next.x >= N) return false;
    if (0 > next.y || next.y >= M) return false;
    // 벽이면 실패
    if (maze[next.x][next.y] == '#') return false;

    // 이미 방문했으면 실패
    if (visited[next.x][next.y][next.keyStatus] == true) return false;

    // 열쇠
    if ('a' <= maze[next.x][next.y] && maze[next.x][next.y] <= 'f')
    {
        GetKey(next, maze[next.x][next.y] - 'a');
    }

    // 문
    if ('A' <= maze[next.x][next.y] && maze[next.x][next.y] <= 'F')
    {
        // 열쇠가 없는 경우
        if (KeyCheck(next.keyStatus, maze[next.x][next.y] - 'A') == false) return false;
    }
    
    return true;
}

void BFS(Pos start)
{
    queue<Pos> q;
    q.push(start);
    visited[start.x][start.y][start.keyStatus] = true;
    
    while(!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (int i=0; i<4; i++)
        {
            // RDLU 순으로 탐색
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};

            Pos next = {f.x + dx[i], f.y + dy[i], f.keyStatus, f.distance + 1};
            if (MoveToNextCell(next))
            {
                visited[next.x][next.y][next.keyStatus] = true;
                if (maze[next.x][next.y] == '1')
                {
                    cout << next.distance << "\n";
                    return;
                }
                q.push(next);
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    // 입력
    cin >> N >> M;
    visited = vector<vector<vector<bool>>>(N,vector<vector<bool>>(M,vector<bool>(1<<7, false)));
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        // 시작 지점
        int zeroIndex = row.find("0");
        if (zeroIndex != string::npos)
        {
            startPos = {i, static_cast<int>(zeroIndex)};
        }
        maze.push_back(row);
    }

    BFS(startPos);

    return 0;
}
