#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

int N, K;
unordered_map<int, queue<int>> timeMap;
struct Cmp
{
    bool operator()(const int& a, const int& b)
    {
        // a가 더이상 나오지 않는 경우 a를 먼저
        if (timeMap[a].size() == 0 && timeMap[b].size() != 0) return false;
        // b가 더이상 나오지 않는 경우 b를 먼저
        if (timeMap[a].size() != 0 && timeMap[b].size() == 0) return true;
        // 둘다 나오지 않는 경우 상관없음
        if (timeMap[a].size() == 0 && timeMap[b].size() == 0) return false;
        // 둘 중 더 늦게 나오는데 앞으로
        // true면 b가 우선
        return (timeMap[a].front() < timeMap[b].front());
    }
};

// 가장 늦게 나오는걸 먼저 뽑자!
int main()
{
    cin >> N >> K;
    
    vector<int> cntVec (K+1);
    vector<int> seq;
    unordered_set<int> plugged;
    
    for (int i=1; i<=K; i++)
    {
        int name;
        cin >> name;
        timeMap[name].push(i-1);
        seq.push_back(name);
    }

    int cnt = 0;
    for (int i=0; i<seq.size(); i++)
    {
        // 현재 시점 삭제
        timeMap[seq[i]].pop();

        // 이미 있는거면 넘어감
        if (plugged.find(seq[i]) != plugged.end()) continue;

        // 꽉 찬 경우
        if (plugged.size() == N)
        {
            // 지금 이후로 가장 늦게 등장하는 걸 뽑음
            priority_queue<int, vector<int> , Cmp>pq (plugged.begin(), plugged.end());
            int top = pq.top();
            plugged.erase(top);
            cnt++;
        }

        // seq[i] 기기 플러그 꼽기
        plugged.insert(seq[i]);
        
    }

    cout << cnt << '\n';

    return 0;
}
