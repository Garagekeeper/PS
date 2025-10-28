#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
enum CellType
{
    NONE = 0,
    WALL,
    FIRE,
    JIHOON,
};

struct Cell
{
    int x;
    int y;
    int cnt;
    int type;

    Cell operator+(const Cell& other)
    {
        int nx = x + other.x;
        int ny = y + other.y;

        return {nx, ny, cnt+1, type};
    }
};

char graph[1000][1000];
bool visited[1000][1000];

vector<Cell> fireVec;
vector<Cell> dirVec={
    {1,0,0,0},
    {0,1,0,0},
    {-1,0,0,0},
    {0,-1,0,0},
};

Cell startCell;
int R,C;

bool CanGo(Cell next)
{
    if (next.x < 0 || next.x >= R) return false;
    if (next.y < 0 || next.y >= C) return false;
    if (visited[next.x][next.y]) return false;
    if (graph[next.x][next.y] == CellType::WALL) return false;
    if (graph[next.x][next.y] == CellType::FIRE) return false;
    if (graph[next.x][next.y] != CellType::NONE && next.type == CellType::FIRE)
        graph[next.x][next.y] = CellType::FIRE;
    
    return true;
}

int BFS(Cell start)
{
    queue<Cell> q;
    Cell curr;
    bool isEscape = false;

    // 불이 있는 칸 큐에 넣기
    for (auto c : fireVec)
    {
        q.push(c);
        visited[c.x][c.y] = true;
    }
    
    // 지훈이 위치 넣기
    q.push(start);
    visited[start.x][start.y];

    // BFS
    while(!q.empty())
    {
        curr = q.front(); q.pop();
        // 지훈이가 가장자리에 가면 탈출
        if (curr.type == CellType::JIHOON)
        {
            if (curr.x == 0 || curr.x == R-1 || curr.y == 0 || curr.y == C-1)
            {
                isEscape = true;
                break;
            }
        }

        // D R U L 방향으로 탐색
        for (auto c : dirVec)
        {
            Cell nextCell = curr + c;
            if (CanGo(nextCell))
            {
                // 지훈, 불 상관없이 방문처리
                visited[nextCell.x][nextCell.y] = true;
                q.push(nextCell);
            }
        }
    }

    // 탈출했으면 지훈의 cnt를 반환
    if (isEscape)
        return curr.cnt;
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> R >> C;
    Cell jihoon;
    
    // 입력
    for (int i=0; i<R; i++)
    {
        string row;
        cin >> row;
        for (int j=0; j<C; j++)
        {
            int type = 0;
            if (row[j] == '#')
                type = CellType::WALL;
            else if (row[j] == 'J')
                jihoon = {i,j,1,CellType::JIHOON};
            else if (row[j] == 'F')
                fireVec.push_back({i,j,0});

            graph[i][j] = type;
        }
    }

    auto res = BFS(jihoon);
    if (res == -1)
        cout << "IMPOSSIBLE";
    else
        cout << res;

    return 0;
}