#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;  // 최대로 필요한 인원수 + 1 (초기값)
    int len = weak.size();

    // 원형을 직선처럼 만들기 위해 weak를 두 배로 늘림
    for (int i = 0; i < len; ++i) {
        weak.push_back(weak[i] + n);
    }

    sort(dist.begin(), dist.end());  // 순열을 위한 정렬

    do {
        // weak의 각 지점에서 출발할 수 있음
        for (int start = 0; start < len; ++start) {
            int friendIdx = 0;
            int position = weak[start] + dist[friendIdx];

            for (int i = start; i < start + len; ++i) {
                if (weak[i] > position) {
                    ++friendIdx;
                    if (friendIdx >= dist.size()) break;
                    position = weak[i] + dist[friendIdx];
                }
            }

            if (friendIdx < answer) {
                answer = friendIdx + 1;
            }
        }

    } while (next_permutation(dist.begin(), dist.end()));

    if (answer > dist.size()) return -1;
    return answer;
}
