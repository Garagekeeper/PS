#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int N;
vector<int> board; // i번째 행에 퀸이 놓인 열 번호

bool CanPlace(int row, int col) {
    for (int i = 0; i < row; i++) {
        // 같은 열 || 대각선(좌우 대각선 모두)
        if (board[i] == col || abs(board[i] - col) == row - i)
            return false;
    }
    return true;
}

void dfs(int row) {
    if (row == N) {
        answer++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (CanPlace(row, col)) {
            board[row] = col;
            dfs(row + 1);
        }
    }
}

int solution(int n) {
    N = n;
    board = vector<int>(N);
    dfs(0);
    return answer;
}