#include <bits/stdc++.h>
#define MAX -1000000000;
#define MIN 1000000000;

int num[11];
int op[4];
int n;
int max = MAX;
int min = MIN;

void dfs(int step, int res) {
  if (step == n) {
    max = std::max(res, max);
    min = std::min(res, min);
  }

  for (int i = 0; i < 4; i++) {
    if (op[i] != 0) {
      op[i]--;
      switch (i) {
        case 0:dfs(step + 1, res + num[step]);
          break;
        case 1:
          dfs(step + 1, res - num[step]);
          break;
        case 2:
          dfs(step + 1, res * num[step]);
          break;
        case 3:
          dfs(step + 1, res / num[step]);
          break;
      }
      op[i]++;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }

  for (int i = 0; i < 4; i++) {
    scanf("%d", &op[i]);
  }

  dfs(1, num[0]);
  printf("%d\n", max);
  printf("%d\n", min);
}