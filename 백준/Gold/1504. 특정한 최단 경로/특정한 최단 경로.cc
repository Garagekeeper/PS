#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;

int N,E;
int u,v;
// dist, nodeNum
vector<vector<int>> dijkstraVec;
vector<bool> visited;
unordered_map<int, vector<pair<int, int>>> adjList;

void dijkcstra(int start)
{
    visited.clear();
    visited.resize(N+1,false);
    dijkstraVec.clear();
    dijkstraVec.resize(N+1,vector<int>(2, INT_MAX));
    dijkstraVec[start][0] = 0;
    dijkstraVec[start][1] = start;

    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
        return a.first > a.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.push({0, start});

    while (!pq.empty())
    {
        auto [dist, currNode] = pq.top(); pq.pop();

        for (auto [v, weight] : adjList[currNode])
        {
            int start2v = dijkstraVec[v][0];
            int start2currNode =  dijkstraVec[currNode][0];
            int currNode2v = weight;
            if (start2v > start2currNode + currNode2v)
            {
                dijkstraVec[v][0] = start2currNode + currNode2v;
                dijkstraVec[v][1] = currNode;
                pq.push({dijkstraVec[v][0], v});
            }
        }
    }
    
}

int main()
{
    
    cin >> N >> E;
    for (int i=0; i<E; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight});
    } 
    cin >> u >> v;
    if (adjList[u].size() == 0 || adjList[u].size() == 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    int start2u;
    int u2v;
    int v2E;

    int valA=0;
    int valB=0;
    dijkcstra(1);
    valA += dijkstraVec[u][0];
    valB += dijkstraVec[v][0];
    
    dijkcstra(u);
    if (dijkstraVec[v][0] == INT_MAX)
        valA = dijkstraVec[v][0];
    else 
        valA = valA + dijkstraVec[v][0];
   
    if (dijkstraVec[N][0] == INT_MAX)
        valB = dijkstraVec[N][0];
    else
        valB = valB + dijkstraVec[N][0];

    
    dijkcstra(v);
    if (dijkstraVec[N][0] == INT_MAX)
        valA = dijkstraVec[N][0];
    else 
        valA = valA + dijkstraVec[N][0];
   
    if (dijkstraVec[u][0] == INT_MAX)
        valB = dijkstraVec[u][0];
    else
        valB = valB + dijkstraVec[u][0];


    int answer=-1;
    if ((valA < 0 || valA == INT_MAX) && (valB < 0 || valB == INT_MAX)) answer = -1;
    else if ((valA < 0 || valA == INT_MAX))
    {
        answer = valB;
    }
    else if ((valB < 0 || valB == INT_MAX))
    {
        answer = valA;
    }
    else
    {
        answer = min(valA, valB);
    }
    
    cout << answer << "\n";

    return 0;
}