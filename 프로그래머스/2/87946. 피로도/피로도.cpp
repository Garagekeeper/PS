#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> Gdungeons;
vector<bool> visited;
int answer = -1;
int N;
using namespace std;

void dfs(int k, int depth)
{
    answer = max(answer, depth);
    for (int i=0; i<N; i++)
    {

        if (visited[i]) continue;
        if (k < Gdungeons[i][0]) continue;
        
        visited[i] = true;
        dfs(k - Gdungeons[i][1], depth+1);
        visited[i] = false;
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    Gdungeons = dungeons;
    N = dungeons.size();
    visited.resize(N,false);
    dfs(k,0);
    return answer;
}