#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, vector<int>> tree;
vector<bool> visited;
vector<int> ginfo;
int answer = 0;

void dfs(vector<int> path)
{
    int sheepCnt=0;
    int wolfCnt=0;
    
    //현재 경로의 늑대와 양의 개수를 종합
    for (auto& p : path)
    {
        if (ginfo[p] == 1) wolfCnt++;
        else sheepCnt++;
    }
    
    // 늑대가 같거나 많은 경우는 경로 폐기
    if (wolfCnt >= sheepCnt) return;
    
    // 양의 최댓값 갱신
    answer = max(sheepCnt, answer);
    
    // 무작정 DFS를 하는게 아니라
    // 현재 경로에 있는 노드들의 인접노드중 방문되지 않은걸 찾아서 새롭게 dfs
    for (int i=0; i<path.size(); i++)
    {
        int p = path[i];
        for (auto& v : tree[p])
        {
            // 이미 방문한 경우 통과 (현재 경로에 포함된 경우)
            if (visited[v]) continue;
            visited[v] = true;
            // 방문하지 않은 인접노드를 경로에 추가하고 DFS
            path.push_back(v);
            dfs(path);
            // v를 넣고 모든 경우의 수를 탐색한 뒤에는
            // v를 미방문 표시
            path.pop_back();
            visited[v] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    ginfo = info;
    visited.resize(info.size());
    // 트리 정보 추가
    // 인접 리스트 형태로 보관
    for (auto& edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
    }
    visited[0] = true;
    dfs({0});
    
    return answer;
}