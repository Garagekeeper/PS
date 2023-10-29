#include <iostream>
#define MAX 128
using namespace std;

bool M[MAX][MAX];
int n;
int w = 0, b = 0;

void DivideAndConquer(int x, int y, int size) {
  int temp = 0;
  if (size == 0) return;

  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      if (M[i][j] == true) temp++;
    }
  }

  if (temp == 0) {
    w++;
  } else if (temp == (size * size)) {
    b++;
  } else {
    DivideAndConquer(x, y, size / 2);
    DivideAndConquer(x + size / 2, y, size / 2);
    DivideAndConquer(x, y + size / 2, size / 2);
    DivideAndConquer(x + size / 2, y + size / 2, size / 2);
  }

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }
    
  DivideAndConquer(0, 0, n);
  cout << w << "\n" << b << "\n";
}
