#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int N;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

// 빨리 끝나는 강의부터 일단 강의실을 주자.
int main()
{
    cin >> N;
    vector<int> startTime(N);
    vector<int> endTime(N); 

    for (int i=0; i<N; i++)
    {
        int start;
        int end;
        cin >> startTime[i] >> endTime[i];
    }

    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());

    int startIndex = 0, endIndex = 0;
    int usedRoomCnt = 0, answer = 0;

    while(startIndex < N)
    {
        // 현재 상황에서
        // 가장 빨리 시작하는 시간이 가장 빨리 끝나는 것보다 작으면
        // ( startIndex번째 강의는 아직 진행중 )
        if (startTime[startIndex] < endTime[endIndex])
        {
            // 사용중인 강의실 수(동시 진행 중인 강의 수) 증가
            usedRoomCnt++;
            // 값 갱신
            answer = max(answer, usedRoomCnt);
            // 다음 시작 시간에 대해서 확인
            startIndex++;
        }
        // 시작 시간이 가장 빨리 끝나는 시간 이후
        // 겹치지 않음
        else 
        {
            // 사용중인 강의실 수 감소
            usedRoomCnt--;
            // 다음 종료 시간에 대해서 확인
            endIndex++;
        }
    }

    cout << answer << '\n';

    return 0;
}
