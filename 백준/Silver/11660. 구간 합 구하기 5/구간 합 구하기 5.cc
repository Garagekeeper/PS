#include <bits/stdc++.h>
#define MAX 1025
using namespace std;
int arr[MAX][MAX];
int sum[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  int x1, x2, y1, y2;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    sum[i][1] = sum[i - 1][1] + arr[i][1];
    sum[1][i] = sum[1][i - 1] + arr[1][i];
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
    }
  }

  while (m--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
                sum[x1 - 1][y1 - 1]
         << "\n";
  }
}
