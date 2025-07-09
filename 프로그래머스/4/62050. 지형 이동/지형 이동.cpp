#include <vector>
#include <queue>
#include <cmath> // abs 함수를 위해 필요

using namespace std;

// 우선순위 큐에 저장할 원소: {비용, 행, 열}
// 비용이 가장 낮은 것이 먼저 나오도록 greater<vector<int>> 사용
typedef priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> MinHeap;

int solution(vector<vector<int>> land, int height) {
    int n = land.size();
    
    // 방문 여부를 저장하는 배열
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    MinHeap pq;
    
    // 시작점 (0,0)은 비용이 0이므로 (0, 0, 0)으로 시작
    pq.push({0, 0, 0}); 
    
    int answer = 0;
    
    // 4방향 (상, 하, 좌, 우) 이동
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    // 모든 칸을 방문할 때까지 반복
    while (!pq.empty()) {
        vector<int> current = pq.top();
        pq.pop();
        
        int cost = current[0];
        int r = current[1];
        int c = current[2];
        
        // 이미 방문한 칸이면 스킵
        if (visited[r][c]) {
            continue;
        }
            
        // 방문 처리 및 비용 추가
        visited[r][c] = true;
        answer += cost;
        
        // 현재 칸에서 4방향으로 이동하며 다음 칸 탐색
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // 격자 범위 내에 있고 아직 방문하지 않은 칸인 경우
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                // 다음 칸으로 이동하는 데 필요한 사다리 비용 계산
                int diff = abs(land[r][c] - land[nr][nc]);
                
                // 높이 차이가 height 이하이면 사다리 없이 이동 가능 (비용 0)
                // height보다 크면 높이 차이만큼 비용 발생
                if (diff <= height) {
                    pq.push({0, nr, nc});
                } else {
                    pq.push({diff, nr, nc});
                }
            }
        }
    }
    
    return answer;
}