#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<bool>> visited;

struct Cell
{
    Cell(int x, int y): _x(x), _y(y), _heightDiff(0) {}
    Cell(int x, int y, int heightDiff): _x(x), _y(y), _heightDiff(heightDiff) {}
    int _x;
    int _y;
    //현재까지 오면서 사용한 사다리 비용
    int _heightDiff;
    
    bool operator<(const Cell& other) const
    {
        return _heightDiff > other._heightDiff;
    }
};

bool canGo(int x, int y, int n)
{
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= n) return false;
    if (visited[x][y]) return false;
    
    return true;
    
}

int BFS(vector<vector<int>>& land, const int& height)
{
    priority_queue<Cell> pq;
    visited.resize(land.size(), vector<bool>(land.size(), false));
    int totalCost = 0;
    
    pq.push(Cell(0,0));
    
    while(!pq.empty())
    {
        Cell top = pq.top();
        pq.pop();
        int cx = top._x;
        int cy = top._y;
        
        if (visited[cx][cy]) continue;
        
        visited[cx][cy] = true;
        totalCost+= top._heightDiff;
        
        vector<int> dx = {0, 1,  0, -1};
        vector<int> dy = {1, 0, -1,  0};
        
        for (int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (canGo(nx, ny, land.size()))
            {
                int diff = abs(land[cx][cy]-land[nx][ny]);
                if ( diff > height)
                    pq.push(Cell(nx, ny, diff));
                    
                else
                    pq.push(Cell(nx, ny, 0));
            }
        }
    }
    return totalCost;
}

int solution(vector<vector<int>> land, int height) {
    return BFS(land, height);
}
