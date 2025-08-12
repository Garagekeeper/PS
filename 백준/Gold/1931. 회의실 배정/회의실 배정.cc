#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

// 가장 빨리 끝나는 회의를 먼저 고른다.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0, ans = 1;

    cin >> N;
    vector<pair<int,int>> timeVec(N);
    for (int i=0; i<N; i++)
        cin >> timeVec[i].first >> timeVec[i].second;

    sort(timeVec.begin(), timeVec.end(), 
    [](const pair<int, int>& a, const pair<int, int>&b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int frontEndTime = timeVec[0].second; 

    for (int i=1; i<N; i++)
    {
        if (frontEndTime > timeVec[i].first && frontEndTime <= timeVec[i].second) continue;
    
        ans++;
        frontEndTime = timeVec[i].second;
    }

    cout << ans;
    return 0;
}
