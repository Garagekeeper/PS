#include <bits/stdc++.h>
#define MAX 46341
using namespace std;
int a, b, c;

int DivideAndConquer(int _a, int _b, int _c) {
  long long res = 1;
  if (_b == 1) return _a % _c;
  res = DivideAndConquer(_a, _b / 2, _c);
  if (_b % 2 == 0) {
    res = (res * res) % _c;
  } else {
    res = ((res * res) % _c * _a) % _c;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  cin >> a >> b >> c;
  cout << DivideAndConquer(a, b, c);
}
