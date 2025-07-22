#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> board;
int N;
int answer;
bool PlaceQueen(int x, int y)
{
    //십자 체크
    for (int i = 0 ; i<N; i++)
    {
        if (board[i][y] == true) return false;
    }
    
    //왼쪽 대각선
    int nx = x;
    int ny = y;
    while (true)
    {
        nx--;
        ny--;
        if (nx < 0|| ny < 0) break;
        if (board[nx][ny] == true) return false;
    }
    
    //오른쪽 대각선
    nx = x;
    ny = y;
    while (true)
    {
        nx--;
        ny++;
        if (nx < 0 || ny >= N) break;
        if (board[nx][ny] == true) return false;
    }
    
    return true;
}

void dfs(int row, int num)
{
    if (num == N)
    {
        answer++;
        return;
    }
    
    for (int i=0; i<N; i++)
    {
        if (board[row][i] == false)
        {
            if (PlaceQueen(row, i))
            {
                board[row][i] = true;
                dfs(row + 1 , num + 1);
                board[row][i] = false;
            }
        }
    }
}

int solution(int n) {
    board.resize(n, vector<bool>(n, false));
    N = n;
    dfs(0, 0);
    
    return answer;
}