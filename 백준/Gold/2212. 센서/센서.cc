#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

int N;
int K;

// 거리가 짧은거 끼리 묶자
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin >> K;
    vector<int> vec;
    set<int> s;
    for (int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    vec = vector<int>(s.begin(), s.end());
    vector<int> rightDist;

    // 자신의 오른쪽에 있는 센서와의 거리 (연결)
    for (int i=0; i<vec.size()-1; i++)
    {
        rightDist.push_back(vec[i+1] - vec[i]);
    }
    
    sort(rightDist.begin(), rightDist.end());

    // 원형이 아닌 무언가를 k 개의 그룹으로 나누려면
    // k-1번 조합을 끊으면 된다.
    // 직사각형을 3개의 직사각형으로 나누려면? -> 2번 잘라야함
    // 연결을 K-1번 끊기
    for (int i=0; i<K-1; i++)
    {
        if (rightDist.size() == 0)
            break;
        rightDist.pop_back();
    }

    int answer = 0;
    // 남아있는 연결의 값을 더하기
    if (rightDist.size() != 0)
        answer = accumulate(rightDist.begin(), rightDist.end(), 0);
    cout << answer << '\n';
    return 0;
}
