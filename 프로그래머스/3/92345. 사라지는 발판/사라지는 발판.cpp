#include <string>
#include <vector>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<int> Apos;
vector<int> Bpos;
vector<vector<int>> gboard;

char turn = 'A';
int answer = 0;

bool CanGo(int x, int y)
{
    if (x < 0 || x >= gboard.size()) return false;
    if (y < 0 || y >= gboard[0].size()) return false;
    if (gboard[x][y] == 0) return false;
    return true;
}

int dfs(char turn)
{
    int count = 0;
    vector<int>& player = turn == 'A' ? Apos : Bpos;
    int cx = player[0];
    int cy = player[1];
    if (gboard[cx][cy] == 0) return 0;
       
    for (int i=0; i<4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (!CanGo(nx, ny)) continue;
        
        player[0] = nx;
        player[1] = ny;
        gboard[cx][cy] = 0;
        int res = dfs('A' + 'B' - turn) + 1;
        gboard[cx][cy] = 1;
        player[0] = cx;
        player[1] = cy;
            
        // A부터 시작.
        // 턴이 2로 나뉘어떨어지면 A가 패배
        // 현재까지 지는 경우였는데 새 경로가 이기는 경로인 경우
        if (count % 2 == 0 && res % 2 == 1) count = res;
        // 현재까지 지는 경우, 새 경로도 지는 경우. (최대한 늦게 지기)
        else if (count % 2 == 0 && res % 2 == 0) count = max (count, res);
        // 현재까지 이기는 경우, 새 경로도 이기는 경우. (최대한 빨리 이기기)
        else if (count % 2 == 1 && res % 2 == 1) count = min (count, res);
    }
    return count;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    gboard = board;
    Apos = aloc;
    Bpos = bloc;
    
    answer = dfs('A');
    
    return answer;
}
