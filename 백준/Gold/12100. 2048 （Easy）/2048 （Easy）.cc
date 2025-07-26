#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int answer = 0;
int N;
vector<vector<int>> board;

// 한 방향으로 보드를 이동
void moveBoard(int dir, vector<vector<int>>& inboard) {
    if (dir == 0) { // 위
        for (int col = 0; col < N; col++) {
            vector<int> tmp;
            for (int row = 0; row < N; row++) {
                if (inboard[row][col] != 0) tmp.push_back(inboard[row][col]);
                inboard[row][col] = 0;
            }

            int idx = 0;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    inboard[idx++][col] = tmp[i] * 2;
                    i++; // skip next
                } else {
                    inboard[idx++][col] = tmp[i];
                }
            }
        }
    }
    else if (dir == 1) { // 아래
        for (int col = 0; col < N; col++) {
            vector<int> tmp;
            for (int row = N - 1; row >= 0; row--) {
                if (inboard[row][col] != 0) tmp.push_back(inboard[row][col]);
                inboard[row][col] = 0;
            }

            int idx = N - 1;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    inboard[idx--][col] = tmp[i] * 2;
                    i++;
                } else {
                    inboard[idx--][col] = tmp[i];
                }
            }
        }
    }
    else if (dir == 2) { // 왼쪽
        for (int row = 0; row < N; row++) {
            vector<int> tmp;
            for (int col = 0; col < N; col++) {
                if (inboard[row][col] != 0) tmp.push_back(inboard[row][col]);
                inboard[row][col] = 0;
            }

            int idx = 0;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    inboard[row][idx++] = tmp[i] * 2;
                    i++;
                } else {
                    inboard[row][idx++] = tmp[i];
                }
            }
        }
    }
    else if (dir == 3) { // 오른쪽
        for (int row = 0; row < N; row++) {
            vector<int> tmp;
            for (int col = N - 1; col >= 0; col--) {
                if (inboard[row][col] != 0) tmp.push_back(inboard[row][col]);
                inboard[row][col] = 0;
            }

            int idx = N - 1;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    inboard[row][idx--] = tmp[i] * 2;
                    i++;
                } else {
                    inboard[row][idx--] = tmp[i];
                }
            }
        }
    }
}

// DFS로 5번 이동 시도
void dfs(int depth, vector<vector<int>> inboard) {
    if (depth == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer = max(answer, inboard[i][j]);
            }
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> copied = inboard;
        moveBoard(dir, copied);
        dfs(depth + 1, copied);
    }
}

int main() {
    cin >> N;
    board.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, board);

    cout << answer << "\n";

    return 0;
}
