#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int map_weight[MAX][MAX];
long long dp[MAX][MAX];
int m, n;

long long dfs(int x, int y) {
  long long res   = 0;
  int vertical[4] = {0, 0, 1, -1};
  int horizen[4]  = {1, -1, 0, 0};
  if (x == m && y == n) return 1;
  if (dp[x][y] != -1) return dp[x][y];

  for (int i = 0; i < 4; i++) {
    int nx = x + vertical[i];
    int ny = y + horizen[i];

    if (nx < 1 || ny < 1) continue;
    if (nx > m || ny > n) continue;
    if (map_weight[nx][ny] < map_weight[x][y]) {
      res += dfs(nx, ny);
    }
  }

  return dp[x][y] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> map_weight[i][j];
    }
  }

  cout << dfs(1, 1);
}