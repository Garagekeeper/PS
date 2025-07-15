#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;


vector<vector<int>> gboard;
vector<vector<vector<int>>> cost;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int N;

enum EDir
{
    RIGHT,
    DOWN,
    LEFT,
    UP,
};

struct Cell
{
    int _x;
    int _y;
    int _cost;
    int _dir;
};

struct CellCmp
{
    bool operator()(const Cell& a, const Cell& b)
    {
        return a._cost > b._cost;
    }
};


bool CanGo(int nx, int ny)
{
    if (nx < 0 || nx >= N) return false;
    if (ny < 0 || ny >= N) return false;
    if (gboard[nx][ny] == 1) return false; 
    return true;
}

void BFS()
{
    cost.resize(N, vector<vector<int>>(N, vector<int>(4,INT_MAX)));
    priority_queue<Cell, vector<Cell>, CellCmp> q;
    
    // 시작점에서 오른쪽 & 아래 방향으로 초기화
    for (int dir = 0; dir < 2; dir++) {
        int nx = dx[dir], ny = dy[dir];
        if (CanGo(nx, ny)) {
            cost[nx][ny][dir] = 100;
            q.push({nx, ny, 100, dir});
        }
    }

    
    while(!q.empty())
    {
        Cell front = q.top();
        q.pop();

        int cx = front._x;
        int cy = front._y;
        int ccost= front._cost;
        int dir = front._dir;

        if (cx == N-1 && cy == N-1) continue;
        
        for (int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (CanGo(nx,ny))
            {
                int newCost;
                int newDir = (i);
                // 같은 방향
                if (dir == newDir)
                {
                    newCost = ccost + 100;
                }
                // 90도 회전
                else
                {
                     newCost = ccost + 600;
                }
                
                if (cost[nx][ny][newDir] > newCost)
                {
                    cost[nx][ny][newDir] = min(cost[nx][ny][newDir], newCost);
                    q.push(Cell({nx,ny,newCost,newDir}));
                    
                }
                
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    gboard = board;
    N = board.size();
    BFS();
    
    int minCost = INT_MAX;
    for (int i=0; i<4; i++)
    {
        minCost = min(minCost, cost[N-1][N-1][i]);
    }
    return minCost;
}