#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int graph[50][50];
int emptyCount = 0;
int maskCheck[1<<10];
const int minVal = 987654321;
int ans = minVal;

enum CellType
{
    None = 0,
    Wall = 1,
    Candidate = 2,
};

struct Cell
{
    int x;
    int y;
    int depth;

    Cell operator+(const Cell other)
    {
        int nx = x + other.x;
        int ny = y + other.y;

        return {nx, ny, depth+1};
    }
};

vector<Cell> candiateVec;
vector<Cell> dirVec = {
    {0,1,0},
    {1,0,0},
    {0,-1,0},
    {-1,0,0},
};

bool CanGo(const vector<vector<bool>>& visited, Cell nextCell)
{
    if (nextCell.x < 0 || nextCell.x >= N) return false;
    if (nextCell.y < 0 || nextCell.y >= N) return false;
    if (visited[nextCell.x][nextCell.y] == true) return false;
    if (graph[nextCell.x][nextCell.y] == CellType::Wall) return false;
    return true;
}


void Simulate(vector<int> selected)
{

    queue<Cell> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int visitedCnt = 0;
    int maxdepth = 0;

    for (auto index : selected)
    {
        q.push(candiateVec[index]);
        visited[candiateVec[index].x][candiateVec[index].y] = true;
        visitedCnt++;
    }

    //BFS
    while(!q.empty())
    {
        auto curr = q.front(); q.pop();
        for (int i=0; i<dirVec.size(); i++)
        {
            Cell nextCell = curr + dirVec[i];
            if (CanGo(visited, nextCell))
            {
                q.push(nextCell);
                visited[nextCell.x][nextCell.y] = true;
                visitedCnt++;
                maxdepth = max(maxdepth, nextCell.depth);
            }
        }
    }

    if (visitedCnt == emptyCount)
        ans = min(ans, maxdepth);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int val;
            cin >> val;
            if (val == CellType::Candidate) 
            {
                candiateVec.push_back({i,j,0}); 
                val = CellType::None;
                emptyCount++;
            }
            else if (val == CellType::None)
            {
                emptyCount++;
            }

            graph[i][j] = val;
        }    
    }

    auto comb = vector<bool>(candiateVec.size(), false);
    for(int i=0; i < M; i++)
    {
        comb[i] = true;
    }

    sort(comb.begin(), comb.end());

    do
    {
        vector<int> selected;
        for (int i=0; i<comb.size(); i++)
            if (comb[i] != 0)
                selected.push_back(i);
        Simulate(selected);
    } while (next_permutation(comb.begin(), comb.end()));
    
    if(ans == minVal)
        ans = -1;

    cout << ans << "\n";

    return 0;
}