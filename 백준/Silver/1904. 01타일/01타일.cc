#include <bits/stdc++.h>

int abc[1000000];

int t(int n) {
  abc[1] = 1;
  abc[2] = 2;

  for (int i = 3; i <= n; i++) {
    abc[i] = ((abc[i - 1] + abc[i - 2])) % 15746;
  }

  return abc[n];
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(NULL);

  int n;
  scanf("%d", &n);
  printf("%d\n", t(n));
}
