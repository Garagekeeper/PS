#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
using namespace std;

const int INF = 10e8;

vector<vector<int>> graph;
vector<int> parent;
map<int, vector<int>> group;

int N, M;

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);

    if (A == B) return;
    parent[A] = B;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    graph = vector<vector<int>>(N+1, vector<int>(N+1, INF));
    parent = vector<int>(N+1);
    for (int i=1; i<=N; i++)
        parent[i] = i;
    
    for (int i=0; i<M; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
        Union(u,v);
    }

    for (int i=1; i<=N; i++)
    {
        group[Find(i)].push_back(i);
    }

    for (int k=1; k<=N; k++)
    {
        for (int i=1; i<=N; i++)
        {
            for (int j=1; j<=N; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    set<int> ans;

    for (auto g : group)
    {
        auto key = g.first;
        auto& vec = g.second;

        int rep = -1;
        int best = INF;

        for (auto from : vec)
        {
            int max_dist = -1;
            for (auto to : vec)
            {
                if (from == to) continue;
                max_dist = max(max_dist, graph[from][to]);
            }

            if (best > max_dist)
            {
                best = max_dist;
                rep = from;
            }
        }
        ans.insert(rep);
    }

    cout << ans.size() << "\n";
    
    for (auto& e : ans)
    {
        cout << e << endl;
    }

    return 0;
}
