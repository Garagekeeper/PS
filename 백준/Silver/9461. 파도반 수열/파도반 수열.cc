#include <bits/stdc++.h>

long long dp[101];

long long triangle(int n) {
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;

  for (int i = 6; i <= n; i++) {
    dp[i] = dp[i - 5] + dp[i - 1];
  }

  return dp[n];
}

int main() {
  int t, n;
    
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%lld\n", triangle(n));
  }
}
