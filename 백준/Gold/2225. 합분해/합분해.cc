#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000000
int N,K;

// (K,N) K개 사용해서 N개 만드는 경우의 수
vector<vector<long long>> dp;

int main()
{
    cin >> N >> K;

    dp.resize(K+1, vector<long long>(N+1));

    for (int i=1; i<=N; i++)
    {
        dp[1][i] = 1;
    }

    for (int i=1; i<=K; i++)
    {
        dp[i][1] = i;
    }

    // cnt개의 숫자를 사용
    for (int cnt = 2; cnt<=K; cnt++)
    {
        // cnt개 사용해서 i를 만들고 싶은 상황
        for (int i = 2; i<=N ; i++)
        {
            dp[cnt][i] = dp[cnt-1][i] + dp[cnt][i-1]; 
            dp[cnt][i] %= MOD;
        }
    }

    cout << dp[K][N] % MOD << '\n';
}