#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

int N,M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    unordered_set<int> unvisited;
    vector<int> groups;
    for(int i=1; i<=N; i++) unvisited.insert(i); 

    for(int i=1; i<=N; i++)
    {
        if (unvisited.count(i) == 0) continue;
        
        queue<int> q;
        q.push(i);
        unvisited.erase(i);
        int groupSize = 1;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            unordered_set<int> adj(graph[u].begin(), graph[u].end());

            vector<int> temp;
            for (auto v : unvisited)
            {
                if (adj.count(v) == 0)
                {
                    temp.push_back(v);
                }
            }

            for (auto v : temp)
            {
                q.push(v);
                    unvisited.erase(v);
                    groupSize++;
            }
        }

        groups.push_back(groupSize);
    }

    sort(groups.begin(), groups.end());

    cout << groups.size() << "\n";
    for (auto v : groups)
    cout << v << " ";
    
    return 0;
}

