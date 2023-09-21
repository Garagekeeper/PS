#include <bits/stdc++.h>

int abc[21][21][21];

int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return abc[0][0][0];
  }

  if (a > 20 || b > 20 || c > 20) {
    return abc[20][20][20];
  }

  return abc[a][b][c];
}

int main() {
  int a, b, c;

  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      for (int k = 0; k < 21; k++) {
        if (i == 0 || j == 0 || k == 0) {
          abc[i][j][k] = 1;
        } else if (i < j && j < k) {
          abc[i][j][k] =
              abc[i][j][k - 1] + abc[i][j - 1][k - 1] - abc[i][j - 1][k];
        } else {
          abc[i][j][k] = abc[i - 1][j][k] + abc[i - 1][j - 1][k] +
                         abc[i - 1][j][k - 1] - abc[i - 1][j - 1][k - 1];
        }
      }
    }
  }

  while (true) {
    scanf("%d %d %d", &a, &b, &c);
    if (a == -1 && b == -1 && c == -1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
  }
}
