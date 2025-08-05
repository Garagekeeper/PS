#include <string>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;
vector<vector<int>> cahche;

int solution(int n) 
{
    int answer = 0;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i=3; i<=n; i++)
    {
        dp[i] = ( dp[i-1] + dp[i-2] ) % MOD;
    }
    
    return dp[n];
}