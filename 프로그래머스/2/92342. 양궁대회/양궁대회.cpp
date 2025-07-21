#include <vector>
#include <algorithm>
using namespace std;

int maxDiff = 0;
vector<int> answer;

void dfs(int idx, int arrowsLeft, vector<int>& ryan, const vector<int>& appeach) {
    if (idx == 11) {
        if (arrowsLeft > 0) ryan[10] += arrowsLeft; // 남은 화살 마지막에 몰아주기

        int ryanScore = 0, appeachScore = 0;
        for (int i = 0; i < 11; ++i) {
            if (ryan[i] > appeach[i]) ryanScore += 10 - i;
            else if (appeach[i] > 0) appeachScore += 10 - i;
        }

        if (ryanScore > appeachScore) {
            int diff = ryanScore - appeachScore;
            if (diff > maxDiff || 
                (diff == maxDiff && lexicographical_compare(answer.rbegin(), answer.rend(), ryan.rbegin(), ryan.rend()))) {
                maxDiff = diff;
                answer = ryan;
            }
        }

        if (arrowsLeft > 0) ryan[10] -= arrowsLeft; // 원상복구
        return;
    }

    // 화살 쏘기
    if (arrowsLeft > appeach[idx]) {
        ryan[idx] = appeach[idx] + 1;
        dfs(idx + 1, arrowsLeft - ryan[idx], ryan, appeach);
        ryan[idx] = 0; // 백트래킹
    }

    // 안 쏘기
    dfs(idx + 1, arrowsLeft, ryan, appeach);
}

vector<int> solution(int n, vector<int> info) {
    answer = {-1};
    vector<int> ryan(11, 0);
    dfs(0, n, ryan, info);
    return answer;
}