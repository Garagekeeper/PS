#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory.h>

using namespace std;

int N, M;
vector<int> matchedEmployee;
vector<bool> jobVisited;
unordered_map<int, vector<int>> jobGraph;

bool dfs(int employee)
{
    for (int job : jobGraph[employee])
    {
        if (jobVisited[job]) continue;
        jobVisited[job] = true;

        // 현재 작업에 매칭된 사람이 없거나
        // 기존에 매칭된 사람이 다른 직업에 매칭 가능하면
        // 매칭
        if (matchedEmployee[job] == 0 || dfs(matchedEmployee[job]))
        {
            matchedEmployee[job] = employee;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int answer = 0;
    cin >> N >> M;

    matchedEmployee.resize(M+1);
    jobVisited.resize(M+1);

    for (int i=1; i<=N; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j=0; j<cnt; j++)
        {
            int job;
            cin >> job;
            jobGraph[i].push_back(job);
        }
    }

    for (int i=1; i<=N; i++)
    {
        fill(jobVisited.begin(), jobVisited.end(), false);
        answer +=  dfs(i) ? 1 : 0;
    }
    
    cout << answer <<'\n';
    return 0;
}