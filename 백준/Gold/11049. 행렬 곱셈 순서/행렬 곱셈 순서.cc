#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int N;
int answer=INT_MAX;


int main()
{
    cin >> N;

    // 0: row, 1:col
    vector<pair<int, int>> mats;
    // dp[i][j] : i to j 까지의 최소 비용
    vector<vector<int>> dp(N+1, vector<int>(N+1, INT_MAX));
    mats.push_back({});
    for (int i=1; i<=N; i++)
    {
        int row,col;
        cin >> row >> col;
        mats.push_back({row, col});
        dp[i][i] = 0;
    }

    // 길이가 len인(포함된 원소가 len+1개인) 슬라이딩 윈도우를 이동.
    // start와 end로 표현하고 이 사이에 원소가 len+1개 있음.
   
    for (int len = 1; len < N; len++)
    {
        for (int start = 1; start + len <= N; start++)
        {
            int end = start + len;
            // start to end의 최솟값을 계산

            for (int k=start; k < end; k++)
            {
                // (start to k) + (k+1 to end) + (start row * k+1 row * end col) 
                dp[start][end] = min(dp[start][k]+ dp[k+1][end]
                     + (mats[start].first * mats[k+1].first * mats[end].second), dp[start][end]);
            }
        }
    }

    cout << dp[1][N] << '\n';
}