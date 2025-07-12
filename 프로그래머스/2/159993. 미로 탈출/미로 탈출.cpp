#include <string>
#include <vector>
#include <queue>
using namespace std;

enum ECellType
{
    CAN_GO = 0,
    CANNOT_GO,
    START,
    LEVER,
    EXIT,
};

vector<vector<ECellType>> board;

struct Cell
{
    int _x;
    int _y;
    int _dist;
    Cell(int x, int y, int dist = 0) : _x(x), _y(y), _dist(dist) {}
};

bool CanGo(int x, int y, const vector<vector<bool>>& visited)
{
    if (x < 0 || x >= board.size()) return false;
    if (y < 0 || y >= board[0].size()) return false;
    if (visited[x][y]) return false;
    if (board[x][y] == CANNOT_GO) return false;
    return true;
}

int BFS(Cell start, ECellType target)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<Cell> q;
    q.push(start);
    visited[start._x][start._y] = true;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty())
    {
        Cell cur = q.front(); q.pop();
        if (board[cur._x][cur._y] == target)
            return cur._dist;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur._x + dx[i];
            int ny = cur._y + dy[i];
            if (CanGo(nx, ny, visited))
            {
                visited[nx][ny] = true;
                q.push(Cell(nx, ny, cur._dist + 1));
            }
        }
    }

    return -1;  // 도달 불가
}

int solution(vector<string> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    board.resize(n, vector<ECellType>(m));
    Cell start(0, 0), lever(0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = maps[i][j];
            if (c == 'S') {
                board[i][j] = START;
                start = Cell(i, j);
            } else if (c == 'E') {
                board[i][j] = EXIT;
            } else if (c == 'L') {
                board[i][j] = LEVER;
                lever = Cell(i, j);
            } else if (c == 'O') {
                board[i][j] = CAN_GO;
            } else if (c == 'X') {
                board[i][j] = CANNOT_GO;
            }
        }
    }

    int toLever = BFS(start, LEVER);
    if (toLever == -1) return -1;

    int toExit = BFS(lever, EXIT);
    if (toExit == -1) return -1;

    return toLever + toExit;
}
