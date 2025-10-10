#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int V,E;
unordered_map<int ,vector<int>> graph;
vector<int> visited;
set<pair<int, int>> plist;
int ftime=1;
int dfs(int n, int parent)
{

    visited[n] = ftime++;
    int ret = visited[n];
    for (auto v : graph[n])
    {
        if (v == parent) continue;
        if (visited[v] != 0)
        {
            ret = min(ret, visited[v]);
            continue;
        }

        int subtree = dfs(v, n);
        ret = min(ret, subtree);

        // 서브 트리의 순번이 부모보다 큰 경우 브릿지임
        if (subtree > visited[n])
        {
            plist.insert({min(n,v), max(n,v)});
        }
    }
       
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i=0; i<E; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.resize(V+1,0);

    dfs(1, 0);

    cout << plist.size() << "\n";
    for (auto p : plist)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
