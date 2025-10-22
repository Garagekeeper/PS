#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;
int graph[20][20];
vector<vector<bool>> visited;
int N;
int ans = 0;
bool dirty;

struct Cell
{
    int x;
    int y; 
    int cnt;
    int babySharkSize;
    int depth;

    bool operator<(const Cell& other) const
    {
    if (depth != other.depth) return depth < other.depth;
    if (x != other.x) return x < other.x;
    return y < other.y;
    }
};

bool CanGo(Cell& cell)
{
    int x = cell.x;
    int y = cell.y;
    int bss = cell.babySharkSize;

    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= N) return false;
    if (visited[x][y]) return false;
    if (bss < graph[x][y]) return false;

    return true;

}

void BFS(Cell start)
{
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    queue<Cell> q;    
    Cell current;
    vector<Cell> fish;

    fish.push_back(start);

    while(true)
    {
        
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        
        if (fish.empty()) break;

        sort(fish.begin(), fish.end());
        Cell& nstart = fish.front();
        visited[nstart.x][nstart.y] = true;

        if (graph[nstart.x][nstart.y] < nstart.babySharkSize &&  graph[nstart.x][nstart.y] != 0)
        {
            graph[nstart.x][nstart.y] = 0;
            nstart.cnt++;
            if (nstart.cnt == fish.front().babySharkSize)
            {
                nstart.babySharkSize++;
                nstart.cnt=0;
            }
        }
        
        q.push(fish.front());
        ans = fish.front().depth;
        fish.clear();

        while(!q.empty())
        {
            current = q.front(); q.pop();
            
            for (int i=0; i<4; i++)
            {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                dirty = false;

                Cell nCell = {nx, ny, current.cnt, current.babySharkSize, current.depth + 1};
                if (CanGo(nCell))
                {
                    if (graph[nx][ny] < current.babySharkSize && graph[nx][ny] != 0)
                    {
                        fish.push_back(nCell);
                    }
                    q.push(nCell);
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int startX;
    int startY;

    cin >> N;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int val;
            cin >> val;
            if (val == 9) {startX = i; startY = j; val = 0;}
            graph[i][j] = val;
        }
    }

    BFS({startX,startY,0,2,0});


    return 0;
}