#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<bool>> board;
vector<int> qpos;
int N;
int answer = 0;

bool CellCheck(int x, int y, int cnt)
{
    if (cnt == 0) return true;
    //cout << "x " << x << " y " << y << endl;
    // 십자 체크
    for (int i=0; i<N; i++)
    {
        if (board[i][y] == true) return false;
        if (board[x][i] == true) return false;
    }
    

    int nx, ny;
    // 왼쪽 대각선
    // 30 41
    // 20 31 42
    // 10 21 32 43
    // 00 11 22 33 44
    // 01 12 23 34
    // 02 13 24
    // 03 14
    
    
    nx = x;
    ny = y;
    
    while (true)
    {
        nx = nx - 1;
        ny = ny - 1;
        if (nx < 0 || ny < 0) break;
        if (board[nx][ny] == true) return false;
    }
    
    // 오른쪽 대각선
    nx = x;
    ny = y;
    
    while (true)
    {
        nx = nx - 1;
        ny = ny + 1;
        if (nx < 0 || ny >= N) break;
        if (board[nx][ny] == true) return false;
    }
    
    return true;
}

int dfs(int row, int num)
{
    
     if (num >= N)
    {
        return 1;
    }
    
    for (int j = 0; j<N; j++)
        {
            if (board[row][j] == false)
            {
                if (CellCheck(row,j, num))
                {
                    board[row][j] = true;
                    answer += dfs(row+1, num + 1);
                    board[row][j] = false;
                }
            }
        }
    
    return 0;
}

int solution(int n) {
    N = n;
    board.resize(n, vector<bool>(n, false));
    qpos.resize(n,0);
    dfs(0,0);
    return answer;
}