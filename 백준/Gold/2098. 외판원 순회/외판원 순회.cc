#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 987654321; // 무한대를 나타내는 값

int N; // 도시의 수
vector<vector<int>> W; // 도시 간 이동 비용 행렬
vector<vector<int>> dp; // DP 테이블

// current_city: 현재 도시
// visited_mask: 지금까지 방문한 도시들의 집합 (비트마스킹)
int tsp(int current_city, int visited_mask)
{
    // 모든 도시를 방문했을 경우
    if (visited_mask == (1 << N) - 1)
    {
        // 마지막 도시에서 시작 도시로 돌아갈 수 있는 경우
        if (W[current_city][0] != 0)
        {
            return W[current_city][0];
        }
        // 돌아갈 수 없는 경우 (무한대)
        else
        {
            return INF;
        }
    }

    if (dp[visited_mask][current_city] != -1)
    {
        return dp[visited_mask][current_city];
    }

    // 최소 비용을 INF로 초기화
    int min_cost = INF;

    // 다음 방문할 도시 탐색
    for (int next_city = 0; next_city < N; ++next_city)
    {
        if (!(visited_mask & (1 << next_city)) && W[current_city][next_city] != 0)
        {
            // 현재까지의 비용 + 다음 도시로 가는 비용 + 다음 도시에서 나머지 경로를 탐색하는 비용
            int new_cost = W[current_city][next_city] + tsp(next_city, visited_mask | (1 << next_city));
            min_cost = min(min_cost, new_cost);
        }
    }

    return dp[visited_mask][current_city] = min_cost;
}

int main()
{
    cin >> N;

    W.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> W[i][j];
        }
    }

    // visited_mask는 1 << N - 1까지, city는 0부터 N-1까지
    dp.resize(1 << N, vector<int>(N, -1));

    cout << tsp(0, 1) << "\n";

    return 0;
}