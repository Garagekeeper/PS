#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;
int graph[20][20];
vector<vector<bool>> visited;
int N;
int ans = 0;

struct Cell
{
    int x;
    int y; 
    int cnt;
    int babySharkSize;
    int depth;

    bool operator<(const Cell& other)
    {
        if (depth == other.depth)
        {
            if (x == other.x)
            {
                return y < other.y;
            }

            return x < other.x;
        }

        return depth < other.depth;
    }
};

bool CanGo(Cell& cell)
{
    int x = cell.x;
    int y = cell.y;
    int bss = cell.babySharkSize;

    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= N) return false;
    if (visited[x][y]) return false;
    if (bss < graph[x][y] && graph[x][y] != 0) return false;

    return true;

}

void BFS(Cell start)
{
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    queue<Cell> q;
    Cell current;
    vector<Cell> fish;

    fish.push_back(start);

    // 시작좌표에서 BFS실행해서 먹을 수 있는 물고기의 후보 선택
    // 후보들을 최단거리, 상단, 좌측 순으로 정렬해서 맨 앞을 선택
    // 그 후보가 새로운 시작 좌표
    while(true)
    {
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        
        //직전 좌표에서 더이상 먹을 수 있는 물고기가 없으면 종료
        if (fish.empty()) break;

        // 먹을 수 있는 물고기 중 조건에 맞는걸 뽑음
        sort(fish.begin(), fish.end());
        int cx=fish.front().x;
        int cy=fish.front().y;
        int& csize = fish.front().babySharkSize;
        int& ccnt = fish.front().cnt;
        visited[cx][cy] = true;

        // 현재 칸의 물고기를 먹을 수 있으면 먹음
        if (graph[cx][cy] < csize &&  graph[cx][cy] != 0)
        {
            graph[cx][cy] = 0;
            ccnt++;
            // 현재까지 먹은 물고기의 수ccnt가 현재 크기와 같아지면 
            // 크기를 늘림
            if (fish.front().cnt == csize)
            {
                csize++;
                ccnt=0;
            }
        }
        
        // BFS를 위해 Q에 삽입
        // 물고기중 조건에 맞는 게 새로운 시작 좌표
        q.push(fish.front());
        
        // 정답 갱신
        ans = fish.front().depth;
        
        // 후보 배열 정리
        fish.clear();

        
        // BFS 시작
        while(!q.empty())
        {
            current = q.front(); q.pop();
            for (int i=0; i<4; i++)
            {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                Cell nCell = {nx, ny, current.cnt, current.babySharkSize, current.depth + 1};
                if (CanGo(nCell))
                {
                    // 물고기 먹을 수 있는 칸은 후보에 추가
                    if (graph[nx][ny] < current.babySharkSize && graph[nx][ny] != 0)
                    {
                        fish.push_back(nCell);
                    }
                    q.push(nCell);
                    visited[nx][ny] = true;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int startX;
    int startY;

    cin >> N;

    // 입력
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int val;
            cin >> val;
            // 현재 위치를 0으로 바꾸기
            if (val == 9) {startX = i; startY = j; val = 0;}
            graph[i][j] = val;
        }
    }

    BFS({startX,startY,0,2,0});

   
    return 0;
}