#include<iostream>
#include<vector>

using namespace std;

bool check = false;
vector<vector<int>> board;

bool CanPlace(int x, int y, int num)
{
    for (int i=0; i<9; i++)
    {
        if (board[x][i] == num) return false;
        if (board[i][y] == num) return false;
    }

    int boxX = ( x / 3 ) * 3;
    int boxy = ( y / 3 ) * 3;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[boxX+i][boxy+j] == num) return false;
        }
    }

    return true;
}

void dfs(int x, int y) 
{
    if (check) return;
    for (int i=x; i<9; i++)
    {
        for (int j= (x==i ? y : 0) ; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 1; k <=9; k++)
                {
                    if (CanPlace(i,j,k))
                    {
                        board[i][j] = k;
                        dfs(i,j);
                        if (check) return;
                        board[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
    check = true;
}

void sudoku() {
    for (int i = 0; i < 9; i++) 
    {
        board.push_back(vector<int>());
        for (int j = 0; j < 9; j++) 
        {
            int temp;
            cin >> temp;
            board[i].push_back(temp);
        }
    }

    dfs(0, 0);

    for (const auto& row : board) 
    {
        for (int n : row)
            cout << n << " ";
        cout << "\n";
    }

}

int main() 
{
  sudoku();
}