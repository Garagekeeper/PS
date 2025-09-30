#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

int main()
{
    cin >> N;
    //x,y 순서
    vector<pair<long long, long long>> pointsVec;

    //y,x 순서
    set<pair<int,int>> activeSet;

    while(N--)
    {
        long long x, y;
        cin >> x >> y;
        pointsVec.push_back({x,y});
    }

    //x좌표를 기준으로 정렬
    sort(pointsVec.begin(), pointsVec.end());
    pointsVec.erase(unique(pointsVec.begin(), pointsVec.end()),pointsVec.end());

    activeSet.insert({pointsVec[0].second, pointsVec[0].first});
    activeSet.insert({pointsVec[1].second, pointsVec[1].first});

    long long dy = pointsVec[1].second - pointsVec[0].second;
    long long dx = pointsVec[1].first - pointsVec[0].first;
    long long d = dy*dy + dx*dx;
    int left = 0;

    for (int i=2; i<pointsVec.size(); i++)
    {
        // 기존에 점들 중에서 최소거리보다 x의 차이가 크면 제외
        // x의 차이가 유클리드 거리의 차 보다 크면
        while (left < i)
        {
            int dx = pointsVec[i].first - pointsVec[left].first; 
            if (dx * dx > d)
            {
                activeSet.erase({pointsVec[left].second, pointsVec[left].first});
                left++;
            }
            else 
            {
                break;
            }
        }

        auto lower = activeSet.lower_bound({pointsVec[i].second - sqrt(d) ,-INT_MAX});
        auto upper = activeSet.upper_bound({pointsVec[i].second + sqrt(d) ,INT_MAX});

        for (auto it = lower; it != upper; it++)
        {
            long long dy = it->first - pointsVec[i].second;
            long long dx = it->second - pointsVec[i].first;
            d = min(d, dx*dx + dy*dy);
        }
        activeSet.insert({pointsVec[i].second,pointsVec[i].first});
    }

    cout << d;

}