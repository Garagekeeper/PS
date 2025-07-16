#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <iostream>
using namespace std;
vector<vector<int>> dijkstraVec;
unordered_map<int, vector<int>> adjList;
vector<bool> visited;
int N;
void Dijkstra(int start)
{
    dijkstraVec.resize(N+1, vector<int>(2,INT_MAX));
    visited.resize(N+1, false);
    dijkstraVec[start][0] = 0;
    dijkstraVec[start][1] = start;
    // dist, node;
    queue<pair<int, int>> q;
    q.push({0,start});
    
    while(!q.empty())
    {
        auto [dist, currNode] = q.front(); q.pop();
        
        if (visited[currNode]) continue;
        visited[currNode]= true;
        
        for (auto& v : adjList[currNode])
        {
            int start2v = dijkstraVec[v][0];
            int start2curr = dijkstraVec[currNode][0];
            int curr2v = 1;
            
            if (start2v > start2curr + curr2v)
            {
                dijkstraVec[v][0] = start2curr + curr2v;
                dijkstraVec[v][1] = currNode;
                q.push({dijkstraVec[v][0], v});
            }
        }
    }    
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N=n;
    
    for (auto& e : edge)
    {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }
    
    Dijkstra(1);
    
    int maxDist = 0;
    for (int i=1; i < N+1; i++)
    {
        maxDist = max(maxDist, dijkstraVec[i][0]);
    }
    
    for (int i=1; i < N+1; i++)
    {
        if (dijkstraVec[i][0] == maxDist) answer++;
    }
    
    return answer;
}