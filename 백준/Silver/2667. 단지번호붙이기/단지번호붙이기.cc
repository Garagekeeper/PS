#include <bits/stdc++.h>

int n;
int cnt = 0;
int arr[25][25];
bool arr2[25][25];
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int i, int j) {
  for (int k = 0; k < 4; k++) {
    int ni = i + move[k][0];
    int nj = j + move[k][1];

    if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
      if (!arr2[ni][nj] && arr[ni][nj] == 1) {
        arr2[ni][nj] = 1;
        cnt++;
        dfs(ni, nj);
      }
    }
  }
}

int main() {
  std::vector<int> vec;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 한글자씩
      scanf("%1d", &arr[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!arr2[i][j] && arr[i][j] == 1) {
        arr2[i][j] = 1;
        cnt++;
        dfs(i, j);
        vec.push_back(cnt);
        cnt = 0;
      }
    }
  }
  sort(vec.begin(), vec.end());
  printf("%d\n", vec.size());
  for (auto a : vec) {
    printf("%d\n", a);
  }
}
