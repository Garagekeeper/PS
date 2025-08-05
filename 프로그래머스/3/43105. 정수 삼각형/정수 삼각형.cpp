#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    
    vector<vector<int>> dp = triangle;
    int row = triangle.size();
    
    for (int i=1; i<row; i++)
    {
        for (int j=0; j<triangle[i].size(); j++)
        {
            if (j == 0) { dp[i][j] += dp[i-1][0]; }
            else if (j == triangle[i].size() - 1) { dp[i][j] += dp[i-1][j-1]; }
            else 
            {
                dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    
    answer = *max_element(dp[row-1].begin(), dp[row-1].end());
    
    return answer;
}