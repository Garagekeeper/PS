#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

vector<bool> visited;
// 0: minDist, 1: node right before this
vector<vector<int>> dijkstraVec;
unordered_map<int, vector<pair<int,int>>> adjList;

void Dijkstra(int N, int start)
{
    visited.resize(N+1, false);
    dijkstraVec.resize(N+1, vector<int>(2, INT_MAX));
    priority_queue<pair<int, int>> pq;
    
    dijkstraVec[1][0] = 0;
    dijkstraVec[1][1] = 1;
    
    pq.push({1,start});
    while(!pq.empty())
    {
        int nodeNum = pq.top().first;
        int currDist = pq.top().second;
        pq.pop();

        for (auto& [to, weight] : adjList[nodeNum])
        {
            if (dijkstraVec[to][0] > dijkstraVec[nodeNum][0] + weight)
            {
                dijkstraVec[to][0] = dijkstraVec[nodeNum][0] + weight;
                dijkstraVec[to][1] = nodeNum;
                pq.push({to, dijkstraVec[to][0]});
            }
        }
    }
    
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for (auto& vec : road)
    {
        for (auto& [to, weight] : adjList[vec[0]])
        {
            if (to == vec[1]) weight = min (weight, vec[2]);
            continue;
        }
        
        adjList[vec[0]].push_back({vec[1], vec[2]});
        adjList[vec[1]].push_back({vec[0], vec[2]});
    }
    
    Dijkstra(N, 1);
    
    for (int i=1; i<N+1; i++)
    {
        if (dijkstraVec[i][0] <= K) answer++;
    }

    return answer;
}