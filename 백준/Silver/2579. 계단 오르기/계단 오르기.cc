#include <bits/stdc++.h>

long long arr[301][2];
long long max = 0;
int n;

int main() {
  int cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int temp;
    scanf("%d", &temp);
    if (i == 1)
      arr[i][0] = temp, arr[i][1] = temp;
    else if (i == 2)
      arr[i][0] = arr[i - 1][1] + temp, arr[i][1] = temp;
    else {
      arr[i][0] = arr[i - 1][1] + temp;
      arr[i][1] = std::max(arr[i - 2][0], arr[i - 2][1]) + temp;
    }
  }

  printf("%d\n", std::max(arr[n][0], arr[n][1]));
}
