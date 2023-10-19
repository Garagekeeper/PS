#include <bits/stdc++.h>
#define MAX 100001

int n, k, r;
bool visited[MAX];
int result[MAX];
int cnt = 0;
std::vector<int> graph[MAX];

void bfs(int r) {
  std::queue<int> q;
  q.push(r);
  visited[r] = 1;
  result[r]  = ++cnt;

  while (!q.empty()) {
    int temp = q.front();
    q.pop();

    for (int i = 0; i < graph[temp].size(); i++) {
      int s = graph[temp][i];
      if (!visited[s]) {
        q.push(s);
        visited[s] = 1;
        result[s]  = ++cnt;
      }
    }
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

  bfs(r);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", result[i]);
  }
}
