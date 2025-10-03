#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

int N,M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 그래프 초기화
    vector<vector<int>> graph(N+1);

    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //방문하지 않은 노드들의 목록을 만든다.
    set<int> unvisited;
    vector<int> groups;
    for(int i=1; i<=N; i++) unvisited.insert(i); 

    // 각 노드에 대해서 BFS
    // 각 노드의 인접 노드를 방문하면서 연결되지 않은 노드를 기록
    for(int i=1; i<=N; i++)
    {

        // i번 노드를 시작점으로

        if (unvisited.count(i) == 0) continue;
        
        //BFS 진행
        queue<int> q;
        q.push(i);
        unvisited.erase(i);
        int groupSize = 1;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            // 현재 노드의 인접노드들
            set<int> adj(graph[u].begin(), graph[u].end());

            vector<int> temp;
            // 방문하지 않은 노드중 현재 노드까지의 경로가 없는 경우를 추가.
            for (auto v : unvisited)
            {
                if (adj.count(v) == 0)
                {
                    temp.push_back(v);
                }
            }

            // 위의 경우 (경로가 없어서 한 그룹으로 묶어야) 같은 그룹에 추가
            for (auto v : temp)
            {
                q.push(v);
                unvisited.erase(v);
                groupSize++;
            }
        }

        // 그룹 추가
        groups.push_back(groupSize);
    }

    sort(groups.begin(), groups.end());

    cout << groups.size() << "\n";
    for (auto v : groups)
    cout << v << " ";
    
    return 0;
}

