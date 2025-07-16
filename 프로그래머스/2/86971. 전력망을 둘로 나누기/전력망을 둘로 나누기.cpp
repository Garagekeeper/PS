#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> visited;
unordered_map<int, vector<int>> adjList;
int answer = INT_MAX;
int dfs(int start)
{
    int cnt = 1;
   
    if (visited[start]) return 0;
    visited[start] = true;
    for (auto& v : adjList[start])
    {
        cnt += dfs(v);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    for (auto& wire : wires)
    {
        adjList[wire[0]].push_back(wire[1]);
        adjList[wire[1]].push_back(wire[0]);
    }
    
    
    for (auto& wire : wires)
    {
        cout << wire[0] << wire[1];
        adjList[wire[0]].erase(find(adjList[wire[0]].begin(), adjList[wire[0]].end(), wire[1]));
        adjList[wire[1]].erase(find(adjList[wire[1]].begin(), adjList[wire[1]].end(), wire[0]));
        
        visited.clear();
        visited.resize(n+1, false);
        
        
        int countA = dfs(1);
        //cout << "cntA :" <<countA << endl;
        if (countA == n) continue;
        
        int countB = n - countA;
        
        answer = min(answer, abs(countA - countB));
        
        adjList[wire[0]].push_back(wire[1]);
        adjList[wire[1]].push_back(wire[0]);
        
    }
    return answer;
}