#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int dp[MAX][MAX];
int prefix[MAX];
int matrix[MAX][3];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  int temp = 1;
  for (int i = 1; i <= n; i++) {
    cin >> matrix[i][1] >> matrix[i][2];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      dp[j][j + i] = INT_MAX;
      for (int x = j; x < i + j; x++) {
        dp[j][j + i] = min(dp[j][x] + dp[x + 1][i + j] +
                               matrix[j][1] * matrix[x][2] * matrix[j + i][2],
                           dp[j][j + i]);
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%d ", dp[i][j]);
  //   }
  //   printf("\n");
  // }
  cout << dp[1][n];
}

// 11 12  12 23
/*
11
dp[1][2] = min(dp[1][2], dp[1][1] + 12)
*/
// 21     13    x 1 2   13 = min(13,11 + , 23+x)
// 31 32

/*
   1   2    3
 1 0  30
 2 0   0   36
 3 0   0    0

123
12 3
1 23

1234
123 4
1 234
*/
