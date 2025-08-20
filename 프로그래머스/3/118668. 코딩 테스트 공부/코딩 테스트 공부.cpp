#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) 
{
    int answer = 0;
    
    int alpMax = alp;
    int copMax = cop;
    
    for (auto& problem : problems)
    {
        alpMax = max(alpMax, problem[0]);
        copMax = max(copMax, problem[1]);
    }
    
    vector<vector<int>> dijkDistVec(alpMax+1, vector<int>(copMax+1, 1000));
    vector<vector<bool>> visited(alpMax+1, vector<bool>(copMax+1, false));
    
    problems.push_back({0,0,1,0,1});
    problems.push_back({0,0,0,1,1});

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    dijkDistVec[alp][cop] = 0;
    pq.push({dijkDistVec[alp][cop], alp, cop});
    
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int topAlp = top[1];
        int topCop = top[2];
        int currCost = top[0];
        if (visited[topAlp][topCop]) continue;
        visited[topAlp][topCop] = true;
        for (auto& problem : problems)
        {
            if (topAlp < problem[0] || topCop < problem[1]) continue;
            int nAlp = min(alpMax, topAlp + problem[2]);
            int nCop = min(copMax, topCop + problem[3]);
            dijkDistVec[nAlp][nCop] = min(dijkDistVec[topAlp][topCop] + problem[4], dijkDistVec[nAlp][nCop]);
            pq.push({dijkDistVec[nAlp][nCop], nAlp, nCop});
        }
    }
    
    return dijkDistVec[alpMax][copMax];
}
