#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    
    vector<vector<int>> dp = triangle;
    
    for (int i=1; i<triangle.size(); i++)
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
    
    for (int i=0; i<dp[triangle.size()-1].size(); i++)
    {
        answer = max (dp[triangle.size()-1][i], answer);
    }
    
    return answer;
}