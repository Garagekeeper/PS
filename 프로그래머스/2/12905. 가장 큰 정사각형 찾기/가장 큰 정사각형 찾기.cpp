#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    dp[0][0] = board[0][0];
    answer = dp[0][0];
    
    for (int i=0; i<col; i++)
    {
        dp[0][i] = board[0][i];
    }
    
    for (int i=0; i<row; i++)
    {
        dp[i][0] = board[i][0];
    }
    
    for (int i=1; i<row; i++)
    {
        for (int j=1; j<col; j++)
        {
         
            if (board[i][j]==1)
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            else 
                dp[i][j] = 0;
            
            answer = max(answer, dp[i][j]);
        }
    }
    
    return answer * answer;
}