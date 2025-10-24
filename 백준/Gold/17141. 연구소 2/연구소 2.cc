#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int graph[50][50];
int emptyCount = 0;
const int minVal = 987654321;
int ans = minVal;

enum CellType
{
    None = 0,
    Wall = 1,
    Candidate = 2,
};

struct Cell
{
    int x;
    int y;
    int depth;

    Cell operator+(const Cell other)
    {
        int nx = x + other.x;
        int ny = y + other.y;

        return {nx, ny, depth+1};
    }
};

// 바이러스를 놓을 수 있는 칸들을 담는 벡터
vector<Cell> candiateVec;
// BFS에 사용할 탐색 방향
// R D L U
vector<Cell> dirVec = {
    {0,1,0},
    {1,0,0},
    {0,-1,0},
    {-1,0,0},
};

// 다음칸으로 갈 수 있는지 반환
bool CanGo(const vector<vector<bool>>& visited, Cell nextCell)
{
    if (nextCell.x < 0 || nextCell.x >= N) return false;
    if (nextCell.y < 0 || nextCell.y >= N) return false;
    if (visited[nextCell.x][nextCell.y] == true) return false;
    if (graph[nextCell.x][nextCell.y] == CellType::Wall) return false;
    return true;
}

// 현재 선택된 칸들에 바이러스를 놓고 BFS
void Simulate(vector<int> selected)
{
    queue<Cell> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    // 감염시킨 칸들의 개수 (방문한 칸의 개수)
    int visitedCnt = 0;
    // 현재 BFS에서 가장 먼 거리
    int maxdepth = 0;

    // 선택된 칸을 감염처리하고 BFS시작
    for (auto index : selected)
    {
        q.push(candiateVec[index]);
        visited[candiateVec[index].x][candiateVec[index].y] = true;
        visitedCnt++;
    }

    //BFS
    while(!q.empty())
    {
        auto curr = q.front(); q.pop();
        for (int i=0; i<dirVec.size(); i++)
        {
            // R D L U순으로 격자 그래프 탐색
            Cell nextCell = curr + dirVec[i];
            if (CanGo(visited, nextCell))
            {
                // 갈 수 있으면 방문처리 후 큐에넣는다.
                visited[nextCell.x][nextCell.y] = true;
                visitedCnt++;
                q.push(nextCell);
                // 가장 긴 거리 갱신
                maxdepth = max(maxdepth, nextCell.depth);
            }
        }
    }

    // 방문한 칸의 개수와 빈칸의 개수가 같은경우 (모두 방문한 경우)
    // 갱신
    if (visitedCnt == emptyCount)
        ans = min(ans, maxdepth);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int val;
            cin >> val;
            // 해당 칸이 빈칸인 경우 빈칸의 개수를 늘림.
            if (val == CellType::Candidate) 
            {
                // 2번, 즉 바이러스를 놓을 수 있는 칸은 빈칸처리 후
                // 벡터에 넣어서 따로 관리
                candiateVec.push_back({i,j,0}); 
                val = CellType::None;
                emptyCount++;
            }
            else if (val == CellType::None)
            {
                emptyCount++;
            }

            graph[i][j] = val;
        }    
    }

    // 조합을 위한 보조 수열
    auto comb = vector<bool>(candiateVec.size(), false);

    // 후보 K게 중에서 M개를 뽑기 위해 M개의 true를 생성
    for(int i=0; i < M; i++)
    {
        comb[i] = true;
    }
    sort(comb.begin(), comb.end());

    do
    {
        // 조합을 담기위한 벡터
        vector<int> selected;

        // i번째 원소가 true면 선택된 것.
        for (int i=0; i<comb.size(); i++)
            if (comb[i] != 0)
                // index를 삽입.
                selected.push_back(i);
        // 각 조합마다 시뮬레이션
        Simulate(selected);
    //순열을 활용해 조합을 생성
    } while (next_permutation(comb.begin(), comb.end()));
    
    // 정답이 갱신되지 않은 경우 (어떤 경우에도 방문불가)
    if(ans == minVal)
        ans = -1;

    cout << ans << "\n";

    return 0;
}