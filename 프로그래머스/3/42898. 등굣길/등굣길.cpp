#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MOD 1'000'000'007

int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;
    vector<vector<int>> land(n+1,vector<int>(m+1, 1));
    vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
    
    for (int i=0; i < puddles.size(); i++)
    {
        if (puddles[i].size() == 0) continue;
        int x = puddles[i][0];
        int y = puddles[i][1];
        land[y][x] = 0;
    }
    
    
    for (int i=1; i<=n; i++)
    {
        if (land[i][1] == 0) break;
        dp[i][1] = 1;
    }
    
    for (int i=1; i<=m; i++)
    {
        if (land[1][i] == 0) break;
        dp[1][i] = 1;
    }
    
    
    for (int i=2; i<=n;i++)
    {
        for (int j=2; j<=m; j++)
        {
            if (land[i][j] != 0)
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    /*
    for (int i=1; i<=n;i++)
    {
        for (int j=1; j<=m; j++)
        {
            {
                cout << "[" <<dp[i][j] << "]";
            }
        }
        cout << endl;
    }
    */

    
    return dp[n][m];
}