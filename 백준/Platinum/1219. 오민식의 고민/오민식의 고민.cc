#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int from, to, cost;
};

int N, start, dest, M;
vector<Edge> edges;
long long dist[50];
int income[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> start >> dest >> M;
    edges.resize(M);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    for (int i = 0; i < N; i++) {
        cin >> income[i];
    }

    fill(dist, dist + N, -INF);
    dist[start] = income[start];

    // 벨만-포드 N-1번 반복
    for (int i = 0; i < N - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.from] == -INF) continue;
            long long cost = dist[e.from] - e.cost + income[e.to];
            if (cost > dist[e.to]) dist[e.to] = cost;
        }
    }

    // N번째 반복으로 사이클 후보 노드 체크
    vector<int> cycleNodes;
    for (auto &e : edges) {
        if (dist[e.from] == -INF) continue;
        long long cost = dist[e.from] - e.cost + income[e.to];
        if (cost > dist[e.to]) {
            dist[e.to] = cost;
            cycleNodes.push_back(e.to);
        }
    }

    // 사이클이 있는 노드가 dest까지 도달 가능한지 BFS
    vector<vector<int>> adj(N);
    for (auto &e : edges) adj[e.from].push_back(e.to);

    vector<bool> visited(N, false);
    queue<int> q;
    for (int node : cycleNodes) {
        q.push(node);
        visited[node] = true;
    }

    bool infinite = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == dest) {
            infinite = true;
            break;
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    if (dist[dest] == -INF) cout << "gg\n";
    else if (infinite) cout << "Gee\n";
    else cout << dist[dest] << "\n";

    return 0;
}
