#include <bits/stdc++.h>

int arr[1001][3];
int min;
int n;

int main() {
  scanf("%d", &n);
  int check = -1;

  for (int i = 1; i <= n; i++) {
    int r, g, b;
    scanf("%d", &r);
    scanf("%d", &g);
    scanf("%d", &b);
    arr[i][0] = std::min(arr[i - 1][1], arr[i - 1][2]) + r;
    arr[i][1] = std::min(arr[i - 1][0], arr[i - 1][2]) + g;
    arr[i][2] = std::min(arr[i - 1][0], arr[i - 1][1]) + b;
  }

  min = std::min(arr[n][0], std::min(arr[n][1], arr[n][2]));
  printf("%d\n", min);
}
