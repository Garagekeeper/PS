#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int dp[MAX][MAX];
int prefix[MAX];
int file[MAX];
int t, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> file[i];
      prefix[i] = prefix[i - 1] + file[i];
    }

    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= k - i; j++) {
        // printf("x:%d\n", x);
        dp[j][j + i] = INT_MAX;
        for (int x = j; x < i + j; x++) {
          dp[j][j + i] =
              min(dp[j][x] + dp[x + 1][i + j] + prefix[j + i] - prefix[j - 1],
                  dp[j][j + i]);
        }
      }
    }
    cout << dp[1][k] << "\n";
  }
}

// 11 23
// 12 33
//