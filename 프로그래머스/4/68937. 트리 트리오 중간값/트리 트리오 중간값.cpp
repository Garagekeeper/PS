#include <vector>
#include <queue>
using namespace std;

// BFS 결과: (가장 먼 거리, 가장 먼 노드 목록)
pair<int, vector<int>> bfs(int start, const vector<vector<int>>& adj, int n) {
    vector<bool> vis(n+1, false);
    queue<pair<int,int>> q;
    q.push({start, 0});
    vis[start] = true;

    int maxDist = 0;
    vector<int> farthest;

    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        if (d > maxDist) {
            maxDist = d;
            farthest.clear();
            farthest.push_back(u);
        } else if (d == maxDist) {
            farthest.push_back(u);
        }
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({v, d + 1});
            }
        }
    }
    return {maxDist, farthest};
}

int solution(int n, vector<vector<int>> edges) 
{
    vector<vector<int>> adj(n + 1);
    for (auto& e : edges) 
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    auto [d1, far1] = bfs(1, adj, n);
    auto [d2, far2] = bfs(far1[0], adj, n);

    if (far2.size() > 1) return d2;  
    auto [d3, far3] = bfs(far2[0], adj, n);
    if (far3.size() > 1) return d3;  
    return d3 - 1;                   
}
