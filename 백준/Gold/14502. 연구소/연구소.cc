#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Cell
{
    int _x;
    int _y;
    int _type;
};

int N,M;
int cnt = 0;
int wallCNT = 3;
int answer = INT_MIN;
vector<vector<int>> board;
vector<Cell> virusVec;
vector<Cell> emptyVec;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool CanGo(int x, int y, vector<vector<int>>& inboard)
{
    if ( x < 0 || x >= N ) return false;
    if ( y < 0 || y >= M ) return false;
    if ( inboard[x][y] != 0) return false;

    return true;
}

void runBFS(std::vector<std::vector<int>> boardCopy, int& remainingEmptyCells)
{
    std::queue<Cell> q;

    // 모든 초기 바이러스 위치에서 BFS 시작
    for (const auto& virus : virusVec) 
    {
        q.push(virus);
    }

    while (!q.empty())
    {
        Cell current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = current._x + dx[i];
            int ny = current._y + dy[i];

            // 이동할 수 있는 곳이라면 (빈칸 0인 곳)
            if (CanGo(nx, ny, boardCopy))
            {
                boardCopy[nx][ny] = 2; // 바이러스 감염
                remainingEmptyCells--; // 안전 영역 감소
                q.push({nx, ny});
            }
        }
    }
}
void dfs()
{
    vector<bool> v(emptyVec.size() - wallCNT, false);
	v.insert(v.end(), wallCNT, true);
	do {
        // 빈칸중에서 벽을 세울 3개 뽑기
        vector<Cell> currentCombination;
		for (int i = 0; i < emptyVec.size(); i++) 
        {
			if (v[i]) currentCombination.push_back(emptyVec[i]);
		}
        // 3개 위치에 벽 세우기
        for (int i=0; i<3; i++)
        {
            int x = currentCombination[i]._x;
            int y = currentCombination[i]._y;
            board[x][y] = 1;
            cnt--;
        }

        // 각 바이러스에 대해서 bfs하기
        int res = cnt;
        runBFS(board, res);
        answer = max(answer, res);

        // 원상복구 하기
        for (int i=0; i<3; i++)
        {
            int x = currentCombination[i]._x;
            int y = currentCombination[i]._y;
            board[x][y] = 0;
            cnt++;
        }
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
    cin >> N >> M;
    board.resize(N,vector<int>(M));
    for (int i=0; i<N;i++)
    {
        for (int j=0; j<M; j++)
        {
            int val;
            cin >> val;
            board[i][j] = val;
            if (val == 2)
                virusVec.push_back({i,j,2});
            else if (val == 0)
            {
                emptyVec.push_back({i,j,0});
                cnt++;
            }
                
        }
    }

    dfs();

    cout << answer << "\n";
    return 0;
}