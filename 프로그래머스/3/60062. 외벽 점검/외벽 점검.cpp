#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;
unordered_map<long long, int> cache;
vector<int> gweak;
vector<int> gdist;
vector<bool> visited;
vector<bool> uvisited;
int N;
int answer = INT_MAX;
//비트마스크를 통한 중복 제거
void dfs(int index, int cnt)
{
    if (cnt > answer) return;
    long long key = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i]) key |= 1LL << (i + 8);
    }
    for (int i = 0; i < uvisited.size(); i++) {
        if (uvisited[i]) key |= 1LL << i;
    }

    if (cache.count(key) && cache[key] <= cnt) return;
    cache[key] = cnt;

    if (all_of(visited.begin(), visited.end(), [](bool x){return x == true;}))
    {
        answer = min(answer, cnt);
        return;
    }
    
    for (int i = index; i < gdist.size(); i++)
    {
        if (uvisited[i]) continue;
        uvisited[i] = true;
        for (int j=0; j<gweak.size(); j++)
        {
            if (visited[j]) continue;
            int start = gweak[j];
            int goal = start + gdist[i];
            
            auto backup = visited;
            for (int k=0; k<gweak.size(); k++)
            {
                int current = gweak[k];
                if (visited[k]) continue;
                if (start <= current && current <= goal)
                {
                    visited[k] = true;
                }
                else if (start <= current + N && current + N  <= goal)
                {
                    visited[k] = true;
                }
            }
            dfs(i+1, cnt + 1);
            visited = backup;
        }
        uvisited[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end(), greater<>());
    gweak = weak;
    gdist = dist;
    visited.resize(weak.size(), false);
    uvisited.resize(dist.size(), false);
    N = n;
    
    dfs(0,0);
    return answer == INT_MAX ? -1 : answer;
}