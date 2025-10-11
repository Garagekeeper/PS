#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
const int INF = 1e8;
int N, M;
vector<int> parent;
vector<vector<int>> graph;
map<int, vector<int>> group; 

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A == B)
        return;
    
    parent[B] = A;

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    graph = vector<vector<int>>(N+1, vector<int>(N+1, INF));
    parent = vector<int>(N+1,0);
    for (int i=1; i<=N; i++)
    {
        parent[i] = i;
        graph[i][i] = 0;
    }

    for(int i=0; i<M; i++)
    {
        int u, v;
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
                if (graph[i][k] == INF) continue;
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
        
    }
    
    cout << group.size() << "\n";
    vector<int> ans;
    for (auto g : group)
    {
        auto& key = g.first;
        auto& val = g.second;
        int best_dist = INF;
        int rep = -1;
        for (auto from : val)
        {
            int maxdist = 0;
            for (auto to : val)
            {
                if (from == to) continue;
                maxdist = max(maxdist, graph[from][to]);
            }

            if (maxdist < best_dist)
            {
                best_dist = maxdist;
                rep = from;
            }
        }
        
       ans.push_back(rep);
    }
    
    sort(ans.begin(), ans.end());
    for (auto e : ans)
        cout << e << "\n";

    return 0;
}
