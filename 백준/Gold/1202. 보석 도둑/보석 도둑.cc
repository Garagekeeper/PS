/*
보석을 가치가 높은 순으로 정렬
용량이 작은 가방부터 들어갈 수 있는 모든 보석을 최대 힙에 넣고 가장 가치가 높은 것을 채택. 이를 위해 보석과 가방의 무게와 허용 무게를 오름차순 정렬해야 함.
가방 용량이 커질수록 들어갈 수 있는 보석은 많아진다. 그러나 여전히 가치가 높은 것을 채택(우선순위 큐)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> gems(N);
    for (int i = 0; i < N; i++) {
        std::cin >> gems[i].first >> gems[i].second;
    }
    
    std::vector<int> bags(K);
    for (int i = 0; i < K; i++) {
        std::cin >> bags[i];
    }

    std::sort(gems.begin(), gems.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    std::sort(bags.begin(), bags.end());

    long long total_value = 0;
    int j = 0;
    std::priority_queue<int> pq;
    for (int i = 0; i < K; i++) {
        while (j < N && gems[j].first <= bags[i]) {
            pq.push(gems[j].second);
            j++;
        }

        if (!pq.empty()) {
            total_value += pq.top();
            pq.pop();
        }
    }

    std::cout << total_value;

    return 0;
}