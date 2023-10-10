#include <bits/stdc++.h>

int n, m;
int num;
int sum[100001];

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &num);
    sum[i] = sum[i - 1] + num;
  }

  while (m--) {
    int i, j;
    scanf("%d %d", &i, &j);
    printf("%d\n", (sum[j] - sum[i - 1]));
  }
}
