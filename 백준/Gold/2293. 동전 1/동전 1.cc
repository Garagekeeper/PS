#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int weight[101];
int dp[MAX];
int n, k;

// dp[x][y]: x까지의 추들을 사용해서 y를 만드는 경우의 수?
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp > MAX - 1) {
      n--;
      i--;
      continue;
    }
    weight[i] = temp;
  }

  for (int j = 1; j <= k; j++) {
    dp[j] += j % weight[0] == 0 ? 1 : 0;
  }

  // for (int j = 1; j <= k; j++) {
  //   printf("%2d ", dp[j]);
  // }
  // printf("\n");

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j == weight[i]) {
        dp[j]++;
      }
      if(j-weight[i] < 1) continue;
      dp[j] += dp[j - weight[i]];
    }
    // for (int j = 1; j <= k; j++) {
    //   printf("%2d ", dp[j]);
    // }
    // printf("\n");
  }

  // for (int j = 1; j <= k; j++) {
  //   printf("%2d ", dp[j]);
  // }
  // printf("\n");

  printf("%d", dp[k]);
}
