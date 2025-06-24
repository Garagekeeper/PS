#include <string>
#include <vector>
using namespace std;

vector<vector<vector<bool>>> visited;

struct Pos
{
    int x;
    int y;
};

// 목표 좌표에 갈 수 있는지
bool CanGo(Pos nPos)
{
    int x = nPos.x;
    int y = nPos.y;
    if (x < -5 || x > 5) return false;
    if (y < -5 || y > 5) return false;
    return true;
}

bool isVisitedBySamePath(Pos bPos, Pos nPos, int dir)
{
    // 벡터 탐색을 위한 인덱스
    int bx, by;
    int nx, ny;
    
    bx = (bPos.x + 5);
    by = (bPos.y + 5);
    nx = (nPos.x + 5);
    ny = (nPos.y + 5);
    
    //양방향 검사
    //이전 좌표에서 목표 좌표로 방문한 적 있는지
    //목표 좌표에서 이전 좌표로 방문한 적 있는지
    if (visited[by][bx][dir] || visited[ny][nx][(dir + 2) % 4]) return true;
    else 
    {
        visited[by][bx][dir] = true;
        return false;
    }
}

void move(char c, Pos& currentpos, int& answer)
{
    Pos nPos = currentpos;
    int dir=0;
    // 목표 좌표 설정
    if (c == 'U')
    {
        nPos.y += 1;
        dir=0;
    }
    else if (c == 'D')
    {
        nPos.y -= 1;
        dir=2;
    }
    else if (c == 'R')
    {
        nPos.x += 1;
        dir=1;
    }
    else if (c == 'L')
    {
        nPos.x -= 1;
        dir=3;
    }
    
    if (CanGo(nPos))
    {
        // 목표 좌표에 갈 수 있으면
        // 이미 방문한 경로인지 확인 아니라면 count 증가
        if (!isVisitedBySamePath(currentpos, nPos, dir)) answer++;
        
        // 현재 좌표 갱신
        currentpos = nPos;
    }
}

int solution(string dirs) 
{
    int answer = 0;
    //각 좌표에서 갈 수 있는 4가지 경로를 방문 했는지 저장하는 벡터
    visited.resize(11, vector<vector<bool>>(11, vector<bool>(4)));
    
    Pos currentPos = Pos{0,0};
    
    for (auto c : dirs)
    {
        move(c, currentPos ,answer);
    }
    
    return answer;
}
