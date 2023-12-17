#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int weight[101];
int dp[MAX] = {1, 0};
int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  // i번째 추까지 사용해서 만들 수 있는 j의 개수
  for (int i = 0; i < n; i++) {
    int weight;
    cin >> weight;
    for (int j = weight; j <= k; j++) {
      dp[j] += dp[j - weight];
    }
  }
  printf("%d", dp[k]);
}
