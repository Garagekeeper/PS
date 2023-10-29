#include <bits/stdc++.h>
#define MAX 2187
using namespace std;

int M[MAX][MAX];
int n;
int one = 0, zero = 0, minus_one = 0;

void DivideAndConquer(int x, int y, int size) {
  bool flag  = true;
  int temp   = 0;
  int before = M[x][y];
  if (size == 0) return;
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      if (before != M[i][j]) {
        flag = false;
        break;
      }
      if (abs(M[i][j])) temp++;
      before = M[i][j];
    }
  }
  if (flag && temp == 0) {
    zero++;
  } else if (flag && temp == (size * size)) {
    M[x][y] > 0 ? one++ : minus_one++;
  } else {
    size /= 3;
    DivideAndConquer(x, y, size);
    DivideAndConquer(x, y + size, size);
    DivideAndConquer(x, y + size * 2, size);
    DivideAndConquer(x + size, y, size);
    DivideAndConquer(x + size, y + size, size);
    DivideAndConquer(x + size, y + size * 2, size);
    DivideAndConquer(x + size * 2, y, size);
    DivideAndConquer(x + size * 2, y + size, size);
    DivideAndConquer(x + size * 2, y + size * 2, size);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }
  DivideAndConquer(0, 0, n);
  cout << minus_one << "\n" << zero << "\n" << one << "\n";
}