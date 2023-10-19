#include <bits/stdc++.h>
#define MAX 100001

int n, k, r;
bool visited[MAX];
int result[MAX];
int cnt = 0;
std::vector<int> graph[MAX];

void dfs(int r) {
  if (visited[r] == 1) return;
  visited[r] = 1;
  cnt++;
  result[r] = cnt;
  for (int i = 0; i < graph[r].size(); i++) {
    dfs(graph[r][i]);
  }
}

// decrease
bool cmp(int i, int j) { return j < i; }

int main() {
  scanf("%d %d %d", &n, &k, &r);
  while (k--) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end(), cmp);
  }
  dfs(r);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", result[i]);
  }
}
