#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<bool> visited;
//0: min Dist,  1: node right before this
vector<vector<int>> dijkstraVec;
unordered_map<int, vector<pair<int,int>>> adjList;
int GN;

void Dijkstra(int start)
{
    dijkstraVec.resize(GN, vector<int>(2, INT_MAX));
    dijkstraVec[start][0] = 0;
    dijkstraVec[start][1] = 1;
    
    visited.resize(GN,false);
    
    // dist, nodeNum
    // 비용이 낮은게 위로 오도록
    auto cmp = [](const pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    pq.push({0,start});
    
    while(!pq.empty())
    {
        auto [dist, currentNode] = pq.top(); pq.pop();
        
        if (visited[currentNode]) continue;
        visited[currentNode] = true;
        
        for (auto& [v, weight] : adjList[currentNode])
        {
            int startToCurrnetNode = dijkstraVec[currentNode][0];
            int startToV = dijkstraVec[v][0];
            int currnetNodeToV = weight;
            
            if (startToV > startToCurrnetNode + currnetNodeToV)
            {
                dijkstraVec[v][0] = startToCurrnetNode + currnetNodeToV;
                dijkstraVec[v][1] = currentNode;
                pq.push({dijkstraVec[v][0], v});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    GN = N + 1;
    
    for (auto& edge : road)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
        adjList[edge[1]].push_back({edge[0], edge[2]});
    }
    
    Dijkstra(1);

    for (int i = 1; i < GN; i++)
    {
        if (dijkstraVec[i][0] <= K) answer++;
    }
    
    return answer;
}