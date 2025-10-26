#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, K;
int dp[101][10001];
int coin[101];
int cnt[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> K;

    for (int i=1; i<=K; i++)
        cin >> coin[i] >> cnt[i];
    
    dp[0][0] = 1;
    //dp[i][j] -> i번째 동전까지 사용해서 j를 만드는 경우의 수

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            // i번째 동전을 l개 사용하는 경우
            for (int l = 0; l <= cnt[i]; l++)
            {
                // i번째 동전까지 사용해서 j를 만드는 중
                // i번째 동전 l개를 제외한 금액
                int val = j - coin[i] * l;
                if (val < 0) break;
                // i번쨰 동전까지 사용해서 j를 만드는 경우의 수
                // => i번째 동전을 사용하지 않는 경우
                // i번째 동전을 1개 사용하는 경우
                // ...
                // i번쨰 동전을 모두 사용한 경우
                dp[i][j] += dp[i-1][val];
            }
        }
    }

    cout << dp[K][T];

    return 0;
}