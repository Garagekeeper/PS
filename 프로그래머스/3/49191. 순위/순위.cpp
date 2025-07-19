#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

unordered_map<int, vector<int>> winList;
unordered_map<int, vector<int>> loseList;
int N;

int bfs(int start, unordered_map<int, vector<int>> adjList)
{
    vector<bool> visited(N+1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto& v : adjList[u])
        {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    
    int cnt=0;
    for (int i=1; i<N+1; i++)
    {
        if(visited[i]) cnt++;
    }
    
    return cnt - 1;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    N = n;
    for (auto& result : results)
    {
        int A = result[0];
        int B = result[1];
        winList[A].push_back(B);
        loseList[B].push_back(A);
    }

    for (int i=1; i<N+1; i++)
    {
        int iWinCnt = bfs(i, winList);
        int iLoseCnt = bfs(i, loseList);
        
        if ((iWinCnt + iLoseCnt) == N-1) answer++;
    }
   
    return answer;
}