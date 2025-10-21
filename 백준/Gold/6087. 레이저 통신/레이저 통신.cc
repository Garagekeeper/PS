#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int W, H;
const int INF = 987654321;
struct Pos
{
    int x;
    int y;
    int dir;
    int cnt;

    bool operator==(Pos& other)
    {
        return x==other.x && y==other.y; 
    }

    bool operator<(const Pos& other) const
    {
        return cnt < other.cnt;
    }


};

vector<string> graph;
vector<vector<vector<int>>> visited;
vector<Pos> ans;
vector<Pos> C;

bool CanGo(Pos nextPos)
{
    int x = nextPos.x;
    int y = nextPos.y;
    int dir = nextPos.dir;

    if (x < 0 || x >= H) return false;
    if (y < 0 || y >= W) return false;
    if (graph[x][y] == '*') return false;
    if (visited[x][y][dir] <= nextPos.cnt) return false;

    return true;
}

void BFS(Pos start)
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<Pos> q;
    q.push({start.x, start.y, -1, 0});

    visited[start.x][start.y][0] = 0;
    visited[start.x][start.y][1] = 0;
    visited[start.x][start.y][2] = 0;
    visited[start.x][start.y][3] = 0;
    Pos curr;

    while (!q.empty())
    {
        curr = q.front(); q.pop();
        for (int i=0; i<4; i++)
        {
            int cnt = curr.cnt;
            if (curr.dir != -1 && i != curr.dir) cnt++;
            Pos nextPos = {curr.x + dx[i], curr.y + dy[i], i, cnt};
            if (CanGo(nextPos))
            {
                visited[nextPos.x][nextPos.y][nextPos.dir] = cnt;
                q.push(nextPos);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> H;
    graph = vector<string>(H, string(W,' '));
    visited = vector<vector<vector<int>>>(H,vector<vector<int>>(W, vector<int>(4,INF)));

    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            char cell;
            cin >> cell;
            if (cell == 'C')
            {
                C.push_back({i,j,0});
            }
            graph[i][j] = cell;
        }
    }

    BFS(C.front());

    auto minVal = *min_element(visited[C.back().x][C.back().y].begin(), visited[C.back().x][C.back().y].end());

    cout << minVal;

    return 0;
}
