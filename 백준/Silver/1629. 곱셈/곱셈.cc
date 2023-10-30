#include <bits/stdc++.h>
using namespace std;
unsigned long long arr[46341];

long long a, b, c;
long long DivideAndConquer(int a, int b, int c) {
  unsigned long long res = 1;
  if (b == 1) return a % c;
  res = DivideAndConquer(a, b / 2, c);
  if (b % 2 == 0) {
    res = (res * res) % c;
  } else {
    res = ((res * res) %c * a) % c;
  }

  return res % c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  arr[0] = 1;
  cin >> a >> b >> c;
  for (int i = 1; i < (int)sqrt(b); i++) {
    arr[i] = (arr[i - 1] * a) % c;
  }

  cout << DivideAndConquer(a, b, c);
}

// 55 -50 40 -30 20
// 1 -2 -3 4 -5
// 1 1 2 3 5 8 13
// 7 3 3 4
// 2147483646 2147483646 2147483647