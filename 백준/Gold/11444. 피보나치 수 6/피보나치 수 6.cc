#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long A[2][2]   = {{1, 1}, {1, 0}};
long long res[2][2] = {{1, 0}, {0, 1}};
long long temp[2][2];

long long n;
void MatrixMultiplication(long long A[2][2], long long B[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      temp[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        temp[i][j] = (temp[i][j] + (A[i][k] % MOD * B[k][j] % MOD)) % MOD;
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A[i][j] = temp[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  if (n == 1) res[0][0] = 1;
  n--;
  while (n > 0) {
    if (n % 2 == 0) {
      MatrixMultiplication(A, A);
    } else {
      MatrixMultiplication(res, A);
      MatrixMultiplication(A, A);
    }
    n /= 2;
  }

  cout << res[0][0];
}
