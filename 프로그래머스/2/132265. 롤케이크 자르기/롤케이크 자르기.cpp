#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> rightCount;
    unordered_map<int, int> leftCount;
    int answer = 0;

    // 초기에는 모든 토핑이 오른쪽에 있음
    for (int t : topping) {
        rightCount[t]++;
    }

    for (int i = 0; i < topping.size(); ++i) {
        int t = topping[i];
        leftCount[t]++;
        rightCount[t]--;

        if (rightCount[t] == 0) {
            rightCount.erase(t);
        }

        if (leftCount.size() == rightCount.size()) {
            answer++;
        }
    }

    return answer;
}