#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<bool> visited;
vector<vector<int>> Gdungeons;
int answer = -1;
int N;
int dfs(int k, int depth)
{
    // 탐색의 깊이가 던전의 개수보다 많으면 종료
    if (N == depth) return depth;


    for (int i=0; i<N; i++)
    {
      if (visited[i] || k < Gdungeons[i][0]) continue;
      visited[i] = true;
      answer = max(answer, dfs(k - Gdungeons[i][1], depth + 1));
      visited[i] = false;
    }
    return depth;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    Gdungeons = dungeons;
    N = dungeons.size();
    visited.resize(N, false);
    dfs(k, 0);
    return answer;
        
}
