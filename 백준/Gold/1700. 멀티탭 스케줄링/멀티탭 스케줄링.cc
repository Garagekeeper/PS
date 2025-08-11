#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
using namespace std;

int N, K;
unordered_map<int, int> cntMap;
unordered_map<int, deque<int>> timeMap;
struct Cmp
{
    bool operator()(const int& a, const int& b)
    {
        if (timeMap[a].size() == 0 && timeMap[b].size() != 0) return false;
        if (timeMap[a].size() != 0 && timeMap[b].size() == 0) return true;
        if (timeMap[a].size() == 0 && timeMap[b].size() == 0) return false;
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
    priority_queue<int, vector<int> , Cmp> pq;
    vector<vector<int>> devicetime(K+1);
    for (int i=1; i<=K; i++)
    {
        int name;
        cin >> name;
        timeMap[name].push_back(i-1);
        seq.push_back(name);
    }


    int cnt = 0;
    for (int i=0; i<seq.size(); i++)
    {
        timeMap[seq[i]].pop_front();

        if (plugged.find(seq[i]) != plugged.end()) continue;

        if (plugged.size() == N)
        {
            pq = priority_queue<int, vector<int> , Cmp>(plugged.begin(), plugged.end());
            int top = pq.top();
            plugged.erase(top);
            cnt++;
        }

        plugged.insert(seq[i]);
        
    }

    cout << cnt << '\n';

    return 0;
}
