#include <bits/stdc++.h>
#define MAX 100001

int n, k, r;
bool visited[MAX];
std::vector<int> graph[MAX];

void bfs(int r) {
  std::queue<int> q;
  q.push(r);
  visited[r] = 1;
  printf("%d ", r);

  while (!q.empty()) {
    int temp = q.front();
    q.pop();

    for (int i = 0; i < graph[temp].size(); i++) {
      int s = graph[temp][i];
      if (!visited[s]) {
        q.push(s);
        visited[s] = 1;
        printf("%d ", s);
      }
    }
  }
}

void dfs(int r) {
  if (visited[r] == 1) return;
  visited[r] = 1;
  printf("%d ", r);
  for (int i = 0; i < graph[r].size(); i++) {
    dfs(graph[r][i]);
  }
}

int main() {
  scanf("%d %d %d", &n, &k, &r);
  while (k--) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(r);
  printf("\n");
  for (int i = 0; i <= n; i++) visited[i] = 0;
  bfs(r);
  printf("\n");
}
