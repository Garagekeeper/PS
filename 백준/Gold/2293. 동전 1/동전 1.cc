#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int weight[101];
int dp[MAX];
int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp > MAX - 1) {
      n--; i--;
      continue;
    }
    weight[i] = temp;
  }
  //i번째 추까지 사용해서 만들 수 있는 j의 개수
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j == weight[i]) dp[j]++;
      dp[j] += j - weight[i] > 0 ? dp[j - weight[i]] : 0;
    }
  }
  cout << dp[k];
}
