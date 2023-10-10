#include <bits/stdc++.h>

int dp[101][100001];  // i,weight
int w[101];
int v[101];
int n, max_weight;
int max;

int main() {
  scanf("%d %d", &n, &max_weight);

  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }

  for (int i = 1; i <= n; i++) {
    for (int weight = 1; weight <= max_weight; weight++) {
      if (w[i] > weight)
        dp[i][weight] = dp[i - 1][weight];
      else
        dp[i][weight] =
            std::max(dp[i - 1][weight], v[i] + dp[i - 1][weight - w[i]]);
    }
  }

  printf("%d\n", dp[n][max_weight]);
}
