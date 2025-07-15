#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> path;
unordered_map<int, vector<int>> treeList;
vector<int> visited;
int N = 0;
int answer = 0;

void dfs(vector<int>& info, vector<int> path)
{
    int sheep = 0, wolf = 0;
    
    for (auto& node : path)
    {
        if (info[node] == 1) wolf++;
        else sheep++;
    }
    
    // 조건을 만족하지 않는 경로는 폐기처리
    if (wolf >= sheep) return;
    
    answer = max(answer, sheep);
    
    for (int i=0; i<path.size(); i++)
    {   
        int node = path[i];
        for (auto& adjNode : treeList[node])
        {
            if (visited[adjNode]) continue;
            visited[adjNode] = true;
            path.push_back(adjNode);
            dfs(info, path);
            path.pop_back();
            visited[adjNode] = false;
        }
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    N = info.size();
    visited.resize(N,false);
    
    // 트리구조를 인접 리스트 형태로
    for (auto& edge : edges)
    {
        treeList[edge[0]].push_back(edge[1]);
    }
    
    dfs(info, {0});
    
    return answer;
}