#include <bits/stdc++.h>

int dp[1000001];
int n;

int main() {
  scanf("%d", &n);
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 3 == 0) {
      dp[i] = std::min(dp[i], dp[i / 3] + 1);
    }
    if (i % 2 == 0) {
      dp[i] = std::min(dp[i], dp[i / 2] + 1);
    }
  }

  printf("%d\n", dp[n]);
}
