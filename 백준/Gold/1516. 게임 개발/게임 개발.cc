#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<int> buildTime(N + 1);         // 각 건물의 기본 건설 시간
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(N + 1, 0);       // 진입 차수
    vector<int> dp(N + 1, 0);         // 각 건물의 최종 건설 시간

    for (int i = 1; i <= N; ++i) 
    {
        cin >> buildTime[i];
        while (true) 
        {
            int pre;
            cin >> pre;
            if (pre == -1) break;
            graph[pre].push_back(i);  
            indegree[i]++;
        }
    }

    queue<int> q;

    // 진입 차수가 0인 건물부터 시작
    for (int i = 1; i <= N; ++i) 
        if (indegree[i] == 0) 
        {
            q.push(i);
            dp[i] = buildTime[i];
        }

    while (!q.empty()) 
    {
        int now = q.front();
        q.pop();

        for (int next : graph[now]) 
        {
            dp[next] = max(dp[next], dp[now] + buildTime[next]);
            indegree[next]--;
            if (indegree[next] == 0) 
                q.push(next);
        }
    }

    for (int i = 1; i <= N; ++i) 
    {
        cout << dp[i] << '\n';
    }

    return 0;
}