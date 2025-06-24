#include <string>
#include <vector>
using namespace std;

vector<vector<vector<bool>>> visited;

struct Pos
{
    int x;
    int y;
};

bool CanGo(Pos nPos)
{
    int x = nPos.x;
    int y = nPos.y;
    if (x < -5 || x > 5) return false;
    if (y < -5 || y > 5) return false;
    return true;
}

bool isVisitedBySamePath(Pos bPos, Pos nPos, char dirC)
{
    // 벡터 탐색을 위한 인덱스
    int bx, by;
    int nx, ny;
    int dir = 0;
    if (dirC == 'U')
    {
        dir = 0;
    }
    else if (dirC == 'D')
    {
        dir = 2;
    }
    else if (dirC == 'R')
    {
         dir = 1;
    }
    else if (dirC == 'L')
    {
        dir = 3;
    }
    
    bx = (bPos.x + 5);
    by = (bPos.y + 5);
    nx = (nPos.x + 5);
    ny = (nPos.y + 5);
    
    
    if (visited[by][bx][dir] || visited[ny][nx][(dir + 2)%4]) return true;
    else 
    {
        visited[by][bx][dir] = true;
        return false;
    }
}

void move(char c, Pos& currentpos, int& count)
{
    Pos nPos = currentpos;
    if (c == 'U')
    {
        nPos.y += 1;
    }
    else if (c == 'D')
    {
        nPos.y -= 1;
    }
    else if (c == 'R')
    {
        nPos.x += 1;
    }
    else if (c == 'L')
    {
        nPos.x -= 1;
    }
    
    if (CanGo(nPos))
    {
        if (!isVisitedBySamePath(currentpos, nPos, c)) count++;
        currentpos.x = nPos.x;
        currentpos.y = nPos.y;
    }
}

int solution(string dirs) 
{
    int answer = 0;
    visited.resize(11, vector<vector<bool>>(11, vector<bool>(4, false)));
    
    Pos currentPos = Pos{0,0};
    
    for (auto c : dirs)
    {
        move(c, currentPos ,answer);
    }
    
    return answer;
}