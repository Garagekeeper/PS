#include <bits/stdc++.h>

#define MOD 1000000000;

int dp[10001][2];
int num[10001];
int n;
int max=0;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  
  dp[1][0] = 1;
  dp[n][1] = 1;
  for (int i=1; i<=n; i++){
      dp[i][0] = 1;
      for (int j=1; j < i; j++){
        if (num[j] < num[i]){
          dp[i][0] = dp[i][0] > (dp[j][0] + 1) ? dp[i][0] : (dp[j][0] + 1);
        }
      }
    }
  for (int i=n; i>=1; i--){
    dp[i][1] = 1;
    for (int j=n; j>i; j--){
      if (num[i] > num[j]){
        dp[i][1] = dp[i][1] > (dp[j][1] + 1) ? dp[i][1] : (dp[j][1] + 1);
      }
    }
  }

  for (int i=1; i<=n; i++){
    max = max > (dp[i][0] + dp[i][1]) ? max : (dp[i][0] + dp[i][1]);
  //printf("[%d %d]\n",dp[i][0], dp[i][1]);
  }

  printf("%d",max-1);
}
