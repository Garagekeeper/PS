#include <bits/stdc++.h>
#define MAX 2001
using namespace std;
int arr[MAX][MAX];
int sum1[MAX][MAX];
int sum2[MAX][MAX];
int minimun;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  minimun = k * k / 2;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char temp;
      int value1, value2;
      cin >> temp;

      // value1: start with B
      // value2: start with W;
      if ((i + j) % 2 == 0) {
        value1 = temp != 'B';
        value2 = temp != 'W';
      } else {
        value1 = temp != 'W';
        value2 = temp != 'B';
      }
      sum1[i][j] =
          sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + value1;
      sum2[i][j] =
          sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + value2;
    }
  }

  for (int i = 1; i + (k - 1) <= n; i++) {
    for (int j = 1; j + (k - 1) <= m; j++) {
      int temp1 = sum1[i + (k - 1)][j + (k - 1)] - sum1[i - 1][j + (k - 1)] -
                  sum1[i + (k - 1)][j - 1] + sum1[i - 1][j - 1];
      int temp2 = sum2[i + (k - 1)][j + (k - 1)] - sum2[i - 1][j + (k - 1)] -
                  sum2[i + (k - 1)][j - 1] + sum2[i - 1][j - 1];
      minimun = min({minimun, temp1, temp2});
    }
  }

  cout << minimun << "\n";
}
