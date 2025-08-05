#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int> > land)
{
    int size = land.size();
    vector<vector<int>> dp(size + 1, vector<int>(4));
    for (int i=0; i<4; i++)
    {
        dp[0][i] = land[0][i];
    }
    
    int answer = 0;

    for (int i=1; i<size; i++)
    {
        for (int j=0; j<4; j++)
        {
            int maxVal = 0;
            for (int k=0; k<4; k++)
            {
                if (j!=k) 
                    maxVal = max(maxVal, dp[i-1][k]);
            }
            dp[i][j] += land[i][j] + maxVal;
        }
    }
    
    answer = max({dp[size-1][0], dp[size-1][1], dp[size-1][2], dp[size-1][3]});
    
    return answer;
}